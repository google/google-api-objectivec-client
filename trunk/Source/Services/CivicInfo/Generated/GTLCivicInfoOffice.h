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
//  GTLCivicInfoOffice.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Civic Information API (civicinfo/v2)
// Description:
//   An API for accessing civic information.
// Documentation:
//   https://developers.google.com/civic-information
// Classes:
//   GTLCivicInfoOffice (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCivicInfoSource;

// ----------------------------------------------------------------------------
//
//   GTLCivicInfoOffice
//

// Information about an Office held by one or more Officials.

@interface GTLCivicInfoOffice : GTLObject

// The OCD ID of the division with which this office is associated.
@property (nonatomic, copy) NSString *divisionId;

// The levels of government of which this office is part. There may be more than
// one in cases where a jurisdiction effectively acts at two different levels of
// government; for example, the mayor of the District of Columbia acts at
// "locality" level, but also effectively at both "administrative-area-2" and
// "administrative-area-1".
@property (nonatomic, retain) NSArray *levels;  // of NSString

// The human-readable name of the office.
@property (nonatomic, copy) NSString *name;

// List of indices in the officials array of people who presently hold this
// office.
@property (nonatomic, retain) NSArray *officialIndices;  // of NSNumber (unsignedIntValue)

// The roles which this office fulfills. Roles are not meant to be exhaustive,
// or to exactly specify the entire set of responsibilities of a given office,
// but are meant to be rough categories that are useful for general selection
// from or sorting of a list of offices.
@property (nonatomic, retain) NSArray *roles;  // of NSString

// A list of sources for this office. If multiple sources are listed, the data
// has been aggregated from those sources.
@property (nonatomic, retain) NSArray *sources;  // of GTLCivicInfoSource

@end
