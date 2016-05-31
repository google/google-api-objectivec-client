/* Copyright (c) 2016 Google Inc.
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
//   GTLQueryAdExchangeBuyer (37 custom class methods, 29 custom properties)

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
@class GTLAdExchangeBuyerPretargetingConfig;
@class GTLAdExchangeBuyerProposal;

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
@property (nonatomic, assign) long long dealId;
@property (nonatomic, retain) NSArray *dealIds;  // of NSString
@property (nonatomic, retain) NSArray *deals;  // of GTLAdExchangeBuyerMarketplaceDeal
@property (nonatomic, copy) NSString *dealsStatusFilter;
@property (nonatomic, copy) NSString *endDateTime;
@property (nonatomic, copy) NSString *externalDealId;
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, assign) NSInteger identifier;
@property (nonatomic, assign) NSUInteger maxResults;
@property (nonatomic, retain) GTLAdExchangeBuyerMarketplaceNote *note;
@property (nonatomic, retain) NSArray *notes;  // of GTLAdExchangeBuyerMarketplaceNote
@property (nonatomic, copy) NSString *openAuctionStatusFilter;
@property (nonatomic, retain) GTLAdExchangeBuyerProposal *order;
@property (nonatomic, copy) NSString *pageToken;
@property (nonatomic, copy) NSString *pqlQuery;
@property (nonatomic, copy) NSString *privateAuctionId;
@property (nonatomic, copy) NSString *productId;
@property (nonatomic, retain) GTLAdExchangeBuyerProposal *proposal;
@property (nonatomic, copy) NSString *proposalId;
@property (nonatomic, assign) long long proposalRevisionNumber;
@property (nonatomic, retain) NSArray *proposals;  // of GTLAdExchangeBuyerProposal
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

// Method: adexchangebuyer.creatives.addDeal
// Add a deal id association for the creative.
//  Required:
//   accountId: The id for the account that will serve this creative.
//   buyerCreativeId: The buyer-specific id for this creative.
//   dealId: The id of the deal id to associate with this creative.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
+ (instancetype)queryForCreativesAddDealWithAccountId:(NSInteger)accountId
                                      buyerCreativeId:(NSString *)buyerCreativeId
                                               dealId:(long long)dealId;

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
//   dealsStatusFilter: When specified, only creatives having the given deals
//     status are returned.
//      kGTLAdExchangeBuyerDealsStatusFilterApproved: Creatives which have been
//        approved for serving on deals.
//      kGTLAdExchangeBuyerDealsStatusFilterConditionallyApproved: Creatives
//        which have been conditionally approved for serving on deals.
//      kGTLAdExchangeBuyerDealsStatusFilterDisapproved: Creatives which have
//        been disapproved for serving on deals.
//      kGTLAdExchangeBuyerDealsStatusFilterNotChecked: Creatives whose deals
//        status is not yet checked.
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

// Method: adexchangebuyer.creatives.removeDeal
// Remove a deal id associated with the creative.
//  Required:
//   accountId: The id for the account that will serve this creative.
//   buyerCreativeId: The buyer-specific id for this creative.
//   dealId: The id of the deal id to disassociate with this creative.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
+ (instancetype)queryForCreativesRemoveDealWithAccountId:(NSInteger)accountId
                                         buyerCreativeId:(NSString *)buyerCreativeId
                                                  dealId:(long long)dealId;

#pragma mark - "marketplacedeals" methods
// These create a GTLQueryAdExchangeBuyer object.

// Method: adexchangebuyer.marketplacedeals.delete
// Delete the specified deals from the proposal
//  Required:
//   proposalId: The proposalId to delete deals from.
//  Optional:
//   dealIds: List of deals to delete for a given proposal
//   proposalRevisionNumber: The last known proposal revision number.
//   updateAction: Indicates an optional action to take on the proposal
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerDeleteOrderDealsResponse.
+ (instancetype)queryForMarketplacedealsDeleteWithProposalId:(NSString *)proposalId;

// Method: adexchangebuyer.marketplacedeals.insert
// Add new deals for the specified proposal
//  Required:
//   proposalId: proposalId for which deals need to be added.
//  Optional:
//   deals: The list of deals to add
//   proposalRevisionNumber: The last known proposal revision number.
//   updateAction: Indicates an optional action to take on the proposal
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerAddOrderDealsResponse.
+ (instancetype)queryForMarketplacedealsInsertWithProposalId:(NSString *)proposalId;

// Method: adexchangebuyer.marketplacedeals.list
// List all the deals for a given proposal
//  Required:
//   proposalId: The proposalId to get deals for. To search across proposals
//     specify order_id = '-' as part of the URL.
//  Optional:
//   pqlQuery: Query string to retrieve specific deals.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerGetOrderDealsResponse.
+ (instancetype)queryForMarketplacedealsListWithProposalId:(NSString *)proposalId;

// Method: adexchangebuyer.marketplacedeals.update
// Replaces all the deals in the proposal with the passed in deals
//  Required:
//   proposalId: The proposalId to edit deals on.
//  Optional:
//   deals: List of deals to edit. Service may perform 3 different operations
//     based on comparison of deals in this list vs deals already persisted in
//     database: 1. Add new deal to proposal If a deal in this list does not
//     exist in the proposal, the service will create a new deal and add it to
//     the proposal. Validation will follow AddOrderDealsRequest. 2. Update
//     existing deal in the proposal If a deal in this list already exist in the
//     proposal, the service will update that existing deal to this new deal in
//     the request. Validation will follow UpdateOrderDealsRequest. 3. Delete
//     deals from the proposal (just need the id) If a existing deal in the
//     proposal is not present in this list, the service will delete that deal
//     from the proposal. Validation will follow DeleteOrderDealsRequest.
//   proposal: If specified, also updates the proposal in the batch transaction.
//     This is useful when the proposal and the deals need to be updated in one
//     transaction.
//   proposalRevisionNumber: The last known revision number for the proposal.
//   updateAction: Indicates an optional action to take on the proposal
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerEditAllOrderDealsResponse.
+ (instancetype)queryForMarketplacedealsUpdateWithProposalId:(NSString *)proposalId;

#pragma mark - "marketplacenotes" methods
// These create a GTLQueryAdExchangeBuyer object.

// Method: adexchangebuyer.marketplacenotes.insert
// Add notes to the proposal
//  Required:
//   proposalId: The proposalId to add notes for.
//  Optional:
//   notes: The list of notes to add.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerAddOrderNotesResponse.
+ (instancetype)queryForMarketplacenotesInsertWithProposalId:(NSString *)proposalId;

// Method: adexchangebuyer.marketplacenotes.list
// Get all the notes associated with a proposal
//  Required:
//   proposalId: The proposalId to get notes for.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerGetOrderNotesResponse.
+ (instancetype)queryForMarketplacenotesListWithProposalId:(NSString *)proposalId;

#pragma mark - "marketplaceprivateauction" methods
// These create a GTLQueryAdExchangeBuyer object.

// Method: adexchangebuyer.marketplaceprivateauction.updateproposal
// Update a given private auction proposal
//  Required:
//   privateAuctionId: The private auction id to be updated.
//  Optional:
//   externalDealId: The externalDealId of the deal to be updated.
//   note: Optional note to be added.
//   proposalRevisionNumber: The current revision number of the proposal to be
//     updated.
//   updateAction: The proposed action on the private auction proposal.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
+ (instancetype)queryForMarketplaceprivateauctionUpdateproposalWithPrivateAuctionId:(NSString *)privateAuctionId;

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

#pragma mark - "products" methods
// These create a GTLQueryAdExchangeBuyer object.

// Method: adexchangebuyer.products.get
// Gets the requested product by id.
//  Required:
//   productId: The id for the product to get the head revision for.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerProduct.
+ (instancetype)queryForProductsGetWithProductId:(NSString *)productId;

// Method: adexchangebuyer.products.search
// Gets the requested product.
//  Optional:
//   pqlQuery: The pql query used to query for products.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerGetOffersResponse.
+ (instancetype)queryForProductsSearch;

#pragma mark - "proposals" methods
// These create a GTLQueryAdExchangeBuyer object.

// Method: adexchangebuyer.proposals.get
// Get a proposal given its id
//  Required:
//   proposalId: Id of the proposal to retrieve.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerProposal.
+ (instancetype)queryForProposalsGetWithProposalId:(NSString *)proposalId;

// Method: adexchangebuyer.proposals.insert
// Create the given list of proposals
//  Optional:
//   proposals: The list of proposals to create.
//   webPropertyCode: Web property id of the seller creating these orders
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerCreateOrdersResponse.
+ (instancetype)queryForProposalsInsert;

// Method: adexchangebuyer.proposals.patch
// Update the given proposal. This method supports patch semantics.
//  Required:
//   proposalId: The proposal id to update.
//   revisionNumber: The last known revision number to update. If the head
//     revision in the marketplace database has since changed, an error will be
//     thrown. The caller should then fetch the latest proposal at head revision
//     and retry the update at that revision.
//   updateAction: The proposed action to take on the proposal.
//      kGTLAdExchangeBuyerUpdateActionAccept: "accept"
//      kGTLAdExchangeBuyerUpdateActionCancel: "cancel"
//      kGTLAdExchangeBuyerUpdateActionPropose: "propose"
//      kGTLAdExchangeBuyerUpdateActionUnknownAction: "unknownAction"
//      kGTLAdExchangeBuyerUpdateActionUpdateFinalized: "updateFinalized"
//  Optional:
//   order: GTLAdExchangeBuyerProposal
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerProposal.
+ (instancetype)queryForProposalsPatchWithProposalId:(NSString *)proposalId
                                      revisionNumber:(long long)revisionNumber
                                        updateAction:(NSString *)updateAction;

// Method: adexchangebuyer.proposals.search
// Search for proposals using pql query
//  Optional:
//   pqlQuery: Query string to retrieve specific proposals.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerGetOrdersResponse.
+ (instancetype)queryForProposalsSearch;

// Method: adexchangebuyer.proposals.setupcomplete
// Update the given proposal to indicate that setup has been completed.
//  Required:
//   proposalId: The proposal id for which the setup is complete
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
+ (instancetype)queryForProposalsSetupcompleteWithProposalId:(NSString *)proposalId;

// Method: adexchangebuyer.proposals.update
// Update the given proposal
//  Required:
//   proposalId: The proposal id to update.
//   revisionNumber: The last known revision number to update. If the head
//     revision in the marketplace database has since changed, an error will be
//     thrown. The caller should then fetch the latest proposal at head revision
//     and retry the update at that revision.
//   updateAction: The proposed action to take on the proposal.
//      kGTLAdExchangeBuyerUpdateActionAccept: "accept"
//      kGTLAdExchangeBuyerUpdateActionCancel: "cancel"
//      kGTLAdExchangeBuyerUpdateActionPropose: "propose"
//      kGTLAdExchangeBuyerUpdateActionUnknownAction: "unknownAction"
//      kGTLAdExchangeBuyerUpdateActionUpdateFinalized: "updateFinalized"
//  Optional:
//   order: GTLAdExchangeBuyerProposal
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerProposal.
+ (instancetype)queryForProposalsUpdateWithProposalId:(NSString *)proposalId
                                       revisionNumber:(long long)revisionNumber
                                         updateAction:(NSString *)updateAction;

#pragma mark - "pubprofiles" methods
// These create a GTLQueryAdExchangeBuyer object.

// Method: adexchangebuyer.pubprofiles.list
// Gets the requested publisher profile(s) by publisher accountId.
//  Required:
//   accountId: The accountId of the publisher to get profiles for.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeBuyerAdexchangeBuyer
// Fetches a GTLAdExchangeBuyerGetPublisherProfilesByAccountIdResponse.
+ (instancetype)queryForPubprofilesListWithAccountId:(NSInteger)accountId;

@end
