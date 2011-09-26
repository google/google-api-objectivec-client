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
//  GTLQueryCalendar.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Calendar API (calendar/v3)
// Description:
//   Lets you manipulate events and other calendar data.
// Documentation:
//   https://code.google.com/apis/calendar/v3/using.html
// Classes:
//   GTLQueryCalendar (31 custom class methods, 24 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLCalendarAclRule;
@class GTLCalendarCalendar;
@class GTLCalendarCalendarListEntry;
@class GTLCalendarEvent;

@interface GTLQueryCalendar : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (retain) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (retain) NSString *calendarId;
@property (retain) NSString *destination;
@property (retain) NSString *eventId;
@property (retain) NSString *iCalUID;
@property (assign) NSInteger maxAttendees;
@property (assign) NSInteger maxResults;
@property (retain) NSString *minAccessRole;
@property (retain) NSString *orderBy;
@property (retain) NSString *originalStart;
@property (retain) NSString *pageToken;
@property (retain) NSString *q;
@property (retain) NSString *ruleId;
@property (assign) BOOL sendNotifications;
@property (retain) NSString *setting;
@property (assign) BOOL showDeleted;
@property (assign) BOOL showHidden;
@property (assign) BOOL showHiddenInvitations;
@property (assign) BOOL singleEvents;
@property (retain) NSString *text;
@property (retain) NSString *timeMax;
@property (retain) NSString *timeMin;
@property (retain) NSString *timeZone;
@property (retain) NSString *updatedMin;

#pragma mark -
#pragma mark "acl" methods
// These create a GTLQueryCalendar object.

// Method: calendar.acl.delete
// Deletes an access control rule.
//  Required:
//   calendarId: Calendar identifier.
//   ruleId: ACL rule identifier.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
+ (id)queryForAclDeleteWithCalendarId:(NSString *)calendarId
                               ruleId:(NSString *)ruleId;

// Method: calendar.acl.get
// Returns an access control rule.
//  Required:
//   calendarId: Calendar identifier.
//   ruleId: ACL rule identifier.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarAclRule.
+ (id)queryForAclGetWithCalendarId:(NSString *)calendarId
                            ruleId:(NSString *)ruleId;

// Method: calendar.acl.insert
// Creates an access control rule.
//  Required:
//   calendarId: Calendar identifier.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarAclRule.
+ (id)queryForAclInsertWithObject:(GTLCalendarAclRule *)object
                       calendarId:(NSString *)calendarId;

// Method: calendar.acl.list
// Returns the rules in the access control list for the calendar.
//  Required:
//   calendarId: Calendar identifier.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarAcl.
+ (id)queryForAclListWithCalendarId:(NSString *)calendarId;

// Method: calendar.acl.patch
// Updates an access control rule. This method supports patch semantics.
//  Required:
//   calendarId: Calendar identifier.
//   ruleId: ACL rule identifier.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarAclRule.
+ (id)queryForAclPatchWithObject:(GTLCalendarAclRule *)object
                      calendarId:(NSString *)calendarId
                          ruleId:(NSString *)ruleId;

// Method: calendar.acl.update
// Updates an access control rule.
//  Required:
//   calendarId: Calendar identifier.
//   ruleId: ACL rule identifier.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarAclRule.
+ (id)queryForAclUpdateWithObject:(GTLCalendarAclRule *)object
                       calendarId:(NSString *)calendarId
                           ruleId:(NSString *)ruleId;

#pragma mark -
#pragma mark "calendarList" methods
// These create a GTLQueryCalendar object.

// Method: calendar.calendarList.delete
// Deletes an entry on the user's calendar list.
//  Required:
//   calendarId: Calendar identifier.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
+ (id)queryForCalendarListDeleteWithCalendarId:(NSString *)calendarId;

// Method: calendar.calendarList.get
// Returns an entry on the user's calendar list.
//  Required:
//   calendarId: Calendar identifier.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarCalendarListEntry.
+ (id)queryForCalendarListGetWithCalendarId:(NSString *)calendarId;

// Method: calendar.calendarList.insert
// Adds an entry to the user's calendar list.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarCalendarListEntry.
+ (id)queryForCalendarListInsertWithObject:(GTLCalendarCalendarListEntry *)object;

// Method: calendar.calendarList.list
// Returns entries on the user's calendar list.
//  Optional:
//   maxResults: Maximum number of entries returned on one result page.
//     Optional.
//   minAccessRole: The minimum access role for the user in the returned
//     entires. Optional. The default is no restriction.
//      kGTLCalendarMinAccessRoleFreebusyReader: The user can read free/busy
//        information.
//      kGTLCalendarMinAccessRoleOwner: The user can read and modify events and
//        access control lists.
//      kGTLCalendarMinAccessRoleReader: The user can read events that are not
//        private.
//      kGTLCalendarMinAccessRoleWriter: The user can read and modify events.
//   pageToken: Token specifying which result page to return. Optional.
//   showHidden: Whether to show hidden entries. Optional. The default is False.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarCalendarList.
+ (id)queryForCalendarListList;

