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
//  GTLCalendarCalendarListEntry.m
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
//   GTLCalendarCalendarListEntry (0 custom class methods, 18 custom properties)
//   GTLCalendarCalendarListEntryNotificationSettings (0 custom class methods, 1 custom properties)

#import "GTLCalendarCalendarListEntry.h"

#import "GTLCalendarEventReminder.h"
#import "GTLCalendarNotification.h"

// ----------------------------------------------------------------------------
//
//   GTLCalendarCalendarListEntry
//

@implementation GTLCalendarCalendarListEntry
@dynamic accessRole, backgroundColor, colorId, defaultReminders, deleted,
         descriptionProperty, ETag, foregroundColor, hidden, identifier, kind,
         location, notificationSettings, primary, selected, summary,
         summaryOverride, timeZone;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"descriptionProperty" : @"description",
    @"ETag" : @"etag",
    @"identifier" : @"id"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"defaultReminders" : [GTLCalendarEventReminder class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"calendar#calendarListEntry"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarCalendarListEntryNotificationSettings
//

@implementation GTLCalendarCalendarListEntryNotificationSettings
@dynamic notifications;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"notifications" : [GTLCalendarNotification class]
  };
  return map;
}

@end
