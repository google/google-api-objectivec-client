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
//  GTLUrlshortenerUrlHistory.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   URL Shortener API (urlshortener/v1)
// Description:
//   Lets you create, inspect, and manage goo.gl short URLs
// Documentation:
//   https://developers.google.com/url-shortener/v1/getting_started
// Classes:
//   GTLUrlshortenerUrlHistory (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLUrlshortenerUrl;

// ----------------------------------------------------------------------------
//
//   GTLUrlshortenerUrlHistory
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLUrlshortenerUrlHistory : GTLCollectionObject

// A list of URL resources.
@property (nonatomic, retain) NSArray *items;  // of GTLUrlshortenerUrl

// Number of items returned with each full "page" of results. Note that the last
// page could have fewer items than the "itemsPerPage" value.
@property (nonatomic, retain) NSNumber *itemsPerPage;  // intValue

// The fixed string "urlshortener#urlHistory".
@property (nonatomic, copy) NSString *kind;

// A token to provide to get the next page of results.
@property (nonatomic, copy) NSString *nextPageToken;

// Total number of short URLs associated with this user (may be approximate).
@property (nonatomic, retain) NSNumber *totalItems;  // intValue

@end
