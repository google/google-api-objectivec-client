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
//  GTLQPXExpressFlightInfo.h
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
//   GTLQPXExpressFlightInfo (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressFlightInfo
//

// A flight is a sequence of legs with the same airline carrier and flight
// number. (A leg is the smallest unit of travel, in the case of a flight a
// takeoff immediately followed by a landing at two set points on a particular
// carrier with a particular flight number.) The naive view is that a flight is
// scheduled travel of an aircraft between two points, with possibly
// intermediate stops, but carriers will frequently list flights that require a
// change of aircraft between legs.

@interface GTLQPXExpressFlightInfo : GTLObject
@property (copy) NSString *carrier;

// The flight number.
@property (copy) NSString *number;

@end
