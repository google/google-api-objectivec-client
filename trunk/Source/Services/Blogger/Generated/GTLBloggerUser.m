/* Copyright (c) 2012 Google Inc.
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
//  GTLBloggerUser.m
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
//   GTLBloggerUser (0 custom class methods, 9 custom properties)
//   GTLBloggerUserBlogs (0 custom class methods, 1 custom properties)
//   GTLBloggerUserLocale (0 custom class methods, 3 custom properties)

#import "GTLBloggerUser.h"

// ----------------------------------------------------------------------------
//
//   GTLBloggerUser
//

@implementation GTLBloggerUser
@dynamic about, blogs, created, displayName, identifier, kind, locale, selfLink,
         url;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"blogger#user"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerUserBlogs
//

@implementation GTLBloggerUserBlogs
@dynamic selfLink;
@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerUserLocale
//

@implementation GTLBloggerUserLocale
@dynamic country, language, variant;
@end
