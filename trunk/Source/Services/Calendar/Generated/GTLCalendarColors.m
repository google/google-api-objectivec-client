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
//  GTLCalendarColors.m
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
//   GTLCalendarColors (0 custom class methods, 4 custom properties)
//   GTLCalendarColorsCalendar (0 custom class methods, 0 custom properties)
//   GTLCalendarColorsEvent (0 custom class methods, 0 custom properties)

#import "GTLCalendarColors.h"

#import "GTLCalendarColorDefinition.h"

// ----------------------------------------------------------------------------
//
//   GTLCalendarColors
//

@implementation GTLCalendarColors
@dynamic calendar, event, kind, updated;

+ (void)load {
  [self registerObjectClassForKind:@"calendar#colors"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarColorsCalendar
//

@implementation GTLCalendarColorsCalendar

+ (Class)classForAdditionalProperties {
  return [GTLCalendarColorDefinition class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarColorsEvent
//

@implementation GTLCalendarColorsEvent

+ (Class)classForAdditionalProperties {
  return [GTLCalendarColorDefinition class];
}

@end
