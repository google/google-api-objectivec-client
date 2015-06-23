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
//  StorageSampleWindowController.m
//

#import "StorageSampleWindowController.h"

#import "GTLUtilities.h"
#import "GTMHTTPFetcherLogging.h"

// Segmented control indices.
enum {
  kObjectsSegment = 0,
  kAccessControlsSegment,
  kDefaultAccessControlsSegment,
};

// Menu item title for downloading the original file.
static NSString *const kOriginalFile = @"Original File";

// Keychain item name for saving the user's authentication information.
NSString *const kKeychainItemName = @"StorageSample: Google Cloud Storage";

@interface StorageSampleWindowController ()
@property (nonatomic, readonly) GTLServiceStorage *storageService;
@end

@implementation StorageSampleWindowController {
  GTLStorageBuckets *_bucketList;
  GTLServiceTicket *_bucketListTicket;
  NSError *_bucketListFetchError;
  GTLServiceTicket *_editBucketListTicket;

  GTLServiceTicket *_uploadObjectTicket;

  // Details
  GTLStorageObjects *_objectsList;
  GTLServiceTicket *_objectsListTicket;
  NSError *_objectsListFetchError;

  GTLStorageBucketAccessControls *_bucketAccessControlsList;
  GTLStorageObjectAccessControls *_defaultObjectAccessControlsList;
}

+ (StorageSampleWindowController *)sharedWindowController {
  static StorageSampleWindowController* gWindowController = nil;
  if (!gWindowController) {
    gWindowController = [[StorageSampleWindowController alloc] init];
  }
  return gWindowController;
}

- (id)init {
  return [self initWithWindowNibName:@"StorageSampleWindow"];
}

- (void)awakeFromNib {
  // Load the OAuth 2 token from the keychain, if it was previously saved.
  NSString *clientID = [_clientIDField stringValue];
  NSString *clientSecret = [_clientSecretField stringValue];

  GTMOAuth2Authentication *auth;
  auth = [GTMOAuth2WindowController authForGoogleFromKeychainForName:kKeychainItemName
                                                            clientID:clientID
                                                        clientSecret:clientSecret];
  self.storageService.authorizer = auth;

  // Set the result text fields to have a distinctive color and mono-spaced font.
  [_bucketListResultTextField setTextColor:[NSColor darkGrayColor]];
  [_detailResultTextField setTextColor:[NSColor darkGrayColor]];

  NSFont *resultTextFont = [NSFont fontWithName:@"Monaco" size:9];
  [_bucketListResultTextField setFont:resultTextFont];
  [_detailResultTextField setFont:resultTextFont];

  [self updateUI];
}

#pragma mark -

- (NSString *)signedInUsername {
  // Get the email address of the signed-in user.
  GTMOAuth2Authentication *auth = self.storageService.authorizer;
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
    [self runSigninThenHandler:^{
      [self updateUI];
    }];
  } else {
    // Sign out
    GTLServiceStorage *service = self.storageService;

    [GTMOAuth2WindowController removeAuthFromKeychainForName:kKeychainItemName];
    service.authorizer = nil;
    [self updateUI];
  }
}

- (IBAction)segmentedControlClicked:(id)sender {
  [self updateUI];
}

- (IBAction)getBucketList:(id)sender {
  if (![self isSignedIn]) {
    [self runSigninThenHandler:^{
      [self fetchBucketList];
    }];
  } else {
    [self fetchBucketList];
  }
}

- (IBAction)cancelBucketList:(id)sender {
  [_bucketListTicket cancelTicket];
  _bucketListTicket = nil;

  [_editBucketListTicket cancelTicket];
  _editBucketListTicket = nil;

  [self updateUI];
}

- (IBAction)cancelObjectsListFetch:(id)sender {
  [_objectsListTicket cancelTicket];
  _objectsListTicket = nil;

  [self updateUI];
}

