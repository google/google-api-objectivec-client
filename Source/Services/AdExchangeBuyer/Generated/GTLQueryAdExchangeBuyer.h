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
//  GTLQueryAdExchangeBuyer.h
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
//   GTLQueryAdExchangeBuyer (32 custom class methods, 24 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLAdExchangeBuyerAccount;
@class GTLAdExchangeBuyerBudget;
@class GTLAdExchangeBuyerCreative;
@class GTLAdExchangeBuyerMarketplaceDeal;
@class GTLAdExchangeBuyerMarketplaceNote;
@class GTLAdExchangeBuyerMarketplaceOrder;
@class GTLAdExchangeBuyerPretargetingConfig;

@interface GTLQueryAdExchangeBuyer : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (nonatomic, copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
// "accountId" has different types for some query methods; see the documentation
// for the right type for each query method.
@property (nonatomic, retain) id accountId;
@property (nonatomic, assign) long long billingId;
// "buyerCreativeId" has different types for some query methods; see the
// documentation for the right type for each query method.
@property (nonatomic, retain) id buyerCreativeId;
@property (nonatomic, assign) long long configId;
@property (nonatomic, retain) NSArray *dealIds;  // of NSString
@property (nonatomic, retain) NSArray *deals;  // of GTLAdExchangeBuyerMarketplaceDeal
@property (nonatomic, copy) NSString *dealsStatusFilter;
@property (nonatomic, copy) NSString *endDateTime;
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, assign) NSInteger identifier;
@property (nonatomic, assign) NSUInteger maxResults;
@property (nonatomic, retain) NSArray *notes;  // of GTLAdExchangeBuyerMarketplaceNote
@property (nonatomic, copy) NSString *offerId;
@property (nonatomic, copy) NSString *openAuctionStatusFilter;
@property (nonatomic, retain) GTLAdExchangeBuyerMarketplaceOrder *order;
@property (nonatomic, copy) NSString *orderId;
@property (nonatomic, assign) long long orderRevisionNumber;
@property (nonatomic, retain) NSArray *orders;  // of GTLAdExchangeBuyerMarketplaceOrder
@property (nonatomic, copy) NSString *pageToken;
@property (nonatomic, copy) NSString *pqlQuery;
@property (nonatomic, assign) long long revisionNumber;
@property (nonatomic, copy) NSString *startDateTime;
@property (nonatomic, copy) NSString *updateAction;
@property (nonatomic, copy) NSString *webPropertyCode;

#pragma mark - "accounts" methods
// These create a GTLQueryAdExchangeBuyer object.

// Method: adexchangebuyer.accounts.get
// Gets one account by ID.
//  Required:
//   identifier: The account id
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerAccount.
+ (instancetype)queryForAccountsGetWithIdentifier:(NSInteger)identifier;

// Method: adexchangebuyer.accounts.list
// Retrieves the authenticated user's list of accounts.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerAccountsList.
+ (instancetype)queryForAccountsList;

// Method: adexchangebuyer.accounts.patch
// Updates an existing account. This method supports patch semantics.
//  Required:
//   identifier: The account id
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerAccount.
+ (instancetype)queryForAccountsPatchWithObject:(GTLAdExchangeBuyerAccount *)object
                                     identifier:(NSInteger)identifier;

// Method: adexchangebuyer.accounts.update
// Updates an existing account.
//  Required:
//   identifier: The account id
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerAccount.
+ (instancetype)queryForAccountsUpdateWithObject:(GTLAdExchangeBuyerAccount *)object
                                      identifier:(NSInteger)identifier;

#pragma mark - "billingInfo" methods
// These create a GTLQueryAdExchangeBuyer object.

// Method: adexchangebuyer.billingInfo.get
// Returns the billing information for one account specified by account ID.
//  Required:
//   accountId: The account id.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerBillingInfo.
+ (instancetype)queryForBillingInfoGetWithAccountId:(NSInteger)accountId;

// Method: adexchangebuyer.billingInfo.list
// Retrieves a list of billing information for all accounts of the authenticated
// user.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerBillingInfoList.
+ (instancetype)queryForBillingInfoList;

#pragma mark - "budget" methods
// These create a GTLQueryAdExchangeBuyer object.

// Method: adexchangebuyer.budget.get
// Returns the budget information for the adgroup specified by the accountId and
// billingId.
//  Required:
//   accountId: The account id to get the budget information for.
//   billingId: The billing id to get the budget information for.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerBudget.
+ (instancetype)queryForBudgetGetWithAccountId:(long long)accountId
                                     billingId:(long long)billingId;

