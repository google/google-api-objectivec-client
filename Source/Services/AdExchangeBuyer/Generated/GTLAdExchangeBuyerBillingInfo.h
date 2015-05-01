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
//  GTLAdExchangeBuyerBillingInfo.h
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
//   GTLAdExchangeBuyerBillingInfo (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerBillingInfo
//

// The configuration data for an Ad Exchange billing info.

@interface GTLAdExchangeBuyerBillingInfo : GTLObject

// Account id.
@property (nonatomic, retain) NSNumber *accountId;  // intValue

// Account name.
@property (nonatomic, copy) NSString *accountName;

// A list of adgroup IDs associated with this particular account. These IDs may
// show up as part of a realtime bidding BidRequest, which indicates a bid
// request for this account.
@property (nonatomic, retain) NSArray *billingId;  // of NSString

// Resource type.
@property (nonatomic, copy) NSString *kind;

@end
