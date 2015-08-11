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
//  GTLQueryAdSenseHost.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Host API (adsensehost/v4.1)
// Description:
//   Gives AdSense Hosts access to report generation, ad code generation, and
//   publisher management capabilities.
// Documentation:
//   https://developers.google.com/adsense/host/
// Classes:
//   GTLQueryAdSenseHost (26 custom class methods, 24 custom properties)

#import "GTLQueryAdSenseHost.h"

#import "GTLAdSenseHostAccount.h"
#import "GTLAdSenseHostAccounts.h"
#import "GTLAdSenseHostAdClient.h"
#import "GTLAdSenseHostAdClients.h"
#import "GTLAdSenseHostAdCode.h"
#import "GTLAdSenseHostAdUnit.h"
#import "GTLAdSenseHostAdUnits.h"
#import "GTLAdSenseHostAssociationSession.h"
#import "GTLAdSenseHostCustomChannel.h"
#import "GTLAdSenseHostCustomChannels.h"
#import "GTLAdSenseHostReport.h"
#import "GTLAdSenseHostUrlChannel.h"
#import "GTLAdSenseHostUrlChannels.h"

@implementation GTLQueryAdSenseHost

@dynamic accountId, adClientId, adUnitId, customChannelId, dimension, endDate,
         fields, filter, filterAdClientId, hostCustomChannelId, includeInactive,
         locale, maxResults, metric, pageToken, productCode, sort, startDate,
         startIndex, token, urlChannelId, userLocale, websiteLocale, websiteUrl;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"dimension" : [NSString class],
    @"filter" : [NSString class],
    @"filterAdClientId" : [NSString class],
    @"hostCustomChannelId" : [NSString class],
    @"metric" : [NSString class],
    @"productCode" : [NSString class],
    @"sort" : [NSString class]
  };
  return map;
}

#pragma mark - "accounts.adclients" methods
// These create a GTLQueryAdSenseHost object.

+ (instancetype)queryForAccountsAdclientsGetWithAccountId:(NSString *)accountId
                                               adClientId:(NSString *)adClientId {
  NSString *methodName = @"adsensehost.accounts.adclients.get";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseHostAdClient class];
  return query;
}

+ (instancetype)queryForAccountsAdclientsListWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adsensehost.accounts.adclients.list";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdSenseHostAdClients class];
  return query;
}

#pragma mark - "accounts.adunits" methods
// These create a GTLQueryAdSenseHost object.

+ (instancetype)queryForAccountsAdunitsDeleteWithAccountId:(NSString *)accountId
                                                adClientId:(NSString *)adClientId
                                                  adUnitId:(NSString *)adUnitId {
  NSString *methodName = @"adsensehost.accounts.adunits.delete";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdSenseHostAdUnit class];
  return query;
}

+ (instancetype)queryForAccountsAdunitsGetWithAccountId:(NSString *)accountId
                                             adClientId:(NSString *)adClientId
                                               adUnitId:(NSString *)adUnitId {
  NSString *methodName = @"adsensehost.accounts.adunits.get";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdSenseHostAdUnit class];
  return query;
}

+ (instancetype)queryForAccountsAdunitsGetAdCodeWithAccountId:(NSString *)accountId
                                                   adClientId:(NSString *)adClientId
                                                     adUnitId:(NSString *)adUnitId {
  NSString *methodName = @"adsensehost.accounts.adunits.getAdCode";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdSenseHostAdCode class];
  return query;
}

+ (instancetype)queryForAccountsAdunitsInsertWithObject:(GTLAdSenseHostAdUnit *)object
                                              accountId:(NSString *)accountId
                                             adClientId:(NSString *)adClientId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"adsensehost.accounts.adunits.insert";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseHostAdUnit class];
  return query;
}

+ (instancetype)queryForAccountsAdunitsListWithAccountId:(NSString *)accountId
                                              adClientId:(NSString *)adClientId {
  NSString *methodName = @"adsensehost.accounts.adunits.list";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseHostAdUnits class];
  return query;
}

+ (instancetype)queryForAccountsAdunitsPatchWithObject:(GTLAdSenseHostAdUnit *)object
                                             accountId:(NSString *)accountId
                                            adClientId:(NSString *)adClientId
                                              adUnitId:(NSString *)adUnitId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"adsensehost.accounts.adunits.patch";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.adUnitId = adUnitId;
  query.expectedObjectClass = [GTLAdSenseHostAdUnit class];
  return query;
}

+ (instancetype)queryForAccountsAdunitsUpdateWithObject:(GTLAdSenseHostAdUnit *)object
                                              accountId:(NSString *)accountId
                                             adClientId:(NSString *)adClientId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"adsensehost.accounts.adunits.update";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = accountId;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseHostAdUnit class];
  return query;
}

#pragma mark - "accounts" methods
// These create a GTLQueryAdSenseHost object.

+ (instancetype)queryForAccountsGetWithAccountId:(NSString *)accountId {
  NSString *methodName = @"adsensehost.accounts.get";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.expectedObjectClass = [GTLAdSenseHostAccount class];
  return query;
}

