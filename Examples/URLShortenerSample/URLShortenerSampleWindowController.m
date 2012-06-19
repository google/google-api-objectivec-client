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
//  URLShortenerSampleWindowController.m
//

#import "URLShortenerSampleWindowController.h"

#import "GTL/GTMOAuth2WindowController.h"
#import "GTL/GTMHTTPFetcherLogging.h"

@interface URLShortenerSampleWindowController ()

// History table properties
@property (retain, nonatomic) GTLUrlshortenerUrlHistory *historyFeed;
@property (retain, nonatomic) GTLServiceTicket *historyTicket;
@property (retain, nonatomic) NSError *historyFetchError;

// Analytics table properties
@property (retain, nonatomic) GTLUrlshortenerUrl *analyticsItem;
@property (retain, nonatomic) GTLServiceTicket *analyticsTicket;
@property (retain, nonatomic) NSError *analyticsFetchError;

// Other properties
@property (retain, nonatomic, readonly) GTLServiceUrlshortener *URLShortenerService;

- (NSString *)signedInUsername;
- (void)runSigninThenInvokeSelector:(SEL)signInDoneSel;
- (void)updateUI;
- (void)displayAlert:(NSString *)title format:(NSString *)format, ...;
- (GTLUrlshortenerUrl *)selectedHistoryItem;
- (NSArray *)selectedAnalyticsCounts;
- (void)fetchHistory;
- (void)addAShortenedURL;
@end

// Keychain item name used to store the user's auth credential
NSString *const kKeychainItemName = @"URL Shortener Sample: Google URL Shortener";


@implementation URLShortenerSampleWindowController

@synthesize historyFeed = historyFeed_,
  historyTicket = historyTicket_,
  historyFetchError = historyFetchError_,
  analyticsItem = analyticsItem_,
  analyticsTicket = analyticsTicket_,
  analyticsFetchError = analyticsFetchError_;

+ (URLShortenerSampleWindowController *)sharedWindowController {

  static URLShortenerSampleWindowController* gWindowController = nil;

  if (!gWindowController) {
    gWindowController = [[URLShortenerSampleWindowController alloc] init];
  }
  return gWindowController;
}


- (id)init {
  return [self initWithWindowNibName:@"URLShortenerSampleWindow"];
}

- (void)awakeFromNib {
  // Set the result text fields to have a distinctive color and mono-spaced font
  [historyResultTextField_ setTextColor:[NSColor darkGrayColor]];

  NSFont *resultTextFont = [NSFont fontWithName:@"Monaco" size:9];
  [historyResultTextField_ setFont:resultTextFont];

  NSString *clientID = [clientIDField_ stringValue];
  NSString *clientSecret = [clientSecretField_ stringValue];

  GTMOAuth2Authentication *auth;
  auth = [GTMOAuth2WindowController authForGoogleFromKeychainForName:kKeychainItemName
                                                            clientID:clientID
                                                        clientSecret:clientSecret];
  self.URLShortenerService.authorizer = auth;

  [self updateUI];
}

- (void)dealloc {
  [historyFeed_ release];
  [historyTicket_ release];
  [historyFetchError_ release];

  [analyticsItem_ release];
  [analyticsTicket_ release];
  [analyticsFetchError_ release];

  [super dealloc];
}

#pragma mark -

- (NSString *)signedInUsername {
  GTMOAuth2Authentication *auth = self.URLShortenerService.authorizer;
  if (auth.canAuthorize) {
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
    [GTMOAuth2WindowController removeAuthFromKeychainForName:kKeychainItemName];
    self.URLShortenerService.authorizer = nil;
    [self updateUI];
  }
}

- (IBAction)getHistoryClicked:(id)sender {
  if (![self isSignedIn]) {
    [self runSigninThenInvokeSelector:@selector(fetchHistory)];
  } else {
    [self fetchHistory];
  }
}

- (IBAction)addShortenedURLClicked:(id)sender {
  [self addAShortenedURL];
}

- (IBAction)cancelHistoryFetchClicked:(id)sender {
  [self.historyTicket cancelTicket];
  self.historyTicket = nil;

  [self updateUI];
}

- (IBAction)cancelAnalyticsFetchClicked:(id)sender {
  [self.analyticsTicket cancelTicket];
  self.analyticsTicket = nil;

  [self updateUI];
}

- (IBAction)analyticsSegmentClicked:(id)sender {
  [self updateUI];
}

- (IBAction)APIConsoleClicked:(id)sender {
  NSURL *url = [NSURL URLWithString:@"https://code.google.com/apis/console"];
  [[NSWorkspace sharedWorkspace] openURL:url];
}

- (IBAction)loggingCheckboxClicked:(id)sender {
  [GTMHTTPFetcher setLoggingEnabled:[sender state]];
}

#pragma mark -

// Get a service object with the current authorization
//
// A "service" object handles networking tasks.  Service objects
// contain user authentication information as well as networking
// state information (such as cookies and cached fetch results.)

