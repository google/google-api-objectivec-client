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
//  DriveSampleWindowController.m
//

#import "DriveSampleWindowController.h"

#import "GTL/GTLUtilities.h"
#import "GTL/GTMSessionFetcherLogging.h"

// Segmented control indices.
enum {
  kRevisionsSegment = 0,
  kPermissionsSegment,
  kChildrenSegment,
  kParentsSegment
};

// Keychain item name for saving the user's authentication information.
NSString *const kKeychainItemName = @"DriveSample: Google Drive";

@interface DriveSampleWindowController ()
@property (nonatomic, readonly) GTLServiceDrive *driveService;
@end

@implementation DriveSampleWindowController {
  GTLDriveFileList *_fileList;
  GTLServiceTicket *_fileListTicket;
  NSError *_fileListFetchError;
  GTLServiceTicket *_editFileListTicket;
  GTLServiceTicket *_uploadFileTicket;

  // Details
  GTLDriveRevisionList *_revisionList;
  NSError *_revisionListFetchError;

  GTLDrivePermissionList *_permissionList;
  NSError *_permissionListFetchError;

  GTLDriveFileList *_childList;
  NSError *_childListFetchError;

  NSArray *_parentsList;
  NSError *_parentsListFetchError;

  GTLServiceTicket *_detailsTicket;
  NSError *_detailsFetchError;
}

+ (DriveSampleWindowController *)sharedWindowController {
  static DriveSampleWindowController* gWindowController = nil;
  if (!gWindowController) {
    gWindowController = [[DriveSampleWindowController alloc] init];
  }
  return gWindowController;
}

- (id)init {
  return [self initWithWindowNibName:@"DriveSampleWindow"];
}

- (void)awakeFromNib {
  // Load the OAuth 2 token from the keychain, if it was previously saved.
  NSString *clientID = [_clientIDField stringValue];
  NSString *clientSecret = [_clientSecretField stringValue];
  if (clientSecret.length == 0) {
    clientSecret = nil;
  }

  GTMOAuth2Authentication *auth;
  auth = [GTMOAuth2WindowController authForGoogleFromKeychainForName:kKeychainItemName
                                                            clientID:clientID
                                                        clientSecret:clientSecret];
  self.driveService.authorizer = auth;

  // Set the result text fields to have a distinctive color and mono-spaced font.
  [_fileListResultTextField setTextColor:[NSColor darkGrayColor]];
  [_detailResultTextField setTextColor:[NSColor darkGrayColor]];

  NSFont *resultTextFont = [NSFont fontWithName:@"Monaco" size:9];
  [_fileListResultTextField setFont:resultTextFont];
  [_detailResultTextField setFont:resultTextFont];

  [self updateUI];
}

#pragma mark -

- (NSString *)signedInUsername {
  // Get the email address of the signed-in user.
  GTMOAuth2Authentication *auth = self.driveService.authorizer;
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
    GTLServiceDrive *service = self.driveService;

    [GTMOAuth2WindowController removeAuthFromKeychainForName:kKeychainItemName];
    service.authorizer = nil;
    [self updateUI];
  }
}

- (IBAction)segmentedControlClicked:(id)sender {
  [self updateUI];
}

- (IBAction)getFileList:(id)sender {
  if (![self isSignedIn]) {
    [self runSigninThenHandler:^{
      [self fetchFileList];
    }];
  } else {
    [self fetchFileList];
  }
}

- (IBAction)cancelFileListFetch:(id)sender {
  [_fileListTicket cancelTicket];
  _fileListTicket = nil;

  [_editFileListTicket cancelTicket];
  _editFileListTicket = nil;

  [self updateUI];
}

- (IBAction)viewClicked:(id)sender {
  GTLDriveFile *selectedFile = [self selectedFileListEntry];
  NSString *viewURLString = selectedFile.webViewLink;
  if ([viewURLString length] > 0) {
    NSURL *url = [NSURL URLWithString:viewURLString];
    [[NSWorkspace sharedWorkspace] openURL:url];
  }
}

- (IBAction)duplicateClicked:(id)sender {
  [self duplicateSelectedFile];
}

