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
//  BooksSampleWindowController.m
//

#import "BooksSampleWindowController.h"

#import "GTL/GTMHTTPFetcherLogging.h"

@interface BooksSampleWindowController ()

@property (nonatomic, readonly) GTLServiceBooks *booksService;

@property (nonatomic, retain) GTLBooksVolumes *publicVolumes;
@property (nonatomic, retain) GTLServiceTicket *publicVolumesTicket;
@property (nonatomic, retain) NSError *publicVolumesFetchError;

@property (nonatomic, retain) GTLBooksBookshelves *bookshelves;
@property (nonatomic, retain) GTLServiceTicket *bookshelvesTicket;

@property (nonatomic, retain) GTLBooksVolumes *myVolumes;
@property (nonatomic, retain) GTLServiceTicket *myVolumesTicket;
@property (nonatomic, retain) NSError *myVolumesFetchError;

@property (nonatomic, retain) GTLServiceTicket *editMyVolumeTicket;

- (void)runSigninThenInvokeSelector:(SEL)signInDoneSel;

- (void)updateUI;
- (void)updateBookshelvesPopup;
- (void)displayAlert:(NSString *)title format:(NSString *)format, ...;

- (void)searchVolumes;
- (void)fetchMyBookshelvesThenInvokeSelector:(SEL)sel;
- (void)fetchMyVolumes;

- (void)addSelectedPublicVolume;
- (void)removeMyVolume;
- (void)removeAllMyVolumes;

- (GTLBooksVolume *)selectedPublicVolume;
- (GTLBooksVolume *)selectedMyVolume;
- (GTLBooksBookshelf *)selectedBookshelf;
@end


NSString *const kKeychainItemName = @"Books Sample: Google Books";

@implementation BooksSampleWindowController

@synthesize publicVolumes = publicVolumes_,
            publicVolumesTicket = publicVolumesTicket_,
            publicVolumesFetchError = publicVolumesFetchError_,
            bookshelves = bookshelves_,
            bookshelvesTicket = bookshelvesTicket_,
            myVolumes = myVolumes_,
            myVolumesTicket = myVolumesTicket_,
            myVolumesFetchError = myVolumesFetchError_,
            editMyVolumeTicket = editMyVolumeTicket_;

+ (BooksSampleWindowController *)sharedWindowController {
  static BooksSampleWindowController* gWindowController = nil;
  if (!gWindowController) {
    gWindowController = [[BooksSampleWindowController alloc] init];
  }
  return gWindowController;
}

- (id)init {
  return [self initWithWindowNibName:@"BooksSampleWindow"];
}

- (void)awakeFromNib {
  // Load the OAuth token from the keychain, if it was previously saved
  NSString *clientID = [clientIDField_ stringValue];
  NSString *clientSecret = [clientSecretField_ stringValue];

  GTMOAuth2Authentication *auth;
  auth = [GTMOAuth2WindowController authForGoogleFromKeychainForName:kKeychainItemName
                                                            clientID:clientID
                                                        clientSecret:clientSecret];
  self.booksService.authorizer = auth;

  // Set the result text fields to have a distinctive color and mono-spaced font
  [publicVolumesResultTextView_ setTextColor:[NSColor darkGrayColor]];
  [myVolumesResultTextView_ setTextColor:[NSColor darkGrayColor]];

  NSFont *resultTextFont = [NSFont fontWithName:@"Monaco" size:9];
  [publicVolumesResultTextView_ setFont:resultTextFont];
  [myVolumesResultTextView_ setFont:resultTextFont];

  [self updateUI];
}

- (void)dealloc {
  self.publicVolumes = nil;
  self.publicVolumesTicket = nil;
  self.publicVolumesFetchError = nil;

  self.bookshelves = nil;
  self.bookshelvesTicket = nil;

  self.myVolumes = nil;
  self.myVolumesTicket = nil;
  self.myVolumesFetchError = nil;

  self.editMyVolumeTicket = nil;

  [super dealloc];
}

