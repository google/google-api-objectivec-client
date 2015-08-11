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
//  GTLQueryCivicInfo.h
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
//   GTLQueryCivicInfo (5 custom class methods, 10 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@interface GTLQueryCivicInfo : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (nonatomic, copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (nonatomic, copy) NSString *address;
@property (nonatomic, assign) long long electionId;
@property (nonatomic, assign) BOOL includeOffices;
@property (nonatomic, retain) NSArray *levels;  // of NSString
@property (nonatomic, copy) NSString *ocdId;
@property (nonatomic, assign) BOOL officialOnly;
@property (nonatomic, copy) NSString *query;
@property (nonatomic, assign) BOOL recursive;
@property (nonatomic, retain) NSArray *roles;  // of NSString

#pragma mark - "divisions" methods
// These create a GTLQueryCivicInfo object.

// Method: civicinfo.divisions.search
// Searches for political divisions by their natural name or OCD ID.
//  Optional:
//   query: The search query. Queries can cover any parts of a OCD ID or a human
//     readable division name. All words given in the query are treated as
//     required patterns. In addition to that, most query operators of the
//     Apache Lucene library are supported. See
//     http://lucene.apache.org/core/2_9_4/queryparsersyntax.html
// Fetches a GTLCivicInfoDivisionSearchResponse.
+ (instancetype)queryForDivisionsSearch;

#pragma mark - "elections" methods
// These create a GTLQueryCivicInfo object.

// Method: civicinfo.elections.electionQuery
// List of available elections to query.
// Fetches a GTLCivicInfoElectionsQueryResponse.
+ (instancetype)queryForElectionsElectionQuery;

// Method: civicinfo.elections.voterInfoQuery
// Looks up information relevant to a voter based on the voter's registered
// address.
//  Required:
//   address: The registered address of the voter to look up.
//  Optional:
//   electionId: The unique ID of the election to look up. A list of election
//     IDs can be obtained at
//     https://www.googleapis.com/civicinfo/{version}/elections (Default 0)
//   officialOnly: If set to true, only data from official state sources will be
//     returned. (Default false)
// Fetches a GTLCivicInfoVoterInfoResponse.
+ (instancetype)queryForElectionsVoterInfoQueryWithAddress:(NSString *)address;

#pragma mark - "representatives" methods
// These create a GTLQueryCivicInfo object.

// Method: civicinfo.representatives.representativeInfoByAddress
// Looks up political geography and representative information for a single
// address.
//  Optional:
//   address: The address to look up. May only be specified if the field ocdId
//     is not given in the URL.
//   includeOffices: Whether to return information about offices and officials.
//     If false, only the top-level district information will be returned.
//     (Default true)
//   levels: A list of office levels to filter by. Only offices that serve at
//     least one of these levels will be returned. Divisions that don't contain
//     a matching office will not be returned.
//      kGTLCivicInfoLevelsAdministrativeArea1: "administrativeArea1"
//      kGTLCivicInfoLevelsAdministrativeArea2: "administrativeArea2"
//      kGTLCivicInfoLevelsCountry: "country"
//      kGTLCivicInfoLevelsInternational: "international"
//      kGTLCivicInfoLevelsLocality: "locality"
//      kGTLCivicInfoLevelsRegional: "regional"
//      kGTLCivicInfoLevelsSpecial: "special"
//      kGTLCivicInfoLevelsSubLocality1: "subLocality1"
//      kGTLCivicInfoLevelsSubLocality2: "subLocality2"
//   roles: A list of office roles to filter by. Only offices fulfilling one of
//     these roles will be returned. Divisions that don't contain a matching
//     office will not be returned.
//      kGTLCivicInfoRolesDeputyHeadOfGovernment: "deputyHeadOfGovernment"
//      kGTLCivicInfoRolesExecutiveCouncil: "executiveCouncil"
//      kGTLCivicInfoRolesGovernmentOfficer: "governmentOfficer"
//      kGTLCivicInfoRolesHeadOfGovernment: "headOfGovernment"
//      kGTLCivicInfoRolesHeadOfState: "headOfState"
//      kGTLCivicInfoRolesHighestCourtJudge: "highestCourtJudge"
//      kGTLCivicInfoRolesJudge: "judge"
//      kGTLCivicInfoRolesLegislatorLowerBody: "legislatorLowerBody"
//      kGTLCivicInfoRolesLegislatorUpperBody: "legislatorUpperBody"
//      kGTLCivicInfoRolesSchoolBoard: "schoolBoard"
//      kGTLCivicInfoRolesSpecialPurposeOfficer: "specialPurposeOfficer"
// Fetches a GTLCivicInfoRepresentativeInfoResponse.
+ (instancetype)queryForRepresentativesRepresentativeInfoByAddress;

// Method: civicinfo.representatives.representativeInfoByDivision
// Looks up representative information for a single geographic division.
//  Required:
//   ocdId: The Open Civic Data division identifier of the division to look up.
//  Optional:
//   levels: A list of office levels to filter by. Only offices that serve at
//     least one of these levels will be returned. Divisions that don't contain
//     a matching office will not be returned.
//      kGTLCivicInfoLevelsAdministrativeArea1: "administrativeArea1"
//      kGTLCivicInfoLevelsAdministrativeArea2: "administrativeArea2"
//      kGTLCivicInfoLevelsCountry: "country"
//      kGTLCivicInfoLevelsInternational: "international"
//      kGTLCivicInfoLevelsLocality: "locality"
//      kGTLCivicInfoLevelsRegional: "regional"
//      kGTLCivicInfoLevelsSpecial: "special"
//      kGTLCivicInfoLevelsSubLocality1: "subLocality1"
//      kGTLCivicInfoLevelsSubLocality2: "subLocality2"
//   recursive: If true, information about all divisions contained in the
//     division requested will be included as well. For example, if querying
//     ocd-division/country:us/district:dc, this would also return all DC's
//     wards and ANCs.
//   roles: A list of office roles to filter by. Only offices fulfilling one of
//     these roles will be returned. Divisions that don't contain a matching
//     office will not be returned.
//      kGTLCivicInfoRolesDeputyHeadOfGovernment: "deputyHeadOfGovernment"
//      kGTLCivicInfoRolesExecutiveCouncil: "executiveCouncil"
//      kGTLCivicInfoRolesGovernmentOfficer: "governmentOfficer"
//      kGTLCivicInfoRolesHeadOfGovernment: "headOfGovernment"
//      kGTLCivicInfoRolesHeadOfState: "headOfState"
//      kGTLCivicInfoRolesHighestCourtJudge: "highestCourtJudge"
//      kGTLCivicInfoRolesJudge: "judge"
//      kGTLCivicInfoRolesLegislatorLowerBody: "legislatorLowerBody"
//      kGTLCivicInfoRolesLegislatorUpperBody: "legislatorUpperBody"
//      kGTLCivicInfoRolesSchoolBoard: "schoolBoard"
//      kGTLCivicInfoRolesSpecialPurposeOfficer: "specialPurposeOfficer"
// Fetches a GTLCivicInfoRepresentativeInfoData.
+ (instancetype)queryForRepresentativesRepresentativeInfoByDivisionWithOcdId:(NSString *)ocdId;

@end
