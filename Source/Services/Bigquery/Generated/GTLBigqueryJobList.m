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
//  GTLBigqueryJobList.m
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
//   GTLBigqueryJobList (0 custom class methods, 5 custom properties)
//   GTLBigqueryJobListJobsItem (0 custom class methods, 9 custom properties)

#import "GTLBigqueryJobList.h"

#import "GTLBigqueryErrorProto.h"
#import "GTLBigqueryJobConfiguration.h"
#import "GTLBigqueryJobReference.h"
#import "GTLBigqueryJobStatistics.h"
#import "GTLBigqueryJobStatus.h"

// ----------------------------------------------------------------------------
//
//   GTLBigqueryJobList
//

@implementation GTLBigqueryJobList
@dynamic ETag, jobs, kind, nextPageToken, totalItems;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"etag"
                                forKey:@"ETag"];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLBigqueryJobListJobsItem class]
                                forKey:@"jobs"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"bigquery#jobList"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBigqueryJobListJobsItem
//

@implementation GTLBigqueryJobListJobsItem
@dynamic configuration, errorResult, identifier, jobReference, kind, state,
         statistics, status, userEmail;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"id", @"identifier",
      @"user_email", @"userEmail",
      nil];
  return map;
}

// +load method not generated as another class also claims kind 'bigquery#job'.

@end
