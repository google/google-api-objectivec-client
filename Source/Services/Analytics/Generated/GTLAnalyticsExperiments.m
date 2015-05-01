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
//  GTLAnalyticsExperiments.m
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
//   GTLAnalyticsExperiments (0 custom class methods, 8 custom properties)

#import "GTLAnalyticsExperiments.h"

#import "GTLAnalyticsExperiment.h"

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsExperiments
//

@implementation GTLAnalyticsExperiments
@dynamic items, itemsPerPage, kind, nextLink, previousLink, startIndex,
         totalResults, username;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"items" : [GTLAnalyticsExperiment class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"analytics#experiments"];
}

@end
