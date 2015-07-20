/* Copyright (c) 2015 Google Inc.
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
//   GTLQueryDrive (59 custom class methods, 46 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLDriveChannel;
@class GTLDriveChildReference;
@class GTLDriveComment;
@class GTLDriveCommentReply;
@class GTLDriveFile;
@class GTLDriveParentReference;
@class GTLDrivePermission;
@class GTLDriveProperty;
@class GTLDriveRevision;

@interface GTLQueryDrive : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (nonatomic, copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (nonatomic, assign) BOOL acknowledgeAbuse;
@property (nonatomic, copy) NSString *addParents;
@property (nonatomic, copy) NSString *appFilterExtensions;
@property (nonatomic, copy) NSString *appFilterMimeTypes;
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *baseRevision;
@property (nonatomic, copy) NSString *changeId;
@property (nonatomic, copy) NSString *childId;
@property (nonatomic, copy) NSString *commentId;
@property (nonatomic, assign) BOOL convert;
@property (nonatomic, copy) NSString *corpus;
@property (nonatomic, copy) NSString *email;
@property (nonatomic, copy) NSString *emailMessage;
@property (nonatomic, copy) NSString *fileId;
@property (nonatomic, copy) NSString *folderId;
@property (nonatomic, assign) BOOL includeDeleted;
@property (nonatomic, assign) BOOL includeSubscribed;
@property (nonatomic, copy) NSString *languageCode;
@property (nonatomic, assign) long long maxChangeIdCount;
@property (nonatomic, assign) NSInteger maxResults;
@property (nonatomic, assign) BOOL newRevision;
@property (nonatomic, assign) BOOL ocr;
@property (nonatomic, copy) NSString *ocrLanguage;
@property (nonatomic, copy) NSString *pageToken;
@property (nonatomic, copy) NSString *parentId;
@property (nonatomic, copy) NSString *permissionId;
@property (nonatomic, assign) BOOL pinned;
@property (nonatomic, copy) NSString *projection;
@property (nonatomic, copy) NSString *propertyKey;
@property (nonatomic, copy) NSString *q;
@property (nonatomic, copy) NSString *removeParents;
@property (nonatomic, copy) NSString *replyId;
@property (nonatomic, assign) NSInteger revision;
@property (nonatomic, copy) NSString *revisionId;
@property (nonatomic, assign) BOOL sendNotificationEmails;
@property (nonatomic, assign) BOOL setModifiedDate;
@property (nonatomic, copy) NSString *spaces;
@property (nonatomic, assign) long long startChangeId;
@property (nonatomic, copy) NSString *timedTextLanguage;
@property (nonatomic, copy) NSString *timedTextTrackName;
@property (nonatomic, assign) BOOL transferOwnership;
@property (nonatomic, copy) NSString *updatedMin;
@property (nonatomic, assign) BOOL updateViewedDate;
@property (nonatomic, assign) BOOL useContentAsIndexableText;
@property (nonatomic, copy) NSString *visibility;

#pragma mark -
#pragma mark "about" methods
// These create a GTLQueryDrive object.

// Method: drive.about.get
// Gets the information about the current user along with Drive API settings
//  Optional:
//   includeSubscribed: When calculating the number of remaining change IDs,
//     whether to include public files the user has opened and shared files.
//     When set to false, this counts only change IDs for owned files and any
//     shared or public files that the user has explicitly added to a folder
//     they own. (Default true)
//   maxChangeIdCount: Maximum number of remaining change IDs to count (Default
//     1)
//   startChangeId: Change ID to start counting from when calculating number of
//     remaining change IDs
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveAbout.
+ (instancetype)queryForAboutGet;

#pragma mark -
#pragma mark "apps" methods
// These create a GTLQueryDrive object.

// Method: drive.apps.get
// Gets a specific app.
//  Required:
//   appId: The ID of the app.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveAppsReadonly
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveApp.
+ (instancetype)queryForAppsGetWithAppId:(NSString *)appId;

// Method: drive.apps.list
// Lists a user's installed apps.
//  Optional:
//   appFilterExtensions: A comma-separated list of file extensions for open
//     with filtering. All apps within the given app query scope which can open
//     any of the given file extensions will be included in the response. If
//     appFilterMimeTypes are provided as well, the result is a union of the two
//     resulting app lists.
//   appFilterMimeTypes: A comma-separated list of MIME types for open with
//     filtering. All apps within the given app query scope which can open any
//     of the given MIME types will be included in the response. If
//     appFilterExtensions are provided as well, the result is a union of the
//     two resulting app lists.
//   languageCode: A language or locale code, as defined by BCP 47, with some
//     extensions from Unicode's LDML format
//     (http://www.unicode.org/reports/tr35/).
//  Authorization scope(s):
//   kGTLAuthScopeDriveAppsReadonly
// Fetches a GTLDriveAppList.
+ (instancetype)queryForAppsList;

#pragma mark -
#pragma mark "changes" methods
// These create a GTLQueryDrive object.

// Method: drive.changes.get
// Gets a specific change.
//  Required:
//   changeId: The ID of the change.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveAppsReadonly
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveChange.
+ (instancetype)queryForChangesGetWithChangeId:(NSString *)changeId;

// Method: drive.changes.list
// Lists the changes for a user.
//  Optional:
//   includeDeleted: Whether to include deleted items. (Default true)
//   includeSubscribed: Whether to include public files the user has opened and
//     shared files. When set to false, the list only includes owned files plus
//     any shared or public files the user has explicitly added to a folder they
//     own. (Default true)
//   maxResults: Maximum number of changes to return. (Default 100)
//   pageToken: Page token for changes.
//   spaces: A comma-separated list of spaces to query. Supported values are
//     'drive' and 'appDataFolder'.
//   startChangeId: Change ID to start listing changes from.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveAppsReadonly
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveChangeList.
+ (instancetype)queryForChangesList;

// Method: drive.changes.watch
// Subscribe to changes for a user.
//  Optional:
//   includeDeleted: Whether to include deleted items. (Default true)
//   includeSubscribed: Whether to include public files the user has opened and
//     shared files. When set to false, the list only includes owned files plus
//     any shared or public files the user has explicitly added to a folder they
//     own. (Default true)
//   maxResults: Maximum number of changes to return. (Default 100)
//   pageToken: Page token for changes.
//   spaces: A comma-separated list of spaces to query. Supported values are
//     'drive' and 'appDataFolder'.
//   startChangeId: Change ID to start listing changes from.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveAppsReadonly
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveChannel.
+ (instancetype)queryForChangesWatchWithObject:(GTLDriveChannel *)object;

#pragma mark -
#pragma mark "channels" methods
// These create a GTLQueryDrive object.

// Method: drive.channels.stop
// Stop watching resources through this channel
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveAppsReadonly
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
+ (instancetype)queryForChannelsStopWithObject:(GTLDriveChannel *)object;

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
+ (instancetype)queryForChildrenDeleteWithFolderId:(NSString *)folderId
                                           childId:(NSString *)childId;

// Method: drive.children.get
// Gets a specific child reference.
//  Required:
//   folderId: The ID of the folder.
//   childId: The ID of the child.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveChildReference.
+ (instancetype)queryForChildrenGetWithFolderId:(NSString *)folderId
                                        childId:(NSString *)childId;

// Method: drive.children.insert
// Inserts a file into a folder.
//  Required:
//   folderId: The ID of the folder.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveChildReference.
+ (instancetype)queryForChildrenInsertWithObject:(GTLDriveChildReference *)object
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
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveChildList.
+ (instancetype)queryForChildrenListWithFolderId:(NSString *)folderId;

#pragma mark -
#pragma mark "comments" methods
// These create a GTLQueryDrive object.

// Method: drive.comments.delete
// Deletes a comment.
//  Required:
//   fileId: The ID of the file.
//   commentId: The ID of the comment.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
+ (instancetype)queryForCommentsDeleteWithFileId:(NSString *)fileId
                                       commentId:(NSString *)commentId;

// Method: drive.comments.get
// Gets a comment by ID.
//  Required:
//   fileId: The ID of the file.
//   commentId: The ID of the comment.
//  Optional:
//   includeDeleted: If set, this will succeed when retrieving a deleted
//     comment, and will include any deleted replies. (Default false)
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveComment.
+ (instancetype)queryForCommentsGetWithFileId:(NSString *)fileId
                                    commentId:(NSString *)commentId;

// Method: drive.comments.insert
// Creates a new comment on the given file.
//  Required:
//   fileId: The ID of the file.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveComment.
+ (instancetype)queryForCommentsInsertWithObject:(GTLDriveComment *)object
                                          fileId:(NSString *)fileId;

// Method: drive.comments.list
// Lists a file's comments.
//  Required:
//   fileId: The ID of the file.
//  Optional:
//   includeDeleted: If set, all comments and replies, including deleted
//     comments and replies (with content stripped) will be returned. (Default
//     false)
//   maxResults: The maximum number of discussions to include in the response,
//     used for paging. (0..100, default 20)
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     "nextPageToken" from the previous response.
//   updatedMin: Only discussions that were updated after this timestamp will be
//     returned. Formatted as an RFC 3339 timestamp.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveCommentList.
+ (instancetype)queryForCommentsListWithFileId:(NSString *)fileId;

// Method: drive.comments.patch
// Updates an existing comment. This method supports patch semantics.
//  Required:
//   fileId: The ID of the file.
//   commentId: The ID of the comment.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveComment.
+ (instancetype)queryForCommentsPatchWithObject:(GTLDriveComment *)object
                                         fileId:(NSString *)fileId
                                      commentId:(NSString *)commentId;

// Method: drive.comments.update
// Updates an existing comment.
//  Required:
//   fileId: The ID of the file.
//   commentId: The ID of the comment.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveComment.
+ (instancetype)queryForCommentsUpdateWithObject:(GTLDriveComment *)object
                                          fileId:(NSString *)fileId
                                       commentId:(NSString *)commentId;

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
//   ocr: Whether to attempt OCR on .jpg, .png, .gif, or .pdf uploads. (Default
//     false)
//   ocrLanguage: If ocr is true, hints at the language to use. Valid values are
//     BCP 47 codes.
//   pinned: Whether to pin the head revision of the new copy. A file can have a
//     maximum of 200 pinned revisions. (Default false)
//   timedTextLanguage: The language of the timed text.
//   timedTextTrackName: The timed text track name.
//   visibility: The visibility of the new file. This parameter is only relevant
//     when the source is not a native Google Doc and convert=false. (Default
//     kGTLDriveVisibilityDefault)
//      kGTLDriveVisibilityDefault: The visibility of the new file is determined
//        by the user's default visibility/sharing policies.
//      kGTLDriveVisibilityPrivate: The new file will be visible to only the
//        owner.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveAppsReadonly
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveFile.
+ (instancetype)queryForFilesCopyWithObject:(GTLDriveFile *)object
                                     fileId:(NSString *)fileId;

// Method: drive.files.delete
// Permanently deletes a file by ID. Skips the trash. The currently
// authenticated user must own the file.
//  Required:
//   fileId: The ID of the file to delete.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
+ (instancetype)queryForFilesDeleteWithFileId:(NSString *)fileId;

// Method: drive.files.emptyTrash
// Permanently deletes all of the user's trashed files.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
+ (instancetype)queryForFilesEmptyTrash;

// Method: drive.files.get
// Gets a file's metadata by ID.
//  Required:
//   fileId: The ID for the file in question.
//  Optional:
//   acknowledgeAbuse: Whether the user is acknowledging the risk of downloading
//     known malware or other abusive files. (Default false)
//   projection: This parameter is deprecated and has no function.
//      kGTLDriveProjectionBasic: Deprecated
//      kGTLDriveProjectionFull: Deprecated
//   revisionId: Specifies the Revision ID that should be downloaded. Ignored
//     unless alt=media is specified.
//   updateViewedDate: Whether to update the view date after successfully
//     retrieving the file. (Default false)
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveAppsReadonly
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveFile.
+ (instancetype)queryForFilesGetWithFileId:(NSString *)fileId;

// Method: drive.files.insert
// Insert a new file.
//  Optional:
//   convert: Whether to convert this file to the corresponding Google Docs
//     format. (Default false)
//   ocr: Whether to attempt OCR on .jpg, .png, .gif, or .pdf uploads. (Default
//     false)
//   ocrLanguage: If ocr is true, hints at the language to use. Valid values are
//     BCP 47 codes.
//   pinned: Whether to pin the head revision of the uploaded file. A file can
//     have a maximum of 200 pinned revisions. (Default false)
//   timedTextLanguage: The language of the timed text.
//   timedTextTrackName: The timed text track name.
//   useContentAsIndexableText: Whether to use the content as indexable text.
//     (Default false)
//   visibility: The visibility of the new file. This parameter is only relevant
//     when convert=false. (Default kGTLDriveVisibilityDefault)
//      kGTLDriveVisibilityDefault: The visibility of the new file is determined
//        by the user's default visibility/sharing policies.
//      kGTLDriveVisibilityPrivate: The new file will be visible to only the
//        owner.
//  Upload Parameters:
//   Maximum size: 5120GB
//   Accepted MIME type(s): */*
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveAppsReadonly
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveFile.
+ (instancetype)queryForFilesInsertWithObject:(GTLDriveFile *)object
                             uploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

