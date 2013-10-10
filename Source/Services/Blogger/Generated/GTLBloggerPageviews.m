/* Copyright (c) 2013 Google Inc.
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
//  GTLBloggerPageviews.m
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
//   GTLBloggerPageviews (0 custom class methods, 3 custom properties)
//   GTLBloggerPageviewsCountsItem (0 custom class methods, 2 custom properties)

#import "GTLBloggerPageviews.h"

// ----------------------------------------------------------------------------
//
//   GTLBloggerPageviews
//

@implementation GTLBloggerPageviews
@dynamic blogId, counts, kind;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLBloggerPageviewsCountsItem class]
                                forKey:@"counts"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"blogger#page_views"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerPageviewsCountsItem
//

@implementation GTLBloggerPageviewsCountsItem
@dynamic count, timeRange;
@end
