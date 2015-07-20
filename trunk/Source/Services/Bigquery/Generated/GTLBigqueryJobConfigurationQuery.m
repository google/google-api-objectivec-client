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
//  GTLBigqueryJobConfigurationQuery.m
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
//   GTLBigqueryJobConfigurationQuery (0 custom class methods, 12 custom properties)
//   GTLBigqueryJobConfigurationQueryTableDefinitions (0 custom class methods, 0 custom properties)

#import "GTLBigqueryJobConfigurationQuery.h"

#import "GTLBigqueryDatasetReference.h"
#import "GTLBigqueryExternalDataConfiguration.h"
#import "GTLBigqueryTableReference.h"
#import "GTLBigqueryUserDefinedFunctionResource.h"

// ----------------------------------------------------------------------------
//
//   GTLBigqueryJobConfigurationQuery
//

@implementation GTLBigqueryJobConfigurationQuery
@dynamic allowLargeResults, createDisposition, defaultDataset, destinationTable,
         flattenResults, preserveNulls, priority, query, tableDefinitions,
         useQueryCache, userDefinedFunctionResources, writeDisposition;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"userDefinedFunctionResources" : [GTLBigqueryUserDefinedFunctionResource class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBigqueryJobConfigurationQueryTableDefinitions
//

@implementation GTLBigqueryJobConfigurationQueryTableDefinitions

+ (Class)classForAdditionalProperties {
  return [GTLBigqueryExternalDataConfiguration class];
}

@end
