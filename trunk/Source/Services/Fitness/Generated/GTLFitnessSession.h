/* Copyright (c) 2014 Google Inc.
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
//   GTLFitnessSession (0 custom class methods, 8 custom properties)

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

// The type of activity this session represents.
@property (retain) NSNumber *activityType;  // intValue

// The application that created the session.
@property (retain) GTLFitnessApplication *application;

// A description for this session.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// An end time, in milliseconds since epoch, inclusive.
@property (retain) NSNumber *endTimeMillis;  // longLongValue

// A client-generated identifier that is unique across all sessions owned by
// this particular user.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// A timestamp that indicates when the session was last modified.
@property (retain) NSNumber *modifiedTimeMillis;  // longLongValue

// A human readable name of the session.
@property (copy) NSString *name;

// A start time, in milliseconds since epoch, inclusive.
@property (retain) NSNumber *startTimeMillis;  // longLongValue

@end
