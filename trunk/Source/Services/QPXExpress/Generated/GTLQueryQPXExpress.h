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
//  GTLQueryQPXExpress.h
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
//   GTLQueryQPXExpress (1 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLQPXExpressTripOptionsRequest;

@interface GTLQueryQPXExpress : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (retain) GTLQPXExpressTripOptionsRequest *request;

#pragma mark -
#pragma mark "trips" methods
// These create a GTLQueryQPXExpress object.

// Method: qpxExpress.trips.search
// Returns a list of flights.
//  Optional:
//   request: A QPX Express search request. Required values are at least one
//     adult or senior passenger, an origin, a destination, and a date.
// Fetches a GTLQPXExpressTripsSearchResponse.
+ (id)queryForTripsSearch;

@end
