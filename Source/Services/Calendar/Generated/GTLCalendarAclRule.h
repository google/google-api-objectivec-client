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
//  GTLCalendarAclRule.h
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
//   GTLCalendarAclRule (0 custom class methods, 5 custom properties)
//   GTLCalendarAclRuleScope (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCalendarAclRuleScope;

// ----------------------------------------------------------------------------
//
//   GTLCalendarAclRule
//

@interface GTLCalendarAclRule : GTLObject

// ETag of the resource.
@property (nonatomic, copy) NSString *ETag;

// Identifier of the ACL rule.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Type of the resource ("calendar#aclRule").
@property (nonatomic, copy) NSString *kind;

// The role assigned to the scope. Possible values are:
// - "none" - Provides no access.
// - "freeBusyReader" - Provides read access to free/busy information.
// - "reader" - Provides read access to the calendar. Private events will appear
// to users with reader access, but event details will be hidden.
// - "writer" - Provides read and write access to the calendar. Private events
// will appear to users with writer access, and event details will be visible.
// - "owner" - Provides ownership of the calendar. This role has all of the
// permissions of the writer role with the additional ability to see and
// manipulate ACLs.
@property (nonatomic, copy) NSString *role;

// The scope of the rule.
@property (nonatomic, retain) GTLCalendarAclRuleScope *scope;

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarAclRuleScope
//

@interface GTLCalendarAclRuleScope : GTLObject

// The type of the scope. Possible values are:
// - "default" - The public scope. This is the default value.
// - "user" - Limits the scope to a single user.
// - "group" - Limits the scope to a group.
// - "domain" - Limits the scope to a domain. Note: The permissions granted to
// the "default", or public, scope apply to any user, authenticated or not.
@property (nonatomic, copy) NSString *type;

// The email address of a user or group, or the name of a domain, depending on
// the scope type. Omitted for type "default".
@property (nonatomic, copy) NSString *value;

@end
