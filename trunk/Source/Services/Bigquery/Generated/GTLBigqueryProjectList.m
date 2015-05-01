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
//  GTLBigqueryProjectList.m
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
//   GTLBigqueryProjectList (0 custom class methods, 5 custom properties)
//   GTLBigqueryProjectListProjectsItem (0 custom class methods, 5 custom properties)

#import "GTLBigqueryProjectList.h"

#import "GTLBigqueryProjectReference.h"

// ----------------------------------------------------------------------------
//
//   GTLBigqueryProjectList
//

@implementation GTLBigqueryProjectList
@dynamic ETag, kind, nextPageToken, projects, totalItems;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"ETag" : @"etag"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"projects" : [GTLBigqueryProjectListProjectsItem class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"bigquery#projectList"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBigqueryProjectListProjectsItem
//

@implementation GTLBigqueryProjectListProjectsItem
@dynamic friendlyName, identifier, kind, numericId, projectReference;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"identifier" : @"id"
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"bigquery#project"];
}

@end
