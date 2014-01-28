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
//   GTLQueryAnalytics (48 custom class methods, 27 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLAnalyticsEntityUserLink;
@class GTLAnalyticsExperiment;
@class GTLAnalyticsGoal;
@class GTLAnalyticsProfile;
@class GTLAnalyticsWebproperty;

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
@property (retain) NSArray *customDataImportUids;  // of NSString
@property (copy) NSString *customDataSourceId;
@property (copy) NSString *date;
@property (copy) NSString *dimensions;
@property (copy) NSString *endDate;
@property (copy) NSString *experimentId;
@property (copy) NSString *filters;
@property (copy) NSString *goalId;
@property (copy) NSString *ids;
@property (copy) NSString *linkId;
@property (assign) NSInteger maxResults;
@property (copy) NSString *metrics;
@property (copy) NSString *output;
@property (copy) NSString *profileId;
@property (copy) NSString *reportType;
@property (assign) BOOL reset;
@property (copy) NSString *samplingLevel;
@property (copy) NSString *segment;
@property (copy) NSString *sort;
@property (copy) NSString *startDate;
@property (assign) NSInteger startIndex;
@property (copy) NSString *type;
@property (copy) NSString *uploadId;
@property (copy) NSString *webPropertyId;

#pragma mark -
#pragma mark "data.ga" methods
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
//     'ga:visits,ga:pageviews'. At least one metric must be specified.
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
//     'rt:activeVisitors'. At least one metric must be specified.
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
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsAccounts.
+ (id)queryForManagementAccountsList;

#pragma mark -
#pragma mark "management.accountUserLinks" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.accountUserLinks.delete
// Removes a user from the given account.
//  Required:
//   accountId: Account ID to delete the user link for.
//   linkId: Link ID to delete the user link for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
+ (id)queryForManagementAccountUserLinksDeleteWithAccountId:(NSString *)accountId
                                                     linkId:(NSString *)linkId;

// Method: analytics.management.accountUserLinks.insert
// Adds a new user to the given account.
//  Required:
//   accountId: Account ID to create the user link for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
// Fetches a GTLAnalyticsEntityUserLink.
+ (id)queryForManagementAccountUserLinksInsertWithObject:(GTLAnalyticsEntityUserLink *)object
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
// Fetches a GTLAnalyticsEntityUserLinks.
+ (id)queryForManagementAccountUserLinksListWithAccountId:(NSString *)accountId;

// Method: analytics.management.accountUserLinks.update
// Updates permissions for an existing user on the given account.
//  Required:
//   accountId: Account ID to update the account-user link for.
//   linkId: Link ID to update the account-user link for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
// Fetches a GTLAnalyticsEntityUserLink.
+ (id)queryForManagementAccountUserLinksUpdateWithObject:(GTLAnalyticsEntityUserLink *)object
                                               accountId:(NSString *)accountId
                                                  linkId:(NSString *)linkId;

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
//   kGTLAuthScopeAnalyticsEdit
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
//   kGTLAuthScopeAnalyticsEdit
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
//   kGTLAuthScopeAnalyticsEdit
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
//   kGTLAuthScopeAnalyticsEdit
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
//   kGTLAuthScopeAnalyticsEdit
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
//   kGTLAuthScopeAnalyticsEdit
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
//   kGTLAuthScopeAnalyticsEdit
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
//   kGTLAuthScopeAnalyticsEdit
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
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsExperiment.
+ (id)queryForManagementExperimentsUpdateWithObject:(GTLAnalyticsExperiment *)object
                                          accountId:(NSString *)accountId
                                      webPropertyId:(NSString *)webPropertyId
                                          profileId:(NSString *)profileId
                                       experimentId:(NSString *)experimentId;

#pragma mark -
#pragma mark "management.goals" methods
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
+ (id)queryForManagementGoalsGetWithAccountId:(NSString *)accountId
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
+ (id)queryForManagementGoalsInsertWithObject:(GTLAnalyticsGoal *)object
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
+ (id)queryForManagementGoalsListWithAccountId:(NSString *)accountId
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
+ (id)queryForManagementGoalsPatchWithObject:(GTLAnalyticsGoal *)object
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
+ (id)queryForManagementGoalsUpdateWithObject:(GTLAnalyticsGoal *)object
                                    accountId:(NSString *)accountId
                                webPropertyId:(NSString *)webPropertyId
                                    profileId:(NSString *)profileId
                                       goalId:(NSString *)goalId;

#pragma mark -
#pragma mark "management.profiles" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.profiles.delete
// Deletes a view (profile).
//  Required:
//   accountId: Account ID to delete the view (profile) for.
//   webPropertyId: Web property ID to delete the view (profile) for.
//   profileId: ID of the view (profile) to be deleted.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
+ (id)queryForManagementProfilesDeleteWithAccountId:(NSString *)accountId
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
+ (id)queryForManagementProfilesGetWithAccountId:(NSString *)accountId
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
+ (id)queryForManagementProfilesInsertWithObject:(GTLAnalyticsProfile *)object
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
+ (id)queryForManagementProfilesListWithAccountId:(NSString *)accountId
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
+ (id)queryForManagementProfilesPatchWithObject:(GTLAnalyticsProfile *)object
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
+ (id)queryForManagementProfilesUpdateWithObject:(GTLAnalyticsProfile *)object
                                       accountId:(NSString *)accountId
                                   webPropertyId:(NSString *)webPropertyId
                                       profileId:(NSString *)profileId;

