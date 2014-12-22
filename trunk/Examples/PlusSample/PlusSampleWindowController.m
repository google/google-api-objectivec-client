/* Copyright (c) 2011 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//
//  PlusSampleWindowController.m
//

#import "PlusSampleWindowController.h"

#import "GTL/GTLUtilities.h"
#import "GTL/GTMHTTPFetcherLogging.h"

@interface PlusSampleWindowController ()

@property (nonatomic, readonly) GTLServicePlus *plusService;

@property (nonatomic, retain) GTLPlusPerson *userProfile;
@property (nonatomic, retain) GTLPlusActivityFeed *activityFeed;
@property (nonatomic, retain) GTLServiceTicket *profileTicket;
@property (nonatomic, retain) NSError *profileFetchError;
@property (nonatomic, retain) NSError *activityFeedFetchError;

- (void)runSigninThenInvokeSelector:(SEL)signInDoneSel;

- (void)updateUI;
- (void)displayAlert:(NSString *)title format:(NSString *)format, ...;

- (void)fetchUserProfile;

- (id)selectedActivityFeedItem;
@end


NSString *const kKeychainItemName = @"Plus Sample: Google Plus";

@implementation PlusSampleWindowController

@synthesize userProfile = userProfile_,
            activityFeed = activityFeed_,
            profileTicket = profileTicket_,
            profileFetchError = profileFetchError_,
            activityFeedFetchError = activityFeedFetchError_;

+ (PlusSampleWindowController *)sharedWindowController {
  static PlusSampleWindowController* gWindowController = nil;
  if (!gWindowController) {
    gWindowController = [[PlusSampleWindowController alloc] init];
  }
  return gWindowController;
}


- (id)init {
  return [self initWithWindowNibName:@"PlusSampleWindow"];
}

- (void)awakeFromNib {
  // Load the OAuth token from the keychain, if it was previously saved
  NSString *clientID = [clientIDField_ stringValue];
  NSString *clientSecret = [clientSecretField_ stringValue];

  GTMOAuth2Authentication *auth;
  auth = [GTMOAuth2WindowController authForGoogleFromKeychainForName:kKeychainItemName
                                                            clientID:clientID
                                                        clientSecret:clientSecret];
  self.plusService.authorizer = auth;

  // Set the result text fields to have a distinctive color and mono-spaced font
  [profileResultTextView_ setTextColor:[NSColor darkGrayColor]];
  [activityFeedResultTextView_ setTextColor:[NSColor darkGrayColor]];

  NSFont *resultTextFont = [NSFont fontWithName:@"Monaco" size:9];
  [profileResultTextView_ setFont:resultTextFont];
  [activityFeedResultTextView_ setFont:resultTextFont];

  [self updateUI];
}

- (void)dealloc {
  [userProfile_ release];
  [activityFeed_ release];
  [profileTicket_ release];
  [profileFetchError_ release];
  [activityFeedFetchError_ release];

  [super dealloc];
}

#pragma mark -

- (NSString *)signedInUsername {
  GTMOAuth2Authentication *auth = self.plusService.authorizer;
  BOOL isSignedIn = auth.canAuthorize;
  if (isSignedIn) {
    return auth.userEmail;
  } else {
    return nil;
  }
}

- (BOOL)isSignedIn {
  NSString *name = [self signedInUsername];
  return (name != nil);
}

#pragma mark IBActions

- (IBAction)signInClicked:(id)sender {
  if (![self isSignedIn]) {
    // Sign in
    [self runSigninThenInvokeSelector:@selector(updateUI)];
  } else {
    // Sign out
    GTLServicePlus *service = self.plusService;

    [GTMOAuth2WindowController removeAuthFromKeychainForName:kKeychainItemName];
    service.authorizer = nil;
    [self updateUI];
  }
}

- (IBAction)getFeedClicked:(id)sender {
  if (![self isSignedIn]) {
    [self runSigninThenInvokeSelector:@selector(fetchUserProfile)];
  } else {
    [self fetchUserProfile];
  }
}

- (IBAction)cancelProfileFetch:(id)sender {
  [self.profileTicket cancelTicket];
  self.profileTicket = nil;

  [self updateUI];
}

- (IBAction)APIConsoleClicked:(id)sender {
  NSURL *url = [NSURL URLWithString:@"https://console.developers.google.com/"];
  [[NSWorkspace sharedWorkspace] openURL:url];
}

- (IBAction)loggingCheckboxClicked:(id)sender {
  [GTMHTTPFetcher setLoggingEnabled:[sender state]];
}

#pragma mark -

// Get a service object
//
// A "service" object handles networking tasks.  Service objects
// contain user authentication information as well as networking
// state information (such as cookies and the "last modified" date for
// fetched data.)

- (GTLServicePlus *)plusService {

  static GTLServicePlus* service = nil;

  if (!service) {
    service = [[GTLServicePlus alloc] init];

    // Have the service object set tickets to retry temporary error conditions
    // automatically
    service.retryEnabled = YES;

    // Have the service object set tickets to automatically fetch additional
    // pages of feeds when the feed's maxResult value is less than the number
    // of items in the feed
    service.shouldFetchNextPages = YES;
  }
  return service;
}

- (GTLPlusPerson *)selectedActivityFeedItem {
  int rowIndex = [activityFeedTable_ selectedRow];
  if (rowIndex > -1) {
    GTLPlusPerson *item = [activityFeed_ itemAtIndex:rowIndex];
    return item;
  }
  return nil;
}

#pragma mark Fetch feed of the user's activities, circles, or albums

- (void)fetchUserProfile {
  self.userProfile = nil;
  self.activityFeed = nil;
  self.profileFetchError = nil;
  self.activityFeedFetchError = nil;

  // Make a batch for fetching both the user's profile and the activity feed
  GTLQueryPlus *profileQuery = [GTLQueryPlus queryForPeopleGetWithUserId:@"me"];
  profileQuery.completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
    if (error == nil) {
      self.userProfile = object;
    } else {
      self.profileFetchError = error;
    }
  };

  GTLQueryPlus *activitiesQuery = [GTLQueryPlus queryForActivitiesListWithUserId:@"me"
                                                                      collection:kGTLPlusCollectionPublic];
  // Set an appropriate page size when requesting the activity items
  activitiesQuery.maxResults = 100;
  activitiesQuery.completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
    if (error == nil) {
      self.activityFeed = object;
    } else {
      self.activityFeedFetchError = error;
    }
  };

  GTLBatchQuery *batchQuery = [GTLBatchQuery batchQuery];
  [batchQuery addQuery:profileQuery];
  [batchQuery addQuery:activitiesQuery];

  GTLServicePlus *service = self.plusService;
  self.profileTicket = [service executeQuery:batchQuery
                           completionHandler:^(GTLServiceTicket *ticket,
                                               id result, NSError *error) {
                             // Callback
                             //
                             // For batch queries with successful execution,
                             // the result is a GTLBatchResult object
                             //
                             // At this point, the query completion blocks
                             // have already been called
                             self.profileTicket = nil;

                             [self updateUI];
                           }];
  [self updateUI];
}

#pragma mark Sign In

- (void)runSigninThenInvokeSelector:(SEL)signInDoneSel {
  // Applications should have client ID and client secret strings
  // hardcoded into the source, but the sample application asks the
  // developer for the strings
  NSString *clientID = [clientIDField_ stringValue];
  NSString *clientSecret = [clientSecretField_ stringValue];

  if ([clientID length] == 0 || [clientSecret length] == 0) {
    // Remind the developer that client ID and client secret are needed
    [clientIDButton_ performSelector:@selector(performClick:)
                          withObject:self
                          afterDelay:0.5];
    return;
  }

  // Show the OAuth 2 sign-in controller
  NSBundle *frameworkBundle = [NSBundle bundleForClass:[GTMOAuth2WindowController class]];
  GTMOAuth2WindowController *windowController;
  windowController = [GTMOAuth2WindowController controllerWithScope:kGTLAuthScopePlusMe
                                                           clientID:clientID
                                                       clientSecret:clientSecret
                                                   keychainItemName:kKeychainItemName
                                                     resourceBundle:frameworkBundle];

  [windowController signInSheetModalForWindow:[self window]
                            completionHandler:^(GTMOAuth2Authentication *auth,
                                                NSError *error) {
                              // callback
                              if (error == nil) {
                                self.plusService.authorizer = auth;
                                if (signInDoneSel) {
                                  [self performSelector:signInDoneSel];
                                }
                              } else {
                                self.profileFetchError = error;
                                [self updateUI];
                              }
                            }];
}

#pragma mark UI

- (void)fetchURLString:(NSString *)urlString
          forImageView:(NSImageView *)imageView {
  // Common code to fetch an image for an NSImageView
  [imageView setImage:nil];

  if (urlString) {
    // We can reuse the fetcher service from the API service object to make
    // the image fetchers, though the image fetches should be unauthorized
    GTMHTTPFetcherService *fetcherService = self.plusService.fetcherService;
    GTMHTTPFetcher *fetcher = [fetcherService fetcherWithURLString:urlString];
    fetcher.authorizer = nil;
    [fetcher setCommentWithFormat:@"image fetch"];

    [fetcher beginFetchWithCompletionHandler:^(NSData *data, NSError *error) {
      // Callback
      if (error == nil) {
        NSImage *image = [[[NSImage alloc] initWithData:data] autorelease];
        [imageView setImage:image];
      } else {
        NSLog(@"Error %@ loading image %@", error, urlString);
      }
    }];
  }
}

- (void)updateProfileImage {
  static NSString* gPriorImageURLStr = nil;

  NSString *newImageURLStr = userProfile_.image.url;

  if (!GTL_AreEqualOrBothNil(newImageURLStr, gPriorImageURLStr)) {
    // The image has changed
    [gPriorImageURLStr release];
    gPriorImageURLStr = [newImageURLStr copy];

    [self fetchURLString:newImageURLStr forImageView:profileImageView_];
  }
}

- (void)updateActivityFeedImage {
  static NSString* gPriorImageURLStr = nil;

  NSString *newImageURLStr = nil;

  GTLPlusActivity *activity = [self selectedActivityFeedItem];
  NSArray *attachments = activity.object.attachments;
  if ([attachments count] > 0) {
    GTLPlusActivityObjectAttachmentsItem *attachment = [attachments objectAtIndex:0];
    newImageURLStr = attachment.image.url;
  }
  if (!GTL_AreEqualOrBothNil(newImageURLStr, gPriorImageURLStr)) {
    // The image has changed
    [gPriorImageURLStr release];
    gPriorImageURLStr = [newImageURLStr copy];

    [self fetchURLString:newImageURLStr forImageView:activityFeedImageView_];
  }
}

- (void)updateUI {
  BOOL isSignedIn = [self isSignedIn];
  NSString *username = [self signedInUsername];
  [signedInButton_ setTitle:(isSignedIn ? @"Sign Out" : @"Sign In")];
  [signedInField_ setStringValue:(isSignedIn ? username : @"No")];

  //
  // Main table: display just the user profile
  //
  // We don't really need a table for this, since there is only one
  // user profile to display, but one day we may be glad there's a table
  // here.
  //
  [profileTable_ reloadData];

  if (profileTicket_ != nil) {
    [profileProgressIndicator_ startAnimation:self];
  } else {
    [profileProgressIndicator_ stopAnimation:self];
  }

  // Display the user profile, or a fetch error
  NSString *resultStr = @"";
  if (profileFetchError_) {
    // Display the error
    resultStr = [profileFetchError_ description];
  } else {
    // Display the profile
    if (userProfile_) {
      resultStr = [userProfile_ description];
    }
  }
  [profileResultTextView_ setString:resultStr];

  [self updateProfileImage];

  //
  // Lower table: display the activity feed
  //
  [activityFeedTable_ reloadData];

  // Get the description of the selected item, or the feed fetch error
  resultStr = @"";

  GTLPlusPerson *person = [self selectedActivityFeedItem];
  if (activityFeedFetchError_) {
    resultStr = [activityFeedFetchError_ description];
  } else {
    if (person) {
      resultStr = [person description];
    }
  }

  [activityFeedResultTextView_ setString:resultStr];

  [self updateActivityFeedImage];

  // Enable buttons
  [profileFetchCancelButton_ setEnabled:(profileTicket_ != nil)];

  // Show or hide the text indicating that the client ID or client secret are
  // needed
  BOOL hasClientIDStrings = [[clientIDField_ stringValue] length] > 0
    && [[clientSecretField_ stringValue] length] > 0;
  [clientIDRequiredTextField_ setHidden:hasClientIDStrings];
}

- (void)displayAlert:(NSString *)title format:(NSString *)format, ... {
  NSString *result = format;
  if (format) {
    va_list argList;
    va_start(argList, format);
    result = [[[NSString alloc] initWithFormat:format
                                     arguments:argList] autorelease];
    va_end(argList);
  }
  NSAlert *alert = [[[NSAlert alloc] init] autorelease];
  alert.messageText = title;
  alert.informativeText = result;
  [alert beginSheetModalForWindow:[self window]
                completionHandler:nil];
}

#pragma mark Client ID Sheet

// Client ID and Client Secret Sheet
//
// Sample apps need this sheet to ask for the client ID and client secret
// strings
//
// Your application will just hardcode the client ID and client secret strings
// into the source rather than ask the user for them.
//
// The string values are obtained from the API Console,
// https://console.developers.google.com/

- (IBAction)clientIDClicked:(id)sender {
  // Show the sheet for developers to enter their client ID and client secret
  [[self window] beginSheet:clientIDSheet_ completionHandler:nil];
}

- (IBAction)clientIDDoneClicked:(id)sender {
  [[self window] endSheet:[sender window]];
}

#pragma mark Text field delegate methods

- (void)controlTextDidChange:(NSNotification *)note {
  [self updateUI];  // enable and disable buttons
}

#pragma mark TableView delegate and data source methods

- (void)tableViewSelectionDidChange:(NSNotification *)notification {
  [self updateUI];
}

- (int)numberOfRowsInTableView:(NSTableView *)tableView {
  if (tableView == profileTable_) {
    return (self.userProfile != nil ? 1 : 0);
  } else {
    return [self.activityFeed.items count];
  }
}

- (id)tableView:(NSTableView *)tableView
objectValueForTableColumn:(NSTableColumn *)tableColumn
            row:(int)row {
  if (tableView == profileTable_) {
    if (row == 0) {
      return self.userProfile.displayName;
    } else {
      return nil;
    }
  } else {
    // Activities
    GTLPlusActivity *item = [self.activityFeed itemAtIndex:row];
    return item.object.content;
  }
}

@end