// Method: adexchangebuyer.budget.patch
// Updates the budget amount for the budget of the adgroup specified by the
// accountId and billingId, with the budget amount in the request. This method
// supports patch semantics.
//  Required:
//   accountId: The account id associated with the budget being updated.
//   billingId: The billing id associated with the budget being updated.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerBudget.
+ (instancetype)queryForBudgetPatchWithObject:(GTLAdExchangeBuyerBudget *)object
                                    accountId:(long long)accountId
                                    billingId:(long long)billingId;

// Method: adexchangebuyer.budget.update
// Updates the budget amount for the budget of the adgroup specified by the
// accountId and billingId, with the budget amount in the request.
//  Required:
//   accountId: The account id associated with the budget being updated.
//   billingId: The billing id associated with the budget being updated.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerBudget.
+ (instancetype)queryForBudgetUpdateWithObject:(GTLAdExchangeBuyerBudget *)object
                                     accountId:(long long)accountId
                                     billingId:(long long)billingId;

#pragma mark - "creatives" methods
// These create a GTLQueryAdExchangeBuyer object.

// Method: adexchangebuyer.creatives.get
// Gets the status for a single creative. A creative will be available 30-40
// minutes after submission.
//  Required:
//   accountId: The id for the account that will serve this creative.
//   buyerCreativeId: The buyer-specific id for this creative.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerCreative.
+ (instancetype)queryForCreativesGetWithAccountId:(NSInteger)accountId
                                  buyerCreativeId:(NSString *)buyerCreativeId;

// Method: adexchangebuyer.creatives.insert
// Submit a new creative.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerCreative.
+ (instancetype)queryForCreativesInsertWithObject:(GTLAdExchangeBuyerCreative *)object;

// Method: adexchangebuyer.creatives.list
// Retrieves a list of the authenticated user's active creatives. A creative
// will be available 30-40 minutes after submission.
//  Optional:
//   accountId: When specified, only creatives for the given account ids are
//     returned.
//     Note: For this method, "accountId" should be of type NSArray<NSNumber>.
//   buyerCreativeId: When specified, only creatives for the given buyer
//     creative ids are returned.
//     Note: For this method, "buyerCreativeId" should be of type
//     NSArray<NSString>.
//   dealsStatusFilter: When specified, only creatives having the given direct
//     deals status are returned.
//      kGTLAdExchangeBuyerDealsStatusFilterApproved: Creatives which have been
//        approved for serving on direct deals.
//      kGTLAdExchangeBuyerDealsStatusFilterConditionallyApproved: Creatives
//        which have been conditionally approved for serving on direct deals.
//      kGTLAdExchangeBuyerDealsStatusFilterDisapproved: Creatives which have
//        been disapproved for serving on direct deals.
//      kGTLAdExchangeBuyerDealsStatusFilterNotChecked: Creatives whose direct
//        deals status is not yet checked.
//   maxResults: Maximum number of entries returned on one result page. If not
//     set, the default is 100. Optional. (1..1000)
//   openAuctionStatusFilter: When specified, only creatives having the given
//     open auction status are returned.
//      kGTLAdExchangeBuyerOpenAuctionStatusFilterApproved: Creatives which have
//        been approved for serving on the open auction.
//      kGTLAdExchangeBuyerOpenAuctionStatusFilterConditionallyApproved: Creatives
//        which have been conditionally approved for serving on the open
//        auction.
//      kGTLAdExchangeBuyerOpenAuctionStatusFilterDisapproved: Creatives which
//        have been disapproved for serving on the open auction.
//      kGTLAdExchangeBuyerOpenAuctionStatusFilterNotChecked: Creatives whose
//        open auction status is not yet checked.
//   pageToken: A continuation token, used to page through ad clients. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response. Optional.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerCreativesList.
+ (instancetype)queryForCreativesList;

#pragma mark - "marketplacedeals" methods
// These create a GTLQueryAdExchangeBuyer object.

// Method: adexchangebuyer.marketplacedeals.delete
// Delete the specified deals from the order
//  Required:
//   orderId: The orderId to delete deals from.
//  Optional:
//   dealIds: List of deals to delete for a given order
//   orderRevisionNumber: The last known order revision number.
//   updateAction: NSString
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerDeleteOrderDealsResponse.
+ (instancetype)queryForMarketplacedealsDeleteWithOrderId:(NSString *)orderId;

// Method: adexchangebuyer.marketplacedeals.insert
// Add new deals for the specified order
//  Required:
//   orderId: OrderId for which deals need to be added.
//  Optional:
//   deals: The list of deals to add
//   orderRevisionNumber: The last known order revision number.
//   updateAction: Indicates an optional action to take on the order
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerAddOrderDealsResponse.
+ (instancetype)queryForMarketplacedealsInsertWithOrderId:(NSString *)orderId;

