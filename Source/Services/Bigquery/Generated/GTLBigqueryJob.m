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
//  GTLBigqueryJob.m
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
//   GTLBigqueryJob (0 custom class methods, 9 custom properties)

#import "GTLBigqueryJob.h"

#import "GTLBigqueryJobConfiguration.h"
#import "GTLBigqueryJobReference.h"
#import "GTLBigqueryJobStatistics.h"
#import "GTLBigqueryJobStatus.h"

// ----------------------------------------------------------------------------
//
//   GTLBigqueryJob
//

@implementation GTLBigqueryJob
@dynamic configuration, ETag, identifier, jobReference, kind, selfLink,
         statistics, status, userEmail;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"ETag" : @"etag",
    @"identifier" : @"id",
    @"userEmail" : @"user_email"
  };
  return map;
}

// +load method not generated as another class also claims kind 'bigquery#job'.

@end
