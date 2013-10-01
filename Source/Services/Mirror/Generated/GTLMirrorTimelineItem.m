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
//  GTLMirrorTimelineItem.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Mirror API (mirror/v1)
// Description:
//   API for interacting with Glass users via the timeline.
// Documentation:
//   https://developers.google.com/glass
// Classes:
//   GTLMirrorTimelineItem (0 custom class methods, 26 custom properties)

#import "GTLMirrorTimelineItem.h"

#import "GTLMirrorAttachment.h"
#import "GTLMirrorContact.h"
#import "GTLMirrorLocation.h"
#import "GTLMirrorMenuItem.h"
#import "GTLMirrorNotificationConfig.h"

// ----------------------------------------------------------------------------
//
//   GTLMirrorTimelineItem
//

@implementation GTLMirrorTimelineItem
@dynamic attachments, bundleId, canonicalUrl, created, creator, displayTime,
         ETag, html, identifier, inReplyTo, isBundleCover, isDeleted, isPinned,
         kind, location, menuItems, notification, pinScore, recipients,
         selfLink, sourceItemId, speakableText, speakableType, text, title,
         updated;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"etag", @"ETag",
      @"id", @"identifier",
      nil];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLMirrorAttachment class], @"attachments",
      [GTLMirrorMenuItem class], @"menuItems",
      [GTLMirrorContact class], @"recipients",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"mirror#timelineItem"];
}

@end
