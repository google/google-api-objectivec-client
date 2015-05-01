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
//  GTLQPXExpressCityData.h
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
//   GTLQPXExpressCityData (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressCityData
//

// Information about a city that might be useful to an end-user; typically the
// city of an airport.

@interface GTLQPXExpressCityData : GTLObject

// The IATA character ID of a city. For example, for Boston this is BOS.
@property (nonatomic, copy) NSString *code;

// The two-character country code of the country the city is located in. For
// example, US for the United States of America.
@property (nonatomic, copy) NSString *country;

// Identifies this as a city, typically with one or more airports. Value: the
// fixed string qpxexpress#cityData.
@property (nonatomic, copy) NSString *kind;

// The full name of a city. An example would be: New York.
@property (nonatomic, copy) NSString *name;

@end
