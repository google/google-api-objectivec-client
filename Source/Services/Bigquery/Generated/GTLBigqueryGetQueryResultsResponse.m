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
//  GTLBigqueryGetQueryResultsResponse.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   BigQuery API (bigquery/v2)
// Description:
//   A data platform for customers to create, manage, share and query data.
// Documentation:
//   https://cloud.google.com/bigquery/
// Classes:
//   GTLBigqueryGetQueryResultsResponse (0 custom class methods, 10 custom properties)

#import "GTLBigqueryGetQueryResultsResponse.h"

#import "GTLBigqueryJobReference.h"
#import "GTLBigqueryTableRow.h"
#import "GTLBigqueryTableSchema.h"

// ----------------------------------------------------------------------------
//
//   GTLBigqueryGetQueryResultsResponse
//

@implementation GTLBigqueryGetQueryResultsResponse
@dynamic cacheHit, ETag, jobComplete, jobReference, kind, pageToken, rows,
         schema, totalBytesProcessed, totalRows;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"ETag" : @"etag"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"rows" : [GTLBigqueryTableRow class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"bigquery#getQueryResultsResponse"];
}

@end
