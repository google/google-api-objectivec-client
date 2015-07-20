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
//  GTLCivicInfoContest.h
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
//   GTLCivicInfoContest (0 custom class methods, 24 custom properties)

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
@property (nonatomic, retain) NSNumber *ballotPlacement;  // longLongValue

// The candidate choices for this contest.
@property (nonatomic, retain) NSArray *candidates;  // of GTLCivicInfoCandidate

// Information about the electoral district that this contest is in.
@property (nonatomic, retain) GTLCivicInfoElectoralDistrict *district;

// A description of any additional eligibility requirements for voting in this
// contest.
@property (nonatomic, copy) NSString *electorateSpecifications;

// An ID for this object. IDs may change in future requests and should not be
// cached. Access to this field requires special access that can be requested
// from the Request more link on the Quotas page.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The levels of government of the office for this contest. There may be more
// than one in cases where a jurisdiction effectively acts at two different
// levels of government; for example, the mayor of the District of Columbia acts
// at "locality" level, but also effectively at both "administrative-area-2" and
// "administrative-area-1".
@property (nonatomic, retain) NSArray *level;  // of NSString

// The number of candidates that will be elected to office in this contest.
@property (nonatomic, retain) NSNumber *numberElected;  // longLongValue

// The number of candidates that a voter may vote for in this contest.
@property (nonatomic, retain) NSNumber *numberVotingFor;  // longLongValue

// The name of the office for this contest.
@property (nonatomic, copy) NSString *office;

// If this is a partisan election, the name of the party it is for.
@property (nonatomic, copy) NSString *primaryParty;

// The set of ballot responses for the referendum. A ballot response represents
// a line on the ballot. Common examples might include "yes" or "no" for
// referenda, or a judge's name for a retention contest. This field is only
// populated for contests of type 'Referendum'.
@property (nonatomic, retain) NSArray *referendumBallotResponses;  // of NSString

// Specifies a short summary of the referendum that is on the ballot below the
// title but above the text. This field is only populated for contests of type
// 'Referendum'.
@property (nonatomic, copy) NSString *referendumBrief;

// A statement in opposition to the referendum. It does not necessarily appear
// on the ballot. This field is only populated for contests of type
// 'Referendum'.
@property (nonatomic, copy) NSString *referendumConStatement;

// Specifies what effect abstaining (not voting) on the proposition will have
// (i.e. whether abstaining is considered a vote against it). This field is only
// populated for contests of type 'Referendum'.
@property (nonatomic, copy) NSString *referendumEffectOfAbstain;

// The threshold of votes that the referendum needs in order to pass, e.g.
// "two-thirds". This field is only populated for contests of type 'Referendum'.
@property (nonatomic, copy) NSString *referendumPassageThreshold;

// A statement in favor of the referendum. It does not necessarily appear on the
// ballot. This field is only populated for contests of type 'Referendum'.
@property (nonatomic, copy) NSString *referendumProStatement;

// A brief description of the referendum. This field is only populated for
// contests of type 'Referendum'.
@property (nonatomic, copy) NSString *referendumSubtitle;

// The full text of the referendum. This field is only populated for contests of
// type 'Referendum'.
@property (nonatomic, copy) NSString *referendumText;

// The title of the referendum (e.g. 'Proposition 42'). This field is only
// populated for contests of type 'Referendum'.
@property (nonatomic, copy) NSString *referendumTitle;

// A link to the referendum. This field is only populated for contests of type
// 'Referendum'.
@property (nonatomic, copy) NSString *referendumUrl;

// The roles which this office fulfills.
@property (nonatomic, retain) NSArray *roles;  // of NSString

// A list of sources for this contest. If multiple sources are listed, the data
// has been aggregated from those sources.
@property (nonatomic, retain) NSArray *sources;  // of GTLCivicInfoSource

// "Yes" or "No" depending on whether this a contest being held outside the
// normal election cycle.
@property (nonatomic, copy) NSString *special;

// The type of contest. Usually this will be 'General', 'Primary', or 'Run-off'
// for contests with candidates. For referenda this will be 'Referendum'.
@property (nonatomic, copy) NSString *type;

@end
