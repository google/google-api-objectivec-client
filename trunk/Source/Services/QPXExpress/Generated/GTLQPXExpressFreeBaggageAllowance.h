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
//  GTLQPXExpressFreeBaggageAllowance.h
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
//   GTLQPXExpressFreeBaggageAllowance (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLQPXExpressBagDescriptor;

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressFreeBaggageAllowance
//

// Information about free baggage allowed on one segment of a trip.

@interface GTLQPXExpressFreeBaggageAllowance : GTLObject

// A representation of a type of bag, such as an ATPCo subcode, Commercial Name,
// or other description.
@property (retain) NSArray *bagDescriptor;  // of GTLQPXExpressBagDescriptor

// The maximum number of kilos all the free baggage together may weigh.
@property (retain) NSNumber *kilos;  // intValue

// The maximum number of kilos any one piece of baggage may weigh.
@property (retain) NSNumber *kilosPerPiece;  // intValue

// Identifies this as free baggage object, allowed on one segment of a trip.
// Value: the fixed string qpxexpress#freeBaggageAllowance.
@property (copy) NSString *kind;

// The number of free pieces of baggage allowed.
@property (retain) NSNumber *pieces;  // intValue

// The number of pounds of free baggage allowed.
@property (retain) NSNumber *pounds;  // intValue

@end
