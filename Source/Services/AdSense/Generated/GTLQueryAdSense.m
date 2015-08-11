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
//  GTLQueryAdSense.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Management API (adsense/v1.4)
// Description:
//   Gives AdSense publishers access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://developers.google.com/adsense/management/
// Classes:
//   GTLQueryAdSense (38 custom class methods, 22 custom properties)

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
#import "GTLAdSensePayments.h"
#import "GTLAdSenseSavedAdStyle.h"
#import "GTLAdSenseSavedAdStyles.h"
#import "GTLAdSenseSavedReports.h"
#import "GTLAdSenseUrlChannels.h"

@implementation GTLQueryAdSense

@dynamic accountId, adClientId, adUnitId, alertId, currency, customChannelId,
         dimension, endDate, fields, filter, includeInactive, locale,
         maxResults, metric, pageToken, savedAdStyleId, savedReportId, sort,
         startDate, startIndex, tree, useTimezoneReporting;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"dimension" : [NSString class],
    @"filter" : [NSString class],
    @"metric" : [NSString class],
    @"sort" : [NSString class]
  };
  return map;
}

#pragma mark - "accounts.adclients" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForAccountsAdclientsListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adsense.accounts.adclients.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdSenseAdClients class];
  return query;
}

#pragma mark - "accounts.adunits.customchannels" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForAccountsAdunitsCustomchannelsListWithAccountId:(NSString *)accountId
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

#pragma mark - "accounts.adunits" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForAccountsAdunitsGetWithAccountId:(NSString *)accountId
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

+ (instancetype)queryForAccountsAdunitsGetAdCodeWithAccountId:(NSString *)accountId
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

+ (instancetype)queryForAccountsAdunitsListWithAccountId:(NSString *)accountId
                                              adClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.accounts.adunits.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseAdUnits class];
  return query;
}

#pragma mark - "accounts.alerts" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForAccountsAlertsDeleteWithAccountId:(NSString *)accountId
                                                  alertId:(NSString *)alertId {
  NSString *methodName = @"adsense.accounts.alerts.delete";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.alertId = alertId;
  return query;
}

+ (instancetype)queryForAccountsAlertsListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adsense.accounts.alerts.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdSenseAlerts class];
  return query;
}

#pragma mark - "accounts.customchannels.adunits" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForAccountsCustomchannelsAdunitsListWithAccountId:(NSString *)accountId
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

#pragma mark - "accounts.customchannels" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForAccountsCustomchannelsGetWithAccountId:(NSString *)accountId
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

+ (instancetype)queryForAccountsCustomchannelsListWithAccountId:(NSString *)accountId
                                                     adClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.accounts.customchannels.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseCustomChannels class];
  return query;
}

#pragma mark - "accounts" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForAccountsGetWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adsense.accounts.get";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdSenseAccount class];
  return query;
}

+ (instancetype)queryForAccountsList {
  NSString *methodName = @"adsense.accounts.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdSenseAccounts class];
  return query;
}

#pragma mark - "accounts.payments" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForAccountsPaymentsListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adsense.accounts.payments.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdSensePayments class];
  return query;
}

#pragma mark - "accounts.reports" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForAccountsReportsGenerateWithAccountId:(NSString *)accountId
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

#pragma mark - "accounts.reports.saved" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForAccountsReportsSavedGenerateWithAccountId:(NSString *)accountId
                                                    savedReportId:(NSString *)savedReportId {
  NSString *methodName = @"adsense.accounts.reports.saved.generate";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.savedReportId = savedReportId;
  query.expectedObjectClass = [GTLAdSenseAdsenseReportsGenerateResponse class];
  return query;
}

+ (instancetype)queryForAccountsReportsSavedListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adsense.accounts.reports.saved.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdSenseSavedReports class];
  return query;
}

#pragma mark - "accounts.savedadstyles" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForAccountsSavedadstylesGetWithAccountId:(NSString *)accountId
                                               savedAdStyleId:(NSString *)savedAdStyleId {
  NSString *methodName = @"adsense.accounts.savedadstyles.get";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.savedAdStyleId = savedAdStyleId;
  query.expectedObjectClass = [GTLAdSenseSavedAdStyle class];
  return query;
}

+ (instancetype)queryForAccountsSavedadstylesListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adsense.accounts.savedadstyles.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdSenseSavedAdStyles class];
  return query;
}

#pragma mark - "accounts.urlchannels" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForAccountsUrlchannelsListWithAccountId:(NSString *)accountId
                                                  adClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.accounts.urlchannels.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseUrlChannels class];
  return query;
}

