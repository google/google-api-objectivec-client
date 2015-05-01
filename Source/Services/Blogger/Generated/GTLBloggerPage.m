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
//  GTLBloggerPage.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Blogger API (blogger/v3)
// Description:
//   API for access to the data within Blogger.
// Documentation:
//   https://developers.google.com/blogger/docs/3.0/getting_started
// Classes:
//   GTLBloggerPage (0 custom class methods, 12 custom properties)
//   GTLBloggerPageAuthor (0 custom class methods, 4 custom properties)
//   GTLBloggerPageBlog (0 custom class methods, 1 custom properties)
//   GTLBloggerPageAuthorImage (0 custom class methods, 1 custom properties)

#import "GTLBloggerPage.h"

// ----------------------------------------------------------------------------
//
//   GTLBloggerPage
//

@implementation GTLBloggerPage
@dynamic author, blog, content, ETag, identifier, kind, published, selfLink,
         status, title, updated, url;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"ETag" : @"etag",
    @"identifier" : @"id"
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"blogger#page"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerPageAuthor
//

@implementation GTLBloggerPageAuthor
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
//   GTLBloggerPageBlog
//

@implementation GTLBloggerPageBlog
@dynamic identifier;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"identifier" : @"id"
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerPageAuthorImage
//

@implementation GTLBloggerPageAuthorImage
@dynamic url;
@end