// Method: adexchangebuyer.marketplacedeals.list
// List all the deals for a given order
//  Required:
//   orderId: The orderId to get deals for.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerGetOrderDealsResponse.
+ (instancetype)queryForMarketplacedealsListWithOrderId:(NSString *)orderId;

// Method: adexchangebuyer.marketplacedeals.update
// Replaces all the deals in the order with the passed in deals
//  Required:
//   orderId: The orderId to edit deals on.
//  Optional:
//   deals: List of deals to edit. Service may perform 3 different operations
//     based on comparison of deals in this list vs deals already persisted in
//     database: 1. Add new deal to order If a deal in this list does not exist
//     in the order, the service will create a new deal and add it to the order.
//     Validation will follow AddOrderDealsRequest. 2. Update existing deal in
//     the order If a deal in this list already exist in the order, the service
//     will update that existing deal to this new deal in the request.
//     Validation will follow UpdateOrderDealsRequest. 3. Delete deals from the
//     order (just need the id) If a existing deal in the order is not present
//     in this list, the service will delete that deal from the order.
//     Validation will follow DeleteOrderDealsRequest.
//   order: If specified, also updates the order in the batch transaction. This
//     is useful when the order and the deals need to be updated in one
//     transaction.
//   orderRevisionNumber: The last known revision number for the order.
//   updateAction: Indicates an optional action to take on the order
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerEditAllOrderDealsResponse.
+ (instancetype)queryForMarketplacedealsUpdateWithOrderId:(NSString *)orderId;

#pragma mark - "marketplacenotes" methods
// These create a GTLQueryAdExchangeBuyer object.

// Method: adexchangebuyer.marketplacenotes.insert
// Add notes to the order
//  Required:
//   orderId: The orderId to add notes for.
//  Optional:
//   notes: The list of notes to add.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerAddOrderNotesResponse.
+ (instancetype)queryForMarketplacenotesInsertWithOrderId:(NSString *)orderId;

// Method: adexchangebuyer.marketplacenotes.list
// Get all the notes associated with an order
//  Required:
//   orderId: The orderId to get notes for.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerGetOrderNotesResponse.
+ (instancetype)queryForMarketplacenotesListWithOrderId:(NSString *)orderId;

#pragma mark - "marketplaceoffers" methods
// These create a GTLQueryAdExchangeBuyer object.

// Method: adexchangebuyer.marketplaceoffers.get
// Gets the requested negotiation.
//  Required:
//   offerId: The offerId for the offer to get the head revision for.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerMarketplaceOffer.
+ (instancetype)queryForMarketplaceoffersGetWithOfferId:(NSString *)offerId;

// Method: adexchangebuyer.marketplaceoffers.search
// Gets the requested negotiation.
//  Optional:
//   pqlQuery: The pql query used to query for offers.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerGetOffersResponse.
+ (instancetype)queryForMarketplaceoffersSearch;

#pragma mark - "marketplaceorders" methods
// These create a GTLQueryAdExchangeBuyer object.

// Method: adexchangebuyer.marketplaceorders.get
// Get an order given its id
//  Required:
//   orderId: Id of the order to retrieve.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerMarketplaceOrder.
+ (instancetype)queryForMarketplaceordersGetWithOrderId:(NSString *)orderId;

// Method: adexchangebuyer.marketplaceorders.insert
// Create the given list of orders
//  Optional:
//   orders: The list of orders to create.
//   webPropertyCode: NSString
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerCreateOrdersResponse.
+ (instancetype)queryForMarketplaceordersInsert;

// Method: adexchangebuyer.marketplaceorders.patch
// Update the given order. This method supports patch semantics.
//  Required:
//   orderId: The order id to update.
//   revisionNumber: The last known revision number to update. If the head
//     revision in the marketplace database has since changed, an error will be
//     thrown. The caller should then fetch the lastest order at head revision
//     and retry the update at that revision.
//   updateAction: The proposed action to take on the order.
//      kGTLAdExchangeBuyerUpdateActionAccept: "accept"
//      kGTLAdExchangeBuyerUpdateActionCancel: "cancel"
//      kGTLAdExchangeBuyerUpdateActionPropose: "propose"
//      kGTLAdExchangeBuyerUpdateActionUnknownAction: "unknownAction"
//      kGTLAdExchangeBuyerUpdateActionUpdateFinalized: "updateFinalized"
//  Optional:
//   order: GTLAdExchangeBuyerMarketplaceOrder
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerMarketplaceOrder.
+ (instancetype)queryForMarketplaceordersPatchWithOrderId:(NSString *)orderId
                                           revisionNumber:(long long)revisionNumber
                                             updateAction:(NSString *)updateAction;

