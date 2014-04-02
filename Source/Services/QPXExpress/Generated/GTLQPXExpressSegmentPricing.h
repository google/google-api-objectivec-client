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
//  GTLQPXExpressSegmentPricing.h
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
//   GTLQPXExpressSegmentPricing (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLQPXExpressFreeBaggageAllowance;

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressSegmentPricing
//

// The price of this segment.

@interface GTLQPXExpressSegmentPricing : GTLObject

// A segment identifier unique within a single solution. It is used to refer to
// different parts of the same solution.
@property (copy) NSString *fareId;

// Details of the free baggage allowance on this segment.
@property (retain) NSArray *freeBaggageOption;  // of GTLQPXExpressFreeBaggageAllowance

// Identifies this as a segment pricing object, representing the price of this
// segment. Value: the fixed string qpxexpress#segmentPricing.
@property (copy) NSString *kind;

// Unique identifier in the response of this segment.
@property (copy) NSString *segmentId;

@end
