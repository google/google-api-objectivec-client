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
//  GTLAdExchangeBuyerProposal.h
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
//   GTLAdExchangeBuyerProposal (0 custom class methods, 22 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerBuyer;
@class GTLAdExchangeBuyerContactInformation;
@class GTLAdExchangeBuyerMarketplaceLabel;
@class GTLAdExchangeBuyerPrivateData;
@class GTLAdExchangeBuyerSeller;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerProposal
//

// Represents a proposal in the marketplace. A proposal is the unit of
// negotiation between a seller and a buyer and contains deals which are served.
// Each field in a proposal can have one of the following setting:
// (readonly) - It is an error to try and set this field. (buyer-readonly) -
// Only the seller can set this field. (seller-readonly) - Only the buyer can
// set this field. (updatable) - The field is updatable at all times by either
// buyer or the seller.

@interface GTLAdExchangeBuyerProposal : GTLObject

// Reference to the buyer that will get billed for this proposal. (readonly)
@property (nonatomic, retain) GTLAdExchangeBuyerBuyer *billedBuyer;

// Reference to the buyer on the proposal. (readonly, except on create)
@property (nonatomic, retain) GTLAdExchangeBuyerBuyer *buyer;

// Optional contact information fort the buyer. (seller-readonly)
@property (nonatomic, retain) NSArray *buyerContacts;  // of GTLAdExchangeBuyerContactInformation

// Private data for buyer. (hidden from seller).
@property (nonatomic, retain) GTLAdExchangeBuyerPrivateData *buyerPrivateData;

// When an proposal is in an accepted state, indicates whether the buyer has
// signed off Once both sides have signed off on a deal, the proposal can be
// finalized by the seller. (seller-readonly)
@property (nonatomic, retain) NSNumber *hasBuyerSignedOff;  // boolValue

// When an proposal is in an accepted state, indicates whether the buyer has
// signed off Once both sides have signed off on a deal, the proposal can be
// finalized by the seller. (buyer-readonly)
@property (nonatomic, retain) NSNumber *hasSellerSignedOff;  // boolValue

// What exchange will provide this inventory (readonly, except on create).
@property (nonatomic, copy) NSString *inventorySource;

// True if the proposal is being renegotiated (readonly).
@property (nonatomic, retain) NSNumber *isRenegotiating;  // boolValue

// True, if the buyside inventory setup is complete for this proposal.
// (readonly, except via OrderSetupCompleted action)
@property (nonatomic, retain) NSNumber *isSetupComplete;  // boolValue

// Identifies what kind of resource this is. Value: the fixed string
// "adexchangebuyer#proposal".
@property (nonatomic, copy) NSString *kind;

// List of labels associated with the proposal. (readonly)
@property (nonatomic, retain) NSArray *labels;  // of GTLAdExchangeBuyerMarketplaceLabel

// The role of the last user that either updated the proposal or left a comment.
// (readonly)
@property (nonatomic, copy) NSString *lastUpdaterOrCommentorRole;

// The name for the proposal (updatable)
@property (nonatomic, copy) NSString *name;

// Optional negotiation id if this proposal is a preferred deal proposal.
@property (nonatomic, copy) NSString *negotiationId;

// Indicates whether the buyer/seller created the proposal.(readonly)
@property (nonatomic, copy) NSString *originatorRole;

// Optional private auction id if this proposal is a private auction proposal.
@property (nonatomic, copy) NSString *privateAuctionId;

// The unique id of the proposal. (readonly).
@property (nonatomic, copy) NSString *proposalId;

// The current state of the proposal. (readonly)
@property (nonatomic, copy) NSString *proposalState;

// The revision number for the proposal (readonly).
@property (nonatomic, retain) NSNumber *revisionNumber;  // longLongValue

// The time (ms since epoch) when the proposal was last revised (readonly).
@property (nonatomic, retain) NSNumber *revisionTimeMs;  // longLongValue

// Reference to the seller on the proposal. (readonly, except on create)
@property (nonatomic, retain) GTLAdExchangeBuyerSeller *seller;

// Optional contact information for the seller (buyer-readonly).
@property (nonatomic, retain) NSArray *sellerContacts;  // of GTLAdExchangeBuyerContactInformation

@end