- (IBAction)trashClicked:(id)sender {
  [self changeTrashStateForSelectedFile];
}

- (IBAction)deleteClicked:(id)sender {
  GTLDriveFile *file = [self selectedFileListEntry];
  NSString *title = file.name;

  NSAlert *alert = [[NSAlert alloc] init];
  alert.messageText = [NSString stringWithFormat:@"Delete \"%@\"?", title];
  [alert addButtonWithTitle:@"Delete"];
  [alert addButtonWithTitle:@"Cancel"];
  [alert beginSheetModalForWindow:[self window]
                completionHandler:^(NSModalResponse returnCode) {
    if (returnCode == NSAlertFirstButtonReturn) {
      [self deleteSelectedFile];
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
  if ([_uploadFileTicket isUploadPaused]) {
    [_uploadFileTicket resumeUpload];
  } else {
    [_uploadFileTicket pauseUpload];
  }
  [self updateUI];
}

- (IBAction)stopUploadClicked:(id)sender {
  [_uploadFileTicket cancelTicket];
  _uploadFileTicket = nil;

  [self updateUI];
}

- (IBAction)createFolderClicked:(id)sender {
  [self createAFolder];
}

- (IBAction)APIConsoleClicked:(id)sender {
  NSURL *url = [NSURL URLWithString:@"https://console.developers.google.com/"];
  [[NSWorkspace sharedWorkspace] openURL:url];
}

- (IBAction)loggingCheckboxClicked:(id)sender {
  [GTMSessionFetcher setLoggingEnabled:[sender state]];
}

#pragma mark -

// Get a service object with the current username/password
//
// A "service" object handles networking tasks.  Service objects
// contain user authentication information as well as networking
// state information (such as cookies and the "last modified" date for
// fetched data.)

- (GTLServiceDrive *)driveService {
  static GTLServiceDrive *service;

  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
    service = [[GTLServiceDrive alloc] init];

    // The Drive API does not support the "items" property on response objects,
    // which is necessary for the server to support the GTL library's
    // shouldFetchNextPages feature.
    // service.shouldFetchNextPages = YES;

    // Have the service object set tickets to retry temporary error conditions
    // automatically
    service.retryEnabled = YES;
  });
  return service;
}

- (GTLDriveFile *)selectedFileListEntry {
  int rowIndex = [_fileListTable selectedRow];
  if (rowIndex > -1) {
    GTLDriveFile *item = _fileList.files[rowIndex];
    return item;
  }
  return nil;
}

- (id)detailCollectionArray {
  NSInteger segment = [_segmentedControl selectedSegment];
  switch (segment) {
    case kRevisionsSegment:
      return _revisionList.revisions;
    case kPermissionsSegment:
      return _permissionList.permissions;
    case kChildrenSegment:
      return _childList.files;
    case kParentsSegment:
      return _parentsList;
    default:
      return nil;
  }
}

- (id)selectedDetailItem {
  int rowIndex = [_detailTable selectedRow];
  if (rowIndex > -1) {
    NSArray *array = [self detailCollectionArray];
    GTLObject *item = array[rowIndex];
    return item;
  }
  return nil;
}

- (NSError *)detailsError {
  // First, check if the query execution succeeded.
  NSError *error = _detailsFetchError;
  if (error == nil) {
    // Next, check if there was an error for the selected detail.
    NSInteger segment = [_segmentedControl selectedSegment];
    switch (segment) {
      case kRevisionsSegment:
        return _revisionListFetchError;
      case kPermissionsSegment:
        return _permissionListFetchError;
      case kChildrenSegment:
        return _childListFetchError;
      case kParentsSegment:
        return _parentsListFetchError;
      default:
        return nil;
    }
  }
  return nil;
}

- (NSString *)descriptionForFileID:(NSString *)fileID {
  NSArray *files = _fileList.files;
  GTLDriveFile *file = [GTLUtilities firstObjectFromArray:files
                                                withValue:fileID
                                               forKeyPath:@"identifier"];
  if (file) {
    return file.name;
  } else {
    // Can't find the file by its identifier.
    return [NSString stringWithFormat:@"<%@>", fileID];
  }
}

- (NSString *)descriptionForDetailItem:(id)item {
  if ([item isKindOfClass:[GTLDriveRevision class]]) {
    return ((GTLDriveRevision *)item).modifiedTime.stringValue;
  } else if ([item isKindOfClass:[GTLDrivePermission class]]) {
    return ((GTLDrivePermission *)item).displayName;
  } else if ([item isKindOfClass:[GTLDriveFile class]]) {
    NSString *fileID = ((GTLDriveFile *)item).identifier;
    return [self descriptionForFileID:fileID];
  } else if ([item isKindOfClass:[NSString class]]) {
    // item is probably a file ID
    return [self descriptionForFileID:item];
  }
  return nil;
}

#pragma mark -
#pragma mark Fetch File List

- (void)fetchFileList {
  _fileList = nil;
  _fileListFetchError = nil;

  GTLServiceDrive *service = self.driveService;

  GTLQueryDrive *query = [GTLQueryDrive queryForFilesList];

  // Drive API v3 uses pageSize to specify the results per page (though the standard
  // for Google APIs for that is the property maxResults.)
  //
  // Because the Drive API does not return items using the standard "items" property,
  // the GTL library's shouldFetchNextPages setting cannot work.  We'll set a large pageSize
  // instead.
  query.pageSize = 150;

  // Google APIs typically allow the fields returned to be limited by the "fields" property.
  // The Drive API uses the "fields" property differently by not sending most of the requested
  // resource's fields unless they are explicitly specified.
  query.fields = @"kind,nextPageToken,files(mimeType,id,kind,name,webViewLink,thumbnailLink,trashed)";

  _fileListTicket = [service executeQuery:query
                        completionHandler:^(GTLServiceTicket *ticket,
                                            GTLDriveFileList *fileList,
                                            NSError *error) {
    // Callback
    _fileList = fileList;
    _fileListFetchError = error;
    _fileListTicket = nil;

    [self updateUI];
  }];

  [self updateUI];
}

#pragma mark Fetch File Details

- (void)fetchSelectedFileDetails {
  _revisionList = nil;
  _revisionListFetchError = nil;
  _permissionList = nil;
  _permissionListFetchError = nil;
  _childList = nil;
  _childListFetchError = nil;
  _parentsList = nil;
  _parentsListFetchError = nil;

  _detailsFetchError = nil;

  GTLServiceDrive *service = self.driveService;

  GTLDriveFile *selectedFile = [self selectedFileListEntry];
  NSString *fileID = selectedFile.identifier;
  if (fileID) {
    // Rather than make separate fetches for each kind of detail for the
    // selected file, we'll make a single batch query to etch the various
    // details.  Each query in the batch will have its own result or error,
    // and the batch query execution itself may fail with an error.
    GTLQueryDrive *revisionQuery = [GTLQueryDrive queryForRevisionsListWithFileId:fileID];
    revisionQuery.completionBlock = ^(GTLServiceTicket *ticket, GTLDriveRevisionList *obj,
                                      NSError *error) {
      _revisionList = obj;
      _revisionListFetchError = error;
    };

    GTLQueryDrive *permissionQuery = [GTLQueryDrive queryForPermissionsListWithFileId:fileID];
    permissionQuery.completionBlock = ^(GTLServiceTicket *ticket, GTLDrivePermissionList *obj,
                                      NSError *error) {
      _permissionList = obj;
      _permissionListFetchError = error;
    };

    GTLQueryDrive *childQuery = [GTLQueryDrive queryForFilesList];
    childQuery.q = [NSString stringWithFormat:@"'%@' in parents", fileID];
    childQuery.completionBlock = ^(GTLServiceTicket *ticket, GTLDriveFileList *obj,
                                   NSError *error) {
      _childList = obj;
      _childListFetchError = error;
    };

    // Note: The fields property in Google APIs is supposed to restrict
    // the fields returned for a partial query, though in the v3 Drive API
    // it is required here to return the parents field.
    GTLQueryDrive *parentsQuery = [GTLQueryDrive queryForFilesGetWithFileId:fileID];
    parentsQuery.fields = @"parents";
    parentsQuery.completionBlock = ^(GTLServiceTicket *ticket, GTLDriveFile *obj,
                                     NSError *error) {
      _parentsList = obj.parents;
      _parentsListFetchError = error;
    };

    // Combine the separate queries into one batch.
    GTLBatchQuery *batchQuery = [GTLBatchQuery batchQuery];
    [batchQuery addQuery:revisionQuery];
    [batchQuery addQuery:permissionQuery];
    [batchQuery addQuery:childQuery];
    [batchQuery addQuery:parentsQuery];

    _detailsTicket = [service executeQuery:batchQuery
                         completionHandler:^(GTLServiceTicket *ticket,
                                             GTLBatchResult *batchResult, NSError *error) {
       // Callback
       //
       // The batch query execution completionHandler runs after the individual
       // query completion handlers have been called.
       _detailsTicket = nil;
       _detailsFetchError = error;

       [self updateUI];
     }];
    [self updateUI];
  }
}

#pragma mark Delete a File

- (void)deleteSelectedFile {
  GTLServiceDrive *service = self.driveService;

  GTLDriveFile *selectedFile = [self selectedFileListEntry];
  NSString *fileID = selectedFile.identifier;
  if (fileID) {
    GTLQueryDrive *query = [GTLQueryDrive queryForFilesDeleteWithFileId:fileID];
    _editFileListTicket = [service executeQuery:query
                              completionHandler:^(GTLServiceTicket *ticket,
                                                  id nilObject,
                                                  NSError *error) {
      // Callback
      _editFileListTicket = nil;
      if (error == nil) {
        [self displayAlert:@"Deleted"
                    format:@"Deleted \"%@\"",
         selectedFile.name];
        [self updateUI];
        [self fetchFileList];
      } else {
        [self displayAlert:@"Delete Failed"
                    format:@"%@", error];
      }
    }];
  }
}

#pragma mark Toggle Trash State

- (void)changeTrashStateForSelectedFile {
  GTLServiceDrive *service = self.driveService;

  GTLDriveFile *selectedFile = [self selectedFileListEntry];
  NSString *fileID = selectedFile.identifier;
  if (fileID) {
    GTLQueryDrive *query;
    BOOL isInTrash = selectedFile.trashed.boolValue;

    GTLDriveFile *updateFile = [GTLDriveFile object];
    updateFile.trashed = isInTrash ? @NO : @YES;

    query = [GTLQueryDrive queryForFilesUpdateWithObject:updateFile
                                                  fileId:fileID
                                        uploadParameters:nil];
    _editFileListTicket = [service executeQuery:query
                              completionHandler:^(GTLServiceTicket *ticket,
                                                  id updatedObject,
                                                  NSError *error) {
                                // Callback
      _editFileListTicket = nil;
      if (error == nil) {
        NSString *fmt = (isInTrash ? @"Moved \"%@\" out of trash" : @"Moved \"%@\" to trash");
        [self displayAlert:@"Updated"
                    format:fmt, selectedFile.name];
        [self updateUI];
        [self fetchFileList];
      } else {
        [self displayAlert:@"Trash Change Failed"
                    format:@"%@", error];
      }
    }];
  }
}

#pragma mark Duplicate a File

- (void)duplicateSelectedFile {
  GTLServiceDrive *service = self.driveService;

  GTLDriveFile *selectedFile = [self selectedFileListEntry];
  NSString *fileID = selectedFile.identifier;
  if (fileID) {
    // Make a file object with the title to use for the duplicate.
    GTLDriveFile *fileObj = [GTLDriveFile object];
    fileObj.name = [NSString stringWithFormat:@"%@ copy", selectedFile.name];

    GTLQueryDrive *query = [GTLQueryDrive queryForFilesCopyWithObject:fileObj
                                                               fileId:fileID];
    _editFileListTicket = [service executeQuery:query
                              completionHandler:^(GTLServiceTicket *ticket,
                                                  GTLDriveFile *copiedFile,
                                                  NSError *error) {
      // Callback
      _editFileListTicket = nil;
      if (error == nil) {
        [self displayAlert:@"Copied"
                    format:@"Created copy \"%@\"",
         copiedFile.name];
        [self updateUI];
        [self fetchFileList];
      } else {
        [self displayAlert:@"Copy failed"
                    format:@"%@", error];
      }
    }];
  }
}

#pragma mark New Folder

- (void)createAFolder {
  GTLServiceDrive *service = self.driveService;

  GTLDriveFile *folderObj = [GTLDriveFile object];
  folderObj.name = [NSString stringWithFormat:@"New Folder %@", [NSDate date]];
  folderObj.mimeType = @"application/vnd.google-apps.folder";

  // To create a folder in a specific parent folder, specify the addParents property
  // for the query.

  GTLQueryDrive *query = [GTLQueryDrive queryForFilesCreateWithObject:folderObj
                                                     uploadParameters:nil];
  _editFileListTicket = [service executeQuery:query
                            completionHandler:^(GTLServiceTicket *ticket,
                                                GTLDriveFile *folderItem,
                                                NSError *error) {
                              // Callback
    _editFileListTicket = nil;
    if (error == nil) {
      [self displayAlert:@"Created"
                  format:@"Created folder \"%@\"",
       folderItem.name];
      [self updateUI];
      [self fetchFileList];
    } else {
      [self displayAlert:@"Create Folder Failed"
                  format:@"%@", error];
    }
  }];
}

#pragma mark Uploading

- (void)uploadFileAtPath:(NSString *)path {
  NSURL *fileToUploadURL = [NSURL fileURLWithPath:path];
  NSError *fileError;
  if (![fileToUploadURL checkPromisedItemIsReachableAndReturnError:&fileError]) {
    // Could not read file data.
    [self displayAlert:@"No Upload File Found"
                format:@"Path: %@", path];
    return;
  }

  // Queries that support file uploads take an uploadParameters object.
  // The uploadParameters include the MIME type of the file being uploaded,
  // and either an NSData with the file contents, or a URL for
  // the file path.
  GTLServiceDrive *service = self.driveService;

  NSString *filename = [path lastPathComponent];
  NSString *mimeType = [self MIMETypeFileName:filename
                              defaultMIMEType:@"binary/octet-stream"];
  GTLUploadParameters *uploadParameters =
    [GTLUploadParameters uploadParametersWithFileURL:fileToUploadURL
                                            MIMEType:mimeType];
  GTLDriveFile *newFile = [GTLDriveFile object];
  newFile.name = filename;

  GTLQueryDrive *query = [GTLQueryDrive queryForFilesCreateWithObject:newFile
                                                     uploadParameters:uploadParameters];
  _uploadFileTicket = [service executeQuery:query
                          completionHandler:^(GTLServiceTicket *ticket,
                                              GTLDriveFile *uploadedFile,
                                              NSError *error) {
    // Callback
    _uploadFileTicket = nil;
    if (error == nil) {
      [self displayAlert:@"Created"
                  format:@"Uploaded file \"%@\"",
       uploadedFile.name];
      [self fetchFileList];
    } else {
      [self displayAlert:@"Upload Failed"
                  format:@"%@", error];
    }
    [_uploadProgressIndicator setDoubleValue:0.0];
    [self updateUI];
  }];

  NSProgressIndicator *uploadProgressIndicator = _uploadProgressIndicator;
  _uploadFileTicket.uploadProgressBlock = ^(GTLServiceTicket *ticket,
                                            unsigned long long numberOfBytesRead,
                                            unsigned long long dataLength) {
    [uploadProgressIndicator setMaxValue:(double)dataLength];
    [uploadProgressIndicator setDoubleValue:(double)numberOfBytesRead];
  };
  [self updateUI];
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

#pragma mark -
#pragma mark Sign In

- (void)runSigninThenHandler:(void (^)(void))handler {
  // Applications should have client ID string hardcoded into the source, but
  // the sample application asks the developer for the strings.
  NSString *clientID = [_clientIDField stringValue];

  if ([clientID length] == 0) {
    // Remind the developer that client ID and client secret are needed
    [_clientIDButton performSelector:@selector(performClick:)
                          withObject:self
                          afterDelay:0.5];
    return;
  }

  // Client secrets are optional for Google services and can be nil.
  NSString *clientSecret = [_clientSecretField stringValue];
  if (clientSecret.length == 0) {
    clientSecret = nil;
  }

  // Show the OAuth 2 sign-in controller
  NSBundle *frameworkBundle = [NSBundle bundleForClass:[GTMOAuth2WindowController class]];
  GTMOAuth2WindowController *windowController;

  // Applications that only need to access files created by this app should
  // use kGTLAuthScopeDriveFile.
  windowController = [GTMOAuth2WindowController controllerWithScope:kGTLAuthScopeDrive
                                                           clientID:clientID
                                                       clientSecret:clientSecret
                                                   keychainItemName:kKeychainItemName
                                                     resourceBundle:frameworkBundle];

  [windowController signInSheetModalForWindow:[self window]
                            completionHandler:^(GTMOAuth2Authentication *auth,
                                                NSError *error) {
    // Callback
    if (error == nil) {
      self.driveService.authorizer = auth;
      if (handler) handler();
    } else {
      _fileListFetchError = error;
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
  // File list table
  //
  [_fileListTable reloadData];

  if (_fileListTicket != nil || _editFileListTicket != nil) {
    [_fileListProgressIndicator startAnimation:self];
  } else {
    [_fileListProgressIndicator stopAnimation:self];
  }

  // Get the description of the selected item, or the feed fetch error
  NSString *resultStr = @"";

  if (_fileListFetchError) {
    // Display the error
    resultStr = [_fileListFetchError description];

    // Also display any server data present
    NSDictionary *errorInfo = [_fileListFetchError userInfo];
    NSData *errData = errorInfo[kGTMSessionFetcherStatusDataKey];
    if (errData) {
      NSString *dataStr = [[NSString alloc] initWithData:errData
                                                encoding:NSUTF8StringEncoding];
      resultStr = [resultStr stringByAppendingFormat:@"\n%@", dataStr];
    }
  } else {
    // Display the selected item
    GTLDriveFile *item = [self selectedFileListEntry];
    if (item) {
      resultStr = [item description];
    }
  }
  [_fileListResultTextField setString:resultStr];

  [self updateThumbnailImage];

  //
  // Details table
  //

  [_detailTable reloadData];

  if (_detailsTicket != nil) {
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
  NSUInteger numberOfRevisions = _revisionList.revisions.count;
  NSUInteger numberOfPermissions = _permissionList.permissions.count;
  NSUInteger numberOfChildren = _childList.files.count;
  NSUInteger numberOfParents = _parentsList.count;

  NSString *revisionsStr = [NSString stringWithFormat:@"Revisions %lu", numberOfRevisions];
  NSString *permissionsStr = [NSString stringWithFormat:@"Permissions %lu", numberOfPermissions];
  NSString *childrenStr = [NSString stringWithFormat:@"Children %lu", numberOfChildren];
  NSString *parentsStr = [NSString stringWithFormat:@"Parents %lu", numberOfParents];

  [_segmentedControl setLabel:revisionsStr forSegment:kRevisionsSegment];
  [_segmentedControl setLabel:permissionsStr forSegment:kPermissionsSegment];
  [_segmentedControl setLabel:childrenStr forSegment:kChildrenSegment];
  [_segmentedControl setLabel:parentsStr forSegment:kParentsSegment];

  // Enable buttons
  BOOL isFetchingFileList = (_fileListTicket != nil);
  BOOL isEditingFileList = (_editFileListTicket != nil);
  [_fileListCancelButton setEnabled:(isFetchingFileList || isEditingFileList)];

  BOOL isFetchingDetails = (_detailsTicket != nil);
  [_detailCancelButton setEnabled:isFetchingDetails];

  GTLDriveFile *selectedFile = [self selectedFileListEntry];
  NSString *webViewLink = selectedFile.webViewLink;
  BOOL isFileViewable = (webViewLink != nil);
  [_viewButton setEnabled:isFileViewable];

  BOOL isFileSelected = (selectedFile != nil);
  [_deleteButton setEnabled:isFileSelected];
  [_trashButton setEnabled:isFileSelected];

  BOOL isInTrash = selectedFile.trashed.boolValue;
  NSString *trashTitle = (isInTrash ? @"Untrash" : @"Trash");
  [_trashButton setTitle:trashTitle];

  [_duplicateButton setEnabled:isFileSelected];

  BOOL hasFileList = (_fileList != nil);
  [_newFolderButton setEnabled:hasFileList];

  BOOL isUploading = (_uploadFileTicket != nil);
  [_uploadButton setEnabled:(hasFileList && !isUploading)];
  [_pauseUploadButton setEnabled:isUploading];
  [_stopUploadButton setEnabled:isUploading];

  BOOL isUploadPaused = [_uploadFileTicket isUploadPaused];
  NSString *pauseTitle = (isUploadPaused ? @"Resume" : @"Pause");
  [_pauseUploadButton setTitle:pauseTitle];

  // Show or hide the text indicating that the client ID is needed
  BOOL hasClientIDStrings = [[_clientIDField stringValue] length] > 0;
  [_clientIDRequiredTextField setHidden:hasClientIDStrings];
}

- (void)updateThumbnailImage {
  // We will fetch the thumbnail image if its URL is different from the one
  // currently displayed.
  static NSString *gDisplayedURLStr = nil;
  GTLDriveFile *selectedFile = [self selectedFileListEntry];

  NSString *thumbnailURLStr = selectedFile.thumbnailLink;

  if (!GTL_AreEqualOrBothNil(gDisplayedURLStr, thumbnailURLStr)) {
    [_thumbnailView setImage:nil];

    gDisplayedURLStr = [thumbnailURLStr copy];

    if (thumbnailURLStr) {
      GTMSessionFetcher *fetcher =
          [self.driveService.fetcherService fetcherWithURLString:thumbnailURLStr];
      fetcher.authorizer = self.driveService.authorizer;
      [fetcher setCommentWithFormat:@"Thumbnail for \"%@\"", selectedFile.name];
      [fetcher beginFetchWithCompletionHandler:^(NSData *data, NSError *error) {
        if (data) {
          NSImage *image = [[NSImage alloc] initWithData:data];
          if (image) {
            [_thumbnailView setImage:image];
          } else {
            NSLog(@"Failed to make image from %lu bytes for \"%@\"",
                  (unsigned long) [data length], selectedFile.name);
          }
        } else {
          NSLog(@"Failed to fetch thumbnail for \"%@\", %@",
                selectedFile.name, error);
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
  [[self window] beginSheet:_clientIDSheet completionHandler:nil];
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
  if ([notification object] == _fileListTable) {
    [self fetchSelectedFileDetails];
  }
}

// Table view data source methods
- (int)numberOfRowsInTableView:(NSTableView *)tableView {
  NSArray *array;
  if (tableView == _fileListTable) {
    array = _fileList.files;
  } else {
    array = [self detailCollectionArray];
  }
  return array.count;
}

- (id)tableView:(NSTableView *)tableView
objectValueForTableColumn:(NSTableColumn *)tableColumn
            row:(NSInteger)row {
  if (tableView == _fileListTable) {
    GTLDriveFile *file = _fileList.files[row];
    return [self fileTitleWithLabelsForFile:file];
  } else {
    NSArray *array = [self detailCollectionArray];
    id item = array[row];
    return [self descriptionForDetailItem:item];
  }
}

- (NSString *)fileTitleWithLabelsForFile:(GTLDriveFile *)file {

  NSMutableString *title = [NSMutableString stringWithString:file.name];

  if (file.starred.boolValue) {
    [title appendString:@" \u2605"]; // star character
  }
  if (file.trashed.boolValue) {
    [title insertString:@"\u2717 " atIndex:0]; // X character
  }
  if (file.viewersCanCopyContent.boolValue) {
    [title appendString:@" \u21DF"]; // crossed down arrow character
  }
  return title;
}

@end
