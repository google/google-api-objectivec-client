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
//  GTLQueryCivicInfo.h
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
//   GTLQueryCivicInfo (4 custom class methods, 8 custom properties)

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
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (copy) NSString *address;
@property (assign) long long electionId;
@property (assign) BOOL includeOffices;
@property (copy) NSString *ocdId;
@property (assign) BOOL officialOnly;
@property (copy) NSString *query;
@property (assign) BOOL recursive;

#pragma mark -
#pragma mark "divisions" methods
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
+ (id)queryForDivisionsSearch;

#pragma mark -
#pragma mark "elections" methods
// These create a GTLQueryCivicInfo object.

// Method: civicinfo.elections.electionQuery
// List of available elections to query.
// Fetches a GTLCivicInfoElectionsQueryResponse.
+ (id)queryForElectionsElectionQuery;

// Method: civicinfo.elections.voterInfoQuery
// Looks up information relevant to a voter based on the voter's registered
// address.
//  Required:
//   electionId: The unique ID of the election to look up. A list of election
//     IDs can be obtained at
//     https://www.googleapis.com/civicinfo/{version}/elections
//  Optional:
//   address: The registered address of the voter to look up.
//   officialOnly: If set to true, only data from official state sources will be
//     returned. (Default false)
// Fetches a GTLCivicInfoVoterInfoResponse.
+ (id)queryForElectionsVoterInfoQueryWithElectionId:(long long)electionId;

#pragma mark -
#pragma mark "representatives" methods
// These create a GTLQueryCivicInfo object.

// Method: civicinfo.representatives.representativeInfoQuery
// Looks up political geography and representative information based on an
// address or Open Civic Data division identifier.
//  Optional:
//   address: The address to look up. May only be specified if the field ocdId
//     is not given in the URL.
//   includeOffices: Whether to return information about offices and officials.
//     If false, only the top-level district information will be returned.
//     (Default true)
//   ocdId: The division to look up. May only be specified if the address field
//     is not given in the request body.
//   recursive: When ocd_id is supplied, return all divisions which are
//     hierarchically nested within the queried division. For example, if
//     querying ocd-division/country:us/district:dc, this would also return all
//     DC's wards and ANCs. (Default false)
// Fetches a GTLCivicInfoRepresentativeInfoResponse.
+ (id)queryForRepresentativesRepresentativeInfoQuery;

@end
