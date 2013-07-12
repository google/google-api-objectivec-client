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
//  GTLCivicInfoContest.h
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
//   GTLCivicInfoContest (0 custom class methods, 16 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCivicInfoCandidate;
@class GTLCivicInfoElectoralDistrict;
@class GTLCivicInfoSource;

// ----------------------------------------------------------------------------
//
//   GTLCivicInfoContest
//

// Information about a contest that appears on a voter's ballot.

@interface GTLCivicInfoContest : GTLObject

// A number specifying the position of this contest on the voter's ballot.
@property (retain) NSNumber *ballotPlacement;  // longLongValue

// The candidate choices for this contest.
@property (retain) NSArray *candidates;  // of GTLCivicInfoCandidate

// Information about the electoral district that this contest is in.
@property (retain) GTLCivicInfoElectoralDistrict *district;

// A description of any additional eligibility requirements for voting in this
// contest.
@property (copy) NSString *electorateSpecifications;

// An ID for this object. IDs may change in future requests and should not be
// cached. Access to this field requires special access that can be requested
// from the Request more link on the Quotas page.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The level of office for this contest. One of: federal, state, county, city,
// other
@property (copy) NSString *level;

// The number of candidates that will be elected to office in this contest.
@property (retain) NSNumber *numberElected;  // longLongValue

// The number of candidates that a voter may vote for in this contest.
@property (retain) NSNumber *numberVotingFor;  // longLongValue

// The name of the office for this contest.
@property (copy) NSString *office;

// If this is a partisan election, the name of the party it is for.
@property (copy) NSString *primaryParty;

// A brief description of the referendum. This field is only populated for
// contests of type 'Referendum'.
@property (copy) NSString *referendumSubtitle;

// The title of the referendum (e.g. 'Proposition 42'). This field is only
// populated for contests of type 'Referendum'.
@property (copy) NSString *referendumTitle;

// A link to the referendum. This field is only populated for contests of type
// 'Referendum'.
@property (copy) NSString *referendumUrl;

// A list of sources for this contest. If multiple sources are listed, the data
// has been aggregated from those sources.
@property (retain) NSArray *sources;  // of GTLCivicInfoSource

// "Yes" or "No" depending on whether this a contest being held outside the
// normal election cycle.
@property (copy) NSString *special;

// The type of contest. Usually this will be 'General', 'Primary', or 'Run-off'
// for contests with candidates. For referenda this will be 'Referendum'.
@property (copy) NSString *type;

@end
