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
//  GTLLatitudeLocationFeed.h
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
//   GTLLatitudeLocationFeed (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLLatitudeLocation;

// ----------------------------------------------------------------------------
//
//   GTLLatitudeLocationFeed
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLLatitudeLocationFeed : GTLCollectionObject
@property (retain) NSArray *items;  // of GTLLatitudeLocation
@property (copy) NSString *kind;
@end
