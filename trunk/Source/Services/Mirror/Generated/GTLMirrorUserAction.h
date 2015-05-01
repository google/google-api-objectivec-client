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
//  GTLMirrorUserAction.h
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
//   GTLMirrorUserAction (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLMirrorUserAction
//

// Represents an action taken by the user that triggered a notification.

@interface GTLMirrorUserAction : GTLObject

// An optional payload for the action.
// For actions of type CUSTOM, this is the ID of the custom menu item that was
// selected.
@property (nonatomic, copy) NSString *payload;

// The type of action. The value of this can be:
// - SHARE - the user shared an item.
// - REPLY - the user replied to an item.
// - REPLY_ALL - the user replied to all recipients of an item.
// - CUSTOM - the user selected a custom menu item on the timeline item.
// - DELETE - the user deleted the item.
// - PIN - the user pinned the item.
// - UNPIN - the user unpinned the item.
// - LAUNCH - the user initiated a voice command. In the future, additional
// types may be added. UserActions with unrecognized types should be ignored.
@property (nonatomic, copy) NSString *type;

@end
