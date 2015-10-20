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
//  GTLAdExchangeBuyerNegotiationDto.h
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
//   GTLAdExchangeBuyerNegotiationDto (0 custom class methods, 15 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerDealPartyDto;
@class GTLAdExchangeBuyerNegotiationRoundDto;
@class GTLAdExchangeBuyerStatsDto;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerNegotiationDto
//

@interface GTLAdExchangeBuyerNegotiationDto : GTLObject

// The billed buyer; Specified by a buyer buying through an intermediary.
@property (nonatomic, retain) GTLAdExchangeBuyerDealPartyDto *billedBuyer;

// Details of the buyer party in this negotiation.
@property (nonatomic, retain) GTLAdExchangeBuyerDealPartyDto *buyer;

// The buyer party's contact email.
@property (nonatomic, retain) NSArray *buyerEmailContacts;  // of NSString

// The type of this deal.
@property (nonatomic, copy) NSString *dealType;

// For finalized negotiations, the ID of the finalized deal.
@property (nonatomic, retain) NSNumber *externalDealId;  // longLongValue

@property (nonatomic, copy) NSString *kind;

// A list of label names applicable to this negotiation.
@property (nonatomic, retain) NSArray *labelNames;  // of NSString

// The unique ID of this negotiation.
@property (nonatomic, retain) NSNumber *negotiationId;  // longLongValue

// The series of negotiation rounds for this negotiation.
@property (nonatomic, retain) NSArray *negotiationRounds;  // of GTLAdExchangeBuyerNegotiationRoundDto

// The state of this negotiation.
@property (nonatomic, copy) NSString *negotiationState;

// The ID of this negotiation's original offer.
@property (nonatomic, retain) NSNumber *offerId;  // longLongValue

// Details of the seller party in this negotiation.
@property (nonatomic, retain) GTLAdExchangeBuyerDealPartyDto *seller;

// The seller party's contact email.
@property (nonatomic, retain) NSArray *sellerEmailContacts;  // of NSString

// The stats for this negotiation.
@property (nonatomic, retain) GTLAdExchangeBuyerStatsDto *stats;

// The status of this negotiation.
@property (nonatomic, copy) NSString *status;

@end
