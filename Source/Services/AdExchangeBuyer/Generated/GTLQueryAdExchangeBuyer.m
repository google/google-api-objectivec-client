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
//   GTLQueryAdExchangeBuyer (46 custom class methods, 35 custom properties)

#import "GTLQueryAdExchangeBuyer.h"

#import "GTLAdExchangeBuyerAccount.h"
#import "GTLAdExchangeBuyerAccountsList.h"
#import "GTLAdExchangeBuyerAddOrderDealsResponse.h"
#import "GTLAdExchangeBuyerAddOrderNotesResponse.h"
#import "GTLAdExchangeBuyerBillingInfo.h"
#import "GTLAdExchangeBuyerBillingInfoList.h"
#import "GTLAdExchangeBuyerBudget.h"
#import "GTLAdExchangeBuyerClientAccessCapabilities.h"
#import "GTLAdExchangeBuyerCreateOrdersResponse.h"
#import "GTLAdExchangeBuyerCreative.h"
#import "GTLAdExchangeBuyerCreativesList.h"
#import "GTLAdExchangeBuyerDeleteOrderDealsResponse.h"
#import "GTLAdExchangeBuyerEditAllOrderDealsResponse.h"
#import "GTLAdExchangeBuyerGetNegotiationsResponse.h"
#import "GTLAdExchangeBuyerGetOffersResponse.h"
#import "GTLAdExchangeBuyerGetOrderDealsResponse.h"
#import "GTLAdExchangeBuyerGetOrderNotesResponse.h"
#import "GTLAdExchangeBuyerGetOrdersResponse.h"
#import "GTLAdExchangeBuyerListClientAccessCapabilitiesResponse.h"
#import "GTLAdExchangeBuyerListOffersResponse.h"
#import "GTLAdExchangeBuyerMarketplaceDeal.h"
#import "GTLAdExchangeBuyerMarketplaceNote.h"
#import "GTLAdExchangeBuyerMarketplaceOffer.h"
#import "GTLAdExchangeBuyerMarketplaceOrder.h"
#import "GTLAdExchangeBuyerNegotiationDto.h"
#import "GTLAdExchangeBuyerNegotiationRoundDto.h"
#import "GTLAdExchangeBuyerOfferDto.h"
#import "GTLAdExchangeBuyerPerformanceReportList.h"
#import "GTLAdExchangeBuyerPretargetingConfig.h"
#import "GTLAdExchangeBuyerPretargetingConfigList.h"

@implementation GTLQueryAdExchangeBuyer

@dynamic accountId, billingId, buyerCreativeId, clientAccessPermissions,
         clientAccountId, configId, dealId, dealIds, deals, dealsStatusFilter,
         endDateTime, fields, finalized, identifier, includePrivateAuctions,
         maxResults, negotiation, negotiationRound, negotiationId, notes, offer,
         offerId, openAuctionStatusFilter, order, orderId, orderRevisionNumber,
         orders, pageToken, pqlQuery, revisionNumber, sinceTimestampMillis,
         sponsorAccountId, startDateTime, updateAction, webPropertyCode;

+ (NSDictionary *)parameterNameMap {
  NSDictionary *map = @{
    @"clientAccessPermissions" : @"client_access_permissions",
    @"identifier" : @"id",
    @"negotiationRound" : @"negotiation_round"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"dealIds" : [NSString class],
    @"deals" : [GTLAdExchangeBuyerMarketplaceDeal class],
    @"notes" : [GTLAdExchangeBuyerMarketplaceNote class],
    @"orders" : [GTLAdExchangeBuyerMarketplaceOrder class]
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

#pragma mark - "clientaccess" methods
// These create a GTLQueryAdExchangeBuyer object.

+ (instancetype)queryForClientaccessDeleteWithClientAccountId:(long long)clientAccountId
                                             sponsorAccountId:(NSInteger)sponsorAccountId {
  NSString *methodName = @"adexchangebuyer.clientaccess.delete";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.clientAccountId = clientAccountId;
  query.sponsorAccountId = [NSNumber numberWithInteger:sponsorAccountId];
  return query;
}

+ (instancetype)queryForClientaccessGetWithClientAccountId:(long long)clientAccountId
                                          sponsorAccountId:(NSInteger)sponsorAccountId {
  NSString *methodName = @"adexchangebuyer.clientaccess.get";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.clientAccountId = clientAccountId;
  query.sponsorAccountId = [NSNumber numberWithInteger:sponsorAccountId];
  query.expectedObjectClass = [GTLAdExchangeBuyerClientAccessCapabilities class];
  return query;
}

+ (instancetype)queryForClientaccessInsert {
  NSString *methodName = @"adexchangebuyer.clientaccess.insert";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdExchangeBuyerClientAccessCapabilities class];
  return query;
}

+ (instancetype)queryForClientaccessList {
  NSString *methodName = @"adexchangebuyer.clientaccess.list";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdExchangeBuyerListClientAccessCapabilitiesResponse class];
  return query;
}

