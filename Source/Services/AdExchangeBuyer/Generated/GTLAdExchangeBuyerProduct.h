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
//  GTLAdExchangeBuyerProduct.h
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
//   GTLAdExchangeBuyerProduct (0 custom class methods, 23 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerContactInformation;
@class GTLAdExchangeBuyerDealTerms;
@class GTLAdExchangeBuyerDeliveryControl;
@class GTLAdExchangeBuyerMarketplaceLabel;
@class GTLAdExchangeBuyerPublisherProvidedForecast;
@class GTLAdExchangeBuyerSeller;
@class GTLAdExchangeBuyerSharedTargeting;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerProduct
//

// A product is segment of inventory that a seller wishes to sell. It is
// associated with certain terms and targeting information which helps buyer
// know more about the inventory. Each field in a product can have one of the
// following setting:
// (readonly) - It is an error to try and set this field. (buyer-readonly) -
// Only the seller can set this field. (seller-readonly) - Only the buyer can
// set this field. (updatable) - The field is updatable at all times by either
// buyer or the seller.

@interface GTLAdExchangeBuyerProduct : GTLObject

// Creation time in ms. since epoch (readonly)
@property (nonatomic, retain) NSNumber *creationTimeMs;  // longLongValue

// Optional contact information for the creator of this product.
// (buyer-readonly)
@property (nonatomic, retain) NSArray *creatorContacts;  // of GTLAdExchangeBuyerContactInformation

// The set of fields around delivery control that are interesting for a buyer to
// see but are non-negotiable. These are set by the publisher. This message is
// assigned an id of 100 since some day we would want to model this as a
// protobuf extension.
@property (nonatomic, retain) GTLAdExchangeBuyerDeliveryControl *deliveryControl;

// The proposed end time for the deal (ms since epoch) (buyer-readonly)
@property (nonatomic, retain) NSNumber *flightEndTimeMs;  // longLongValue

// Inventory availability dates. (times are in ms since epoch) The granularity
// is generally in the order of seconds. (buyer-readonly)
@property (nonatomic, retain) NSNumber *flightStartTimeMs;  // longLongValue

// If the creator has already signed off on the product, then the buyer can
// finalize the deal by accepting the product as is. When copying to a proposal,
// if any of the terms are changed, then auto_finalize is automatically set to
// false.
@property (nonatomic, retain) NSNumber *hasCreatorSignedOff;  // boolValue

// What exchange will provide this inventory (readonly, except on create).
@property (nonatomic, copy) NSString *inventorySource;

// Identifies what kind of resource this is. Value: the fixed string
// "adexchangebuyer#product".
@property (nonatomic, copy) NSString *kind;

// Optional List of labels for the product (optional, buyer-readonly).
@property (nonatomic, retain) NSArray *labels;  // of GTLAdExchangeBuyerMarketplaceLabel

// Time of last update in ms. since epoch (readonly)
@property (nonatomic, retain) NSNumber *lastUpdateTimeMs;  // longLongValue

// Optional legacy offer id if this offer is a preferred deal offer.
@property (nonatomic, copy) NSString *legacyOfferId;

// The name for this product as set by the seller. (buyer-readonly)
@property (nonatomic, copy) NSString *name;

// Optional private auction id if this offer is a private auction offer.
@property (nonatomic, copy) NSString *privateAuctionId;

// The unique id for the product (readonly)
@property (nonatomic, copy) NSString *productId;

// Id of the publisher profile for a given seller. A (seller.account_id,
// publisher_profile_id) pair uniquely identifies a publisher profile. Buyers
// can call the PublisherProfiles::List endpoint to get a list of publisher
// profiles for a given seller.
@property (nonatomic, copy) NSString *publisherProfileId;

// Publisher self-provided forecast information.
@property (nonatomic, retain) GTLAdExchangeBuyerPublisherProvidedForecast *publisherProvidedForecast;

// The revision number of the product. (readonly)
@property (nonatomic, retain) NSNumber *revisionNumber;  // longLongValue

// Information about the seller that created this product (readonly, except on
// create)
@property (nonatomic, retain) GTLAdExchangeBuyerSeller *seller;

// Targeting that is shared between the buyer and the seller. Each targeting
// criteria has a specified key and for each key there is a list of inclusion
// value or exclusion values. (buyer-readonly)
@property (nonatomic, retain) NSArray *sharedTargetings;  // of GTLAdExchangeBuyerSharedTargeting

// The state of the product. (buyer-readonly)
@property (nonatomic, copy) NSString *state;

// The syndication product associated with the deal. (readonly, except on
// create)
@property (nonatomic, copy) NSString *syndicationProduct;

// The negotiable terms of the deal (buyer-readonly)
@property (nonatomic, retain) GTLAdExchangeBuyerDealTerms *terms;

// The web property code for the seller. This field is meant to be copied over
// as is when creating deals.
@property (nonatomic, copy) NSString *webPropertyCode;

@end