#pragma mark - "adclients" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForAdclientsList {
  NSString *methodName = @"adsense.adclients.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdSenseAdClients class];
  return query;
}

#pragma mark - "adunits.customchannels" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForAdunitsCustomchannelsListWithAdClientId:(NSString *)adClientId
                                                       adUnitId:(NSString *)adUnitId {
  NSString *methodName = @"adsense.adunits.customchannels.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdSenseCustomChannels class];
  return query;
}

#pragma mark - "adunits" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForAdunitsGetWithAdClientId:(NSString *)adClientId
                                        adUnitId:(NSString *)adUnitId {
  NSString *methodName = @"adsense.adunits.get";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdSenseAdUnit class];
  return query;
}

+ (instancetype)queryForAdunitsGetAdCodeWithAdClientId:(NSString *)adClientId
                                              adUnitId:(NSString *)adUnitId {
  NSString *methodName = @"adsense.adunits.getAdCode";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdSenseAdCode class];
  return query;
}

+ (instancetype)queryForAdunitsListWithAdClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.adunits.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseAdUnits class];
  return query;
}

#pragma mark - "alerts" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForAlertsDeleteWithAlertId:(NSString *)alertId {
  NSString *methodName = @"adsense.alerts.delete";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.alertId = alertId;
  return query;
}

+ (instancetype)queryForAlertsList {
  NSString *methodName = @"adsense.alerts.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdSenseAlerts class];
  return query;
}

#pragma mark - "customchannels.adunits" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForCustomchannelsAdunitsListWithAdClientId:(NSString *)adClientId
                                                customChannelId:(NSString *)customChannelId {
  NSString *methodName = @"adsense.customchannels.adunits.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.customChannelId = customChannelId;
  query.expectedObjectClass = [GTLAdSenseAdUnits class];
  return query;
}

#pragma mark - "customchannels" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForCustomchannelsGetWithAdClientId:(NSString *)adClientId
                                        customChannelId:(NSString *)customChannelId {
  NSString *methodName = @"adsense.customchannels.get";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.customChannelId = customChannelId;
  query.expectedObjectClass = [GTLAdSenseCustomChannel class];
  return query;
}

+ (instancetype)queryForCustomchannelsListWithAdClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.customchannels.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseCustomChannels class];
  return query;
}

#pragma mark - "metadata.dimensions" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForMetadataDimensionsList {
  NSString *methodName = @"adsense.metadata.dimensions.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdSenseMetadata class];
  return query;
}

#pragma mark - "metadata.metrics" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForMetadataMetricsList {
  NSString *methodName = @"adsense.metadata.metrics.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdSenseMetadata class];
  return query;
}

#pragma mark - "payments" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForPaymentsList {
  NSString *methodName = @"adsense.payments.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdSensePayments class];
  return query;
}

#pragma mark - "reports" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForReportsGenerateWithStartDate:(NSString *)startDate
                                             endDate:(NSString *)endDate {
  NSString *methodName = @"adsense.reports.generate";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.startDate = startDate;
  query.endDate = endDate;
  query.expectedObjectClass = [GTLAdSenseAdsenseReportsGenerateResponse class];
  return query;
}

#pragma mark - "reports.saved" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForReportsSavedGenerateWithSavedReportId:(NSString *)savedReportId {
  NSString *methodName = @"adsense.reports.saved.generate";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.savedReportId = savedReportId;
  query.expectedObjectClass = [GTLAdSenseAdsenseReportsGenerateResponse class];
  return query;
}

+ (instancetype)queryForReportsSavedList {
  NSString *methodName = @"adsense.reports.saved.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdSenseSavedReports class];
  return query;
}

#pragma mark - "savedadstyles" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForSavedadstylesGetWithSavedAdStyleId:(NSString *)savedAdStyleId {
  NSString *methodName = @"adsense.savedadstyles.get";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.savedAdStyleId = savedAdStyleId;
  query.expectedObjectClass = [GTLAdSenseSavedAdStyle class];
  return query;
}

+ (instancetype)queryForSavedadstylesList {
  NSString *methodName = @"adsense.savedadstyles.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdSenseSavedAdStyles class];
  return query;
}

#pragma mark - "urlchannels" methods
// These create a GTLQueryAdSense object.

+ (instancetype)queryForUrlchannelsListWithAdClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.urlchannels.list";
  GTLQueryAdSense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseUrlChannels class];
  return query;
}

@end
