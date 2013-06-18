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
//  GTLQueryAdSense.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Management API (adsense/v1.3)
// Description:
//   Gives AdSense publishers access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://developers.google.com/adsense/management/
// Classes:
//   GTLQueryAdSense (34 custom class methods, 21 custom properties)

#import "GTLQueryAdSense.h"

#import "GTLAdSenseAccount.h"
#import "GTLAdSenseAccounts.h"
#import "GTLAdSenseAdClients.h"
#import "GTLAdSenseAdCode.h"
#import "GTLAdSenseAdsenseReportsGenerateResponse.h"
#import "GTLAdSenseAdUnit.h"
#import "GTLAdSenseAdUnits.h"
#import "GTLAdSenseAlerts.h"
#import "GTLAdSenseCustomChannel.h"
#import "GTLAdSenseCustomChannels.h"
#import "GTLAdSenseMetadata.h"
#import "GTLAdSenseSavedAdStyle.h"
#import "GTLAdSenseSavedAdStyles.h"
#import "GTLAdSenseSavedReports.h"
#import "GTLAdSenseUrlChannels.h"

@implementation GTLQueryAdSense

@dynamic accountId, adClientId, adUnitId, currency, customChannelId, dimension,
         endDate, fields, filter, includeInactive, locale, maxResults, metric,
         pageToken, savedAdStyleId, savedReportId, sort, startDate, startIndex,
         tree, useTimezoneReporting;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [NSString class], @"dimension",
      [NSString class], @"filter",
      [NSString class], @"metric",
      [NSString class], @"sort",
      nil];
  return map;
}

#pragma mark -
#pragma mark "accounts.adclients" methods
// These create a GTLQueryAdSense object.

+ (id)queryForAccountsAdclientsListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adsense.accounts.adclients.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdSenseAdClients class];
  return query;
}

#pragma mark -
#pragma mark "accounts.adunits.customchannels" methods
// These create a GTLQueryAdSense object.

+ (id)queryForAccountsAdunitsCustomchannelsListWithAccountId:(NSString *)accountId
                                                  adClientId:(NSString *)adClientId
                                                    adUnitId:(NSString *)adUnitId {
  NSString *methodName = @"adsense.accounts.adunits.customchannels.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdSenseCustomChannels class];
  return query;
}

#pragma mark -
#pragma mark "accounts.adunits" methods
// These create a GTLQueryAdSense object.

+ (id)queryForAccountsAdunitsGetWithAccountId:(NSString *)accountId
                                   adClientId:(NSString *)adClientId
                                     adUnitId:(NSString *)adUnitId {
  NSString *methodName = @"adsense.accounts.adunits.get";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdSenseAdUnit class];
  return query;
}

+ (id)queryForAccountsAdunitsGetAdCodeWithAccountId:(NSString *)accountId
                                         adClientId:(NSString *)adClientId
                                           adUnitId:(NSString *)adUnitId {
  NSString *methodName = @"adsense.accounts.adunits.getAdCode";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdSenseAdCode class];
  return query;
}

+ (id)queryForAccountsAdunitsListWithAccountId:(NSString *)accountId
                                    adClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.accounts.adunits.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseAdUnits class];
  return query;
}

#pragma mark -
#pragma mark "accounts.alerts" methods
// These create a GTLQueryAdSense object.

+ (id)queryForAccountsAlertsListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adsense.accounts.alerts.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdSenseAlerts class];
  return query;
}

#pragma mark -
#pragma mark "accounts.customchannels.adunits" methods
// These create a GTLQueryAdSense object.

+ (id)queryForAccountsCustomchannelsAdunitsListWithAccountId:(NSString *)accountId
                                                  adClientId:(NSString *)adClientId
                                             customChannelId:(NSString *)customChannelId {
  NSString *methodName = @"adsense.accounts.customchannels.adunits.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.customChannelId = customChannelId;
  query.expectedObjectClass = [GTLAdSenseAdUnits class];
  return query;
}

