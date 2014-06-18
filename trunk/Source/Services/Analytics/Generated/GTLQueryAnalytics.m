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
//  GTLQueryAnalytics.m
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
//   GTLQueryAnalytics (72 custom class methods, 30 custom properties)

#import "GTLQueryAnalytics.h"

#import "GTLAnalyticsAccounts.h"
#import "GTLAnalyticsAccountSummaries.h"
#import "GTLAnalyticsAccountTicket.h"
#import "GTLAnalyticsColumns.h"
#import "GTLAnalyticsCustomDataSources.h"
#import "GTLAnalyticsDailyUploadAppend.h"
#import "GTLAnalyticsDailyUploads.h"
#import "GTLAnalyticsEntityAdWordsLink.h"
#import "GTLAnalyticsEntityAdWordsLinks.h"
#import "GTLAnalyticsEntityUserLink.h"
#import "GTLAnalyticsEntityUserLinks.h"
#import "GTLAnalyticsExperiment.h"
#import "GTLAnalyticsExperiments.h"
#import "GTLAnalyticsFilter.h"
#import "GTLAnalyticsFilters.h"
#import "GTLAnalyticsGaData.h"
#import "GTLAnalyticsGoal.h"
#import "GTLAnalyticsGoals.h"
#import "GTLAnalyticsMcfData.h"
#import "GTLAnalyticsProfile.h"
#import "GTLAnalyticsProfileFilterLink.h"
#import "GTLAnalyticsProfileFilterLinks.h"
#import "GTLAnalyticsProfiles.h"
#import "GTLAnalyticsRealtimeData.h"
#import "GTLAnalyticsSegments.h"
#import "GTLAnalyticsUnsampledReport.h"
#import "GTLAnalyticsUnsampledReports.h"
#import "GTLAnalyticsUpload.h"
#import "GTLAnalyticsUploads.h"
#import "GTLAnalyticsWebproperties.h"
#import "GTLAnalyticsWebproperty.h"

@implementation GTLQueryAnalytics

@dynamic accountId, appendNumber, customDataImportUids, customDataSourceId,
         date, dimensions, endDate, experimentId, fields, filterId, filters,
         goalId, ids, linkId, maxResults, metrics, output, profileId,
         reportType, reset, samplingLevel, segment, sort, startDate, startIndex,
         type, unsampledReportId, uploadId, webPropertyAdWordsLinkId,
         webPropertyId;

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

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[NSString class]
                                forKey:@"customDataImportUids"];
  return map;
}

#pragma mark -
#pragma mark "data.ga" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForDataGaGetWithIds:(NSString *)ids
                     startDate:(NSString *)startDate
                       endDate:(NSString *)endDate
                       metrics:(NSString *)metrics {
  NSString *methodName = @"analytics.data.ga.get";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.ids = ids;
  query.startDate = startDate;
  query.endDate = endDate;
  query.metrics = metrics;
  query.expectedObjectClass = [GTLAnalyticsGaData class];
  return query;
}

#pragma mark -
#pragma mark "data.mcf" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForDataMcfGetWithIds:(NSString *)ids
                      startDate:(NSString *)startDate
                        endDate:(NSString *)endDate
                        metrics:(NSString *)metrics {
  NSString *methodName = @"analytics.data.mcf.get";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.ids = ids;
  query.startDate = startDate;
  query.endDate = endDate;
  query.metrics = metrics;
  query.expectedObjectClass = [GTLAnalyticsMcfData class];
  return query;
}

#pragma mark -
#pragma mark "data.realtime" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForDataRealtimeGetWithIds:(NSString *)ids
                             metrics:(NSString *)metrics {
  NSString *methodName = @"analytics.data.realtime.get";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.ids = ids;
  query.metrics = metrics;
  query.expectedObjectClass = [GTLAnalyticsRealtimeData class];
  return query;
}

#pragma mark -
#pragma mark "management.accounts" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementAccountsList {
  NSString *methodName = @"analytics.management.accounts.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAnalyticsAccounts class];
  return query;
}

#pragma mark -
#pragma mark "management.accountSummaries" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementAccountSummariesList {
  NSString *methodName = @"analytics.management.accountSummaries.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAnalyticsAccountSummaries class];
  return query;
}

