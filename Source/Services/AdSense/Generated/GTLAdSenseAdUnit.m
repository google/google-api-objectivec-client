/* Copyright (c) 2013 Google Inc.
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
//  GTLAdSenseAdUnit.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Management API (adsense/v1.4)
// Description:
//   Gives AdSense publishers access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://developers.google.com/adsense/management/
// Classes:
//   GTLAdSenseAdUnit (0 custom class methods, 10 custom properties)
//   GTLAdSenseAdUnitContentAdsSettings (0 custom class methods, 3 custom properties)
//   GTLAdSenseAdUnitFeedAdsSettings (0 custom class methods, 4 custom properties)
//   GTLAdSenseAdUnitMobileContentAdsSettings (0 custom class methods, 4 custom properties)
//   GTLAdSenseAdUnitContentAdsSettingsBackupOption (0 custom class methods, 3 custom properties)

#import "GTLAdSenseAdUnit.h"

#import "GTLAdSenseAdStyle.h"

// ----------------------------------------------------------------------------
//
//   GTLAdSenseAdUnit
//

@implementation GTLAdSenseAdUnit
@dynamic code, contentAdsSettings, customStyle, feedAdsSettings, identifier,
         kind, mobileContentAdsSettings, name, savedStyleId, status;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"adsense#adUnit"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAdSenseAdUnitContentAdsSettings
//

@implementation GTLAdSenseAdUnitContentAdsSettings
@dynamic backupOption, size, type;
@end


// ----------------------------------------------------------------------------
//
//   GTLAdSenseAdUnitFeedAdsSettings
//

@implementation GTLAdSenseAdUnitFeedAdsSettings
@dynamic adPosition, frequency, minimumWordCount, type;
@end


// ----------------------------------------------------------------------------
//
//   GTLAdSenseAdUnitMobileContentAdsSettings
//

@implementation GTLAdSenseAdUnitMobileContentAdsSettings
@dynamic markupLanguage, scriptingLanguage, size, type;
@end


// ----------------------------------------------------------------------------
//
//   GTLAdSenseAdUnitContentAdsSettingsBackupOption
//

@implementation GTLAdSenseAdUnitContentAdsSettingsBackupOption
@dynamic color, type, url;
@end
