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
//  GTLCalendarColors.h
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
//   GTLCalendarColors (0 custom class methods, 4 custom properties)
//   GTLCalendarColorsCalendar (0 custom class methods, 0 custom properties)
//   GTLCalendarColorsEvent (0 custom class methods, 0 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCalendarColorDefinition;
@class GTLCalendarColorsCalendar;
@class GTLCalendarColorsEvent;

// ----------------------------------------------------------------------------
//
//   GTLCalendarColors
//

@interface GTLCalendarColors : GTLObject

// Palette of calendar colors, mapping from the color ID to its definition. A
// calendarListEntry resource refers to one of these color IDs in its color
// field. Read-only.
@property (nonatomic, retain) GTLCalendarColorsCalendar *calendar;

// Palette of event colors, mapping from the color ID to its definition. An
// event resource may refer to one of these color IDs in its color field.
// Read-only.
@property (nonatomic, retain) GTLCalendarColorsEvent *event;

// Type of the resource ("calendar#colors").
@property (nonatomic, copy) NSString *kind;

// Last modification time of the color palette (as a RFC 3339 timestamp).
// Read-only.
@property (nonatomic, retain) GTLDateTime *updated;

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarColorsCalendar
//

@interface GTLCalendarColorsCalendar : GTLObject
// This object is documented as having more properties that are
// GTLCalendarColorDefinition. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarColorsEvent
//

@interface GTLCalendarColorsEvent : GTLObject
// This object is documented as having more properties that are
// GTLCalendarColorDefinition. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end