- (IBAction)downloadFileClicked:(id)sender {
  __block GTLStorageObject *storageObject = (GTLStorageObject *)[self selectedDetailItem];

  NSString *suggestedName = [storageObject.name lastPathComponent];
  NSSavePanel *savePanel = [NSSavePanel savePanel];
  [savePanel setNameFieldStringValue:suggestedName];
  [savePanel beginSheetModalForWindow:[self window]
                    completionHandler:^(NSInteger result) {
    // Callback
    if (result == NSFileHandlingPanelOKButton) {
      __block NSString *savePath = [[savePanel URL] path];
      GTLQueryStorage *query = [GTLQueryStorage queryForObjectsGetWithBucket:storageObject.bucket
                                                                      object:storageObject.name];
      [query setUrlQueryParameters: @{ @"alt": @"media" }];

      GTLServiceStorage *service = self.storageService;
      [service executeQuery:query
          completionHandler:^(GTLServiceTicket *ticket, id object, NSError *error) {
        NSString *urlString = nil;

        // Error should be a redirect. Typically 303, though that may change.
        GTLErrorObject *errorObject = [[error userInfo] objectForKey:@"GTLStructuredError"];
        if ([[errorObject code] isEqual:@303]) {
          urlString = [errorObject additionalPropertyForName:@"location"];

          // Use a GTMHTTPFetcher object to download the file with authorization.
          GTMHTTPFetcher *fetcher = [self.storageService.fetcherService fetcherWithURLString:urlString];

          // The fetcher can save data directly to a file.
          fetcher.downloadPath = savePath;

          // Fetcher logging can include comments.
          [fetcher setCommentWithFormat:@"Downloading \"%@/%@\"", storageObject.bucket, storageObject.name];

          fetcher.receivedDataBlock = ^(NSData *receivedData) {
            // The fetcher will call the received data block periodically.
            // When a download path has been specified, the received data
            // parameter will be nil.
          };

          [fetcher beginFetchWithCompletionHandler:^(NSData *data, NSError *error) {
            // Callback
            if (error == nil) {
              // Successfully saved the file.
              //
              // Since a downloadPath property was specified, the data argument is
              // nil, and the file data has been written to disk.
              [self displayAlert:@"Downloaded"
                          format:@"%@", savePath];
            } else {
              [self displayAlert:@"Error Downloading File"
                          format:@"%@", error];
            }
          }];
        } else {
          // Not sure how to handle the response from the server.
          NSLog(@"Expected a redirect from the service, but didn't get one.");
          NSLog(@"Object: %@", object);
          NSLog(@"Error: %@; as GTLErrorObject: %@", error, errorObject);
        }
      }];
    }
  }];
}

- (IBAction)addBucketClicked:(id)sender {
  // Show the sheet for creating a new bucket
  [_bucketAddName setStringValue:@""];
  [[self window] beginSheet:_bucketAddSheet completionHandler:nil];
}

- (IBAction)addBucketCancelClicked:(id)sender {
  [[self window] endSheet:[sender window]];
  [self updateUI];
}

- (IBAction)addBucketAddClicked:(id)sender {
  [[self window] endSheet:[sender window]];
  NSString *name = [_bucketAddName stringValue];
  [self addBucket:name];
  [self updateUI];
}

- (IBAction)deleteBucketClicked:(id)sender {
  GTLStorageBucket *bucket = [self selectedBucketListEntry];
  NSString *title = bucket.name;

  NSAlert *alert = [[NSAlert alloc] init];
  alert.messageText = [NSString stringWithFormat:@"Delete \"%@\"?", title];
  [alert addButtonWithTitle:@"Delete"];
  [alert addButtonWithTitle:@"Cancel"];
  [alert beginSheetModalForWindow:[self window]
                completionHandler:^(NSModalResponse returnCode) {
    if (returnCode == NSAlertFirstButtonReturn) {
      [self deleteSelectedBucket];
    }
  }];
}

- (IBAction)uploadFileClicked:(id)sender {
  // Ask the user to choose a file.
  NSOpenPanel *openPanel = [NSOpenPanel openPanel];
  [openPanel setPrompt:@"Upload"];
  [openPanel setCanChooseDirectories:NO];
  [openPanel beginSheetModalForWindow:[self window]
                    completionHandler:^(NSInteger result) {
    // Callback.
    if (result == NSFileHandlingPanelOKButton) {
      // The user chose a file and clicked OK.
      //
      // Start uploading (deferred briefly since
      // we currently have a sheet displayed).
      NSString *path = [[openPanel URL] path];
      [self performSelector:@selector(uploadFileAtPath:)
                 withObject:path
                 afterDelay:0.1];
    }
  }];
}

