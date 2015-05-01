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
//  GTLAdExchangeBuyerBudget.h
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
//   GTLAdExchangeBuyerBudget (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerBudget
//

// The configuration data for Ad Exchange RTB - Budget API.

@interface GTLAdExchangeBuyerBudget : GTLObject

// The id of the account. This is required for get and update requests.
@property (nonatomic, retain) NSNumber *accountId;  // longLongValue

// The billing id to determine which adgroup to provide budget information for.
// This is required for get and update requests.
@property (nonatomic, retain) NSNumber *billingId;  // longLongValue

// The budget amount to apply for the billingId provided. This is required for
// update requests.
@property (nonatomic, retain) NSNumber *budgetAmount;  // longLongValue

// The currency code for the buyer. This cannot be altered here.
@property (nonatomic, copy) NSString *currencyCode;

// The unique id that describes this item.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The kind of the resource, i.e. "adexchangebuyer#budget".
@property (nonatomic, copy) NSString *kind;

@end
