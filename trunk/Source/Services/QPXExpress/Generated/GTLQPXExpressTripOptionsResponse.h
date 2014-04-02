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
//  GTLQPXExpressTripOptionsResponse.h
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
//   GTLQPXExpressTripOptionsResponse (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLQPXExpressData;
@class GTLQPXExpressTripOption;

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressTripOptionsResponse
//

// A QPX Express search response.

@interface GTLQPXExpressTripOptionsResponse : GTLObject

// Informational data global to list of solutions.
@property (retain) GTLQPXExpressData *data;

// Identifies this as a QPX Express trip response object, which consists of zero
// or more solutions. Value: the fixed string qpxexpress#tripOptions.
@property (copy) NSString *kind;

// An identifier uniquely identifying this response.
@property (copy) NSString *requestId;

// A list of priced itinerary solutions to the QPX Express query.
@property (retain) NSArray *tripOption;  // of GTLQPXExpressTripOption

@end
