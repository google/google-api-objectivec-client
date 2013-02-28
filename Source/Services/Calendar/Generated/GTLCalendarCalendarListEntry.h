/* Copyright (c) 2013 Google Inc.
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
//  GTLCalendarCalendarListEntry.h
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
//   GTLCalendarCalendarListEntry (0 custom class methods, 16 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCalendarEventReminder;

// ----------------------------------------------------------------------------
//
//   GTLCalendarCalendarListEntry
//

@interface GTLCalendarCalendarListEntry : GTLObject

// The effective access role that the authenticated user has on the calendar.
// Read-only. Possible values are:
// - "freeBusyReader" - Provides read access to free/busy information.
// - "reader" - Provides read access to the calendar. Private events will appear
// to users with reader access, but event details will be hidden.
// - "writer" - Provides read and write access to the calendar. Private events
// will appear to users with writer access, and event details will be visible.
// - "owner" - Provides ownership of the calendar. This role has all of the
// permissions of the writer role with the additional ability to see and
// manipulate ACLs.
@property (copy) NSString *accessRole;

// The main color of the calendar in the format '#0088aa'. This property
// supersedes the index-based colorId property. Optional.
@property (copy) NSString *backgroundColor;

// The color of the calendar. This is an ID referring to an entry in the
// "calendar" section of the colors definition (see the "colors" endpoint).
// Optional.
@property (copy) NSString *colorId;

// The default reminders that the authenticated user has for this calendar.
@property (retain) NSArray *defaultReminders;  // of GTLCalendarEventReminder

// Description of the calendar. Optional. Read-only.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// ETag of the resource.
@property (copy) NSString *ETag;

// The foreground color of the calendar in the format '#ffffff'. This property
// supersedes the index-based colorId property. Optional.
@property (copy) NSString *foregroundColor;

// Whether the calendar has been hidden from the list. Optional. The default is
// False.
@property (retain) NSNumber *hidden;  // boolValue

// Identifier of the calendar.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Type of the resource ("calendar#calendarListEntry").
@property (copy) NSString *kind;

// Geographic location of the calendar as free-form text. Optional. Read-only.
@property (copy) NSString *location;

// Whether the calendar is the primary calendar of the authenticated user.
// Read-only. Optional. The default is False.
@property (retain) NSNumber *primary;  // boolValue

// Whether the calendar content shows up in the calendar UI. Optional. The
// default is False.
@property (retain) NSNumber *selected;  // boolValue

// Title of the calendar. Read-only.
@property (copy) NSString *summary;

// The summary that the authenticated user has set for this calendar. Optional.
@property (copy) NSString *summaryOverride;

// The time zone of the calendar. Optional. Read-only.
@property (copy) NSString *timeZone;

@end
