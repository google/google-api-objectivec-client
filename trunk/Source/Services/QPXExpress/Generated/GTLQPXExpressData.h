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
//  GTLQPXExpressData.h
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
//   GTLQPXExpressData (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLQPXExpressAircraftData;
@class GTLQPXExpressAirportData;
@class GTLQPXExpressCarrierData;
@class GTLQPXExpressCityData;
@class GTLQPXExpressTaxData;

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressData
//

// Detailed information about components found in the solutions of this
// response, including a trip's airport, city, taxes, airline, and aircraft.

@interface GTLQPXExpressData : GTLObject

// The aircraft that is flying between an origin and destination.
@property (nonatomic, retain) NSArray *aircraft;  // of GTLQPXExpressAircraftData

// The airport of an origin or destination.
@property (nonatomic, retain) NSArray *airport;  // of GTLQPXExpressAirportData

// The airline carrier of the aircraft flying between an origin and destination.
// Allowed values are IATA carrier codes.
@property (nonatomic, retain) NSArray *carrier;  // of GTLQPXExpressCarrierData

// The city that is either the origin or destination of part of a trip.
@property (nonatomic, retain) NSArray *city;  // of GTLQPXExpressCityData

// Identifies this as QPX Express response resource, including a trip's airport,
// city, taxes, airline, and aircraft. Value: the fixed string qpxexpress#data.
@property (nonatomic, copy) NSString *kind;

// The taxes due for flying between an origin and a destination.
@property (nonatomic, retain) NSArray *tax;  // of GTLQPXExpressTaxData

@end
