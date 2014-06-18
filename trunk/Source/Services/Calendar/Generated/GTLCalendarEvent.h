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
//  GTLCalendarEvent.h
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
//   GTLCalendarEvent (0 custom class methods, 36 custom properties)
//   GTLCalendarEventCreator (0 custom class methods, 4 custom properties)
//   GTLCalendarEventExtendedProperties (0 custom class methods, 2 custom properties)
//   GTLCalendarEventGadget (0 custom class methods, 8 custom properties)
//   GTLCalendarEventOrganizer (0 custom class methods, 4 custom properties)
//   GTLCalendarEventReminders (0 custom class methods, 2 custom properties)
//   GTLCalendarEventSource (0 custom class methods, 2 custom properties)
//   GTLCalendarEventExtendedPropertiesPrivate (0 custom class methods, 0 custom properties)
//   GTLCalendarEventExtendedPropertiesShared (0 custom class methods, 0 custom properties)
//   GTLCalendarEventGadgetPreferences (0 custom class methods, 0 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCalendarEventAttendee;
@class GTLCalendarEventCreator;
@class GTLCalendarEventDateTime;
@class GTLCalendarEventExtendedProperties;
@class GTLCalendarEventExtendedPropertiesPrivate;
@class GTLCalendarEventExtendedPropertiesShared;
@class GTLCalendarEventGadget;
@class GTLCalendarEventGadgetPreferences;
@class GTLCalendarEventOrganizer;
@class GTLCalendarEventReminder;
@class GTLCalendarEventReminders;
@class GTLCalendarEventSource;

// ----------------------------------------------------------------------------
//
//   GTLCalendarEvent
//

@interface GTLCalendarEvent : GTLObject

// Whether anyone can invite themselves to the event. Optional. The default is
// False.
@property (retain) NSNumber *anyoneCanAddSelf;  // boolValue

// The attendees of the event.
@property (retain) NSArray *attendees;  // of GTLCalendarEventAttendee

// Whether attendees may have been omitted from the event's representation. When
// retrieving an event, this may be due to a restriction specified by the
// maxAttendee query parameter. When updating an event, this can be used to only
// update the participant's response. Optional. The default is False.
@property (retain) NSNumber *attendeesOmitted;  // boolValue

// The color of the event. This is an ID referring to an entry in the event
// section of the colors definition (see the colors endpoint). Optional.
@property (copy) NSString *colorId;

// Creation time of the event (as a RFC 3339 timestamp). Read-only.
@property (retain) GTLDateTime *created;

// The creator of the event. Read-only.
@property (retain) GTLCalendarEventCreator *creator;

// Description of the event. Optional.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// The (exclusive) end time of the event. For a recurring event, this is the end
// time of the first instance.
@property (retain) GTLCalendarEventDateTime *end;

// Whether the end time is actually unspecified. An end time is still provided
// for compatibility reasons, even if this attribute is set to True. The default
// is False.
@property (retain) NSNumber *endTimeUnspecified;  // boolValue

// ETag of the resource.
@property (copy) NSString *ETag;

// Extended properties of the event.
@property (retain) GTLCalendarEventExtendedProperties *extendedProperties;

// A gadget that extends this event.
@property (retain) GTLCalendarEventGadget *gadget;

// Whether attendees other than the organizer can invite others to the event.
// Optional. The default is True.
@property (retain) NSNumber *guestsCanInviteOthers;  // boolValue

// Whether attendees other than the organizer can modify the event. Optional.
// The default is False.
@property (retain) NSNumber *guestsCanModify;  // boolValue

// Whether attendees other than the organizer can see who the event's attendees
// are. Optional. The default is True.
@property (retain) NSNumber *guestsCanSeeOtherGuests;  // boolValue

// An absolute link to the Google+ hangout associated with this event.
// Read-only.
@property (copy) NSString *hangoutLink;

// An absolute link to this event in the Google Calendar Web UI. Read-only.
@property (copy) NSString *htmlLink;

// Event ID in the iCalendar format.
@property (copy) NSString *iCalUID;

// Identifier of the event. When creating new single or recurring events, you
// can specify their IDs. Provided IDs must follow these rules:
// - characters allowed in the ID are those used in base32hex encoding, i.e.
// lowercase letters a-v and digits 0-9, see section 3.1.2 in RFC2938
// - the length of the ID must be between 5 and 1024 characters
// - the ID must be unique per calendar Due to the globally distributed nature
// of the system, we cannot guarantee that ID collisions will be detected at
// event creation time. To minimize the risk of collisions we recommend using an
// established UUID algorithm such as one described in RFC4122.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Type of the resource ("calendar#event").
@property (copy) NSString *kind;

// Geographic location of the event as free-form text. Optional.
@property (copy) NSString *location;

// Whether this is a locked event copy where no changes can be made to the main
// event fields "summary", "description", "location", "start", "end" or
// "recurrence". The default is False. Read-Only.
@property (retain) NSNumber *locked;  // boolValue

// The organizer of the event. If the organizer is also an attendee, this is
// indicated with a separate entry in attendees with the organizer field set to
// True. To change the organizer, use the move operation. Read-only, except when
// importing an event.
@property (retain) GTLCalendarEventOrganizer *organizer;

// For an instance of a recurring event, this is the time at which this event
// would start according to the recurrence data in the recurring event
// identified by recurringEventId. Immutable.
@property (retain) GTLCalendarEventDateTime *originalStartTime;

// Whether this is a private event copy where changes are not shared with other
// copies on other calendars. Optional. Immutable. The default is False.
@property (retain) NSNumber *privateCopy;  // boolValue

