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
//  GTLFitnessValue.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Fitness (fitness/v1)
// Description:
//   Google Fit API
// Documentation:
//   https://developers.google.com/fit/rest/
// Classes:
//   GTLFitnessValue (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLFitnessValueMapValEntry;

// ----------------------------------------------------------------------------
//
//   GTLFitnessValue
//

// Holder object for the value of a single field in a data point.
// A field value has a particular format and is only ever set to one of an
// integer or a floating point value.

@interface GTLFitnessValue : GTLObject

// Floating point value. When this is set, other values must not be set.
@property (nonatomic, retain) NSNumber *fpVal;  // doubleValue

// Integer value. When this is set, other values must not be set.
@property (nonatomic, retain) NSNumber *intVal;  // intValue

// Map value. The valid key space and units for the corresponding value of each
// entry should be documented as part of the data type definition. Keys should
// be kept small whenever possible. Data streams with large keys and high data
// frequency may be down sampled.
@property (nonatomic, retain) NSArray *mapVal;  // of GTLFitnessValueMapValEntry

// String value. When this is set, other values must not be set. Strings should
// be kept small whenever possible. Data streams with large string values and
// high data frequency may be down sampled.
@property (nonatomic, copy) NSString *stringVal;

@end
