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
//  GTLQPXExpressBagDescriptor.h
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
//   GTLQPXExpressBagDescriptor (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressBagDescriptor
//

// Information about an item of baggage.

@interface GTLQPXExpressBagDescriptor : GTLObject

// Provides the commercial name for an optional service.
@property (copy) NSString *commercialName;

// How many of this type of bag will be checked on this flight.
@property (retain) NSNumber *count;  // intValue

// A description of the baggage.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (retain) NSArray *descriptionProperty;  // of NSString

// Identifies this as a baggage object. Value: the fixed string
// qpxexpress#bagDescriptor.
@property (copy) NSString *kind;

// The standard IATA subcode used to identify this optional service.
@property (copy) NSString *subcode;

@end
