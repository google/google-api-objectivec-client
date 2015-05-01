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
//  GTLMirrorNotification.h
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
//   GTLMirrorNotification (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLMirrorUserAction;

// ----------------------------------------------------------------------------
//
//   GTLMirrorNotification
//

// A notification delivered by the API.

@interface GTLMirrorNotification : GTLObject

// The collection that generated the notification.
@property (nonatomic, copy) NSString *collection;

// The ID of the item that generated the notification.
@property (nonatomic, copy) NSString *itemId;

// The type of operation that generated the notification.
@property (nonatomic, copy) NSString *operation;

// A list of actions taken by the user that triggered the notification.
@property (nonatomic, retain) NSArray *userActions;  // of GTLMirrorUserAction

// The user token provided by the service when it subscribed for notifications.
@property (nonatomic, copy) NSString *userToken;

// The secret verify token provided by the service when it subscribed for
// notifications.
@property (nonatomic, copy) NSString *verifyToken;

@end
