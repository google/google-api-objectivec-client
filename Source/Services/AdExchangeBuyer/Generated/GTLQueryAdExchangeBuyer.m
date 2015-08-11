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
//  GTLQueryAdExchangeBuyer.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Ad Exchange Buyer API (adexchangebuyer/v1.4)
// Description:
//   Accesses your bidding-account information, submits creatives for
//   validation, finds available direct deals, and retrieves performance
//   reports.
// Documentation:
//   https://developers.google.com/ad-exchange/buyer-rest
// Classes:
//   GTLQueryAdExchangeBuyer (19 custom class methods, 12 custom properties)

#import "GTLQueryAdExchangeBuyer.h"

#import "GTLAdExchangeBuyerAccount.h"
#import "GTLAdExchangeBuyerAccountsList.h"
#import "GTLAdExchangeBuyerBillingInfo.h"
#import "GTLAdExchangeBuyerBillingInfoList.h"
#import "GTLAdExchangeBuyerBudget.h"
#import "GTLAdExchangeBuyerCreative.h"
#import "GTLAdExchangeBuyerCreativesList.h"
#import "GTLAdExchangeBuyerPerformanceReportList.h"
#import "GTLAdExchangeBuyerPretargetingConfig.h"
#import "GTLAdExchangeBuyerPretargetingConfigList.h"

@implementation GTLQueryAdExchangeBuyer

@dynamic accountId, billingId, buyerCreativeId, configId, dealsStatusFilter,
         endDateTime, fields, identifier, maxResults, openAuctionStatusFilter,
         pageToken, startDateTime;

+ (NSDictionary *)parameterNameMap {
  NSDictionary *map = @{
    @"identifier" : @"id"
  };
  return map;
}

#pragma mark - "accounts" methods
// These create a GTLQueryAdExchangeBuyer object.

+ (instancetype)queryForAccountsGetWithIdentifier:(NSInteger)identifier {
  NSString *methodName = @"adexchangebuyer.accounts.get";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLAdExchangeBuyerAccount class];
  return query;
}

+ (instancetype)queryForAccountsList {
  NSString *methodName = @"adexchangebuyer.accounts.list";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdExchangeBuyerAccountsList class];
  return query;
}

+ (instancetype)queryForAccountsPatchWithObject:(GTLAdExchangeBuyerAccount *)object
                                     identifier:(NSInteger)identifier {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"adexchangebuyer.accounts.patch";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.identifier = identifier;
  query.expectedObjectClass = [GTLAdExchangeBuyerAccount class];
  return query;
}

+ (instancetype)queryForAccountsUpdateWithObject:(GTLAdExchangeBuyerAccount *)object
                                      identifier:(NSInteger)identifier {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"adexchangebuyer.accounts.update";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.identifier = identifier;
  query.expectedObjectClass = [GTLAdExchangeBuyerAccount class];
  return query;
}

#pragma mark - "billingInfo" methods
// These create a GTLQueryAdExchangeBuyer object.

+ (instancetype)queryForBillingInfoGetWithAccountId:(NSInteger)accountId {
  NSString *methodName = @"adexchangebuyer.billingInfo.get";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.accountId = [NSNumber numberWithInteger:accountId];
  query.expectedObjectClass = [GTLAdExchangeBuyerBillingInfo class];
  return query;
}

+ (instancetype)queryForBillingInfoList {
  NSString *methodName = @"adexchangebuyer.billingInfo.list";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdExchangeBuyerBillingInfoList class];
  return query;
}

#pragma mark - "budget" methods
// These create a GTLQueryAdExchangeBuyer object.

+ (instancetype)queryForBudgetGetWithAccountId:(long long)accountId
                                     billingId:(long long)billingId {
  NSString *methodName = @"adexchangebuyer.budget.get";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.accountId = [NSNumber numberWithLongLong:accountId];
  query.billingId = billingId;
  query.expectedObjectClass = [GTLAdExchangeBuyerBudget class];
  return query;
}

+ (instancetype)queryForBudgetPatchWithObject:(GTLAdExchangeBuyerBudget *)object
                                    accountId:(long long)accountId
                                    billingId:(long long)billingId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"adexchangebuyer.budget.patch";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = [NSNumber numberWithLongLong:accountId];
  query.billingId = billingId;
  query.expectedObjectClass = [GTLAdExchangeBuyerBudget class];
  return query;
}

