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
//  GTLAdExchangeBuyerNegotiationDto.m
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

#import "GTLAdExchangeBuyerNegotiationDto.h"

#import "GTLAdExchangeBuyerDealPartyDto.h"
#import "GTLAdExchangeBuyerNegotiationRoundDto.h"
#import "GTLAdExchangeBuyerStatsDto.h"

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerNegotiationDto
//

@implementation GTLAdExchangeBuyerNegotiationDto
@dynamic billedBuyer, buyer, buyerEmailContacts, dealType, externalDealId, kind,
         labelNames, negotiationId, negotiationRounds, negotiationState,
         offerId, seller, sellerEmailContacts, stats, status;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"buyerEmailContacts" : [NSString class],
    @"labelNames" : [NSString class],
    @"negotiationRounds" : [GTLAdExchangeBuyerNegotiationRoundDto class],
    @"sellerEmailContacts" : [NSString class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"adexchangebuyer#negotiation"];
}

@end
