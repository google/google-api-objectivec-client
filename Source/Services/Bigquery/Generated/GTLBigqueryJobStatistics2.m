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
//  GTLBigqueryJobStatistics2.m
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
//   GTLBigqueryJobStatistics2 (0 custom class methods, 7 custom properties)

#import "GTLBigqueryJobStatistics2.h"

#import "GTLBigqueryExplainQueryStage.h"
#import "GTLBigqueryTableReference.h"
#import "GTLBigqueryTableSchema.h"

// ----------------------------------------------------------------------------
//
//   GTLBigqueryJobStatistics2
//

@implementation GTLBigqueryJobStatistics2
@dynamic billingTier, cacheHit, queryPlan, referencedTables, schema,
         totalBytesBilled, totalBytesProcessed;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"queryPlan" : [GTLBigqueryExplainQueryStage class],
    @"referencedTables" : [GTLBigqueryTableReference class]
  };
  return map;
}

@end
