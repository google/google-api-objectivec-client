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
//  GTLQueryDrive.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Drive API (drive/v2)
// Description:
//   The API to interact with Drive.
// Documentation:
//   https://developers.google.com/drive/
// Classes:
//   GTLQueryDrive (34 custom class methods, 29 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLDriveChildReference;
@class GTLDriveFile;
@class GTLDriveParentReference;
@class GTLDrivePermission;
@class GTLDriveRevision;

@interface GTLQueryDrive : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (copy) NSString *appId;
@property (copy) NSString *changeId;
@property (copy) NSString *childId;
@property (assign) BOOL convert;
@property (copy) NSString *fileId;
@property (copy) NSString *folderId;
@property (assign) BOOL includeDeleted;
@property (assign) BOOL includeSubscribed;
@property (assign) long long maxChangeIdCount;
@property (assign) NSInteger maxResults;
@property (assign) BOOL newRevision;
@property (assign) BOOL ocr;
@property (copy) NSString *ocrLanguage;
@property (copy) NSString *pageToken;
@property (copy) NSString *parentId;
@property (copy) NSString *permissionId;
@property (assign) BOOL pinned;
@property (copy) NSString *projection;
@property (copy) NSString *q;
@property (copy) NSString *revisionId;
@property (assign) BOOL sendNotificationEmails;
@property (assign) BOOL setModifiedDate;
@property (copy) NSString *sourceLanguage;
@property (assign) long long startChangeId;
@property (copy) NSString *targetLanguage;
@property (copy) NSString *timedTextLanguage;
@property (copy) NSString *timedTextTrackName;
@property (assign) BOOL updateViewedDate;

#pragma mark -
#pragma mark "about" methods
// These create a GTLQueryDrive object.

// Method: drive.about.get
// Gets the information about the current user along with Drive API settings
//  Optional:
//   includeSubscribed: Whether to include subscribed items when calculating the
//     number of remaining change IDs (Default true)
//   maxChangeIdCount: Maximum number of remaining change IDs to count (Default
//     1)
//   startChangeId: Change ID to start counting from when calculating number of
//     remaining change IDs
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveAbout.
+ (id)queryForAboutGet;

#pragma mark -
#pragma mark "apps" methods
// These create a GTLQueryDrive object.

// Method: drive.apps.get
// Gets a specific app.
//  Required:
//   appId: The ID of the app.
//  Authorization scope(s):
//   kGTLAuthScopeDriveAppsReadonly
// Fetches a GTLDriveApp.
+ (id)queryForAppsGetWithAppId:(NSString *)appId;

// Method: drive.apps.list
// Lists a user's apps.
//  Authorization scope(s):
//   kGTLAuthScopeDriveAppsReadonly
// Fetches a GTLDriveAppList.
+ (id)queryForAppsList;

#pragma mark -
#pragma mark "changes" methods
// These create a GTLQueryDrive object.

// Method: drive.changes.get
// Gets a specific change.
//  Required:
//   changeId: The ID of the change.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveChange.
+ (id)queryForChangesGetWithChangeId:(NSString *)changeId;

// Method: drive.changes.list
// Lists the changes for a user.
//  Optional:
//   includeDeleted: Whether to include deleted items. (Default true)
//   includeSubscribed: Whether to include subscribed items. (Default true)
//   maxResults: Maximum number of changes to return. (Default 100)
//   pageToken: Page token for changes.
//   startChangeId: Change ID to start listing changes from.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveChangeList.
+ (id)queryForChangesList;

#pragma mark -
#pragma mark "children" methods
// These create a GTLQueryDrive object.

// Method: drive.children.delete
// Removes a child from a folder.
//  Required:
//   folderId: The ID of the folder.
//   childId: The ID of the child.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
+ (id)queryForChildrenDeleteWithFolderId:(NSString *)folderId
                                 childId:(NSString *)childId;

