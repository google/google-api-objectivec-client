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
//  GTLQueryAdsense.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Management API (adsense/v1.1)
// Description:
//   Gives AdSense publishers access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://code.google.com/apis/adsense/management/
// Classes:
//   GTLQueryAdsense (20 custom class methods, 18 custom properties)

#import "GTLQueryAdsense.h"

#import "GTLAdsenseAccount.h"
#import "GTLAdsenseAccounts.h"
#import "GTLAdsenseAdClients.h"
#import "GTLAdsenseAdsenseReportsGenerateResponse.h"
#import "GTLAdsenseAdUnit.h"
#import "GTLAdsenseAdUnits.h"
#import "GTLAdsenseCustomChannel.h"
#import "GTLAdsenseCustomChannels.h"
#import "GTLAdsenseUrlChannels.h"

@implementation GTLQueryAdsense

@dynamic accountId, adClientId, adUnitId, currency, customChannelId, dimension,
         endDate, fields, filter, includeInactive, locale, maxResults, metric,
         pageToken, sort, startDate, startIndex, tree;

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
// These create a GTLQueryAdsense object.

+ (id)queryForAccountsAdclientsListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adsense.accounts.adclients.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdsenseAdClients class];
  return query;
}

#pragma mark -
#pragma mark "accounts.adunits.customchannels" methods
// These create a GTLQueryAdsense object.

+ (id)queryForAccountsAdunitsCustomchannelsListWithAccountId:(NSString *)accountId
                                                  adClientId:(NSString *)adClientId
                                                    adUnitId:(NSString *)adUnitId {
  NSString *methodName = @"adsense.accounts.adunits.customchannels.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdsenseCustomChannels class];
  return query;
}

#pragma mark -
#pragma mark "accounts.adunits" methods
// These create a GTLQueryAdsense object.

+ (id)queryForAccountsAdunitsGetWithAccountId:(NSString *)accountId
                                   adClientId:(NSString *)adClientId
                                     adUnitId:(NSString *)adUnitId {
  NSString *methodName = @"adsense.accounts.adunits.get";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdsenseAdUnit class];
  return query;
}

+ (id)queryForAccountsAdunitsListWithAccountId:(NSString *)accountId
                                    adClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.accounts.adunits.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdsenseAdUnits class];
  return query;
}

#pragma mark -
#pragma mark "accounts.customchannels.adunits" methods
// These create a GTLQueryAdsense object.

+ (id)queryForAccountsCustomchannelsAdunitsListWithAccountId:(NSString *)accountId
                                                  adClientId:(NSString *)adClientId
                                             customChannelId:(NSString *)customChannelId {
  NSString *methodName = @"adsense.accounts.customchannels.adunits.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.customChannelId = customChannelId;
  query.expectedObjectClass = [GTLAdsenseAdUnits class];
  return query;
}

#pragma mark -
#pragma mark "accounts.customchannels" methods
// These create a GTLQueryAdsense object.

+ (id)queryForAccountsCustomchannelsGetWithAccountId:(NSString *)accountId
                                          adClientId:(NSString *)adClientId
                                     customChannelId:(NSString *)customChannelId {
  NSString *methodName = @"adsense.accounts.customchannels.get";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.customChannelId = customChannelId;
  query.expectedObjectClass = [GTLAdsenseCustomChannel class];
  return query;
}

+ (id)queryForAccountsCustomchannelsListWithAccountId:(NSString *)accountId
                                           adClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.accounts.customchannels.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdsenseCustomChannels class];
  return query;
}

#pragma mark -
#pragma mark "accounts" methods
// These create a GTLQueryAdsense object.

+ (id)queryForAccountsGetWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adsense.accounts.get";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdsenseAccount class];
  return query;
}

+ (id)queryForAccountsList {
  NSString *methodName = @"adsense.accounts.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdsenseAccounts class];
  return query;
}

#pragma mark -
#pragma mark "accounts.reports" methods
// These create a GTLQueryAdsense object.

+ (id)queryForAccountsReportsGenerateWithStartDate:(NSString *)startDate
                                           endDate:(NSString *)endDate {
  NSString *methodName = @"adsense.accounts.reports.generate";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.startDate = startDate;
  query.endDate = endDate;
  query.expectedObjectClass = [GTLAdsenseAdsenseReportsGenerateResponse class];
  return query;
}

#pragma mark -
#pragma mark "accounts.urlchannels" methods
// These create a GTLQueryAdsense object.

+ (id)queryForAccountsUrlchannelsListWithAccountId:(NSString *)accountId
                                        adClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.accounts.urlchannels.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdsenseUrlChannels class];
  return query;
}

#pragma mark -
#pragma mark "adclients" methods
// These create a GTLQueryAdsense object.

+ (id)queryForAdclientsList {
  NSString *methodName = @"adsense.adclients.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdsenseAdClients class];
  return query;
}

#pragma mark -
#pragma mark "adunits.customchannels" methods
// These create a GTLQueryAdsense object.

+ (id)queryForAdunitsCustomchannelsListWithAdClientId:(NSString *)adClientId
                                             adUnitId:(NSString *)adUnitId {
  NSString *methodName = @"adsense.adunits.customchannels.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdsenseCustomChannels class];
  return query;
}

#pragma mark -
#pragma mark "adunits" methods
// These create a GTLQueryAdsense object.

+ (id)queryForAdunitsGetWithAdClientId:(NSString *)adClientId
                              adUnitId:(NSString *)adUnitId {
  NSString *methodName = @"adsense.adunits.get";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdsenseAdUnit class];
  return query;
}

+ (id)queryForAdunitsListWithAdClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.adunits.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdsenseAdUnits class];
  return query;
}

#pragma mark -
#pragma mark "customchannels.adunits" methods
// These create a GTLQueryAdsense object.

+ (id)queryForCustomchannelsAdunitsListWithAdClientId:(NSString *)adClientId
                                      customChannelId:(NSString *)customChannelId {
  NSString *methodName = @"adsense.customchannels.adunits.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.customChannelId = customChannelId;
  query.expectedObjectClass = [GTLAdsenseAdUnits class];
  return query;
}

#pragma mark -
#pragma mark "customchannels" methods
// These create a GTLQueryAdsense object.

+ (id)queryForCustomchannelsGetWithAdClientId:(NSString *)adClientId
                              customChannelId:(NSString *)customChannelId {
  NSString *methodName = @"adsense.customchannels.get";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.customChannelId = customChannelId;
  query.expectedObjectClass = [GTLAdsenseCustomChannel class];
  return query;
}

+ (id)queryForCustomchannelsListWithAdClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.customchannels.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdsenseCustomChannels class];
  return query;
}

#pragma mark -
#pragma mark "reports" methods
// These create a GTLQueryAdsense object.

+ (id)queryForReportsGenerateWithStartDate:(NSString *)startDate
                                   endDate:(NSString *)endDate {
  NSString *methodName = @"adsense.reports.generate";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.startDate = startDate;
  query.endDate = endDate;
  query.expectedObjectClass = [GTLAdsenseAdsenseReportsGenerateResponse class];
  return query;
}

#pragma mark -
#pragma mark "urlchannels" methods
// These create a GTLQueryAdsense object.

+ (id)queryForUrlchannelsListWithAdClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.urlchannels.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdsenseUrlChannels class];
  return query;
}

@end
