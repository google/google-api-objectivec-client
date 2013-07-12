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
//  GTLQueryCivicInfo.m
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
//   GTLQueryCivicInfo (2 custom class methods, 4 custom properties)

#import "GTLQueryCivicInfo.h"

#import "GTLCivicInfoElectionsQueryResponse.h"
#import "GTLCivicInfoVoterInfoResponse.h"

@implementation GTLQueryCivicInfo

@dynamic address, electionId, fields, officialOnly;

#pragma mark -
#pragma mark "elections" methods
// These create a GTLQueryCivicInfo object.

+ (id)queryForElectionsElectionQuery {
  NSString *methodName = @"civicinfo.elections.electionQuery";
  GTLQueryCivicInfo *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLCivicInfoElectionsQueryResponse class];
  return query;
}

+ (id)queryForElectionsVoterInfoQueryWithElectionId:(long long)electionId {
  NSString *methodName = @"civicinfo.elections.voterInfoQuery";
  GTLQueryCivicInfo *query = [self queryWithMethodName:methodName];
  query.electionId = electionId;
  query.expectedObjectClass = [GTLCivicInfoVoterInfoResponse class];
  return query;
}

@end