// Method: drive.children.get
// Gets a specific child reference.
//  Required:
//   folderId: The ID of the folder.
//   childId: The ID of the child.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveChildReference.
+ (id)queryForChildrenGetWithFolderId:(NSString *)folderId
                              childId:(NSString *)childId;

// Method: drive.children.insert
// Inserts a file into a folder.
//  Required:
//   folderId: The ID of the folder.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveChildReference.
+ (id)queryForChildrenInsertWithObject:(GTLDriveChildReference *)object
                              folderId:(NSString *)folderId;

// Method: drive.children.list
// Lists a folder's children.
//  Required:
//   folderId: The ID of the folder.
//  Optional:
//   maxResults: Maximum number of children to return. (Default 100)
//   pageToken: Page token for children.
//   q: Query string for searching children.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveChildList.
+ (id)queryForChildrenListWithFolderId:(NSString *)folderId;

#pragma mark -
#pragma mark "files" methods
// These create a GTLQueryDrive object.

// Method: drive.files.copy
// Creates a copy of the specified file.
//  Required:
//   fileId: The ID of the file to copy.
//  Optional:
//   convert: Whether to convert this file to the corresponding Google Docs
//     format. (Default false)
//   ocr: Whether to attempt OCR on .jpg, .png, or .gif uploads. (Default false)
//   ocrLanguage: If ocr is true, hints at the language to use. Valid values are
//     ISO 639-1 codes.
//   pinned: Whether to pin the head revision of the new copy. (Default false)
//   sourceLanguage: The language of the original file to be translated.
//   targetLanguage: Target language to translate the file to. If no
//     sourceLanguage is provided, the API will attempt to detect the language.
//   timedTextLanguage: The language of the timed text.
//   timedTextTrackName: The timed text track name.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveFile.
+ (id)queryForFilesCopyWithObject:(GTLDriveFile *)object
                           fileId:(NSString *)fileId;

// Method: drive.files.delete
// Permanently deletes a file by ID. Skips the trash.
//  Required:
//   fileId: The ID of the file to delete.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
+ (id)queryForFilesDeleteWithFileId:(NSString *)fileId;

// Method: drive.files.get
// Gets a file's metadata by ID.
//  Required:
//   fileId: The ID for the file in question.
//  Optional:
//   projection: This parameter is deprecated and has no function.
//      kGTLDriveProjectionBasic: Deprecated
//      kGTLDriveProjectionFull: Deprecated
//   updateViewedDate: Whether to update the view date after successfully
//     retrieving the file. (Default false)
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveFile.
+ (id)queryForFilesGetWithFileId:(NSString *)fileId;

// Method: drive.files.insert
// Insert a new file.
//  Optional:
//   convert: Whether to convert this file to the corresponding Google Docs
//     format. (Default false)
//   ocr: Whether to attempt OCR on .jpg, .png, or .gif uploads. (Default false)
//   ocrLanguage: If ocr is true, hints at the language to use. Valid values are
//     ISO 639-1 codes.
//   pinned: Whether to pin the head revision of the uploaded file. (Default
//     false)
//   sourceLanguage: The language of the original file to be translated.
//   targetLanguage: Target language to translate the file to. If no
//     sourceLanguage is provided, the API will attempt to detect the language.
//   timedTextLanguage: The language of the timed text.
//   timedTextTrackName: The timed text track name.
//  Upload Parameters:
//   Maximum size: 10GB
//   Accepted MIME type(s): */*
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveFile.
+ (id)queryForFilesInsertWithObject:(GTLDriveFile *)object
                   uploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

// Method: drive.files.list
// Lists the user's files.
//  Optional:
//   maxResults: Maximum number of files to return. (Default 100)
//   pageToken: Page token for files.
//   projection: This parameter is deprecated and has no function.
//      kGTLDriveProjectionBasic: Deprecated
//      kGTLDriveProjectionFull: Deprecated
//   q: Query string for searching files.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveFileList.
+ (id)queryForFilesList;

