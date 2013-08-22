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
//   GTLQueryAnalytics (19 custom class methods, 21 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLAnalyticsExperiment;

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
@property (assign) NSInteger appendNumber;
@property (copy) NSString *customDataSourceId;
@property (copy) NSString *date;
@property (copy) NSString *dimensions;
@property (copy) NSString *endDate;
@property (copy) NSString *experimentId;
@property (copy) NSString *filters;
@property (copy) NSString *ids;
@property (assign) NSInteger maxResults;
@property (copy) NSString *metrics;
@property (copy) NSString *profileId;
@property (copy) NSString *reportType;
@property (assign) BOOL reset;
@property (copy) NSString *segment;
@property (copy) NSString *sort;
@property (copy) NSString *startDate;
@property (assign) NSInteger startIndex;
@property (copy) NSString *type;
@property (copy) NSString *webPropertyId;

#pragma mark -
#pragma mark "data.ga" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.data.ga.get
// Returns Analytics data for a view (profile).
//  Required:
//   ids: Unique table ID for retrieving Analytics data. Table ID is of the form
//     ga:XXXX, where XXXX is the Analytics view (profile) ID.
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
//   kGTLAuthScopeAnalytics
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
// Returns Analytics Multi-Channel Funnels data for a view (profile).
//  Required:
//   ids: Unique table ID for retrieving Analytics data. Table ID is of the form
//     ga:XXXX, where XXXX is the Analytics view (profile) ID.
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
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsMcfData.
+ (id)queryForDataMcfGetWithIds:(NSString *)ids
                      startDate:(NSString *)startDate
                        endDate:(NSString *)endDate
                        metrics:(NSString *)metrics;

#pragma mark -
#pragma mark "data.realtime" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.data.realtime.get
// Returns real time data for a view (profile).
//  Required:
//   ids: Unique table ID for retrieving real time data. Table ID is of the form
//     ga:XXXX, where XXXX is the Analytics view (profile) ID.
//   metrics: A comma-separated list of real time metrics. E.g.,
//     'ga:activeVisitors'. At least one metric must be specified.
//  Optional:
//   dimensions: A comma-separated list of real time dimensions. E.g.,
//     'ga:medium,ga:city'.
//   filters: A comma-separated list of dimension or metric filters to be
//     applied to real time data.
//   maxResults: The maximum number of entries to include in this feed.
//   sort: A comma-separated list of dimensions or metrics that determine the
//     sort order for real time data.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsRealtimeData.
+ (id)queryForDataRealtimeGetWithIds:(NSString *)ids
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
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsAccounts.
+ (id)queryForManagementAccountsList;

#pragma mark -
#pragma mark "management.customDataSources" methods
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
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsCustomDataSources.
+ (id)queryForManagementCustomDataSourcesListWithAccountId:(NSString *)accountId
                                             webPropertyId:(NSString *)webPropertyId;

#pragma mark -
#pragma mark "management.dailyUploads" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.dailyUploads.delete
// Delete uploaded data for the given date.
//  Required:
//   accountId: Account Id associated with daily upload delete.
//   webPropertyId: Web property Id associated with daily upload delete.
//   customDataSourceId: Custom data source Id associated with daily upload
//     delete.
//   date: Date for which data is to be deleted. Date should be formatted as
//     YYYY-MM-DD.
//   type: Type of data for this delete.
//      kGTLAnalyticsTypeCost: Value for specifying cost data upload.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
+ (id)queryForManagementDailyUploadsDeleteWithAccountId:(NSString *)accountId
                                          webPropertyId:(NSString *)webPropertyId
                                     customDataSourceId:(NSString *)customDataSourceId
                                                   date:(NSString *)date
                                                   type:(NSString *)type;