#pragma mark -
#pragma mark "management.accountUserLinks" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementAccountUserLinksDeleteWithAccountId:(NSString *)accountId
                                                     linkId:(NSString *)linkId {
  NSString *methodName = @"analytics.management.accountUserLinks.delete";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.linkId = linkId;
  return query;
}

+ (id)queryForManagementAccountUserLinksInsertWithObject:(GTLAnalyticsEntityUserLink *)object
                                               accountId:(NSString *)accountId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.accountUserLinks.insert";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAnalyticsEntityUserLink class];
  return query;
}

+ (id)queryForManagementAccountUserLinksListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"analytics.management.accountUserLinks.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAnalyticsEntityUserLinks class];
  return query;
}

+ (id)queryForManagementAccountUserLinksUpdateWithObject:(GTLAnalyticsEntityUserLink *)object
                                               accountId:(NSString *)accountId
                                                  linkId:(NSString *)linkId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.accountUserLinks.update";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.linkId = linkId;
  query.expectedObjectClass = [GTLAnalyticsEntityUserLink class];
  return query;
}

#pragma mark -
#pragma mark "management.customDataSources" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementCustomDataSourcesListWithAccountId:(NSString *)accountId
                                             webPropertyId:(NSString *)webPropertyId {
  NSString *methodName = @"analytics.management.customDataSources.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.expectedObjectClass = [GTLAnalyticsCustomDataSources class];
  return query;
}

#pragma mark -
#pragma mark "management.dailyUploads" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementDailyUploadsDeleteWithAccountId:(NSString *)accountId
                                          webPropertyId:(NSString *)webPropertyId
                                     customDataSourceId:(NSString *)customDataSourceId
                                                   date:(NSString *)date
                                                   type:(NSString *)type {
  NSString *methodName = @"analytics.management.dailyUploads.delete";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.customDataSourceId = customDataSourceId;
  query.date = date;
  query.type = type;
  return query;
}

+ (id)queryForManagementDailyUploadsListWithAccountId:(NSString *)accountId
                                        webPropertyId:(NSString *)webPropertyId
                                   customDataSourceId:(NSString *)customDataSourceId
                                            startDate:(NSString *)startDate
                                              endDate:(NSString *)endDate {
  NSString *methodName = @"analytics.management.dailyUploads.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.customDataSourceId = customDataSourceId;
  query.startDate = startDate;
  query.endDate = endDate;
  query.expectedObjectClass = [GTLAnalyticsDailyUploads class];
  return query;
}

+ (id)queryForManagementDailyUploadsUploadWithAccountId:(NSString *)accountId
                                          webPropertyId:(NSString *)webPropertyId
                                     customDataSourceId:(NSString *)customDataSourceId
                                                   date:(NSString *)date
                                           appendNumber:(NSInteger)appendNumber
                                                   type:(NSString *)type
                                       uploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"analytics.management.dailyUploads.upload";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.customDataSourceId = customDataSourceId;
  query.date = date;
  query.appendNumber = appendNumber;
  query.type = type;
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLAnalyticsDailyUploadAppend class];
  return query;
}

#pragma mark -
#pragma mark "management.experiments" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementExperimentsDeleteWithAccountId:(NSString *)accountId
                                         webPropertyId:(NSString *)webPropertyId
                                             profileId:(NSString *)profileId
                                          experimentId:(NSString *)experimentId {
  NSString *methodName = @"analytics.management.experiments.delete";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.experimentId = experimentId;
  return query;
}

+ (id)queryForManagementExperimentsGetWithAccountId:(NSString *)accountId
                                      webPropertyId:(NSString *)webPropertyId
                                          profileId:(NSString *)profileId
                                       experimentId:(NSString *)experimentId {
  NSString *methodName = @"analytics.management.experiments.get";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.experimentId = experimentId;
  query.expectedObjectClass = [GTLAnalyticsExperiment class];
  return query;
}

+ (id)queryForManagementExperimentsInsertWithObject:(GTLAnalyticsExperiment *)object
                                          accountId:(NSString *)accountId
                                      webPropertyId:(NSString *)webPropertyId
                                          profileId:(NSString *)profileId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.experiments.insert";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.expectedObjectClass = [GTLAnalyticsExperiment class];
  return query;
}

