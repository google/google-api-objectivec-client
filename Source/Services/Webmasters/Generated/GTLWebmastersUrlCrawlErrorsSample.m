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
//  GTLWebmastersUrlCrawlErrorsSample.m
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

#import "GTLWebmastersUrlCrawlErrorsSample.h"

#import "GTLWebmastersUrlSampleDetails.h"

// ----------------------------------------------------------------------------
//
//   GTLWebmastersUrlCrawlErrorsSample
//

@implementation GTLWebmastersUrlCrawlErrorsSample
@dynamic firstDetected, lastCrawled, pageUrl, responseCode, urlDetails;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"firstDetected" : @"first_detected",
    @"lastCrawled" : @"last_crawled"
  };
  return map;
}

@end
