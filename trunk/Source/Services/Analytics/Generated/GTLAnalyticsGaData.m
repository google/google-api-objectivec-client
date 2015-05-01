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
//  GTLAnalyticsGaData.m
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
//   GTLAnalyticsGaData (0 custom class methods, 16 custom properties)
//   GTLAnalyticsGaDataColumnHeadersItem (0 custom class methods, 3 custom properties)
//   GTLAnalyticsGaDataDataTable (0 custom class methods, 2 custom properties)
//   GTLAnalyticsGaDataProfileInfo (0 custom class methods, 6 custom properties)
//   GTLAnalyticsGaDataQuery (0 custom class methods, 11 custom properties)
//   GTLAnalyticsGaDataTotalsForAllResults (0 custom class methods, 0 custom properties)
//   GTLAnalyticsGaDataDataTableColsItem (0 custom class methods, 3 custom properties)
//   GTLAnalyticsGaDataDataTableRowsItem (0 custom class methods, 1 custom properties)
//   GTLAnalyticsGaDataDataTableRowsItemCItem (0 custom class methods, 1 custom properties)

#import "GTLAnalyticsGaData.h"

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaData
//

@implementation GTLAnalyticsGaData
@dynamic columnHeaders, containsSampledData, dataTable, identifier,
         itemsPerPage, kind, nextLink, previousLink, profileInfo, query, rows,
         sampleSize, sampleSpace, selfLink, totalResults, totalsForAllResults;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"identifier" : @"id"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"columnHeaders" : [GTLAnalyticsGaDataColumnHeadersItem class],
    @"rows" : [NSString class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"analytics#gaData"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaDataColumnHeadersItem
//

@implementation GTLAnalyticsGaDataColumnHeadersItem
@dynamic columnType, dataType, name;
@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaDataDataTable
//

@implementation GTLAnalyticsGaDataDataTable
@dynamic cols, rows;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"cols" : [GTLAnalyticsGaDataDataTableColsItem class],
    @"rows" : [GTLAnalyticsGaDataDataTableRowsItem class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaDataProfileInfo
//

@implementation GTLAnalyticsGaDataProfileInfo
@dynamic accountId, internalWebPropertyId, profileId, profileName, tableId,
         webPropertyId;
@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaDataQuery
//

@implementation GTLAnalyticsGaDataQuery
@dynamic dimensions, endDate, filters, ids, maxResults, metrics, samplingLevel,
         segment, sort, startDate, startIndex;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"endDate" : @"end-date",
    @"maxResults" : @"max-results",
    @"startDate" : @"start-date",
    @"startIndex" : @"start-index"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"metrics" : [NSString class],
    @"sort" : [NSString class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaDataTotalsForAllResults
//

@implementation GTLAnalyticsGaDataTotalsForAllResults

+ (Class)classForAdditionalProperties {
  return [NSString class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaDataDataTableColsItem
//

@implementation GTLAnalyticsGaDataDataTableColsItem
@dynamic identifier, label, type;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"identifier" : @"id"
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaDataDataTableRowsItem
//

@implementation GTLAnalyticsGaDataDataTableRowsItem
@dynamic c;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"c" : [GTLAnalyticsGaDataDataTableRowsItemCItem class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaDataDataTableRowsItemCItem
//

@implementation GTLAnalyticsGaDataDataTableRowsItemCItem
@dynamic v;
@end