// Method: drive.files.list
// Lists the user's files.
//  Optional:
//   corpus: The body of items (files/documents) to which the query applies.
//      kGTLDriveCorpusDefault: The items that the user has accessed.
//      kGTLDriveCorpusDomain: Items shared to the user's domain.
//   maxResults: Maximum number of files to return. (Default 100)
//   pageToken: Page token for files.
//   projection: This parameter is deprecated and has no function.
//      kGTLDriveProjectionBasic: Deprecated
//      kGTLDriveProjectionFull: Deprecated
//   q: Query string for searching files.
//   spaces: A comma-separated list of spaces to query. Supported values are
//     'drive' and 'appDataFolder'.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveAppsReadonly
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveFileList.
+ (instancetype)queryForFilesList;

// Method: drive.files.patch
// Updates file metadata and/or content. This method supports patch semantics.
//  Required:
//   fileId: The ID of the file to update.
//  Optional:
//   addParents: Comma-separated list of parent IDs to add.
//   convert: Whether to convert this file to the corresponding Google Docs
//     format. (Default false)
//   newRevision: Whether a blob upload should create a new revision. If false,
//     the blob data in the current head revision is replaced. If true or not
//     set, a new blob is created as head revision, and previous unpinned
//     revisions are preserved for a short period of time. Pinned revisions are
//     stored indefinitely, using additional storage quota, up to a maximum of
//     200 revisions. (Default true)
//   ocr: Whether to attempt OCR on .jpg, .png, .gif, or .pdf uploads. (Default
//     false)
//   ocrLanguage: If ocr is true, hints at the language to use. Valid values are
//     BCP 47 codes.
//   pinned: Whether to pin the new revision. A file can have a maximum of 200
//     pinned revisions. (Default false)
//   removeParents: Comma-separated list of parent IDs to remove.
//   setModifiedDate: Whether to set the modified date with the supplied
//     modified date. (Default false)
//   timedTextLanguage: The language of the timed text.
//   timedTextTrackName: The timed text track name.
//   updateViewedDate: Whether to update the view date after successfully
//     updating the file. (Default true)
//   useContentAsIndexableText: Whether to use the content as indexable text.
//     (Default false)
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveAppsReadonly
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveScripts
// Fetches a GTLDriveFile.
+ (instancetype)queryForFilesPatchWithObject:(GTLDriveFile *)object
                                      fileId:(NSString *)fileId;

