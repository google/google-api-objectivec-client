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
#import "GTL/GTMHTTPFetcherLogging.h"

// Segmented control indices.
enum {
  kRevisionsSegment = 0,
  kPermissionsSegment,
  kChildrenSegment,
  kParentsSegment
};

// Menu item title for downloading the original file.
static NSString *const kOriginalFile = @"Original File";

@interface DriveSampleWindowController ()

@property (readonly) GTLServiceDrive *driveService;

// File List
@property (retain) GTLDriveFileList *fileList;
@property (retain) GTLServiceTicket *fileListTicket;
@property (retain) NSError *fileListFetchError;
@property (retain) GTLServiceTicket *editFileListTicket;
@property (retain) GTLServiceTicket *uploadFileTicket;

// Details
@property (retain) GTLDriveRevisionList *revisionList;
@property (retain) NSError *revisionListFetchError;

@property (retain) GTLDrivePermissionList *permissionList;
@property (retain) NSError *permissionListFetchError;

@property (retain) GTLDriveChildList *childList;
@property (retain) NSError *childListFetchError;

@property (retain) GTLDriveParentList *parentsList;
@property (retain) NSError *parentsListFetchError;

@property (retain) GTLServiceTicket *detailsTicket;
@property (retain) NSError *detailsFetchError;

@end

// Keychain item name for saving the user's authentication information.
NSString *const kKeychainItemName = @"DriveSample: Google Drive";

@implementation DriveSampleWindowController

@synthesize fileList = fileList_,
            fileListTicket = fileListTicket_,
            fileListFetchError = fileListFetchError_,
            editFileListTicket = editFileListTicket_,
            uploadFileTicket = uploadFileTicket_;

@synthesize revisionList = revisionList_,
            revisionListFetchError = revisionListFetchError_,
            permissionList = permissionList_,
            permissionListFetchError = permissionListFetchError_,
            childList = childList_,
            childListFetchError = childListFetchError_,
            parentsList = parentsList_,
            parentsListFetchError = parentsListFetchError_,
            detailsTicket = detailsTicket_,
            detailsFetchError = detailsFetchError_;

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
  NSString *clientID = [clientIDField_ stringValue];
  NSString *clientSecret = [clientSecretField_ stringValue];

  GTMOAuth2Authentication *auth;
  auth = [GTMOAuth2WindowController authForGoogleFromKeychainForName:kKeychainItemName
                                                            clientID:clientID
                                                        clientSecret:clientSecret];
  self.driveService.authorizer = auth;

  // Set the result text fields to have a distinctive color and mono-spaced font.
  [fileListResultTextField_ setTextColor:[NSColor darkGrayColor]];
  [detailResultTextField_ setTextColor:[NSColor darkGrayColor]];

  NSFont *resultTextFont = [NSFont fontWithName:@"Monaco" size:9];
  [fileListResultTextField_ setFont:resultTextFont];
  [detailResultTextField_ setFont:resultTextFont];

  [self updateUI];
}

- (void)dealloc {
  [fileList_ release];
  [fileListTicket_ release];
  [fileListFetchError_ release];
  [editFileListTicket_ release];
  [uploadFileTicket_ release];

  [revisionList_ release];
  [revisionListFetchError_ release];
  [permissionList_ release];
  [permissionListFetchError_ release];
  [childList_ release];
  [childListFetchError_ release];
  [parentsList_ release];
  [parentsListFetchError_ release];
  [detailsTicket_ release];
  [detailsFetchError_ release];

  [super dealloc];
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
    [self runSigninThenInvokeSelector:@selector(updateUI)];
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
    [self runSigninThenInvokeSelector:@selector(fetchFileList)];
  } else {
    [self fetchFileList];
  }
}

- (IBAction)cancelFileListFetch:(id)sender {
  [self.fileListTicket cancelTicket];
  self.fileListTicket = nil;

  [self.editFileListTicket cancelTicket];
  self.editFileListTicket = nil;

  [self updateUI];
}