// Method: drive.files.patch
// Updates file metadata and/or content. This method supports patch semantics.
//  Required:
//   fileId: The ID of the file to update.
//  Optional:
//   convert: Whether to convert this file to the corresponding Google Docs
//     format. (Default false)
//   newRevision: Whether a blob upload should create a new revision. If false,
//     the blob data in the current head revision will be replaced. (Default
//     true)
//   ocr: Whether to attempt OCR on .jpg, .png, or .gif uploads. (Default false)
//   ocrLanguage: If ocr is true, hints at the language to use. Valid values are
//     ISO 639-1 codes.
//   pinned: Whether to pin the new revision. (Default false)
//   setModifiedDate: Whether to set the modified date with the supplied
//     modified date. (Default false)
//   sourceLanguage: The language of the original file to be translated.
//   targetLanguage: Target language to translate the file to. If no
//     sourceLanguage is provided, the API will attempt to detect the language.
//   timedTextLanguage: The language of the timed text.
//   timedTextTrackName: The timed text track name.
//   updateViewedDate: Whether to update the view date after successfully
//     updating the file. (Default true)
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveFile.
+ (id)queryForFilesPatchWithObject:(GTLDriveFile *)object
                            fileId:(NSString *)fileId;

// Method: drive.files.touch
// Set the file's updated time to the current server time.
//  Required:
//   fileId: The ID of the file to update.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveFile.
+ (id)queryForFilesTouchWithFileId:(NSString *)fileId;

// Method: drive.files.trash
// Moves a file to the trash.
//  Required:
//   fileId: The ID of the file to trash.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveFile.
+ (id)queryForFilesTrashWithFileId:(NSString *)fileId;

// Method: drive.files.untrash
// Restores a file from the trash.
//  Required:
//   fileId: The ID of the file to untrash.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveFile.
+ (id)queryForFilesUntrashWithFileId:(NSString *)fileId;

// Method: drive.files.update
// Updates file metadata and/or content
//  Required:
//   fileId: The ID of the file to update.
//  Optional:
//   convert: Whether to convert this file to the corresponding Google Docs
//     format. (Default false)
//   newRevision: Whether a blob upload should create a new revision. If false,
//     the blob data in the current head revision will be replaced. (Default
//     true)
//   ocr: Whether to attempt OCR on .jpg, .png, or .gif uploads. (Default false)
//   ocrLanguage: If ocr is true, hints at the language to use. Valid values are
//     ISO 639-1 codes.
//   pinned: Whether to pin the new revision. (Default false)
//   setModifiedDate: Whether to set the modified date with the supplied
//     modified date. (Default false)
//   sourceLanguage: The language of the original file to be translated.
//   targetLanguage: Target language to translate the file to. If no
//     sourceLanguage is provided, the API will attempt to detect the language.
//   timedTextLanguage: The language of the timed text.
//   timedTextTrackName: The timed text track name.
//   updateViewedDate: Whether to update the view date after successfully
//     updating the file. (Default true)
//  Upload Parameters:
//   Maximum size: 10GB
//   Accepted MIME type(s): */*
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveFile.
+ (id)queryForFilesUpdateWithObject:(GTLDriveFile *)object
                             fileId:(NSString *)fileId
                   uploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

#pragma mark -
#pragma mark "parents" methods
// These create a GTLQueryDrive object.

// Method: drive.parents.delete
// Removes a parent from a file.
//  Required:
//   fileId: The ID of the file.
//   parentId: The ID of the parent.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
+ (id)queryForParentsDeleteWithFileId:(NSString *)fileId
                             parentId:(NSString *)parentId;

// Method: drive.parents.get
// Gets a specific parent reference.
//  Required:
//   fileId: The ID of the file.
//   parentId: The ID of the parent.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveParentReference.
+ (id)queryForParentsGetWithFileId:(NSString *)fileId
                          parentId:(NSString *)parentId;

