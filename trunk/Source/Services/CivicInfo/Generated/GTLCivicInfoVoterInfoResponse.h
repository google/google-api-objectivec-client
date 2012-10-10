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
//  GTLCivicInfoVoterInfoResponse.h
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
//   GTLCivicInfoVoterInfoResponse (0 custom class methods, 8 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCivicInfoAdministrationRegion;
@class GTLCivicInfoContest;
@class GTLCivicInfoElection;
@class GTLCivicInfoPollingLocation;
@class GTLCivicInfoSimpleAddressType;

// ----------------------------------------------------------------------------
//
//   GTLCivicInfoVoterInfoResponse
//

// The result of a voter info lookup query.

@interface GTLCivicInfoVoterInfoResponse : GTLObject

// Contests that will appear on the voter's ballot
@property (retain) NSArray *contests;  // of GTLCivicInfoContest

// Locations where the voter is eligible to vote early, prior to election day
@property (retain) NSArray *earlyVoteSites;  // of GTLCivicInfoPollingLocation

// The election that was queried.
@property (retain) GTLCivicInfoElection *election;

// The kind, fixed to "civicinfo#voterInfoResponse".
@property (copy) NSString *kind;

// The normalized version of the requested address
@property (retain) GTLCivicInfoSimpleAddressType *normalizedInput;

// Locations where the voter is eligible to vote on election day. For states
// with mail-in voting only, these locations will be nearby drop box locations.
// Drop box locations are free to the voter and may be used instead of placing
// the ballot in the mail.
@property (retain) NSArray *pollingLocations;  // of GTLCivicInfoPollingLocation

// Local Election Information for the state that the voter votes in. For the US,
// there will only be one element in this array.
@property (retain) NSArray *state;  // of GTLCivicInfoAdministrationRegion

// The result of the request. One of: success, noStreetSegmentFound,
// addressUnparseable, noAddressParameter, multipleStreetSegmentsFound,
// electionOver, electionUnknown, internalLookupFailure
@property (copy) NSString *status;

@end