// Method: adexchangebuyer.marketplaceorders.search
// Search for orders using pql query
//  Optional:
//   pqlQuery: Query string to retrieve specific orders.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerGetOrdersResponse.
+ (instancetype)queryForMarketplaceordersSearch;

// Method: adexchangebuyer.marketplaceorders.update
// Update the given order
//  Required:
//   orderId: The order id to update.
//   revisionNumber: The last known revision number to update. If the head
//     revision in the marketplace database has since changed, an error will be
//     thrown. The caller should then fetch the lastest order at head revision
//     and retry the update at that revision.
//   updateAction: The proposed action to take on the order.
//      kGTLAdExchangeBuyerUpdateActionAccept: "accept"
//      kGTLAdExchangeBuyerUpdateActionCancel: "cancel"
//      kGTLAdExchangeBuyerUpdateActionPropose: "propose"
//      kGTLAdExchangeBuyerUpdateActionUnknownAction: "unknownAction"
//      kGTLAdExchangeBuyerUpdateActionUpdateFinalized: "updateFinalized"
//  Optional:
//   order: GTLAdExchangeBuyerMarketplaceOrder
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerMarketplaceOrder.
+ (instancetype)queryForMarketplaceordersUpdateWithOrderId:(NSString *)orderId
                                            revisionNumber:(long long)revisionNumber
                                              updateAction:(NSString *)updateAction;

#pragma mark - "performanceReport" methods
// These create a GTLQueryAdExchangeBuyer object.

// Method: adexchangebuyer.performanceReport.list
// Retrieves the authenticated user's list of performance metrics.
//  Required:
//   accountId: The account id to get the reports.
//   endDateTime: The end time of the report in ISO 8601 timestamp format using
//     UTC.
//   startDateTime: The start time of the report in ISO 8601 timestamp format
//     using UTC.
//  Optional:
//   maxResults: Maximum number of entries returned on one result page. If not
//     set, the default is 100. Optional. (1..1000)
//   pageToken: A continuation token, used to page through performance reports.
//     To retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response. Optional.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerPerformanceReportList.
+ (instancetype)queryForPerformanceReportListWithAccountId:(long long)accountId
                                               endDateTime:(NSString *)endDateTime
                                             startDateTime:(NSString *)startDateTime;

#pragma mark - "pretargetingConfig" methods
// These create a GTLQueryAdExchangeBuyer object.

// Method: adexchangebuyer.pretargetingConfig.delete
// Deletes an existing pretargeting config.
//  Required:
//   accountId: The account id to delete the pretargeting config for.
//   configId: The specific id of the configuration to delete.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
+ (instancetype)queryForPretargetingConfigDeleteWithAccountId:(long long)accountId
                                                     configId:(long long)configId;

// Method: adexchangebuyer.pretargetingConfig.get
// Gets a specific pretargeting configuration
//  Required:
//   accountId: The account id to get the pretargeting config for.
//   configId: The specific id of the configuration to retrieve.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerPretargetingConfig.
+ (instancetype)queryForPretargetingConfigGetWithAccountId:(long long)accountId
                                                  configId:(long long)configId;

// Method: adexchangebuyer.pretargetingConfig.insert
// Inserts a new pretargeting configuration.
//  Required:
//   accountId: The account id to insert the pretargeting config for.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerPretargetingConfig.
+ (instancetype)queryForPretargetingConfigInsertWithObject:(GTLAdExchangeBuyerPretargetingConfig *)object
                                                 accountId:(long long)accountId;

// Method: adexchangebuyer.pretargetingConfig.list
// Retrieves a list of the authenticated user's pretargeting configurations.
//  Required:
//   accountId: The account id to get the pretargeting configs for.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerPretargetingConfigList.
+ (instancetype)queryForPretargetingConfigListWithAccountId:(long long)accountId;

// Method: adexchangebuyer.pretargetingConfig.patch
// Updates an existing pretargeting config. This method supports patch
// semantics.
//  Required:
//   accountId: The account id to update the pretargeting config for.
//   configId: The specific id of the configuration to update.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerPretargetingConfig.
+ (instancetype)queryForPretargetingConfigPatchWithObject:(GTLAdExchangeBuyerPretargetingConfig *)object
                                                accountId:(long long)accountId
                                                 configId:(long long)configId;

// Method: adexchangebuyer.pretargetingConfig.update
// Updates an existing pretargeting config.
//  Required:
//   accountId: The account id to update the pretargeting config for.
//   configId: The specific id of the configuration to update.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerPretargetingConfig.
+ (instancetype)queryForPretargetingConfigUpdateWithObject:(GTLAdExchangeBuyerPretargetingConfig *)object
                                                 accountId:(long long)accountId
                                                  configId:(long long)configId;

@end
