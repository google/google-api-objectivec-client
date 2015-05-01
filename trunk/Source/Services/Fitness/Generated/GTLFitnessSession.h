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
//  GTLFitnessSession.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Fitness (fitness/v1)
// Description:
//   Google Fit API
// Documentation:
//   https://developers.google.com/fit/rest/
// Classes:
//   GTLFitnessSession (0 custom class methods, 9 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLFitnessApplication;

// ----------------------------------------------------------------------------
//
//   GTLFitnessSession
//

// Sessions contain metadata, such as a user-friendly name and time interval
// information.

@interface GTLFitnessSession : GTLObject

// Session active time. While start_time_millis and end_time_millis define the
// full session time, the active time can be shorter and specified by
// active_time_millis. If the inactive time during the session is known, it
// should also be inserted via a com.google.activity.segment data point with a
// STILL activity value
@property (nonatomic, retain) NSNumber *activeTimeMillis;  // longLongValue

// The type of activity this session represents.
@property (nonatomic, retain) NSNumber *activityType;  // intValue

// The application that created the session.
@property (nonatomic, retain) GTLFitnessApplication *application;

// A description for this session.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// An end time, in milliseconds since epoch, inclusive.
@property (nonatomic, retain) NSNumber *endTimeMillis;  // longLongValue

// A client-generated identifier that is unique across all sessions owned by
// this particular user.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// A timestamp that indicates when the session was last modified.
@property (nonatomic, retain) NSNumber *modifiedTimeMillis;  // longLongValue

// A human readable name of the session.
@property (nonatomic, copy) NSString *name;

// A start time, in milliseconds since epoch, inclusive.
@property (nonatomic, retain) NSNumber *startTimeMillis;  // longLongValue

@end