+ (instancetype)queryForBudgetUpdateWithObject:(GTLAdExchangeBuyerBudget *)object
                                     accountId:(long long)accountId
                                     billingId:(long long)billingId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"adexchangebuyer.budget.update";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = [NSNumber numberWithLongLong:accountId];
  query.billingId = billingId;
  query.expectedObjectClass = [GTLAdExchangeBuyerBudget class];
  return query;
}

#pragma mark - "creatives" methods
// These create a GTLQueryAdExchangeBuyer object.

+ (instancetype)queryForCreativesGetWithAccountId:(NSInteger)accountId
                                  buyerCreativeId:(NSString *)buyerCreativeId {
  NSString *methodName = @"adexchangebuyer.creatives.get";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.accountId = [NSNumber numberWithInteger:accountId];
  query.buyerCreativeId = buyerCreativeId;
  query.expectedObjectClass = [GTLAdExchangeBuyerCreative class];
  return query;
}

+ (instancetype)queryForCreativesInsertWithObject:(GTLAdExchangeBuyerCreative *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"adexchangebuyer.creatives.insert";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.expectedObjectClass = [GTLAdExchangeBuyerCreative class];
  return query;
}

+ (instancetype)queryForCreativesList {
  NSString *methodName = @"adexchangebuyer.creatives.list";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdExchangeBuyerCreativesList class];
  return query;
}

#pragma mark - "performanceReport" methods
// These create a GTLQueryAdExchangeBuyer object.

+ (instancetype)queryForPerformanceReportListWithAccountId:(long long)accountId
                                               endDateTime:(NSString *)endDateTime
                                             startDateTime:(NSString *)startDateTime {
  NSString *methodName = @"adexchangebuyer.performanceReport.list";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.accountId = [NSNumber numberWithLongLong:accountId];
  query.endDateTime = endDateTime;
  query.startDateTime = startDateTime;
  query.expectedObjectClass = [GTLAdExchangeBuyerPerformanceReportList class];
  return query;
}

#pragma mark - "pretargetingConfig" methods
// These create a GTLQueryAdExchangeBuyer object.

+ (instancetype)queryForPretargetingConfigDeleteWithAccountId:(long long)accountId
                                                     configId:(long long)configId {
  NSString *methodName = @"adexchangebuyer.pretargetingConfig.delete";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.accountId = [NSNumber numberWithLongLong:accountId];
  query.configId = configId;
  return query;
}

+ (instancetype)queryForPretargetingConfigGetWithAccountId:(long long)accountId
                                                  configId:(long long)configId {
  NSString *methodName = @"adexchangebuyer.pretargetingConfig.get";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.accountId = [NSNumber numberWithLongLong:accountId];
  query.configId = configId;
  query.expectedObjectClass = [GTLAdExchangeBuyerPretargetingConfig class];
  return query;
}

+ (instancetype)queryForPretargetingConfigInsertWithObject:(GTLAdExchangeBuyerPretargetingConfig *)object
                                                 accountId:(long long)accountId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"adexchangebuyer.pretargetingConfig.insert";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = [NSNumber numberWithLongLong:accountId];
  query.expectedObjectClass = [GTLAdExchangeBuyerPretargetingConfig class];
  return query;
}

+ (instancetype)queryForPretargetingConfigListWithAccountId:(long long)accountId {
  NSString *methodName = @"adexchangebuyer.pretargetingConfig.list";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.accountId = [NSNumber numberWithLongLong:accountId];
  query.expectedObjectClass = [GTLAdExchangeBuyerPretargetingConfigList class];
  return query;
}

+ (instancetype)queryForPretargetingConfigPatchWithObject:(GTLAdExchangeBuyerPretargetingConfig *)object
                                                accountId:(long long)accountId
                                                 configId:(long long)configId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"adexchangebuyer.pretargetingConfig.patch";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = [NSNumber numberWithLongLong:accountId];
  query.configId = configId;
  query.expectedObjectClass = [GTLAdExchangeBuyerPretargetingConfig class];
  return query;
}

+ (instancetype)queryForPretargetingConfigUpdateWithObject:(GTLAdExchangeBuyerPretargetingConfig *)object
                                                 accountId:(long long)accountId
                                                  configId:(long long)configId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"adexchangebuyer.pretargetingConfig.update";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.accountId = [NSNumber numberWithLongLong:accountId];
  query.configId = configId;
  query.expectedObjectClass = [GTLAdExchangeBuyerPretargetingConfig class];
  return query;
}

@end
