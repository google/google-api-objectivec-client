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
//  GTLCalendarFreeBusyRequest.h
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
//   GTLCalendarFreeBusyRequest (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCalendarFreeBusyRequestItem;

// ----------------------------------------------------------------------------
//
//   GTLCalendarFreeBusyRequest
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLCalendarFreeBusyRequest : GTLCollectionObject

// Maximal number of calendars for which FreeBusy information is to be provided.
// Optional.
@property (retain) NSNumber *calendarExpansionMax;  // intValue

// Maximal number of calendar identifiers to be provided for a single group.
// Optional. An error will be returned for a group with more members than this
// value.
@property (retain) NSNumber *groupExpansionMax;  // intValue

// List of calendars and/or groups to query.
@property (retain) NSArray *items;  // of GTLCalendarFreeBusyRequestItem

// The end of the interval for the query.
@property (retain) GTLDateTime *timeMax;

// The start of the interval for the query.
@property (retain) GTLDateTime *timeMin;

// Time zone used in the response. Optional. The default is UTC.
@property (copy) NSString *timeZone;

@end
