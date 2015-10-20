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
//  GTLAdExchangeBuyerTermsDto.h
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
//   GTLAdExchangeBuyerTermsDto (0 custom class methods, 27 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerAdSlotDto;
@class GTLAdExchangeBuyerAdvertiserDto;
@class GTLAdExchangeBuyerAudienceSegment;
@class GTLAdExchangeBuyerDateTime;
@class GTLAdExchangeBuyerInventorySegmentTargeting;
@class GTLAdExchangeBuyerMoneyDto;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerTermsDto
//

@interface GTLAdExchangeBuyerTermsDto : GTLObject

// The particular ad slots targeted by the offer.
@property (nonatomic, retain) NSArray *adSlots;  // of GTLAdExchangeBuyerAdSlotDto

// A list of advertisers for this offer.
@property (nonatomic, retain) NSArray *advertisers;  // of GTLAdExchangeBuyerAdvertiserDto

// The audience segment for the offer.
@property (nonatomic, retain) GTLAdExchangeBuyerAudienceSegment *audienceSegment;

// A description of the audience segment for the offer.
@property (nonatomic, copy) NSString *audienceSegmentDescription;

// The billing terms.
@property (nonatomic, copy) NSString *billingTerms;

// The buyer billing type.
@property (nonatomic, copy) NSString *buyerBillingType;

// The cpm terms.
@property (nonatomic, retain) GTLAdExchangeBuyerMoneyDto *cpm;

// Whether to use or ignore publisher blocking rules.
@property (nonatomic, copy) NSString *creativeBlockingLevel;

// Whether to use publisher review policy or AdX review policy.
@property (nonatomic, copy) NSString *creativeReviewPolicy;

// The premium terms.
@property (nonatomic, retain) GTLAdExchangeBuyerMoneyDto *dealPremium;

// A description for these terms.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// A descriptive name for these terms.
@property (nonatomic, copy) NSString *descriptiveName;

// The end date for the offer.
@property (nonatomic, retain) GTLAdExchangeBuyerDateTime *endDate;

// The estimated daily impressions for the offer.
@property (nonatomic, retain) NSNumber *estimatedImpressionsPerDay;  // longLongValue

// The estimated spend for the offer.
@property (nonatomic, retain) GTLAdExchangeBuyerMoneyDto *estimatedSpend;

// If true, the offer will finalize automatically when accepted.
@property (nonatomic, retain) NSNumber *finalizeAutomatically;  // boolValue

// The inventory segment targeting for the offer.
@property (nonatomic, retain) GTLAdExchangeBuyerInventorySegmentTargeting *inventorySegmentTargeting;

// Whether the offer is a reservation.
@property (nonatomic, retain) NSNumber *isReservation;  // boolValue

// The minimum spend for the offer.
@property (nonatomic, retain) NSNumber *minimumSpendMicros;  // longLongValue

// The minimum true looks for the offer.
@property (nonatomic, retain) NSNumber *minimumTrueLooks;  // longLongValue

// The monetizer type.
@property (nonatomic, copy) NSString *monetizerType;

// Whether this offer is semi-transparent.
@property (nonatomic, retain) NSNumber *semiTransparent;  // boolValue

// The start date for the offer.
@property (nonatomic, retain) GTLAdExchangeBuyerDateTime *startDate;

// Whether to target by deal id.
@property (nonatomic, retain) NSNumber *targetByDealId;  // boolValue

// If true, the offer targets all ad slots.
@property (nonatomic, retain) NSNumber *targetingAllAdSlots;  // boolValue

// A list of terms attributes.
@property (nonatomic, retain) NSArray *termsAttributes;  // of NSString

// The urls applicable to the offer.
@property (nonatomic, retain) NSArray *urls;  // of NSString

@end