// Method: drive.files.touch
// Set the file's updated time to the current server time.
//  Required:
//   fileId: The ID of the file to update.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveAppsReadonly
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
// Fetches a GTLDriveFile.
+ (instancetype)queryForFilesTouchWithFileId:(NSString *)fileId;

// Method: drive.files.trash
// Moves a file to the trash.
//  Required:
//   fileId: The ID of the file to trash.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveAppsReadonly
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveFile.
+ (instancetype)queryForFilesTrashWithFileId:(NSString *)fileId;

// Method: drive.files.untrash
// Restores a file from the trash.
//  Required:
//   fileId: The ID of the file to untrash.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveAppsReadonly
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveFile.
+ (instancetype)queryForFilesUntrashWithFileId:(NSString *)fileId;

// Method: drive.files.update
// Updates file metadata and/or content.
//  Required:
//   fileId: The ID of the file to update.
//  Optional:
//   addParents: Comma-separated list of parent IDs to add.
//   convert: Whether to convert this file to the corresponding Google Docs
//     format. (Default false)
//   newRevision: Whether a blob upload should create a new revision. If false,
//     the blob data in the current head revision is replaced. If true or not
//     set, a new blob is created as head revision, and previous unpinned
//     revisions are preserved for a short period of time. Pinned revisions are
//     stored indefinitely, using additional storage quota, up to a maximum of
//     200 revisions. (Default true)
//   ocr: Whether to attempt OCR on .jpg, .png, .gif, or .pdf uploads. (Default
//     false)
//   ocrLanguage: If ocr is true, hints at the language to use. Valid values are
//     BCP 47 codes.
//   pinned: Whether to pin the new revision. A file can have a maximum of 200
//     pinned revisions. (Default false)
//   removeParents: Comma-separated list of parent IDs to remove.
//   setModifiedDate: Whether to set the modified date with the supplied
//     modified date. (Default false)
//   timedTextLanguage: The language of the timed text.
//   timedTextTrackName: The timed text track name.
//   updateViewedDate: Whether to update the view date after successfully
//     updating the file. (Default true)
//   useContentAsIndexableText: Whether to use the content as indexable text.
//     (Default false)
//  Upload Parameters:
//   Maximum size: 5120GB
//   Accepted MIME type(s): */*
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveAppsReadonly
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveScripts
// Fetches a GTLDriveFile.
+ (instancetype)queryForFilesUpdateWithObject:(GTLDriveFile *)object
                                       fileId:(NSString *)fileId
                             uploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