+ (id)queryForManagementExperimentsListWithAccountId:(NSString *)accountId
                                       webPropertyId:(NSString *)webPropertyId
                                           profileId:(NSString *)profileId {
  NSString *methodName = @"analytics.management.experiments.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.expectedObjectClass = [GTLAnalyticsExperiments class];
  return query;
}

+ (id)queryForManagementExperimentsPatchWithObject:(GTLAnalyticsExperiment *)object
                                         accountId:(NSString *)accountId
                                     webPropertyId:(NSString *)webPropertyId
                                         profileId:(NSString *)profileId
                                      experimentId:(NSString *)experimentId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.experiments.patch";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.experimentId = experimentId;
  query.expectedObjectClass = [GTLAnalyticsExperiment class];
  return query;
}

+ (id)queryForManagementExperimentsUpdateWithObject:(GTLAnalyticsExperiment *)object
                                          accountId:(NSString *)accountId
                                      webPropertyId:(NSString *)webPropertyId
                                          profileId:(NSString *)profileId
                                       experimentId:(NSString *)experimentId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.experiments.update";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.experimentId = experimentId;
  query.expectedObjectClass = [GTLAnalyticsExperiment class];
  return query;
}

#pragma mark -
#pragma mark "management.filters" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementFiltersDeleteWithAccountId:(NSString *)accountId
                                          filterId:(NSString *)filterId {
  NSString *methodName = @"analytics.management.filters.delete";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.filterId = filterId;
  query.expectedObjectClass = [GTLAnalyticsFilter class];
  return query;
}

+ (id)queryForManagementFiltersGetWithAccountId:(NSString *)accountId
                                       filterId:(NSString *)filterId {
  NSString *methodName = @"analytics.management.filters.get";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.filterId = filterId;
  query.expectedObjectClass = [GTLAnalyticsFilter class];
  return query;
}

+ (id)queryForManagementFiltersInsertWithObject:(GTLAnalyticsFilter *)object
                                      accountId:(NSString *)accountId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.filters.insert";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAnalyticsFilter class];
  return query;
}

+ (id)queryForManagementFiltersListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"analytics.management.filters.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAnalyticsFilters class];
  return query;
}

+ (id)queryForManagementFiltersPatchWithObject:(GTLAnalyticsFilter *)object
                                     accountId:(NSString *)accountId
                                      filterId:(NSString *)filterId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.filters.patch";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.filterId = filterId;
  query.expectedObjectClass = [GTLAnalyticsFilter class];
  return query;
}

+ (id)queryForManagementFiltersUpdateWithObject:(GTLAnalyticsFilter *)object
                                      accountId:(NSString *)accountId
                                       filterId:(NSString *)filterId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.filters.update";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.filterId = filterId;
  query.expectedObjectClass = [GTLAnalyticsFilter class];
  return query;
}

#pragma mark -
#pragma mark "management.goals" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementGoalsGetWithAccountId:(NSString *)accountId
                                webPropertyId:(NSString *)webPropertyId
                                    profileId:(NSString *)profileId
                                       goalId:(NSString *)goalId {
  NSString *methodName = @"analytics.management.goals.get";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.goalId = goalId;
  query.expectedObjectClass = [GTLAnalyticsGoal class];
  return query;
}

+ (id)queryForManagementGoalsInsertWithObject:(GTLAnalyticsGoal *)object
                                    accountId:(NSString *)accountId
                                webPropertyId:(NSString *)webPropertyId
                                    profileId:(NSString *)profileId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.goals.insert";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.expectedObjectClass = [GTLAnalyticsGoal class];
  return query;
}

+ (id)queryForManagementGoalsListWithAccountId:(NSString *)accountId
                                 webPropertyId:(NSString *)webPropertyId
                                     profileId:(NSString *)profileId {
  NSString *methodName = @"analytics.management.goals.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.expectedObjectClass = [GTLAnalyticsGoals class];
  return query;
}

