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
//  GTLFitnessDataType.m
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
//   GTLFitnessDataType (0 custom class methods, 2 custom properties)

#import "GTLFitnessDataType.h"

#import "GTLFitnessDataTypeField.h"

// ----------------------------------------------------------------------------
//
//   GTLFitnessDataType
//

@implementation GTLFitnessDataType
@dynamic field, name;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"field" : [GTLFitnessDataTypeField class]
  };
  return map;
}

@end