+ (instancetype)queryForAccountsListWithFilterAdClientId:(NSArray *)filterAdClientId {
  NSString *methodName = @"adsensehost.accounts.list";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.filterAdClientId = filterAdClientId;
  query.expectedObjectClass = [GTLAdSenseHostAccounts class];
  return query;
}

#pragma mark - "accounts.reports" methods
// These create a GTLQueryAdSenseHost object.

+ (instancetype)queryForAccountsReportsGenerateWithAccountId:(NSString *)accountId
                                                   startDate:(NSString *)startDate
                                                     endDate:(NSString *)endDate {
  NSString *methodName = @"adsensehost.accounts.reports.generate";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.accountId = accountId;
  query.startDate = startDate;
  query.endDate = endDate;
  query.expectedObjectClass = [GTLAdSenseHostReport class];
  return query;
}

#pragma mark - "adclients" methods
// These create a GTLQueryAdSenseHost object.

+ (instancetype)queryForAdclientsGetWithAdClientId:(NSString *)adClientId {
  NSString *methodName = @"adsensehost.adclients.get";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseHostAdClient class];
  return query;
}

+ (instancetype)queryForAdclientsList {
  NSString *methodName = @"adsensehost.adclients.list";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdSenseHostAdClients class];
  return query;
}

#pragma mark - "associationsessions" methods
// These create a GTLQueryAdSenseHost object.

+ (instancetype)queryForAssociationsessionsStartWithProductCode:(NSArray *)productCode
                                                     websiteUrl:(NSString *)websiteUrl {
  NSString *methodName = @"adsensehost.associationsessions.start";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.productCode = productCode;
  query.websiteUrl = websiteUrl;
  query.expectedObjectClass = [GTLAdSenseHostAssociationSession class];
  return query;
}

+ (instancetype)queryForAssociationsessionsVerifyWithToken:(NSString *)token {
  NSString *methodName = @"adsensehost.associationsessions.verify";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.token = token;
  query.expectedObjectClass = [GTLAdSenseHostAssociationSession class];
  return query;
}

#pragma mark - "customchannels" methods
// These create a GTLQueryAdSenseHost object.

+ (instancetype)queryForCustomchannelsDeleteWithAdClientId:(NSString *)adClientId
                                           customChannelId:(NSString *)customChannelId {
  NSString *methodName = @"adsensehost.customchannels.delete";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.customChannelId = customChannelId;
  query.expectedObjectClass = [GTLAdSenseHostCustomChannel class];
  return query;
}

+ (instancetype)queryForCustomchannelsGetWithAdClientId:(NSString *)adClientId
                                        customChannelId:(NSString *)customChannelId {
  NSString *methodName = @"adsensehost.customchannels.get";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.customChannelId = customChannelId;
  query.expectedObjectClass = [GTLAdSenseHostCustomChannel class];
  return query;
}

+ (instancetype)queryForCustomchannelsInsertWithObject:(GTLAdSenseHostCustomChannel *)object
                                            adClientId:(NSString *)adClientId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"adsensehost.customchannels.insert";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseHostCustomChannel class];
  return query;
}

+ (instancetype)queryForCustomchannelsListWithAdClientId:(NSString *)adClientId {
  NSString *methodName = @"adsensehost.customchannels.list";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseHostCustomChannels class];
  return query;
}

+ (instancetype)queryForCustomchannelsPatchWithObject:(GTLAdSenseHostCustomChannel *)object
                                           adClientId:(NSString *)adClientId
                                      customChannelId:(NSString *)customChannelId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"adsensehost.customchannels.patch";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.adClientId = adClientId;
  query.customChannelId = customChannelId;
  query.expectedObjectClass = [GTLAdSenseHostCustomChannel class];
  return query;
}

+ (instancetype)queryForCustomchannelsUpdateWithObject:(GTLAdSenseHostCustomChannel *)object
                                            adClientId:(NSString *)adClientId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"adsensehost.customchannels.update";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseHostCustomChannel class];
  return query;
}

#pragma mark - "reports" methods
// These create a GTLQueryAdSenseHost object.

+ (instancetype)queryForReportsGenerateWithStartDate:(NSString *)startDate
                                             endDate:(NSString *)endDate {
  NSString *methodName = @"adsensehost.reports.generate";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.startDate = startDate;
  query.endDate = endDate;
  query.expectedObjectClass = [GTLAdSenseHostReport class];
  return query;
}

#pragma mark - "urlchannels" methods
// These create a GTLQueryAdSenseHost object.

+ (instancetype)queryForUrlchannelsDeleteWithAdClientId:(NSString *)adClientId
                                           urlChannelId:(NSString *)urlChannelId {
  NSString *methodName = @"adsensehost.urlchannels.delete";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.urlChannelId = urlChannelId;
  query.expectedObjectClass = [GTLAdSenseHostUrlChannel class];
  return query;
}

+ (instancetype)queryForUrlchannelsInsertWithObject:(GTLAdSenseHostUrlChannel *)object
                                         adClientId:(NSString *)adClientId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"adsensehost.urlchannels.insert";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseHostUrlChannel class];
  return query;
}

+ (instancetype)queryForUrlchannelsListWithAdClientId:(NSString *)adClientId {
  NSString *methodName = @"adsensehost.urlchannels.list";
  GTLQueryAdSenseHost *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdSenseHostUrlChannels class];
  return query;
}

@end