- (IBAction)viewClicked:(id)sender {
  GTLDriveFile *selectedFile = [self selectedFileListEntry];
  NSString *viewURLString = selectedFile.alternateLink;
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
  NSString *title = file.title;

  NSBeginAlertSheet(@"Delete", nil, @"Cancel", nil,
                    [self window], self,
                    @selector(deleteFileSheetDidEnd:returnCode:contextInfo:),
                    nil, nil, @"Delete \"%@\"?", title);
}

- (void)deleteFileSheetDidEnd:(NSWindow *)sheet
                   returnCode:(int)returnCode
                  contextInfo:(void *)contextInfo {
  if (returnCode == NSAlertDefaultReturn) {
    [self deleteSelectedFile];
  }
}

- (IBAction)uploadFileClicked:(id)sender {
  // Ask the user to choose a file.
  NSOpenPanel *openPanel = [NSOpenPanel openPanel];
  [openPanel setPrompt:@"Upload"];
  [openPanel setCanChooseDirectories:NO];
  [openPanel beginSheetModalForWindow:[self window]
                    completionHandler:^(NSInteger result) {
    // Callback.
    if (result == NSOKButton) {
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
  if ([self.uploadFileTicket isUploadPaused]) {
    [self.uploadFileTicket resumeUpload];
  } else {
    [self.uploadFileTicket pauseUpload];
  }
  [self updateUI];
}

- (IBAction)stopUploadClicked:(id)sender {
  [self.uploadFileTicket cancelTicket];
  self.uploadFileTicket = nil;

  [self updateUI];
}

- (IBAction)createFolderClicked:(id)sender {
  [self createAFolder];
}

- (IBAction)APIConsoleClicked:(id)sender {
  NSURL *url = [NSURL URLWithString:@"https://code.google.com/apis/console"];
  [[NSWorkspace sharedWorkspace] openURL:url];
}

- (IBAction)loggingCheckboxClicked:(id)sender {
  [GTMHTTPFetcher setLoggingEnabled:[sender state]];
}

#pragma mark -

// Get a service object with the current username/password
//
// A "service" object handles networking tasks.  Service objects
// contain user authentication information as well as networking
// state information (such as cookies and the "last modified" date for
// fetched data.)

- (GTLServiceDrive *)driveService {
  static GTLServiceDrive *service = nil;

  if (!service) {
    service = [[GTLServiceDrive alloc] init];

    // Have the service object set tickets to fetch consecutive pages
    // of the feed so we do not need to manually fetch them
    service.shouldFetchNextPages = YES;

    // Have the service object set tickets to retry temporary error conditions
    // automatically
    service.retryEnabled = YES;
  }
  return service;
}

- (GTLDriveFile *)selectedFileListEntry {
  int rowIndex = [fileListTable_ selectedRow];
  if (rowIndex > -1) {
    GTLDriveFile *item = [self.fileList itemAtIndex:rowIndex];
    return item;
  }
  return nil;
}

- (id)detailCollection {
  NSInteger segment = [segmentedControl_ selectedSegment];
  switch (segment) {
    case kRevisionsSegment:
      return self.revisionList;
    case kPermissionsSegment:
      return self.permissionList;
    case kChildrenSegment:
      return self.childList;
    case kParentsSegment:
      return self.parentsList;
    default:
      return nil;
  }
}

- (id)selectedDetailItem {
  int rowIndex = [detailTable_ selectedRow];
  if (rowIndex > -1) {
    GTLCollectionObject *collection = [self detailCollection];
    GTLObject *item = [collection itemAtIndex:rowIndex];
    return item;
  }
  return nil;
}

- (NSError *)detailsError {
  // First, check if the query execution succeeded.
  NSError *error = self.detailsFetchError;
  if (error == nil) {
    // Next, check if there was an error for the selected detail.
    NSInteger segment = [segmentedControl_ selectedSegment];
    switch (segment) {
      case kRevisionsSegment:
        return self.revisionListFetchError;
      case kPermissionsSegment:
        return self.permissionListFetchError;
      case kChildrenSegment:
        return self.childListFetchError;
      case kParentsSegment:
        return self.parentsListFetchError;
      default:
        return nil;
    }
  }
  return nil;
}

- (NSString *)descriptionForFileID:(NSString *)fileID {
  NSArray *files = self.fileList.items;
  GTLDriveFile *file = [GTLUtilities firstObjectFromArray:files
                                                withValue:fileID
                                               forKeyPath:@"identifier"];
  if (file) {
    return file.title;
  } else {
    // Can't find the file by its identifier.
    return [NSString stringWithFormat:@"<%@>", fileID];
  }
}

- (NSString *)descriptionForDetailItem:(id)item {
  if ([item isKindOfClass:[GTLDriveRevision class]]) {
    return ((GTLDriveRevision *)item).modifiedDate.stringValue;
  } else if ([item isKindOfClass:[GTLDrivePermission class]]) {
    return ((GTLDrivePermission *)item).name;
  } else if ([item isKindOfClass:[GTLDriveChildReference class]]) {
    NSString *childID = ((GTLDriveChildReference *)item).identifier;
    return [self descriptionForFileID:childID];
  } else if ([item isKindOfClass:[GTLDriveParentReference class]]) {
    GTLDriveParentReference *parentRef = ((GTLDriveParentReference *)item);
    if ([[parentRef isRoot] boolValue]) {
      return @"<root folder>";
    } else {
      NSString *parentID = parentRef.identifier;
      return [self descriptionForFileID:parentID];
    }
  }
  return nil;
}

#pragma mark -
#pragma mark Fetch File List

- (void)fetchFileList {
  self.fileList = nil;
  self.fileListFetchError = nil;

  GTLServiceDrive *service = self.driveService;

  GTLQueryDrive *query = [GTLQueryDrive queryForFilesList];

  // maxResults specifies the number of results per page.  Since we earlier
  // specified shouldFetchNextPages=YES, all results should be fetched,
  // though specifying a larger maxResults will reduce the number of fetches
  // needed to retrieve all pages.
  query.maxResults = 150;

  // The Drive API's file entries are chock full of data that the app may not
  // care about. Specifying the fields we want here reduces the network
  // bandwidth and memory needed for the collection.
  //
  // For example, leave query.files as nil during development.
  // When ready to test and optimize your app, specify just the fields needed.
  // For example, this sample app might use
  //
  // query.fields = @"kind,etag,items(id,downloadUrl,editable,etag,exportLinks,kind,labels,originalFilename,title)";

  self.fileListTicket = [service executeQuery:query
                            completionHandler:^(GTLServiceTicket *ticket,
                                                GTLDriveFileList *fileList,
                                                NSError *error) {
    // Callback
    self.fileList = fileList;
    self.fileListFetchError = error;
    self.fileListTicket = nil;

    [self updateUI];
  }];

  [self updateUI];
}

#pragma mark Fetch File Details

- (void)fetchSelectedFileDetails {
  self.revisionList = nil;
  self.revisionListFetchError = nil;
  self.permissionList = nil;
  self.permissionListFetchError = nil;
  self.childList = nil;
  self.childListFetchError = nil;
  self.parentsList = nil;
  self.parentsListFetchError = nil;

  self.detailsFetchError = nil;

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
      self.revisionList = obj;
      self.revisionListFetchError = error;
    };

    GTLQueryDrive *permissionQuery = [GTLQueryDrive queryForPermissionsListWithFileId:fileID];
    permissionQuery.completionBlock = ^(GTLServiceTicket *ticket, GTLDrivePermissionList *obj,
                                      NSError *error) {
      self.permissionList = obj;
      self.permissionListFetchError = error;
    };

    GTLQueryDrive *childQuery = [GTLQueryDrive queryForChildrenListWithFolderId:fileID];
    childQuery.completionBlock = ^(GTLServiceTicket *ticket, GTLDriveChildList *obj,
                                      NSError *error) {
      self.childList = obj;
      self.childListFetchError = error;
    };

    GTLQueryDrive *parentsQuery = [GTLQueryDrive queryForParentsListWithFileId:fileID];
    parentsQuery.completionBlock = ^(GTLServiceTicket *ticket, GTLDriveParentList *obj,
                                      NSError *error) {
      // Note that we could obtain the parents list for a file item from the
      // main file list feed, too.
      self.parentsList = obj;
      self.parentsListFetchError = error;
    };

    // Combine the separate queries into one batch.
    GTLBatchQuery *batchQuery = [GTLBatchQuery batchQuery];
    [batchQuery addQuery:revisionQuery];
    [batchQuery addQuery:permissionQuery];
    [batchQuery addQuery:childQuery];
    [batchQuery addQuery:parentsQuery];

    self.detailsTicket = [service executeQuery:batchQuery
                             completionHandler:^(GTLServiceTicket *ticket,
                                                 GTLBatchResult *batchResult, NSError *error) {
       // Callback
       //
       // The batch query execution completionHandler runs after the individual
       // query completion handlers have been called.
       self.detailsTicket = nil;
       self.detailsFetchError = error;

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
    self.editFileListTicket = [service executeQuery:query
                                  completionHandler:^(GTLServiceTicket *ticket,
                                                      id nilObject,
                                                      NSError *error) {
      // Callback
      self.editFileListTicket = nil;
      if (error == nil) {
        [self displayAlert:@"Deleted"
                    format:@"Deleted \"%@\"",
         selectedFile.title];
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
    BOOL isInTrash = [selectedFile.labels.trashed boolValue];
    if (isInTrash) {
      query = [GTLQueryDrive queryForFilesUntrashWithFileId:fileID];
    } else {
      query = [GTLQueryDrive queryForFilesTrashWithFileId:fileID];
    }
    self.editFileListTicket = [service executeQuery:query
                                  completionHandler:^(GTLServiceTicket *ticket,
                                                      id nilObject,
                                                      NSError *error) {
      // Callback
      self.editFileListTicket = nil;
      if (error == nil) {
        NSString *fmt = (isInTrash ? @"Moved \"%@\" out of trash" : @"Moved \"%@\" to trash");
        [self displayAlert:@"Updated"
                    format:fmt, selectedFile.title];
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
    fileObj.title = [NSString stringWithFormat:@"%@ copy", selectedFile.title];

    GTLQueryDrive *query = [GTLQueryDrive queryForFilesCopyWithObject:fileObj
                                                               fileId:fileID];
    self.editFileListTicket = [service executeQuery:query
                                  completionHandler:^(GTLServiceTicket *ticket,
                                                      GTLDriveFile *copiedFile,
                                                      NSError *error) {
      // Callback
      self.editFileListTicket = nil;
      if (error == nil) {
        [self displayAlert:@"Copied"
                    format:@"Created copy \"%@\"",
         copiedFile.title];
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
  folderObj.title = [NSString stringWithFormat:@"New Folder %@", [NSDate date]];
  folderObj.mimeType = @"application/vnd.google-apps.folder";

  // To create a folder in a specific parent folder, specify the identifier
  // of the parent:
  //
  //  GTLDriveFileParentsCollectionItem *parentItem = [GTLDriveFileParentsCollectionItem object];
  //  GTLDriveParentReference *parentRef = [GTLDriveParentReference object];
  //  parentRef.identifier = parentID;

  GTLQueryDrive *query = [GTLQueryDrive queryForFilesInsertWithObject:folderObj
                                                     uploadParameters:nil];
  self.editFileListTicket = [service executeQuery:query
                                completionHandler:^(GTLServiceTicket *ticket,
                                                    GTLDriveFile *folderItem,
                                                    NSError *error) {
    // Callback
    self.editFileListTicket = nil;
    if (error == nil) {
      [self displayAlert:@"Created"
                  format:@"Created folder \"%@\"",
       folderItem.title];
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
  // Queries that support file uploads take an uploadParameters object.
  // The uploadParameters include the MIME type of the file being uploaded,
  // and either an NSData with the file contents, or an NSFileHandler for
  // the file path.
  NSFileHandle *fileHandle = [NSFileHandle fileHandleForReadingAtPath:path];
  if (fileHandle) {
    GTLServiceDrive *service = self.driveService;

    NSString *mimeType = [GTLUtilities MIMETypeForFileAtPath:path
                                             defaultMIMEType:@"binary/octet-stream"];
    GTLUploadParameters *uploadParameters =
      [GTLUploadParameters uploadParametersWithFileHandle:fileHandle
                                                 MIMEType:mimeType];
    GTLDriveFile *newFile = [GTLDriveFile object];
    newFile.title = [path lastPathComponent];

    GTLQueryDrive *query = [GTLQueryDrive queryForFilesInsertWithObject:newFile
                                                       uploadParameters:uploadParameters];
    self.uploadFileTicket = [service executeQuery:query
                                  completionHandler:^(GTLServiceTicket *ticket,
                                                      GTLDriveFile *uploadedFile,
                                                      NSError *error) {
      // Callback
      self.uploadFileTicket = nil;
      if (error == nil) {
        [self displayAlert:@"Created"
                    format:@"Uploaded file \"%@\"",
         uploadedFile.title];
        [self fetchFileList];
      } else {
        [self displayAlert:@"Upload Failed"
                    format:@"%@", error];
      }
      [uploadProgressIndicator_ setDoubleValue:0.0];
      [self updateUI];
    }];

    self.uploadFileTicket.uploadProgressBlock = ^(GTLServiceTicket *ticket,
                                                    unsigned long long numberOfBytesRead,
                                                    unsigned long long dataLength) {
      [uploadProgressIndicator_ setMaxValue:(double)dataLength];
      [uploadProgressIndicator_ setDoubleValue:(double)numberOfBytesRead];
    };
    [self updateUI];
  } else {
    // Could not read file data.
    [self displayAlert:@"No Upload File Found" format:@"Path: %@", path];
  }
}

#pragma mark Downloading

- (void)downloadFormatSelected:(NSMenuItem *)menuItem {
  // The user chose a format for downloading the selected file.
  NSString *exportFormat = [menuItem title];
  GTLDriveFile *file = [menuItem representedObject];
  NSString *exportURLStr;
  NSString *extn = nil;
  if ([exportFormat isEqual:kOriginalFile]) {
    exportURLStr = file.downloadUrl;
  } else {
    exportURLStr = [file.exportLinks JSONValueForKey:exportFormat];
    extn = [self extensionForMIMEType:exportFormat];
  }
  if ([exportURLStr length] > 0) {
    // Show a save panel so the user can pick a download location.
    NSString *suggestedName = file.originalFilename;
    if ([suggestedName length] == 0) {
      suggestedName = file.title;
    }
    if ([extn length] > 0) {
      NSString *withoutExt = [suggestedName stringByDeletingPathExtension];
      suggestedName = [withoutExt stringByAppendingPathExtension:extn];
    }
    NSSavePanel *savePanel = [NSSavePanel savePanel];
    [savePanel setNameFieldStringValue:suggestedName];
    [savePanel beginSheetModalForWindow:[self window]
                      completionHandler:^(NSInteger result) {
      // Callback
      if (result == NSOKButton) {
        NSString *savePath = [[savePanel URL] path];

        // Use a GTMHTTPFetcher object to download the file with authorization.
        NSURL *url = [NSURL URLWithString:exportURLStr];
        NSURLRequest *request = [NSURLRequest requestWithURL:url];
        GTMHTTPFetcher *fetcher = [GTMHTTPFetcher fetcherWithRequest:request];
        fetcher.authorizer = self.driveService.authorizer;
        fetcher.downloadPath = savePath;
        [fetcher setCommentWithFormat:@"Downloading \"%@\"", file.title];
        [fetcher beginFetchWithCompletionHandler:^(NSData *data, NSError *error) {
          // Callback
          if (error == nil) {
            // Successfully saved the document
            //
            // Since a downloadPath property was specified, the data argument is
            // nil, and the file data has been written to disk.
          } else {
            [self displayAlert:@"Error Downloading File"
                        format:@"%@", error];
          }
        }];
      }
    }];
  }
}

- (NSString *)extensionForMIMEType:(NSString *)mimeType {
  NSString *result = nil;
  CFStringRef uti = UTTypeCreatePreferredIdentifierForTag(kUTTagClassMIMEType,
                                                          (CFStringRef)mimeType,
                                                          NULL);
  if (uti) {
    CFStringRef cfExtn = UTTypeCopyPreferredTagWithClass(uti, kUTTagClassFilenameExtension);
    if (cfExtn) {
      result = [NSString stringWithString:(NSString *)cfExtn];
      CFRelease(cfExtn);
    }
    CFRelease(uti);
  }
  return result;
}

#pragma mark -
#pragma mark Sign In

- (void)runSigninThenInvokeSelector:(SEL)signInDoneSel {
  // Applications should have client ID and client secret strings
  // hardcoded into the source, but the sample application asks the
  // developer for the strings.
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
      if (signInDoneSel) {
        [self performSelector:signInDoneSel];
      }
    } else {
      self.fileListFetchError = error;
      [self updateUI];
    }
  }];
}

#pragma mark -
#pragma mark UI

- (void)updateUI {
  BOOL isSignedIn = [self isSignedIn];
  NSString *username = [self signedInUsername];
  [signedInButton_ setTitle:(isSignedIn ? @"Sign Out" : @"Sign In")];
  [signedInField_ setStringValue:(isSignedIn ? username : @"No")];

  //
  // File list table
  //
  [fileListTable_ reloadData];

  if (self.fileListTicket != nil || self.editFileListTicket != nil) {
    [fileListProgressIndicator_ startAnimation:self];
  } else {
    [fileListProgressIndicator_ stopAnimation:self];
  }

  // Get the description of the selected item, or the feed fetch error
  NSString *resultStr = @"";

  if (self.fileListFetchError) {
    // Display the error
    resultStr = [self.fileListFetchError description];

    // Also display any server data present
    NSData *errData = [[self.fileListFetchError userInfo] objectForKey:kGTMHTTPFetcherStatusDataKey];
    if (errData) {
      NSString *dataStr = [[[NSString alloc] initWithData:errData
                                                 encoding:NSUTF8StringEncoding] autorelease];
      resultStr = [resultStr stringByAppendingFormat:@"\n%@", dataStr];
    }
  } else {
    // Display the selected item
    GTLDriveFile *item = [self selectedFileListEntry];
    if (item) {
      resultStr = [item description];
    }
  }
  [fileListResultTextField_ setString:resultStr];

  [self updateThumbnailImage];

  //
  // Details table
  //

  [detailTable_ reloadData];

  if (self.detailsTicket != nil) {
    [detailProgressIndicator_ startAnimation:self];
  } else {
    [detailProgressIndicator_ stopAnimation:self];
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

  [detailResultTextField_ setString:resultStr];

  // Update the counts in the segmented control
  NSUInteger numberOfRevisions = [self.revisionList.items count];
  NSUInteger numberOfPermissions = [self.permissionList.items count];
  NSUInteger numberOfChildren = [self.childList.items count];
  NSUInteger numberOfParents = [self.parentsList.items count];

  NSString *revisionsStr = [NSString stringWithFormat:@"Revisions %u", numberOfRevisions];
  NSString *permissionsStr = [NSString stringWithFormat:@"Permissions %u", numberOfPermissions];
  NSString *childrenStr = [NSString stringWithFormat:@"Children %u", numberOfChildren];
  NSString *parentsStr = [NSString stringWithFormat:@"Parents %u", numberOfParents];

  [segmentedControl_ setLabel:revisionsStr forSegment:kRevisionsSegment];
  [segmentedControl_ setLabel:permissionsStr forSegment:kPermissionsSegment];
  [segmentedControl_ setLabel:childrenStr forSegment:kChildrenSegment];
  [segmentedControl_ setLabel:parentsStr forSegment:kParentsSegment];

  // Enable buttons
  BOOL isFetchingFileList = (self.fileListTicket != nil);
  BOOL isEditingFileList = (self.editFileListTicket != nil);
  [fileListCancelButton_ setEnabled:(isFetchingFileList || isEditingFileList)];

  BOOL isFetchingDetails = (self.detailsTicket != nil);
  [detailCancelButton_ setEnabled:isFetchingDetails];

  GTLDriveFile *selectedFile = [self selectedFileListEntry];
  BOOL isFileSelected = (selectedFile != nil);
  BOOL isFileViewable = (selectedFile.alternateLink != nil);
  [viewButton_ setEnabled:isFileViewable];

  BOOL isEditable = [selectedFile.editable boolValue];
  [deleteButton_ setEnabled:isEditable];
  [trashButton_ setEnabled:isEditable];

  BOOL isInTrash = [selectedFile.labels.trashed boolValue];
  NSString *trashTitle = (isInTrash ? @"Untrash" : @"Trash");
  [trashButton_ setTitle:trashTitle];

  [duplicateButton_ setEnabled:isFileSelected];

  BOOL hasFileList = (self.fileList != nil);
  [newFolderButton_ setEnabled:hasFileList];

  BOOL isUploading = (self.uploadFileTicket != nil);
  [uploadButton_ setEnabled:(hasFileList && !isUploading)];
  [pauseUploadButton_ setEnabled:isUploading];
  [stopUploadButton_ setEnabled:isUploading];

  BOOL isUploadPaused = [self.uploadFileTicket isUploadPaused];
  NSString *pauseTitle = (isUploadPaused ? @"Resume" : @"Pause");
  [pauseUploadButton_ setTitle:pauseTitle];

  // Fill in the download menu with the available download formats.
  BOOL hasDownloadURL = ([selectedFile.downloadUrl length] > 0);
  GTLDriveFileExportLinks *exportLinks = selectedFile.exportLinks;
  NSArray *exportLinkKeys = [exportLinks additionalJSONKeys];
  BOOL hasExportLinks = ([exportLinkKeys count] > 0);
  [downloadButton_ setEnabled:(hasDownloadURL || hasExportLinks)];

  NSMenu *menu = [[[NSMenu alloc] init] autorelease];
  [menu addItemWithTitle:@"Download" action:NULL keyEquivalent:@""];

  // Add an "Original File" menu item only if there's a download URL.
  if ([selectedFile.downloadUrl length] > 0) {
    NSMenuItem *menuItem = [menu addItemWithTitle:kOriginalFile
                                           action:@selector(downloadFormatSelected:)
                                    keyEquivalent:@""];
    [menuItem setTarget:self];
    [menuItem setRepresentedObject:selectedFile];
  }

  for (NSString *key in exportLinkKeys) {
    NSMenuItem *menuItem = [menu addItemWithTitle:key
                                           action:@selector(downloadFormatSelected:)
                                    keyEquivalent:@""];
    [menuItem setTarget:self];

    [menuItem setRepresentedObject:selectedFile];
  }
  [downloadButton_ setMenu:menu];

  // Show or hide the text indicating that the client ID or client secret are
  // needed
  BOOL hasClientIDStrings = [[clientIDField_ stringValue] length] > 0
    && [[clientSecretField_ stringValue] length] > 0;
  [clientIDRequiredTextField_ setHidden:hasClientIDStrings];
}

- (void)updateThumbnailImage {
  // We will fetch the thumbnail image if its URL is different from the one
  // currently displayed.
  static NSString *gDisplayedURLStr = nil;
  GTLDriveFile *selectedFile = [self selectedFileListEntry];
  NSString *thumbnailURLStr = selectedFile.thumbnailLink;

  if (!GTL_AreEqualOrBothNil(gDisplayedURLStr, thumbnailURLStr)) {
    [thumbnailView_ setImage:nil];

    [gDisplayedURLStr autorelease];
    gDisplayedURLStr = [thumbnailURLStr copy];

    if (thumbnailURLStr) {
      GTMHTTPFetcher *fetcher = [GTMHTTPFetcher fetcherWithURLString:thumbnailURLStr];
      fetcher.authorizer = self.driveService.authorizer;
      [fetcher setCommentWithFormat:@"Thumbnail for \"%@\"", selectedFile.title];
      [fetcher beginFetchWithCompletionHandler:^(NSData *data, NSError *error) {
        if (data) {
          NSImage *image = [[[NSImage alloc] initWithData:data] autorelease];
          if (image) {
            [thumbnailView_ setImage:image];
          } else {
            NSLog(@"Failed to make image from %lu bytes for \"%@\"",
                  (unsigned long) [data length], selectedFile.title);
          }
        } else {
          NSLog(@"Failed to fetch thumbnail for \"%@\", %@",
                selectedFile.title, error);
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

- (IBAction)clientIDClicked:(id)sender {
  // Show the sheet for developers to enter their client ID and client secret
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
  [self updateUI];  // enable and disable buttons
}

#pragma mark TableView delegate and data source methods

- (void)tableViewSelectionDidChange:(NSNotification *)notification {
  [self updateUI];
  if ([notification object] == fileListTable_) {
    [self fetchSelectedFileDetails];
  }
}

// Table view data source methods
- (int)numberOfRowsInTableView:(NSTableView *)tableView {
  GTLCollectionObject *collection;
  if (tableView == fileListTable_) {
    collection = self.fileList;
  } else {
    collection = [self detailCollection];
  }
  return [collection.items count];
}

- (id)tableView:(NSTableView *)tableView
objectValueForTableColumn:(NSTableColumn *)tableColumn
            row:(NSInteger)row {
  if (tableView == fileListTable_) {
    GTLDriveFile *file = [self.fileList itemAtIndex:row];
    return [self fileTitleWithLabelsForFile:file];
  } else {
    GTLCollectionObject *collection = [self detailCollection];
    GTLObject *item = [collection itemAtIndex:row];
    return [self descriptionForDetailItem:item];
  }
}

- (NSString *)fileTitleWithLabelsForFile:(GTLDriveFile *)file {

  const UniChar kStarChar = 0x2605;
  const UniChar kQuarterMoon = 0x263D;
  const UniChar kTrashedX = 0x2717;
  const UniChar kCrossedDownArrow = 0x21DF;

  NSMutableString *title = [NSMutableString stringWithString:file.title];
  GTLDriveFileLabels *labels = file.labels;

  if ([labels.starred boolValue]) {
    [title appendFormat:@" %C", kStarChar];
  }
  if ([labels.trashed boolValue]) {
    title = [NSMutableString stringWithFormat:@"%C %@", kTrashedX, title];
  }
  if ([labels.hidden boolValue]) {
    [title appendFormat:@" %C", kQuarterMoon];
  }
  if ([labels.restricted boolValue]) {
    [title appendFormat:@" %C", kCrossedDownArrow];
  }
  return title;
}

@end
