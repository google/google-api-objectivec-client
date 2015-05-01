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
//  GTLFitnessDataTypeField.h
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
//   GTLFitnessDataTypeField (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLFitnessDataTypeField
//

// In case of multi-dimensional data (such as an accelerometer with x, y, and z
// axes) each field represents one dimension. Each data type field has a unique
// name which identifies it. The field also defines the format of the data (int,
// float, etc.).
// This message is only instantiated in code and not used for wire comms or
// stored in any way.

@interface GTLFitnessDataTypeField : GTLObject

// The different supported formats for each field in a data type.
@property (nonatomic, copy) NSString *format;

// Defines the name and format of data. Unlike data type names, field names are
// not namespaced, and only need to be unique within the data type.
@property (nonatomic, copy) NSString *name;

@property (nonatomic, retain) NSNumber *optional;  // boolValue
@end