- (IBAction)pauseUploadClicked:(id)sender {
  if ([_uploadObjectTicket isUploadPaused]) {
    [_uploadObjectTicket resumeUpload];
  } else {
    [_uploadObjectTicket pauseUpload];
  }
  [self updateUI];
}

- (IBAction)stopUploadClicked:(id)sender {
  [_uploadObjectTicket cancelTicket];
  _uploadObjectTicket = nil;

  [self updateUI];
}

- (IBAction)createFolderClicked:(id)sender {
  //[self createAFolder];
}

- (IBAction)APIConsoleClicked:(id)sender {
  NSURL *url = [NSURL URLWithString:@"https://code.google.com/apis/console"];
  [[NSWorkspace sharedWorkspace] openURL:url];
}

- (IBAction)loggingCheckboxClicked:(id)sender {
  [GTMHTTPFetcher setLoggingEnabled:[sender state]];
}

// Get a service object with the current username/password
//
// A "service" object handles networking tasks.  Service objects
// contain user authentication information as well as networking
// state information (such as cookies and the "last modified" date for
// fetched data.)

- (GTLServiceStorage *)storageService {
    static GTLServiceStorage *service;

    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        service = [[GTLServiceStorage alloc] init];

        // Have the service object set tickets to fetch consecutive pages
        // of the feed so we do not need to manually fetch them
        service.shouldFetchNextPages = YES;

        // Have the service object set tickets to retry temporary error conditions
        // automatically
        service.retryEnabled = YES;
    });
    return service;
}

- (GTLStorageBucket *)selectedBucketListEntry {
  int rowIndex = [_bucketListTable selectedRow];
  if (rowIndex > -1) {
    // GTLCollectionObjects like GTLStorageBuckets support indexed
    // access to the collection items
    GTLStorageBucket *item = _bucketList[rowIndex];
    return item;
  }
  return nil;
}

- (id)detailCollection {
  NSInteger segment = [_segmentedControl selectedSegment];
  switch (segment) {
    case kObjectsSegment:
      return _objectsList;
    case kAccessControlsSegment:
      return _bucketAccessControlsList;
    case kDefaultAccessControlsSegment:
      return _defaultObjectAccessControlsList;
    default:
      return nil;
  }
}

- (id)selectedDetailItem {
  int rowIndex = [_detailTable selectedRow];
  if (rowIndex > -1) {
    GTLCollectionObject *collection = [self detailCollection];
    GTLObject *item = collection[rowIndex];
    return item;
  }
  return nil;
}

- (NSError *)detailsError {
  return _objectsListFetchError;
}

- (NSString *)descriptionForDetailItem:(id)item {
  if ([item isKindOfClass:[GTLStorageObject class]]) {
    return ((GTLStorageObject *)item).name;
  } else if ([item isKindOfClass:[GTLStorageBucketAccessControl class]]) {
    GTLStorageBucketAccessControl *bucketAccessControl = ((GTLStorageBucketAccessControl *)item);
    return [NSString stringWithFormat:@"%@ – %@", bucketAccessControl.entity, bucketAccessControl.role];
  } else if ([item isKindOfClass:[GTLStorageObjectAccessControl class]]) {
    GTLStorageObjectAccessControl *objectAccessControl = ((GTLStorageObjectAccessControl *)item);
    return [NSString stringWithFormat:@"%@ – %@", objectAccessControl.entity, objectAccessControl.role];
  }
  return nil;
}

#pragma mark -
#pragma mark Get project
- (NSString *)project {
  // Pull project string off of the client id.
  //
  // This sample uses the API client's project as the project to work with, requiring that
  // project has the Google Storage Service turned on,
  // TODO(nherring): one better would be to have this simply be the default and let clients
  // choose a different project to list buckets from. Add edit field?
  NSCharacterSet *dotSet = [NSCharacterSet characterSetWithCharactersInString:@"."];
  NSRange dotRange = [[_clientIDField stringValue] rangeOfCharacterFromSet:dotSet];
  if (dotRange.location == NSNotFound) {
    return NULL;  // No can do. Presumably this is an invalid project #.
  }
  NSRange projectRange = {0, dotRange.location};
  
  return [[_clientIDField stringValue] substringWithRange:projectRange];
}