// Method: drive.parents.insert
// Adds a parent folder for a file.
//  Required:
//   fileId: The ID of the file.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveParentReference.
+ (id)queryForParentsInsertWithObject:(GTLDriveParentReference *)object
                               fileId:(NSString *)fileId;

// Method: drive.parents.list
// Lists a file's parents.
//  Required:
//   fileId: The ID of the file.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveParentList.
+ (id)queryForParentsListWithFileId:(NSString *)fileId;

#pragma mark -
#pragma mark "permissions" methods
// These create a GTLQueryDrive object.

// Method: drive.permissions.delete
// Deletes a permission from a file.
//  Required:
//   fileId: The ID for the file.
//   permissionId: The ID for the permission.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
+ (id)queryForPermissionsDeleteWithFileId:(NSString *)fileId
                             permissionId:(NSString *)permissionId;

// Method: drive.permissions.get
// Gets a permission by ID.
//  Required:
//   fileId: The ID for the file.
//   permissionId: The ID for the permission.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDrivePermission.
+ (id)queryForPermissionsGetWithFileId:(NSString *)fileId
                          permissionId:(NSString *)permissionId;

// Method: drive.permissions.insert
// Inserts a permission for a file.
//  Required:
//   fileId: The ID for the file.
//  Optional:
//   sendNotificationEmails: Whether to send notification emails. (Default true)
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDrivePermission.
+ (id)queryForPermissionsInsertWithObject:(GTLDrivePermission *)object
                                   fileId:(NSString *)fileId;

// Method: drive.permissions.list
// Lists a file's permissions.
//  Required:
//   fileId: The ID for the file.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDrivePermissionList.
+ (id)queryForPermissionsListWithFileId:(NSString *)fileId;

// Method: drive.permissions.patch
// Updates a permission. This method supports patch semantics.
//  Required:
//   fileId: The ID for the file.
//   permissionId: The ID for the permission.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDrivePermission.
+ (id)queryForPermissionsPatchWithObject:(GTLDrivePermission *)object
                                  fileId:(NSString *)fileId
                            permissionId:(NSString *)permissionId;

// Method: drive.permissions.update
// Updates a permission.
//  Required:
//   fileId: The ID for the file.
//   permissionId: The ID for the permission.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDrivePermission.
+ (id)queryForPermissionsUpdateWithObject:(GTLDrivePermission *)object
                                   fileId:(NSString *)fileId
                             permissionId:(NSString *)permissionId;

#pragma mark -
#pragma mark "revisions" methods
// These create a GTLQueryDrive object.

// Method: drive.revisions.delete
// Removes a revision.
//  Required:
//   fileId: The ID of the file.
//   revisionId: The ID of the revision.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
+ (id)queryForRevisionsDeleteWithFileId:(NSString *)fileId
                             revisionId:(NSString *)revisionId;

// Method: drive.revisions.get
// Gets a specific revision.
//  Required:
//   fileId: The ID of the file.
//   revisionId: The ID of the revision.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveRevision.
+ (id)queryForRevisionsGetWithFileId:(NSString *)fileId
                          revisionId:(NSString *)revisionId;

// Method: drive.revisions.list
// Lists a file's revisions.
//  Required:
//   fileId: The ID of the file.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveRevisionList.
+ (id)queryForRevisionsListWithFileId:(NSString *)fileId;

// Method: drive.revisions.patch
// Updates a revision. This method supports patch semantics.
//  Required:
//   fileId: The ID for the file.
//   revisionId: The ID for the revision.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveRevision.
+ (id)queryForRevisionsPatchWithObject:(GTLDriveRevision *)object
                                fileId:(NSString *)fileId
                            revisionId:(NSString *)revisionId;

// Method: drive.revisions.update
// Updates a revision.
//  Required:
//   fileId: The ID for the file.
//   revisionId: The ID for the revision.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveRevision.
+ (id)queryForRevisionsUpdateWithObject:(GTLDriveRevision *)object
                                 fileId:(NSString *)fileId
                             revisionId:(NSString *)revisionId;

@end
