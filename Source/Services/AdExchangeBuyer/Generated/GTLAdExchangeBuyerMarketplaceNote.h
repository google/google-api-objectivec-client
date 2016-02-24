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
//  GTLAdExchangeBuyerMarketplaceNote.h
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
//   GTLAdExchangeBuyerMarketplaceNote (0 custom class methods, 8 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerMarketplaceNote
//

// A proposal is associated with a bunch of notes which may optionally be
// associated with a deal and/or revision number.

@interface GTLAdExchangeBuyerMarketplaceNote : GTLObject

// The role of the person (buyer/seller) creating the note. (readonly)
@property (nonatomic, copy) NSString *creatorRole;

// Notes can optionally be associated with a deal. (readonly, except on create)
@property (nonatomic, copy) NSString *dealId;

// Identifies what kind of resource this is. Value: the fixed string
// "adexchangebuyer#marketplaceNote".
@property (nonatomic, copy) NSString *kind;

// The actual note to attach. (readonly, except on create)
@property (nonatomic, copy) NSString *note;

// The unique id for the note. (readonly)
@property (nonatomic, copy) NSString *noteId;

// The proposalId that a note is attached to. (readonly)
@property (nonatomic, copy) NSString *proposalId;

// If the note is associated with a proposal revision number, then store that
// here. (readonly, except on create)
@property (nonatomic, retain) NSNumber *proposalRevisionNumber;  // longLongValue

// The timestamp (ms since epoch) that this note was created. (readonly)
@property (nonatomic, retain) NSNumber *timestampMs;  // longLongValue

@end