// Method: drive.files.watch
// Subscribe to changes on a file
//  Required:
//   fileId: The ID for the file in question.
//  Optional:
//   acknowledgeAbuse: Whether the user is acknowledging the risk of downloading
//     known malware or other abusive files. (Default false)
//   projection: This parameter is deprecated and has no function.
//      kGTLDriveProjectionBasic: Deprecated
//      kGTLDriveProjectionFull: Deprecated
//   revisionId: Specifies the Revision ID that should be downloaded. Ignored
//     unless alt=media is specified.
//   updateViewedDate: Whether to update the view date after successfully
//     retrieving the file. (Default false)
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveAppsReadonly
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveChannel.
+ (instancetype)queryForFilesWatchWithObject:(GTLDriveChannel *)object
                                      fileId:(NSString *)fileId;

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
+ (instancetype)queryForParentsDeleteWithFileId:(NSString *)fileId
                                       parentId:(NSString *)parentId;

// Method: drive.parents.get
// Gets a specific parent reference.
//  Required:
//   fileId: The ID of the file.
//   parentId: The ID of the parent.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveParentReference.
+ (instancetype)queryForParentsGetWithFileId:(NSString *)fileId
                                    parentId:(NSString *)parentId;

// Method: drive.parents.insert
// Adds a parent folder for a file.
//  Required:
//   fileId: The ID of the file.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveParentReference.
+ (instancetype)queryForParentsInsertWithObject:(GTLDriveParentReference *)object
                                         fileId:(NSString *)fileId;