+ (id)queryForManagementGoalsPatchWithObject:(GTLAnalyticsGoal *)object
                                   accountId:(NSString *)accountId
                               webPropertyId:(NSString *)webPropertyId
                                   profileId:(NSString *)profileId
                                      goalId:(NSString *)goalId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.goals.patch";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.goalId = goalId;
  query.expectedObjectClass = [GTLAnalyticsGoal class];
  return query;
}

+ (id)queryForManagementGoalsUpdateWithObject:(GTLAnalyticsGoal *)object
                                    accountId:(NSString *)accountId
                                webPropertyId:(NSString *)webPropertyId
                                    profileId:(NSString *)profileId
                                       goalId:(NSString *)goalId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.goals.update";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.goalId = goalId;
  query.expectedObjectClass = [GTLAnalyticsGoal class];
  return query;
}

#pragma mark -
#pragma mark "management.profileFilterLinks" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementProfileFilterLinksDeleteWithAccountId:(NSString *)accountId
                                                webPropertyId:(NSString *)webPropertyId
                                                    profileId:(NSString *)profileId
                                                       linkId:(NSString *)linkId {
  NSString *methodName = @"analytics.management.profileFilterLinks.delete";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.linkId = linkId;
  return query;
}

+ (id)queryForManagementProfileFilterLinksGetWithAccountId:(NSString *)accountId
                                             webPropertyId:(NSString *)webPropertyId
                                                 profileId:(NSString *)profileId
                                                    linkId:(NSString *)linkId {
  NSString *methodName = @"analytics.management.profileFilterLinks.get";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.linkId = linkId;
  query.expectedObjectClass = [GTLAnalyticsProfileFilterLink class];
  return query;
}

+ (id)queryForManagementProfileFilterLinksInsertWithObject:(GTLAnalyticsProfileFilterLink *)object
                                                 accountId:(NSString *)accountId
                                             webPropertyId:(NSString *)webPropertyId
                                                 profileId:(NSString *)profileId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.profileFilterLinks.insert";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.expectedObjectClass = [GTLAnalyticsProfileFilterLink class];
  return query;
}

+ (id)queryForManagementProfileFilterLinksListWithAccountId:(NSString *)accountId
                                              webPropertyId:(NSString *)webPropertyId
                                                  profileId:(NSString *)profileId {
  NSString *methodName = @"analytics.management.profileFilterLinks.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.expectedObjectClass = [GTLAnalyticsProfileFilterLinks class];
  return query;
}

+ (id)queryForManagementProfileFilterLinksPatchWithObject:(GTLAnalyticsProfileFilterLink *)object
                                                accountId:(NSString *)accountId
                                            webPropertyId:(NSString *)webPropertyId
                                                profileId:(NSString *)profileId
                                                   linkId:(NSString *)linkId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.profileFilterLinks.patch";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.linkId = linkId;
  query.expectedObjectClass = [GTLAnalyticsProfileFilterLink class];
  return query;
}

+ (id)queryForManagementProfileFilterLinksUpdateWithObject:(GTLAnalyticsProfileFilterLink *)object
                                                 accountId:(NSString *)accountId
                                             webPropertyId:(NSString *)webPropertyId
                                                 profileId:(NSString *)profileId
                                                    linkId:(NSString *)linkId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.profileFilterLinks.update";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.linkId = linkId;
  query.expectedObjectClass = [GTLAnalyticsProfileFilterLink class];
  return query;
}

#pragma mark -
#pragma mark "management.profiles" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementProfilesDeleteWithAccountId:(NSString *)accountId
                                      webPropertyId:(NSString *)webPropertyId
                                          profileId:(NSString *)profileId {
  NSString *methodName = @"analytics.management.profiles.delete";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  return query;
}

+ (id)queryForManagementProfilesGetWithAccountId:(NSString *)accountId
                                   webPropertyId:(NSString *)webPropertyId
                                       profileId:(NSString *)profileId {
  NSString *methodName = @"analytics.management.profiles.get";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.expectedObjectClass = [GTLAnalyticsProfile class];
  return query;
}

+ (id)queryForManagementProfilesInsertWithObject:(GTLAnalyticsProfile *)object
                                       accountId:(NSString *)accountId
                                   webPropertyId:(NSString *)webPropertyId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.profiles.insert";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.expectedObjectClass = [GTLAnalyticsProfile class];
  return query;
}

