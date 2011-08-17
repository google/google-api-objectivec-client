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
//  GTLUrlshortenerAnalyticsSummary.h
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
//   GTLUrlshortenerAnalyticsSummary (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLUrlshortenerAnalyticsSnapshot;

// ----------------------------------------------------------------------------
//
//   GTLUrlshortenerAnalyticsSummary
//

@interface GTLUrlshortenerAnalyticsSummary : GTLObject

// Click analytics over all time.
@property (retain) GTLUrlshortenerAnalyticsSnapshot *allTime;

// Click analytics over the last day.
@property (retain) GTLUrlshortenerAnalyticsSnapshot *day;

// Click analytics over the last month.
@property (retain) GTLUrlshortenerAnalyticsSnapshot *month;

// Click analytics over the last two hours.
@property (retain) GTLUrlshortenerAnalyticsSnapshot *twoHours;

// Click analytics over the last week.
@property (retain) GTLUrlshortenerAnalyticsSnapshot *week;

@end
