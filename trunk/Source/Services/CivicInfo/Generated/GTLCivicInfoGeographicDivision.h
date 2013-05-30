/* Copyright (c) 2013 Google Inc.
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
//  GTLCivicInfoGeographicDivision.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Civic Information API (civicinfo/us_v1)
// Description:
//   An API for accessing civic information.
// Documentation:
//   https://developers.google.com/civic-information
// Classes:
//   GTLCivicInfoGeographicDivision (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCivicInfoOffice;

// ----------------------------------------------------------------------------
//
//   GTLCivicInfoGeographicDivision
//

// Describes a political geography.

@interface GTLCivicInfoGeographicDivision : GTLObject

// Numerical value between 0 and 1 that expresses level of confidence that a
// given district is relevant to the request.
@property (retain) NSNumber *confidence;  // floatValue

// The name of the division.
@property (copy) NSString *name;

// The unique Open Civic Data identifier for this division.
@property (copy) NSString *ocdId;

// List of offices elected from this division.
@property (retain) NSArray *offices;  // of GTLCivicInfoOffice

// The type of this division. If unspecified the division's geography is not
// known.
@property (copy) NSString *type;

@end
