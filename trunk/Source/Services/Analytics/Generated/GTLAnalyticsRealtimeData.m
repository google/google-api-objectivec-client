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
//  GTLAnalyticsRealtimeData.m
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
//   GTLAnalyticsRealtimeData (0 custom class methods, 9 custom properties)
//   GTLAnalyticsRealtimeDataColumnHeadersItem (0 custom class methods, 3 custom properties)
//   GTLAnalyticsRealtimeDataProfileInfo (0 custom class methods, 6 custom properties)
//   GTLAnalyticsRealtimeDataQuery (0 custom class methods, 6 custom properties)
//   GTLAnalyticsRealtimeDataTotalsForAllResults (0 custom class methods, 0 custom properties)

#import "GTLAnalyticsRealtimeData.h"

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsRealtimeData
//

@implementation GTLAnalyticsRealtimeData
@dynamic columnHeaders, identifier, kind, profileInfo, query, rows, selfLink,
         totalResults, totalsForAllResults;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLAnalyticsRealtimeDataColumnHeadersItem class], @"columnHeaders",
      [NSString class], @"rows",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"analytics#realtimeData"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsRealtimeDataColumnHeadersItem
//

@implementation GTLAnalyticsRealtimeDataColumnHeadersItem
@dynamic columnType, dataType, name;
@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsRealtimeDataProfileInfo
//

@implementation GTLAnalyticsRealtimeDataProfileInfo
@dynamic accountId, internalWebPropertyId, profileId, profileName, tableId,
         webPropertyId;
@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsRealtimeDataQuery
//

@implementation GTLAnalyticsRealtimeDataQuery
@dynamic dimensions, filters, ids, maxResults, metrics, sort;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"max-results"
                                forKey:@"maxResults"];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [NSString class], @"metrics",
      [NSString class], @"sort",
      nil];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsRealtimeDataTotalsForAllResults
//

@implementation GTLAnalyticsRealtimeDataTotalsForAllResults

+ (Class)classForAdditionalProperties {
  return [NSString class];
}

@end
