/* Copyright (c) 2011 Google Inc.
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
//  GTLQueryAnalytics.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Analytics API (analytics/v3)
// Description:
//   View and manage your Google Analytics data
// Documentation:
//   http://code.google.com/apis/analytics
// Classes:
//   GTLQueryAnalytics (6 custom class methods, 14 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@interface GTLQueryAnalytics : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (retain) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (retain) NSString *accountId;
@property (retain) NSString *dimensions;
@property (retain) NSString *endDate;
@property (retain) NSString *filters;
@property (retain) NSString *ids;
@property (retain) id maxResults;
@property (retain) NSString *metrics;
@property (retain) NSString *profileId;
@property (retain) NSString *segment;
@property (retain) NSString *sort;
@property (retain) NSString *startDate;
@property (assign) NSInteger startIndex;
@property (retain) NSString *webPropertyId;

#pragma mark -
#pragma mark "management.accounts" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.accounts.list
// Lists all accounts to which the user has access.
//  Optional:
//   maxResults: The maximum number of entries to include in this response.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsAccounts.
+ (id)queryForManagementAccountsList;

#pragma mark -
#pragma mark "management.goals" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.goals.list
// Lists goals to which the user has access.
//  Required:
//   accountId: Account ID for the web properties to retrieve. Can either be a
//     specific account ID or '~all', which refers to all the accounts to which
//     the user has access.
//   webPropertyId: Web property ID for the web properties to retrieve. Can
//     either be a specific web property ID or '~all', which refers to all the
//     web properties to which the user has access.
//   profileId: Profile ID for the web properties to retrieve. Can either be a
//     specific profile ID or '~all', which refers to all the profiles to which
//     the user has access.
//  Optional:
//   maxResults: The maximum number of entries to include in this response.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsGoals.
+ (id)queryForManagementGoalsListWithAccountId:(NSString *)accountId
                                 webPropertyId:(NSString *)webPropertyId
                                     profileId:(NSString *)profileId;

#pragma mark -
#pragma mark "management.profiles" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.profiles.list
// Lists profiles to which the user has access.
//  Required:
//   accountId: Account ID for the web properties to retrieve. Can either be a
//     specific account ID or '~all', which refers to all the accounts to which
//     the user has access.
//   webPropertyId: Web property ID for the web properties to retrieve. Can
//     either be a specific web property ID or '~all', which refers to all the
//     web properties to which the user has access.
//  Optional:
//   maxResults: The maximum number of entries to include in this response.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsProfiles.
+ (id)queryForManagementProfilesListWithAccountId:(NSString *)accountId
                                    webPropertyId:(NSString *)webPropertyId;

#pragma mark -
#pragma mark "management.segments" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.segments.list
// Lists advanced segments to which the user has access.
//  Optional:
//   maxResults: The maximum number of entries to include in this response.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsSegments.
+ (id)queryForManagementSegmentsList;

#pragma mark -
#pragma mark "management.webproperties" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.webproperties.list
// Lists web properties to which the user has access.
//  Required:
//   accountId: Account ID for the web properties to retrieve. Can either be a
//     specific account ID or '~all', which refers to all the accounts to which
//     user has access.
//  Optional:
//   maxResults: The maximum number of entries to include in this response.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsWebproperties.
+ (id)queryForManagementWebpropertiesListWithAccountId:(NSString *)accountId;

#pragma mark -
#pragma mark "report" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.report.get
// Returns Analytics report data for a profile.
//  Required:
//   endDate: End date for fetching report data. All requests should specify an
//     end date formatted as YYYY-MM-DD.
//   startDate: Start date for fetching report data. All requests should specify
//     a start date formatted as YYYY-MM-DD.
//   metrics: A comma-separated list of Analytics metrics. E.g.,
//     'ga:visits,ga:pageviews'. At least one metric must be specified to
//     retrieve a valid Analytics report.
//   ids: Unique table ID for retrieving report data. Table ID is of the form
//     ga:XXXX, where XXXX is the Analytics profile ID.
//  Optional:
//   dimensions: A comma-separated list of Analytics dimensions. E.g.,
//     'ga:browser,ga:city'.
//   filters: A comma-separated list of dimension or metric filters to be
//     applied to the report data.
//   maxResults: The maximum number of entries to include in this feed.
//   segment: An Analytics advanced segment to be applied to the report data.
//   sort: A comma-separated list of dimensions or metrics that determine the
//     sort order for the report data.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsGaReport.
+ (id)queryForReportGetWithEndDate:(NSString *)endDate
                         startDate:(NSString *)startDate
                           metrics:(NSString *)metrics
                               ids:(NSString *)ids;

@end
