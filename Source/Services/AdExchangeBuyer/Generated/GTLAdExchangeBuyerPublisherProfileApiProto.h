/* Copyright (c) 2016 Google Inc.
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
//  GTLAdExchangeBuyerPublisherProfileApiProto.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Ad Exchange Buyer API (adexchangebuyer/v1.4)
// Description:
//   Accesses your bidding-account information, submits creatives for
//   validation, finds available direct deals, and retrieves performance
//   reports.
// Documentation:
//   https://developers.google.com/ad-exchange/buyer-rest
// Classes:
//   GTLAdExchangeBuyerPublisherProfileApiProto (0 custom class methods, 23 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerPublisherProvidedForecast;
@class GTLAdExchangeBuyerSeller;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerPublisherProfileApiProto
//

@interface GTLAdExchangeBuyerPublisherProfileApiProto : GTLObject

// The account id of the seller.
@property (nonatomic, copy) NSString *accountId;

// Publisher provided info on its audience.
@property (nonatomic, copy) NSString *audience;

// A pitch statement for the buyer
@property (nonatomic, copy) NSString *buyerPitchStatement;

// Direct contact for the publisher profile.
@property (nonatomic, copy) NSString *directContact;

// Exchange where this publisher profile is from. E.g. AdX, Rubicon etc...
@property (nonatomic, copy) NSString *exchange;

// Link to publisher's Google+ page.
@property (nonatomic, copy) NSString *googlePlusLink;

// True, if this is the parent profile, which represents all domains owned by
// the publisher.
@property (nonatomic, retain) NSNumber *isParent;  // boolValue

// True, if this profile is published. Deprecated for state.
@property (nonatomic, retain) NSNumber *isPublished;  // boolValue

// Identifies what kind of resource this is. Value: the fixed string
// "adexchangebuyer#publisherProfileApiProto".
@property (nonatomic, copy) NSString *kind;

// The url to the logo for the publisher.
@property (nonatomic, copy) NSString *logoUrl;

// The url for additional marketing and sales materials.
@property (nonatomic, copy) NSString *mediaKitLink;

@property (nonatomic, copy) NSString *name;

// Publisher provided overview.
@property (nonatomic, copy) NSString *overview;

// The pair of (seller.account_id, profile_id) uniquely identifies a publisher
// profile for a given publisher.
@property (nonatomic, retain) NSNumber *profileId;  // intValue

// Programmatic contact for the publisher profile.
@property (nonatomic, copy) NSString *programmaticContact;

// The list of domains represented in this publisher profile. Empty if this is a
// parent profile.
@property (nonatomic, retain) NSArray *publisherDomains;  // of NSString

// Unique Id for publisher profile.
@property (nonatomic, copy) NSString *publisherProfileId;

// Publisher provided forecasting information.
@property (nonatomic, retain) GTLAdExchangeBuyerPublisherProvidedForecast *publisherProvidedForecast;

// Link to publisher rate card
@property (nonatomic, copy) NSString *rateCardInfoLink;

// Link for a sample content page.
@property (nonatomic, copy) NSString *samplePageLink;

// Seller of the publisher profile.
@property (nonatomic, retain) GTLAdExchangeBuyerSeller *seller;

// State of the publisher profile.
@property (nonatomic, copy) NSString *state;

// Publisher provided key metrics and rankings.
@property (nonatomic, retain) NSArray *topHeadlines;  // of NSString

@end
