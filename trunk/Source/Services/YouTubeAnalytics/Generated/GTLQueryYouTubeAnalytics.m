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
//  GTLQueryYouTubeAnalytics.m
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
//   GTLQueryYouTubeAnalytics (3 custom class methods, 12 custom properties)

#import "GTLQueryYouTubeAnalytics.h"

#import "GTLYouTubeAnalyticsBatchReportDefinitionList.h"
#import "GTLYouTubeAnalyticsBatchReportList.h"
#import "GTLYouTubeAnalyticsResultTable.h"

@implementation GTLQueryYouTubeAnalytics

@dynamic batchReportDefinitionId, dimensions, endDate, fields, filters, ids,
         maxResults, metrics, onBehalfOfContentOwner, sort, startDate,
         startIndex;

+ (NSDictionary *)parameterNameMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"end-date", @"endDate",
      @"max-results", @"maxResults",
      @"start-date", @"startDate",
      @"start-index", @"startIndex",
      nil];
  return map;
}

#pragma mark -
#pragma mark "batchReportDefinitions" methods
// These create a GTLQueryYouTubeAnalytics object.

+ (id)queryForBatchReportDefinitionsListWithOnBehalfOfContentOwner:(NSString *)onBehalfOfContentOwner {
  NSString *methodName = @"youtubeAnalytics.batchReportDefinitions.list";
  GTLQueryYouTubeAnalytics *query = [self queryWithMethodName:methodName];
  query.onBehalfOfContentOwner = onBehalfOfContentOwner;
  query.expectedObjectClass = [GTLYouTubeAnalyticsBatchReportDefinitionList class];
  return query;
}

#pragma mark -
#pragma mark "batchReports" methods
// These create a GTLQueryYouTubeAnalytics object.

+ (id)queryForBatchReportsListWithBatchReportDefinitionId:(NSString *)batchReportDefinitionId
                                   onBehalfOfContentOwner:(NSString *)onBehalfOfContentOwner {
  NSString *methodName = @"youtubeAnalytics.batchReports.list";
  GTLQueryYouTubeAnalytics *query = [self queryWithMethodName:methodName];
  query.batchReportDefinitionId = batchReportDefinitionId;
  query.onBehalfOfContentOwner = onBehalfOfContentOwner;
  query.expectedObjectClass = [GTLYouTubeAnalyticsBatchReportList class];
  return query;
}

#pragma mark -
#pragma mark "reports" methods
// These create a GTLQueryYouTubeAnalytics object.

+ (id)queryForReportsQueryWithIds:(NSString *)ids
                        startDate:(NSString *)startDate
                          endDate:(NSString *)endDate
                          metrics:(NSString *)metrics {
  NSString *methodName = @"youtubeAnalytics.reports.query";
  GTLQueryYouTubeAnalytics *query = [self queryWithMethodName:methodName];
  query.ids = ids;
  query.startDate = startDate;
  query.endDate = endDate;
  query.metrics = metrics;
  query.expectedObjectClass = [GTLYouTubeAnalyticsResultTable class];
  return query;
}

@end
