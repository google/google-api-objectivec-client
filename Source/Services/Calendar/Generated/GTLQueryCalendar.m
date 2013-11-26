/* Copyright (c) 2013 Google Inc.
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
//  GTLQueryCalendar.m
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
//   GTLQueryCalendar (34 custom class methods, 31 custom properties)

#import "GTLQueryCalendar.h"

#import "GTLCalendarAcl.h"
#import "GTLCalendarAclRule.h"
#import "GTLCalendarCalendar.h"
#import "GTLCalendarCalendarList.h"
#import "GTLCalendarCalendarListEntry.h"
#import "GTLCalendarChannel.h"
#import "GTLCalendarColors.h"
#import "GTLCalendarEvent.h"
#import "GTLCalendarEvents.h"
#import "GTLCalendarFreeBusyRequestItem.h"
#import "GTLCalendarFreeBusyResponse.h"
#import "GTLCalendarSetting.h"
#import "GTLCalendarSettings.h"

@implementation GTLQueryCalendar

@dynamic alwaysIncludeEmail, calendarExpansionMax, calendarId, colorRgbFormat,
         destination, eventId, fields, groupExpansionMax, iCalUID, items,
         maxAttendees, maxResults, minAccessRole, orderBy, originalStart,
         pageToken, privateExtendedProperty, q, ruleId, sendNotifications,
         setting, sharedExtendedProperty, showDeleted, showHidden,
         showHiddenInvitations, singleEvents, text, timeMax, timeMin, timeZone,
         updatedMin;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLCalendarFreeBusyRequestItem class], @"items",
      [NSString class], @"privateExtendedProperty",
      [NSString class], @"sharedExtendedProperty",
      nil];
  return map;
}

#pragma mark -
#pragma mark "acl" methods
// These create a GTLQueryCalendar object.

+ (id)queryForAclDeleteWithCalendarId:(NSString *)calendarId
                               ruleId:(NSString *)ruleId {
  NSString *methodName = @"calendar.acl.delete";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.calendarId = calendarId;
  query.ruleId = ruleId;
  return query;
}

+ (id)queryForAclGetWithCalendarId:(NSString *)calendarId
                            ruleId:(NSString *)ruleId {
  NSString *methodName = @"calendar.acl.get";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.calendarId = calendarId;
  query.ruleId = ruleId;
  query.expectedObjectClass = [GTLCalendarAclRule class];
  return query;
}

+ (id)queryForAclInsertWithObject:(GTLCalendarAclRule *)object
                       calendarId:(NSString *)calendarId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"calendar.acl.insert";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.calendarId = calendarId;
  query.expectedObjectClass = [GTLCalendarAclRule class];
  return query;
}

+ (id)queryForAclListWithCalendarId:(NSString *)calendarId {
  NSString *methodName = @"calendar.acl.list";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.calendarId = calendarId;
  query.expectedObjectClass = [GTLCalendarAcl class];
  return query;
}

+ (id)queryForAclPatchWithObject:(GTLCalendarAclRule *)object
                      calendarId:(NSString *)calendarId
                          ruleId:(NSString *)ruleId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"calendar.acl.patch";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.calendarId = calendarId;
  query.ruleId = ruleId;
  query.expectedObjectClass = [GTLCalendarAclRule class];
  return query;
}

+ (id)queryForAclUpdateWithObject:(GTLCalendarAclRule *)object
                       calendarId:(NSString *)calendarId
                           ruleId:(NSString *)ruleId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"calendar.acl.update";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.calendarId = calendarId;
  query.ruleId = ruleId;
  query.expectedObjectClass = [GTLCalendarAclRule class];
  return query;
}

#pragma mark -
#pragma mark "calendarList" methods
// These create a GTLQueryCalendar object.

+ (id)queryForCalendarListDeleteWithCalendarId:(NSString *)calendarId {
  NSString *methodName = @"calendar.calendarList.delete";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.calendarId = calendarId;
  return query;
}

+ (id)queryForCalendarListGetWithCalendarId:(NSString *)calendarId {
  NSString *methodName = @"calendar.calendarList.get";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.calendarId = calendarId;
  query.expectedObjectClass = [GTLCalendarCalendarListEntry class];
  return query;
}

+ (id)queryForCalendarListInsertWithObject:(GTLCalendarCalendarListEntry *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"calendar.calendarList.insert";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.expectedObjectClass = [GTLCalendarCalendarListEntry class];
  return query;
}

+ (id)queryForCalendarListList {
  NSString *methodName = @"calendar.calendarList.list";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLCalendarCalendarList class];
  return query;
}

+ (id)queryForCalendarListPatchWithObject:(GTLCalendarCalendarListEntry *)object
                               calendarId:(NSString *)calendarId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"calendar.calendarList.patch";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.calendarId = calendarId;
  query.expectedObjectClass = [GTLCalendarCalendarListEntry class];
  return query;
}

+ (id)queryForCalendarListUpdateWithObject:(GTLCalendarCalendarListEntry *)object
                                calendarId:(NSString *)calendarId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"calendar.calendarList.update";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.calendarId = calendarId;
  query.expectedObjectClass = [GTLCalendarCalendarListEntry class];
  return query;
}

#pragma mark -
#pragma mark "calendars" methods
// These create a GTLQueryCalendar object.

+ (id)queryForCalendarsClearWithCalendarId:(NSString *)calendarId {
  NSString *methodName = @"calendar.calendars.clear";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.calendarId = calendarId;
  return query;
}

+ (id)queryForCalendarsDeleteWithCalendarId:(NSString *)calendarId {
  NSString *methodName = @"calendar.calendars.delete";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.calendarId = calendarId;
  return query;
}

+ (id)queryForCalendarsGetWithCalendarId:(NSString *)calendarId {
  NSString *methodName = @"calendar.calendars.get";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.calendarId = calendarId;
  query.expectedObjectClass = [GTLCalendarCalendar class];
  return query;
}

+ (id)queryForCalendarsInsertWithObject:(GTLCalendarCalendar *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"calendar.calendars.insert";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.expectedObjectClass = [GTLCalendarCalendar class];
  return query;
}

+ (id)queryForCalendarsPatchWithObject:(GTLCalendarCalendar *)object
                            calendarId:(NSString *)calendarId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"calendar.calendars.patch";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.calendarId = calendarId;
  query.expectedObjectClass = [GTLCalendarCalendar class];
  return query;
}

+ (id)queryForCalendarsUpdateWithObject:(GTLCalendarCalendar *)object
                             calendarId:(NSString *)calendarId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"calendar.calendars.update";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.calendarId = calendarId;
  query.expectedObjectClass = [GTLCalendarCalendar class];
  return query;
}

#pragma mark -
#pragma mark "channels" methods
// These create a GTLQueryCalendar object.

+ (id)queryForChannelsStopWithObject:(GTLCalendarChannel *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"calendar.channels.stop";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  return query;
}

#pragma mark -
#pragma mark "colors" methods
// These create a GTLQueryCalendar object.

+ (id)queryForColorsGet {
  NSString *methodName = @"calendar.colors.get";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLCalendarColors class];
  return query;
}

#pragma mark -
#pragma mark "events" methods
// These create a GTLQueryCalendar object.

+ (id)queryForEventsDeleteWithCalendarId:(NSString *)calendarId
                                 eventId:(NSString *)eventId {
  NSString *methodName = @"calendar.events.delete";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.calendarId = calendarId;
  query.eventId = eventId;
  return query;
}

+ (id)queryForEventsGetWithCalendarId:(NSString *)calendarId
                              eventId:(NSString *)eventId {
  NSString *methodName = @"calendar.events.get";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.calendarId = calendarId;
  query.eventId = eventId;
  query.expectedObjectClass = [GTLCalendarEvent class];
  return query;
}

+ (id)queryForEventsImportWithObject:(GTLCalendarEvent *)object
                          calendarId:(NSString *)calendarId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"calendar.events.import";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.calendarId = calendarId;
  query.expectedObjectClass = [GTLCalendarEvent class];
  return query;
}

+ (id)queryForEventsInsertWithObject:(GTLCalendarEvent *)object
                          calendarId:(NSString *)calendarId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"calendar.events.insert";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.calendarId = calendarId;
  query.expectedObjectClass = [GTLCalendarEvent class];
  return query;
}

+ (id)queryForEventsInstancesWithCalendarId:(NSString *)calendarId
                                    eventId:(NSString *)eventId {
  NSString *methodName = @"calendar.events.instances";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.calendarId = calendarId;
  query.eventId = eventId;
  query.expectedObjectClass = [GTLCalendarEvents class];
  return query;
}

+ (id)queryForEventsListWithCalendarId:(NSString *)calendarId {
  NSString *methodName = @"calendar.events.list";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.calendarId = calendarId;
  query.expectedObjectClass = [GTLCalendarEvents class];
  return query;
}

+ (id)queryForEventsMoveWithCalendarId:(NSString *)calendarId
                               eventId:(NSString *)eventId
                           destination:(NSString *)destination {
  NSString *methodName = @"calendar.events.move";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.calendarId = calendarId;
  query.eventId = eventId;
  query.destination = destination;
  query.expectedObjectClass = [GTLCalendarEvent class];
  return query;
}

+ (id)queryForEventsPatchWithObject:(GTLCalendarEvent *)object
                         calendarId:(NSString *)calendarId
                            eventId:(NSString *)eventId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"calendar.events.patch";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.calendarId = calendarId;
  query.eventId = eventId;
  query.expectedObjectClass = [GTLCalendarEvent class];
  return query;
}

+ (id)queryForEventsQuickAddWithCalendarId:(NSString *)calendarId
                                      text:(NSString *)text {
  NSString *methodName = @"calendar.events.quickAdd";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.calendarId = calendarId;
  query.text = text;
  query.expectedObjectClass = [GTLCalendarEvent class];
  return query;
}

+ (id)queryForEventsUpdateWithObject:(GTLCalendarEvent *)object
                          calendarId:(NSString *)calendarId
                             eventId:(NSString *)eventId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"calendar.events.update";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.calendarId = calendarId;
  query.eventId = eventId;
  query.expectedObjectClass = [GTLCalendarEvent class];
  return query;
}

+ (id)queryForEventsWatchWithObject:(GTLCalendarChannel *)object
                         calendarId:(NSString *)calendarId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"calendar.events.watch";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.calendarId = calendarId;
  query.expectedObjectClass = [GTLCalendarChannel class];
  return query;
}

#pragma mark -
#pragma mark "freebusy" methods
// These create a GTLQueryCalendar object.

+ (id)queryForFreebusyQuery {
  NSString *methodName = @"calendar.freebusy.query";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLCalendarFreeBusyResponse class];
  return query;
}

#pragma mark -
#pragma mark "settings" methods
// These create a GTLQueryCalendar object.

+ (id)queryForSettingsGetWithSetting:(NSString *)setting {
  NSString *methodName = @"calendar.settings.get";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.setting = setting;
  query.expectedObjectClass = [GTLCalendarSetting class];
  return query;
}

+ (id)queryForSettingsList {
  NSString *methodName = @"calendar.settings.list";
  GTLQueryCalendar *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLCalendarSettings class];
  return query;
}

@end
