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
//  GTLAnalyticsWebproperty.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Analytics API (analytics/v3)
// Description:
//   View and manage your Google Analytics data
// Documentation:
//   https://developers.google.com/analytics/
// Classes:
//   GTLAnalyticsWebproperty (0 custom class methods, 16 custom properties)
//   GTLAnalyticsWebpropertyChildLink (0 custom class methods, 2 custom properties)
//   GTLAnalyticsWebpropertyParentLink (0 custom class methods, 2 custom properties)
//   GTLAnalyticsWebpropertyPermissions (0 custom class methods, 1 custom properties)

#import "GTLAnalyticsWebproperty.h"

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsWebproperty
//

@implementation GTLAnalyticsWebproperty
@dynamic accountId, childLink, created, defaultProfileId, identifier,
         industryVertical, internalWebPropertyId, kind, level, name, parentLink,
         permissions, profileCount, selfLink, updated, websiteUrl;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"identifier" : @"id"
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"analytics#webproperty"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsWebpropertyChildLink
//

@implementation GTLAnalyticsWebpropertyChildLink
@dynamic href, type;
@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsWebpropertyParentLink
//

@implementation GTLAnalyticsWebpropertyParentLink
@dynamic href, type;
@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsWebpropertyPermissions
//

@implementation GTLAnalyticsWebpropertyPermissions
@dynamic effective;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"effective" : [NSString class]
  };
  return map;
}

@end
