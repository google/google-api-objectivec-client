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
//  GTLCivicInfoAdministrativeBody.m
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
//   GTLCivicInfoAdministrativeBody (0 custom class methods, 13 custom properties)

#import "GTLCivicInfoAdministrativeBody.h"

#import "GTLCivicInfoElectionOfficial.h"
#import "GTLCivicInfoSimpleAddressType.h"

// ----------------------------------------------------------------------------
//
//   GTLCivicInfoAdministrativeBody
//

@implementation GTLCivicInfoAdministrativeBody
@dynamic absenteeVotingInfoUrl, ballotInfoUrl, correspondenceAddress,
         electionInfoUrl, electionOfficials,
         electionRegistrationConfirmationUrl, electionRegistrationUrl,
         electionRulesUrl, hoursOfOperation, name, physicalAddress,
         voterServices, votingLocationFinderUrl;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"voter_services"
                                forKey:@"voterServices"];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLCivicInfoElectionOfficial class], @"electionOfficials",
      [NSString class], @"voter_services",
      nil];
  return map;
}

@end
