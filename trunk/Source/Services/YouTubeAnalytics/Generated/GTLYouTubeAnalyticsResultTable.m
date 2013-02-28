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
//  GTLYouTubeAnalyticsResultTable.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   YouTube Analytics API (youtubeAnalytics/v1)
// Description:
//   Retrieve your YouTube Analytics reports.
// Documentation:
//   http://developers.google.com/youtube/analytics/
// Classes:
//   GTLYouTubeAnalyticsResultTable (0 custom class methods, 3 custom properties)
//   GTLYouTubeAnalyticsResultTableColumnHeadersItem (0 custom class methods, 3 custom properties)

#import "GTLYouTubeAnalyticsResultTable.h"

// ----------------------------------------------------------------------------
//
//   GTLYouTubeAnalyticsResultTable
//

@implementation GTLYouTubeAnalyticsResultTable
@dynamic columnHeaders, kind, rows;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLYouTubeAnalyticsResultTableColumnHeadersItem class], @"columnHeaders",
      [NSObject class], @"rows",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"youtubeAnalytics#resultTable"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeAnalyticsResultTableColumnHeadersItem
//

@implementation GTLYouTubeAnalyticsResultTableColumnHeadersItem
@dynamic columnType, dataType, name;
@end
