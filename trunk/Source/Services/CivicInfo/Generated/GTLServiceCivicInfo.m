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
//  GTLServiceCivicInfo.m
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
//   GTLServiceCivicInfo (0 custom class methods, 0 custom properties)

#import "GTLCivicInfo.h"

@implementation GTLServiceCivicInfo

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = @[
    [GTLQueryCivicInfo class],
    [GTLCivicInfoAdministrationRegion class],
    [GTLCivicInfoAdministrativeBody class],
    [GTLCivicInfoCandidate class],
    [GTLCivicInfoChannel class],
    [GTLCivicInfoContest class],
    [GTLCivicInfoDivisionSearchResponse class],
    [GTLCivicInfoDivisionSearchResult class],
    [GTLCivicInfoElection class],
    [GTLCivicInfoElectionOfficial class],
    [GTLCivicInfoElectionsQueryResponse class],
    [GTLCivicInfoElectoralDistrict class],
    [GTLCivicInfoGeographicDivision class],
    [GTLCivicInfoOffice class],
    [GTLCivicInfoOfficial class],
    [GTLCivicInfoPollingLocation class],
    [GTLCivicInfoRepresentativeInfoData class],
    [GTLCivicInfoRepresentativeInfoResponse class],
    [GTLCivicInfoSimpleAddressType class],
    [GTLCivicInfoSource class],
    [GTLCivicInfoVoterInfoResponse class]
  ];
  return classes;
}
#endif  // DEBUG

- (instancetype)init {
  self = [super init];
  if (self) {
    // Version from discovery.
    self.apiVersion = @"v2";

    // From discovery.  Where to send JSON-RPC.
    // Turn off prettyPrint for this service to save bandwidth (especially on
    // mobile). The fetcher logging will pretty print.
    self.rpcURL = [NSURL URLWithString:@"https://www.googleapis.com/rpc?prettyPrint=false"];
  }
  return self;
}

@end
