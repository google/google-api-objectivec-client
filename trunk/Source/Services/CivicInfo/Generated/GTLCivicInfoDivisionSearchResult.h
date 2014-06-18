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
//  GTLCivicInfoDivisionSearchResult.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Civic Information API (civicinfo/v1)
// Description:
//   An API for accessing civic information.
// Documentation:
//   https://developers.google.com/civic-information
// Classes:
//   GTLCivicInfoDivisionSearchResult (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLCivicInfoDivisionSearchResult
//

// Represents a political geographic division that matches the requested query.

@interface GTLCivicInfoDivisionSearchResult : GTLObject

// Other Open Civic Data identifiers that refer to the same division -- for
// example, those that refer to other political divisions whose boundaries are
// defined to be coterminous with this one. For example,
// ocd-division/country:us/state:wy will include an alias of
// ocd-division/country:us/state:wy/cd:1, since Wyoming has only one
// Congressional district.
@property (retain) NSArray *aliases;  // of NSString

// The name of the division.
@property (copy) NSString *name;

// The unique Open Civic Data identifier for this division.
@property (copy) NSString *ocdId;

@end