// Method: analytics.management.dailyUploads.list
// List daily uploads to which the user has access.
//  Required:
//   accountId: Account Id for the daily uploads to retrieve.
//   webPropertyId: Web property Id for the daily uploads to retrieve.
//   customDataSourceId: Custom data source Id for daily uploads to retrieve.
//   startDate: Start date of the form YYYY-MM-DD.
//   endDate: End date of the form YYYY-MM-DD.
//  Optional:
//   maxResults: The maximum number of custom data sources to include in this
//     response.
//   startIndex: A 1-based index of the first daily upload to retrieve. Use this
//     parameter as a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsDailyUploads.
+ (id)queryForManagementDailyUploadsListWithAccountId:(NSString *)accountId
                                        webPropertyId:(NSString *)webPropertyId
                                   customDataSourceId:(NSString *)customDataSourceId
                                            startDate:(NSString *)startDate
                                              endDate:(NSString *)endDate;

// Method: analytics.management.dailyUploads.upload
// Update/Overwrite data for a custom data source.
//  Required:
//   accountId: Account Id associated with daily upload.
//   webPropertyId: Web property Id associated with daily upload.
//   customDataSourceId: Custom data source Id to which the data being uploaded
//     belongs.
//   date: Date for which data is uploaded. Date should be formatted as
//     YYYY-MM-DD.
//   appendNumber: Append number for this upload indexed from 1. (1..20)
//   type: Type of data for this upload.
//      kGTLAnalyticsTypeCost: Value for specifying cost data upload.
//  Optional:
//   reset: Reset/Overwrite all previous appends for this date and start over
//     with this file as the first upload. (Default false)
//  Upload Parameters:
//   Maximum size: 5MB
//   Accepted MIME type(s): application/octet-stream
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
// Fetches a GTLAnalyticsDailyUploadAppend.
+ (id)queryForManagementDailyUploadsUploadWithAccountId:(NSString *)accountId
                                          webPropertyId:(NSString *)webPropertyId
                                     customDataSourceId:(NSString *)customDataSourceId
                                                   date:(NSString *)date
                                           appendNumber:(NSInteger)appendNumber
                                                   type:(NSString *)type
                                       uploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

#pragma mark -
#pragma mark "management.experiments" methods
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
+ (id)queryForManagementExperimentsDeleteWithAccountId:(NSString *)accountId
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
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsExperiment.
+ (id)queryForManagementExperimentsGetWithAccountId:(NSString *)accountId
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
// Fetches a GTLAnalyticsExperiment.
+ (id)queryForManagementExperimentsInsertWithObject:(GTLAnalyticsExperiment *)object
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
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsExperiments.
+ (id)queryForManagementExperimentsListWithAccountId:(NSString *)accountId
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
// Fetches a GTLAnalyticsExperiment.
+ (id)queryForManagementExperimentsPatchWithObject:(GTLAnalyticsExperiment *)object
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
// Fetches a GTLAnalyticsExperiment.
+ (id)queryForManagementExperimentsUpdateWithObject:(GTLAnalyticsExperiment *)object
                                          accountId:(NSString *)accountId
                                      webPropertyId:(NSString *)webPropertyId
                                          profileId:(NSString *)profileId
                                       experimentId:(NSString *)experimentId;

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
//   profileId: View (Profile) ID to retrieve goals for. Can either be a
//     specific view (profile) ID or '~all', which refers to all the views
//     (profiles) that user has access to.
//  Optional:
//   maxResults: The maximum number of goals to include in this response.
//   startIndex: An index of the first goal to retrieve. Use this parameter as a
//     pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsGoals.
+ (id)queryForManagementGoalsListWithAccountId:(NSString *)accountId
                                 webPropertyId:(NSString *)webPropertyId
                                     profileId:(NSString *)profileId;

#pragma mark -
#pragma mark "management.profiles" methods
// These create a GTLQueryAnalytics object.

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
//   kGTLAuthScopeAnalytics
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
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsWebproperties.
+ (id)queryForManagementWebpropertiesListWithAccountId:(NSString *)accountId;

#pragma mark -
#pragma mark "metadata.columns" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.metadata.columns.list
// Lists all columns for a report type
//  Required:
//   reportType: Report type. Allowed Values: 'ga'. Where 'ga' corresponds to
//     the Core Reporting API
//  Authorization scope(s):
//   kGTLAuthScopeAnalytics
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsColumns.
+ (id)queryForMetadataColumnsListWithReportType:(NSString *)reportType;

@end
