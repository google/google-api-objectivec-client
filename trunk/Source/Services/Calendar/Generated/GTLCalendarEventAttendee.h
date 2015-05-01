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
//  GTLCalendarEventAttendee.h
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
//   GTLCalendarEventAttendee (0 custom class methods, 10 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLCalendarEventAttendee
//

@interface GTLCalendarEventAttendee : GTLObject

// Number of additional guests. Optional. The default is 0.
@property (nonatomic, retain) NSNumber *additionalGuests;  // intValue

// The attendee's response comment. Optional.
@property (nonatomic, copy) NSString *comment;

// The attendee's name, if available. Optional.
@property (nonatomic, copy) NSString *displayName;

// The attendee's email address, if available. This field must be present when
// adding an attendee.
@property (nonatomic, copy) NSString *email;

// The attendee's Profile ID, if available.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Whether this is an optional attendee. Optional. The default is False.
@property (nonatomic, retain) NSNumber *optional;  // boolValue

// Whether the attendee is the organizer of the event. Read-only. The default is
// False.
@property (nonatomic, retain) NSNumber *organizer;  // boolValue

// Whether the attendee is a resource. Read-only. The default is False.
@property (nonatomic, retain) NSNumber *resource;  // boolValue

// The attendee's response status. Possible values are:
// - "needsAction" - The attendee has not responded to the invitation.
// - "declined" - The attendee has declined the invitation.
// - "tentative" - The attendee has tentatively accepted the invitation.
// - "accepted" - The attendee has accepted the invitation.
@property (nonatomic, copy) NSString *responseStatus;

// Whether this entry represents the calendar on which this copy of the event
// appears. Read-only. The default is False.
// Remapped to 'selfProperty' to avoid language reserved word 'self'.
@property (nonatomic, retain) NSNumber *selfProperty;  // boolValue

@end