#pragma mark -
#pragma mark "accounts.customchannels" methods
// These create a GTLQueryAdSense object.

+ (id)queryForAccountsCustomchannelsGetWithAccountId:(NSString *)accountId
                                          adClientId:(NSString *)adClientId
                                     customChannelId:(NSString *)customChannelId {
  NSString *methodName = @"adsense.accounts.customchannels.get";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.customChannelId = customChannelId;
  query.expectedObjectClass = [GTLAdSenseCustomChannel class];
  return query;
}

+ (id)queryForAccountsCustomchannelsListWithAccountId:(NSString *)accountId
                                           adClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.accounts.customchannels.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseCustomChannels class];
  return query;
}

#pragma mark -
#pragma mark "accounts" methods
// These create a GTLQueryAdSense object.

+ (id)queryForAccountsGetWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adsense.accounts.get";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdSenseAccount class];
  return query;
}

+ (id)queryForAccountsList {
  NSString *methodName = @"adsense.accounts.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdSenseAccounts class];
  return query;
}

#pragma mark -
#pragma mark "accounts.reports" methods
// These create a GTLQueryAdSense object.

+ (id)queryForAccountsReportsGenerateWithAccountId:(NSString *)accountId
                                         startDate:(NSString *)startDate
                                           endDate:(NSString *)endDate {
  NSString *methodName = @"adsense.accounts.reports.generate";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.startDate = startDate;
  query.endDate = endDate;
  query.expectedObjectClass = [GTLAdSenseAdsenseReportsGenerateResponse class];
  return query;
}

#pragma mark -
#pragma mark "accounts.reports.saved" methods
// These create a GTLQueryAdSense object.

+ (id)queryForAccountsReportsSavedGenerateWithAccountId:(NSString *)accountId
                                          savedReportId:(NSString *)savedReportId {
  NSString *methodName = @"adsense.accounts.reports.saved.generate";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.savedReportId = savedReportId;
  query.expectedObjectClass = [GTLAdSenseAdsenseReportsGenerateResponse class];
  return query;
}

+ (id)queryForAccountsReportsSavedListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adsense.accounts.reports.saved.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdSenseSavedReports class];
  return query;
}

#pragma mark -
#pragma mark "accounts.savedadstyles" methods
// These create a GTLQueryAdSense object.

+ (id)queryForAccountsSavedadstylesGetWithAccountId:(NSString *)accountId
                                     savedAdStyleId:(NSString *)savedAdStyleId {
  NSString *methodName = @"adsense.accounts.savedadstyles.get";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.savedAdStyleId = savedAdStyleId;
  query.expectedObjectClass = [GTLAdSenseSavedAdStyle class];
  return query;
}

+ (id)queryForAccountsSavedadstylesListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adsense.accounts.savedadstyles.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdSenseSavedAdStyles class];
  return query;
}

#pragma mark -
#pragma mark "accounts.urlchannels" methods
// These create a GTLQueryAdSense object.

+ (id)queryForAccountsUrlchannelsListWithAccountId:(NSString *)accountId
                                        adClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.accounts.urlchannels.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseUrlChannels class];
  return query;
}

#pragma mark -
#pragma mark "adclients" methods
// These create a GTLQueryAdSense object.

+ (id)queryForAdclientsList {
  NSString *methodName = @"adsense.adclients.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdSenseAdClients class];
  return query;
}

#pragma mark -
#pragma mark "adunits.customchannels" methods
// These create a GTLQueryAdSense object.

+ (id)queryForAdunitsCustomchannelsListWithAdClientId:(NSString *)adClientId
                                             adUnitId:(NSString *)adUnitId {
  NSString *methodName = @"adsense.adunits.customchannels.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdSenseCustomChannels class];
  return query;
}

#pragma mark -
#pragma mark "adunits" methods
// These create a GTLQueryAdSense object.

+ (id)queryForAdunitsGetWithAdClientId:(NSString *)adClientId
                              adUnitId:(NSString *)adUnitId {
  NSString *methodName = @"adsense.adunits.get";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdSenseAdUnit class];
  return query;
}

