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
//  GTLCalendarEvents.h
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
//   GTLCalendarEvents (0 custom class methods, 11 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCalendarEvent;
@class GTLCalendarEventReminder;

// ----------------------------------------------------------------------------
//
//   GTLCalendarEvents
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLCalendarEvents : GTLCollectionObject

// The user's access role for this calendar. Read-only.
@property (retain) NSString *accessRole;

// The default reminders on the calendar for the authenticated user. These
// reminders apply to all events on this calendar that do not explicitly
// override them (i.e. do not have 'reminders.useDefault' set to 'true').
@property (retain) NSArray *defaultReminders;  // of GTLCalendarEventReminder

// Description of the calendar. Read-only.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (retain) NSString *descriptionProperty;

// ETag of the collection.
@property (retain) NSString *ETag;

// Identifier of the calendar.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSString *identifier;

// List of events on the calendar.
@property (retain) NSArray *items;  // of GTLCalendarEvent

// Type of the collection ("calendar#events").
@property (retain) NSString *kind;

// Token used to access the next page of this result. Omitted if no further
// results are available.
@property (retain) NSString *nextPageToken;

// Title of the calendar. Read-only.
@property (retain) NSString *summary;

// The time zone of the calendar. Read-only.
@property (retain) NSString *timeZone;

// Last modification time of the calendar (as a RFC 3339 timestamp). Read-only.
@property (retain) GTLDateTime *updated;

@end
