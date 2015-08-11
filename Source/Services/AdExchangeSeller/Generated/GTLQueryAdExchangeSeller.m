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
//  GTLQueryAdExchangeSeller.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Ad Exchange Seller API (adexchangeseller/v2.0)
// Description:
//   Gives Ad Exchange seller users access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://developers.google.com/ad-exchange/seller-rest/
// Classes:
//   GTLQueryAdExchangeSeller (14 custom class methods, 16 custom properties)

#import "GTLQueryAdExchangeSeller.h"

#import "GTLAdExchangeSellerAccount.h"
#import "GTLAdExchangeSellerAccounts.h"
#import "GTLAdExchangeSellerAdClients.h"
#import "GTLAdExchangeSellerAlerts.h"
#import "GTLAdExchangeSellerCustomChannel.h"
#import "GTLAdExchangeSellerCustomChannels.h"
#import "GTLAdExchangeSellerMetadata.h"
#import "GTLAdExchangeSellerPreferredDeal.h"
#import "GTLAdExchangeSellerPreferredDeals.h"
#import "GTLAdExchangeSellerReport.h"
#import "GTLAdExchangeSellerSavedReports.h"
#import "GTLAdExchangeSellerUrlChannels.h"

@implementation GTLQueryAdExchangeSeller

@dynamic accountId, adClientId, customChannelId, dealId, dimension, endDate,
         fields, filter, locale, maxResults, metric, pageToken, savedReportId,
         sort, startDate, startIndex;

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
// These create a GTLQueryAdExchangeSeller object.

+ (instancetype)queryForAccountsAdclientsListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adexchangeseller.accounts.adclients.list";
  GTLQueryAdExchangeSeller *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdExchangeSellerAdClients class];
  return query;
}

#pragma mark - "accounts.alerts" methods
// These create a GTLQueryAdExchangeSeller object.

+ (instancetype)queryForAccountsAlertsListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adexchangeseller.accounts.alerts.list";
  GTLQueryAdExchangeSeller *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdExchangeSellerAlerts class];
  return query;
}

#pragma mark - "accounts.customchannels" methods
// These create a GTLQueryAdExchangeSeller object.

+ (instancetype)queryForAccountsCustomchannelsGetWithAccountId:(NSString *)accountId
                                                    adClientId:(NSString *)adClientId
                                               customChannelId:(NSString *)customChannelId {
  NSString *methodName = @"adexchangeseller.accounts.customchannels.get";
  GTLQueryAdExchangeSeller *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.customChannelId = customChannelId;
  query.expectedObjectClass = [GTLAdExchangeSellerCustomChannel class];
  return query;
}

+ (instancetype)queryForAccountsCustomchannelsListWithAccountId:(NSString *)accountId
                                                     adClientId:(NSString *)adClientId {
  NSString *methodName = @"adexchangeseller.accounts.customchannels.list";
  GTLQueryAdExchangeSeller *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdExchangeSellerCustomChannels class];
  return query;
}

#pragma mark - "accounts" methods
// These create a GTLQueryAdExchangeSeller object.

+ (instancetype)queryForAccountsGetWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adexchangeseller.accounts.get";
  GTLQueryAdExchangeSeller *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdExchangeSellerAccount class];
  return query;
}

+ (instancetype)queryForAccountsList {
  NSString *methodName = @"adexchangeseller.accounts.list";
  GTLQueryAdExchangeSeller *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdExchangeSellerAccounts class];
  return query;
}

#pragma mark - "accounts.metadata.dimensions" methods
// These create a GTLQueryAdExchangeSeller object.

+ (instancetype)queryForAccountsMetadataDimensionsListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adexchangeseller.accounts.metadata.dimensions.list";
  GTLQueryAdExchangeSeller *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdExchangeSellerMetadata class];
  return query;
}

#pragma mark - "accounts.metadata.metrics" methods
// These create a GTLQueryAdExchangeSeller object.

+ (instancetype)queryForAccountsMetadataMetricsListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adexchangeseller.accounts.metadata.metrics.list";
  GTLQueryAdExchangeSeller *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdExchangeSellerMetadata class];
  return query;
}

#pragma mark - "accounts.preferreddeals" methods
// These create a GTLQueryAdExchangeSeller object.

+ (instancetype)queryForAccountsPreferreddealsGetWithAccountId:(NSString *)accountId
                                                        dealId:(NSString *)dealId {
  NSString *methodName = @"adexchangeseller.accounts.preferreddeals.get";
  GTLQueryAdExchangeSeller *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.dealId = dealId;
  query.expectedObjectClass = [GTLAdExchangeSellerPreferredDeal class];
  return query;
}

+ (instancetype)queryForAccountsPreferreddealsListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adexchangeseller.accounts.preferreddeals.list";
  GTLQueryAdExchangeSeller *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdExchangeSellerPreferredDeals class];
  return query;
}

#pragma mark - "accounts.reports" methods
// These create a GTLQueryAdExchangeSeller object.

+ (instancetype)queryForAccountsReportsGenerateWithAccountId:(NSString *)accountId
                                                   startDate:(NSString *)startDate
                                                     endDate:(NSString *)endDate {
  NSString *methodName = @"adexchangeseller.accounts.reports.generate";
  GTLQueryAdExchangeSeller *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.startDate = startDate;
  query.endDate = endDate;
  query.expectedObjectClass = [GTLAdExchangeSellerReport class];
  return query;
}

#pragma mark - "accounts.reports.saved" methods
// These create a GTLQueryAdExchangeSeller object.

+ (instancetype)queryForAccountsReportsSavedGenerateWithAccountId:(NSString *)accountId
                                                    savedReportId:(NSString *)savedReportId {
  NSString *methodName = @"adexchangeseller.accounts.reports.saved.generate";
  GTLQueryAdExchangeSeller *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.savedReportId = savedReportId;
  query.expectedObjectClass = [GTLAdExchangeSellerReport class];
  return query;
}

+ (instancetype)queryForAccountsReportsSavedListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adexchangeseller.accounts.reports.saved.list";
  GTLQueryAdExchangeSeller *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdExchangeSellerSavedReports class];
  return query;
}

#pragma mark - "accounts.urlchannels" methods
// These create a GTLQueryAdExchangeSeller object.

+ (instancetype)queryForAccountsUrlchannelsListWithAccountId:(NSString *)accountId
                                                  adClientId:(NSString *)adClientId {
  NSString *methodName = @"adexchangeseller.accounts.urlchannels.list";
  GTLQueryAdExchangeSeller *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdExchangeSellerUrlChannels class];
  return query;
}

@end
