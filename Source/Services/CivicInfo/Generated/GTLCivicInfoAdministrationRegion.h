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
//  GTLCivicInfoAdministrationRegion.h
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
//   GTLCivicInfoAdministrationRegion (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCivicInfoAdministrationRegion;
@class GTLCivicInfoAdministrativeBody;
@class GTLCivicInfoSource;

// ----------------------------------------------------------------------------
//
//   GTLCivicInfoAdministrationRegion
//

// Describes information about a regional election administrative area.

@interface GTLCivicInfoAdministrationRegion : GTLObject

// The election administration body for this area.
@property (nonatomic, retain) GTLCivicInfoAdministrativeBody *electionAdministrationBody;

// An ID for this object. IDs may change in future requests and should not be
// cached. Access to this field requires special access that can be requested
// from the Request more link on the Quotas page.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The city or county that provides election information for this voter. This
// object can have the same elements as state.
@property (nonatomic, retain) GTLCivicInfoAdministrationRegion *localJurisdiction;

// The name of the jurisdiction.
@property (nonatomic, copy) NSString *name;

// A list of sources for this area. If multiple sources are listed the data has
// been aggregated from those sources.
@property (nonatomic, retain) NSArray *sources;  // of GTLCivicInfoSource

@end