#pragma mark -

- (NSString *)signedInUsername {
  GTMOAuth2Authentication *auth = self.booksService.authorizer;
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
    GTLServiceBooks *service = self.booksService;

    [GTMOAuth2WindowController removeAuthFromKeychainForName:kKeychainItemName];
    service.authorizer = nil;
    [self updateUI];
  }
}

- (IBAction)searchClicked:(id)sender {
  [self searchVolumes];
}

- (IBAction)cancelSearchClicked:(id)sender {
  [self.publicVolumesTicket cancelTicket];
  self.publicVolumesTicket = nil;

  [self updateUI];
}

- (IBAction)fetchMyVolumesClicked:(id)sender {
  if (![self isSignedIn]) {
    [self runSigninThenInvokeSelector:@selector(fetchMyVolumes)];
  } else {
    [self fetchMyVolumes];
  }
}

- (IBAction)cancelMyVolumesFetchClicked:(id)sender {
  [self.publicVolumesTicket cancelTicket];
  self.publicVolumesTicket = nil;

  [self.editMyVolumeTicket cancelTicket];
  self.editMyVolumeTicket = nil;

  [self updateUI];
}

- (IBAction)addToMyLibraryClicked:(id)sender {
  [self addSelectedPublicVolume];
};

- (IBAction)removeFromMyLibraryClicked:(id)sender {
  [self removeMyVolume];
};

- (IBAction)removeAllFromMyLibraryClicked:(id)sender {
  // Make the user confirm that the all books on the shelf should be deleted
  GTLBooksBookshelf *shelf = [self selectedBookshelf];
  NSAlert *alert = [[[NSAlert alloc] init] autorelease];
  alert.messageText = [NSString stringWithFormat:@"Delete %@ volumes for shelf \"%@\"?",
                       shelf.volumeCount, shelf.title];
  [alert addButtonWithTitle:@"Delete"];
  [alert addButtonWithTitle:@"Cancel"];
  [alert beginSheetModalForWindow:[self window]
                completionHandler:^(NSModalResponse returnCode) {
                  if (returnCode == NSAlertFirstButtonReturn) {
                    [self removeAllMyVolumes];
                  }
                }];
};

- (IBAction)APIConsoleClicked:(id)sender {
  NSURL *url = [NSURL URLWithString:@"https://console.developers.google.com/"];
  [[NSWorkspace sharedWorkspace] openURL:url];
}

- (IBAction)loggingCheckboxClicked:(id)sender {
  [GTMHTTPFetcher setLoggingEnabled:[sender state]];
}

#pragma mark -

// get a service object with the current username/password
//
// A "service" object handles networking tasks.  Service objects
// contain user authentication information as well as networking
// state information (such as cookies and the "last modified" date for
// fetched data.)

- (GTLServiceBooks *)booksService {

  static GTLServiceBooks* service = nil;

  if (!service) {
    service = [[GTLServiceBooks alloc] init];

    // Have the service object set tickets to fetch consecutive pages
    // of the object so we do not need to manually fetch them
    service.shouldFetchNextPages = YES;

    // Have the service object set tickets to retry temporary error conditions
    // automatically
    service.retryEnabled = YES;
  }
  return service;
}

- (GTLBooksVolume *)selectedPublicVolume {
  int rowIndex = [publicVolumesTable_ selectedRow];
  if (rowIndex > -1) {
    GTLBooksVolume *item = [self.publicVolumes itemAtIndex:rowIndex];
    return item;
  }
  return nil;
}

- (GTLBooksVolume *)selectedMyVolume {
  int rowIndex = [myVolumesTable_ selectedRow];
  if (rowIndex > -1) {
    GTLBooksVolume *item = [self.myVolumes itemAtIndex:rowIndex];
    return item;
  }
  return nil;
}

- (GTLBooksBookshelf *)selectedBookshelf {
  NSMenuItem *menuItem = [myBookshelvesPopup_ selectedItem];
  GTLBooksBookshelf *shelf = [menuItem representedObject];
  return shelf;
}