+ (id)queryForAdunitsGetAdCodeWithAdClientId:(NSString *)adClientId
                                    adUnitId:(NSString *)adUnitId {
  NSString *methodName = @"adsense.adunits.getAdCode";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdSenseAdCode class];
  return query;
}

+ (id)queryForAdunitsListWithAdClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.adunits.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseAdUnits class];
  return query;
}

#pragma mark -
#pragma mark "alerts" methods
// These create a GTLQueryAdSense object.

+ (id)queryForAlertsList {
  NSString *methodName = @"adsense.alerts.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdSenseAlerts class];
  return query;
}

#pragma mark -
#pragma mark "customchannels.adunits" methods
// These create a GTLQueryAdSense object.

+ (id)queryForCustomchannelsAdunitsListWithAdClientId:(NSString *)adClientId
                                      customChannelId:(NSString *)customChannelId {
  NSString *methodName = @"adsense.customchannels.adunits.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.customChannelId = customChannelId;
  query.expectedObjectClass = [GTLAdSenseAdUnits class];
  return query;
}

#pragma mark -
#pragma mark "customchannels" methods
// These create a GTLQueryAdSense object.

+ (id)queryForCustomchannelsGetWithAdClientId:(NSString *)adClientId
                              customChannelId:(NSString *)customChannelId {
  NSString *methodName = @"adsense.customchannels.get";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.customChannelId = customChannelId;
  query.expectedObjectClass = [GTLAdSenseCustomChannel class];
  return query;
}

+ (id)queryForCustomchannelsListWithAdClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.customchannels.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseCustomChannels class];
  return query;
}

#pragma mark -
#pragma mark "metadata.dimensions" methods
// These create a GTLQueryAdSense object.

+ (id)queryForMetadataDimensionsList {
  NSString *methodName = @"adsense.metadata.dimensions.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdSenseMetadata class];
  return query;
}

#pragma mark -
#pragma mark "metadata.metrics" methods
// These create a GTLQueryAdSense object.

+ (id)queryForMetadataMetricsList {
  NSString *methodName = @"adsense.metadata.metrics.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdSenseMetadata class];
  return query;
}

#pragma mark -
#pragma mark "reports" methods
// These create a GTLQueryAdSense object.

+ (id)queryForReportsGenerateWithStartDate:(NSString *)startDate
                                   endDate:(NSString *)endDate {
  NSString *methodName = @"adsense.reports.generate";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.startDate = startDate;
  query.endDate = endDate;
  query.expectedObjectClass = [GTLAdSenseAdsenseReportsGenerateResponse class];
  return query;
}

#pragma mark -
#pragma mark "reports.saved" methods
// These create a GTLQueryAdSense object.

+ (id)queryForReportsSavedGenerateWithSavedReportId:(NSString *)savedReportId {
  NSString *methodName = @"adsense.reports.saved.generate";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.savedReportId = savedReportId;
  query.expectedObjectClass = [GTLAdSenseAdsenseReportsGenerateResponse class];
  return query;
}

+ (id)queryForReportsSavedList {
  NSString *methodName = @"adsense.reports.saved.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdSenseSavedReports class];
  return query;
}

#pragma mark -
#pragma mark "savedadstyles" methods
// These create a GTLQueryAdSense object.

+ (id)queryForSavedadstylesGetWithSavedAdStyleId:(NSString *)savedAdStyleId {
  NSString *methodName = @"adsense.savedadstyles.get";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.savedAdStyleId = savedAdStyleId;
  query.expectedObjectClass = [GTLAdSenseSavedAdStyle class];
  return query;
}

+ (id)queryForSavedadstylesList {
  NSString *methodName = @"adsense.savedadstyles.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdSenseSavedAdStyles class];
  return query;
}

#pragma mark -
#pragma mark "urlchannels" methods
// These create a GTLQueryAdSense object.

+ (id)queryForUrlchannelsListWithAdClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.urlchannels.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseUrlChannels class];
  return query;
}

@end
