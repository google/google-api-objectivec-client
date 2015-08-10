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
//  GTLCalendarEventAttachment.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Calendar API (calendar/v3)
// Description:
//   Lets you manipulate events and other calendar data.
// Documentation:
//   https://developers.google.com/google-apps/calendar/firstapp
// Classes:
//   GTLCalendarEventAttachment (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLCalendarEventAttachment
//

@interface GTLCalendarEventAttachment : GTLObject

// ID of the attached file. Read-only.
// For Google Drive files, this is the ID of the corresponding Files resource
// entry in the Drive API.
@property (nonatomic, copy) NSString *fileId;

// URL link to the attachment.
// For adding Google Drive file attachments use the same format as in
// alternateLink property of the Files resource in the Drive API.
@property (nonatomic, copy) NSString *fileUrl;

// URL link to the attachment's icon. Read-only.
@property (nonatomic, copy) NSString *iconLink;

// Internet media type (MIME type) of the attachment.
@property (nonatomic, copy) NSString *mimeType;

// Attachment title.
@property (nonatomic, copy) NSString *title;

@end
