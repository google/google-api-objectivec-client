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
//  GTLCalendarConstants.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Calendar API (calendar/v3)
// Description:
//   Lets you manipulate events and other calendar data.
// Documentation:
//   https://developers.google.com/google-apps/calendar/firstapp

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// Manage your calendars
GTL_EXTERN NSString * const kGTLAuthScopeCalendar;          // "https://www.googleapis.com/auth/calendar"
// View your calendars
GTL_EXTERN NSString * const kGTLAuthScopeCalendarReadonly;  // "https://www.googleapis.com/auth/calendar.readonly"

// GTLQueryCalendar - MinAccessRole
GTL_EXTERN NSString * const kGTLCalendarMinAccessRoleFreeBusyReader;  // "freeBusyReader"
GTL_EXTERN NSString * const kGTLCalendarMinAccessRoleOwner;     // "owner"
GTL_EXTERN NSString * const kGTLCalendarMinAccessRoleReader;    // "reader"
GTL_EXTERN NSString * const kGTLCalendarMinAccessRoleWriter;    // "writer"

// GTLQueryCalendar - OrderBy
GTL_EXTERN NSString * const kGTLCalendarOrderByStartTime;  // "startTime"
GTL_EXTERN NSString * const kGTLCalendarOrderByUpdated;    // "updated"
