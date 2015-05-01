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
//  GTLPlusDomainsComment.m
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
//   GTLPlusDomainsComment (0 custom class methods, 11 custom properties)
//   GTLPlusDomainsCommentActor (0 custom class methods, 4 custom properties)
//   GTLPlusDomainsCommentInReplyToItem (0 custom class methods, 2 custom properties)
//   GTLPlusDomainsCommentObject (0 custom class methods, 3 custom properties)
//   GTLPlusDomainsCommentPlusoners (0 custom class methods, 1 custom properties)
//   GTLPlusDomainsCommentActorImage (0 custom class methods, 1 custom properties)

#import "GTLPlusDomainsComment.h"

// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsComment
//

@implementation GTLPlusDomainsComment
@dynamic actor, ETag, identifier, inReplyTo, kind, object, plusoners, published,
         selfLink, updated, verb;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"ETag" : @"etag",
    @"identifier" : @"id"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"inReplyTo" : [GTLPlusDomainsCommentInReplyToItem class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"plus#comment"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsCommentActor
//

@implementation GTLPlusDomainsCommentActor
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
//   GTLPlusDomainsCommentInReplyToItem
//

@implementation GTLPlusDomainsCommentInReplyToItem
@dynamic identifier, url;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"identifier" : @"id"
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsCommentObject
//

@implementation GTLPlusDomainsCommentObject
@dynamic content, objectType, originalContent;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsCommentPlusoners
//

@implementation GTLPlusDomainsCommentPlusoners
@dynamic totalItems;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsCommentActorImage
//

@implementation GTLPlusDomainsCommentActorImage
@dynamic url;
@end
