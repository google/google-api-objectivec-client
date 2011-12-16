/* Copyright (c) 2011 Google Inc.
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
//  GTLAdsenseAccounts.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Management API (adsense/v1.1)
// Description:
//   Gives AdSense publishers access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://code.google.com/apis/adsense/management/
// Classes:
//   GTLAdsenseAccounts (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdsenseAccount;

// ----------------------------------------------------------------------------
//
//   GTLAdsenseAccounts
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLAdsenseAccounts : GTLCollectionObject

// ETag of this response for caching purposes.
@property (copy) NSString *ETag;

// The accounts returned in this list response.
@property (retain) NSArray *items;  // of GTLAdsenseAccount

// Kind of list this is, in this case adsense#accounts.
@property (copy) NSString *kind;

// Continuation token used to page through accounts. To retrieve the next page
// of results, set the next request's "pageToken" value to this.
@property (copy) NSString *nextPageToken;

@end
