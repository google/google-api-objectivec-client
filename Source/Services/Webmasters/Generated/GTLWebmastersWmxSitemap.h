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
//  GTLWebmastersWmxSitemap.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLWebmastersWmxSitemapContent;

// ----------------------------------------------------------------------------
//
//   GTLWebmastersWmxSitemap
//

// Contains detailed information about a specific URL submitted as a sitemap.

@interface GTLWebmastersWmxSitemap : GTLObject

// The various content types in the sitemap.
@property (nonatomic, retain) NSArray *contents;  // of GTLWebmastersWmxSitemapContent

// Number of errors in the sitemap. These are issues with the sitemap itself
// that need to be fixed before it can be processed correctly.
@property (nonatomic, retain) NSNumber *errors;  // longLongValue

// If true, the sitemap has not been processed.
@property (nonatomic, retain) NSNumber *isPending;  // boolValue

// If true, the sitemap is a collection of sitemaps.
@property (nonatomic, retain) NSNumber *isSitemapsIndex;  // boolValue

// Date & time in which this sitemap was last downloaded. Date format is in RFC
// 3339 format (yyyy-mm-dd).
@property (nonatomic, retain) GTLDateTime *lastDownloaded;

// Date & time in which this sitemap was submitted. Date format is in RFC 3339
// format (yyyy-mm-dd).
@property (nonatomic, retain) GTLDateTime *lastSubmitted;

// The url of the sitemap.
@property (nonatomic, copy) NSString *path;

// The type of the sitemap. For example: rssFeed.
@property (nonatomic, copy) NSString *type;

// Number of warnings for the sitemap. These are generally non-critical issues
// with URLs in the sitemaps.
@property (nonatomic, retain) NSNumber *warnings;  // longLongValue

@end
