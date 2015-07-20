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
//  GTLDriveFile.m
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

#import "GTLDriveFile.h"

#import "GTLDriveParentReference.h"
#import "GTLDrivePermission.h"
#import "GTLDriveProperty.h"
#import "GTLDriveUser.h"

// ----------------------------------------------------------------------------
//
//   GTLDriveFile
//

@implementation GTLDriveFile
@dynamic alternateLink, appDataContents, canComment, copyable, createdDate,
         defaultOpenWithLink, descriptionProperty, downloadUrl, editable,
         embedLink, ETag, explicitlyTrashed, exportLinks, fileExtension,
         fileSize, folderColorRgb, headRevisionId, iconLink, identifier,
         imageMediaMetadata, indexableText, kind, labels, lastModifyingUser,
         lastModifyingUserName, lastViewedByMeDate, markedViewedByMeDate,
         md5Checksum, mimeType, modifiedByMeDate, modifiedDate, openWithLinks,
         originalFilename, ownedByMe, ownerNames, owners, parents, permissions,
         properties, quotaBytesUsed, selfLink, shareable, shared,
         sharedWithMeDate, sharingUser, spaces, thumbnail, thumbnailLink, title,
         userPermission, version, videoMediaMetadata, webContentLink,
         webViewLink, writersCanShare;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"descriptionProperty" : @"description",
    @"ETag" : @"etag",
    @"identifier" : @"id"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"ownerNames" : [NSString class],
    @"owners" : [GTLDriveUser class],
    @"parents" : [GTLDriveParentReference class],
    @"permissions" : [GTLDrivePermission class],
    @"properties" : [GTLDriveProperty class],
    @"spaces" : [NSString class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"drive#file"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileExportLinks
//

@implementation GTLDriveFileExportLinks

+ (Class)classForAdditionalProperties {
  return [NSString class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileImageMediaMetadata
//

@implementation GTLDriveFileImageMediaMetadata
@dynamic aperture, cameraMake, cameraModel, colorSpace, date, exposureBias,
         exposureMode, exposureTime, flashUsed, focalLength, height, isoSpeed,
         lens, location, maxApertureValue, meteringMode, rotation, sensor,
         subjectDistance, whiteBalance, width;
@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileIndexableText
//

@implementation GTLDriveFileIndexableText
@dynamic text;
@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileLabels
//

@implementation GTLDriveFileLabels
@dynamic hidden, restricted, starred, trashed, viewed;
@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileOpenWithLinks
//

@implementation GTLDriveFileOpenWithLinks

+ (Class)classForAdditionalProperties {
  return [NSString class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileThumbnail
//

@implementation GTLDriveFileThumbnail
@dynamic image, mimeType;
@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileVideoMediaMetadata
//

@implementation GTLDriveFileVideoMediaMetadata
@dynamic durationMillis, height, width;
@end


// ----------------------------------------------------------------------------
//
//   GTLDriveFileImageMediaMetadataLocation
//

@implementation GTLDriveFileImageMediaMetadataLocation
@dynamic altitude, latitude, longitude;
@end
