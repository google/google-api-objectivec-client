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
//  GTLQueryYouTubeAnalytics.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@interface GTLQueryYouTubeAnalytics : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (copy) NSString *batchReportDefinitionId;
@property (copy) NSString *dimensions;
@property (copy) NSString *endDate;
@property (copy) NSString *filters;
@property (copy) NSString *ids;
@property (assign) NSInteger maxResults;
@property (copy) NSString *metrics;
@property (copy) NSString *onBehalfOfContentOwner;
@property (copy) NSString *sort;
@property (copy) NSString *startDate;
@property (assign) NSInteger startIndex;

#pragma mark -
#pragma mark "batchReportDefinitions" methods
// These create a GTLQueryYouTubeAnalytics object.

// Method: youtubeAnalytics.batchReportDefinitions.list
// Retrieves a list of available batch report definitions.
//  Required:
//   onBehalfOfContentOwner: The onBehalfOfContentOwner parameter identifies the
//     content owner that the user is acting on behalf of.
//  Authorization scope(s):
//   kGTLAuthScopeYouTubeAnalyticsYtAnalyticsMonetaryReadonly
//   kGTLAuthScopeYouTubeAnalyticsYtAnalyticsReadonly
// Fetches a GTLYouTubeAnalyticsBatchReportDefinitionList.
+ (id)queryForBatchReportDefinitionsListWithOnBehalfOfContentOwner:(NSString *)onBehalfOfContentOwner;

#pragma mark -
#pragma mark "batchReports" methods
// These create a GTLQueryYouTubeAnalytics object.

// Method: youtubeAnalytics.batchReports.list
// Retrieves a list of processed batch reports.
//  Required:
//   batchReportDefinitionId: The batchReportDefinitionId parameter specifies
//     the ID of the batch reportort definition for which you are retrieving
//     reports.
//   onBehalfOfContentOwner: The onBehalfOfContentOwner parameter identifies the
//     content owner that the user is acting on behalf of.
//  Authorization scope(s):
//   kGTLAuthScopeYouTubeAnalyticsYtAnalyticsMonetaryReadonly
//   kGTLAuthScopeYouTubeAnalyticsYtAnalyticsReadonly
// Fetches a GTLYouTubeAnalyticsBatchReportList.
+ (id)queryForBatchReportsListWithBatchReportDefinitionId:(NSString *)batchReportDefinitionId
                                   onBehalfOfContentOwner:(NSString *)onBehalfOfContentOwner;

#pragma mark -
#pragma mark "reports" methods
// These create a GTLQueryYouTubeAnalytics object.

// Method: youtubeAnalytics.reports.query
// Retrieve your YouTube Analytics reports.
//  Required:
//   ids: Identifies the YouTube channel or content owner for which you are
//     retrieving YouTube Analytics data.
//     - To request data for a YouTube user, set the ids parameter value to
//     channel==CHANNEL_ID, where CHANNEL_ID specifies the unique YouTube
//     channel ID.
//     - To request data for a YouTube CMS content owner, set the ids parameter
//     value to contentOwner==OWNER_NAME, where OWNER_NAME is the CMS name of
//     the content owner.
//   startDate: The start date for fetching YouTube Analytics data. The value
//     should be in YYYY-MM-DD format.
//   endDate: The end date for fetching YouTube Analytics data. The value should
//     be in YYYY-MM-DD format.
//   metrics: A comma-separated list of YouTube Analytics metrics, such as views
//     or likes,dislikes. See the Available Reports document for a list of the
//     reports that you can retrieve and the metrics available in each report,
//     and see the Metrics document for definitions of those metrics.
//  Optional:
//   dimensions: A comma-separated list of YouTube Analytics dimensions, such as
//     views or ageGroup,gender. See the Available Reports document for a list
//     of the reports that you can retrieve and the dimensions used for those
//     reports. Also see the Dimensions document for definitions of those
//     dimensions.
//   filters: A list of filters that should be applied when retrieving YouTube
//     Analytics data. The Available Reports document identifies the dimensions
//     that can be used to filter each report, and the Dimensions document
//     defines those dimensions. If a request uses multiple filters, join them
//     together with a semicolon (;), and the returned result table will satisfy
//     both filters. For example, a filters parameter value of
//     video==dMH0bHeiRNg;country==IT restricts the result set to include data
//     for the given video in Italy.
//   maxResults: The maximum number of rows to include in the response.
//   sort: A comma-separated list of dimensions or metrics that determine the
//     sort order for YouTube Analytics data. By default the sort order is
//     ascending. The '-' prefix causes descending sort order.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter (one-based,
//     inclusive).
//  Authorization scope(s):
//   kGTLAuthScopeYouTubeAnalyticsYtAnalyticsMonetaryReadonly
//   kGTLAuthScopeYouTubeAnalyticsYtAnalyticsReadonly
// Fetches a GTLYouTubeAnalyticsResultTable.
+ (id)queryForReportsQueryWithIds:(NSString *)ids
                        startDate:(NSString *)startDate
                          endDate:(NSString *)endDate
                          metrics:(NSString *)metrics;

@end
