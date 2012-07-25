/* Copyright (c) 2012 Google Inc.
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
//   GTLQueryAnalytics (7 custom class methods, 14 custom properties)

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
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (copy) NSString *accountId;
@property (copy) NSString *dimensions;
@property (copy) NSString *endDate;
@property (copy) NSString *filters;
@property (copy) NSString *ids;
@property (assign) NSInteger maxResults;
@property (copy) NSString *metrics;
@property (copy) NSString *profileId;
@property (copy) NSString *segment;
@property (copy) NSString *sort;
@property (copy) NSString *startDate;
@property (assign) NSInteger startIndex;
@property (copy) NSString *webPropertyId;

#pragma mark -
#pragma mark "data.ga" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.data.ga.get
// Returns Analytics data for a profile.
//  Required:
//   ids: Unique table ID for retrieving Analytics data. Table ID is of the form
//     ga:XXXX, where XXXX is the Analytics profile ID.
//   startDate: Start date for fetching Analytics data. All requests should
//     specify a start date formatted as YYYY-MM-DD.
//   endDate: End date for fetching Analytics data. All requests should specify
//     an end date formatted as YYYY-MM-DD.
//   metrics: A comma-separated list of Analytics metrics. E.g.,
//     'ga:visits,ga:pageviews'. At least one metric must be specified.
//  Optional:
//   dimensions: A comma-separated list of Analytics dimensions. E.g.,
//     'ga:browser,ga:city'.
//   filters: A comma-separated list of dimension or metric filters to be
//     applied to Analytics data.
//   maxResults: The maximum number of entries to include in this feed.
//   segment: An Analytics advanced segment to be applied to data.
//   sort: A comma-separated list of dimensions or metrics that determine the
//     sort order for Analytics data.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsGaData.
+ (id)queryForDataGaGetWithIds:(NSString *)ids
                     startDate:(NSString *)startDate
                       endDate:(NSString *)endDate
                       metrics:(NSString *)metrics;

#pragma mark -
#pragma mark "data.mcf" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.data.mcf.get
// Returns Analytics Multi-Channel Funnels data for a profile.
//  Required:
//   ids: Unique table ID for retrieving Analytics data. Table ID is of the form
//     ga:XXXX, where XXXX is the Analytics profile ID.
//   startDate: Start date for fetching Analytics data. All requests should
//     specify a start date formatted as YYYY-MM-DD.
//   endDate: End date for fetching Analytics data. All requests should specify
//     an end date formatted as YYYY-MM-DD.
//   metrics: A comma-separated list of Multi-Channel Funnels metrics. E.g.,
//     'mcf:totalConversions,mcf:totalConversionValue'. At least one metric must
//     be specified.
//  Optional:
//   dimensions: A comma-separated list of Multi-Channel Funnels dimensions.
//     E.g., 'mcf:source,mcf:medium'.
//   filters: A comma-separated list of dimension or metric filters to be
//     applied to the Analytics data.
//   maxResults: The maximum number of entries to include in this feed.
//   sort: A comma-separated list of dimensions or metrics that determine the
//     sort order for the Analytics data.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsMcfData.
+ (id)queryForDataMcfGetWithIds:(NSString *)ids
                      startDate:(NSString *)startDate
                        endDate:(NSString *)endDate
                        metrics:(NSString *)metrics;

#pragma mark -
#pragma mark "management.accounts" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.accounts.list
// Lists all accounts to which the user has access.
//  Optional:
//   maxResults: The maximum number of accounts to include in this response.
//   startIndex: An index of the first account to retrieve. Use this parameter
//     as a pagination mechanism along with the max-results parameter.
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
//   accountId: Account ID to retrieve goals for. Can either be a specific
//     account ID or '~all', which refers to all the accounts that user has
//     access to.
//   webPropertyId: Web property ID to retrieve goals for. Can either be a
//     specific web property ID or '~all', which refers to all the web
//     properties that user has access to.
//   profileId: Profile ID to retrieve goals for. Can either be a specific
//     profile ID or '~all', which refers to all the profiles that user has
//     access to.
//  Optional:
//   maxResults: The maximum number of goals to include in this response.
//   startIndex: An index of the first goal to retrieve. Use this parameter as a
//     pagination mechanism along with the max-results parameter.
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
//   accountId: Account ID for the profiles to retrieve. Can either be a
//     specific account ID or '~all', which refers to all the accounts to which
//     the user has access.
//   webPropertyId: Web property ID for the profiles to retrieve. Can either be
//     a specific web property ID or '~all', which refers to all the web
//     properties to which the user has access.
//  Optional:
//   maxResults: The maximum number of profiles to include in this response.
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
//   maxResults: The maximum number of advanced segments to include in this
//     response.
//   startIndex: An index of the first advanced segment to retrieve. Use this
//     parameter as a pagination mechanism along with the max-results parameter.
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
//   accountId: Account ID to retrieve web properties for. Can either be a
//     specific account ID or '~all', which refers to all the accounts that user
//     has access to.
//  Optional:
//   maxResults: The maximum number of web properties to include in this
//     response.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsWebproperties.
+ (id)queryForManagementWebpropertiesListWithAccountId:(NSString *)accountId;

@end
