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
//  GTLPlusDomainsPerson.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLPlusDomainsPersonCover;
@class GTLPlusDomainsPersonCoverCoverInfo;
@class GTLPlusDomainsPersonCoverCoverPhoto;
@class GTLPlusDomainsPersonEmailsItem;
@class GTLPlusDomainsPersonImage;
@class GTLPlusDomainsPersonName;
@class GTLPlusDomainsPersonOrganizationsItem;
@class GTLPlusDomainsPersonPlacesLivedItem;
@class GTLPlusDomainsPersonUrlsItem;

// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPerson
//

@interface GTLPlusDomainsPerson : GTLObject

// A short biography for this person.
@property (nonatomic, copy) NSString *aboutMe;

// The person's date of birth, represented as YYYY-MM-DD.
@property (nonatomic, copy) NSString *birthday;

// The "bragging rights" line of this person.
@property (nonatomic, copy) NSString *braggingRights;

// For followers who are visible, the number of people who have added this
// person or page to a circle.
@property (nonatomic, retain) NSNumber *circledByCount;  // intValue

// The cover photo content.
@property (nonatomic, retain) GTLPlusDomainsPersonCover *cover;

// (this field is not currently used)
@property (nonatomic, copy) NSString *currentLocation;

// The name of this person, which is suitable for display.
@property (nonatomic, copy) NSString *displayName;

// The hosted domain name for the user's Google Apps account. For instance,
// example.com. The plus.profile.emails.read or email scope is needed to get
// this domain name.
@property (nonatomic, copy) NSString *domain;

// A list of email addresses that this person has, including their Google
// account email address, and the public verified email addresses on their
// Google+ profile. The plus.profile.emails.read scope is needed to retrieve
// these email addresses, or the email scope can be used to retrieve just the
// Google account email address.
@property (nonatomic, retain) NSArray *emails;  // of GTLPlusDomainsPersonEmailsItem

// ETag of this response for caching purposes.
@property (nonatomic, copy) NSString *ETag;

// The person's gender. Possible values include, but are not limited to, the
// following values:
// - "male" - Male gender.
// - "female" - Female gender.
// - "other" - Other.
@property (nonatomic, copy) NSString *gender;

// The ID of this person.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The representation of the person's profile photo.
@property (nonatomic, retain) GTLPlusDomainsPersonImage *image;

// Whether this user has signed up for Google+.
@property (nonatomic, retain) NSNumber *isPlusUser;  // boolValue

// Identifies this resource as a person. Value: "plus#person".
@property (nonatomic, copy) NSString *kind;

// An object representation of the individual components of a person's name.
@property (nonatomic, retain) GTLPlusDomainsPersonName *name;

// The nickname of this person.
@property (nonatomic, copy) NSString *nickname;

// Type of person within Google+. Possible values include, but are not limited
// to, the following values:
// - "person" - represents an actual person.
// - "page" - represents a page.
@property (nonatomic, copy) NSString *objectType;

// The occupation of this person.
@property (nonatomic, copy) NSString *occupation;

// A list of current or past organizations with which this person is associated.
@property (nonatomic, retain) NSArray *organizations;  // of GTLPlusDomainsPersonOrganizationsItem

// A list of places where this person has lived.
@property (nonatomic, retain) NSArray *placesLived;  // of GTLPlusDomainsPersonPlacesLivedItem

// If a Google+ Page, the number of people who have +1'd this page.
@property (nonatomic, retain) NSNumber *plusOneCount;  // intValue

// The person's relationship status. Possible values include, but are not
// limited to, the following values:
// - "single" - Person is single.
// - "in_a_relationship" - Person is in a relationship.
// - "engaged" - Person is engaged.
// - "married" - Person is married.
// - "its_complicated" - The relationship is complicated.
// - "open_relationship" - Person is in an open relationship.
// - "widowed" - Person is widowed.
// - "in_domestic_partnership" - Person is in a domestic partnership.
// - "in_civil_union" - Person is in a civil union.
@property (nonatomic, copy) NSString *relationshipStatus;

// The person's skills.
@property (nonatomic, copy) NSString *skills;

// The brief description (tagline) of this person.
@property (nonatomic, copy) NSString *tagline;

// The URL of this person's profile.
@property (nonatomic, copy) NSString *url;

// A list of URLs for this person.
@property (nonatomic, retain) NSArray *urls;  // of GTLPlusDomainsPersonUrlsItem

// Whether the person or Google+ Page has been verified.
@property (nonatomic, retain) NSNumber *verified;  // boolValue

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonCover
//

