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
//  GTLAdSenseHostAdUnit.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Host API (adsensehost/v4.1)
// Description:
//   Gives AdSense Hosts access to report generation, ad code generation, and
//   publisher management capabilities.
// Documentation:
//   https://developers.google.com/adsense/host/
// Classes:
//   GTLAdSenseHostAdUnit (0 custom class methods, 8 custom properties)
//   GTLAdSenseHostAdUnitContentAdsSettings (0 custom class methods, 3 custom properties)
//   GTLAdSenseHostAdUnitMobileContentAdsSettings (0 custom class methods, 4 custom properties)
//   GTLAdSenseHostAdUnitContentAdsSettingsBackupOption (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdSenseHostAdStyle;
@class GTLAdSenseHostAdUnitContentAdsSettings;
@class GTLAdSenseHostAdUnitContentAdsSettingsBackupOption;
@class GTLAdSenseHostAdUnitMobileContentAdsSettings;

// ----------------------------------------------------------------------------
//
//   GTLAdSenseHostAdUnit
//

@interface GTLAdSenseHostAdUnit : GTLObject

// Identity code of this ad unit, not necessarily unique across ad clients.
@property (nonatomic, copy) NSString *code;

// Settings specific to content ads (AFC) and highend mobile content ads (AFMC).
@property (nonatomic, retain) GTLAdSenseHostAdUnitContentAdsSettings *contentAdsSettings;

// Custom style information specific to this ad unit.
@property (nonatomic, retain) GTLAdSenseHostAdStyle *customStyle;

// Unique identifier of this ad unit. This should be considered an opaque
// identifier; it is not safe to rely on it being in any particular format.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Kind of resource this is, in this case adsensehost#adUnit.
@property (nonatomic, copy) NSString *kind;

// Settings specific to WAP mobile content ads (AFMC).
@property (nonatomic, retain) GTLAdSenseHostAdUnitMobileContentAdsSettings *mobileContentAdsSettings;

// Name of this ad unit.
@property (nonatomic, copy) NSString *name;

// Status of this ad unit. Possible values are:
// NEW: Indicates that the ad unit was created within the last seven days and
// does not yet have any activity associated with it.
// ACTIVE: Indicates that there has been activity on this ad unit in the last
// seven days.
// INACTIVE: Indicates that there has been no activity on this ad unit in the
// last seven days.
@property (nonatomic, copy) NSString *status;

@end


// ----------------------------------------------------------------------------
//
//   GTLAdSenseHostAdUnitContentAdsSettings
//

@interface GTLAdSenseHostAdUnitContentAdsSettings : GTLObject

// The backup option to be used in instances where no ad is available.
@property (nonatomic, retain) GTLAdSenseHostAdUnitContentAdsSettingsBackupOption *backupOption;

// Size of this ad unit. Size values are in the form SIZE_{width}_{height}.
@property (nonatomic, copy) NSString *size;

// Type of this ad unit. Possible values are TEXT, TEXT_IMAGE, IMAGE and LINK.
@property (nonatomic, copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLAdSenseHostAdUnitMobileContentAdsSettings
//

@interface GTLAdSenseHostAdUnitMobileContentAdsSettings : GTLObject

// The markup language to use for this ad unit.
@property (nonatomic, copy) NSString *markupLanguage;

// The scripting language to use for this ad unit.
@property (nonatomic, copy) NSString *scriptingLanguage;

// Size of this ad unit.
@property (nonatomic, copy) NSString *size;

// Type of this ad unit.
@property (nonatomic, copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLAdSenseHostAdUnitContentAdsSettingsBackupOption
//

@interface GTLAdSenseHostAdUnitContentAdsSettingsBackupOption : GTLObject

// Color to use when type is set to COLOR. These are represented as six
// hexadecimal characters, similar to HTML color codes, but without the leading
// hash.
@property (nonatomic, copy) NSString *color;

// Type of the backup option. Possible values are BLANK, COLOR and URL.
@property (nonatomic, copy) NSString *type;

// URL to use when type is set to URL.
@property (nonatomic, copy) NSString *url;

@end
