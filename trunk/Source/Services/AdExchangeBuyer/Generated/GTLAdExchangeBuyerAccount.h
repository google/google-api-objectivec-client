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
//  GTLAdExchangeBuyerAccount.h
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
//   GTLAdExchangeBuyerAccount (0 custom class methods, 8 custom properties)
//   GTLAdExchangeBuyerAccountBidderLocationItem (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerAccountBidderLocationItem;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerAccount
//

// Configuration data for an Ad Exchange buyer account.

@interface GTLAdExchangeBuyerAccount : GTLObject

// Your bidder locations that have distinct URLs.
@property (nonatomic, retain) NSArray *bidderLocation;  // of GTLAdExchangeBuyerAccountBidderLocationItem

// The nid parameter value used in cookie match requests. Please contact your
// technical account manager if you need to change this.
@property (nonatomic, copy) NSString *cookieMatchingNid;

// The base URL used in cookie match requests.
@property (nonatomic, copy) NSString *cookieMatchingUrl;

// Account id.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, retain) NSNumber *identifier;  // intValue

// Resource type.
@property (nonatomic, copy) NSString *kind;

// The maximum number of active creatives that an account can have, where a
// creative is active if it was inserted or bid with in the last 30 days. Please
// contact your technical account manager if you need to change this.
@property (nonatomic, retain) NSNumber *maximumActiveCreatives;  // intValue

// The sum of all bidderLocation.maximumQps values cannot exceed this. Please
// contact your technical account manager if you need to change this.
@property (nonatomic, retain) NSNumber *maximumTotalQps;  // intValue

// The number of creatives that this account inserted or bid with in the last 30
// days.
@property (nonatomic, retain) NSNumber *numberActiveCreatives;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerAccountBidderLocationItem
//

@interface GTLAdExchangeBuyerAccountBidderLocationItem : GTLObject

// The maximum queries per second the Ad Exchange will send.
@property (nonatomic, retain) NSNumber *maximumQps;  // intValue

// The geographical region the Ad Exchange should send requests from. Only used
// by some quota systems, but always setting the value is recommended. Allowed
// values:
// - ASIA
// - EUROPE
// - US_EAST
// - US_WEST
@property (nonatomic, copy) NSString *region;

// The URL to which the Ad Exchange will send bid requests.
@property (nonatomic, copy) NSString *url;

@end