// Method: drive.parents.list
// Lists a file's parents.
//  Required:
//   fileId: The ID of the file.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveParentList.
+ (instancetype)queryForParentsListWithFileId:(NSString *)fileId;

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
+ (instancetype)queryForPermissionsDeleteWithFileId:(NSString *)fileId
                                       permissionId:(NSString *)permissionId;

// Method: drive.permissions.get
// Gets a permission by ID.
//  Required:
//   fileId: The ID for the file.
//   permissionId: The ID for the permission.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDrivePermission.
+ (instancetype)queryForPermissionsGetWithFileId:(NSString *)fileId
                                    permissionId:(NSString *)permissionId;

// Method: drive.permissions.getIdForEmail
// Returns the permission ID for an email address.
//  Required:
//   email: The email address for which to return a permission ID
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveAppsReadonly
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDrivePermissionId.
+ (instancetype)queryForPermissionsGetIdForEmailWithEmail:(NSString *)email;

// Method: drive.permissions.insert
// Inserts a permission for a file.
//  Required:
//   fileId: The ID for the file.
//  Optional:
//   emailMessage: A custom message to include in notification emails.
//   sendNotificationEmails: Whether to send notification emails when sharing to
//     users or groups. This parameter is ignored and an email is sent if the
//     role is owner. (Default true)
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDrivePermission.
+ (instancetype)queryForPermissionsInsertWithObject:(GTLDrivePermission *)object
                                             fileId:(NSString *)fileId;

// Method: drive.permissions.list
// Lists a file's permissions.
//  Required:
//   fileId: The ID for the file.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDrivePermissionList.
+ (instancetype)queryForPermissionsListWithFileId:(NSString *)fileId;

// Method: drive.permissions.patch
// Updates a permission. This method supports patch semantics.
//  Required:
//   fileId: The ID for the file.
//   permissionId: The ID for the permission.
//  Optional:
//   transferOwnership: Whether changing a role to 'owner' downgrades the
//     current owners to writers. Does nothing if the specified role is not
//     'owner'. (Default false)
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDrivePermission.
+ (instancetype)queryForPermissionsPatchWithObject:(GTLDrivePermission *)object
                                            fileId:(NSString *)fileId
                                      permissionId:(NSString *)permissionId;

