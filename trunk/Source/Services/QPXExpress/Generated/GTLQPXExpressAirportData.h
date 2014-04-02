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
//  GTLQPXExpressAirportData.h
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
//   GTLQPXExpressAirportData (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressAirportData
//

// An airport.

@interface GTLQPXExpressAirportData : GTLObject

// The city code an airport is located in. For example, for JFK airport, this is
// NYC.
@property (copy) NSString *city;

// An airport's code. For example, for Boston Logan airport, this is BOS.
@property (copy) NSString *code;

// Identifies this as an airport object. Value: the fixed string
// qpxexpress#airportData.
@property (copy) NSString *kind;

// The name of an airport. For example, for airport BOS the name is "Boston
// Logan International".
@property (copy) NSString *name;

@end
