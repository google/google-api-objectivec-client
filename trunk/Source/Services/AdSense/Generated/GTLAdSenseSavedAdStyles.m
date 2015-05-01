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
//  GTLAdSenseSavedAdStyles.m
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
//   GTLAdSenseSavedAdStyles (0 custom class methods, 4 custom properties)

#import "GTLAdSenseSavedAdStyles.h"

#import "GTLAdSenseSavedAdStyle.h"

// ----------------------------------------------------------------------------
//
//   GTLAdSenseSavedAdStyles
//

@implementation GTLAdSenseSavedAdStyles
@dynamic ETag, items, kind, nextPageToken;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"ETag" : @"etag"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"items" : [GTLAdSenseSavedAdStyle class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"adsense#savedAdStyles"];
}

@end
