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
//  GTLCalendarEvents.h
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

// The user's access role for this calendar. Read-only. Possible values are:
// - "none" - The user has no access.
// - "freeBusyReader" - The user has read access to free/busy information.
// - "reader" - The user has read access to the calendar. Private events will
// appear to users with reader access, but event details will be hidden.
// - "writer" - The user has read and write access to the calendar. Private
// events will appear to users with writer access, and event details will be
// visible.
// - "owner" - The user has ownership of the calendar. This role has all of the
// permissions of the writer role with the additional ability to see and
// manipulate ACLs.
@property (copy) NSString *accessRole;

// The default reminders on the calendar for the authenticated user. These
// reminders apply to all events on this calendar that do not explicitly
// override them (i.e. do not have reminders.useDefault set to True).
@property (retain) NSArray *defaultReminders;  // of GTLCalendarEventReminder

// Description of the calendar. Read-only.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// ETag of the collection.
@property (copy) NSString *ETag;

// List of events on the calendar.
@property (retain) NSArray *items;  // of GTLCalendarEvent

// Type of the collection ("calendar#events").
@property (copy) NSString *kind;

// Token used to access the next page of this result. Omitted if no further
// results are available, in which case nextSyncToken is provided.
@property (copy) NSString *nextPageToken;

// Token used at a later point in time to retrieve only the entries that have
// changed since this result was returned. Omitted if further results are
// available, in which case nextPageToken is provided.
@property (copy) NSString *nextSyncToken;

// Title of the calendar. Read-only.
@property (copy) NSString *summary;

// The time zone of the calendar. Read-only.
@property (copy) NSString *timeZone;

// Last modification time of the calendar (as a RFC 3339 timestamp). Read-only.
@property (retain) GTLDateTime *updated;

@end