+ (instancetype)queryForClientaccessPatchWithClientAccountId:(long long)clientAccountId
                                            sponsorAccountId:(NSInteger)sponsorAccountId {
  NSString *methodName = @"adexchangebuyer.clientaccess.patch";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.clientAccountId = clientAccountId;
  query.sponsorAccountId = [NSNumber numberWithInteger:sponsorAccountId];
  query.expectedObjectClass = [GTLAdExchangeBuyerClientAccessCapabilities class];
  return query;
}

+ (instancetype)queryForClientaccessUpdateWithClientAccountId:(long long)clientAccountId
                                             sponsorAccountId:(NSInteger)sponsorAccountId {
  NSString *methodName = @"adexchangebuyer.clientaccess.update";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.clientAccountId = clientAccountId;
  query.sponsorAccountId = [NSNumber numberWithInteger:sponsorAccountId];
  query.expectedObjectClass = [GTLAdExchangeBuyerClientAccessCapabilities class];
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

#pragma mark - "deals" methods
// These create a GTLQueryAdExchangeBuyer object.

+ (instancetype)queryForDealsGetWithDealId:(long long)dealId {
  NSString *methodName = @"adexchangebuyer.deals.get";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.dealId = dealId;
  query.expectedObjectClass = [GTLAdExchangeBuyerNegotiationDto class];
  return query;
}

#pragma mark - "marketplacedeals" methods
// These create a GTLQueryAdExchangeBuyer object.

+ (instancetype)queryForMarketplacedealsDeleteWithOrderId:(NSString *)orderId {
  NSString *methodName = @"adexchangebuyer.marketplacedeals.delete";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.orderId = orderId;
  query.expectedObjectClass = [GTLAdExchangeBuyerDeleteOrderDealsResponse class];
  return query;
}

+ (instancetype)queryForMarketplacedealsInsertWithOrderId:(NSString *)orderId {
  NSString *methodName = @"adexchangebuyer.marketplacedeals.insert";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.orderId = orderId;
  query.expectedObjectClass = [GTLAdExchangeBuyerAddOrderDealsResponse class];
  return query;
}

+ (instancetype)queryForMarketplacedealsListWithOrderId:(NSString *)orderId {
  NSString *methodName = @"adexchangebuyer.marketplacedeals.list";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.orderId = orderId;
  query.expectedObjectClass = [GTLAdExchangeBuyerGetOrderDealsResponse class];
  return query;
}

+ (instancetype)queryForMarketplacedealsUpdateWithOrderId:(NSString *)orderId {
  NSString *methodName = @"adexchangebuyer.marketplacedeals.update";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.orderId = orderId;
  query.expectedObjectClass = [GTLAdExchangeBuyerEditAllOrderDealsResponse class];
  return query;
}

#pragma mark - "marketplacenotes" methods
// These create a GTLQueryAdExchangeBuyer object.

+ (instancetype)queryForMarketplacenotesInsertWithOrderId:(NSString *)orderId {
  NSString *methodName = @"adexchangebuyer.marketplacenotes.insert";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.orderId = orderId;
  query.expectedObjectClass = [GTLAdExchangeBuyerAddOrderNotesResponse class];
  return query;
}

+ (instancetype)queryForMarketplacenotesListWithOrderId:(NSString *)orderId {
  NSString *methodName = @"adexchangebuyer.marketplacenotes.list";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.orderId = orderId;
  query.expectedObjectClass = [GTLAdExchangeBuyerGetOrderNotesResponse class];
  return query;
}

#pragma mark - "marketplaceoffers" methods
// These create a GTLQueryAdExchangeBuyer object.

+ (instancetype)queryForMarketplaceoffersGetWithOfferId:(NSString *)offerId {
  NSString *methodName = @"adexchangebuyer.marketplaceoffers.get";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.offerId = offerId;
  query.expectedObjectClass = [GTLAdExchangeBuyerMarketplaceOffer class];
  return query;
}

+ (instancetype)queryForMarketplaceoffersSearch {
  NSString *methodName = @"adexchangebuyer.marketplaceoffers.search";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdExchangeBuyerGetOffersResponse class];
  return query;
}

