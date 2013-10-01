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
//  GTLMirrorTimelineItem.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLMirrorAttachment;
@class GTLMirrorContact;
@class GTLMirrorLocation;
@class GTLMirrorMenuItem;
@class GTLMirrorNotificationConfig;

// ----------------------------------------------------------------------------
//
//   GTLMirrorTimelineItem
//

// Each item in the user's timeline is represented as a TimelineItem JSON
// structure, described below.

@interface GTLMirrorTimelineItem : GTLObject

// A list of media attachments associated with this item. As a convenience, you
// can refer to attachments in your HTML payloads with the attachment or cid
// scheme. For example:
// - attachment: <img src="attachment:attachment_index"> where attachment_index
// is the 0-based index of this array.
// - cid: <img src="cid:attachment_id"> where attachment_id is the ID of the
// attachment.
@property (retain) NSArray *attachments;  // of GTLMirrorAttachment

// The bundle ID for this item. Services can specify a bundleId to group many
// items together. They appear under a single top-level item on the device.
@property (copy) NSString *bundleId;

// A canonical URL pointing to the canonical/high quality version of the data
// represented by the timeline item.
@property (copy) NSString *canonicalUrl;

// The time at which this item was created, formatted according to RFC 3339.
@property (retain) GTLDateTime *created;

// The user or group that created this item.
@property (retain) GTLMirrorContact *creator;

// The time that should be displayed when this item is viewed in the timeline,
// formatted according to RFC 3339. This user's timeline is sorted
// chronologically on display time, so this will also determine where the item
// is displayed in the timeline. If not set by the service, the display time
// defaults to the updated time.
@property (retain) GTLDateTime *displayTime;

// ETag for this item.
@property (copy) NSString *ETag;

// HTML content for this item. If both text and html are provided for an item,
// the html will be rendered in the timeline.
// Allowed HTML elements - You can use these elements in your timeline cards.
// - Headers: h1, h2, h3, h4, h5, h6
// - Images: img
// - Lists: li, ol, ul
// - HTML5 semantics: article, aside, details, figure, figcaption, footer,
// header, nav, section, summary, time
// - Structural: blockquote, br, div, hr, p, span
// - Style: b, big, center, em, i, u, s, small, strike, strong, style, sub, sup
// - Tables: table, tbody, td, tfoot, th, thead, tr
// Blocked HTML elements: These elements and their contents are removed from
// HTML payloads.
// - Document headers: head, title
// - Embeds: audio, embed, object, source, video
// - Frames: frame, frameset
// - Scripting: applet, script
// Other elements: Any elements that aren't listed are removed, but their
// contents are preserved.
@property (copy) NSString *html;

// The ID of the timeline item. This is unique within a user's timeline.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// If this item was generated as a reply to another item, this field will be set
// to the ID of the item being replied to. This can be used to attach a reply to
// the appropriate conversation or post.
@property (copy) NSString *inReplyTo;

// Whether this item is a bundle cover.
// If an item is marked as a bundle cover, it will be the entry point to the
// bundle of items that have the same bundleId as that item. It will be shown
// only on the main timeline — not within the opened bundle.
// On the main timeline, items that are shown are:
// - Items that have isBundleCover set to true
// - Items that do not have a bundleId In a bundle sub-timeline, items that are
// shown are:
// - Items that have the bundleId in question AND isBundleCover set to false
@property (retain) NSNumber *isBundleCover;  // boolValue

// When true, indicates this item is deleted, and only the ID property is set.
@property (retain) NSNumber *isDeleted;  // boolValue

// When true, indicates this item is pinned, which means it's grouped alongside
// "active" items like navigation and hangouts, on the opposite side of the home
// screen from historical (non-pinned) timeline items. You can allow the user to
// toggle the value of this property with the TOGGLE_PINNED built-in menu item.
@property (retain) NSNumber *isPinned;  // boolValue

// The type of resource. This is always mirror#timelineItem.
@property (copy) NSString *kind;

// The geographic location associated with this item.
@property (retain) GTLMirrorLocation *location;

// A list of menu items that will be presented to the user when this item is
// selected in the timeline.
@property (retain) NSArray *menuItems;  // of GTLMirrorMenuItem

// Controls how notifications for this item are presented on the device. If this
// is missing, no notification will be generated.
@property (retain) GTLMirrorNotificationConfig *notification;

// For pinned items, this determines the order in which the item is displayed in
// the timeline, with a higher score appearing closer to the clock. Note:
// setting this field is currently not supported.
@property (retain) NSNumber *pinScore;  // intValue

// A list of users or groups that this item has been shared with.
@property (retain) NSArray *recipients;  // of GTLMirrorContact

// A URL that can be used to retrieve this item.
@property (copy) NSString *selfLink;

// Opaque string you can use to map a timeline item to data in your own service.
@property (copy) NSString *sourceItemId;

// The speakable version of the content of this item. Along with the READ_ALOUD
// menu item, use this field to provide text that would be clearer when read
// aloud, or to provide extended information to what is displayed visually on
// Glass.
// Glassware should also specify the speakableType field, which will be spoken
// before this text in cases where the additional context is useful, for example
// when the user requests that the item be read aloud following a notification.
@property (copy) NSString *speakableText;

// A speakable description of the type of this item. This will be announced to
// the user prior to reading the content of the item in cases where the
// additional context is useful, for example when the user requests that the
// item be read aloud following a notification.
// This should be a short, simple noun phrase such as "Email", "Text message",
// or "Daily Planet News Update".
// Glassware are encouraged to populate this field for every timeline item, even
// if the item does not contain speakableText or text so that the user can learn
// the type of the item without looking at the screen.
@property (copy) NSString *speakableType;

// Text content of this item.
@property (copy) NSString *text;

// The title of this item.
@property (copy) NSString *title;

// The time at which this item was last modified, formatted according to RFC
// 3339.
@property (retain) GTLDateTime *updated;

@end
