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
//  GTLAdExchangeBuyerDirectDeal.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Ad Exchange Buyer API (adexchangebuyer/v1.3)
// Description:
//   Accesses your bidding-account information, submits creatives for
//   validation, finds available direct deals, and retrieves performance
//   reports.
// Documentation:
//   https://developers.google.com/ad-exchange/buyer-rest
// Classes:
//   GTLAdExchangeBuyerDirectDeal (0 custom class methods, 12 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerDirectDeal
//

// The configuration data for an Ad Exchange direct deal.

@interface GTLAdExchangeBuyerDirectDeal : GTLObject

// The account id of the buyer this deal is for.
@property (nonatomic, retain) NSNumber *accountId;  // intValue

// The name of the advertiser this deal is for.
@property (nonatomic, copy) NSString *advertiser;

// The currency code that applies to the fixed_cpm value. If not set then
// assumed to be USD.
@property (nonatomic, copy) NSString *currencyCode;

// End time for when this deal stops being active. If not set then this deal is
// valid until manually disabled by the publisher. In seconds since the epoch.
@property (nonatomic, retain) NSNumber *endTime;  // longLongValue

// The fixed price for this direct deal. In cpm micros of currency according to
// currency_code. If set, then this deal is eligible for the fixed price tier of
// buying (highest priority, pay exactly the configured fixed price).
@property (nonatomic, retain) NSNumber *fixedCpm;  // longLongValue

// Deal id.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, retain) NSNumber *identifier;  // longLongValue

// Resource type.
@property (nonatomic, copy) NSString *kind;

// Deal name.
@property (nonatomic, copy) NSString *name;

// The minimum price for this direct deal. In cpm micros of currency according
// to currency_code. If set, then this deal is eligible for the private exchange
// tier of buying (below fixed price priority, run as a second price auction).
@property (nonatomic, retain) NSNumber *privateExchangeMinCpm;  // longLongValue

// If true, the publisher has opted to have their blocks ignored when a creative
// is bid with for this deal.
@property (nonatomic, retain) NSNumber *publisherBlocksOverriden;  // boolValue

// The name of the publisher offering this direct deal.
@property (nonatomic, copy) NSString *sellerNetwork;

// Start time for when this deal becomes active. If not set then this deal is
// active immediately upon creation. In seconds since the epoch.
@property (nonatomic, retain) NSNumber *startTime;  // longLongValue

@end
