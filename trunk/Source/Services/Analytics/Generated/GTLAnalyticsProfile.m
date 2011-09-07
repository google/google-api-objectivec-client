/* Copyright (c) 2011 Google Inc.
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
//  GTLAnalyticsProfile.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Analytics API (analytics/v3)
// Description:
//   View and manage your Google Analytics data
// Documentation:
//   http://code.google.com/apis/analytics
// Classes:
//   GTLAnalyticsProfile (0 custom class methods, 17 custom properties)
//   GTLAnalyticsProfileChildLink (0 custom class methods, 2 custom properties)
//   GTLAnalyticsProfileParentLink (0 custom class methods, 2 custom properties)

#import "GTLAnalyticsProfile.h"

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsProfile
//

@implementation GTLAnalyticsProfile
@dynamic accountId, childLink, created, currency, defaultPage,
         excludeQueryParameters, identifier, internalWebPropertyId, kind, name,
         parentLink, selfLink, siteSearchCategoryParameters,
         siteSearchQueryParameters, timezone, updated, webPropertyId;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"analytics#profile"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsProfileChildLink
//

@implementation GTLAnalyticsProfileChildLink
@dynamic href, type;
@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsProfileParentLink
//

@implementation GTLAnalyticsProfileParentLink
@dynamic href, type;
@end