#pragma mark -
#pragma mark "management.profileUserLinks" methods
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
+ (id)queryForManagementProfileUserLinksDeleteWithAccountId:(NSString *)accountId
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
+ (id)queryForManagementProfileUserLinksInsertWithObject:(GTLAnalyticsEntityUserLink *)object
                                               accountId:(NSString *)accountId
                                           webPropertyId:(NSString *)webPropertyId
                                               profileId:(NSString *)profileId;

// Method: analytics.management.profileUserLinks.list
// Lists profile-user links for a given view (profile).
//  Required:
//   accountId: Account ID which the given view (profile) belongs to.
//   webPropertyId: Web Property ID which the given view (profile) belongs to.
//   profileId: View (Profile) ID to retrieve the profile-user links for
//  Optional:
//   maxResults: The maximum number of profile-user links to include in this
//     response.
//   startIndex: An index of the first profile-user link to retrieve. Use this
//     parameter as a pagination mechanism along with the max-results parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
// Fetches a GTLAnalyticsEntityUserLinks.
+ (id)queryForManagementProfileUserLinksListWithAccountId:(NSString *)accountId
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
+ (id)queryForManagementProfileUserLinksUpdateWithObject:(GTLAnalyticsEntityUserLink *)object
                                               accountId:(NSString *)accountId
                                           webPropertyId:(NSString *)webPropertyId
                                               profileId:(NSString *)profileId
                                                  linkId:(NSString *)linkId;

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
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsSegments.
+ (id)queryForManagementSegmentsList;

#pragma mark -
#pragma mark "management.uploads" methods
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
+ (id)queryForManagementUploadsDeleteUploadDataWithAccountId:(NSString *)accountId
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
+ (id)queryForManagementUploadsGetWithAccountId:(NSString *)accountId
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
+ (id)queryForManagementUploadsListWithAccountId:(NSString *)accountId
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
+ (id)queryForManagementUploadsUploadDataWithAccountId:(NSString *)accountId
                                         webPropertyId:(NSString *)webPropertyId
                                    customDataSourceId:(NSString *)customDataSourceId
                                      uploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

#pragma mark -
#pragma mark "management.webproperties" methods
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
+ (id)queryForManagementWebpropertiesGetWithAccountId:(NSString *)accountId
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
+ (id)queryForManagementWebpropertiesInsertWithObject:(GTLAnalyticsWebproperty *)object
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
+ (id)queryForManagementWebpropertiesListWithAccountId:(NSString *)accountId;

// Method: analytics.management.webproperties.patch
// Updates an existing web property. This method supports patch semantics.
//  Required:
//   accountId: Account ID to which the web property belongs
//   webPropertyId: Web property ID
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsEdit
// Fetches a GTLAnalyticsWebproperty.
+ (id)queryForManagementWebpropertiesPatchWithObject:(GTLAnalyticsWebproperty *)object
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
+ (id)queryForManagementWebpropertiesUpdateWithObject:(GTLAnalyticsWebproperty *)object
                                            accountId:(NSString *)accountId
                                        webPropertyId:(NSString *)webPropertyId;

#pragma mark -
#pragma mark "management.webpropertyUserLinks" methods
// These create a GTLQueryAnalytics object.

// Method: analytics.management.webpropertyUserLinks.delete
// Removes a user from the given web property.
//  Required:
//   accountId: Account ID to delete the user link for.
//   webPropertyId: Web Property ID to delete the user link for.
//   linkId: Link ID to delete the user link for.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
+ (id)queryForManagementWebpropertyUserLinksDeleteWithAccountId:(NSString *)accountId
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
+ (id)queryForManagementWebpropertyUserLinksInsertWithObject:(GTLAnalyticsEntityUserLink *)object
                                                   accountId:(NSString *)accountId
                                               webPropertyId:(NSString *)webPropertyId;

// Method: analytics.management.webpropertyUserLinks.list
// Lists webProperty-user links for a given web property.
//  Required:
//   accountId: Account ID which the given web property belongs to.
//   webPropertyId: Web Property ID for the webProperty-user links to retrieve.
//  Optional:
//   maxResults: The maximum number of webProperty-user Links to include in this
//     response.
//   startIndex: An index of the first webProperty-user link to retrieve. Use
//     this parameter as a pagination mechanism along with the max-results
//     parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAnalyticsManageUsers
// Fetches a GTLAnalyticsEntityUserLinks.
+ (id)queryForManagementWebpropertyUserLinksListWithAccountId:(NSString *)accountId
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
+ (id)queryForManagementWebpropertyUserLinksUpdateWithObject:(GTLAnalyticsEntityUserLink *)object
                                                   accountId:(NSString *)accountId
                                               webPropertyId:(NSString *)webPropertyId
                                                      linkId:(NSString *)linkId;

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
//   kGTLAuthScopeAnalyticsEdit
//   kGTLAuthScopeAnalyticsReadonly
// Fetches a GTLAnalyticsColumns.
+ (id)queryForMetadataColumnsListWithReportType:(NSString *)reportType;

@end
