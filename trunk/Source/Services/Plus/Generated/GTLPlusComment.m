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
//  GTLPlusComment.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google+ API (plus/v1)
// Description:
//   The Google+ API enables developers to build on top of the Google+ platform.
// Documentation:
//   https://developers.google.com/+/api/
// Classes:
//   GTLPlusComment (0 custom class methods, 11 custom properties)
//   GTLPlusCommentActor (0 custom class methods, 5 custom properties)
//   GTLPlusCommentInReplyToItem (0 custom class methods, 2 custom properties)
//   GTLPlusCommentObject (0 custom class methods, 3 custom properties)
//   GTLPlusCommentPlusoners (0 custom class methods, 1 custom properties)
//   GTLPlusCommentActorImage (0 custom class methods, 1 custom properties)
//   GTLPlusCommentActorVerification (0 custom class methods, 1 custom properties)

#import "GTLPlusComment.h"

// ----------------------------------------------------------------------------
//
//   GTLPlusComment
//

@implementation GTLPlusComment
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
    @"inReplyTo" : [GTLPlusCommentInReplyToItem class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"plus#comment"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusCommentActor
//

@implementation GTLPlusCommentActor
@dynamic displayName, identifier, image, url, verification;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"identifier" : @"id"
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusCommentInReplyToItem
//

@implementation GTLPlusCommentInReplyToItem
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
//   GTLPlusCommentObject
//

@implementation GTLPlusCommentObject
@dynamic content, objectType, originalContent;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusCommentPlusoners
//

@implementation GTLPlusCommentPlusoners
@dynamic totalItems;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusCommentActorImage
//

@implementation GTLPlusCommentActorImage
@dynamic url;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusCommentActorVerification
//

@implementation GTLPlusCommentActorVerification
@dynamic adHocVerified;
@end