- (GTLServiceUrlshortener *)URLShortenerService {

  static GTLServiceUrlshortener* service = nil;
  if (!service) {
    service = [[GTLServiceUrlshortener alloc] init];

    // Have the service object set tickets to fetch consecutive pages
    // of the feed so we do not need to manually fetch them
    service.shouldFetchNextPages = YES;

    // Have the service object set tickets to retry temporary error conditions
    // automatically
    service.retryEnabled = YES;
  }
  return service;
}

- (GTLUrlshortenerUrl *)selectedHistoryItem {
  int rowIndex = [historyTable_ selectedRow];
  if (rowIndex > -1) {
    GTLUrlshortenerUrl *item = [self.historyFeed itemAtIndex:rowIndex];
    return item;
  }
  return nil;
}

- (NSArray *)selectedAnalyticsCounts {
  // segment names are the array fields of the analytics snapshot
  NSSegmentedControl *segments = analyticsSegmentedControl_;
  NSInteger segmentIndex = segments.selectedSegment;
  NSString *fieldName = [segments labelForSegment:segmentIndex];

  GTLUrlshortenerUrl *item = self.analyticsItem;
  GTLUrlshortenerAnalyticsSummary *summary = item.analytics;
  GTLUrlshortenerAnalyticsSnapshot *snapshot = summary.allTime;
  NSArray *counts = [snapshot valueForKey:fieldName];
  return counts;
}

#pragma mark Fetch the locations feed

// begin retrieving the feed
- (void)fetchHistory {
  self.historyFeed = nil;
  self.historyFetchError = nil;

  GTLQueryUrlshortener *query = [GTLQueryUrlshortener queryForUrlList];
  self.historyTicket = [self.URLShortenerService executeQuery:query
                                            completionHandler:^(GTLServiceTicket *ticket, id feed, NSError *error) {
                                              // callback
                                              self.historyFeed = feed;
                                              self.historyFetchError = error;
                                              self.historyTicket = nil;

                                              [self updateUI];
                                            }];
  [self updateUI];
}

#pragma mark Fetch an analytics items

- (void)fetchAnalyticsForSelectedHistoryItem {
  self.analyticsItem = nil;
  self.analyticsFetchError = nil;

  GTLUrlshortenerUrl *item = [self selectedHistoryItem];
  if (item) {
    GTLQueryUrlshortener *query = [GTLQueryUrlshortener queryForUrlGetWithShortUrl:item.identifier];
    query.projection = kGTLUrlshortenerProjectionFull;

    self.analyticsTicket = [self.URLShortenerService executeQuery:query
                                                completionHandler:^(GTLServiceTicket *ticket, id item, NSError *error) {
                                                  // callback
                                                  self.analyticsItem = item;
                                                  self.analyticsFetchError = error;
                                                  self.analyticsTicket = nil;

                                                  [self updateUI];
                                                }];
    [self updateUI];
  }
}

#pragma mark Add a new short URL

- (void)addAShortenedURL {
  NSString *newURLStr = [addShortenedURLField_ stringValue];
  if ([newURLStr length] > 0) {
    // make an object with the URL to be shortened
    GTLUrlshortenerUrl *obj = [GTLUrlshortenerUrl object];
    obj.longUrl = newURLStr;

    GTLQueryUrlshortener *query = [GTLQueryUrlshortener queryForUrlInsertWithObject:obj];
    [self.URLShortenerService executeQuery:query
                         completionHandler:^(GTLServiceTicket *ticket, id object, NSError *error) {
                           // callback
                           if (error == nil) {
                             GTLUrlshortenerUrl *item = object;
                             [self displayAlert:@"Add URL"
                                         format:@"Added URL \"%@\" for \n\"%@\"", item.identifier, item.longUrl];
                             [self fetchHistory];
                             [addShortenedURLField_ setStringValue:@""];
                           } else {
                             [self displayAlert:@"Add URL Error"
                                         format:@"%@", error];
                             [self updateUI];
                           }
                         }];
  }
}

#pragma mark Sign-In Sheet

- (void)runSigninThenInvokeSelector:(SEL)signInDoneSel {
  // Your app should have clientID and clientSecret hardcoded into the source
  NSString *clientID = [clientIDField_ stringValue];
  NSString *clientSecret = [clientSecretField_ stringValue];

  if ([clientID length] == 0 || [clientSecret length] == 0) {
    // remind the developer that client ID and client secret are needed
    [clientIDButton_ performSelector:@selector(performClick:)
                          withObject:self
                          afterDelay:0.5];
    return;
  }

  NSBundle *frameworkBundle = [NSBundle bundleForClass:[GTMOAuth2WindowController class]];
  GTMOAuth2WindowController *windowController;
  windowController = [GTMOAuth2WindowController controllerWithScope:kGTLAuthScopeUrlshortener
                                                           clientID:clientID
                                                       clientSecret:clientSecret
                                                   keychainItemName:kKeychainItemName
                                                     resourceBundle:frameworkBundle];

  [windowController signInSheetModalForWindow:[self window]
                            completionHandler:^(GTMOAuth2Authentication *auth, NSError *error) {
                              if (error == nil) {
                                self.URLShortenerService.authorizer = auth;

                                if (signInDoneSel) {
                                  [self performSelector:signInDoneSel];
                                }
                              } else {
                                self.historyFetchError = error;
                                [self updateUI];
                              }
                            }];
}

