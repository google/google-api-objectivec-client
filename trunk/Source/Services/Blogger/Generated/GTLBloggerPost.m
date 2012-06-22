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
//  GTLBloggerPost.m
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
//   GTLBloggerPost (0 custom class methods, 14 custom properties)
//   GTLBloggerPostAuthor (0 custom class methods, 4 custom properties)
//   GTLBloggerPostBlog (0 custom class methods, 1 custom properties)
//   GTLBloggerPostLocation (0 custom class methods, 4 custom properties)
//   GTLBloggerPostReplies (0 custom class methods, 3 custom properties)
//   GTLBloggerPostAuthorImage (0 custom class methods, 1 custom properties)

#import "GTLBloggerPost.h"

#import "GTLBloggerComment.h"

// ----------------------------------------------------------------------------
//
//   GTLBloggerPost
//

@implementation GTLBloggerPost
@dynamic author, blog, content, customMetaData, identifier, kind, labels,
         location, published, replies, selfLink, title, updated, url;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[NSString class]
                                forKey:@"labels"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"blogger#post"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerPostAuthor
//

@implementation GTLBloggerPostAuthor
@dynamic displayName, identifier, image, url;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerPostBlog
//

@implementation GTLBloggerPostBlog
@dynamic identifier;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerPostLocation
//

@implementation GTLBloggerPostLocation
@dynamic lat, lng, name, span;
@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerPostReplies
//

@implementation GTLBloggerPostReplies
@dynamic items, selfLink, totalItems;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLBloggerComment class]
                                forKey:@"items"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerPostAuthorImage
//

@implementation GTLBloggerPostAuthorImage
@dynamic url;
@end
