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
//  GTLAdExchangeBuyerDealTermsGuaranteedFixedPriceTerms.h
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
//   GTLAdExchangeBuyerDealTermsGuaranteedFixedPriceTerms (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerDealTermsGuaranteedFixedPriceTermsBillingInfo;
@class GTLAdExchangeBuyerPricePerBuyer;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerDealTermsGuaranteedFixedPriceTerms
//

@interface GTLAdExchangeBuyerDealTermsGuaranteedFixedPriceTerms : GTLObject

// External billing info for this Deal. This field is relevant when external
// billing info such as price has a different currency code than DFP/AdX.
@property (nonatomic, retain) GTLAdExchangeBuyerDealTermsGuaranteedFixedPriceTermsBillingInfo *billingInfo;

// Fixed price for the specified buyer.
@property (nonatomic, retain) NSArray *fixedPrices;  // of GTLAdExchangeBuyerPricePerBuyer

// Guaranteed impressions as a percentage. This is the percentage of guaranteed
// looks that the buyer is guaranteeing to buy.
@property (nonatomic, retain) NSNumber *guaranteedImpressions;  // longLongValue

// Count of guaranteed looks. Required for deal, optional for product.
@property (nonatomic, retain) NSNumber *guaranteedLooks;  // longLongValue

@end
