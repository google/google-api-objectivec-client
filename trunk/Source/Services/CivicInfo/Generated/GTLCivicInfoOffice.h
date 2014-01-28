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
//  GTLCivicInfoOffice.h
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
//   GTLCivicInfoOffice (0 custom class methods, 4 custom properties)

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

// The level of this elected office. One of: federal, state, county, city, other
@property (copy) NSString *level;

// The human-readable name of the office.
@property (copy) NSString *name;

// List of people who presently hold the office.
@property (retain) NSArray *officialIds;  // of NSString

// A list of sources for this office. If multiple sources are listed, the data
// has been aggregated from those sources.
@property (retain) NSArray *sources;  // of GTLCivicInfoSource

@end