// Method: drive.permissions.update
// Updates a permission.
//  Required:
//   fileId: The ID for the file.
//   permissionId: The ID for the permission.
//  Optional:
//   transferOwnership: Whether changing a role to 'owner' downgrades the
//     current owners to writers. Does nothing if the specified role is not
//     'owner'. (Default false)
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDrivePermission.
+ (instancetype)queryForPermissionsUpdateWithObject:(GTLDrivePermission *)object
                                             fileId:(NSString *)fileId
                                       permissionId:(NSString *)permissionId;

#pragma mark -
#pragma mark "properties" methods
// These create a GTLQueryDrive object.

// Method: drive.properties.delete
// Deletes a property.
//  Required:
//   fileId: The ID of the file.
//   propertyKey: The key of the property.
//  Optional:
//   visibility: The visibility of the property. (Default private)
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
+ (instancetype)queryForPropertiesDeleteWithFileId:(NSString *)fileId
                                       propertyKey:(NSString *)propertyKey;

// Method: drive.properties.get
// Gets a property by its key.
//  Required:
//   fileId: The ID of the file.
//   propertyKey: The key of the property.
//  Optional:
//   visibility: The visibility of the property. (Default private)
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveProperty.
+ (instancetype)queryForPropertiesGetWithFileId:(NSString *)fileId
                                    propertyKey:(NSString *)propertyKey;

// Method: drive.properties.insert
// Adds a property to a file.
//  Required:
//   fileId: The ID of the file.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
// Fetches a GTLDriveProperty.
+ (instancetype)queryForPropertiesInsertWithObject:(GTLDriveProperty *)object
                                            fileId:(NSString *)fileId;

// Method: drive.properties.list
// Lists a file's properties.
//  Required:
//   fileId: The ID of the file.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDrivePropertyList.
+ (instancetype)queryForPropertiesListWithFileId:(NSString *)fileId;

// Method: drive.properties.patch
// Updates a property. This method supports patch semantics.
//  Required:
//   fileId: The ID of the file.
//   propertyKey: The key of the property.
//  Optional:
//   visibility: The visibility of the property. (Default private)
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
// Fetches a GTLDriveProperty.
+ (instancetype)queryForPropertiesPatchWithObject:(GTLDriveProperty *)object
                                           fileId:(NSString *)fileId
                                      propertyKey:(NSString *)propertyKey;

// Method: drive.properties.update
// Updates a property.
//  Required:
//   fileId: The ID of the file.
//   propertyKey: The key of the property.
//  Optional:
//   visibility: The visibility of the property. (Default private)
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
// Fetches a GTLDriveProperty.
+ (instancetype)queryForPropertiesUpdateWithObject:(GTLDriveProperty *)object
                                            fileId:(NSString *)fileId
                                       propertyKey:(NSString *)propertyKey;

#pragma mark -
#pragma mark "realtime" methods
// These create a GTLQueryDrive object.

// Method: drive.realtime.get
// Exports the contents of the Realtime API data model associated with this file
// as JSON.
//  Required:
//   fileId: The ID of the file that the Realtime API data model is associated
//     with.
//  Optional:
//   revision: The revision of the Realtime API data model to export. Revisions
//     start at 1 (the initial empty data model) and are incremented with each
//     change. If this parameter is excluded, the most recent data model will be
//     returned.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveReadonly
+ (instancetype)queryForRealtimeGetWithFileId:(NSString *)fileId;

// Method: drive.realtime.update
// Overwrites the Realtime API data model associated with this file with the
// provided JSON data model.
//  Required:
//   fileId: The ID of the file that the Realtime API data model is associated
//     with.
//  Optional:
//   baseRevision: The revision of the model to diff the uploaded model against.
//     If set, the uploaded model is diffed against the provided revision and
//     those differences are merged with any changes made to the model after the
//     provided revision. If not set, the uploaded model replaces the current
//     model on the server.
//  Upload Parameters:
//   Maximum size: 10MB
//   Accepted MIME type(s): */*
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
+ (instancetype)queryForRealtimeUpdateWithFileId:(NSString *)fileId
                                uploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

#pragma mark -
#pragma mark "replies" methods
// These create a GTLQueryDrive object.

