/* Copyright (c) 2012 Google Inc.
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
//  YouTubeSampleWindowController.m
//

#if !defined(__has_feature) || !__has_feature(objc_arc)
#error "This file requires ARC support."
#endif

#import "YouTubeSampleWindowController.h"

#import "GTL/GTLUtilities.h"
#import "GTL/GTMHTTPUploadFetcher.h"
#import "GTL/GTMHTTPFetcherLogging.h"
#import "GTL/GTMOAuth2WindowController.h"

enum {
  // Playlist pop-up menu item tags.
  kUploadsTag = 0,
  kLikesTag = 1,
  kFavoritesTag = 2,
  kWatchHistoryTag = 3,
  kWatchLaterTag = 4
};

// Keychain item name for saving the user's authentication information.
NSString *const kKeychainItemName = @"YouTubeSample: YouTube";

@interface YouTubeSampleWindowController ()
// Accessor for the app's single instance of the service object.
@property (nonatomic, readonly) GTLServiceYouTube *youTubeService;
@end

@implementation YouTubeSampleWindowController {
  GTLYouTubeChannelContentDetailsRelatedPlaylists *_myPlaylists;
  GTLServiceTicket *_channelListTicket;
  NSError *_channelListFetchError;

  GTLYouTubePlaylistItemListResponse *_playlistItemList;
  GTLServiceTicket *_playlistItemListTicket;
  NSError *_playlistFetchError;

  GTLServiceTicket *_uploadFileTicket;
  NSURL *_uploadLocationURL;  // URL for restarting an upload.
}

+ (YouTubeSampleWindowController *)sharedWindowController {
  static YouTubeSampleWindowController* gWindowController = nil;
  if (!gWindowController) {
    gWindowController = [[YouTubeSampleWindowController alloc] init];
  }
  return gWindowController;
}

- (id)init {
  return [self initWithWindowNibName:@"YouTubeSampleWindow"];
}

- (void)awakeFromNib {
  // Load the OAuth 2 token from the keychain, if it was previously saved.
  NSString *clientID = [_clientIDField stringValue];
  NSString *clientSecret = [_clientSecretField stringValue];

  GTMOAuth2Authentication *auth =
      [GTMOAuth2WindowController authForGoogleFromKeychainForName:kKeychainItemName
                                                         clientID:clientID
                                                     clientSecret:clientSecret];
  self.youTubeService.authorizer = auth;

  // Set the result text fields to have a distinctive color and mono-spaced font.
  [_playlistResultTextField setTextColor:[NSColor darkGrayColor]];

  NSFont *resultTextFont = [NSFont fontWithName:@"Monaco" size:9];
  [_playlistResultTextField setFont:resultTextFont];

  [_uploadPathField setStringValue:@""];

  // Fetch the list of categories for video uploads.
  [_uploadCategoryPopup setEnabled:NO];

  [self updateUI];
}

#pragma mark -

- (NSString *)signedInUsername {
  // Get the email address of the signed-in user.
  GTMOAuth2Authentication *auth = self.youTubeService.authorizer;
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
    // Sign in.
    [self runSigninThenHandler:^{
      [self updateUI];
    }];
  } else {
    // Sign out.
    GTLServiceYouTube *service = self.youTubeService;

    [GTMOAuth2WindowController removeAuthFromKeychainForName:kKeychainItemName];
    service.authorizer = nil;
    [self updateUI];
  }
}

- (IBAction)getPlaylist:(id)sender {
  void (^getPlaylist)(void) = ^{
    if (_myPlaylists == nil) {
      [self fetchMyChannelList];
    } else {
      [self fetchSelectedPlaylist];
    }
  };

  if (![self isSignedIn]) {
    [self runSigninThenHandler:getPlaylist];
  } else {
    getPlaylist();
  }
}

- (IBAction)playlistPopupClicked:(id)sender {
  [self getPlaylist:sender];
}

- (IBAction)cancelPlaylistFetch:(id)sender {
  [_channelListTicket cancelTicket];
  _channelListTicket = nil;

  [_playlistItemListTicket cancelTicket];
  _playlistItemListTicket = nil;

  [self updateUI];
}

- (IBAction)chooseFileClicked:(id)sender {
  // Ask the user to choose a video file for uploading.
  NSOpenPanel *openPanel = [NSOpenPanel openPanel];
  [openPanel setPrompt:@"Choose"];

  [openPanel setAllowedFileTypes:@[ @"mov", @"mp4" ]];
  [openPanel beginSheetModalForWindow:[self window]
                    completionHandler:^(NSInteger result) {
    // Callback
    if (result == NSFileHandlingPanelOKButton) {
      // The user chose a file.
      NSString *path = [[openPanel URL] path];
      [_uploadPathField setStringValue:path];

      [self updateUI]; // Update UI in case we need to enable the upload button.
    }
  }];
}

- (IBAction)uploadClicked:(id)sender {
  [self uploadVideoFile];
}

- (IBAction)pauseUploadClicked:(id)sender {
  if ([_uploadFileTicket isUploadPaused]) {
    // Resume from pause.
    [_uploadFileTicket resumeUpload];
  } else {
    // Pause.
    [_uploadFileTicket pauseUpload];
  }

  [self updateUI];
}

- (IBAction)stopUploadClicked:(id)sender {
  [_uploadFileTicket cancelTicket];
  _uploadFileTicket = nil;

  [_uploadProgressIndicator setDoubleValue:0.0];
  [self updateUI];
}

- (IBAction)restartUploadClicked:(id)sender {
  [self restartUpload];
}

- (IBAction)APIConsoleClicked:(id)sender {
  NSURL *url = [NSURL URLWithString:@"https://console.developers.google.com/"];
  [[NSWorkspace sharedWorkspace] openURL:url];
}

- (IBAction)loggingCheckboxClicked:(id)sender {
  [GTMHTTPFetcher setLoggingEnabled:[sender state]];
}

#pragma mark -

// Get a service object with the current username/password.
//
// A "service" object handles networking tasks.  Service objects
// contain user authentication information as well as networking
// state information such as cookies set by the server in response
// to queries.

- (GTLServiceYouTube *)youTubeService {
  static GTLServiceYouTube *service;

  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
    service = [[GTLServiceYouTube alloc] init];

    // Have the service object set tickets to fetch consecutive pages
    // of the feed so we do not need to manually fetch them.
    service.shouldFetchNextPages = YES;

    // Have the service object set tickets to retry temporary error conditions
    // automatically.
    service.retryEnabled = YES;
  });
  return service;
}

- (GTLYouTubePlaylistItem *)selectedPlaylistItem {
  NSInteger row = [_playlistItemTable selectedRow];
  GTLYouTubePlaylistItem *item = _playlistItemList[row];
  return item;
}

#pragma mark - Fetch Playlist

- (void)fetchMyChannelList {
  _myPlaylists = nil;
  _channelListFetchError = nil;

  GTLServiceYouTube *service = self.youTubeService;

  GTLQueryYouTube *query = [GTLQueryYouTube queryForChannelsListWithPart:@"contentDetails"];
  query.mine = YES;

  // maxResults specifies the number of results per page.  Since we earlier
  // specified shouldFetchNextPages=YES, all results should be fetched,
  // though specifying a larger maxResults will reduce the number of fetches
  // needed to retrieve all pages.
  query.maxResults = 50;

  // We can specify the fields we want here to reduce the network
  // bandwidth and memory needed for the fetched collection.
  //
  // For example, leave query.fields as nil during development.
  // When ready to test and optimize your app, specify just the fields needed.
  // For example, this sample app might use
  //
  // query.fields = @"kind,etag,items(id,etag,kind,contentDetails)";

  _channelListTicket = [service executeQuery:query
                        completionHandler:^(GTLServiceTicket *ticket,
                                            GTLYouTubeChannelListResponse *channelList,
                                            NSError *error) {
    // Callback

    // The contentDetails of the response has the playlists available for
    // "my channel".
    if ([[channelList items] count] > 0) {
      GTLYouTubeChannel *channel = channelList[0];
      _myPlaylists = channel.contentDetails.relatedPlaylists;
    }
    _channelListFetchError = error;
    _channelListTicket = nil;

    if (_myPlaylists) {
      [self fetchSelectedPlaylist];
    }

    [self fetchVideoCategories];
  }];

  [self updateUI];
}

- (void)fetchSelectedPlaylist {
  NSString *playlistID = nil;
  NSInteger tag = [_playlistPopup selectedTag];
  switch(tag) {
    case kUploadsTag:      playlistID = _myPlaylists.uploads; break;
    case kLikesTag:        playlistID = _myPlaylists.likes; break;
    case kFavoritesTag:    playlistID = _myPlaylists.favorites; break;
    case kWatchHistoryTag: playlistID = _myPlaylists.watchHistory; break;
    case kWatchLaterTag:   playlistID = _myPlaylists.watchLater; break;
    default: NSAssert(0, @"Unexpected tag: %ld", tag);
  }

  if ([playlistID length] > 0) {
    GTLServiceYouTube *service = self.youTubeService;

    GTLQueryYouTube *query = [GTLQueryYouTube queryForPlaylistItemsListWithPart:@"snippet,contentDetails"];
    query.playlistId = playlistID;
    query.maxResults = 50;

    _playlistItemListTicket = [service executeQuery:query
                                   completionHandler:^(GTLServiceTicket *ticket,
                                                       GTLYouTubePlaylistItemListResponse *playlistItemList,
                                                       NSError *error) {
       // Callback
       _playlistItemList = playlistItemList;
       _playlistFetchError = error;
       _playlistItemListTicket = nil;

       [self updateUI];
     }];
  }
  [self updateUI];
}

- (void)fetchVideoCategories {
  // For uploading, we want the category popup to have a list of all categories
  // that may be assigned to a video.
  GTLServiceYouTube *service = self.youTubeService;

  GTLQueryYouTube *query = [GTLQueryYouTube queryForVideoCategoriesListWithPart:@"snippet,id"];
  query.regionCode = [[NSLocale currentLocale] objectForKey:NSLocaleCountryCode];

  [service executeQuery:query
      completionHandler:^(GTLServiceTicket *ticket,
                          GTLYouTubeVideoCategoryListResponse *categoryList,
                          NSError *error) {
      if (error) {
        NSLog(@"Could not fetch video category list: %@", error);
      } else {
        // We will build a menu with the category names as menu item titles,
        // and category ID strings as the menu item represented
        // objects.
        NSMenu *categoryMenu = [[NSMenu alloc] init];
        for (GTLYouTubeVideoCategory *category in categoryList) {
          NSString *title = category.snippet.title;
          NSString *categoryID = category.identifier;
          NSMenuItem *item = [[NSMenuItem alloc] initWithTitle:title
                                                        action:NULL
                                                 keyEquivalent:@""];
          [item setRepresentedObject:categoryID];
          [categoryMenu addItem:item];
        }
        [_uploadCategoryPopup setMenu:categoryMenu];
        [_uploadCategoryPopup setEnabled:YES];
      }
   }];
}

#pragma mark - Upload

- (void)uploadVideoFile {
  // Collect the metadata for the upload from the user interface.

  // Status.
  GTLYouTubeVideoStatus *status = [GTLYouTubeVideoStatus object];
  status.privacyStatus = [_uploadPrivacyPopup titleOfSelectedItem];

  // Snippet.
  GTLYouTubeVideoSnippet *snippet = [GTLYouTubeVideoSnippet object];
  snippet.title = [_uploadTitleField stringValue];
  NSString *desc = [_uploadDescriptionField stringValue];
  if ([desc length] > 0) {
    snippet.descriptionProperty = desc;
  }
  NSString *tagsStr = [_uploadTagsField stringValue];
  if ([tagsStr length] > 0) {
    snippet.tags = [tagsStr componentsSeparatedByString:@","];
  }
  if ([_uploadCategoryPopup isEnabled]) {
    NSMenuItem *selectedCategory = [_uploadCategoryPopup selectedItem];
    snippet.categoryId = [selectedCategory representedObject];
  }

  GTLYouTubeVideo *video = [GTLYouTubeVideo object];
  video.status = status;
  video.snippet = snippet;

  [self uploadVideoWithVideoObject:video
           resumeUploadLocationURL:nil];
}

- (void)restartUpload {
  // Restart a stopped upload, using the location URL from the previous
  // upload attempt
  if (_uploadLocationURL == nil) return;

  // Since we are restarting an upload, we do not need to add metadata to the
  // video object.
  GTLYouTubeVideo *video = [GTLYouTubeVideo object];

  [self uploadVideoWithVideoObject:video
           resumeUploadLocationURL:_uploadLocationURL];
}

- (void)uploadVideoWithVideoObject:(GTLYouTubeVideo *)video
           resumeUploadLocationURL:(NSURL *)locationURL {
  // Get a file handle for the upload data.
  NSString *path = [_uploadPathField stringValue];
  NSString *filename = [path lastPathComponent];
  NSFileHandle *fileHandle = [NSFileHandle fileHandleForReadingAtPath:path];
  if (fileHandle) {
    NSString *mimeType = [self MIMETypeForFilename:filename
                                   defaultMIMEType:@"video/mp4"];
    GTLUploadParameters *uploadParameters =
        [GTLUploadParameters uploadParametersWithFileHandle:fileHandle
                                                   MIMEType:mimeType];
    uploadParameters.uploadLocationURL = locationURL;

    GTLQueryYouTube *query = [GTLQueryYouTube queryForVideosInsertWithObject:video
                                                                        part:@"snippet,status"
                                                            uploadParameters:uploadParameters];

    GTLServiceYouTube *service = self.youTubeService;
    _uploadFileTicket = [service executeQuery:query
                            completionHandler:^(GTLServiceTicket *ticket,
                                                GTLYouTubeVideo *uploadedVideo,
                                                NSError *error) {
        // Callback
        _uploadFileTicket = nil;
        if (error == nil) {
          [self displayAlert:@"Uploaded"
                      format:@"Uploaded file \"%@\"",
           uploadedVideo.snippet.title];

          if ([_playlistPopup selectedTag] == kUploadsTag) {
            // Refresh the displayed uploads playlist.
            [self fetchSelectedPlaylist];
          }
        } else {
          [self displayAlert:@"Upload Failed"
                      format:@"%@", error];
        }

        [_uploadProgressIndicator setDoubleValue:0.0];
        _uploadLocationURL = nil;
        [self updateUI];
      }];

    NSProgressIndicator *progressIndicator = _uploadProgressIndicator;
    _uploadFileTicket.uploadProgressBlock = ^(GTLServiceTicket *ticket,
                                              unsigned long long numberOfBytesRead,
                                              unsigned long long dataLength) {
      [progressIndicator setMaxValue:(double)dataLength];
      [progressIndicator setDoubleValue:(double)numberOfBytesRead];
    };

    // To allow restarting after stopping, we need to track the upload location
    // URL.
    //
    // For compatibility with systems that do not support Objective-C blocks
    // (iOS 3 and Mac OS X 10.5), the location URL may also be obtained in the
    // progress callback as ((GTMHTTPUploadFetcher *)[ticket objectFetcher]).locationURL

    GTMHTTPUploadFetcher *uploadFetcher = (GTMHTTPUploadFetcher *)[_uploadFileTicket objectFetcher];
    uploadFetcher.locationChangeBlock = ^(NSURL *url) {
      _uploadLocationURL = url;
      [self updateUI];
    };

    [self updateUI];
  } else {
    // Could not read file data.
    [self displayAlert:@"File Not Found" format:@"Path: %@", path];
  }
}

- (NSString *)MIMETypeForFilename:(NSString *)filename
                  defaultMIMEType:(NSString *)defaultType {
  NSString *result = defaultType;
  NSString *extension = [filename pathExtension];
  CFStringRef uti = UTTypeCreatePreferredIdentifierForTag(kUTTagClassFilenameExtension,
      (__bridge CFStringRef)extension, NULL);
  if (uti) {
    CFStringRef cfMIMEType = UTTypeCopyPreferredTagWithClass(uti, kUTTagClassMIMEType);
    if (cfMIMEType) {
      result = CFBridgingRelease(cfMIMEType);
    }
    CFRelease(uti);
  }
  return result;
}

#pragma mark - Sign In

- (void)runSigninThenHandler:(void (^)(void))handler {
  // Applications should have client ID and client secret strings
  // hardcoded into the source, but the sample application asks the
  // developer for the strings.
  NSString *clientID = [_clientIDField stringValue];
  NSString *clientSecret = [_clientSecretField stringValue];

  if ([clientID length] == 0 || [clientSecret length] == 0) {
    // Remind the developer that client ID and client secret are needed.
    [_clientIDButton performSelector:@selector(performClick:)
                          withObject:self
                          afterDelay:0.5];
    return;
  }

  // Show the OAuth 2 sign-in controller.
  NSBundle *frameworkBundle = [NSBundle bundleForClass:[GTMOAuth2WindowController class]];
  GTMOAuth2WindowController *windowController =
      [GTMOAuth2WindowController controllerWithScope:kGTLAuthScopeYouTube
                                            clientID:clientID
                                        clientSecret:clientSecret
                                    keychainItemName:kKeychainItemName
                                      resourceBundle:frameworkBundle];

  [windowController signInSheetModalForWindow:[self window]
                            completionHandler:^(GTMOAuth2Authentication *auth,
                                                NSError *error) {
    // Callback
    if (error == nil) {
      self.youTubeService.authorizer = auth;
      if (handler) handler();
    } else {
      _channelListFetchError = error;
      [self updateUI];
    }
  }];
}

#pragma mark - UI

- (void)updateUI {
  BOOL isSignedIn = [self isSignedIn];
  NSString *username = [self signedInUsername];
  [_signedInButton setTitle:(isSignedIn ? @"Sign Out" : @"Sign In")];
  [_signedInField setStringValue:(isSignedIn ? username : @"No")];

  //
  // Playlist table.
  //
  [_playlistItemTable reloadData];

  BOOL isFetchingPlaylist = (_channelListTicket != nil || _playlistItemListTicket != nil);
  if (isFetchingPlaylist) {
    [_playlistProgressIndicator startAnimation:self];
  } else {
    [_playlistProgressIndicator stopAnimation:self];
  }

  // Get the description of the selected item, or the feed fetch error
  NSString *resultStr = @"";
  NSError *error;

  if (_channelListFetchError) {
    error = _channelListFetchError;
  } else {
    error = _playlistFetchError;
  }

  if (error) {
    // Display the error.
    resultStr = [error description];

    // Also display any server data present
    NSDictionary *errorInfo = [error userInfo];
    NSData *errData = errorInfo[kGTMHTTPFetcherStatusDataKey];
    if (errData) {
      NSString *dataStr = [[NSString alloc] initWithData:errData
                                                encoding:NSUTF8StringEncoding];
      resultStr = [resultStr stringByAppendingFormat:@"\n%@", dataStr];
    }
  } else {
    // Display the selected item.
    GTLYouTubePlaylistItem *item = [self selectedPlaylistItem];
    if (item) {
      resultStr = [item description];
    }
  }
  [_playlistResultTextField setString:resultStr];

  [self updateThumbnailImage];

  //
  // Enable buttons
  //
  [_fetchPlaylistButton setEnabled:(!isFetchingPlaylist)];
  [_playlistPopup setEnabled:(isSignedIn && !isFetchingPlaylist)];
  [_playlistCancelButton setEnabled:isFetchingPlaylist];

  BOOL hasUploadTitle = ([[_uploadTitleField stringValue] length] > 0);
  BOOL hasUploadFile = ([[_uploadPathField stringValue] length] > 0);
  BOOL isUploading = (_uploadFileTicket != nil);
  BOOL isPaused = (isUploading && [_uploadFileTicket isUploadPaused]);
  BOOL canUpload = (isSignedIn && hasUploadFile && hasUploadTitle && !isUploading);
  BOOL canRestartUpload = (_uploadLocationURL != nil);
  [_uploadButton setEnabled:canUpload];
  [_pauseUploadButton setEnabled:isUploading];
  [_pauseUploadButton setTitle:(isPaused ? @"Resume" : @"Pause")];
  [_stopUploadButton setEnabled:isUploading];
  [_restartUploadButton setEnabled:canRestartUpload];

  // Show or hide the text indicating that the client ID or client secret are
  // needed
  BOOL hasClientIDStrings = [[_clientIDField stringValue] length] > 0
    && [[_clientSecretField stringValue] length] > 0;
  [_clientIDRequiredTextField setHidden:hasClientIDStrings];
}

- (void)updateThumbnailImage {
  // We will fetch the thumbnail image if its URL is different from the one
  // currently displayed.
  static NSString *gDisplayedURLStr = nil;

  GTLYouTubePlaylistItem *playlistItem = [self selectedPlaylistItem];
  GTLYouTubeThumbnailDetails *thumbnails = playlistItem.snippet.thumbnails;
  GTLYouTubeThumbnail *thumbnail = thumbnails.defaultProperty;
  NSString *thumbnailURLStr = thumbnail.url;

  if (!GTL_AreEqualOrBothNil(gDisplayedURLStr, thumbnailURLStr)) {
    [_thumbnailView setImage:nil];

    gDisplayedURLStr = [thumbnailURLStr copy];

    if (thumbnailURLStr) {
      GTMHTTPFetcher *fetcher = [GTMHTTPFetcher fetcherWithURLString:thumbnailURLStr];
      fetcher.authorizer = self.youTubeService.authorizer;

      NSString *title = playlistItem.snippet.title;
      [fetcher setCommentWithFormat:@"Thumbnail for \"%@\"", title];
      [fetcher beginFetchWithCompletionHandler:^(NSData *data, NSError *error) {
        if (data) {
          NSImage *image = [[NSImage alloc] initWithData:data];
          if (image) {
            [_thumbnailView setImage:image];
          } else {
            NSLog(@"Failed to make image from %lu bytes for \"%@\"",
                  (unsigned long) [data length], title);
          }
        } else {
          NSLog(@"Failed to fetch thumbnail for \"%@\", %@",  title, error);
        }
      }];
    }
  }
}

- (void)displayAlert:(NSString *)title format:(NSString *)format, ... {
  NSString *result = format;
  if (format) {
    va_list argList;
    va_start(argList, format);
    result = [[NSString alloc] initWithFormat:format
                                    arguments:argList];
    va_end(argList);
  }
  NSAlert *alert = [[NSAlert alloc] init];
  alert.messageText = title;
  alert.informativeText = result;
  [alert beginSheetModalForWindow:[self window]
                completionHandler:nil];
}

#pragma mark - Client ID Sheet

// Client ID and Client Secret Sheet
//
// Sample apps need this sheet to ask for the client ID and client secret
// strings.
//
// Your application will just hardcode the client ID and client secret strings
// into the source rather than ask the user for them.
//
// The string values are obtained from the API Console,
// https://console.developers.google.com/

- (IBAction)clientIDClicked:(id)sender {
  // Show the sheet for developers to enter their client ID and client secret
  [[self window] beginSheet:_clientIDSheet completionHandler:nil];
}

- (IBAction)clientIDDoneClicked:(id)sender {
  [[self window] endSheet:[sender window]];
}

#pragma mark - Text field delegate methods

- (void)controlTextDidChange:(NSNotification *)note {
  [self updateUI];  // enable and disable buttons
}

#pragma mark - TableView delegate and data source methods

- (void)tableViewSelectionDidChange:(NSNotification *)notification {
  [self updateUI];
}

// Table view data source methods.
- (NSInteger)numberOfRowsInTableView:(NSTableView *)tableView {
  if (tableView == _playlistItemTable) {
    return [_playlistItemList.items count];
  }
  return 0;
}

- (id)tableView:(NSTableView *)tableView
objectValueForTableColumn:(NSTableColumn *)tableColumn
            row:(NSInteger)row {
  if (tableView == _playlistItemTable) {
    GTLYouTubePlaylistItem *item = _playlistItemList[row];
    NSString *title = item.snippet.title;
    return title;
  }
  return nil;
}

@end