#pragma mark UI

- (void)updateUI {
  // History table
  [historyTable_ reloadData];

  if (self.historyTicket != nil) {
    [historyProgressIndicator_ startAnimation:self];
    [historyCancelButton_ setEnabled:YES];
  } else {
    [historyProgressIndicator_ stopAnimation:self];
    [historyCancelButton_ setEnabled:NO];
  }

  // Display the selected history item, or the fetch error
  GTLUrlshortenerUrl *selectedItem = [self selectedHistoryItem];
  NSString *resultStr = @"";
  NSError *fetchError = self.historyFetchError;
  if (fetchError != nil) {
    resultStr = [fetchError description];
  } else {
    if (selectedItem) {
      resultStr = [selectedItem description];
    }
  }
  [historyResultTextField_ setString:resultStr];

  // Analytics table
  [analyticsTable_ reloadData];

  if (self.analyticsTicket != nil) {
    [analyticsProgressIndicator_ startAnimation:self];
    [analyticsCancelButton_ setEnabled:YES];
  } else {
    [analyticsProgressIndicator_ stopAnimation:self];
    [analyticsCancelButton_ setEnabled:NO];
  }

  NSString *shortClicksStr = @"Short URL Clicks: -";
  NSString *longClicksStr = @"Long URL Clicks: -";
  if (self.analyticsItem.analytics) {
    NSNumber *shortClicks = self.analyticsItem.analytics.allTime.shortUrlClicks;
    NSNumber *longClicks = self.analyticsItem.analytics.allTime.shortUrlClicks;

    shortClicksStr = [NSString stringWithFormat:@"Short URL Clicks: %@", shortClicks];
    longClicksStr = [NSString stringWithFormat:@"Long URL Clicks: %@", longClicks];
  }
  [shortURLClicksField_ setStringValue:shortClicksStr];
  [longURLClicksField_ setStringValue:longClicksStr];

  // Enable buttons
  BOOL isSignedIn = ([self signedInUsername] != nil);
  [signedInButton_ setTitle:(isSignedIn ? @"Sign Out" : @"Sign In")];
  [signedInField_ setStringValue:(isSignedIn ? [self signedInUsername] : @"No")];

  BOOL hasALongURL = ([[addShortenedURLField_ stringValue] length] > 0);
  [addShortenedURLButton_ setEnabled:(isSignedIn && hasALongURL)];

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
  NSBeginAlertSheet(title, nil, nil, nil, [self window], nil, nil,
                    nil, nil, @"%@", result);
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
// https://code.google.com/apis/console
//

- (IBAction)clientIDClicked:(id)sender {
  // show the sheet for developers to enter client ID and client secret
  [NSApp beginSheet:clientIDSheet_
     modalForWindow:[self window]
      modalDelegate:self
     didEndSelector:@selector(clientIDSheetDidEnd:returnCode:contextInfo:)
        contextInfo:NULL];
}

- (IBAction)clientIDDoneClicked:(id)sender {
  [NSApp endSheet:clientIDSheet_ returnCode:NSOKButton];
}

- (void)clientIDSheetDidEnd:(NSWindow *)sheet returnCode:(NSInteger)returnCode contextInfo:(void *)contextInfo {
  [sheet orderOut:self];

  [self updateUI];
}

#pragma mark Text field delegate methods

- (void)controlTextDidChange:(NSNotification *)note {
  [self updateUI]; // enabled/disable buttons
}

#pragma mark TableView delegate and data source methods

- (void)tableViewSelectionDidChange:(NSNotification *)notification {
  if ([notification object] == historyTable_) {
    [self fetchAnalyticsForSelectedHistoryItem];
  } else {
    [self updateUI];
  }
}

// table view data source methods
- (int)numberOfRowsInTableView:(NSTableView *)tableView {
  if (tableView == historyTable_) {
    NSArray *items = self.historyFeed.items;
    return [items count];
  } else {
    NSArray *items = [self selectedAnalyticsCounts];
    return [items count];
  }
}

- (id)tableView:(NSTableView *)tableView
objectValueForTableColumn:(NSTableColumn *)tableColumn
            row:(int)row {
  if (tableView == historyTable_) {
    GTLUrlshortenerUrl *item = [self.historyFeed itemAtIndex:row];
    NSString *resultStr = [NSString stringWithFormat:@"%@ → %@",
                           item.identifier, item.longUrl];
    return resultStr;
  } else {
    NSArray *counts = [self selectedAnalyticsCounts];
    GTLUrlshortenerStringCount *countPair = [counts objectAtIndex:row];
    NSString *resultStr = [NSString stringWithFormat:@"%@: %@",
                           countPair.count, countPair.identifier];
    return resultStr;
  }
}

@end
