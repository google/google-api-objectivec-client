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
//  GTLAnalyticsGaReport.m
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
//   GTLAnalyticsGaReport (0 custom class methods, 13 custom properties)
//   GTLAnalyticsGaReportColumnHeadersItem (0 custom class methods, 3 custom properties)
//   GTLAnalyticsGaReportProfileInfo (0 custom class methods, 5 custom properties)
//   GTLAnalyticsGaReportQuery (0 custom class methods, 10 custom properties)
//   GTLAnalyticsGaReportTotalsForAllResults (0 custom class methods, 0 custom properties)

#import "GTLAnalyticsGaReport.h"

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaReport
//

@implementation GTLAnalyticsGaReport
@dynamic columnHeaders, containsSampledData, identifier, itemsPerPage, kind,
         nextLink, previousLink, profileInfo, query, rows, selfLink,
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
      [GTLAnalyticsGaReportColumnHeadersItem class], @"columnHeaders",
      [NSString class], @"rows",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"analytics#gaReport"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaReportColumnHeadersItem
//

@implementation GTLAnalyticsGaReportColumnHeadersItem
@dynamic columnType, dataType, name;
@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaReportProfileInfo
//

@implementation GTLAnalyticsGaReportProfileInfo
@dynamic accountId, profileId, profileName, tableId, webPropertyId;
@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaReportQuery
//

@implementation GTLAnalyticsGaReportQuery
@dynamic dimensions, endDate, filters, ids, maxResults, metrics, segment, sort,
         startDate, startIndex;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"end-date", @"endDate",
      @"max-results", @"maxResults",
      @"start-date", @"startDate",
      @"start-index", @"startIndex",
      nil];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [NSString class], @"dimensions",
      [NSString class], @"metrics",
      [NSString class], @"sort",
      nil];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaReportTotalsForAllResults
//

@implementation GTLAnalyticsGaReportTotalsForAllResults
@end