// List of RRULE, EXRULE, RDATE and EXDATE lines for a recurring event. This
// field is omitted for single events or instances of recurring events.
@property (retain) NSArray *recurrence;  // of NSString

// For an instance of a recurring event, this is the event ID of the recurring
// event itself. Immutable.
@property (copy) NSString *recurringEventId;

// Information about the event's reminders for the authenticated user.
@property (retain) GTLCalendarEventReminders *reminders;

// Sequence number as per iCalendar.
@property (retain) NSNumber *sequence;  // intValue

// Source of an event from which it was created; for example a web page, an
// email message or any document identifiable by an URL using HTTP/HTTPS
// protocol. Accessible only by the creator of the event.
@property (retain) GTLCalendarEventSource *source;

// The (inclusive) start time of the event. For a recurring event, this is the
// start time of the first instance.
@property (retain) GTLCalendarEventDateTime *start;

// Status of the event. Optional. Possible values are:
// - "confirmed" - The event is confirmed. This is the default status.
// - "tentative" - The event is tentatively confirmed.
// - "cancelled" - The event is cancelled.
@property (copy) NSString *status;

// Title of the event.
@property (copy) NSString *summary;

// Whether the event blocks time on the calendar. Optional. Possible values are:
// - "opaque" - The event blocks time on the calendar. This is the default
// value.
// - "transparent" - The event does not block time on the calendar.
@property (copy) NSString *transparency;

// Last modification time of the event (as a RFC 3339 timestamp). Read-only.
@property (retain) GTLDateTime *updated;

// Visibility of the event. Optional. Possible values are:
// - "default" - Uses the default visibility for events on the calendar. This is
// the default value.
// - "public" - The event is public and event details are visible to all readers
// of the calendar.
// - "private" - The event is private and only event attendees may view event
// details.
// - "confidential" - The event is private. This value is provided for
// compatibility reasons.
@property (copy) NSString *visibility;

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventCreator
//

@interface GTLCalendarEventCreator : GTLObject

// The creator's name, if available.
@property (copy) NSString *displayName;

// The creator's email address, if available.
@property (copy) NSString *email;

// The creator's Profile ID, if available.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Whether the creator corresponds to the calendar on which this copy of the
// event appears. Read-only. The default is False.
// Remapped to 'selfProperty' to avoid language reserved word 'self'.
@property (retain) NSNumber *selfProperty;  // boolValue

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventExtendedProperties
//

@interface GTLCalendarEventExtendedProperties : GTLObject

// Properties that are private to the copy of the event that appears on this
// calendar.
// Remapped to 'privateProperty' to avoid language reserved word 'private'.
@property (retain) GTLCalendarEventExtendedPropertiesPrivate *privateProperty;

// Properties that are shared between copies of the event on other attendees'
// calendars.
@property (retain) GTLCalendarEventExtendedPropertiesShared *shared;

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventGadget
//

@interface GTLCalendarEventGadget : GTLObject

// The gadget's display mode. Optional. Possible values are:
// - "icon" - The gadget displays next to the event's title in the calendar
// view.
// - "chip" - The gadget displays when the event is clicked.
@property (copy) NSString *display;

// The gadget's height in pixels. Optional.
@property (retain) NSNumber *height;  // intValue

// The gadget's icon URL.
@property (copy) NSString *iconLink;

// The gadget's URL.
@property (copy) NSString *link;

// Preferences.
@property (retain) GTLCalendarEventGadgetPreferences *preferences;

// The gadget's title.
@property (copy) NSString *title;

// The gadget's type.
@property (copy) NSString *type;

// The gadget's width in pixels. Optional.
@property (retain) NSNumber *width;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventOrganizer
//

@interface GTLCalendarEventOrganizer : GTLObject

// The organizer's name, if available.
@property (copy) NSString *displayName;

// The organizer's email address, if available.
@property (copy) NSString *email;

// The organizer's Profile ID, if available.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Whether the organizer corresponds to the calendar on which this copy of the
// event appears. Read-only. The default is False.
// Remapped to 'selfProperty' to avoid language reserved word 'self'.
@property (retain) NSNumber *selfProperty;  // boolValue

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventReminders
//

@interface GTLCalendarEventReminders : GTLObject

// If the event doesn't use the default reminders, this lists the reminders
// specific to the event, or, if not set, indicates that no reminders are set
// for this event.
@property (retain) NSArray *overrides;  // of GTLCalendarEventReminder

// Whether the default reminders of the calendar apply to the event.
@property (retain) NSNumber *useDefault;  // boolValue

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventSource
//

@interface GTLCalendarEventSource : GTLObject

// Title of the source; for example a title of a web page or an email subject.
@property (copy) NSString *title;

// URL of the source pointing to a resource. URL's protocol must be HTTP or
// HTTPS.
@property (copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventExtendedPropertiesPrivate
//

@interface GTLCalendarEventExtendedPropertiesPrivate : GTLObject
// This object is documented as having more properties that are NSString. Use
// -additionalJSONKeys and -additionalPropertyForName: to get the list of
// properties and then fetch them; or -additionalProperties to fetch them all at
// once.
@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventExtendedPropertiesShared
//

@interface GTLCalendarEventExtendedPropertiesShared : GTLObject
// This object is documented as having more properties that are NSString. Use
// -additionalJSONKeys and -additionalPropertyForName: to get the list of
// properties and then fetch them; or -additionalProperties to fetch them all at
// once.
@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventGadgetPreferences
//

@interface GTLCalendarEventGadgetPreferences : GTLObject
// This object is documented as having more properties that are NSString. Use
// -additionalJSONKeys and -additionalPropertyForName: to get the list of
// properties and then fetch them; or -additionalProperties to fetch them all at
// once.
@end
