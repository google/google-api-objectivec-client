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
//  GTLWebmastersWmxSitemap.m
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
//   GTLWebmastersWmxSitemap (0 custom class methods, 9 custom properties)

#import "GTLWebmastersWmxSitemap.h"

#import "GTLWebmastersWmxSitemapContent.h"

// ----------------------------------------------------------------------------
//
//   GTLWebmastersWmxSitemap
//

@implementation GTLWebmastersWmxSitemap
@dynamic contents, errors, isPending, isSitemapsIndex, lastDownloaded,
         lastSubmitted, path, type, warnings;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"contents" : [GTLWebmastersWmxSitemapContent class]
  };
  return map;
}

@end
