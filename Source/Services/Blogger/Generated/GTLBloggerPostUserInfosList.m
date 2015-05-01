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
//  GTLBloggerPostUserInfosList.m
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
//   GTLBloggerPostUserInfosList (0 custom class methods, 3 custom properties)

#import "GTLBloggerPostUserInfosList.h"

#import "GTLBloggerPostUserInfo.h"

// ----------------------------------------------------------------------------
//
//   GTLBloggerPostUserInfosList
//

@implementation GTLBloggerPostUserInfosList
@dynamic items, kind, nextPageToken;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"items" : [GTLBloggerPostUserInfo class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"blogger#postUserInfosList"];
}

@end
