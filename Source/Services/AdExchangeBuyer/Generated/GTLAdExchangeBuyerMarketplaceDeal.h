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
//  GTLAdExchangeBuyerMarketplaceDeal.h
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
//   GTLAdExchangeBuyerMarketplaceDeal (0 custom class methods, 23 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerContactInformation;
@class GTLAdExchangeBuyerDealServingMetadata;
@class GTLAdExchangeBuyerDealTerms;
@class GTLAdExchangeBuyerDeliveryControl;
@class GTLAdExchangeBuyerPrivateData;
@class GTLAdExchangeBuyerSharedTargeting;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerMarketplaceDeal
//

// A proposal can contain multiple deals. A deal contains the terms and
// targeting information that is used for serving.

@interface GTLAdExchangeBuyerMarketplaceDeal : GTLObject

// Buyer private data (hidden from seller).
@property (nonatomic, retain) GTLAdExchangeBuyerPrivateData *buyerPrivateData;

// The time (ms since epoch) of the deal creation. (readonly)
@property (nonatomic, retain) NSNumber *creationTimeMs;  // longLongValue

// Specifies the creative pre-approval policy (buyer-readonly)
@property (nonatomic, copy) NSString *creativePreApprovalPolicy;

// Specifies whether the creative is safeFrame compatible (buyer-readonly)
@property (nonatomic, copy) NSString *creativeSafeFrameCompatibility;

// A unique deal=id for the deal (readonly).
@property (nonatomic, copy) NSString *dealId;

// Metadata about the serving status of this deal (readonly, writes via custom
// actions)
@property (nonatomic, retain) GTLAdExchangeBuyerDealServingMetadata *dealServingMetadata;

// The set of fields around delivery control that are interesting for a buyer to
// see but are non-negotiable. These are set by the publisher. This message is
// assigned an id of 100 since some day we would want to model this as a
// protobuf extension.
@property (nonatomic, retain) GTLAdExchangeBuyerDeliveryControl *deliveryControl;

// The external deal id assigned to this deal once the deal is finalized. This
// is the deal-id that shows up in serving/reporting etc. (readonly)
@property (nonatomic, copy) NSString *externalDealId;

// Proposed flight end time of the deal (ms since epoch) This will generally be
// stored in a granularity of a second. (updatable)
@property (nonatomic, retain) NSNumber *flightEndTimeMs;  // longLongValue

// Proposed flight start time of the deal (ms since epoch) This will generally
// be stored in a granularity of a second. (updatable)
@property (nonatomic, retain) NSNumber *flightStartTimeMs;  // longLongValue

// Description for the deal terms. (updatable)
@property (nonatomic, copy) NSString *inventoryDescription;

// Identifies what kind of resource this is. Value: the fixed string
// "adexchangebuyer#marketplaceDeal".
@property (nonatomic, copy) NSString *kind;

// The time (ms since epoch) when the deal was last updated. (readonly)
@property (nonatomic, retain) NSNumber *lastUpdateTimeMs;  // longLongValue

// The name of the deal. (updatable)
@property (nonatomic, copy) NSString *name;

// The product-id from which this deal was created. (readonly, except on create)
@property (nonatomic, copy) NSString *productId;

// The revision number of the product that the deal was created from (readonly,
// except on create)
@property (nonatomic, retain) NSNumber *productRevisionNumber;  // longLongValue

// Specifies the creative source for programmatic deals, PUBLISHER means
// creative is provided by seller and ADVERTISR means creative is provided by
// buyer. (buyer-readonly)
@property (nonatomic, copy) NSString *programmaticCreativeSource;

@property (nonatomic, copy) NSString *proposalId;

// Optional Seller contact information for the deal (buyer-readonly)
@property (nonatomic, retain) NSArray *sellerContacts;  // of GTLAdExchangeBuyerContactInformation

// The shared targeting visible to buyers and sellers. Each shared targeting
// entity is AND'd together. (updatable)
@property (nonatomic, retain) NSArray *sharedTargetings;  // of GTLAdExchangeBuyerSharedTargeting

// The syndication product associated with the deal. (readonly, except on
// create)
@property (nonatomic, copy) NSString *syndicationProduct;

// The negotiable terms of the deal. (updatable)
@property (nonatomic, retain) GTLAdExchangeBuyerDealTerms *terms;

@property (nonatomic, copy) NSString *webPropertyCode;
@end