+ (id)queryForManagementProfilesListWithAccountId:(NSString *)accountId
                                    webPropertyId:(NSString *)webPropertyId {
  NSString *methodName = @"analytics.management.profiles.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.expectedObjectClass = [GTLAnalyticsProfiles class];
  return query;
}

+ (id)queryForManagementProfilesPatchWithObject:(GTLAnalyticsProfile *)object
                                      accountId:(NSString *)accountId
                                  webPropertyId:(NSString *)webPropertyId
                                      profileId:(NSString *)profileId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.profiles.patch";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.expectedObjectClass = [GTLAnalyticsProfile class];
  return query;
}

+ (id)queryForManagementProfilesUpdateWithObject:(GTLAnalyticsProfile *)object
                                       accountId:(NSString *)accountId
                                   webPropertyId:(NSString *)webPropertyId
                                       profileId:(NSString *)profileId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.profiles.update";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.expectedObjectClass = [GTLAnalyticsProfile class];
  return query;
}

#pragma mark -
#pragma mark "management.profileUserLinks" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementProfileUserLinksDeleteWithAccountId:(NSString *)accountId
                                              webPropertyId:(NSString *)webPropertyId
                                                  profileId:(NSString *)profileId
                                                     linkId:(NSString *)linkId {
  NSString *methodName = @"analytics.management.profileUserLinks.delete";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.linkId = linkId;
  return query;
}

+ (id)queryForManagementProfileUserLinksInsertWithObject:(GTLAnalyticsEntityUserLink *)object
                                               accountId:(NSString *)accountId
                                           webPropertyId:(NSString *)webPropertyId
                                               profileId:(NSString *)profileId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.profileUserLinks.insert";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.expectedObjectClass = [GTLAnalyticsEntityUserLink class];
  return query;
}

+ (id)queryForManagementProfileUserLinksListWithAccountId:(NSString *)accountId
                                            webPropertyId:(NSString *)webPropertyId
                                                profileId:(NSString *)profileId {
  NSString *methodName = @"analytics.management.profileUserLinks.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.expectedObjectClass = [GTLAnalyticsEntityUserLinks class];
  return query;
}

+ (id)queryForManagementProfileUserLinksUpdateWithObject:(GTLAnalyticsEntityUserLink *)object
                                               accountId:(NSString *)accountId
                                           webPropertyId:(NSString *)webPropertyId
                                               profileId:(NSString *)profileId
                                                  linkId:(NSString *)linkId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.profileUserLinks.update";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.linkId = linkId;
  query.expectedObjectClass = [GTLAnalyticsEntityUserLink class];
  return query;
}

#pragma mark -
#pragma mark "management.segments" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementSegmentsList {
  NSString *methodName = @"analytics.management.segments.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAnalyticsSegments class];
  return query;
}

#pragma mark -
#pragma mark "management.unsampledReports" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementUnsampledReportsGetWithAccountId:(NSString *)accountId
                                           webPropertyId:(NSString *)webPropertyId
                                               profileId:(NSString *)profileId
                                       unsampledReportId:(NSString *)unsampledReportId {
  NSString *methodName = @"analytics.management.unsampledReports.get";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.unsampledReportId = unsampledReportId;
  query.expectedObjectClass = [GTLAnalyticsUnsampledReport class];
  return query;
}

+ (id)queryForManagementUnsampledReportsInsertWithObject:(GTLAnalyticsUnsampledReport *)object
                                               accountId:(NSString *)accountId
                                           webPropertyId:(NSString *)webPropertyId
                                               profileId:(NSString *)profileId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.unsampledReports.insert";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.expectedObjectClass = [GTLAnalyticsUnsampledReport class];
  return query;
}

+ (id)queryForManagementUnsampledReportsListWithAccountId:(NSString *)accountId
                                            webPropertyId:(NSString *)webPropertyId
                                                profileId:(NSString *)profileId {
  NSString *methodName = @"analytics.management.unsampledReports.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.profileId = profileId;
  query.expectedObjectClass = [GTLAnalyticsUnsampledReports class];
  return query;
}

