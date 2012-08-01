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
// Documentation:
//   https://developers.google.com/drive/
// Classes:
//   GTLDriveFile (0 custom class methods, 33 custom properties)
//   GTLDriveFileExportLinks (0 custom class methods, 0 custom properties)
//   GTLDriveFileImageMediaMetadata (0 custom class methods, 4 custom properties)
//   GTLDriveFileIndexableText (0 custom class methods, 1 custom properties)
//   GTLDriveFileLabels (0 custom class methods, 5 custom properties)
//   GTLDriveFileImageMediaMetadataLocation (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLDriveFileExportLinks;
@class GTLDriveFileImageMediaMetadata;
@class GTLDriveFileImageMediaMetadataLocation;
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

// A link for opening the file in using a relevant Google editor or viewer.
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

// Whether this file has been explicitly trashed, as opposed to recursively
// trashed. This will only be populated if the file is trashed.
@property (retain) NSNumber *explicitlyTrashed;  // boolValue

// Links for exporting Google Docs to specific formats.
@property (retain) GTLDriveFileExportLinks *exportLinks;

// The file extension used when downloading this file. This field is set from
// the title when inserting or uploading new content. This will only be
// populated on files with content stored in Drive.
@property (copy) NSString *fileExtension;

// The size of the file in bytes. This will only be populated on files with
// content stored in Drive.
@property (retain) NSNumber *fileSize;  // longLongValue

// The id of the file.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Metadata about image media. This will only be present for image types, and
// its contents will depend on what can be parsed from the image content.
@property (retain) GTLDriveFileImageMediaMetadata *imageMediaMetadata;

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

// The MIME type of the file. This is only mutable on update when uploading new
// content. This field can be left blank, and the mimetype will be determined
// from the uploaded content's MIME type.
@property (copy) NSString *mimeType;

// Last time this file was modified by the user (formatted RFC 3339 timestamp).
// Note that setting modifiedDate will also update the modifiedByMe date for the
// user which set the date.
@property (retain) GTLDateTime *modifiedByMeDate;

// Last time this file was modified by anyone (formatted RFC 3339 timestamp).
// This is only mutable on update when the setModifiedDate parameter is set.
@property (retain) GTLDateTime *modifiedDate;

// The original filename if the file was uploaded manually, or the original
// title if the file was inserted through the API. Note that renames of the
// title will not change the original filename. This will only be populated on
// files with content stored in Drive.
@property (copy) NSString *originalFilename;

// Name(s) of the owner(s) of this file.
@property (retain) NSArray *ownerNames;  // of NSString

// Collection of parent folders which contain this file.
// Setting this field will put the file in all of the provided folders. On
// insert, if no folders are provided, the file will be placed in the default
// root folder.
@property (retain) NSArray *parents;  // of GTLDriveParentReference

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

// A link for downloading the content of the file in a browser using cookie
// based authentication. In cases where the content is shared publicly, the
// content can be downloaded without any credentials.
@property (copy) NSString *webContentLink;

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
//   GTLDriveFileImageMediaMetadata
//

@interface GTLDriveFileImageMediaMetadata : GTLObject

// The height of the image in pixels.
@property (retain) NSNumber *height;  // intValue

// Geographic location information stored in the image.
@property (retain) GTLDriveFileImageMediaMetadataLocation *location;

// The rotation in clockwise degrees from the image's original orientation.
@property (retain) NSNumber *rotation;  // intValue

// The width of the image in pixels.
@property (retain) NSNumber *width;  // intValue

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


// ----------------------------------------------------------------------------
//
//   GTLDriveFileImageMediaMetadataLocation
//

@interface GTLDriveFileImageMediaMetadataLocation : GTLObject

// The altitude stored in the image.
@property (retain) NSNumber *altitude;  // doubleValue

// The latitude stored in the image.
@property (retain) NSNumber *latitude;  // doubleValue

// The longitude stored in the image.
@property (retain) NSNumber *longitude;  // doubleValue

@end