// Method: calendar.calendarList.patch
// Updates an entry on the user's calendar list. This method supports patch
// semantics.
//  Required:
//   calendarId: Calendar identifier.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarCalendarListEntry.
+ (id)queryForCalendarListPatchWithObject:(GTLCalendarCalendarListEntry *)object
                               calendarId:(NSString *)calendarId;

// Method: calendar.calendarList.update
// Updates an entry on the user's calendar list.
//  Required:
//   calendarId: Calendar identifier.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarCalendarListEntry.
+ (id)queryForCalendarListUpdateWithObject:(GTLCalendarCalendarListEntry *)object
                                calendarId:(NSString *)calendarId;

#pragma mark -
#pragma mark "calendars" methods
// These create a GTLQueryCalendar object.

// Method: calendar.calendars.clear
// Clears a primary calendar. This operation deletes all data associated with
// the primary calendar of an account and cannot be undone.
//  Required:
//   calendarId: Calendar identifier.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
+ (id)queryForCalendarsClearWithCalendarId:(NSString *)calendarId;

// Method: calendar.calendars.delete
// Deletes a secondary calendar.
//  Required:
//   calendarId: Calendar identifier.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
+ (id)queryForCalendarsDeleteWithCalendarId:(NSString *)calendarId;

// Method: calendar.calendars.get
// Returns metadata for a calendar.
//  Required:
//   calendarId: Calendar identifier.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarCalendar.
+ (id)queryForCalendarsGetWithCalendarId:(NSString *)calendarId;

// Method: calendar.calendars.insert
// Creates a secondary calendar.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarCalendar.
+ (id)queryForCalendarsInsertWithObject:(GTLCalendarCalendar *)object;

// Method: calendar.calendars.patch
// Updates metadata for a calendar. This method supports patch semantics.
//  Required:
//   calendarId: Calendar identifier.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarCalendar.
+ (id)queryForCalendarsPatchWithObject:(GTLCalendarCalendar *)object
                            calendarId:(NSString *)calendarId;

// Method: calendar.calendars.update
// Updates metadata for a calendar.
//  Required:
//   calendarId: Calendar identifier.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarCalendar.
+ (id)queryForCalendarsUpdateWithObject:(GTLCalendarCalendar *)object
                             calendarId:(NSString *)calendarId;

#pragma mark -
#pragma mark "events" methods
// These create a GTLQueryCalendar object.

// Method: calendar.events.delete
// Deletes an event.
//  Required:
//   calendarId: Calendar identifier.
//   eventId: Event identifier.
//  Optional:
//   sendNotifications: Whether to send notifications about the deletion of the
//     event. Optional. The default is False.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
+ (id)queryForEventsDeleteWithCalendarId:(NSString *)calendarId
                                 eventId:(NSString *)eventId;

// Method: calendar.events.get
// Returns an event.
//  Required:
//   calendarId: Calendar identifier.
//   eventId: Event identifier.
//  Optional:
//   maxAttendees: The maximum number of attendees to include in the response.
//     If there are more than the specified number of attendees, only the
//     participant is returned. Optional.
//   timeZone: Time zone used in the response. Optional. The default is the time
//     zone of the calendar.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarEvent.
+ (id)queryForEventsGetWithCalendarId:(NSString *)calendarId
                              eventId:(NSString *)eventId;

// Method: calendar.events.import
// Imports an event.
//  Required:
//   calendarId: Calendar identifier.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarEvent.
+ (id)queryForEventsImportWithObject:(GTLCalendarEvent *)object
                          calendarId:(NSString *)calendarId;

// Method: calendar.events.insert
// Creates an event.
//  Required:
//   calendarId: Calendar identifier.
//  Optional:
//   sendNotifications: Whether to send notifications about the creation of the
//     new event. Optional. The default is False.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarEvent.
+ (id)queryForEventsInsertWithObject:(GTLCalendarEvent *)object
                          calendarId:(NSString *)calendarId;

// Method: calendar.events.instances
// Returns instances of the specified recurring event.
//  Required:
//   calendarId: Calendar identifier.
//   eventId: Recurring event identifier.
//  Optional:
//   maxAttendees: The maximum number of attendees to include in the response.
//     If there are more than the specified number of attendees, only the
//     participant is returned. Optional.
//   maxResults: Maximum number of events returned on one result page. Optional.
//   originalStart: The original start time of the instance in the result.
//     Optional.
//   pageToken: Token specifying which result page to return. Optional.
//   showDeleted: Whether to include deleted events (with 'eventStatus' equals
//     'cancelled') in the result. Optional. The default is False.
//   timeZone: Time zone used in the response. Optional. The default is the time
//     zone of the calendar.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarEvents.
+ (id)queryForEventsInstancesWithCalendarId:(NSString *)calendarId
                                    eventId:(NSString *)eventId;