#pragma mark -
#pragma mark "management.uploads" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementUploadsDeleteUploadDataWithAccountId:(NSString *)accountId
                                               webPropertyId:(NSString *)webPropertyId
                                          customDataSourceId:(NSString *)customDataSourceId {
  NSString *methodName = @"analytics.management.uploads.deleteUploadData";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.customDataSourceId = customDataSourceId;
  return query;
}

+ (id)queryForManagementUploadsGetWithAccountId:(NSString *)accountId
                                  webPropertyId:(NSString *)webPropertyId
                             customDataSourceId:(NSString *)customDataSourceId
                                       uploadId:(NSString *)uploadId {
  NSString *methodName = @"analytics.management.uploads.get";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.customDataSourceId = customDataSourceId;
  query.uploadId = uploadId;
  query.expectedObjectClass = [GTLAnalyticsUpload class];
  return query;
}

+ (id)queryForManagementUploadsListWithAccountId:(NSString *)accountId
                                   webPropertyId:(NSString *)webPropertyId
                              customDataSourceId:(NSString *)customDataSourceId {
  NSString *methodName = @"analytics.management.uploads.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.customDataSourceId = customDataSourceId;
  query.expectedObjectClass = [GTLAnalyticsUploads class];
  return query;
}

+ (id)queryForManagementUploadsMigrateDataImportWithAccountId:(NSString *)accountId
                                                webPropertyId:(NSString *)webPropertyId
                                           customDataSourceId:(NSString *)customDataSourceId {
  NSString *methodName = @"analytics.management.uploads.migrateDataImport";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.customDataSourceId = customDataSourceId;
  return query;
}

+ (id)queryForManagementUploadsUploadDataWithAccountId:(NSString *)accountId
                                         webPropertyId:(NSString *)webPropertyId
                                    customDataSourceId:(NSString *)customDataSourceId
                                      uploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"analytics.management.uploads.uploadData";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.customDataSourceId = customDataSourceId;
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLAnalyticsUpload class];
  return query;
}

#pragma mark -
#pragma mark "management.webproperties" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementWebpropertiesGetWithAccountId:(NSString *)accountId
                                        webPropertyId:(NSString *)webPropertyId {
  NSString *methodName = @"analytics.management.webproperties.get";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.expectedObjectClass = [GTLAnalyticsWebproperty class];
  return query;
}

+ (id)queryForManagementWebpropertiesInsertWithObject:(GTLAnalyticsWebproperty *)object
                                            accountId:(NSString *)accountId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.webproperties.insert";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAnalyticsWebproperty class];
  return query;
}

+ (id)queryForManagementWebpropertiesListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"analytics.management.webproperties.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAnalyticsWebproperties class];
  return query;
}

+ (id)queryForManagementWebpropertiesPatchWithObject:(GTLAnalyticsWebproperty *)object
                                           accountId:(NSString *)accountId
                                       webPropertyId:(NSString *)webPropertyId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.webproperties.patch";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.expectedObjectClass = [GTLAnalyticsWebproperty class];
  return query;
}

+ (id)queryForManagementWebpropertiesUpdateWithObject:(GTLAnalyticsWebproperty *)object
                                            accountId:(NSString *)accountId
                                        webPropertyId:(NSString *)webPropertyId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.webproperties.update";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.expectedObjectClass = [GTLAnalyticsWebproperty class];
  return query;
}

#pragma mark -
#pragma mark "management.webPropertyAdWordsLinks" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementWebPropertyAdWordsLinksDeleteWithAccountId:(NSString *)accountId
                                                     webPropertyId:(NSString *)webPropertyId
                                          webPropertyAdWordsLinkId:(NSString *)webPropertyAdWordsLinkId {
  NSString *methodName = @"analytics.management.webPropertyAdWordsLinks.delete";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.webPropertyAdWordsLinkId = webPropertyAdWordsLinkId;
  return query;
}

+ (id)queryForManagementWebPropertyAdWordsLinksGetWithAccountId:(NSString *)accountId
                                                  webPropertyId:(NSString *)webPropertyId
                                       webPropertyAdWordsLinkId:(NSString *)webPropertyAdWordsLinkId {
  NSString *methodName = @"analytics.management.webPropertyAdWordsLinks.get";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.webPropertyAdWordsLinkId = webPropertyAdWordsLinkId;
  query.expectedObjectClass = [GTLAnalyticsEntityAdWordsLink class];
  return query;
}

