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
//  GTLGmailConstants.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Gmail API (gmail/v1)
// Description:
//   The Gmail REST API.
// Documentation:
//   https://developers.google.com/gmail/api/

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// View and manage your mail
GTL_EXTERN NSString * const kGTLAuthScopeGmail;          // "https://mail.google.com/"
// Manage drafts and send emails
GTL_EXTERN NSString * const kGTLAuthScopeGmailCompose;   // "https://www.googleapis.com/auth/gmail.compose"
// Insert mail into your mailbox
GTL_EXTERN NSString * const kGTLAuthScopeGmailInsert;    // "https://www.googleapis.com/auth/gmail.insert"
// Manage mailbox labels
GTL_EXTERN NSString * const kGTLAuthScopeGmailLabels;    // "https://www.googleapis.com/auth/gmail.labels"
// View and modify but not delete your email
GTL_EXTERN NSString * const kGTLAuthScopeGmailModify;    // "https://www.googleapis.com/auth/gmail.modify"
// View your emails messages and settings
GTL_EXTERN NSString * const kGTLAuthScopeGmailReadonly;  // "https://www.googleapis.com/auth/gmail.readonly"

// GTLGmailLabel - LabelListVisibility
GTL_EXTERN NSString * const kGTLGmailLabel_LabelListVisibility_LabelHide;  // "labelHide"
GTL_EXTERN NSString * const kGTLGmailLabel_LabelListVisibility_LabelShow;  // "labelShow"
GTL_EXTERN NSString * const kGTLGmailLabel_LabelListVisibility_LabelShowIfUnread;  // "labelShowIfUnread"

// GTLGmailLabel - MessageListVisibility
GTL_EXTERN NSString * const kGTLGmailLabel_MessageListVisibility_Hide;  // "hide"
GTL_EXTERN NSString * const kGTLGmailLabel_MessageListVisibility_Show;  // "show"

// GTLGmailLabel - Type
GTL_EXTERN NSString * const kGTLGmailLabel_Type_System;  // "system"
GTL_EXTERN NSString * const kGTLGmailLabel_Type_User;    // "user"

// GTLQueryGmail - Format
GTL_EXTERN NSString * const kGTLGmailFormatFull;      // "full"
GTL_EXTERN NSString * const kGTLGmailFormatMetadata;  // "metadata"
GTL_EXTERN NSString * const kGTLGmailFormatMinimal;   // "minimal"
GTL_EXTERN NSString * const kGTLGmailFormatRaw;       // "raw"

// GTLQueryGmail - InternalDateSource
GTL_EXTERN NSString * const kGTLGmailInternalDateSourceDateHeader;  // "dateHeader"
GTL_EXTERN NSString * const kGTLGmailInternalDateSourceReceivedTime;  // "receivedTime"

// GTLQueryGmail - LabelFilterAction
GTL_EXTERN NSString * const kGTLGmailLabelFilterActionExclude;  // "exclude"
GTL_EXTERN NSString * const kGTLGmailLabelFilterActionInclude;  // "include"