#pragma mark Search Public Volumes

- (void)searchVolumes {
  self.publicVolumes = nil;
  self.publicVolumesFetchError = nil;

  NSString *text = [keywordsField_ stringValue];
  GTLQueryBooks *query = [GTLQueryBooks queryForVolumesListWithQ:text];

  // The Books API currently requires that search queries not have an
  // authorization header (b/4445456)
  query.shouldSkipAuthorization = YES;

  // Note: setting the APIKey on the service object may give a higher
  // server quota when executing unauthorized queries
  GTLServiceBooks *service = self.booksService;
  self.publicVolumesTicket = [service executeQuery:query
                                 completionHandler:^(GTLServiceTicket *ticket,
                                                     id object, NSError *error) {
                                   // callback
                                   self.publicVolumes = object;
                                   self.publicVolumesFetchError = error;
                                   self.publicVolumesTicket = nil;

                                   [self updateUI];
                                 }];
  [self updateUI];
}

#pragma mark Fetch Bookshelves

- (void)fetchMyBookshelvesThenInvokeSelector:(SEL)sel {
  self.bookshelves = nil;
  self.myVolumesFetchError = nil;

  GTLQueryBooks *query = [GTLQueryBooks queryForMylibraryBookshelvesList];

  GTLServiceBooks *service = self.booksService;
  self.bookshelvesTicket = [service executeQuery:query
                               completionHandler:^(GTLServiceTicket *ticket,
                                                   id object, NSError *error) {
                                 // callback
                                 self.bookshelves = object;
                                 self.myVolumesFetchError = error;
                                 self.bookshelvesTicket = nil;

                                 if (error == nil) {
                                    // load the pop-up menu
                                   [self updateBookshelvesPopup];
                                   if (sel) {
                                     [self performSelector:sel];
                                   }
                                 }

                                 [self updateUI];
                               }];
  [self updateUI];
}

- (void)updateBookshelvesPopup {
  NSInteger index = [myBookshelvesPopup_ indexOfSelectedItem];
  NSMenu *menu = [myBookshelvesPopup_ menu];
  [menu removeAllItems];

  for (GTLBooksBookshelf *shelf in self.bookshelves) {
    // Make a pop-up menu item including the bookshelf name and
    // the number of books
    NSString *title = [NSString stringWithFormat:@"%@ (%@)",
                       shelf.title, shelf.volumeCount ?: @"-"];

    NSMenuItem *menuItem = [menu addItemWithTitle:title
                                           action:@selector(bookshelfPopupChanged:)
                                    keyEquivalent:@""];
    [menuItem setTarget:self];

    // Save this bookshelf in the menu item
    [menuItem setRepresentedObject:shelf];
  }
  [myBookshelvesPopup_ selectItemAtIndex:index];
}

- (void)bookshelfPopupChanged:(id)sender {
  [self fetchMyVolumes];
}

#pragma mark Fetch My Volumes

- (void)fetchMyVolumes {
  GTLBooksBookshelves *bookshelves = self.bookshelves;
  if (bookshelves == nil) {
    // Before we fetch volumes, fetch the list of bookshelves so we can
    // know which shelf of volumes to fetch
    [self fetchMyBookshelvesThenInvokeSelector:@selector(fetchMyVolumes)];
    return;
  }

  self.myVolumes = nil;
  self.myVolumesFetchError = nil;

  GTLBooksBookshelf *shelf = [self selectedBookshelf];
  
  // per b/4444470 bookshelf ID should be a string type, not a number
  NSString *shelfID = [shelf.identifier stringValue];

  GTLQueryBooks *query = [GTLQueryBooks queryForMylibraryBookshelvesVolumesListWithShelf:shelfID];

  GTLServiceBooks *service = self.booksService;
  self.myVolumesTicket = [service executeQuery:query
                             completionHandler:^(GTLServiceTicket *ticket,
                                                 id object, NSError *error) {
                               // callback
                               self.myVolumes = object;
                               self.myVolumesFetchError = error;
                               self.myVolumesTicket = nil;

                               [self updateUI];
                           }];
  [self updateUI];
}