// Method: calendar.events.list
// Returns events on the specified calendar.
//  Required:
//   calendarId: Calendar identifier.
//  Optional:
//   iCalUID: Specifies iCalendar UID (iCalUID) of events to be included in the
//     response. Optional.
//   maxAttendees: The maximum number of attendees to include in the response.
//     If there are more than the specified number of attendees, only the
//     participant is returned. Optional.
//   maxResults: Maximum number of events returned on one result page. Optional.
//   orderBy: The order of the events returned in the result. Optional. The
//     default is an unspecified, stable order.
//      kGTLCalendarOrderByStartTime: Order by the start date/time (ascending).
//        This is only available when querying single events (i.e. the parameter
//        "singleEvents" is True)
//      kGTLCalendarOrderByUpdated: Order by last modification time (ascending).
//   pageToken: Token specifying which result page to return. Optional.
//   q: Free text search terms to find events that match these terms in any
//     field, except for extended properties. Optional.
//   showDeleted: Whether to include deleted events (with 'eventStatus' equals
//     'cancelled') in the result. Optional. The default is False.
//   showHiddenInvitations: Whether to include hidden invitations in the result.
//     Optional. The default is False.
//   singleEvents: Whether to expand recurring events into instances and only
//     return single one-off events and instances of recurring events, but not
//     the underlying recurring events themselves. Optional. The default is
//     False.
//   timeMax: Upper bound (exclusive) for an event's start time to filter by.
//     Optional. The default is not to filter by start time.
//   timeMin: Lower bound (inclusive) for an event's end time to filter by.
//     Optional. The default is not to filter by end time.
//   timeZone: Time zone used in the response. Optional. The default is the time
//     zone of the calendar.
//   updatedMin: Lower bound for an event's last modification time (as a RFC
//     3339 timestamp) to filter by. Optional. The default is not to filter by
//     last modification time.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarEvents.
+ (id)queryForEventsListWithCalendarId:(NSString *)calendarId;

// Method: calendar.events.move
// Moves an event to another calendar, i.e. changes an event's organizer.
//  Required:
//   calendarId: Calendar identifier of the source calendar where the event
//     currently is on.
//   eventId: Event identifier.
//   destination: Calendar identifier of the target calendar where the event is
//     to be moved to.
//  Optional:
//   sendNotifications: Whether to send notifications about the change of the
//     event's organizer. Optional. The default is False.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarEvent.
+ (id)queryForEventsMoveWithCalendarId:(NSString *)calendarId
                               eventId:(NSString *)eventId
                           destination:(NSString *)destination;

// Method: calendar.events.patch
// Updates an event. This method supports patch semantics.
//  Required:
//   calendarId: Calendar identifier.
//   eventId: Event identifier.
//  Optional:
//   sendNotifications: Whether to send notifications about the event update
//     (e.g. attendee's responses, title changes, etc.). Optional. The default
//     is False.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarEvent.
+ (id)queryForEventsPatchWithObject:(GTLCalendarEvent *)object
                         calendarId:(NSString *)calendarId
                            eventId:(NSString *)eventId;

// Method: calendar.events.quickAdd
// Creates an event based on a simple text string.
//  Required:
//   calendarId: Calendar identifier.
//   text: The text describing the event to be created.
//  Optional:
//   sendNotifications: Whether to send notifications about the creation of the
//     event. Optional. The default is False.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarEvent.
+ (id)queryForEventsQuickAddWithCalendarId:(NSString *)calendarId
                                      text:(NSString *)text;

// Method: calendar.events.reset
// Resets a specialized instance of a recurring event to its original state.
//  Required:
//   calendarId: Calendar identifier.
//   eventId: Event identifier.
//  Optional:
//   sendNotifications: Whether to send notifications about the event update.
//     Optional. The default is False.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarEvent.
+ (id)queryForEventsResetWithCalendarId:(NSString *)calendarId
                                eventId:(NSString *)eventId;

// Method: calendar.events.update
// Updates an event.
//  Required:
//   calendarId: Calendar identifier.
//   eventId: Event identifier.
//  Optional:
//   sendNotifications: Whether to send notifications about the event update
//     (e.g. attendee's responses, title changes, etc.). Optional. The default
//     is False.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarEvent.
+ (id)queryForEventsUpdateWithObject:(GTLCalendarEvent *)object
                          calendarId:(NSString *)calendarId
                             eventId:(NSString *)eventId;

#pragma mark -
#pragma mark "settings" methods
// These create a GTLQueryCalendar object.

// Method: calendar.settings.get
// Returns a single user setting.
//  Required:
//   setting: Name of the user setting.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarSetting.
+ (id)queryForSettingsGetWithSetting:(NSString *)setting;

// Method: calendar.settings.list
// Returns all user settings for the authenticated user.
//  Authorization scope(s):
//   kGTLAuthScopeCalendar
// Fetches a GTLCalendarSettings.
+ (id)queryForSettingsList;

@end