#pragma mark - "marketplaceorders" methods
// These create a GTLQueryAdExchangeBuyer object.

+ (instancetype)queryForMarketplaceordersGetWithOrderId:(NSString *)orderId {
  NSString *methodName = @"adexchangebuyer.marketplaceorders.get";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.orderId = orderId;
  query.expectedObjectClass = [GTLAdExchangeBuyerMarketplaceOrder class];
  return query;
}

+ (instancetype)queryForMarketplaceordersInsert {
  NSString *methodName = @"adexchangebuyer.marketplaceorders.insert";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdExchangeBuyerCreateOrdersResponse class];
  return query;
}

+ (instancetype)queryForMarketplaceordersPatchWithOrderId:(NSString *)orderId
                                           revisionNumber:(long long)revisionNumber
                                             updateAction:(NSString *)updateAction {
  NSString *methodName = @"adexchangebuyer.marketplaceorders.patch";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.orderId = orderId;
  query.revisionNumber = revisionNumber;
  query.updateAction = updateAction;
  query.expectedObjectClass = [GTLAdExchangeBuyerMarketplaceOrder class];
  return query;
}

+ (instancetype)queryForMarketplaceordersSearch {
  NSString *methodName = @"adexchangebuyer.marketplaceorders.search";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdExchangeBuyerGetOrdersResponse class];
  return query;
}

+ (instancetype)queryForMarketplaceordersUpdateWithOrderId:(NSString *)orderId
                                            revisionNumber:(long long)revisionNumber
                                              updateAction:(NSString *)updateAction {
  NSString *methodName = @"adexchangebuyer.marketplaceorders.update";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.orderId = orderId;
  query.revisionNumber = revisionNumber;
  query.updateAction = updateAction;
  query.expectedObjectClass = [GTLAdExchangeBuyerMarketplaceOrder class];
  return query;
}

#pragma mark - "negotiationrounds" methods
// These create a GTLQueryAdExchangeBuyer object.

+ (instancetype)queryForNegotiationroundsInsertWithNegotiationId:(long long)negotiationId {
  NSString *methodName = @"adexchangebuyer.negotiationrounds.insert";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.negotiationId = negotiationId;
  query.expectedObjectClass = [GTLAdExchangeBuyerNegotiationRoundDto class];
  return query;
}

#pragma mark - "negotiations" methods
// These create a GTLQueryAdExchangeBuyer object.

+ (instancetype)queryForNegotiationsGetWithNegotiationId:(long long)negotiationId {
  NSString *methodName = @"adexchangebuyer.negotiations.get";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.negotiationId = negotiationId;
  query.expectedObjectClass = [GTLAdExchangeBuyerNegotiationDto class];
  return query;
}

+ (instancetype)queryForNegotiationsInsert {
  NSString *methodName = @"adexchangebuyer.negotiations.insert";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdExchangeBuyerNegotiationDto class];
  return query;
}

+ (instancetype)queryForNegotiationsList {
  NSString *methodName = @"adexchangebuyer.negotiations.list";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdExchangeBuyerGetNegotiationsResponse class];
  return query;
}

#pragma mark - "offers" methods
// These create a GTLQueryAdExchangeBuyer object.

+ (instancetype)queryForOffersGetWithOfferId:(long long)offerId {
  NSString *methodName = @"adexchangebuyer.offers.get";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.offerId = [NSNumber numberWithLongLong:offerId];
  query.expectedObjectClass = [GTLAdExchangeBuyerOfferDto class];
  return query;
}

+ (instancetype)queryForOffersInsert {
  NSString *methodName = @"adexchangebuyer.offers.insert";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdExchangeBuyerOfferDto class];
  return query;
}

+ (instancetype)queryForOffersList {
  NSString *methodName = @"adexchangebuyer.offers.list";
  GTLQueryAdExchangeBuyer *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdExchangeBuyerListOffersResponse class];
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
