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
//  GTLCalendarFreeBusyResponse.h
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
//   GTLCalendarFreeBusyResponse (0 custom class methods, 5 custom properties)
//   GTLCalendarFreeBusyResponseCalendars (0 custom class methods, 0 custom properties)
//   GTLCalendarFreeBusyResponseGroups (0 custom class methods, 0 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCalendarFreeBusyCalendar;
@class GTLCalendarFreeBusyGroup;
@class GTLCalendarFreeBusyResponseCalendars;
@class GTLCalendarFreeBusyResponseGroups;

// ----------------------------------------------------------------------------
//
//   GTLCalendarFreeBusyResponse
//

@interface GTLCalendarFreeBusyResponse : GTLObject

// List of free/busy information for calendars.
@property (nonatomic, retain) GTLCalendarFreeBusyResponseCalendars *calendars;

// Expansion of groups.
@property (nonatomic, retain) GTLCalendarFreeBusyResponseGroups *groups;

// Type of the resource ("calendar#freeBusy").
@property (nonatomic, copy) NSString *kind;

// The end of the interval.
@property (nonatomic, retain) GTLDateTime *timeMax;

// The start of the interval.
@property (nonatomic, retain) GTLDateTime *timeMin;

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarFreeBusyResponseCalendars
//

@interface GTLCalendarFreeBusyResponseCalendars : GTLObject
// This object is documented as having more properties that are
// GTLCalendarFreeBusyCalendar. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarFreeBusyResponseGroups
//

@interface GTLCalendarFreeBusyResponseGroups : GTLObject
// This object is documented as having more properties that are
// GTLCalendarFreeBusyGroup. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end
