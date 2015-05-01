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
//  GTLQPXExpressPassengerCounts.h
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
//   GTLQPXExpressPassengerCounts (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressPassengerCounts
//

// The number and type of passengers. Unfortunately the definition of an infant,
// child, adult, and senior citizen varies across carriers and reservation
// systems.

@interface GTLQPXExpressPassengerCounts : GTLObject

// The number of passengers that are adults.
@property (nonatomic, retain) NSNumber *adultCount;  // intValue

// The number of passengers that are children.
@property (nonatomic, retain) NSNumber *childCount;  // intValue

// The number of passengers that are infants travelling in the lap of an adult.
@property (nonatomic, retain) NSNumber *infantInLapCount;  // intValue

// The number of passengers that are infants each assigned a seat.
@property (nonatomic, retain) NSNumber *infantInSeatCount;  // intValue

// Identifies this as a passenger count object, representing the number of
// passengers. Value: the fixed string qpxexpress#passengerCounts.
@property (nonatomic, copy) NSString *kind;

// The number of passengers that are senior citizens.
@property (nonatomic, retain) NSNumber *seniorCount;  // intValue

@end
