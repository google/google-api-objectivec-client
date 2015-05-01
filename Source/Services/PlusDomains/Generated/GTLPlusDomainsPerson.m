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
//  GTLPlusDomainsPerson.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google+ Domains API (plusDomains/v1)
// Description:
//   The Google+ API enables developers to build on top of the Google+ platform.
// Documentation:
//   https://developers.google.com/+/domains/
// Classes:
//   GTLPlusDomainsPerson (0 custom class methods, 28 custom properties)
//   GTLPlusDomainsPersonCover (0 custom class methods, 3 custom properties)
//   GTLPlusDomainsPersonEmailsItem (0 custom class methods, 2 custom properties)
//   GTLPlusDomainsPersonImage (0 custom class methods, 2 custom properties)
//   GTLPlusDomainsPersonName (0 custom class methods, 6 custom properties)
//   GTLPlusDomainsPersonOrganizationsItem (0 custom class methods, 9 custom properties)
//   GTLPlusDomainsPersonPlacesLivedItem (0 custom class methods, 2 custom properties)
//   GTLPlusDomainsPersonUrlsItem (0 custom class methods, 3 custom properties)
//   GTLPlusDomainsPersonCoverCoverInfo (0 custom class methods, 2 custom properties)
//   GTLPlusDomainsPersonCoverCoverPhoto (0 custom class methods, 3 custom properties)

#import "GTLPlusDomainsPerson.h"

// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPerson
//

@implementation GTLPlusDomainsPerson
@dynamic aboutMe, birthday, braggingRights, circledByCount, cover,
         currentLocation, displayName, domain, emails, ETag, gender, identifier,
         image, isPlusUser, kind, name, nickname, objectType, occupation,
         organizations, placesLived, plusOneCount, relationshipStatus, skills,
         tagline, url, urls, verified;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"ETag" : @"etag",
    @"identifier" : @"id"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"emails" : [GTLPlusDomainsPersonEmailsItem class],
    @"organizations" : [GTLPlusDomainsPersonOrganizationsItem class],
    @"placesLived" : [GTLPlusDomainsPersonPlacesLivedItem class],
    @"urls" : [GTLPlusDomainsPersonUrlsItem class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"plus#person"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonCover
//

@implementation GTLPlusDomainsPersonCover
@dynamic coverInfo, coverPhoto, layout;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonEmailsItem
//

@implementation GTLPlusDomainsPersonEmailsItem
@dynamic type, value;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonImage
//

@implementation GTLPlusDomainsPersonImage
@dynamic isDefault, url;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonName
//

@implementation GTLPlusDomainsPersonName
@dynamic familyName, formatted, givenName, honorificPrefix, honorificSuffix,
         middleName;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonOrganizationsItem
//

@implementation GTLPlusDomainsPersonOrganizationsItem
@dynamic department, descriptionProperty, endDate, location, name, primary,
         startDate, title, type;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"descriptionProperty" : @"description"
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonPlacesLivedItem
//

@implementation GTLPlusDomainsPersonPlacesLivedItem
@dynamic primary, value;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonUrlsItem
//

@implementation GTLPlusDomainsPersonUrlsItem
@dynamic label, type, value;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonCoverCoverInfo
//

@implementation GTLPlusDomainsPersonCoverCoverInfo
@dynamic leftImageOffset, topImageOffset;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonCoverCoverPhoto
//

@implementation GTLPlusDomainsPersonCoverCoverPhoto
@dynamic height, url, width;
@end
