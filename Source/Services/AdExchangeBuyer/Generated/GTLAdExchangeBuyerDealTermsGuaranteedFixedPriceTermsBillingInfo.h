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
//  GTLAdExchangeBuyerDealTermsGuaranteedFixedPriceTermsBillingInfo.h
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
//   GTLAdExchangeBuyerDealTermsGuaranteedFixedPriceTermsBillingInfo (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerPrice;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerDealTermsGuaranteedFixedPriceTermsBillingInfo
//

@interface GTLAdExchangeBuyerDealTermsGuaranteedFixedPriceTermsBillingInfo : GTLObject

// The timestamp (in ms since epoch) when the original reservation price for the
// deal was first converted to DFP currency. This is used to convert the
// contracted price into advertiser's currency without discrepancy.
@property (nonatomic, retain) NSNumber *currencyConversionTimeMs;  // longLongValue

// The original contracted quantity (# impressions) for this deal. To ensure
// delivery, sometimes publisher will book the deal with a impression buffer,
// however clients are billed using the original contracted quantity.
@property (nonatomic, retain) NSNumber *originalContractedQuantity;  // longLongValue

// The original reservation price for the deal, if the currency code is
// different from the one used in negotiation.
@property (nonatomic, retain) GTLAdExchangeBuyerPrice *price;

@end
