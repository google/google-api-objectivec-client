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
//  GTLBloggerBlog.m
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
//   GTLBloggerBlog (0 custom class methods, 13 custom properties)
//   GTLBloggerBlogLocale (0 custom class methods, 3 custom properties)
//   GTLBloggerBlogPages (0 custom class methods, 2 custom properties)
//   GTLBloggerBlogPosts (0 custom class methods, 3 custom properties)

#import "GTLBloggerBlog.h"

#import "GTLBloggerPost.h"

// ----------------------------------------------------------------------------
//
//   GTLBloggerBlog
//

@implementation GTLBloggerBlog
@dynamic customMetaData, descriptionProperty, identifier, kind, locale, name,
         pages, posts, published, selfLink, status, updated, url;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"descriptionProperty" : @"description",
    @"identifier" : @"id"
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"blogger#blog"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerBlogLocale
//

@implementation GTLBloggerBlogLocale
@dynamic country, language, variant;
@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerBlogPages
//

@implementation GTLBloggerBlogPages
@dynamic selfLink, totalItems;
@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerBlogPosts
//

@implementation GTLBloggerBlogPosts
@dynamic items, selfLink, totalItems;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"items" : [GTLBloggerPost class]
  };
  return map;
}

@end
