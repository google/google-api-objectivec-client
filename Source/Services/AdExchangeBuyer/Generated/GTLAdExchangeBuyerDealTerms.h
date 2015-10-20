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
//  GTLAdExchangeBuyerDealTerms.h
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
//   GTLAdExchangeBuyerDealTerms (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerDealTermsGuaranteedFixedPriceTerms;
@class GTLAdExchangeBuyerDealTermsNonGuaranteedAuctionTerms;
@class GTLAdExchangeBuyerDealTermsNonGuaranteedFixedPriceTerms;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerDealTerms
//

@interface GTLAdExchangeBuyerDealTerms : GTLObject

// Description for the proposed terms of the deal.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// The terms for guaranteed fixed price deals.
@property (nonatomic, retain) GTLAdExchangeBuyerDealTermsGuaranteedFixedPriceTerms *guaranteedFixedPriceTerms;

// The terms for non-guaranteed auction deals.
@property (nonatomic, retain) GTLAdExchangeBuyerDealTermsNonGuaranteedAuctionTerms *nonGuaranteedAuctionTerms;

// The terms for non-guaranteed fixed price deals.
@property (nonatomic, retain) GTLAdExchangeBuyerDealTermsNonGuaranteedFixedPriceTerms *nonGuaranteedFixedPriceTerms;

@end
