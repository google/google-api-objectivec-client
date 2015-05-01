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
//  GTLGmailLabel.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Gmail API (gmail/v1)
// Description:
//   The Gmail REST API.
// Documentation:
//   https://developers.google.com/gmail/api/
// Classes:
//   GTLGmailLabel (0 custom class methods, 9 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLGmailLabel
//

// Labels are used to categorize messages and threads within the user's mailbox.

@interface GTLGmailLabel : GTLObject

// The immutable ID of the label.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The visibility of the label in the label list in the Gmail web interface.
@property (nonatomic, copy) NSString *labelListVisibility;

// The visibility of the label in the message list in the Gmail web interface.
@property (nonatomic, copy) NSString *messageListVisibility;

// The total number of messages with the label.
@property (nonatomic, retain) NSNumber *messagesTotal;  // intValue

// The number of unread messages with the label.
@property (nonatomic, retain) NSNumber *messagesUnread;  // intValue

// The display name of the label.
@property (nonatomic, copy) NSString *name;

// The total number of threads with the label.
@property (nonatomic, retain) NSNumber *threadsTotal;  // intValue

// The number of unread threads with the label.
@property (nonatomic, retain) NSNumber *threadsUnread;  // intValue

// The owner type for the label. User labels are created by the user and can be
// modified and deleted by the user and can be applied to any message or thread.
// System labels are internally created and cannot be added, modified, or
// deleted. System labels may be able to be applied to or removed from messages
// and threads under some circumstances but this is not guaranteed. For example,
// users can apply and remove the INBOX and UNREAD labels from messages and
// threads, but cannot apply or remove the DRAFTS or SENT labels from messages
// or threads.
@property (nonatomic, copy) NSString *type;

@end
