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
//  GTLCivicInfoAdministrationRegion.m
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
//   GTLCivicInfoAdministrationRegion (0 custom class methods, 5 custom properties)

#import "GTLCivicInfoAdministrationRegion.h"

#import "GTLCivicInfoAdministrativeBody.h"
#import "GTLCivicInfoSource.h"

// ----------------------------------------------------------------------------
//
//   GTLCivicInfoAdministrationRegion
//

@implementation GTLCivicInfoAdministrationRegion
@dynamic electionAdministrationBody, identifier, localJurisdiction, name,
         sources;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"identifier" : @"id",
    @"localJurisdiction" : @"local_jurisdiction"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"sources" : [GTLCivicInfoSource class]
  };
  return map;
}

@end
