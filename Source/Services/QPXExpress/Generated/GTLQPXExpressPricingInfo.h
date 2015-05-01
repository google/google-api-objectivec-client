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
//  GTLQPXExpressPricingInfo.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   QPX Express API (qpxExpress/v1)
// Description:
//   Lets you find the least expensive flights between an origin and a
//   destination.
// Documentation:
//   http://developers.google.com/qpx-express
// Classes:
//   GTLQPXExpressPricingInfo (0 custom class methods, 13 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLQPXExpressFareInfo;
@class GTLQPXExpressPassengerCounts;
@class GTLQPXExpressSegmentPricing;
@class GTLQPXExpressTaxInfo;

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressPricingInfo
//

// The price of one or more travel segments. The currency used to purchase
// tickets is usually determined by the sale/ticketing city or the
// sale/ticketing country, unless none are specified, in which case it defaults
// to that of the journey origin country.

@interface GTLQPXExpressPricingInfo : GTLObject

// The total fare in the base fare currency (the currency of the country of
// origin). This element is only present when the sales currency and the
// currency of the country of commencement are different.
@property (nonatomic, copy) NSString *baseFareTotal;

// The fare used to price one or more segments.
@property (nonatomic, retain) NSArray *fare;  // of GTLQPXExpressFareInfo

// The horizontal fare calculation. This is a field on a ticket that displays
// all of the relevant items that go into the calculation of the fare.
@property (nonatomic, copy) NSString *fareCalculation;

// Identifies this as a pricing object, representing the price of one or more
// travel segments. Value: the fixed string qpxexpress#pricingInfo.
@property (nonatomic, copy) NSString *kind;

// The latest ticketing time for this pricing assuming the reservation occurs at
// ticketing time and there is no change in fares/rules. The time is local to
// the point of sale (POS).
@property (nonatomic, copy) NSString *latestTicketingTime;

// The number of passengers to which this price applies.
@property (nonatomic, retain) GTLQPXExpressPassengerCounts *passengers;

// The passenger type code for this pricing. An alphanumeric code used by a
// carrier to restrict fares to certain categories of passenger. For instance, a
// fare might be valid only for senior citizens.
@property (nonatomic, copy) NSString *ptc;

// Whether the fares on this pricing are refundable.
@property (nonatomic, retain) NSNumber *refundable;  // boolValue

// The total fare in the sale or equivalent currency.
@property (nonatomic, copy) NSString *saleFareTotal;

// The taxes in the sale or equivalent currency.
@property (nonatomic, copy) NSString *saleTaxTotal;

// Total per-passenger price (fare and tax) in the sale or equivalent currency.
@property (nonatomic, copy) NSString *saleTotal;

// The per-segment price and baggage information.
@property (nonatomic, retain) NSArray *segmentPricing;  // of GTLQPXExpressSegmentPricing

// The taxes used to calculate the tax total per ticket.
@property (nonatomic, retain) NSArray *tax;  // of GTLQPXExpressTaxInfo

@end
