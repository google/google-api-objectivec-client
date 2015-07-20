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
//  GTLGmailMessage.h
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
//   GTLGmailMessage (0 custom class methods, 9 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLGmailMessagePart;

// ----------------------------------------------------------------------------
//
//   GTLGmailMessage
//

// An email message.

@interface GTLGmailMessage : GTLObject

// The ID of the last history record that modified this message.
@property (nonatomic, retain) NSNumber *historyId;  // unsignedLongLongValue

// The immutable ID of the message.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The internal message creation timestamp (epoch ms), which determines ordering
// in the inbox. For normal SMTP-received email, this represents the time the
// message was originally accepted by Google, which is more reliable than the
// Date header. However, for API-migrated mail, it can be configured by client
// to be based on the Date header.
@property (nonatomic, retain) NSNumber *internalDate;  // longLongValue

// List of IDs of labels applied to this message.
@property (nonatomic, retain) NSArray *labelIds;  // of NSString

// The parsed email structure in the message parts.
@property (nonatomic, retain) GTLGmailMessagePart *payload;

// The entire email message in an RFC 2822 formatted and base64url encoded
// string. Returned in messages.get and drafts.get responses when the format=RAW
// parameter is supplied.
@property (nonatomic, copy) NSString *raw;  // GTLBase64 can encode/decode (probably web-safe format)

// Estimated size in bytes of the message.
@property (nonatomic, retain) NSNumber *sizeEstimate;  // intValue

// A short part of the message text.
@property (nonatomic, copy) NSString *snippet;

// The ID of the thread the message belongs to. To add a message or draft to a
// thread, the following criteria must be met:
// - The requested threadId must be specified on the Message or Draft.Message
// you supply with your request.
// - The References and In-Reply-To headers must be set in compliance with the
// RFC 2822 standard.
// - The Subject headers must match.
@property (nonatomic, copy) NSString *threadId;

@end