#pragma mark Fetch Bucket List

- (void)fetchBucketList {
  _bucketList = nil;
  _bucketListFetchError = nil;

  GTLServiceStorage *service = self.storageService;
  NSString *projectString = [self project];
  GTLQueryStorage *query = [GTLQueryStorage queryForBucketsListWithProject:projectString];

  // maxResults specifies the number of results per page.  Since we earlier
  // specified shouldFetchNextPages=YES, all results should be fetched,
  // though specifying a larger maxResults will reduce the number of fetches
  // needed to retrieve all pages.
  query.maxResults = 150;

  // The default set of metadata returned excludes ACLs, so let's specify all
  // metadata.
  query.projection = @"full";

  // The Cloud Storage JSON API's bucket entries have data that the app may not
  // care about. Specifying the fields we want here reduces the network
  // bandwidth and memory needed for the collection.
  //
  // For example, leave query.fields as nil during development.
  // When ready to test and optimize your app, specify just the fields needed.
  // For example, this sample app might use
  //
  query.fields = @"kind,items(id,storageClass,defaultObjectAcl,owner,metageneration,projectNumber,location,timeCreated,acl,kind,website,name,etag)";

  _bucketListTicket = [service executeQuery:query
                         completionHandler:^(GTLServiceTicket *ticket,
                                             GTLStorageBuckets *bucketList,
                                             NSError *error) {
                          // Callback
                          _bucketList = bucketList;
                          _bucketListFetchError = error;
                          _bucketListTicket = nil;

                          [self updateUI];
                        }];

  [self updateUI];
}

#pragma mark Fetch Bucket Details

- (void)fetchSelectedBucketDetails {
  _objectsList = nil;
  _objectsListFetchError = nil;
  _bucketAccessControlsList = nil;
  _defaultObjectAccessControlsList = nil;

  GTLServiceStorage *service = self.storageService;

  GTLStorageBucket *selectedBucket = [self selectedBucketListEntry];
  NSString *bucketName = selectedBucket.name;
  if (bucketName) {
    // Get an object listing for the bucket.
    GTLQueryStorage *query = [GTLQueryStorage queryForObjectsListWithBucket:bucketName];
    query.maxResults = 150;
    query.fields = @"kind,items(id,generation,updated,owner,metageneration,contentType,crc32c,size,md5Hash,bucket,kind,etag,name)";

    _objectsListTicket = [service executeQuery:query
                             completionHandler:^(GTLServiceTicket *ticket, GTLStorageObjects *objectsList, NSError *error) {
                               // Callback
                               _objectsList = objectsList;
                               _objectsListFetchError = error;
                               _objectsListTicket = nil;

                               [self updateUI];
                             }];

    // Also, update the ACLs. Since the bucket property "acl" is just an NSArray
    // rather than a GTLStorageBucketAccessControls, we'll formulate one.
    _bucketAccessControlsList = [GTLStorageBucketAccessControls object];
    _bucketAccessControlsList.items = selectedBucket.acl;
    _defaultObjectAccessControlsList = [GTLStorageObjectAccessControls object];
    _defaultObjectAccessControlsList.items = selectedBucket.defaultObjectAcl;
    [self updateUI];
  }
}

#pragma mark Add a bucket

