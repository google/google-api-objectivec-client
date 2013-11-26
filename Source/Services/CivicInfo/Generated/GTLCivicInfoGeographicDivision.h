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
//   GTLCivicInfoGeographicDivision (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLCivicInfoGeographicDivision
//

// Describes a political geography.

@interface GTLCivicInfoGeographicDivision : GTLObject

// The name of the division.
@property (copy) NSString *name;

// List of keys in the offices object, one for each office elected from this
// division. Will only be present if includeOffices was true (or absent) in the
// request.
@property (retain) NSArray *officeIds;  // of NSString

// The geographic scope of the division. If unspecified, the division's
// geography is not known. One of: national, statewide, congressional,
// stateUpper, stateLower, countywide, judicial, schoolBoard, cityWide,
// township, countyCouncil, cityCouncil, ward, special
@property (copy) NSString *scope;

@end
