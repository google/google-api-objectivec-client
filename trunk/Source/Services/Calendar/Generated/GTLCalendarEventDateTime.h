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
//  GTLCalendarEventDateTime.h
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
//   GTLCalendarEventDateTime (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLCalendarEventDateTime
//

@interface GTLCalendarEventDateTime : GTLObject

// The date, in the format "yyyy-mm-dd", if this is an all-day event.
@property (nonatomic, retain) GTLDateTime *date;  // Date only (yyyy-mm-dd)

// The time, as a combined date-time value (formatted according to RFC 3339). A
// time zone offset is required unless a time zone is explicitly specified in
// timeZone.
@property (nonatomic, retain) GTLDateTime *dateTime;

// The time zone in which the time is specified. (Formatted as an IANA Time Zone
// Database name, e.g. "Europe/Zurich".) For recurring events this field is
// required and specifies the time zone in which the recurrence is expanded. For
// single events this field is optional and indicates a custom time zone for the
// event start/end.
@property (nonatomic, copy) NSString *timeZone;

@end
