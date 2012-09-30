/* Copyright (c) 2012 Google Inc.
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
//  GTLCivicInfoPollingLocation.h
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
//   GTLCivicInfoPollingLocation (0 custom class methods, 7 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCivicInfoSimpleAddressType;
@class GTLCivicInfoSource;

// ----------------------------------------------------------------------------
//
//   GTLCivicInfoPollingLocation
//

// A location where a voter can vote. This may be an early vote site or an
// election day voting location.

@interface GTLCivicInfoPollingLocation : GTLObject

// The address of the polling location.
@property (retain) GTLCivicInfoSimpleAddressType *address;

// The last date that this early vote site may be used.
@property (copy) NSString *endDate;

// The name of the early vote site.
@property (copy) NSString *name;

// A description of when this polling location is open.
@property (copy) NSString *pollingHours;

// A list of sources for this polling location. If multiple sources are listed
// the data has been aggregated from those sources.
@property (retain) NSArray *sources;  // of GTLCivicInfoSource

// The first date that this early vote site may be used.
@property (copy) NSString *startDate;

// The services provided by this early vote site.
@property (copy) NSString *voterServices;

@end