- (void)addBucket:(NSString *)bucketName {
  GTLServiceStorage *service = self.storageService;
  GTLStorageBucket* storageBucket = [GTLStorageBucket object];
  [storageBucket setName:bucketName];
  // Other interesting settings include location and storage class
  [storageBucket setLocation:@"US"];
  [storageBucket setStorageClass:@"STANDARD"];
  NSString *projectString = [self project];

  GTLQueryStorage *query = [GTLQueryStorage queryForBucketsInsertWithObject:storageBucket
                                                                    project:projectString];
  _editBucketListTicket = [service executeQuery:query
                              completionHandler:^(GTLServiceTicket *ticket,
                                                  id nilObject,
                                                  NSError *error) {
    // Callback
    _editBucketListTicket = nil;
    if (error == nil) {
        [self displayAlert:@"Added"
                    format:@"Added \"%@\"",
         bucketName];
        [self updateUI];
        [self fetchBucketList];
      } else {
        [self displayAlert:@"Add Failed"
                    format:@"%@", error];
      }
    }];
}

#pragma mark Delete a Bucket

- (void)deleteSelectedBucket {
  GTLServiceStorage *service = self.storageService;

  GTLStorageBucket *selectedBucket = [self selectedBucketListEntry];
  NSString *bucketID = selectedBucket.identifier;
  if (bucketID) {
    GTLQueryStorage *query = [GTLQueryStorage queryForBucketsDeleteWithBucket:selectedBucket.name];
    _editBucketListTicket = [service executeQuery:query
                                completionHandler:^(GTLServiceTicket *ticket,
                                                    id nilObject,
                                                    NSError *error) {
      // Callback
      _editBucketListTicket = nil;
      if (error == nil) {
        [self displayAlert:@"Deleted"
                    format:@"Deleted \"%@\"",
         selectedBucket.name];
        [self updateUI];
        [self fetchBucketList];
      } else {
        [self displayAlert:@"Delete Failed"
                    format:@"%@", error];
      }
    }];
  }
}

#pragma mark Uploading

- (void)uploadFileAtPath:(NSString *)path {
  // Queries that support file uploads take an uploadParameters object.
  // The uploadParameters include the MIME type of the file being uploaded,
  // and either an NSData with the file contents, or an NSFileHandler for
  // the file path.
  NSFileHandle *fileHandle = [NSFileHandle fileHandleForReadingAtPath:path];
  if (fileHandle) {
    GTLServiceStorage *service = self.storageService;

    NSString *filename = [path lastPathComponent];
    NSString *mimeType = [self MIMETypeFileName:filename
                                defaultMIMEType:@"binary/octet-stream"];
    GTLUploadParameters *uploadParameters =
      [GTLUploadParameters uploadParametersWithFileHandle:fileHandle
                                                 MIMEType:mimeType];
    GTLStorageObject *newObject = [GTLStorageObject object];
    newObject.name = [path lastPathComponent];

    GTLQueryStorage *query = [GTLQueryStorage queryForObjectsInsertWithObject:newObject
                                                                       bucket:[[self selectedBucketListEntry] name]
                                                             uploadParameters:uploadParameters];
    _uploadObjectTicket = [service executeQuery:query
                            completionHandler:^(GTLServiceTicket *ticket,
                                                GTLStorageObject *uploadedFile,
                                                NSError *error) {
      // Callback
      _uploadObjectTicket = nil;
      if (error == nil) {
        [self displayAlert:@"Created"
                    format:@"Uploaded file \"%@\"",
         uploadedFile.name];
         [self fetchSelectedBucketDetails];
      } else {
        [self displayAlert:@"Upload Failed"
                    format:@"%@", error];
      }
      [_uploadProgressIndicator setDoubleValue:0.0];
      [self updateUI];
    }];

    NSProgressIndicator *uploadProgressIndicator = _uploadProgressIndicator;
    _uploadObjectTicket.uploadProgressBlock = ^(GTLServiceTicket *ticket,
                                              unsigned long long numberOfBytesRead,
                                              unsigned long long dataLength) {
      [uploadProgressIndicator setMaxValue:(double)dataLength];
      [uploadProgressIndicator setDoubleValue:(double)numberOfBytesRead];
    };
    [self updateUI];
  } else {
    // Could not read file data.
    [self displayAlert:@"No Upload File Found" format:@"Path: %@", path];
  }
}

