/* Copyright (c) 2012 Google Inc.
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
//  GTLGroupssettingsGroups.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Groups Settings API (groupssettings/v1)
// Description:
//   Lets you manage permission levels and related settings of a group.
// Documentation:
//   https://developers.google.com/google-apps/groups-settings/get_started
// Classes:
//   GTLGroupssettingsGroups (0 custom class methods, 24 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLGroupssettingsGroups
//

// JSON template for Group resource

@interface GTLGroupssettingsGroups : GTLObject

// Are external members allowed to join the group.
@property (copy) NSString *allowExternalMembers;

// Is google allowed to contact admins.
@property (copy) NSString *allowGoogleCommunication;

// If posting from web is allowed.
@property (copy) NSString *allowWebPosting;

// If the group is archive only
@property (copy) NSString *archiveOnly;

// Default email to which reply to any message should go.
@property (copy) NSString *customReplyTo;

// Default message deny notification message
@property (copy) NSString *defaultMessageDenyNotificationText;

// Description of the group
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Email id of the group
@property (copy) NSString *email;

// If the contents of the group are archived.
@property (copy) NSString *isArchived;

// The type of the resource.
@property (copy) NSString *kind;

// Maximum message size allowed.
@property (retain) NSNumber *maxMessageBytes;  // intValue

// Can members post using the group email address.
@property (copy) NSString *membersCanPostAsTheGroup;

// Default message display font. Possible values are: DEFAULT_FONT
// FIXED_WIDTH_FONT
@property (copy) NSString *messageDisplayFont;

// Moderation level for messages. Possible values are: MODERATE_ALL_MESSAGES
// MODERATE_NON_MEMBERS MODERATE_NEW_MEMBERS MODERATE_NONE
@property (copy) NSString *messageModerationLevel;

// Name of the Group
@property (copy) NSString *name;

// Primary language for the group.
@property (copy) NSString *primaryLanguage;

// Whome should the default reply to a message go to. Possible values are:
// REPLY_TO_CUSTOM REPLY_TO_SENDER REPLY_TO_LIST REPLY_TO_OWNER REPLY_TO_IGNORE
// REPLY_TO_MANAGERS
@property (copy) NSString *replyTo;

// Should the member be notified if his message is denied by owner.
@property (copy) NSString *sendMessageDenyNotification;

// Is the group listed in groups directory
@property (copy) NSString *showInGroupDirectory;

// Permissions to invite members. Possbile values are: ALL_MEMBERS_CAN_INVITE
// ALL_MANAGERS_CAN_INVITE
@property (copy) NSString *whoCanInvite;

// Permissions to join the group. Possible values are: ANYONE_CAN_JOIN
// ALL_IN_DOMAIN_CAN_JOIN INVITED_CAN_JOIN CAN_REQUEST_TO_JOIN
@property (copy) NSString *whoCanJoin;

// Permissions to post messages to the group. Possible values are: NONE_CAN_POST
// ALL_MANAGERS_CAN_POST ALL_MEMBERS_CAN_POST ALL_IN_DOMAIN_CAN_POST
// ANYONE_CAN_POST
@property (copy) NSString *whoCanPostMessage;

// Permissions to view group. Possbile values are: ANYONE_CAN_VIEW
// ALL_IN_DOMAIN_CAN_VIEW ALL_MEMBERS_CAN_VIEW ALL_MANAGERS_CAN_VIEW
@property (copy) NSString *whoCanViewGroup;

// Permissions to view membership. Possbile values are: ALL_IN_DOMAIN_CAN_VIEW
// ALL_MEMBERS_CAN_VIEW ALL_MANAGERS_CAN_VIEW
@property (copy) NSString *whoCanViewMembership;

@end