#pragma mark Add Selected Public Volume To My Volumes

- (void)addSelectedPublicVolume {
  GTLBooksVolume *selectedVolume = [self selectedPublicVolume];
  if (selectedVolume) {
    // per b/4444470 bookshelf ID should be a string type, not a number
    GTLBooksBookshelf *shelf = [self selectedBookshelf];
    NSString *shelfID = [shelf.identifier stringValue];

    NSString *volumeID = selectedVolume.identifier;
    GTLQueryBooks *query = [GTLQueryBooks queryForMylibraryBookshelvesAddVolumeWithShelf:shelfID
                                                                                volumeId:volumeID];
    GTLServiceBooks *service = self.booksService;
    self.myVolumesTicket = [service executeQuery:query
                               completionHandler:^(GTLServiceTicket *ticket,
                                                   id object, NSError *error) {
                                 // callback
                                 self.myVolumesTicket = nil;

                                 if (error == nil) {
                                   [self displayAlert:@"Volume Added"
                                               format:@"Added \"%@\" to shelf \"%@\"",
                                    selectedVolume.volumeInfo.title, shelf.title];

                                   // Refresh the bookshelf count and the volume list
                                   self.bookshelves = nil;
                                   [self fetchMyVolumes];
                                 } else {
                                   [self displayAlert:@"Add Failed"
                                               format:@"%@", error];
                                   [self updateUI];
                                 }
                               }];
    [self updateUI];
  }
}

#pragma mark Remove My Volume

- (void)removeMyVolume {
  GTLBooksVolume *selectedVolume = [self selectedMyVolume];
  if (selectedVolume) {
    // per b/4444470 bookshelf ID should be a string type, not a number
    GTLBooksBookshelf *shelf = [self selectedBookshelf];
    NSString *shelfID = [shelf.identifier stringValue];

    NSString *volumeID = selectedVolume.identifier;
    GTLQueryBooks *query = [GTLQueryBooks queryForMylibraryBookshelvesRemoveVolumeWithShelf:shelfID
                                                                                   volumeId:volumeID];
    GTLServiceBooks *service = self.booksService;
    self.myVolumesTicket = [service executeQuery:query
                               completionHandler:^(GTLServiceTicket *ticket,
                                                   id object, NSError *error) {
                                 // callback
                                 self.myVolumesTicket = nil;

                                 if (error == nil) {
                                   [self displayAlert:@"Volume Removed"
                                               format:@"Removed \"%@\" from shelf \"%@\"",
                                    selectedVolume.volumeInfo.title, shelf.title];

                                   // Refresh the bookshelf count and the volume list
                                   self.bookshelves = nil;
                                   [self fetchMyVolumes];
                                 } else {
                                   [self displayAlert:@"Remove Failed"
                                               format:@"%@", error];
                                   [self updateUI];
                                 }
                               }];
    [self updateUI];
  }
}

#pragma mark Remove My Volume

