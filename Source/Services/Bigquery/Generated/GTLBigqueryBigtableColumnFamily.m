/* Copyright (c) 2016 Google Inc.
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
//  GTLBigqueryBigtableColumnFamily.m
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
//   GTLBigqueryBigtableColumnFamily (0 custom class methods, 5 custom properties)

#import "GTLBigqueryBigtableColumnFamily.h"

#import "GTLBigqueryBigtableColumn.h"

// ----------------------------------------------------------------------------
//
//   GTLBigqueryBigtableColumnFamily
//

@implementation GTLBigqueryBigtableColumnFamily
@dynamic columns, encoding, familyId, onlyReadLatest, type;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"columns" : [GTLBigqueryBigtableColumn class]
  };
  return map;
}

@end
