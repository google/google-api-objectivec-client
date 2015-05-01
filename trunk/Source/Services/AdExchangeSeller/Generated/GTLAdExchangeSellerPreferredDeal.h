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
//  GTLAdExchangeSellerPreferredDeal.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Ad Exchange Seller API (adexchangeseller/v2.0)
// Description:
//   Gives Ad Exchange seller users access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://developers.google.com/ad-exchange/seller-rest/
// Classes:
//   GTLAdExchangeSellerPreferredDeal (0 custom class methods, 8 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeSellerPreferredDeal
//

@interface GTLAdExchangeSellerPreferredDeal : GTLObject

// The name of the advertiser this deal is for.
@property (nonatomic, copy) NSString *advertiserName;

// The name of the buyer network this deal is for.
@property (nonatomic, copy) NSString *buyerNetworkName;

// The currency code that applies to the fixed_cpm value. If not set then
// assumed to be USD.
@property (nonatomic, copy) NSString *currencyCode;

// Time when this deal stops being active in seconds since the epoch (GMT). If
// not set then this deal is valid until manually disabled by the publisher.
@property (nonatomic, retain) NSNumber *endTime;  // unsignedLongLongValue

// The fixed price for this preferred deal. In cpm micros of currency according
// to currencyCode. If set, then this preferred deal is eligible for the fixed
// price tier of buying (highest priority, pay exactly the configured fixed
// price).
@property (nonatomic, retain) NSNumber *fixedCpm;  // longLongValue

// Unique identifier of this preferred deal.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, retain) NSNumber *identifier;  // longLongValue

// Kind of resource this is, in this case adexchangeseller#preferredDeal.
@property (nonatomic, copy) NSString *kind;

// Time when this deal becomes active in seconds since the epoch (GMT). If not
// set then this deal is active immediately upon creation.
@property (nonatomic, retain) NSNumber *startTime;  // unsignedLongLongValue

@end
