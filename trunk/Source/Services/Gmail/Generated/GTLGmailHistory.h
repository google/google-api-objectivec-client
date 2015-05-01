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
//  GTLGmailHistory.h
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
//   GTLGmailHistory (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLGmailHistoryLabelAdded;
@class GTLGmailHistoryLabelRemoved;
@class GTLGmailHistoryMessageAdded;
@class GTLGmailHistoryMessageDeleted;
@class GTLGmailMessage;

// ----------------------------------------------------------------------------
//
//   GTLGmailHistory
//

// A record of a change to the user's mailbox. Each history change may affect
// multiple messages in multiple ways.

@interface GTLGmailHistory : GTLObject

// The mailbox sequence ID.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, retain) NSNumber *identifier;  // unsignedLongLongValue

// Labels added to messages in this history record.
@property (nonatomic, retain) NSArray *labelsAdded;  // of GTLGmailHistoryLabelAdded

// Labels removed from messages in this history record.
@property (nonatomic, retain) NSArray *labelsRemoved;  // of GTLGmailHistoryLabelRemoved

// List of messages changed in this history record. The fields for specific
// change types, such as messagesAdded may duplicate messages in this field. We
// recommend using the specific change-type fields instead of this.
@property (nonatomic, retain) NSArray *messages;  // of GTLGmailMessage

// Messages added to the mailbox in this history record.
@property (nonatomic, retain) NSArray *messagesAdded;  // of GTLGmailHistoryMessageAdded

// Messages deleted (not Trashed) from the mailbox in this history record.
@property (nonatomic, retain) NSArray *messagesDeleted;  // of GTLGmailHistoryMessageDeleted

@end
