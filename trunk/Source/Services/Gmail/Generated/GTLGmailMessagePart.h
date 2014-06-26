/* Copyright (c) 2014 Google Inc.
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
//  GTLGmailMessagePart.h
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
//   GTLGmailMessagePart (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLGmailMessagePart;
@class GTLGmailMessagePartBody;
@class GTLGmailMessagePartHeader;

// ----------------------------------------------------------------------------
//
//   GTLGmailMessagePart
//

// A single MIME message part.

@interface GTLGmailMessagePart : GTLObject

// The message part body for this part, which may be empty for container MIME
// message parts.
@property (retain) GTLGmailMessagePartBody *body;

// The filename of the attachment. Only present if this message part represents
// an attachment.
@property (copy) NSString *filename;

// List of headers on this message part. For the top-level message part,
// representing the entire message payload, it will contain the standard RFC
// 2822 email headers such as To, From, and Subject.
@property (retain) NSArray *headers;  // of GTLGmailMessagePartHeader

// The MIME type of the message part.
@property (copy) NSString *mimeType;

// The immutable ID of the message part.
@property (copy) NSString *partId;

// The child MIME message parts of this part. This only applies to container
// MIME message parts, for example multipart/*. For non- container MIME message
// part types, such as text/plain, this field is empty. For more information,
// see RFC 1521.
@property (retain) NSArray *parts;  // of GTLGmailMessagePart

@end
