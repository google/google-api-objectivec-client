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
//  GTLAdExchangeBuyerMarketplaceOffer.h
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
//   GTLAdExchangeBuyerMarketplaceOffer (0 custom class methods, 17 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerContactInformation;
@class GTLAdExchangeBuyerDealTerms;
@class GTLAdExchangeBuyerMarketplaceLabel;
@class GTLAdExchangeBuyerSeller;
@class GTLAdExchangeBuyerSharedTargeting;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerMarketplaceOffer
//

// An offer is segment of inventory that a seller wishes to sell. It is
// associated with certain terms and targeting information which helps buyer
// know more about the inventory. Each field in an order can have one of the
// following setting:
// (readonly) - It is an error to try and set this field. (buyer-readonly) -
// Only the seller can set this field. (seller-readonly) - Only the buyer can
// set this field. (updatable) - The field is updatable at all times by either
// buyer or the seller.

@interface GTLAdExchangeBuyerMarketplaceOffer : GTLObject

// Creation time in ms. since epoch (readonly)
@property (nonatomic, retain) NSNumber *creationTimeMs;  // longLongValue

// Optional contact information for the creator of this offer. (buyer-readonly)
@property (nonatomic, retain) NSArray *creatorContacts;  // of GTLAdExchangeBuyerContactInformation

// The proposed end time for the deal (ms since epoch) (buyer-readonly)
@property (nonatomic, retain) NSNumber *flightEndTimeMs;  // longLongValue

// Inventory availability dates. (times are in ms since epoch) The granularity
// is generally in the order of seconds. (buyer-readonly)
@property (nonatomic, retain) NSNumber *flightStartTimeMs;  // longLongValue

// If the creator has already signed off on the offer, then the buyer can
// finalize the deal by accepting the offer as is. When copying to an order, if
// any of the terms are changed, then auto_finalize is automatically set to
// false.
@property (nonatomic, retain) NSNumber *hasCreatorSignedOff;  // boolValue

// Identifies what kind of resource this is. Value: the fixed string
// "adexchangebuyer#marketplaceOffer".
@property (nonatomic, copy) NSString *kind;

// Optional List of labels for the offer (optional, buyer-readonly).
@property (nonatomic, retain) NSArray *labels;  // of GTLAdExchangeBuyerMarketplaceLabel

// Time of last update in ms. since epoch (readonly)
@property (nonatomic, retain) NSNumber *lastUpdateTimeMs;  // longLongValue

// The name for this offer as set by the seller. (buyer-readonly)
@property (nonatomic, copy) NSString *name;

// The unique id for the offer (readonly)
@property (nonatomic, copy) NSString *offerId;

// The revision number of the offer. (readonly)
@property (nonatomic, retain) NSNumber *revisionNumber;  // longLongValue

// Information about the seller that created this offer (readonly, except on
// create)
@property (nonatomic, retain) GTLAdExchangeBuyerSeller *seller;

// Targeting that is shared between the buyer and the seller. Each targeting
// criteria has a specified key and for each key there is a list of inclusion
// value or exclusion values. (buyer-readonly)
@property (nonatomic, retain) NSArray *sharedTargetings;  // of GTLAdExchangeBuyerSharedTargeting

// The state of the offer. (buyer-readonly)
@property (nonatomic, copy) NSString *state;

// The syndication product associated with the deal. (readonly, except on
// create)
@property (nonatomic, copy) NSString *syndicationProduct;

// The negotiable terms of the deal (buyer-readonly)
@property (nonatomic, retain) GTLAdExchangeBuyerDealTerms *terms;

@property (nonatomic, copy) NSString *webPropertyCode;
@end
