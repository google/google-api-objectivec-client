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
//  GTLCivicInfoAdministrativeBody.h
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
//   GTLCivicInfoAdministrativeBody (0 custom class methods, 13 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCivicInfoElectionOfficial;
@class GTLCivicInfoSimpleAddressType;

// ----------------------------------------------------------------------------
//
//   GTLCivicInfoAdministrativeBody
//

// Information about an election administrative body (e.g. County Board of
// Elections).

@interface GTLCivicInfoAdministrativeBody : GTLObject

// A URL provided by this administrative body for information on absentee
// voting.
@property (copy) NSString *absenteeVotingInfoUrl;

// A URL provided by this administrative body to give contest information to the
// voter.
@property (copy) NSString *ballotInfoUrl;

// The mailing address of this administrative body.
@property (retain) GTLCivicInfoSimpleAddressType *correspondenceAddress;

// A URL provided by this administrative body for looking up general election
// information.
@property (copy) NSString *electionInfoUrl;

// The election officials for this election administrative body.
@property (retain) NSArray *electionOfficials;  // of GTLCivicInfoElectionOfficial

// A URL provided by this administrative body for confirming that the voter is
// registered to vote.
@property (copy) NSString *electionRegistrationConfirmationUrl;

// A URL provided by this administrative body for looking up how to register to
// vote.
@property (copy) NSString *electionRegistrationUrl;

// A URL provided by this administrative body describing election rules to the
// voter.
@property (copy) NSString *electionRulesUrl;

// A description of the hours of operation for this administrative body.
@property (copy) NSString *hoursOfOperation;

// The name of this election administrative body.
@property (copy) NSString *name;

// The physical address of this administrative body.
@property (retain) GTLCivicInfoSimpleAddressType *physicalAddress;

// A description of the services this administrative body may provide.
@property (retain) NSArray *voterServices;  // of NSString

// A URL provided by this administrative body for looking up where to vote.
@property (copy) NSString *votingLocationFinderUrl;

@end
