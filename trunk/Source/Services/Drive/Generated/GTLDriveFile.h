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
//   GTLDriveFile (0 custom class methods, 55 custom properties)
//   GTLDriveFileExportLinks (0 custom class methods, 0 custom properties)
//   GTLDriveFileImageMediaMetadata (0 custom class methods, 21 custom properties)
//   GTLDriveFileIndexableText (0 custom class methods, 1 custom properties)
//   GTLDriveFileLabels (0 custom class methods, 5 custom properties)
//   GTLDriveFileOpenWithLinks (0 custom class methods, 0 custom properties)
//   GTLDriveFileThumbnail (0 custom class methods, 2 custom properties)
//   GTLDriveFileVideoMediaMetadata (0 custom class methods, 3 custom properties)
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
@class GTLDriveFileOpenWithLinks;
@class GTLDriveFileThumbnail;
@class GTLDriveFileVideoMediaMetadata;
@class GTLDriveParentReference;
@class GTLDrivePermission;
@class GTLDriveProperty;
@class GTLDriveUser;

// ----------------------------------------------------------------------------
//
//   GTLDriveFile
//

// The metadata for a file.

@interface GTLDriveFile : GTLObject

// A link for opening the file in a relevant Google editor or viewer.
@property (nonatomic, copy) NSString *alternateLink;

// Whether this file is in the Application Data folder.
@property (nonatomic, retain) NSNumber *appDataContents;  // boolValue

// Whether the current user can comment on the file.
@property (nonatomic, retain) NSNumber *canComment;  // boolValue

// Whether the file can be copied by the current user.
@property (nonatomic, retain) NSNumber *copyable;  // boolValue

// Create time for this file (formatted RFC 3339 timestamp).
@property (nonatomic, retain) GTLDateTime *createdDate;

// A link to open this file with the user's default app for this file. Only
// populated when the drive.apps.readonly scope is used.
@property (nonatomic, copy) NSString *defaultOpenWithLink;

// A short description of the file.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

@property (nonatomic, copy) NSString *downloadUrl;

// Whether the file can be edited by the current user.
@property (nonatomic, retain) NSNumber *editable;  // boolValue

// A link for embedding the file.
@property (nonatomic, copy) NSString *embedLink;

// ETag of the file.
@property (nonatomic, copy) NSString *ETag;

// Whether this file has been explicitly trashed, as opposed to recursively
// trashed.
@property (nonatomic, retain) NSNumber *explicitlyTrashed;  // boolValue

// Links for exporting Google Docs to specific formats.
@property (nonatomic, retain) GTLDriveFileExportLinks *exportLinks;

// The file extension used when downloading this file. This field is read only.
// To set the extension, include it in the title when creating the file. This is
// only populated for files with content stored in Drive.
@property (nonatomic, copy) NSString *fileExtension;

// The size of the file in bytes. This is only populated for files with content
// stored in Drive.
@property (nonatomic, retain) NSNumber *fileSize;  // longLongValue

// Folder color as an RGB hex string if the file is a folder. The list of
// supported colors is available in the folderColorPalette field of the About
// resource. If an unsupported color is specified, it will be changed to the
// closest color in the palette.
@property (nonatomic, copy) NSString *folderColorRgb;

// The ID of the file's head revision. This will only be populated for files
// with content stored in Drive.
@property (nonatomic, copy) NSString *headRevisionId;

// A link to the file's icon.
@property (nonatomic, copy) NSString *iconLink;

// The ID of the file.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Metadata about image media. This will only be present for image types, and
// its contents will depend on what can be parsed from the image content.
@property (nonatomic, retain) GTLDriveFileImageMediaMetadata *imageMediaMetadata;

// Indexable text attributes for the file (can only be written)
@property (nonatomic, retain) GTLDriveFileIndexableText *indexableText;

// The type of file. This is always drive#file.
@property (nonatomic, copy) NSString *kind;

// A group of labels for the file.
@property (nonatomic, retain) GTLDriveFileLabels *labels;

// The last user to modify this file.
@property (nonatomic, retain) GTLDriveUser *lastModifyingUser;

// Name of the last user to modify this file.
@property (nonatomic, copy) NSString *lastModifyingUserName;

// Last time this file was viewed by the user (formatted RFC 3339 timestamp).
@property (nonatomic, retain) GTLDateTime *lastViewedByMeDate;

// Time this file was explicitly marked viewed by the user (formatted RFC 3339
// timestamp).
@property (nonatomic, retain) GTLDateTime *markedViewedByMeDate;

