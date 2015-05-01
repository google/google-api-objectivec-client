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
//  GTLBigqueryJobConfiguration.m
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
//   GTLBigqueryJobConfiguration (0 custom class methods, 6 custom properties)

#import "GTLBigqueryJobConfiguration.h"

#import "GTLBigqueryJobConfigurationExtract.h"
#import "GTLBigqueryJobConfigurationLink.h"
#import "GTLBigqueryJobConfigurationLoad.h"
#import "GTLBigqueryJobConfigurationQuery.h"
#import "GTLBigqueryJobConfigurationTableCopy.h"

// ----------------------------------------------------------------------------
//
//   GTLBigqueryJobConfiguration
//

@implementation GTLBigqueryJobConfiguration
@dynamic copyProperty, dryRun, extract, link, load, query;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"copyProperty" : @"copy"
  };
  return map;
}

@end
