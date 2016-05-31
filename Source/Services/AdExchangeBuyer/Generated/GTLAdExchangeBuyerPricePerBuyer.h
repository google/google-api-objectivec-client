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
//  GTLAdExchangeBuyerPricePerBuyer.h
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
//   GTLAdExchangeBuyerPricePerBuyer (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerBuyer;
@class GTLAdExchangeBuyerPrice;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerPricePerBuyer
//

// Used to specify pricing rules for buyers/advertisers. Each PricePerBuyer in
// an product can become [0,1] deals. To check if there is a PricePerBuyer for a
// particular buyer or buyer/advertiser pair, we look for the most specific
// matching rule - we first look for a rule matching the buyer and advertiser,
// next a rule with the buyer but an empty advertiser list, and otherwise look
// for a matching rule where no buyer is set.

@interface GTLAdExchangeBuyerPricePerBuyer : GTLObject

// Optional access type for this buyer.
@property (nonatomic, copy) NSString *auctionTier;

// The buyer who will pay this price. If unset, all buyers can pay this price
// (if the advertisers match, and there's no more specific rule matching the
// buyer).
@property (nonatomic, retain) GTLAdExchangeBuyerBuyer *buyer;

// The specified price
@property (nonatomic, retain) GTLAdExchangeBuyerPrice *price;

@end
