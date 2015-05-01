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
//  GTLAdExchangeSellerUrlChannels.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Ad Exchange Seller API (adexchangeseller/v2.0)
// Description:
//   Gives Ad Exchange seller users access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://developers.google.com/ad-exchange/seller-rest/
// Classes:
//   GTLAdExchangeSellerUrlChannels (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeSellerUrlChannel;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeSellerUrlChannels
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLAdExchangeSellerUrlChannels : GTLCollectionObject

// ETag of this response for caching purposes.
@property (nonatomic, copy) NSString *ETag;

// The URL channels returned in this list response.
@property (nonatomic, retain) NSArray *items;  // of GTLAdExchangeSellerUrlChannel

// Kind of list this is, in this case adexchangeseller#urlChannels.
@property (nonatomic, copy) NSString *kind;

// Continuation token used to page through URL channels. To retrieve the next
// page of results, set the next request's "pageToken" value to this.
@property (nonatomic, copy) NSString *nextPageToken;

@end
