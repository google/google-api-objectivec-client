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
//  GTLAdExchangeBuyerCreativesList.h
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
//   GTLAdExchangeBuyerCreativesList (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerCreative;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerCreativesList
//

// The creatives feed lists the active creatives for the Ad Exchange buyer
// accounts that the user has access to. Each entry in the feed corresponds to a
// single creative.

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLAdExchangeBuyerCreativesList : GTLCollectionObject

// A list of creatives.
@property (nonatomic, retain) NSArray *items;  // of GTLAdExchangeBuyerCreative

// Resource type.
@property (nonatomic, copy) NSString *kind;

// Continuation token used to page through creatives. To retrieve the next page
// of results, set the next request's "pageToken" value to this.
@property (nonatomic, copy) NSString *nextPageToken;

@end
