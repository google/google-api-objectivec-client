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
//  GTLWebmastersUrlCrawlErrorsSample.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Webmaster Tools API (webmasters/v3)
// Description:
//   Lets you view Google Webmaster Tools data for your verified sites.
// Documentation:
//   https://developers.google.com/webmaster-tools/
// Classes:
//   GTLWebmastersUrlCrawlErrorsSample (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLWebmastersUrlSampleDetails;

// ----------------------------------------------------------------------------
//
//   GTLWebmastersUrlCrawlErrorsSample
//

// Contains information about specific crawl errors.

@interface GTLWebmastersUrlCrawlErrorsSample : GTLObject

// The time the error was first detected, in RFC 3339 format.
@property (nonatomic, retain) GTLDateTime *firstDetected;

// The time when the URL was last crawled, in RFC 3339 format.
@property (nonatomic, retain) GTLDateTime *lastCrawled;

// The URL of an error, relative to the site.
@property (nonatomic, copy) NSString *pageUrl;

// The HTTP response code, if any.
@property (nonatomic, retain) NSNumber *responseCode;  // intValue

// Additional details about the URL, set only when calling get().
@property (nonatomic, retain) GTLWebmastersUrlSampleDetails *urlDetails;

@end
