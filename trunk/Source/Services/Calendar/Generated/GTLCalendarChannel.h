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
//  GTLCalendarChannel.h
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
//   GTLCalendarChannel (0 custom class methods, 9 custom properties)
//   GTLCalendarChannelParams (0 custom class methods, 0 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCalendarChannelParams;

// ----------------------------------------------------------------------------
//
//   GTLCalendarChannel
//

@interface GTLCalendarChannel : GTLObject

// The address of the receiving entity where events are delivered. Specific to
// the channel type.
@property (copy) NSString *address;

// The expiration instant for this channel if it is defined.
@property (retain) NSNumber *expiration;  // longLongValue

// A UUID for the channel
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// A channel watching an API resource
@property (copy) NSString *kind;

// Additional parameters controlling delivery channel behavior
@property (retain) GTLCalendarChannelParams *params;

// An opaque id that identifies the resource that is being watched. Stable
// across different API versions
@property (copy) NSString *resourceId;

// The canonicalized ID of the watched resource.
@property (copy) NSString *resourceUri;

// An arbitrary string associated with the channel that is delivered to the
// target address with each event delivered over this channel.
@property (copy) NSString *token;

// The type of delivery mechanism used by this channel
@property (copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarChannelParams
//

@interface GTLCalendarChannelParams : GTLObject
// This object is documented as having more properties that are NSString. Use
// -additionalJSONKeys and -additionalPropertyForName: to get the list of
// properties and then fetch them; or -additionalProperties to fetch them all at
// once.
@end
