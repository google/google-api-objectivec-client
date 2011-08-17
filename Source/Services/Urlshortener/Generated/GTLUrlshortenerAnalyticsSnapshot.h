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
//  GTLUrlshortenerAnalyticsSnapshot.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   URL Shortener API (urlshortener/v1)
// Description:
//   Lets you create, inspect, and manage goo.gl short URLs
// Documentation:
//   http://code.google.com/apis/urlshortener/v1/getting_started.html
// Classes:
//   GTLUrlshortenerAnalyticsSnapshot (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLUrlshortenerStringCount;

// ----------------------------------------------------------------------------
//
//   GTLUrlshortenerAnalyticsSnapshot
//

@interface GTLUrlshortenerAnalyticsSnapshot : GTLObject

// Top browsers, e.g. "Chrome"; sorted by (descending) click counts. Only
// present if this data is available.
@property (retain) NSArray *browsers;  // of GTLUrlshortenerStringCount

// Top countries (expressed as country codes), e.g. "US" or "DE"; sorted by
// (descending) click counts. Only present if this data is available.
@property (retain) NSArray *countries;  // of GTLUrlshortenerStringCount

// Number of clicks on all goo.gl short URLs pointing to this long URL.
@property (retain) NSNumber *longUrlClicks;  // longLongValue

// Top platforms or OSes, e.g. "Windows"; sorted by (descending) click counts.
// Only present if this data is available.
@property (retain) NSArray *platforms;  // of GTLUrlshortenerStringCount

// Top referring hosts, e.g. "www.google.com"; sorted by (descending) click
// counts. Only present if this data is available.
@property (retain) NSArray *referrers;  // of GTLUrlshortenerStringCount

// Number of clicks on this short URL.
@property (retain) NSNumber *shortUrlClicks;  // longLongValue

@end
