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
//  GTLQPXExpressLegInfo.h
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
//   GTLQPXExpressLegInfo (0 custom class methods, 17 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressLegInfo
//

// Information about a leg. (A leg is the smallest unit of travel, in the case
// of a flight a takeoff immediately followed by a landing at two set points on
// a particular carrier with a particular flight number.)

@interface GTLQPXExpressLegInfo : GTLObject

// The aircraft (or bus, ferry, railcar, etc) travelling between the two points
// of this leg.
@property (copy) NSString *aircraft;

// The scheduled time of arrival at the destination of the leg, local to the
// point of arrival.
@property (copy) NSString *arrivalTime;

// Whether you have to change planes following this leg. Only applies to the
// next leg.
@property (retain) NSNumber *changePlane;  // boolValue

// Duration of a connection following this leg, in minutes.
@property (retain) NSNumber *connectionDuration;  // intValue

// The scheduled departure time of the leg, local to the point of departure.
@property (copy) NSString *departureTime;

// The leg destination as a city and airport.
@property (copy) NSString *destination;

// The terminal the flight is scheduled to arrive at.
@property (copy) NSString *destinationTerminal;

// The scheduled travelling time from the origin to the destination.
@property (retain) NSNumber *duration;  // intValue

// An identifier that uniquely identifies this leg in the solution.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Identifies this as a leg object. A leg is the smallest unit of travel, in the
// case of a flight a takeoff immediately followed by a landing at two set
// points on a particular carrier with a particular flight number. Value: the
// fixed string qpxexpress#legInfo.
@property (copy) NSString *kind;

// A simple, general description of the meal(s) served on the flight, for
// example: "Hot meal".
@property (copy) NSString *meal;

// The number of miles in this leg.
@property (retain) NSNumber *mileage;  // intValue

// In percent, the published on time performance on this leg.
@property (retain) NSNumber *onTimePerformance;  // intValue

// Department of Transportation disclosure information on the actual operator of
// a flight in a code share. (A code share refers to a marketing agreement
// between two carriers, where one carrier will list in its schedules (and take
// bookings for) flights that are actually operated by another carrier.)
@property (copy) NSString *operatingDisclosure;

// The leg origin as a city and airport.
@property (copy) NSString *origin;

// The terminal the flight is scheduled to depart from.
@property (copy) NSString *originTerminal;

// Whether passenger information must be furnished to the United States
// Transportation Security Administration (TSA) prior to departure.
@property (retain) NSNumber *secure;  // boolValue

@end
