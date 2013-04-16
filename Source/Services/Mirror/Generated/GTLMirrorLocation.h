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
//  GTLMirrorLocation.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Mirror API (mirror/v1)
// Description:
//   API for interacting with Glass users via the timeline.
// Documentation:
//   https://developers.google.com/glass
// Classes:
//   GTLMirrorLocation (0 custom class methods, 8 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLMirrorLocation
//

// A geographic location that can be associated with a timeline item.

@interface GTLMirrorLocation : GTLObject

// The accuracy of the location fix in meters.
@property (retain) NSNumber *accuracy;  // doubleValue

// The full address of the location.
@property (copy) NSString *address;

// The name to be displayed. This may be a business name or a user-defined
// place, such as "Home".
@property (copy) NSString *displayName;

// The ID of the location.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The type of resource. This is always mirror#location.
@property (copy) NSString *kind;

// The latitude, in degrees.
@property (retain) NSNumber *latitude;  // doubleValue

// The longitude, in degrees.
@property (retain) NSNumber *longitude;  // doubleValue

// The time at which this location was captured, formatted according to RFC
// 3339.
@property (retain) GTLDateTime *timestamp;

@end
