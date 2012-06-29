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
//  GTLCalendarEvent.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Calendar API (calendar/v3)
// Description:
//   Lets you manipulate events and other calendar data.
// Documentation:
//   http://code.google.com/apis/calendar/v3/using.html
// Classes:
//   GTLCalendarEvent (0 custom class methods, 34 custom properties)
//   GTLCalendarEventCreator (0 custom class methods, 4 custom properties)
//   GTLCalendarEventExtendedProperties (0 custom class methods, 2 custom properties)
//   GTLCalendarEventGadget (0 custom class methods, 8 custom properties)
//   GTLCalendarEventOrganizer (0 custom class methods, 4 custom properties)
//   GTLCalendarEventReminders (0 custom class methods, 2 custom properties)
//   GTLCalendarEventExtendedPropertiesPrivate (0 custom class methods, 0 custom properties)
//   GTLCalendarEventExtendedPropertiesShared (0 custom class methods, 0 custom properties)
//   GTLCalendarEventGadgetPreferences (0 custom class methods, 0 custom properties)

#import "GTLCalendarEvent.h"

#import "GTLCalendarEventAttendee.h"
#import "GTLCalendarEventDateTime.h"
#import "GTLCalendarEventReminder.h"

// ----------------------------------------------------------------------------
//
//   GTLCalendarEvent
//

@implementation GTLCalendarEvent
@dynamic anyoneCanAddSelf, attendees, attendeesOmitted, colorId, created,
         creator, descriptionProperty, end, endTimeUnspecified, ETag,
         extendedProperties, gadget, guestsCanInviteOthers, guestsCanModify,
         guestsCanSeeOtherGuests, htmlLink, iCalUID, identifier, kind, location,
         locked, organizer, originalStartTime, privateCopy, recurrence,
         recurringEventId, reminders, sequence, start, status, summary,
         transparency, updated, visibility;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"description", @"descriptionProperty",
      @"etag", @"ETag",
      @"id", @"identifier",
      nil];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLCalendarEventAttendee class], @"attendees",
      [NSString class], @"recurrence",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"calendar#event"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventCreator
//

@implementation GTLCalendarEventCreator
@dynamic displayName, email, identifier, selfProperty;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"id", @"identifier",
      @"self", @"selfProperty",
      nil];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventExtendedProperties
//

@implementation GTLCalendarEventExtendedProperties
@dynamic privateProperty, shared;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"private"
                                forKey:@"privateProperty"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventGadget
//

@implementation GTLCalendarEventGadget
@dynamic display, height, iconLink, link, preferences, title, type, width;
@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventOrganizer
//

@implementation GTLCalendarEventOrganizer
@dynamic displayName, email, identifier, selfProperty;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"id", @"identifier",
      @"self", @"selfProperty",
      nil];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventReminders
//

@implementation GTLCalendarEventReminders
@dynamic overrides, useDefault;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLCalendarEventReminder class]
                                forKey:@"overrides"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventExtendedPropertiesPrivate
//

@implementation GTLCalendarEventExtendedPropertiesPrivate

+ (Class)classForAdditionalProperties {
  return [NSString class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventExtendedPropertiesShared
//

@implementation GTLCalendarEventExtendedPropertiesShared

+ (Class)classForAdditionalProperties {
  return [NSString class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarEventGadgetPreferences
//

@implementation GTLCalendarEventGadgetPreferences

+ (Class)classForAdditionalProperties {
  return [NSString class];
}

@end
