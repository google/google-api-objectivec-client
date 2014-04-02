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
//  GTLQPXExpressSliceInput.h
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
//   GTLQPXExpressSliceInput (0 custom class methods, 11 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLQPXExpressTimeOfDayRange;

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressSliceInput
//

// Criteria a desired slice must satisfy.

@interface GTLQPXExpressSliceInput : GTLObject

// Slices with only the carriers in this alliance should be returned; do not use
// this field with permittedCarrier. Allowed values are ONEWORLD, SKYTEAM, and
// STAR.
@property (copy) NSString *alliance;

// Departure date in YYYY-MM-DD format.
@property (copy) NSString *date;

// Airport or city IATA designator of the destination.
@property (copy) NSString *destination;

// Identifies this as a slice input object, representing the criteria a desired
// slice must satisfy. Value: the fixed string qpxexpress#sliceInput.
@property (copy) NSString *kind;

// The longest connection between two legs, in minutes, you are willing to
// accept.
@property (retain) NSNumber *maxConnectionDuration;  // intValue

// The maximum number of stops you are willing to accept in this slice.
@property (retain) NSNumber *maxStops;  // intValue

// Airport or city IATA designator of the origin.
@property (copy) NSString *origin;

// A list of 2-letter IATA airline designators. Slices with only these carriers
// should be returned.
@property (retain) NSArray *permittedCarrier;  // of NSString

// Slices must depart in this time of day range, local to the point of
// departure.
@property (retain) GTLQPXExpressTimeOfDayRange *permittedDepartureTime;

// Prefer solutions that book in this cabin for this slice. Allowed values are
// COACH, PREMIUM_COACH, BUSINESS, and FIRST.
@property (copy) NSString *preferredCabin;

// A list of 2-letter IATA airline designators. Exclude slices that use these
// carriers.
@property (retain) NSArray *prohibitedCarrier;  // of NSString

@end
