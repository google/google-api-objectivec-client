/* Copyright (c) 2012 Google Inc.
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
//  GTLLatitudeLocation.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Latitude API (latitude/v1)
// Description:
//   Lets you read and update your current location and work with your location
//   history
// Documentation:
//   https://developers.google.com/latitude/v1/using
// Classes:
//   GTLLatitudeLocation (0 custom class methods, 10 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLLatitudeLocation
//

// A Location resource identifies a user's position at a particular time. It may
// include metadata about the user's position, such as a venue if the location
// was recorded at the time of a check-in.

@interface GTLLatitudeLocation : GTLObject

// Accuracy of the latitude and longitude coordinates, in non-negative meters.
// Optional.
@property (retain) id accuracy;

// Unique ID of the Buzz message that corresponds to the check-in associated
// with this location. Available only for check-in locations. Optional.
@property (retain) id activityId;

// Altitude of the location, in meters. Optional.
@property (retain) id altitude;

// Accuracy of the altitude value, in meters. Optional.
@property (retain) id altitudeAccuracy;

// Direction of travel of the user when this location was recorded. In degrees,
// clockwise relative to true north. Optional.
@property (retain) id heading;

// Kind of this item.
@property (copy) NSString *kind;

// Latitude of the location, in decimal degrees.
@property (retain) id latitude;

// Longitude of the location, in decimal degrees.
@property (retain) id longitude;

// Ground speed of the user at the time this location was recorded, in meters
// per second. Non-negative. Optional.
@property (retain) id speed;

// Timestamp of the Location Resource, in milliseconds since the epoch (UTC).
// This is also the Location Resource's unique id.
@property (retain) id timestampMs;

@end
