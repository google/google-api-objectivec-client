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
//  GTLQPXExpressTripOptionsRequest.h
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
//   GTLQPXExpressTripOptionsRequest (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLQPXExpressPassengerCounts;
@class GTLQPXExpressSliceInput;

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressTripOptionsRequest
//

// A QPX Express search request, which will yield one or more solutions.

@interface GTLQPXExpressTripOptionsRequest : GTLObject

// Do not return solutions that cost more than this price. The alphabetical part
// of the price is in ISO 4217. The format, in regex, is [A-Z]{3}\d+(\.\d+)?
// Example: $102.07
@property (copy) NSString *maxPrice;

// Counts for each passenger type in the request.
@property (retain) GTLQPXExpressPassengerCounts *passengers;

// Return only solutions with refundable fares.
@property (retain) NSNumber *refundable;  // boolValue

// IATA country code representing the point of sale. This determines the
// "equivalent amount paid" currency for the ticket.
@property (copy) NSString *saleCountry;

// The slices that make up the itinerary of this trip. A slice represents a
// traveler's intent, the portion of a low-fare search corresponding to a
// traveler's request to get between two points. One-way journeys are generally
// expressed using one slice, round-trips using two. An example of a one slice
// trip with three segments might be BOS-SYD, SYD-LAX, LAX-BOS if the traveler
// only stopped in SYD and LAX just long enough to change planes.
@property (retain) NSArray *slice;  // of GTLQPXExpressSliceInput

// The number of solutions to return, maximum 500.
@property (retain) NSNumber *solutions;  // intValue

@end
