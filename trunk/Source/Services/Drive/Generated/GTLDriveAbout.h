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
//  GTLDriveAbout.h
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
//   GTLDriveAbout (0 custom class methods, 24 custom properties)
//   GTLDriveAboutAdditionalRoleInfoItem (0 custom class methods, 2 custom properties)
//   GTLDriveAboutExportFormatsItem (0 custom class methods, 2 custom properties)
//   GTLDriveAboutFeaturesItem (0 custom class methods, 2 custom properties)
//   GTLDriveAboutImportFormatsItem (0 custom class methods, 2 custom properties)
//   GTLDriveAboutMaxUploadSizesItem (0 custom class methods, 2 custom properties)
//   GTLDriveAboutQuotaBytesByServiceItem (0 custom class methods, 2 custom properties)
//   GTLDriveAboutAdditionalRoleInfoItemRoleSetsItem (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLDriveAboutAdditionalRoleInfoItem;
@class GTLDriveAboutAdditionalRoleInfoItemRoleSetsItem;
@class GTLDriveAboutExportFormatsItem;
@class GTLDriveAboutFeaturesItem;
@class GTLDriveAboutImportFormatsItem;
@class GTLDriveAboutMaxUploadSizesItem;
@class GTLDriveAboutQuotaBytesByServiceItem;
@class GTLDriveUser;

// ----------------------------------------------------------------------------
//
//   GTLDriveAbout
//

// An item with user information and settings.

@interface GTLDriveAbout : GTLObject

// Information about supported additional roles per file type. The most specific
// type takes precedence.
@property (nonatomic, retain) NSArray *additionalRoleInfo;  // of GTLDriveAboutAdditionalRoleInfoItem

// The domain sharing policy for the current user. Possible values are:
// - ALLOWED
// - ALLOWED_WITH_WARNING
// - INCOMING_ONLY
// - DISALLOWED
@property (nonatomic, copy) NSString *domainSharingPolicy;

// The ETag of the item.
@property (nonatomic, copy) NSString *ETag;

// The allowable export formats.
@property (nonatomic, retain) NSArray *exportFormats;  // of GTLDriveAboutExportFormatsItem

// List of additional features enabled on this account.
@property (nonatomic, retain) NSArray *features;  // of GTLDriveAboutFeaturesItem

// The palette of allowable folder colors as RGB hex strings.
@property (nonatomic, retain) NSArray *folderColorPalette;  // of NSString

// The allowable import formats.
@property (nonatomic, retain) NSArray *importFormats;  // of GTLDriveAboutImportFormatsItem

// A boolean indicating whether the authenticated app is installed by the
// authenticated user.
@property (nonatomic, retain) NSNumber *isCurrentAppInstalled;  // boolValue

// This is always drive#about.
@property (nonatomic, copy) NSString *kind;

// The user's language or locale code, as defined by BCP 47, with some
// extensions from Unicode's LDML format (http://www.unicode.org/reports/tr35/).
@property (nonatomic, copy) NSString *languageCode;

// The largest change id.
@property (nonatomic, retain) NSNumber *largestChangeId;  // longLongValue

// List of max upload sizes for each file type. The most specific type takes
// precedence.
@property (nonatomic, retain) NSArray *maxUploadSizes;  // of GTLDriveAboutMaxUploadSizesItem

// The name of the current user.
@property (nonatomic, copy) NSString *name;

// The current user's ID as visible in the permissions collection.
@property (nonatomic, copy) NSString *permissionId;

// The amount of storage quota used by different Google services.
@property (nonatomic, retain) NSArray *quotaBytesByService;  // of GTLDriveAboutQuotaBytesByServiceItem

// The total number of quota bytes.
@property (nonatomic, retain) NSNumber *quotaBytesTotal;  // longLongValue

// The number of quota bytes used by Google Drive.
@property (nonatomic, retain) NSNumber *quotaBytesUsed;  // longLongValue

// The number of quota bytes used by all Google apps (Drive, Picasa, etc.).
@property (nonatomic, retain) NSNumber *quotaBytesUsedAggregate;  // longLongValue

// The number of quota bytes used by trashed items.
@property (nonatomic, retain) NSNumber *quotaBytesUsedInTrash;  // longLongValue

// The type of the user's storage quota. Possible values are:
// - LIMITED
// - UNLIMITED
@property (nonatomic, copy) NSString *quotaType;

// The number of remaining change ids.
@property (nonatomic, retain) NSNumber *remainingChangeIds;  // longLongValue

// The id of the root folder.
@property (nonatomic, copy) NSString *rootFolderId;

// A link back to this item.
@property (nonatomic, copy) NSString *selfLink;

// The authenticated user.
@property (nonatomic, retain) GTLDriveUser *user;

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveAboutAdditionalRoleInfoItem
//

@interface GTLDriveAboutAdditionalRoleInfoItem : GTLObject

// The supported additional roles per primary role.
@property (nonatomic, retain) NSArray *roleSets;  // of GTLDriveAboutAdditionalRoleInfoItemRoleSetsItem

// The content type that this additional role info applies to.
@property (nonatomic, copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveAboutExportFormatsItem
//

@interface GTLDriveAboutExportFormatsItem : GTLObject

// The content type to convert from.
@property (nonatomic, copy) NSString *source;

// The possible content types to convert to.
@property (nonatomic, retain) NSArray *targets;  // of NSString

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveAboutFeaturesItem
//

@interface GTLDriveAboutFeaturesItem : GTLObject

// The name of the feature.
@property (nonatomic, copy) NSString *featureName;

// The request limit rate for this feature, in queries per second.
@property (nonatomic, retain) NSNumber *featureRate;  // doubleValue

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveAboutImportFormatsItem
//

@interface GTLDriveAboutImportFormatsItem : GTLObject

// The imported file's content type to convert from.
@property (nonatomic, copy) NSString *source;

// The possible content types to convert to.
@property (nonatomic, retain) NSArray *targets;  // of NSString

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveAboutMaxUploadSizesItem
//

@interface GTLDriveAboutMaxUploadSizesItem : GTLObject

// The max upload size for this type.
@property (nonatomic, retain) NSNumber *size;  // longLongValue

// The file type.
@property (nonatomic, copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveAboutQuotaBytesByServiceItem
//

@interface GTLDriveAboutQuotaBytesByServiceItem : GTLObject

// The storage quota bytes used by the service.
@property (nonatomic, retain) NSNumber *bytesUsed;  // longLongValue

// The service's name, e.g. DRIVE, GMAIL, or PHOTOS.
@property (nonatomic, copy) NSString *serviceName;

@end


// ----------------------------------------------------------------------------
//
//   GTLDriveAboutAdditionalRoleInfoItemRoleSetsItem
//

@interface GTLDriveAboutAdditionalRoleInfoItemRoleSetsItem : GTLObject

// The supported additional roles with the primary role.
@property (nonatomic, retain) NSArray *additionalRoles;  // of NSString

// A primary permission role.
@property (nonatomic, copy) NSString *primaryRole;

@end