// An MD5 checksum for the content of this file. This is populated only for
// files with content stored in Drive.
@property (nonatomic, copy) NSString *md5Checksum;

// The MIME type of the file. This is only mutable on update when uploading new
// content. This field can be left blank, and the mimetype will be determined
// from the uploaded content's MIME type.
@property (nonatomic, copy) NSString *mimeType;

// Last time this file was modified by the user (formatted RFC 3339 timestamp).
// Note that setting modifiedDate will also update the modifiedByMe date for the
// user which set the date.
@property (nonatomic, retain) GTLDateTime *modifiedByMeDate;

// Last time this file was modified by anyone (formatted RFC 3339 timestamp).
// This is only mutable on update when the setModifiedDate parameter is set.
@property (nonatomic, retain) GTLDateTime *modifiedDate;

// A map of the id of each of the user's apps to a link to open this file with
// that app. Only populated when the drive.apps.readonly scope is used.
@property (nonatomic, retain) GTLDriveFileOpenWithLinks *openWithLinks;

// The original filename if the file was uploaded manually, or the original
// title if the file was inserted through the API. Note that renames of the
// title will not change the original filename. This will only be populated on
// files with content stored in Drive.
@property (nonatomic, copy) NSString *originalFilename;

// Whether the file is owned by the current user.
@property (nonatomic, retain) NSNumber *ownedByMe;  // boolValue

// Name(s) of the owner(s) of this file.
@property (nonatomic, retain) NSArray *ownerNames;  // of NSString

// The owner(s) of this file.
@property (nonatomic, retain) NSArray *owners;  // of GTLDriveUser

// Collection of parent folders which contain this file.
// Setting this field will put the file in all of the provided folders. On
// insert, if no folders are provided, the file will be placed in the default
// root folder.
@property (nonatomic, retain) NSArray *parents;  // of GTLDriveParentReference

// The list of permissions for users with access to this file.
@property (nonatomic, retain) NSArray *permissions;  // of GTLDrivePermission

// The list of properties.
@property (nonatomic, retain) NSArray *properties;  // of GTLDriveProperty

// The number of quota bytes used by this file.
@property (nonatomic, retain) NSNumber *quotaBytesUsed;  // longLongValue

// A link back to this file.
@property (nonatomic, copy) NSString *selfLink;

// Whether the file's sharing settings can be modified by the current user.
@property (nonatomic, retain) NSNumber *shareable;  // boolValue

// Whether the file has been shared.
@property (nonatomic, retain) NSNumber *shared;  // boolValue

// Time at which this file was shared with the user (formatted RFC 3339
// timestamp).
@property (nonatomic, retain) GTLDateTime *sharedWithMeDate;

// User that shared the item with the current user, if available.
@property (nonatomic, retain) GTLDriveUser *sharingUser;

// The list of spaces which contain the file. Supported values are 'drive',
// 'appDataFolder' and 'photos'.
@property (nonatomic, retain) NSArray *spaces;  // of NSString

// Thumbnail for the file. Only accepted on upload and for files that are not
// already thumbnailed by Google.
@property (nonatomic, retain) GTLDriveFileThumbnail *thumbnail;

// A short-lived link to the file's thumbnail. Typically lasts on the order of
// hours.
@property (nonatomic, copy) NSString *thumbnailLink;

// The title of this file.
@property (nonatomic, copy) NSString *title;

// The permissions for the authenticated user on this file.
@property (nonatomic, retain) GTLDrivePermission *userPermission;

// A monotonically increasing version number for the file. This reflects every
// change made to the file on the server, even those not visible to the
// requesting user.
@property (nonatomic, retain) NSNumber *version;  // longLongValue

// Metadata about video media. This will only be present for video types.
@property (nonatomic, retain) GTLDriveFileVideoMediaMetadata *videoMediaMetadata;

// A link for downloading the content of the file in a browser using cookie
// based authentication. In cases where the content is shared publicly, the
// content can be downloaded without any credentials.
@property (nonatomic, copy) NSString *webContentLink;

// A link only available on public folders for viewing their static web assets
// (HTML, CSS, JS, etc) via Google Drive's Website Hosting.
@property (nonatomic, copy) NSString *webViewLink;

// Whether writers can share the document with other users.
@property (nonatomic, retain) NSNumber *writersCanShare;  // boolValue

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

// The aperture used to create the photo (f-number).
@property (nonatomic, retain) NSNumber *aperture;  // floatValue

// The make of the camera used to create the photo.
@property (nonatomic, copy) NSString *cameraMake;

