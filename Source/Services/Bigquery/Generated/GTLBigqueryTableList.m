/* Copyright (c) 2014 Google Inc.
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
//  GTLBigqueryTableList.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   BigQuery API (bigquery/v2)
// Description:
//   A data platform for customers to create, manage, share and query data.
// Documentation:
//   https://developers.google.com/bigquery/docs/overview
// Classes:
//   GTLBigqueryTableList (0 custom class methods, 5 custom properties)
//   GTLBigqueryTableListTablesItem (0 custom class methods, 5 custom properties)

#import "GTLBigqueryTableList.h"

#import "GTLBigqueryTableReference.h"

// ----------------------------------------------------------------------------
//
//   GTLBigqueryTableList
//

@implementation GTLBigqueryTableList
@dynamic ETag, kind, nextPageToken, tables, totalItems;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"etag"
                                forKey:@"ETag"];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLBigqueryTableListTablesItem class]
                                forKey:@"tables"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"bigquery#tableList"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBigqueryTableListTablesItem
//

@implementation GTLBigqueryTableListTablesItem
@dynamic friendlyName, identifier, kind, tableReference, type;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

// +load method not generated as another class also claims kind 'bigquery#table'.

@end