- (NSString *)MIMETypeFileName:(NSString *)path
                    defaultMIMEType:(NSString *)defaultType {
  NSString *result = defaultType;
  NSString *extension = [path pathExtension];
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

#pragma mark Downloading

- (NSString *)extensionForMIMEType:(NSString *)mimeType {
  NSString *result = nil;
  CFStringRef uti = UTTypeCreatePreferredIdentifierForTag(kUTTagClassMIMEType,
      (__bridge CFStringRef)mimeType, NULL);
  if (uti) {
    CFStringRef cfExtn = UTTypeCopyPreferredTagWithClass(uti, kUTTagClassFilenameExtension);
    if (cfExtn) {
      result = CFBridgingRelease(cfExtn);
    }
    CFRelease(uti);
  }
  return result;
}

#pragma mark -
#pragma mark Sign In

- (void)runSigninThenHandler:(void (^)(void))handler {
  // Applications should have client ID and client secret strings
  // hardcoded into the source, but the sample application asks the
  // developer for the strings.
  NSString *clientID = [_clientIDField stringValue];
  NSString *clientSecret = [_clientSecretField stringValue];

  if ([clientID length] == 0 || [clientSecret length] == 0) {
    // Remind the developer that client ID and client secret are needed
    [_clientIDButton performSelector:@selector(performClick:)
                          withObject:self
                          afterDelay:0.5];
    return;
  }

  // Show the OAuth 2 sign-in controller
  NSBundle *frameworkBundle = [NSBundle bundleForClass:[GTMOAuth2WindowController class]];
  GTMOAuth2WindowController *windowController;

  // Applications that only need to access files created by this app should
  // use kGTLAuthScopeStorageDevstorageReadOnly.
  windowController = [GTMOAuth2WindowController controllerWithScope:kGTLAuthScopeStorageDevstorageFullControl
                                                           clientID:clientID
                                                       clientSecret:clientSecret
                                                   keychainItemName:kKeychainItemName
                                                     resourceBundle:frameworkBundle];

  [windowController signInSheetModalForWindow:[self window]
                            completionHandler:^(GTMOAuth2Authentication *auth,
                                                NSError *error) {
    // Callback
    if (error == nil) {
        self.storageService.authorizer = auth;
      if (handler) handler();
    } else {
      _objectsListFetchError = error;
      [self updateUI];
    }
  }];
}

#pragma mark -
#pragma mark UI

- (void)updateUI {
  BOOL isSignedIn = [self isSignedIn];
  NSString *username = [self signedInUsername];
  [_signedInButton setTitle:(isSignedIn ? @"Sign Out" : @"Sign In")];
  [_signedInField setStringValue:(isSignedIn ? username : @"No")];

  //
  // Bucket list table
  //
  [_bucketListTable reloadData];

  if (_bucketListTicket != nil) {
    [_bucketListProgressIndicator startAnimation:self];
  } else {
    [_bucketListProgressIndicator stopAnimation:self];
  }

  // Get the description of the selected item, or the feed fetch error
  NSString *resultStr = @"";

  if (_bucketListFetchError) {
    // Display the error
    resultStr = [_bucketListFetchError description];

    // Also display any server data present
    NSDictionary *errorInfo = [_bucketListFetchError userInfo];
    NSData *errData = errorInfo[kGTMHTTPFetcherStatusDataKey];
    if (errData) {
      NSString *dataStr = [[NSString alloc] initWithData:errData
                                                encoding:NSUTF8StringEncoding];
      resultStr = [resultStr stringByAppendingFormat:@"\n%@", dataStr];
    }
  } else {
    // Display the selected item
    GTLStorageBucket *item = [self selectedBucketListEntry];
    if (item) {
      resultStr = [item description];
    } else {
      _bucketAccessControlsList = nil;
      _defaultObjectAccessControlsList = nil;
    }
  }
  [_bucketListResultTextField setString:resultStr];

  //
  // Details table
  //

  [_detailTable reloadData];

  if (_objectsListTicket != nil) {
    [_detailProgressIndicator startAnimation:self];
  } else {
    [_detailProgressIndicator stopAnimation:self];
  }

  // Get the description of the selected item, or the feed fetch error
  resultStr = @"";

  NSError *error = [self detailsError];
  if (error) {
    resultStr = [error description];
  } else {
    id item = [self selectedDetailItem];
    if (item) {
      resultStr = [item description];
    }
  }

  [_detailResultTextField setString:resultStr];

  // Update the counts in the segmented control
  NSUInteger numberOfObjects = [_objectsList.items count];
  NSUInteger numberOfAccessControls = [_bucketAccessControlsList.items count];
  NSUInteger numberOfDefaultAccessControls = [_defaultObjectAccessControlsList.items count];

  NSString *objectsStr = [NSString stringWithFormat:@"Objects %lu", numberOfObjects];
  NSString *accessControlsStr = [NSString stringWithFormat:@"Access Controls %lu", numberOfAccessControls];
  NSString *defaultAccessControlsStr = [NSString stringWithFormat:@"Default Access Controls %lu", numberOfDefaultAccessControls];

  [_segmentedControl setLabel:objectsStr forSegment:kObjectsSegment];
  [_segmentedControl setLabel:accessControlsStr forSegment:kAccessControlsSegment];
  [_segmentedControl setLabel:defaultAccessControlsStr forSegment:kDefaultAccessControlsSegment];

  // Enable buttons
  BOOL isFetchingBucketList = (_bucketListTicket != nil);
  BOOL isEditingBucketList = (_editBucketListTicket != nil);
  [_bucketListCancelButton setEnabled:(isFetchingBucketList || isEditingBucketList)];

  BOOL isFetchingDetails = (_objectsListTicket != nil);
  [_detailCancelButton setEnabled:isFetchingDetails];

  BOOL hasObjectsList = (_objectsList != nil);

  BOOL isUploading = (_uploadObjectTicket != nil);
  [_uploadButton setEnabled:(hasObjectsList && !isUploading)];
  [_pauseUploadButton setEnabled:isUploading];
  [_stopUploadButton setEnabled:isUploading];

  BOOL isUploadPaused = [_uploadObjectTicket isUploadPaused];
  NSString *pauseTitle = (isUploadPaused ? @"Resume" : @"Pause");
  [_pauseUploadButton setTitle:pauseTitle];

  BOOL canDownload = ([_segmentedControl selectedSegment] == kObjectsSegment &&
                      [self selectedDetailItem] != nil);
  [_downloadButton setEnabled:canDownload];

  // Show or hide the text indicating that the client ID or client secret are
  // needed
  BOOL hasClientIDStrings = [[_clientIDField stringValue] length] > 0
    && [[_clientSecretField stringValue] length] > 0;
  [_clientIDRequiredTextField setHidden:hasClientIDStrings];
  // And bucket listing needs the project from the client ID as well.
  [_bucketListButton setEnabled:[[_clientIDField stringValue] length] > 0];
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

- (IBAction)clientIDClicked:(id)sender {
  // Show the sheet for developers to enter their client ID and client secret
  [[self window] beginSheet:_clientIDSheet completionHandler:nil];
}

- (IBAction)clientIDDoneClicked:(id)sender {
  [[self window] endSheet:[sender window]];
  [self updateUI];
}

#pragma mark Text field delegate methods

- (void)controlTextDidChange:(NSNotification *)note {
  [self updateUI];  // enable and disable buttons
}

#pragma mark TableView delegate and data source methods

- (void)tableViewSelectionDidChange:(NSNotification *)notification {
  [self updateUI];
  if ([notification object] == _bucketListTable) {
    [self fetchSelectedBucketDetails];
  }
}

// Table view data source methods
- (int)numberOfRowsInTableView:(NSTableView *)tableView {
  GTLCollectionObject *collection;
  if (tableView == _bucketListTable) {
    collection = _bucketList;
  } else {
    collection = [self detailCollection];
  }
  return [collection.items count];
}

- (id)tableView:(NSTableView *)tableView
objectValueForTableColumn:(NSTableColumn *)tableColumn
            row:(NSInteger)row {
  if (tableView == _bucketListTable) {
    // GTLCollectionObjects support indexed access to the collection items
    GTLStorageBucket *bucket = _bucketList[row];
    return bucket.name;
  } else {
    GTLCollectionObject *collection = [self detailCollection];
    GTLObject *item = collection[row];
    return [self descriptionForDetailItem:item];
  }
}

@end
