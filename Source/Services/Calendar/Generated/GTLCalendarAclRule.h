/* Copyright (c) 2011 Google Inc.
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
//   https://code.google.com/apis/calendar/v3/using.html
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
@property (retain) NSString *ETag;

// Identifier of the ACL rule.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSString *identifier;

// Type of the resource ("calendar#aclRule").
@property (retain) NSString *kind;

// The role assigned to the scope.
@property (retain) NSString *role;

// The scope of the rule.
@property (retain) GTLCalendarAclRuleScope *scope;

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarAclRuleScope
//

@interface GTLCalendarAclRuleScope : GTLObject

// The type of the scope.
@property (retain) NSString *type;

// The email address of a user or group, or the name of a domain, depending on
// the scope type. Omitted for type "default".
@property (retain) NSString *value;

@end
