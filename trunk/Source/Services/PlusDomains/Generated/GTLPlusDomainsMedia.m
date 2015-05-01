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
//  GTLPlusDomainsMedia.m
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
//   GTLPlusDomainsMedia (0 custom class methods, 18 custom properties)
//   GTLPlusDomainsMediaAuthor (0 custom class methods, 4 custom properties)
//   GTLPlusDomainsMediaExif (0 custom class methods, 1 custom properties)
//   GTLPlusDomainsMediaAuthorImage (0 custom class methods, 1 custom properties)

#import "GTLPlusDomainsMedia.h"

#import "GTLPlusDomainsVideostream.h"

// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsMedia
//

@implementation GTLPlusDomainsMedia
@dynamic author, displayName, ETag, exif, height, identifier, kind,
         mediaCreatedTime, mediaUrl, published, sizeBytes, streams, summary,
         updated, url, videoDuration, videoStatus, width;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"ETag" : @"etag",
    @"identifier" : @"id"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"streams" : [GTLPlusDomainsVideostream class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"plus#media"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsMediaAuthor
//

@implementation GTLPlusDomainsMediaAuthor
@dynamic displayName, identifier, image, url;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"identifier" : @"id"
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsMediaExif
//

@implementation GTLPlusDomainsMediaExif
@dynamic time;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsMediaAuthorImage
//

@implementation GTLPlusDomainsMediaAuthorImage
@dynamic url;
@end
