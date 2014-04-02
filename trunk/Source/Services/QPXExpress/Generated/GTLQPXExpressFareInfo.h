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
//  GTLQPXExpressFareInfo.h
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
//   GTLQPXExpressFareInfo (0 custom class methods, 7 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressFareInfo
//

// Complete information about a fare used in the solution to a low-fare search
// query. In the airline industry a fare is a price an airline charges for
// one-way travel between two points. A fare typically contains a carrier code,
// two city codes, a price, and a fare basis. (A fare basis is a one-to-eight
// character alphanumeric code used to identify a fare.)

@interface GTLQPXExpressFareInfo : GTLObject
@property (copy) NSString *basisCode;

// The carrier of the aircraft or other vehicle commuting between two points.
@property (copy) NSString *carrier;

// The city code of the city the trip ends at.
@property (copy) NSString *destination;

// A unique identifier of the fare.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Identifies this as a fare object. Value: the fixed string
// qpxexpress#fareInfo.
@property (copy) NSString *kind;

// The city code of the city the trip begins at.
@property (copy) NSString *origin;

// Whether this is a private fare, for example one offered only to select
// customers rather than the general public.
// Remapped to 'privateProperty' to avoid language reserved word 'private'.
@property (retain) NSNumber *privateProperty;  // boolValue

@end