// The model of the camera used to create the photo.
@property (nonatomic, copy) NSString *cameraModel;

// The color space of the photo.
@property (nonatomic, copy) NSString *colorSpace;

// The date and time the photo was taken (EXIF format timestamp).
@property (nonatomic, copy) NSString *date;

// The exposure bias of the photo (APEX value).
@property (nonatomic, retain) NSNumber *exposureBias;  // floatValue

// The exposure mode used to create the photo.
@property (nonatomic, copy) NSString *exposureMode;

// The length of the exposure, in seconds.
@property (nonatomic, retain) NSNumber *exposureTime;  // floatValue

// Whether a flash was used to create the photo.
@property (nonatomic, retain) NSNumber *flashUsed;  // boolValue

// The focal length used to create the photo, in millimeters.
@property (nonatomic, retain) NSNumber *focalLength;  // floatValue

// The height of the image in pixels.
@property (nonatomic, retain) NSNumber *height;  // intValue

// The ISO speed used to create the photo.
@property (nonatomic, retain) NSNumber *isoSpeed;  // intValue

// The lens used to create the photo.
@property (nonatomic, copy) NSString *lens;

// Geographic location information stored in the image.
@property (nonatomic, retain) GTLDriveFileImageMediaMetadataLocation *location;

// The smallest f-number of the lens at the focal length used to create the
// photo (APEX value).
@property (nonatomic, retain) NSNumber *maxApertureValue;  // floatValue

// The metering mode used to create the photo.
@property (nonatomic, copy) NSString *meteringMode;

// The rotation in clockwise degrees from the image's original orientation.
@property (nonatomic, retain) NSNumber *rotation;  // intValue

// The type of sensor used to create the photo.
@property (nonatomic, copy) NSString *sensor;

// The distance to the subject of the photo, in meters.
@property (nonatomic, retain) NSNumber *subjectDistance;  // intValue

// The white balance mode used to create the photo.
@property (nonatomic, copy) NSString *whiteBalance;

// The width of the image in pixels.
@property (nonatomic, retain) NSNumber *width;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileIndexableText
//

@interface GTLDriveFileIndexableText : GTLObject

// The text to be indexed for this file.
@property (nonatomic, copy) NSString *text;

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileLabels
//

@interface GTLDriveFileLabels : GTLObject

// Deprecated.
@property (nonatomic, retain) NSNumber *hidden;  // boolValue

// Whether viewers are prevented from downloading this file.
@property (nonatomic, retain) NSNumber *restricted;  // boolValue

// Whether this file is starred by the user.
@property (nonatomic, retain) NSNumber *starred;  // boolValue

// Whether this file has been trashed. This label applies to all users accessing
// the file; however, only owners are allowed to see and untrash files.
@property (nonatomic, retain) NSNumber *trashed;  // boolValue

// Whether this file has been viewed by this user.
@property (nonatomic, retain) NSNumber *viewed;  // boolValue

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileOpenWithLinks
//

@interface GTLDriveFileOpenWithLinks : GTLObject
// This object is documented as having more properties that are NSString. Use
// -additionalJSONKeys and -additionalPropertyForName: to get the list of
// properties and then fetch them; or -additionalProperties to fetch them all at
// once.
@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileThumbnail
//

@interface GTLDriveFileThumbnail : GTLObject

// The URL-safe Base64 encoded bytes of the thumbnail image. It should conform
// to RFC 4648 section 5.
@property (nonatomic, copy) NSString *image;  // GTLBase64 can encode/decode (probably web-safe format)

// The MIME type of the thumbnail.
@property (nonatomic, copy) NSString *mimeType;

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileVideoMediaMetadata
//

@interface GTLDriveFileVideoMediaMetadata : GTLObject

// The duration of the video in milliseconds.
@property (nonatomic, retain) NSNumber *durationMillis;  // longLongValue

// The height of the video in pixels.
@property (nonatomic, retain) NSNumber *height;  // intValue

// The width of the video in pixels.
@property (nonatomic, retain) NSNumber *width;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileImageMediaMetadataLocation
//

@interface GTLDriveFileImageMediaMetadataLocation : GTLObject

// The altitude stored in the image.
@property (nonatomic, retain) NSNumber *altitude;  // doubleValue

// The latitude stored in the image.
@property (nonatomic, retain) NSNumber *latitude;  // doubleValue

// The longitude stored in the image.
@property (nonatomic, retain) NSNumber *longitude;  // doubleValue

@end
