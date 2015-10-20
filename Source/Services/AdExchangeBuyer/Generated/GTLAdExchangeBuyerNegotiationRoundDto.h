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
//  GTLAdExchangeBuyerNegotiationRoundDto.h
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
//   GTLAdExchangeBuyerNegotiationRoundDto (0 custom class methods, 9 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerEditHistoryDto;
@class GTLAdExchangeBuyerTermsDto;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerNegotiationRoundDto
//

@interface GTLAdExchangeBuyerNegotiationRoundDto : GTLObject

// The action performed by this negotiation round.
@property (nonatomic, copy) NSString *action;

// Stores DBM partner ID for use by DBM
@property (nonatomic, retain) NSNumber *dbmPartnerId;  // longLongValue

// The edit history of this negotiation round.
@property (nonatomic, retain) GTLAdExchangeBuyerEditHistoryDto *editHistory;

@property (nonatomic, copy) NSString *kind;

// The ID of the negotiation to which this negotiation round applies.
@property (nonatomic, retain) NSNumber *negotiationId;  // longLongValue

// Notes regarding this negotiation round.
@property (nonatomic, copy) NSString *notes;

// The role, either buyer or seller, initiating this negotiation round.
@property (nonatomic, copy) NSString *originatorRole;

// The number of this negotiation round, in sequence.
@property (nonatomic, retain) NSNumber *roundNumber;  // longLongValue

// The detailed terms proposed in this negotiation round.
@property (nonatomic, retain) GTLAdExchangeBuyerTermsDto *terms;

@end