@interface GTLPlusDomainsPersonCover : GTLObject

// Extra information about the cover photo.
@property (nonatomic, retain) GTLPlusDomainsPersonCoverCoverInfo *coverInfo;

// The person's primary cover image.
@property (nonatomic, retain) GTLPlusDomainsPersonCoverCoverPhoto *coverPhoto;

// The layout of the cover art. Possible values include, but are not limited to,
// the following values:
// - "banner" - One large image banner.
@property (nonatomic, copy) NSString *layout;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonEmailsItem
//

@interface GTLPlusDomainsPersonEmailsItem : GTLObject

// The type of address. Possible values include, but are not limited to, the
// following values:
// - "account" - Google account email address.
// - "home" - Home email address.
// - "work" - Work email address.
// - "other" - Other.
@property (nonatomic, copy) NSString *type;

// The email address.
@property (nonatomic, copy) NSString *value;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonImage
//

@interface GTLPlusDomainsPersonImage : GTLObject

// Whether the person's profile photo is the default one
@property (nonatomic, retain) NSNumber *isDefault;  // boolValue

// The URL of the person's profile photo. To resize the image and crop it to a
// square, append the query string ?sz=x, where x is the dimension in pixels of
// each side.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonName
//

@interface GTLPlusDomainsPersonName : GTLObject

// The family name (last name) of this person.
@property (nonatomic, copy) NSString *familyName;

// The full name of this person, including middle names, suffixes, etc.
@property (nonatomic, copy) NSString *formatted;

// The given name (first name) of this person.
@property (nonatomic, copy) NSString *givenName;

// The honorific prefixes (such as "Dr." or "Mrs.") for this person.
@property (nonatomic, copy) NSString *honorificPrefix;

// The honorific suffixes (such as "Jr.") for this person.
@property (nonatomic, copy) NSString *honorificSuffix;

// The middle name of this person.
@property (nonatomic, copy) NSString *middleName;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonOrganizationsItem
//

@interface GTLPlusDomainsPersonOrganizationsItem : GTLObject

// The department within the organization. Deprecated.
@property (nonatomic, copy) NSString *department;

// A short description of the person's role in this organization. Deprecated.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// The date that the person left this organization.
@property (nonatomic, copy) NSString *endDate;

// The location of this organization. Deprecated.
@property (nonatomic, copy) NSString *location;

// The name of the organization.
@property (nonatomic, copy) NSString *name;

// If "true", indicates this organization is the person's primary one, which is
// typically interpreted as the current one.
@property (nonatomic, retain) NSNumber *primary;  // boolValue

// The date that the person joined this organization.
@property (nonatomic, copy) NSString *startDate;

// The person's job title or role within the organization.
@property (nonatomic, copy) NSString *title;

// The type of organization. Possible values include, but are not limited to,
// the following values:
// - "work" - Work.
// - "school" - School.
@property (nonatomic, copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonPlacesLivedItem
//

@interface GTLPlusDomainsPersonPlacesLivedItem : GTLObject

// If "true", this place of residence is this person's primary residence.
@property (nonatomic, retain) NSNumber *primary;  // boolValue

// A place where this person has lived. For example: "Seattle, WA", "Near
// Toronto".
@property (nonatomic, copy) NSString *value;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonUrlsItem
//

@interface GTLPlusDomainsPersonUrlsItem : GTLObject

// The label of the URL.
@property (nonatomic, copy) NSString *label;

// The type of URL. Possible values include, but are not limited to, the
// following values:
// - "otherProfile" - URL for another profile.
// - "contributor" - URL to a site for which this person is a contributor.
// - "website" - URL for this Google+ Page's primary website.
// - "other" - Other URL.
@property (nonatomic, copy) NSString *type;

// The URL value.
@property (nonatomic, copy) NSString *value;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonCoverCoverInfo
//

@interface GTLPlusDomainsPersonCoverCoverInfo : GTLObject

// The difference between the left position of the cover image and the actual
// displayed cover image. Only valid for banner layout.
@property (nonatomic, retain) NSNumber *leftImageOffset;  // intValue

// The difference between the top position of the cover image and the actual
// displayed cover image. Only valid for banner layout.
@property (nonatomic, retain) NSNumber *topImageOffset;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPersonCoverCoverPhoto
//

@interface GTLPlusDomainsPersonCoverCoverPhoto : GTLObject

// The height of the image.
@property (nonatomic, retain) NSNumber *height;  // intValue

// The URL of the image.
@property (nonatomic, copy) NSString *url;

// The width of the image.
@property (nonatomic, retain) NSNumber *width;  // intValue

@end