- (void)removeAllMyVolumes {
  // per b/4444470 bookshelf ID should be a string type, not a number
  GTLBooksBookshelf *shelf = [self selectedBookshelf];
  NSString *shelfID = [shelf.identifier stringValue];

  GTLBatchQuery *batchQuery = [GTLBatchQuery batchQuery];

  for (GTLBooksVolume *volume in self.myVolumes) {
    NSString *volumeID = volume.identifier;
    GTLQueryBooks *query = [GTLQueryBooks queryForMylibraryBookshelvesRemoveVolumeWithShelf:shelfID
                                                                                   volumeId:volumeID];
    [batchQuery addQuery:query];
  }

  GTLServiceBooks *service = self.booksService;
  self.myVolumesTicket = [service executeQuery:batchQuery
                             completionHandler:^(GTLServiceTicket *ticket,
                                                 id object, NSError *error) {
                               // callback
                               self.myVolumesTicket = nil;

                               if (error == nil) {
                                 // execution succeeded
                                 GTLBatchResult *batchResults = (GTLBatchResult *)object;

                                 NSDictionary *successes = batchResults.successes;
                                 NSDictionary *failures = batchResults.failures;

                                 NSUInteger numberRemoved = [successes count];
                                 NSUInteger numberFailed = [failures count];

                                 [self displayAlert:@"Volumes Removed"
                                             format:@"Removed %lu of %lu from shelf \"%@\"",
                                  numberRemoved, numberRemoved + numberFailed,
                                  shelf.title];

                                 // Refresh the bookshelf count and the volume list
                                 self.bookshelves = nil;
                                 [self fetchMyVolumes];
                               } else {
                                 // execution failed
                                 [self displayAlert:@"Remove Failed"
                                             format:@"%@", error];
                                 [self updateUI];
                               }
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
  windowController = [GTMOAuth2WindowController controllerWithScope:@"https://www.googleapis.com/auth/books"
                                                           clientID:clientID
                                                       clientSecret:clientSecret
                                                   keychainItemName:kKeychainItemName
                                                     resourceBundle:frameworkBundle];
  [windowController signInSheetModalForWindow:[self window]
                            completionHandler:^(GTMOAuth2Authentication *auth,
                                                NSError *error) {
                              // callback
                              if (error == nil) {
                                self.booksService.authorizer = auth;
                                if (signInDoneSel) {
                                  [self performSelector:signInDoneSel];
                                }
                              } else {
                                self.myVolumesFetchError = error;
                                [self updateUI];
                              }
                            }];
}

#pragma mark UI

- (void)fetchURLString:(NSString *)newImageURLStr
       staticURLString:(NSString **)priorURLString
          forImageView:(NSImageView *)imageView
                volume:(GTLBooksVolume *)volume {
  // Common code to fetch an image for an NSImageView
  if (!GTL_AreEqualOrBothNil(newImageURLStr, *priorURLString)) {
    // The URL has changed since the previous fetch; save the new URL string
    // in the static
    *priorURLString = newImageURLStr;

    [imageView setImage:nil];

    if (newImageURLStr) {
      // Use an http fetcher to retrieve the image data
      GTMHTTPFetcherService *fetcherService = self.booksService.fetcherService;
      GTMHTTPFetcher *fetcher = [fetcherService fetcherWithURLString:newImageURLStr];

      // Book image URLs are not https so they can't be authorized
      fetcher.authorizer = nil;
      fetcher.allowedInsecureSchemes = @[ @"http" ];
      [fetcher setCommentWithFormat:@"image for volume \"%@\"",
       volume.volumeInfo.title];

      [fetcher beginFetchWithCompletionHandler:^(NSData *data, NSError *error) {
        // callback
        if (error == nil) {
          NSImage *image = [[[NSImage alloc] initWithData:data] autorelease];
          [imageView setImage:image];
        } else {
          NSLog(@"Error %@ loading image %@", error, newImageURLStr);
        }
      }];
    }
  }
}

- (void)updatePublicVolumeImage {
  static NSString* priorImageURLStr = nil;

  GTLBooksVolume *volume = [self selectedPublicVolume];
  NSString *imageURLStr = volume.volumeInfo.imageLinks.thumbnail;

  [self fetchURLString:imageURLStr
       staticURLString:&priorImageURLStr
          forImageView:publicVolumesImageView_
                volume:volume];
}

- (void)updateMyVolumeImage {
  static NSString* priorImageURLStr = nil;

  GTLBooksVolume *volume = [self selectedMyVolume];
  NSString *imageURLStr = volume.volumeInfo.imageLinks.thumbnail;

  [self fetchURLString:imageURLStr
       staticURLString:&priorImageURLStr
          forImageView:myVolumesImageView_
                volume:volume];
}

- (void)updateUI {
  BOOL isSignedIn = [self isSignedIn];
  NSString *username = [self signedInUsername];
  [signedInButton_ setTitle:(isSignedIn ? @"Sign Out" : @"Sign In")];
  [signedInField_ setStringValue:(isSignedIn ? username : @"No")];

  //
  // Public Volumes table
  //

  [publicVolumesTable_ reloadData];

  if (self.publicVolumesTicket) {
    [publicVolumesProgressIndicator_ startAnimation:self];
  } else {
    [publicVolumesProgressIndicator_ stopAnimation:self];
  }

  // Get the description of the selected item, or the fetch error
  NSString *resultStr = @"";

  if (self.publicVolumesFetchError) {
    // Display the error
    resultStr = [self.publicVolumesFetchError description];
  } else {
    // Display the selected item
    GTLBooksVolume *item = [self selectedPublicVolume];
    if (item) {
      resultStr = [item description];
    }
  }
  [publicVolumesResultTextView_ setString:resultStr];

  [self updatePublicVolumeImage];

  //
  // My Volumes table
  //

  [myVolumesTable_ reloadData];

  if (self.myVolumesTicket) {
    [myVolumesProgressIndicator_ startAnimation:self];
  } else {
    [myVolumesProgressIndicator_ stopAnimation:self];
  }

  // Get the description of the selected item, or the fetch error
  resultStr = @"";

  if (self.myVolumesFetchError) {
    // Display the error
    resultStr = [self.myVolumesFetchError description];
  } else {
    // Display the selected item
    GTLBooksVolume *item = [self selectedMyVolume];
    if (item) {
      resultStr = [item description];
    }
  }
  [myVolumesResultTextView_ setString:resultStr];

  [self updateMyVolumeImage];

  // Enable buttons
  BOOL hasSearchTerms = ([[keywordsField_ stringValue] length] > 0);
  BOOL isFetchingPublicVolumes = (self.publicVolumesTicket != nil);
  [searchButton_ setEnabled:(hasSearchTerms && !isFetchingPublicVolumes)];
  [publicVolumesCancelButton_ setEnabled:isFetchingPublicVolumes];

  BOOL isFetchingMyVolumes = (self.myVolumesTicket != nil
                              || self.editMyVolumeTicket != nil);
  [fetchMyLibraryButton_ setEnabled:(isSignedIn && !isFetchingMyVolumes)];
  [myLibraryCancelButton_ setEnabled:isFetchingMyVolumes];

  BOOL hasMyLibrary = (self.myVolumes != nil);
  BOOL isPublicLibraryVolumeSelected = ([self selectedPublicVolume] != nil);
  [addToMyLibraryButton_ setEnabled:(isPublicLibraryVolumeSelected && hasMyLibrary)];

  BOOL isMyLibraryVolumeSelected = ([self selectedMyVolume] != nil);
  [removeButton_ setEnabled:isMyLibraryVolumeSelected];

  BOOL hasMyLibraryVolumes = ([self.myVolumes.items count] > 0);
  [removeAllButton_ setEnabled:hasMyLibraryVolumes];

  BOOL hasBookshelves = (self.bookshelves != nil);
  [myBookshelvesPopup_ setEnabled:hasBookshelves];

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

// Table view data source methods
- (int)numberOfRowsInTableView:(NSTableView *)tableView {
  if (tableView == publicVolumesTable_) {
    return [self.publicVolumes.items count];
  } else {
    return [self.myVolumes.items count];
  }
}

- (id)tableView:(NSTableView *)tableView
objectValueForTableColumn:(NSTableColumn *)tableColumn
            row:(int)row {
  NSArray *items;
  if (tableView == publicVolumesTable_) {
    items = self.publicVolumes.items;
  } else {
    items = self.myVolumes.items;
  }
  GTLBooksVolume *item = [items objectAtIndex:row];
  NSString *title = item.volumeInfo.title;
  return title;
}

@end
