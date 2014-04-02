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
//  GTLQPXExpressSliceInfo.h
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
//   GTLQPXExpressSliceInfo (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLQPXExpressSegmentInfo;

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressSliceInfo
//

// Information about a slice. A slice represents a traveller's intent, the
// portion of a low-fare search corresponding to a traveler's request to get
// between two points. One-way journeys are generally expressed using 1 slice,
// round-trips using 2. For example, if a traveler specifies the following trip
// in a user interface:
// | Origin | Destination | Departure Date | | BOS | LAX | March 10, 2007 | |
// LAX | SYD | March 17, 2007 | | SYD | BOS | March 22, 2007 |
// then this is a three slice trip.

@interface GTLQPXExpressSliceInfo : GTLObject

// The duration of the slice in minutes.
@property (retain) NSNumber *duration;  // intValue

// Identifies this as a slice object. A slice represents a traveller's intent,
// the portion of a low-fare search corresponding to a traveler's request to get
// between two points. One-way journeys are generally expressed using 1 slice,
// round-trips using 2. Value: the fixed string qpxexpress#sliceInfo.
@property (copy) NSString *kind;

// The segment(s) constituting the slice.
@property (retain) NSArray *segment;  // of GTLQPXExpressSegmentInfo

@end
