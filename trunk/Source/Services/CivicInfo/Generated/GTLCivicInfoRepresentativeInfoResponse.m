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
//  GTLCivicInfoRepresentativeInfoResponse.m
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
//   GTLCivicInfoRepresentativeInfoResponse (0 custom class methods, 6 custom properties)
//   GTLCivicInfoRepresentativeInfoResponseDivisions (0 custom class methods, 0 custom properties)
//   GTLCivicInfoRepresentativeInfoResponseOffices (0 custom class methods, 0 custom properties)
//   GTLCivicInfoRepresentativeInfoResponseOfficials (0 custom class methods, 0 custom properties)

#import "GTLCivicInfoRepresentativeInfoResponse.h"

#import "GTLCivicInfoGeographicDivision.h"
#import "GTLCivicInfoOffice.h"
#import "GTLCivicInfoOfficial.h"
#import "GTLCivicInfoSimpleAddressType.h"

// ----------------------------------------------------------------------------
//
//   GTLCivicInfoRepresentativeInfoResponse
//

@implementation GTLCivicInfoRepresentativeInfoResponse
@dynamic divisions, kind, normalizedInput, offices, officials, status;

+ (void)load {
  [self registerObjectClassForKind:@"civicinfo#representativeInfoResponse"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLCivicInfoRepresentativeInfoResponseDivisions
//

@implementation GTLCivicInfoRepresentativeInfoResponseDivisions

+ (Class)classForAdditionalProperties {
  return [GTLCivicInfoGeographicDivision class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLCivicInfoRepresentativeInfoResponseOffices
//

@implementation GTLCivicInfoRepresentativeInfoResponseOffices

+ (Class)classForAdditionalProperties {
  return [GTLCivicInfoOffice class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLCivicInfoRepresentativeInfoResponseOfficials
//

@implementation GTLCivicInfoRepresentativeInfoResponseOfficials

+ (Class)classForAdditionalProperties {
  return [GTLCivicInfoOfficial class];
}

@end
