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
//   GTLQueryAnalytics (11 custom class methods, 19 custom properties)

#import "GTLQueryAnalytics.h"

#import "GTLAnalyticsAccounts.h"
#import "GTLAnalyticsCustomDataSources.h"
#import "GTLAnalyticsDailyUploadAppend.h"
#import "GTLAnalyticsDailyUploads.h"
#import "GTLAnalyticsGaData.h"
#import "GTLAnalyticsGoals.h"
#import "GTLAnalyticsMcfData.h"
#import "GTLAnalyticsProfiles.h"
#import "GTLAnalyticsSegments.h"
#import "GTLAnalyticsWebproperties.h"

@implementation GTLQueryAnalytics

@dynamic accountId, appendNumber, customDataSourceId, date, dimensions, endDate,
         fields, filters, ids, maxResults, metrics, profileId, reset, segment,
         sort, startDate, startIndex, type, webPropertyId;

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
#pragma mark "management.accounts" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementAccountsList {
  NSString *methodName = @"analytics.management.accounts.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAnalyticsAccounts class];
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
#pragma mark "management.goals" methods
// These create a GTLQueryAnalytics object.

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

#pragma mark -
#pragma mark "management.profiles" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementProfilesListWithAccountId:(NSString *)accountId
                                    webPropertyId:(NSString *)webPropertyId {
  NSString *methodName = @"analytics.management.profiles.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.webPropertyId = webPropertyId;
  query.expectedObjectClass = [GTLAnalyticsProfiles class];
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
#pragma mark "management.webproperties" methods
// These create a GTLQueryAnalytics object.

+ (id)queryForManagementWebpropertiesListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"analytics.management.webproperties.list";
  GTLQueryAnalytics *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAnalyticsWebproperties class];
  return query;
}

@end