+ (id)queryForManagementWebPropertyAdWordsLinksInsertWithObject:(GTLAnalyticsEntityAdWordsLink *)object
                                                      accountId:(NSString *)accountId
                                                  webPropertyId:(NSString *)webPropertyId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.webPropertyAdWordsLinks.insert";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.expectedObjectClass = [GTLAnalyticsEntityAdWordsLink class];
  return query;
}

+ (id)queryForManagementWebPropertyAdWordsLinksListWithAccountId:(NSString *)accountId
                                                   webPropertyId:(NSString *)webPropertyId {
  NSString *methodName = @"analytics.management.webPropertyAdWordsLinks.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.expectedObjectClass = [GTLAnalyticsEntityAdWordsLinks class];
  return query;
}

+ (id)queryForManagementWebPropertyAdWordsLinksPatchWithObject:(GTLAnalyticsEntityAdWordsLink *)object
                                                     accountId:(NSString *)accountId
                                                 webPropertyId:(NSString *)webPropertyId
                                      webPropertyAdWordsLinkId:(NSString *)webPropertyAdWordsLinkId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.webPropertyAdWordsLinks.patch";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.webPropertyAdWordsLinkId = webPropertyAdWordsLinkId;
  query.expectedObjectClass = [GTLAnalyticsEntityAdWordsLink class];
  return query;
}

+ (id)queryForManagementWebPropertyAdWordsLinksUpdateWithObject:(GTLAnalyticsEntityAdWordsLink *)object
                                                      accountId:(NSString *)accountId
                                                  webPropertyId:(NSString *)webPropertyId
                                       webPropertyAdWordsLinkId:(NSString *)webPropertyAdWordsLinkId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.webPropertyAdWordsLinks.update";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.webPropertyAdWordsLinkId = webPropertyAdWordsLinkId;
  query.expectedObjectClass = [GTLAnalyticsEntityAdWordsLink class];
  return query;
}

#pragma mark -
#pragma mark "management.webpropertyUserLinks" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementWebpropertyUserLinksDeleteWithAccountId:(NSString *)accountId
                                                  webPropertyId:(NSString *)webPropertyId
                                                         linkId:(NSString *)linkId {
  NSString *methodName = @"analytics.management.webpropertyUserLinks.delete";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.linkId = linkId;
  return query;
}

+ (id)queryForManagementWebpropertyUserLinksInsertWithObject:(GTLAnalyticsEntityUserLink *)object
                                                   accountId:(NSString *)accountId
                                               webPropertyId:(NSString *)webPropertyId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.webpropertyUserLinks.insert";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.expectedObjectClass = [GTLAnalyticsEntityUserLink class];
  return query;
}

+ (id)queryForManagementWebpropertyUserLinksListWithAccountId:(NSString *)accountId
                                                webPropertyId:(NSString *)webPropertyId {
  NSString *methodName = @"analytics.management.webpropertyUserLinks.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.expectedObjectClass = [GTLAnalyticsEntityUserLinks class];
  return query;
}

+ (id)queryForManagementWebpropertyUserLinksUpdateWithObject:(GTLAnalyticsEntityUserLink *)object
                                                   accountId:(NSString *)accountId
                                               webPropertyId:(NSString *)webPropertyId
                                                      linkId:(NSString *)linkId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.management.webpropertyUserLinks.update";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.linkId = linkId;
  query.expectedObjectClass = [GTLAnalyticsEntityUserLink class];
  return query;
}

#pragma mark -
#pragma mark "metadata.columns" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForMetadataColumnsListWithReportType:(NSString *)reportType {
  NSString *methodName = @"analytics.metadata.columns.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.reportType = reportType;
  query.expectedObjectClass = [GTLAnalyticsColumns class];
  return query;
}

#pragma mark -
#pragma mark "provisioning" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForProvisioningCreateAccountTicketWithObject:(GTLAnalyticsAccountTicket *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"analytics.provisioning.createAccountTicket";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.expectedObjectClass = [GTLAnalyticsAccountTicket class];
  return query;
}

@end
