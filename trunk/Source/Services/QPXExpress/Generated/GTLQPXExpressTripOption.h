/* Copyright (c) 2014 Google Inc.
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
//  GTLQPXExpressTripOption.h
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
//   GTLQPXExpressTripOption (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLQPXExpressPricingInfo;
@class GTLQPXExpressSliceInfo;

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressTripOption
//

// Trip information.

@interface GTLQPXExpressTripOption : GTLObject

// Identifier uniquely identifying this trip in a response.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Identifies this as a trip information object. Value: the fixed string
// qpxexpress#tripOption.
@property (copy) NSString *kind;

// Per passenger pricing information.
@property (retain) NSArray *pricing;  // of GTLQPXExpressPricingInfo

// The total price for all passengers on the trip, in the form of a currency
// followed by an amount, e.g. USD253.35.
@property (copy) NSString *saleTotal;

// The slices that make up this trip's itinerary.
@property (retain) NSArray *slice;  // of GTLQPXExpressSliceInfo

@end
