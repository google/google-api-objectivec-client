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
//  GTLQueryAnalytics.h
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
//   GTLQueryAnalytics (78 custom class methods, 29 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLAnalyticsAccountTicket;
@class GTLAnalyticsCustomDimension;
@class GTLAnalyticsCustomMetric;
@class GTLAnalyticsEntityAdWordsLink;
@class GTLAnalyticsEntityUserLink;
@class GTLAnalyticsExperiment;
@class GTLAnalyticsFilter;
@class GTLAnalyticsGoal;
@class GTLAnalyticsProfile;
@class GTLAnalyticsProfileFilterLink;
@class GTLAnalyticsUnsampledReport;
@class GTLAnalyticsWebproperty;

@interface GTLQueryAnalytics : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (nonatomic, copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (nonatomic, copy) NSString *accountId;
@property (nonatomic, retain) NSArray *customDataImportUids;  // of NSString
@property (nonatomic, copy) NSString *customDataSourceId;
@property (nonatomic, copy) NSString *customDimensionId;
@property (nonatomic, copy) NSString *customMetricId;
@property (nonatomic, copy) NSString *dimensions;
@property (nonatomic, copy) NSString *endDate;
@property (nonatomic, copy) NSString *experimentId;
@property (nonatomic, copy) NSString *filterId;
@property (nonatomic, copy) NSString *filters;
@property (nonatomic, copy) NSString *goalId;
@property (nonatomic, copy) NSString *ids;
@property (nonatomic, assign) BOOL ignoreCustomDataSourceLinks;
@property (nonatomic, copy) NSString *linkId;
@property (nonatomic, assign) NSInteger maxResults;
@property (nonatomic, copy) NSString *metrics;
@property (nonatomic, copy) NSString *output;
@property (nonatomic, copy) NSString *profileId;
@property (nonatomic, copy) NSString *reportType;
@property (nonatomic, copy) NSString *samplingLevel;
@property (nonatomic, copy) NSString *segment;
@property (nonatomic, copy) NSString *sort;
@property (nonatomic, copy) NSString *startDate;
@property (nonatomic, assign) NSInteger startIndex;
@property (nonatomic, copy) NSString *unsampledReportId;
@property (nonatomic, copy) NSString *uploadId;
@property (nonatomic, copy) NSString *webPropertyAdWordsLinkId;
@property (nonatomic, copy) NSString *webPropertyId;

#pragma mark - "data.ga" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.data.ga.get
// Returns Analytics data for a view (profile).
//  Required:
//   ids: Unique table ID for retrieving Analytics data. Table ID is of the form
//     ga:XXXX, where XXXX is the Analytics view (profile) ID.
//   startDate: Start date for fetching Analytics data. Requests can specify a
//     start date formatted as YYYY-MM-DD, or as a relative date (e.g., today,
//     yesterday, or 7daysAgo). The default value is 7daysAgo.
//   endDate: End date for fetching Analytics data. Request can should specify
//     an end date formatted as YYYY-MM-DD, or as a relative date (e.g., today,
//     yesterday, or 7daysAgo). The default value is yesterday.
//   metrics: A comma-separated list of Analytics metrics. E.g.,
//     'ga:sessions,ga:pageviews'. At least one metric must be specified.
//  Optional:
//   dimensions: A comma-separated list of Analytics dimensions. E.g.,
//     'ga:browser,ga:city'.
//   filters: A comma-separated list of dimension or metric filters to be
//     applied to Analytics data.
//   maxResults: The maximum number of entries to include in this feed.
//   output: The selected format for the response. Default format is JSON.
//      kGTLAnalyticsOutputDataTable: Returns the response in Google Charts Data
//        Table format. This is useful in creating visualization using Google
//        Charts.
//      kGTLAnalyticsOutputJson: Returns the response in standard JSON format.
//   samplingLevel: The desired sampling level.
//      kGTLAnalyticsSamplingLevelDefault: Returns response with a sample size
//        that balances speed and accuracy.
//      kGTLAnalyticsSamplingLevelFaster: Returns a fast response with a smaller
//        sample size.
//      kGTLAnalyticsSamplingLevelHigherPrecision: Returns a more accurate
//        response using a large sample size, but this may result in the
//        response being slower.
//   segment: An Analytics segment to be applied to data.
//   sort: A comma-separated list of dimensions or metrics that determine the
//     sort order for Analytics data.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsGaData.
+ (instancetype)queryForDataGaGetWithIds:(NSString *)ids
                               startDate:(NSString *)startDate
                                 endDate:(NSString *)endDate
                                 metrics:(NSString *)metrics;

#pragma mark - "data.mcf" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.data.mcf.get
// Returns Analytics Multi-Channel Funnels data for a view (profile).
//  Required:
//   ids: Unique table ID for retrieving Analytics data. Table ID is of the form
//     ga:XXXX, where XXXX is the Analytics view (profile) ID.
//   startDate: Start date for fetching Analytics data. Requests can specify a
//     start date formatted as YYYY-MM-DD, or as a relative date (e.g., today,
//     yesterday, or 7daysAgo). The default value is 7daysAgo.
//   endDate: End date for fetching Analytics data. Requests can specify a start
//     date formatted as YYYY-MM-DD, or as a relative date (e.g., today,
//     yesterday, or 7daysAgo). The default value is 7daysAgo.
//   metrics: A comma-separated list of Multi-Channel Funnels metrics. E.g.,
//     'mcf:totalConversions,mcf:totalConversionValue'. At least one metric must
//     be specified.
//  Optional:
//   dimensions: A comma-separated list of Multi-Channel Funnels dimensions.
//     E.g., 'mcf:source,mcf:medium'.
//   filters: A comma-separated list of dimension or metric filters to be
//     applied to the Analytics data.
//   maxResults: The maximum number of entries to include in this feed.
//   samplingLevel: The desired sampling level.
//      kGTLAnalyticsSamplingLevelDefault: Returns response with a sample size
//        that balances speed and accuracy.
//      kGTLAnalyticsSamplingLevelFaster: Returns a fast response with a smaller
//        sample size.
//      kGTLAnalyticsSamplingLevelHigherPrecision: Returns a more accurate
//        response using a large sample size, but this may result in the
//        response being slower.
//   sort: A comma-separated list of dimensions or metrics that determine the
//     sort order for the Analytics data.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsMcfData.
+ (instancetype)queryForDataMcfGetWithIds:(NSString *)ids
                                startDate:(NSString *)startDate
                                  endDate:(NSString *)endDate
                                  metrics:(NSString *)metrics;

#pragma mark - "data.realtime" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.data.realtime.get
// Returns real time data for a view (profile).
//  Required:
//   ids: Unique table ID for retrieving real time data. Table ID is of the form
//     ga:XXXX, where XXXX is the Analytics view (profile) ID.
//   metrics: A comma-separated list of real time metrics. E.g.,
//     'rt:activeUsers'. At least one metric must be specified.
//  Optional:
//   dimensions: A comma-separated list of real time dimensions. E.g.,
//     'rt:medium,rt:city'.
//   filters: A comma-separated list of dimension or metric filters to be
//     applied to real time data.
//   maxResults: The maximum number of entries to include in this feed.
//   sort: A comma-separated list of dimensions or metrics that determine the
//     sort order for real time data.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsRealtimeData.
+ (instancetype)queryForDataRealtimeGetWithIds:(NSString *)ids
                                       metrics:(NSString *)metrics;

#pragma mark - "management.accounts" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.accounts.list
// Lists all accounts to which the user has access.
//  Optional:
//   maxResults: The maximum number of accounts to include in this response.
//   startIndex: An index of the first account to retrieve. Use this parameter
//     as a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsAccounts.
+ (instancetype)queryForManagementAccountsList;

#pragma mark - "management.accountSummaries" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.accountSummaries.list
// Lists account summaries (lightweight tree comprised of
// accounts/properties/profiles) to which the user has access.
//  Optional:
//   maxResults: The maximum number of account summaries to include in this
//     response, where the largest acceptable value is 1000.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsAccountSummaries.
+ (instancetype)queryForManagementAccountSummariesList;

#pragma mark - "management.accountUserLinks" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.accountUserLinks.delete
// Removes a user from the given account.
//  Required:
//   accountId: Account ID to delete the user link for.
//   linkId: Link ID to delete the user link for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
+ (instancetype)queryForManagementAccountUserLinksDeleteWithAccountId:(NSString *)accountId
                                                               linkId:(NSString *)linkId;

// Method: analytics.management.accountUserLinks.insert
// Adds a new user to the given account.
//  Required:
//   accountId: Account ID to create the user link for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
// Fetches a GTLAnalyticsEntityUserLink.
+ (instancetype)queryForManagementAccountUserLinksInsertWithObject:(GTLAnalyticsEntityUserLink *)object
                                                         accountId:(NSString *)accountId;

// Method: analytics.management.accountUserLinks.list
// Lists account-user links for a given account.
//  Required:
//   accountId: Account ID to retrieve the user links for.
//  Optional:
//   maxResults: The maximum number of account-user links to include in this
//     response.
//   startIndex: An index of the first account-user link to retrieve. Use this
//     parameter as a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
//   kGTLAuthScopeAnalyticsManageUsersReadonly
// Fetches a GTLAnalyticsEntityUserLinks.
+ (instancetype)queryForManagementAccountUserLinksListWithAccountId:(NSString *)accountId;

// Method: analytics.management.accountUserLinks.update
// Updates permissions for an existing user on the given account.
//  Required:
//   accountId: Account ID to update the account-user link for.
//   linkId: Link ID to update the account-user link for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
// Fetches a GTLAnalyticsEntityUserLink.
+ (instancetype)queryForManagementAccountUserLinksUpdateWithObject:(GTLAnalyticsEntityUserLink *)object
                                                         accountId:(NSString *)accountId
                                                            linkId:(NSString *)linkId;

#pragma mark - "management.customDataSources" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.customDataSources.list
// List custom data sources to which the user has access.
//  Required:
//   accountId: Account Id for the custom data sources to retrieve.
//   webPropertyId: Web property Id for the custom data sources to retrieve.
//  Optional:
//   maxResults: The maximum number of custom data sources to include in this
//     response.
//   startIndex: A 1-based index of the first custom data source to retrieve.
//     Use this parameter as a pagination mechanism along with the max-results
//     parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsCustomDataSources.
+ (instancetype)queryForManagementCustomDataSourcesListWithAccountId:(NSString *)accountId
                                                       webPropertyId:(NSString *)webPropertyId;

#pragma mark - "management.customDimensions" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.customDimensions.get
// Get a custom dimension to which the user has access.
//  Required:
//   accountId: Account ID for the custom dimension to retrieve.
//   webPropertyId: Web property ID for the custom dimension to retrieve.
//   customDimensionId: The ID of the custom dimension to retrieve.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsCustomDimension.
+ (instancetype)queryForManagementCustomDimensionsGetWithAccountId:(NSString *)accountId
                                                     webPropertyId:(NSString *)webPropertyId
                                                 customDimensionId:(NSString *)customDimensionId;

// Method: analytics.management.customDimensions.insert
// Create a new custom dimension.
//  Required:
//   accountId: Account ID for the custom dimension to create.
//   webPropertyId: Web property ID for the custom dimension to create.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsCustomDimension.
+ (instancetype)queryForManagementCustomDimensionsInsertWithObject:(GTLAnalyticsCustomDimension *)object
                                                         accountId:(NSString *)accountId
                                                     webPropertyId:(NSString *)webPropertyId;

// Method: analytics.management.customDimensions.list
// Lists custom dimensions to which the user has access.
//  Required:
//   accountId: Account ID for the custom dimensions to retrieve.
//   webPropertyId: Web property ID for the custom dimensions to retrieve.
//  Optional:
//   maxResults: The maximum number of custom dimensions to include in this
//     response.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsCustomDimensions.
+ (instancetype)queryForManagementCustomDimensionsListWithAccountId:(NSString *)accountId
                                                      webPropertyId:(NSString *)webPropertyId;

// Method: analytics.management.customDimensions.patch
// Updates an existing custom dimension. This method supports patch semantics.
//  Required:
//   accountId: Account ID for the custom dimension to update.
//   webPropertyId: Web property ID for the custom dimension to update.
//   customDimensionId: Custom dimension ID for the custom dimension to update.
//  Optional:
//   ignoreCustomDataSourceLinks: Force the update and ignore any warnings
//     related to the custom dimension being linked to a custom data source /
//     data set. (Default false)
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsCustomDimension.
+ (instancetype)queryForManagementCustomDimensionsPatchWithObject:(GTLAnalyticsCustomDimension *)object
                                                        accountId:(NSString *)accountId
                                                    webPropertyId:(NSString *)webPropertyId
                                                customDimensionId:(NSString *)customDimensionId;

// Method: analytics.management.customDimensions.update
// Updates an existing custom dimension.
//  Required:
//   accountId: Account ID for the custom dimension to update.
//   webPropertyId: Web property ID for the custom dimension to update.
//   customDimensionId: Custom dimension ID for the custom dimension to update.
//  Optional:
//   ignoreCustomDataSourceLinks: Force the update and ignore any warnings
//     related to the custom dimension being linked to a custom data source /
//     data set. (Default false)
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsCustomDimension.
+ (instancetype)queryForManagementCustomDimensionsUpdateWithObject:(GTLAnalyticsCustomDimension *)object
                                                         accountId:(NSString *)accountId
                                                     webPropertyId:(NSString *)webPropertyId
                                                 customDimensionId:(NSString *)customDimensionId;

#pragma mark - "management.customMetrics" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.customMetrics.get
// Get a custom metric to which the user has access.
//  Required:
//   accountId: Account ID for the custom metric to retrieve.
//   webPropertyId: Web property ID for the custom metric to retrieve.
//   customMetricId: The ID of the custom metric to retrieve.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsCustomMetric.
+ (instancetype)queryForManagementCustomMetricsGetWithAccountId:(NSString *)accountId
                                                  webPropertyId:(NSString *)webPropertyId
                                                 customMetricId:(NSString *)customMetricId;

// Method: analytics.management.customMetrics.insert
// Create a new custom metric.
//  Required:
//   accountId: Account ID for the custom metric to create.
//   webPropertyId: Web property ID for the custom dimension to create.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsCustomMetric.
+ (instancetype)queryForManagementCustomMetricsInsertWithObject:(GTLAnalyticsCustomMetric *)object
                                                      accountId:(NSString *)accountId
                                                  webPropertyId:(NSString *)webPropertyId;

// Method: analytics.management.customMetrics.list
// Lists custom metrics to which the user has access.
//  Required:
//   accountId: Account ID for the custom metrics to retrieve.
//   webPropertyId: Web property ID for the custom metrics to retrieve.
//  Optional:
//   maxResults: The maximum number of custom metrics to include in this
//     response.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsCustomMetrics.
+ (instancetype)queryForManagementCustomMetricsListWithAccountId:(NSString *)accountId
                                                   webPropertyId:(NSString *)webPropertyId;

// Method: analytics.management.customMetrics.patch
// Updates an existing custom metric. This method supports patch semantics.
//  Required:
//   accountId: Account ID for the custom metric to update.
//   webPropertyId: Web property ID for the custom metric to update.
//   customMetricId: Custom metric ID for the custom metric to update.
//  Optional:
//   ignoreCustomDataSourceLinks: Force the update and ignore any warnings
//     related to the custom metric being linked to a custom data source / data
//     set. (Default false)
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsCustomMetric.
+ (instancetype)queryForManagementCustomMetricsPatchWithObject:(GTLAnalyticsCustomMetric *)object
                                                     accountId:(NSString *)accountId
                                                 webPropertyId:(NSString *)webPropertyId
                                                customMetricId:(NSString *)customMetricId;

// Method: analytics.management.customMetrics.update
// Updates an existing custom metric.
//  Required:
//   accountId: Account ID for the custom metric to update.
//   webPropertyId: Web property ID for the custom metric to update.
//   customMetricId: Custom metric ID for the custom metric to update.
//  Optional:
//   ignoreCustomDataSourceLinks: Force the update and ignore any warnings
//     related to the custom metric being linked to a custom data source / data
//     set. (Default false)
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsCustomMetric.
+ (instancetype)queryForManagementCustomMetricsUpdateWithObject:(GTLAnalyticsCustomMetric *)object
                                                      accountId:(NSString *)accountId
                                                  webPropertyId:(NSString *)webPropertyId
                                                 customMetricId:(NSString *)customMetricId;

#pragma mark - "management.experiments" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.experiments.delete
// Delete an experiment.
//  Required:
//   accountId: Account ID to which the experiment belongs
//   webPropertyId: Web property ID to which the experiment belongs
//   profileId: View (Profile) ID to which the experiment belongs
//   experimentId: ID of the experiment to delete
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
+ (instancetype)queryForManagementExperimentsDeleteWithAccountId:(NSString *)accountId
                                                   webPropertyId:(NSString *)webPropertyId
                                                       profileId:(NSString *)profileId
                                                    experimentId:(NSString *)experimentId;

// Method: analytics.management.experiments.get
// Returns an experiment to which the user has access.
//  Required:
//   accountId: Account ID to retrieve the experiment for.
//   webPropertyId: Web property ID to retrieve the experiment for.
//   profileId: View (Profile) ID to retrieve the experiment for.
//   experimentId: Experiment ID to retrieve the experiment for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsExperiment.
+ (instancetype)queryForManagementExperimentsGetWithAccountId:(NSString *)accountId
                                                webPropertyId:(NSString *)webPropertyId
                                                    profileId:(NSString *)profileId
                                                 experimentId:(NSString *)experimentId;

// Method: analytics.management.experiments.insert
// Create a new experiment.
//  Required:
//   accountId: Account ID to create the experiment for.
//   webPropertyId: Web property ID to create the experiment for.
//   profileId: View (Profile) ID to create the experiment for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsExperiment.
+ (instancetype)queryForManagementExperimentsInsertWithObject:(GTLAnalyticsExperiment *)object
                                                    accountId:(NSString *)accountId
                                                webPropertyId:(NSString *)webPropertyId
                                                    profileId:(NSString *)profileId;

// Method: analytics.management.experiments.list
// Lists experiments to which the user has access.
//  Required:
//   accountId: Account ID to retrieve experiments for.
//   webPropertyId: Web property ID to retrieve experiments for.
//   profileId: View (Profile) ID to retrieve experiments for.
//  Optional:
//   maxResults: The maximum number of experiments to include in this response.
//   startIndex: An index of the first experiment to retrieve. Use this
//     parameter as a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsExperiments.
+ (instancetype)queryForManagementExperimentsListWithAccountId:(NSString *)accountId
                                                 webPropertyId:(NSString *)webPropertyId
                                                     profileId:(NSString *)profileId;

// Method: analytics.management.experiments.patch
// Update an existing experiment. This method supports patch semantics.
//  Required:
//   accountId: Account ID of the experiment to update.
//   webPropertyId: Web property ID of the experiment to update.
//   profileId: View (Profile) ID of the experiment to update.
//   experimentId: Experiment ID of the experiment to update.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsExperiment.
+ (instancetype)queryForManagementExperimentsPatchWithObject:(GTLAnalyticsExperiment *)object
                                                   accountId:(NSString *)accountId
                                               webPropertyId:(NSString *)webPropertyId
                                                   profileId:(NSString *)profileId
                                                experimentId:(NSString *)experimentId;

// Method: analytics.management.experiments.update
// Update an existing experiment.
//  Required:
//   accountId: Account ID of the experiment to update.
//   webPropertyId: Web property ID of the experiment to update.
//   profileId: View (Profile) ID of the experiment to update.
//   experimentId: Experiment ID of the experiment to update.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsExperiment.
+ (instancetype)queryForManagementExperimentsUpdateWithObject:(GTLAnalyticsExperiment *)object
                                                    accountId:(NSString *)accountId
                                                webPropertyId:(NSString *)webPropertyId
                                                    profileId:(NSString *)profileId
                                                 experimentId:(NSString *)experimentId;

#pragma mark - "management.filters" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.filters.delete
// Delete a filter.
//  Required:
//   accountId: Account ID to delete the filter for.
//   filterId: ID of the filter to be deleted.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsFilter.
+ (instancetype)queryForManagementFiltersDeleteWithAccountId:(NSString *)accountId
                                                    filterId:(NSString *)filterId;

// Method: analytics.management.filters.get
// Returns a filters to which the user has access.
//  Required:
//   accountId: Account ID to retrieve filters for.
//   filterId: Filter ID to retrieve filters for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsFilter.
+ (instancetype)queryForManagementFiltersGetWithAccountId:(NSString *)accountId
                                                 filterId:(NSString *)filterId;

// Method: analytics.management.filters.insert
// Create a new filter.
//  Required:
//   accountId: Account ID to create filter for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsFilter.
+ (instancetype)queryForManagementFiltersInsertWithObject:(GTLAnalyticsFilter *)object
                                                accountId:(NSString *)accountId;

// Method: analytics.management.filters.list
// Lists all filters for an account
//  Required:
//   accountId: Account ID to retrieve filters for.
//  Optional:
//   maxResults: The maximum number of filters to include in this response.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsFilters.
+ (instancetype)queryForManagementFiltersListWithAccountId:(NSString *)accountId;

// Method: analytics.management.filters.patch
// Updates an existing filter. This method supports patch semantics.
//  Required:
//   accountId: Account ID to which the filter belongs.
//   filterId: ID of the filter to be updated.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsFilter.
+ (instancetype)queryForManagementFiltersPatchWithObject:(GTLAnalyticsFilter *)object
                                               accountId:(NSString *)accountId
                                                filterId:(NSString *)filterId;

// Method: analytics.management.filters.update
// Updates an existing filter.
//  Required:
//   accountId: Account ID to which the filter belongs.
//   filterId: ID of the filter to be updated.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsFilter.
+ (instancetype)queryForManagementFiltersUpdateWithObject:(GTLAnalyticsFilter *)object
                                                accountId:(NSString *)accountId
                                                 filterId:(NSString *)filterId;

#pragma mark - "management.goals" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.goals.get
// Gets a goal to which the user has access.
//  Required:
//   accountId: Account ID to retrieve the goal for.
//   webPropertyId: Web property ID to retrieve the goal for.
//   profileId: View (Profile) ID to retrieve the goal for.
//   goalId: Goal ID to retrieve the goal for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsGoal.
+ (instancetype)queryForManagementGoalsGetWithAccountId:(NSString *)accountId
                                          webPropertyId:(NSString *)webPropertyId
                                              profileId:(NSString *)profileId
                                                 goalId:(NSString *)goalId;

// Method: analytics.management.goals.insert
// Create a new goal.
//  Required:
//   accountId: Account ID to create the goal for.
//   webPropertyId: Web property ID to create the goal for.
//   profileId: View (Profile) ID to create the goal for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsGoal.
+ (instancetype)queryForManagementGoalsInsertWithObject:(GTLAnalyticsGoal *)object
                                              accountId:(NSString *)accountId
                                          webPropertyId:(NSString *)webPropertyId
                                              profileId:(NSString *)profileId;

// Method: analytics.management.goals.list
// Lists goals to which the user has access.
//  Required:
//   accountId: Account ID to retrieve goals for. Can either be a specific
//     account ID or '~all', which refers to all the accounts that user has
//     access to.
//   webPropertyId: Web property ID to retrieve goals for. Can either be a
//     specific web property ID or '~all', which refers to all the web
//     properties that user has access to.
//   profileId: View (Profile) ID to retrieve goals for. Can either be a
//     specific view (profile) ID or '~all', which refers to all the views
//     (profiles) that user has access to.
//  Optional:
//   maxResults: The maximum number of goals to include in this response.
//   startIndex: An index of the first goal to retrieve. Use this parameter as a
//     pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsGoals.
+ (instancetype)queryForManagementGoalsListWithAccountId:(NSString *)accountId
                                           webPropertyId:(NSString *)webPropertyId
                                               profileId:(NSString *)profileId;

// Method: analytics.management.goals.patch
// Updates an existing view (profile). This method supports patch semantics.
//  Required:
//   accountId: Account ID to update the goal.
//   webPropertyId: Web property ID to update the goal.
//   profileId: View (Profile) ID to update the goal.
//   goalId: Index of the goal to be updated.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsGoal.
+ (instancetype)queryForManagementGoalsPatchWithObject:(GTLAnalyticsGoal *)object
                                             accountId:(NSString *)accountId
                                         webPropertyId:(NSString *)webPropertyId
                                             profileId:(NSString *)profileId
                                                goalId:(NSString *)goalId;

// Method: analytics.management.goals.update
// Updates an existing view (profile).
//  Required:
//   accountId: Account ID to update the goal.
//   webPropertyId: Web property ID to update the goal.
//   profileId: View (Profile) ID to update the goal.
//   goalId: Index of the goal to be updated.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsGoal.
+ (instancetype)queryForManagementGoalsUpdateWithObject:(GTLAnalyticsGoal *)object
                                              accountId:(NSString *)accountId
                                          webPropertyId:(NSString *)webPropertyId
                                              profileId:(NSString *)profileId
                                                 goalId:(NSString *)goalId;

#pragma mark - "management.profileFilterLinks" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.profileFilterLinks.delete
// Delete a profile filter link.
//  Required:
//   accountId: Account ID to which the profile filter link belongs.
//   webPropertyId: Web property Id to which the profile filter link belongs.
//   profileId: Profile ID to which the filter link belongs.
//   linkId: ID of the profile filter link to delete.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
+ (instancetype)queryForManagementProfileFilterLinksDeleteWithAccountId:(NSString *)accountId
                                                          webPropertyId:(NSString *)webPropertyId
                                                              profileId:(NSString *)profileId
                                                                 linkId:(NSString *)linkId;

// Method: analytics.management.profileFilterLinks.get
// Returns a single profile filter link.
//  Required:
//   accountId: Account ID to retrieve profile filter link for.
//   webPropertyId: Web property Id to retrieve profile filter link for.
//   profileId: Profile ID to retrieve filter link for.
//   linkId: ID of the profile filter link.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsProfileFilterLink.
+ (instancetype)queryForManagementProfileFilterLinksGetWithAccountId:(NSString *)accountId
                                                       webPropertyId:(NSString *)webPropertyId
                                                           profileId:(NSString *)profileId
                                                              linkId:(NSString *)linkId;

// Method: analytics.management.profileFilterLinks.insert
// Create a new profile filter link.
//  Required:
//   accountId: Account ID to create profile filter link for.
//   webPropertyId: Web property Id to create profile filter link for.
//   profileId: Profile ID to create filter link for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsProfileFilterLink.
+ (instancetype)queryForManagementProfileFilterLinksInsertWithObject:(GTLAnalyticsProfileFilterLink *)object
                                                           accountId:(NSString *)accountId
                                                       webPropertyId:(NSString *)webPropertyId
                                                           profileId:(NSString *)profileId;

// Method: analytics.management.profileFilterLinks.list
// Lists all profile filter links for a profile.
//  Required:
//   accountId: Account ID to retrieve profile filter links for.
//   webPropertyId: Web property Id for profile filter links for. Can either be
//     a specific web property ID or '~all', which refers to all the web
//     properties that user has access to.
//   profileId: Profile ID to retrieve filter links for. Can either be a
//     specific profile ID or '~all', which refers to all the profiles that user
//     has access to.
//  Optional:
//   maxResults: The maximum number of profile filter links to include in this
//     response.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsProfileFilterLinks.
+ (instancetype)queryForManagementProfileFilterLinksListWithAccountId:(NSString *)accountId
                                                        webPropertyId:(NSString *)webPropertyId
                                                            profileId:(NSString *)profileId;

// Method: analytics.management.profileFilterLinks.patch
// Update an existing profile filter link. This method supports patch semantics.
//  Required:
//   accountId: Account ID to which profile filter link belongs.
//   webPropertyId: Web property Id to which profile filter link belongs
//   profileId: Profile ID to which filter link belongs
//   linkId: ID of the profile filter link to be updated.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsProfileFilterLink.
+ (instancetype)queryForManagementProfileFilterLinksPatchWithObject:(GTLAnalyticsProfileFilterLink *)object
                                                          accountId:(NSString *)accountId
                                                      webPropertyId:(NSString *)webPropertyId
                                                          profileId:(NSString *)profileId
                                                             linkId:(NSString *)linkId;

// Method: analytics.management.profileFilterLinks.update
// Update an existing profile filter link.
//  Required:
//   accountId: Account ID to which profile filter link belongs.
//   webPropertyId: Web property Id to which profile filter link belongs
//   profileId: Profile ID to which filter link belongs
//   linkId: ID of the profile filter link to be updated.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsProfileFilterLink.
+ (instancetype)queryForManagementProfileFilterLinksUpdateWithObject:(GTLAnalyticsProfileFilterLink *)object
                                                           accountId:(NSString *)accountId
                                                       webPropertyId:(NSString *)webPropertyId
                                                           profileId:(NSString *)profileId
                                                              linkId:(NSString *)linkId;

#pragma mark - "management.profiles" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.profiles.delete
// Deletes a view (profile).
//  Required:
//   accountId: Account ID to delete the view (profile) for.
//   webPropertyId: Web property ID to delete the view (profile) for.
//   profileId: ID of the view (profile) to be deleted.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
+ (instancetype)queryForManagementProfilesDeleteWithAccountId:(NSString *)accountId
                                                webPropertyId:(NSString *)webPropertyId
                                                    profileId:(NSString *)profileId;

// Method: analytics.management.profiles.get
// Gets a view (profile) to which the user has access.
//  Required:
//   accountId: Account ID to retrieve the goal for.
//   webPropertyId: Web property ID to retrieve the goal for.
//   profileId: View (Profile) ID to retrieve the goal for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsProfile.
+ (instancetype)queryForManagementProfilesGetWithAccountId:(NSString *)accountId
                                             webPropertyId:(NSString *)webPropertyId
                                                 profileId:(NSString *)profileId;

// Method: analytics.management.profiles.insert
// Create a new view (profile).
//  Required:
//   accountId: Account ID to create the view (profile) for.
//   webPropertyId: Web property ID to create the view (profile) for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsProfile.
+ (instancetype)queryForManagementProfilesInsertWithObject:(GTLAnalyticsProfile *)object
                                                 accountId:(NSString *)accountId
                                             webPropertyId:(NSString *)webPropertyId;

// Method: analytics.management.profiles.list
// Lists views (profiles) to which the user has access.
//  Required:
//   accountId: Account ID for the view (profiles) to retrieve. Can either be a
//     specific account ID or '~all', which refers to all the accounts to which
//     the user has access.
//   webPropertyId: Web property ID for the views (profiles) to retrieve. Can
//     either be a specific web property ID or '~all', which refers to all the
//     web properties to which the user has access.
//  Optional:
//   maxResults: The maximum number of views (profiles) to include in this
//     response.
//   startIndex: An index of the first entity to retrieve. Use this parameter as
//     a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsProfiles.
+ (instancetype)queryForManagementProfilesListWithAccountId:(NSString *)accountId
                                              webPropertyId:(NSString *)webPropertyId;

// Method: analytics.management.profiles.patch
// Updates an existing view (profile). This method supports patch semantics.
//  Required:
//   accountId: Account ID to which the view (profile) belongs
//   webPropertyId: Web property ID to which the view (profile) belongs
//   profileId: ID of the view (profile) to be updated.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsProfile.
+ (instancetype)queryForManagementProfilesPatchWithObject:(GTLAnalyticsProfile *)object
                                                accountId:(NSString *)accountId
                                            webPropertyId:(NSString *)webPropertyId
                                                profileId:(NSString *)profileId;

// Method: analytics.management.profiles.update
// Updates an existing view (profile).
//  Required:
//   accountId: Account ID to which the view (profile) belongs
//   webPropertyId: Web property ID to which the view (profile) belongs
//   profileId: ID of the view (profile) to be updated.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsProfile.
+ (instancetype)queryForManagementProfilesUpdateWithObject:(GTLAnalyticsProfile *)object
                                                 accountId:(NSString *)accountId
                                             webPropertyId:(NSString *)webPropertyId
                                                 profileId:(NSString *)profileId;

#pragma mark - "management.profileUserLinks" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.profileUserLinks.delete
// Removes a user from the given view (profile).
//  Required:
//   accountId: Account ID to delete the user link for.
//   webPropertyId: Web Property ID to delete the user link for.
//   profileId: View (Profile) ID to delete the user link for.
//   linkId: Link ID to delete the user link for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
+ (instancetype)queryForManagementProfileUserLinksDeleteWithAccountId:(NSString *)accountId
                                                        webPropertyId:(NSString *)webPropertyId
                                                            profileId:(NSString *)profileId
                                                               linkId:(NSString *)linkId;

// Method: analytics.management.profileUserLinks.insert
// Adds a new user to the given view (profile).
//  Required:
//   accountId: Account ID to create the user link for.
//   webPropertyId: Web Property ID to create the user link for.
//   profileId: View (Profile) ID to create the user link for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
// Fetches a GTLAnalyticsEntityUserLink.
+ (instancetype)queryForManagementProfileUserLinksInsertWithObject:(GTLAnalyticsEntityUserLink *)object
                                                         accountId:(NSString *)accountId
                                                     webPropertyId:(NSString *)webPropertyId
                                                         profileId:(NSString *)profileId;

// Method: analytics.management.profileUserLinks.list
// Lists profile-user links for a given view (profile).
//  Required:
//   accountId: Account ID which the given view (profile) belongs to.
//   webPropertyId: Web Property ID which the given view (profile) belongs to.
//     Can either be a specific web property ID or '~all', which refers to all
//     the web properties that user has access to.
//   profileId: View (Profile) ID to retrieve the profile-user links for. Can
//     either be a specific profile ID or '~all', which refers to all the
//     profiles that user has access to.
//  Optional:
//   maxResults: The maximum number of profile-user links to include in this
//     response.
//   startIndex: An index of the first profile-user link to retrieve. Use this
//     parameter as a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
//   kGTLAuthScopeAnalyticsManageUsersReadonly
// Fetches a GTLAnalyticsEntityUserLinks.
+ (instancetype)queryForManagementProfileUserLinksListWithAccountId:(NSString *)accountId
                                                      webPropertyId:(NSString *)webPropertyId
                                                          profileId:(NSString *)profileId;

// Method: analytics.management.profileUserLinks.update
// Updates permissions for an existing user on the given view (profile).
//  Required:
//   accountId: Account ID to update the user link for.
//   webPropertyId: Web Property ID to update the user link for.
//   profileId: View (Profile ID) to update the user link for.
//   linkId: Link ID to update the user link for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
// Fetches a GTLAnalyticsEntityUserLink.
+ (instancetype)queryForManagementProfileUserLinksUpdateWithObject:(GTLAnalyticsEntityUserLink *)object
                                                         accountId:(NSString *)accountId
                                                     webPropertyId:(NSString *)webPropertyId
                                                         profileId:(NSString *)profileId
                                                            linkId:(NSString *)linkId;

#pragma mark - "management.segments" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.segments.list
// Lists segments to which the user has access.
//  Optional:
//   maxResults: The maximum number of segments to include in this response.
//   startIndex: An index of the first segment to retrieve. Use this parameter
//     as a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsSegments.
+ (instancetype)queryForManagementSegmentsList;

#pragma mark - "management.unsampledReports" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.unsampledReports.get
// Returns a single unsampled report.
//  Required:
//   accountId: Account ID to retrieve unsampled report for.
//   webPropertyId: Web property ID to retrieve unsampled reports for.
//   profileId: View (Profile) ID to retrieve unsampled report for.
//   unsampledReportId: ID of the unsampled report to retrieve.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsUnsampledReport.
+ (instancetype)queryForManagementUnsampledReportsGetWithAccountId:(NSString *)accountId
                                                     webPropertyId:(NSString *)webPropertyId
                                                         profileId:(NSString *)profileId
                                                 unsampledReportId:(NSString *)unsampledReportId;

// Method: analytics.management.unsampledReports.insert
// Create a new unsampled report.
//  Required:
//   accountId: Account ID to create the unsampled report for.
//   webPropertyId: Web property ID to create the unsampled report for.
//   profileId: View (Profile) ID to create the unsampled report for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsUnsampledReport.
+ (instancetype)queryForManagementUnsampledReportsInsertWithObject:(GTLAnalyticsUnsampledReport *)object
                                                         accountId:(NSString *)accountId
                                                     webPropertyId:(NSString *)webPropertyId
                                                         profileId:(NSString *)profileId;

// Method: analytics.management.unsampledReports.list
// Lists unsampled reports to which the user has access.
//  Required:
//   accountId: Account ID to retrieve unsampled reports for. Must be a specific
//     account ID, ~all is not supported.
//   webPropertyId: Web property ID to retrieve unsampled reports for. Must be a
//     specific web property ID, ~all is not supported.
//   profileId: View (Profile) ID to retrieve unsampled reports for. Must be a
//     specific view (profile) ID, ~all is not supported.
//  Optional:
//   maxResults: The maximum number of unsampled reports to include in this
//     response.
//   startIndex: An index of the first unsampled report to retrieve. Use this
//     parameter as a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsUnsampledReports.
+ (instancetype)queryForManagementUnsampledReportsListWithAccountId:(NSString *)accountId
                                                      webPropertyId:(NSString *)webPropertyId
                                                          profileId:(NSString *)profileId;

#pragma mark - "management.uploads" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.uploads.deleteUploadData
// Delete data associated with a previous upload.
//  Required:
//   accountId: Account Id for the uploads to be deleted.
//   webPropertyId: Web property Id for the uploads to be deleted.
//   customDataSourceId: Custom data source Id for the uploads to be deleted.
//  Optional:
//   customDataImportUids: A list of upload UIDs.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
+ (instancetype)queryForManagementUploadsDeleteUploadDataWithAccountId:(NSString *)accountId
                                                         webPropertyId:(NSString *)webPropertyId
                                                    customDataSourceId:(NSString *)customDataSourceId;

// Method: analytics.management.uploads.get
// List uploads to which the user has access.
//  Required:
//   accountId: Account Id for the upload to retrieve.
//   webPropertyId: Web property Id for the upload to retrieve.
//   customDataSourceId: Custom data source Id for upload to retrieve.
//   uploadId: Upload Id to retrieve.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsUpload.
+ (instancetype)queryForManagementUploadsGetWithAccountId:(NSString *)accountId
                                            webPropertyId:(NSString *)webPropertyId
                                       customDataSourceId:(NSString *)customDataSourceId
                                                 uploadId:(NSString *)uploadId;

// Method: analytics.management.uploads.list
// List uploads to which the user has access.
//  Required:
//   accountId: Account Id for the uploads to retrieve.
//   webPropertyId: Web property Id for the uploads to retrieve.
//   customDataSourceId: Custom data source Id for uploads to retrieve.
//  Optional:
//   maxResults: The maximum number of uploads to include in this response.
//   startIndex: A 1-based index of the first upload to retrieve. Use this
//     parameter as a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsUploads.
+ (instancetype)queryForManagementUploadsListWithAccountId:(NSString *)accountId
                                             webPropertyId:(NSString *)webPropertyId
                                        customDataSourceId:(NSString *)customDataSourceId;

// Method: analytics.management.uploads.uploadData
// Upload data for a custom data source.
//  Required:
//   accountId: Account Id associated with the upload.
//   webPropertyId: Web property UA-string associated with the upload.
//   customDataSourceId: Custom data source Id to which the data being uploaded
//     belongs.
//  Upload Parameters:
//   Maximum size: 1GB
//   Accepted MIME type(s): application/octet-stream
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsUpload.
+ (instancetype)queryForManagementUploadsUploadDataWithAccountId:(NSString *)accountId
                                                   webPropertyId:(NSString *)webPropertyId
                                              customDataSourceId:(NSString *)customDataSourceId
                                                uploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

#pragma mark - "management.webproperties" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.webproperties.get
// Gets a web property to which the user has access.
//  Required:
//   accountId: Account ID to retrieve the web property for.
//   webPropertyId: ID to retrieve the web property for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsWebproperty.
+ (instancetype)queryForManagementWebpropertiesGetWithAccountId:(NSString *)accountId
                                                  webPropertyId:(NSString *)webPropertyId;

// Method: analytics.management.webproperties.insert
// Create a new property if the account has fewer than 20 properties. Web
// properties are visible in the Google Analytics interface only if they have at
// least one profile.
//  Required:
//   accountId: Account ID to create the web property for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsWebproperty.
+ (instancetype)queryForManagementWebpropertiesInsertWithObject:(GTLAnalyticsWebproperty *)object
                                                      accountId:(NSString *)accountId;

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
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsWebproperties.
+ (instancetype)queryForManagementWebpropertiesListWithAccountId:(NSString *)accountId;

// Method: analytics.management.webproperties.patch
// Updates an existing web property. This method supports patch semantics.
//  Required:
//   accountId: Account ID to which the web property belongs
//   webPropertyId: Web property ID
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsWebproperty.
+ (instancetype)queryForManagementWebpropertiesPatchWithObject:(GTLAnalyticsWebproperty *)object
                                                     accountId:(NSString *)accountId
                                                 webPropertyId:(NSString *)webPropertyId;

// Method: analytics.management.webproperties.update
// Updates an existing web property.
//  Required:
//   accountId: Account ID to which the web property belongs
//   webPropertyId: Web property ID
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsWebproperty.
+ (instancetype)queryForManagementWebpropertiesUpdateWithObject:(GTLAnalyticsWebproperty *)object
                                                      accountId:(NSString *)accountId
                                                  webPropertyId:(NSString *)webPropertyId;

#pragma mark - "management.webPropertyAdWordsLinks" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.webPropertyAdWordsLinks.delete
// Deletes a web property-AdWords link.
//  Required:
//   accountId: ID of the account which the given web property belongs to.
//   webPropertyId: Web property ID to delete the AdWords link for.
//   webPropertyAdWordsLinkId: Web property AdWords link ID.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
+ (instancetype)queryForManagementWebPropertyAdWordsLinksDeleteWithAccountId:(NSString *)accountId
                                                               webPropertyId:(NSString *)webPropertyId
                                                    webPropertyAdWordsLinkId:(NSString *)webPropertyAdWordsLinkId;

// Method: analytics.management.webPropertyAdWordsLinks.get
// Returns a web property-AdWords link to which the user has access.
//  Required:
//   accountId: ID of the account which the given web property belongs to.
//   webPropertyId: Web property ID to retrieve the AdWords link for.
//   webPropertyAdWordsLinkId: Web property-AdWords link ID.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsEntityAdWordsLink.
+ (instancetype)queryForManagementWebPropertyAdWordsLinksGetWithAccountId:(NSString *)accountId
                                                            webPropertyId:(NSString *)webPropertyId
                                                 webPropertyAdWordsLinkId:(NSString *)webPropertyAdWordsLinkId;

// Method: analytics.management.webPropertyAdWordsLinks.insert
// Creates a webProperty-AdWords link.
//  Required:
//   accountId: ID of the Google Analytics account to create the link for.
//   webPropertyId: Web property ID to create the link for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsEntityAdWordsLink.
+ (instancetype)queryForManagementWebPropertyAdWordsLinksInsertWithObject:(GTLAnalyticsEntityAdWordsLink *)object
                                                                accountId:(NSString *)accountId
                                                            webPropertyId:(NSString *)webPropertyId;

// Method: analytics.management.webPropertyAdWordsLinks.list
// Lists webProperty-AdWords links for a given web property.
//  Required:
//   accountId: ID of the account which the given web property belongs to.
//   webPropertyId: Web property ID to retrieve the AdWords links for.
//  Optional:
//   maxResults: The maximum number of webProperty-AdWords links to include in
//     this response.
//   startIndex: An index of the first webProperty-AdWords link to retrieve. Use
//     this parameter as a pagination mechanism along with the max-results
//     parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsEntityAdWordsLinks.
+ (instancetype)queryForManagementWebPropertyAdWordsLinksListWithAccountId:(NSString *)accountId
                                                             webPropertyId:(NSString *)webPropertyId;

// Method: analytics.management.webPropertyAdWordsLinks.patch
// Updates an existing webProperty-AdWords link. This method supports patch
// semantics.
//  Required:
//   accountId: ID of the account which the given web property belongs to.
//   webPropertyId: Web property ID to retrieve the AdWords link for.
//   webPropertyAdWordsLinkId: Web property-AdWords link ID.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsEntityAdWordsLink.
+ (instancetype)queryForManagementWebPropertyAdWordsLinksPatchWithObject:(GTLAnalyticsEntityAdWordsLink *)object
                                                               accountId:(NSString *)accountId
                                                           webPropertyId:(NSString *)webPropertyId
                                                webPropertyAdWordsLinkId:(NSString *)webPropertyAdWordsLinkId;

// Method: analytics.management.webPropertyAdWordsLinks.update
// Updates an existing webProperty-AdWords link.
//  Required:
//   accountId: ID of the account which the given web property belongs to.
//   webPropertyId: Web property ID to retrieve the AdWords link for.
//   webPropertyAdWordsLinkId: Web property-AdWords link ID.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsEntityAdWordsLink.
+ (instancetype)queryForManagementWebPropertyAdWordsLinksUpdateWithObject:(GTLAnalyticsEntityAdWordsLink *)object
                                                                accountId:(NSString *)accountId
                                                            webPropertyId:(NSString *)webPropertyId
                                                 webPropertyAdWordsLinkId:(NSString *)webPropertyAdWordsLinkId;

#pragma mark - "management.webpropertyUserLinks" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.webpropertyUserLinks.delete
// Removes a user from the given web property.
//  Required:
//   accountId: Account ID to delete the user link for.
//   webPropertyId: Web Property ID to delete the user link for.
//   linkId: Link ID to delete the user link for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
+ (instancetype)queryForManagementWebpropertyUserLinksDeleteWithAccountId:(NSString *)accountId
                                                            webPropertyId:(NSString *)webPropertyId
                                                                   linkId:(NSString *)linkId;

// Method: analytics.management.webpropertyUserLinks.insert
// Adds a new user to the given web property.
//  Required:
//   accountId: Account ID to create the user link for.
//   webPropertyId: Web Property ID to create the user link for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
// Fetches a GTLAnalyticsEntityUserLink.
+ (instancetype)queryForManagementWebpropertyUserLinksInsertWithObject:(GTLAnalyticsEntityUserLink *)object
                                                             accountId:(NSString *)accountId
                                                         webPropertyId:(NSString *)webPropertyId;

// Method: analytics.management.webpropertyUserLinks.list
// Lists webProperty-user links for a given web property.
//  Required:
//   accountId: Account ID which the given web property belongs to.
//   webPropertyId: Web Property ID for the webProperty-user links to retrieve.
//     Can either be a specific web property ID or '~all', which refers to all
//     the web properties that user has access to.
//  Optional:
//   maxResults: The maximum number of webProperty-user Links to include in this
//     response.
//   startIndex: An index of the first webProperty-user link to retrieve. Use
//     this parameter as a pagination mechanism along with the max-results
//     parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
//   kGTLAuthScopeAnalyticsManageUsersReadonly
// Fetches a GTLAnalyticsEntityUserLinks.
+ (instancetype)queryForManagementWebpropertyUserLinksListWithAccountId:(NSString *)accountId
                                                          webPropertyId:(NSString *)webPropertyId;

// Method: analytics.management.webpropertyUserLinks.update
// Updates permissions for an existing user on the given web property.
//  Required:
//   accountId: Account ID to update the account-user link for.
//   webPropertyId: Web property ID to update the account-user link for.
//   linkId: Link ID to update the account-user link for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
// Fetches a GTLAnalyticsEntityUserLink.
+ (instancetype)queryForManagementWebpropertyUserLinksUpdateWithObject:(GTLAnalyticsEntityUserLink *)object
                                                             accountId:(NSString *)accountId
                                                         webPropertyId:(NSString *)webPropertyId
                                                                linkId:(NSString *)linkId;

#pragma mark - "metadata.columns" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.metadata.columns.list
// Lists all columns for a report type
//  Required:
//   reportType: Report type. Allowed Values: 'ga'. Where 'ga' corresponds to
//     the Core Reporting API
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsColumns.
+ (instancetype)queryForMetadataColumnsListWithReportType:(NSString *)reportType;

#pragma mark - "provisioning" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.provisioning.createAccountTicket
// Creates an account ticket.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsProvision
// Fetches a GTLAnalyticsAccountTicket.
+ (instancetype)queryForProvisioningCreateAccountTicketWithObject:(GTLAnalyticsAccountTicket *)object;

@end
