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
//  GTLUrlshortenerUrl.h
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
//   GTLUrlshortenerUrl (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLUrlshortenerAnalyticsSummary;

// ----------------------------------------------------------------------------
//
//   GTLUrlshortenerUrl
//

@interface GTLUrlshortenerUrl : GTLObject

// A summary of the click analytics for the short and long URL. Might not be
// present if not requested or currently unavailable.
@property (nonatomic, retain) GTLUrlshortenerAnalyticsSummary *analytics;

// Time the short URL was created; ISO 8601 representation using the
// yyyy-MM-dd'T'HH:mm:ss.SSSZZ format, e.g. "2010-10-14T19:01:24.944+00:00".
@property (nonatomic, copy) NSString *created;

// Short URL, e.g. "http://goo.gl/l6MS".
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The fixed string "urlshortener#url".
@property (nonatomic, copy) NSString *kind;

// Long URL, e.g. "http://www.google.com/". Might not be present if the status
// is "REMOVED".
@property (nonatomic, copy) NSString *longUrl;

// Status of the target URL. Possible values: "OK", "MALWARE", "PHISHING", or
// "REMOVED". A URL might be marked "REMOVED" if it was flagged as spam, for
// example.
@property (nonatomic, copy) NSString *status;

@end
