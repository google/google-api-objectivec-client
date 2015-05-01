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
//  GTLAdSenseHostAdUnit.m
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

#import "GTLAdSenseHostAdUnit.h"

#import "GTLAdSenseHostAdStyle.h"

// ----------------------------------------------------------------------------
//
//   GTLAdSenseHostAdUnit
//

@implementation GTLAdSenseHostAdUnit
@dynamic code, contentAdsSettings, customStyle, identifier, kind,
         mobileContentAdsSettings, name, status;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"identifier" : @"id"
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"adsensehost#adUnit"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAdSenseHostAdUnitContentAdsSettings
//

@implementation GTLAdSenseHostAdUnitContentAdsSettings
@dynamic backupOption, size, type;
@end


// ----------------------------------------------------------------------------
//
//   GTLAdSenseHostAdUnitMobileContentAdsSettings
//

@implementation GTLAdSenseHostAdUnitMobileContentAdsSettings
@dynamic markupLanguage, scriptingLanguage, size, type;
@end


// ----------------------------------------------------------------------------
//
//   GTLAdSenseHostAdUnitContentAdsSettingsBackupOption
//

@implementation GTLAdSenseHostAdUnitContentAdsSettingsBackupOption
@dynamic color, type, url;
@end
