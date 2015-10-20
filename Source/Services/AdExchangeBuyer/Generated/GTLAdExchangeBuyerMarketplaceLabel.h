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
//  GTLAdExchangeBuyerMarketplaceLabel.h
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
//   GTLAdExchangeBuyerMarketplaceLabel (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerMarketplaceDealParty;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerMarketplaceLabel
//

@interface GTLAdExchangeBuyerMarketplaceLabel : GTLObject

// The accountId of the party that created the label.
@property (nonatomic, copy) NSString *accountId;

// The creation time (in ms since epoch) for the label.
@property (nonatomic, retain) NSNumber *createTimeMs;  // longLongValue

// Information about the party that created the label.
@property (nonatomic, retain) GTLAdExchangeBuyerMarketplaceDealParty *deprecatedMarketplaceDealParty;

// The label to use.
@property (nonatomic, copy) NSString *label;

@end
