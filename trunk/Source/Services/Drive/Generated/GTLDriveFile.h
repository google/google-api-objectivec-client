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
//  GTLDriveFile.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Drive API (drive/v2)
// Description:
//   The API to interact with Drive.
// Classes:
//   GTLDriveFile (0 custom class methods, 31 custom properties)
//   GTLDriveFileExportLinks (0 custom class methods, 0 custom properties)
//   GTLDriveFileIndexableText (0 custom class methods, 1 custom properties)
//   GTLDriveFileLabels (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLDriveFileExportLinks;
@class GTLDriveFileIndexableText;
@class GTLDriveFileLabels;
@class GTLDriveParentReference;
@class GTLDrivePermission;

// ----------------------------------------------------------------------------
//
//   GTLDriveFile
//

// The metadata for a file.

@interface GTLDriveFile : GTLObject

// A link for opening the file in a browser.
@property (copy) NSString *alternateLink;

// Create time for this file (formatted ISO8601 timestamp).
@property (retain) GTLDateTime *createdDate;

// A short description of the file.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Short term download URL for the file. This will only be populated on files
// with content stored in Drive.
@property (copy) NSString *downloadUrl;

// Whether the file can be edited by the current user.
@property (retain) NSNumber *editable;  // boolValue

// A link for embedding the file.
@property (copy) NSString *embedLink;

// ETag of the file.
@property (copy) NSString *ETag;

// Links for exporting Google Docs to specific formats.
@property (retain) GTLDriveFileExportLinks *exportLinks;

// The file extension used when downloading this file. This field is read only.
// To set the extension, include it on title when creating the file. This will
// only be populated on files with content stored in Drive.
@property (copy) NSString *fileExtension;

// The size of the file in bytes. This will only be populated on files with
// content stored in Drive.
@property (retain) NSNumber *fileSize;  // longLongValue

// The id of the file.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Indexable text attributes for the file (can only be written)
@property (retain) GTLDriveFileIndexableText *indexableText;

// The type of file. This is always drive#file.
@property (copy) NSString *kind;

// A group of labels for the file.
@property (retain) GTLDriveFileLabels *labels;

// Name of the last user to modify this file. This will only be populated if a
// user has edited this file.
@property (copy) NSString *lastModifyingUserName;

// Last time this file was viewed by the user (formatted RFC 3339 timestamp).
@property (retain) GTLDateTime *lastViewedByMeDate;

// An MD5 checksum for the content of this file. This will only be populated on
// files with content stored in Drive.
@property (copy) NSString *md5Checksum;

// The MIME type of the file.
@property (copy) NSString *mimeType;

// Last time this file was modified by the user (formatted RFC 3339 timestamp).
@property (retain) GTLDateTime *modifiedByMeDate;

// Last time this file was modified by anyone (formatted RFC 3339 timestamp).
@property (retain) GTLDateTime *modifiedDate;

// The filename when uploading this file. This will only be populated on files
// with content stored in Drive.
@property (copy) NSString *originalFilename;

// Name(s) of the owner(s) of this file.
@property (retain) NSArray *ownerNames;  // of NSString

// Collection of parent folders which contain this file.
// On insert, setting this field will put the file in all of the provided
// folders. If no folders are provided, the file will be placed in the default
// root folder. On update, this field is ignored.
@property (retain) NSArray *parents;  // of GTLDriveParentReference

// A link to the permissions collection.
@property (copy) NSString *permissionsLink;

// The number of quota bytes used by this file.
@property (retain) NSNumber *quotaBytesUsed;  // longLongValue

// A link back to this file.
@property (copy) NSString *selfLink;

// Time at which this file was shared with the user (formatted RFC 3339
// timestamp).
@property (retain) GTLDateTime *sharedWithMeDate;

// A link to the file's thumbnail.
@property (copy) NSString *thumbnailLink;

// The title of this file.
@property (copy) NSString *title;

// The permissions for the authenticated user on this file.
@property (retain) GTLDrivePermission *userPermission;

// Whether writers can share the document with other users.
@property (retain) NSNumber *writersCanShare;  // boolValue

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileExportLinks
//

@interface GTLDriveFileExportLinks : GTLObject
// This object is documented as having more properties that are NSString. Use
// -additionalJSONKeys and -additionalPropertyForName: to get the list of
// properties and then fetch them; or -additionalProperties to fetch them all at
// once.
@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileIndexableText
//

@interface GTLDriveFileIndexableText : GTLObject

// The text to be indexed for this file
@property (copy) NSString *text;

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileLabels
//

@interface GTLDriveFileLabels : GTLObject

// Whether this file is hidden from the user.
@property (retain) NSNumber *hidden;  // boolValue

// Whether viewers are prevented from downloading this file.
@property (retain) NSNumber *restricted;  // boolValue

// Whether this file is starred by the user.
@property (retain) NSNumber *starred;  // boolValue

// Whether this file has been trashed.
@property (retain) NSNumber *trashed;  // boolValue

// Whether this file has been viewed by this user.
@property (retain) NSNumber *viewed;  // boolValue

@end
