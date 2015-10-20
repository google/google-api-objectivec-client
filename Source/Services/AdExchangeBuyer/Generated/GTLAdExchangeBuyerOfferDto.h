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
//  GTLAdExchangeBuyerOfferDto.h
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
//   GTLAdExchangeBuyerOfferDto (0 custom class methods, 14 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerDealPartyDto;
@class GTLAdExchangeBuyerTermsDto;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerOfferDto
//

@interface GTLAdExchangeBuyerOfferDto : GTLObject

// Whether this offer is anonymous.
@property (nonatomic, retain) NSNumber *anonymous;  // boolValue

// The billed buyer; For buyer initiated offers, buying through an intermediary.
@property (nonatomic, retain) GTLAdExchangeBuyerDealPartyDto *billedBuyer;

// The list of buyer or seller parties this offer is closed to.
@property (nonatomic, retain) NSArray *closedToDealParties;  // of GTLAdExchangeBuyerDealPartyDto

// The creator of this offer.
@property (nonatomic, retain) GTLAdExchangeBuyerDealPartyDto *creator;

// The list of email contacts for this offer.
@property (nonatomic, retain) NSArray *emailContacts;  // of NSString

// Whether this offer is open.
@property (nonatomic, retain) NSNumber *isOpen;  // boolValue

@property (nonatomic, copy) NSString *kind;

// The list of label names applicable to this offer.
@property (nonatomic, retain) NSArray *labelNames;  // of NSString

// The unique ID of this offer.
@property (nonatomic, retain) NSNumber *offerId;  // longLongValue

// The state of this offer.
@property (nonatomic, copy) NSString *offerState;

// The list of buyer or seller parties this offer is open to.
@property (nonatomic, retain) NSArray *openToDealParties;  // of GTLAdExchangeBuyerDealPartyDto

// The point of contact for this offer.
@property (nonatomic, copy) NSString *pointOfContact;

// The status of this offer.
@property (nonatomic, copy) NSString *status;

// The terms of this offer.
@property (nonatomic, retain) GTLAdExchangeBuyerTermsDto *terms;

@end
