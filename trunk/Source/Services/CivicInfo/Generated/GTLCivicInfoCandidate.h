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
//  GTLCivicInfoCandidate.h
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
//   GTLCivicInfoCandidate (0 custom class methods, 8 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCivicInfoChannel;

// ----------------------------------------------------------------------------
//
//   GTLCivicInfoCandidate
//

// Information about a candidate running for elected office.

@interface GTLCivicInfoCandidate : GTLObject

// The URL for the candidate's campaign web site.
@property (nonatomic, copy) NSString *candidateUrl;

// A list of known (social) media channels for this candidate.
@property (nonatomic, retain) NSArray *channels;  // of GTLCivicInfoChannel

// The email address for the candidate's campaign.
@property (nonatomic, copy) NSString *email;

// The candidate's name.
@property (nonatomic, copy) NSString *name;

// The order the candidate appears on the ballot for this contest.
@property (nonatomic, retain) NSNumber *orderOnBallot;  // longLongValue

// The full name of the party the candidate is a member of.
@property (nonatomic, copy) NSString *party;

// The voice phone number for the candidate's campaign office.
@property (nonatomic, copy) NSString *phone;

// A URL for a photo of the candidate.
@property (nonatomic, copy) NSString *photoUrl;

@end
