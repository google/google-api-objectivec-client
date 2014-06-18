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
//  GTLCivicInfoRepresentativeInfoResponse.h
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
//   GTLCivicInfoRepresentativeInfoResponse (0 custom class methods, 6 custom properties)
//   GTLCivicInfoRepresentativeInfoResponseDivisions (0 custom class methods, 0 custom properties)
//   GTLCivicInfoRepresentativeInfoResponseOffices (0 custom class methods, 0 custom properties)
//   GTLCivicInfoRepresentativeInfoResponseOfficials (0 custom class methods, 0 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCivicInfoGeographicDivision;
@class GTLCivicInfoOffice;
@class GTLCivicInfoOfficial;
@class GTLCivicInfoRepresentativeInfoResponseDivisions;
@class GTLCivicInfoRepresentativeInfoResponseOffices;
@class GTLCivicInfoRepresentativeInfoResponseOfficials;
@class GTLCivicInfoSimpleAddressType;

// ----------------------------------------------------------------------------
//
//   GTLCivicInfoRepresentativeInfoResponse
//

// The result of a representative info lookup query.

@interface GTLCivicInfoRepresentativeInfoResponse : GTLObject

// Political geographic divisions that contain the requested address.
@property (retain) GTLCivicInfoRepresentativeInfoResponseDivisions *divisions;

// Identifies what kind of resource this is. Value: the fixed string
// "civicinfo#representativeInfoResponse".
@property (copy) NSString *kind;

// The normalized version of the requested address
@property (retain) GTLCivicInfoSimpleAddressType *normalizedInput;

// Elected offices referenced by the divisions listed above. Will only be
// present if includeOffices was true in the request.
@property (retain) GTLCivicInfoRepresentativeInfoResponseOffices *offices;

// Officials holding the offices listed above. Will only be present if
// includeOffices was true in the request.
@property (retain) GTLCivicInfoRepresentativeInfoResponseOfficials *officials;

// The result of the request. One of: success, noStreetSegmentFound,
// addressUnparseable, noAddressParameter, multipleStreetSegmentsFound,
// electionOver, electionUnknown, internalLookupFailure,
// RequestedBothAddressAndOcdId
@property (copy) NSString *status;

@end


// ----------------------------------------------------------------------------
//
//   GTLCivicInfoRepresentativeInfoResponseDivisions
//

@interface GTLCivicInfoRepresentativeInfoResponseDivisions : GTLObject
// This object is documented as having more properties that are
// GTLCivicInfoGeographicDivision. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end


// ----------------------------------------------------------------------------
//
//   GTLCivicInfoRepresentativeInfoResponseOffices
//

@interface GTLCivicInfoRepresentativeInfoResponseOffices : GTLObject
// This object is documented as having more properties that are
// GTLCivicInfoOffice. Use -additionalJSONKeys and -additionalPropertyForName:
// to get the list of properties and then fetch them; or -additionalProperties
// to fetch them all at once.
@end


// ----------------------------------------------------------------------------
//
//   GTLCivicInfoRepresentativeInfoResponseOfficials
//

@interface GTLCivicInfoRepresentativeInfoResponseOfficials : GTLObject
// This object is documented as having more properties that are
// GTLCivicInfoOfficial. Use -additionalJSONKeys and -additionalPropertyForName:
// to get the list of properties and then fetch them; or -additionalProperties
// to fetch them all at once.
@end
