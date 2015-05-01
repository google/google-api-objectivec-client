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
//  GTLPlusDomainsAudiencesFeed.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google+ Domains API (plusDomains/v1)
// Description:
//   The Google+ API enables developers to build on top of the Google+ platform.
// Documentation:
//   https://developers.google.com/+/domains/
// Classes:
//   GTLPlusDomainsAudiencesFeed (0 custom class methods, 5 custom properties)

#import "GTLPlusDomainsAudiencesFeed.h"

#import "GTLPlusDomainsAudience.h"

// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsAudiencesFeed
//

@implementation GTLPlusDomainsAudiencesFeed
@dynamic ETag, items, kind, nextPageToken, totalItems;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"ETag" : @"etag"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"items" : [GTLPlusDomainsAudience class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"plus#audiencesFeed"];
}

@end