// Method: drive.replies.delete
// Deletes a reply.
//  Required:
//   fileId: The ID of the file.
//   commentId: The ID of the comment.
//   replyId: The ID of the reply.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
+ (instancetype)queryForRepliesDeleteWithFileId:(NSString *)fileId
                                      commentId:(NSString *)commentId
                                        replyId:(NSString *)replyId;

// Method: drive.replies.get
// Gets a reply.
//  Required:
//   fileId: The ID of the file.
//   commentId: The ID of the comment.
//   replyId: The ID of the reply.
//  Optional:
//   includeDeleted: If set, this will succeed when retrieving a deleted reply.
//     (Default false)
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveCommentReply.
+ (instancetype)queryForRepliesGetWithFileId:(NSString *)fileId
                                   commentId:(NSString *)commentId
                                     replyId:(NSString *)replyId;

// Method: drive.replies.insert
// Creates a new reply to the given comment.
//  Required:
//   fileId: The ID of the file.
//   commentId: The ID of the comment.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveCommentReply.
+ (instancetype)queryForRepliesInsertWithObject:(GTLDriveCommentReply *)object
                                         fileId:(NSString *)fileId
                                      commentId:(NSString *)commentId;

// Method: drive.replies.list
// Lists all of the replies to a comment.
//  Required:
//   fileId: The ID of the file.
//   commentId: The ID of the comment.
//  Optional:
//   includeDeleted: If set, all replies, including deleted replies (with
//     content stripped) will be returned. (Default false)
//   maxResults: The maximum number of replies to include in the response, used
//     for paging. (0..100, default 20)
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveCommentReplyList.
+ (instancetype)queryForRepliesListWithFileId:(NSString *)fileId
                                    commentId:(NSString *)commentId;

// Method: drive.replies.patch
// Updates an existing reply. This method supports patch semantics.
//  Required:
//   fileId: The ID of the file.
//   commentId: The ID of the comment.
//   replyId: The ID of the reply.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveCommentReply.
+ (instancetype)queryForRepliesPatchWithObject:(GTLDriveCommentReply *)object
                                        fileId:(NSString *)fileId
                                     commentId:(NSString *)commentId
                                       replyId:(NSString *)replyId;

// Method: drive.replies.update
// Updates an existing reply.
//  Required:
//   fileId: The ID of the file.
//   commentId: The ID of the comment.
//   replyId: The ID of the reply.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveCommentReply.
+ (instancetype)queryForRepliesUpdateWithObject:(GTLDriveCommentReply *)object
                                         fileId:(NSString *)fileId
                                      commentId:(NSString *)commentId
                                        replyId:(NSString *)replyId;

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
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
+ (instancetype)queryForRevisionsDeleteWithFileId:(NSString *)fileId
                                       revisionId:(NSString *)revisionId;

// Method: drive.revisions.get
// Gets a specific revision.
//  Required:
//   fileId: The ID of the file.
//   revisionId: The ID of the revision.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveRevision.
+ (instancetype)queryForRevisionsGetWithFileId:(NSString *)fileId
                                    revisionId:(NSString *)revisionId;

// Method: drive.revisions.list
// Lists a file's revisions.
//  Required:
//   fileId: The ID of the file.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
//   kGTLAuthScopeDriveMetadata
//   kGTLAuthScopeDriveMetadataReadonly
//   kGTLAuthScopeDriveReadonly
// Fetches a GTLDriveRevisionList.
+ (instancetype)queryForRevisionsListWithFileId:(NSString *)fileId;

// Method: drive.revisions.patch
// Updates a revision. This method supports patch semantics.
//  Required:
//   fileId: The ID for the file.
//   revisionId: The ID for the revision.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveRevision.
+ (instancetype)queryForRevisionsPatchWithObject:(GTLDriveRevision *)object
                                          fileId:(NSString *)fileId
                                      revisionId:(NSString *)revisionId;

// Method: drive.revisions.update
// Updates a revision.
//  Required:
//   fileId: The ID for the file.
//   revisionId: The ID for the revision.
//  Authorization scope(s):
//   kGTLAuthScopeDrive
//   kGTLAuthScopeDriveAppdata
//   kGTLAuthScopeDriveFile
// Fetches a GTLDriveRevision.
+ (instancetype)queryForRevisionsUpdateWithObject:(GTLDriveRevision *)object
                                           fileId:(NSString *)fileId
                                       revisionId:(NSString *)revisionId;

@end
