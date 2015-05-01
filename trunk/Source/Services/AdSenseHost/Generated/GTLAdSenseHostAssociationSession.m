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
//  GTLAdSenseHostAssociationSession.m
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
//   GTLAdSenseHostAssociationSession (0 custom class methods, 9 custom properties)

#import "GTLAdSenseHostAssociationSession.h"

// ----------------------------------------------------------------------------
//
//   GTLAdSenseHostAssociationSession
//

@implementation GTLAdSenseHostAssociationSession
@dynamic accountId, identifier, kind, productCodes, redirectUrl, status,
         userLocale, websiteLocale, websiteUrl;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"identifier" : @"id"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"productCodes" : [NSString class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"adsensehost#associationSession"];
}

@end
