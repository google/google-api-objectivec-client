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
//  GTLMapsEngineMap.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Maps Engine API (mapsengine/v1)
// Description:
//   The Google Maps Engine API allows developers to store and query geospatial
//   vector and raster data.
// Documentation:
//   https://developers.google.com/maps-engine/
// Classes:
//   GTLMapsEngineMap (0 custom class methods, 11 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLMapsEngineMapItem;

// ----------------------------------------------------------------------------
//
//   GTLMapsEngineMap
//

// A Map is a collection of Layers, optionally contained within folders.

@interface GTLMapsEngineMap : GTLObject

// An array of four numbers (west, south, east, north) which define the
// rectangular bounding box which contains all of the data in this Map. The
// numbers represent latitude and longitude in decimal degrees.
@property (retain) NSArray *bbox;  // of NSNumber (doubleValue)

// The contents of this Map.
@property (retain) NSArray *contents;  // of GTLMapsEngineMapItem

// The creation time of this map. The value is an RFC 3339 formatted date-time
// value (e.g. 1970-01-01T00:00:00Z).
@property (retain) GTLDateTime *creationTime;

// An array of four numbers (west, south, east, north) which defines the
// rectangular bounding box of the default viewport. The numbers represent
// latitude and longitude in decimal degrees.
@property (retain) NSArray *defaultViewport;  // of NSNumber (doubleValue)

// The description of this Map, supplied by the author.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// A globally unique ID, used to refer to this Map.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The last modified time of this map. The value is an RFC 3339 formatted
// date-time value (e.g. 1970-01-01T00:00:00Z).
@property (retain) GTLDateTime *lastModifiedTime;

// The name of this Map, supplied by the author.
@property (copy) NSString *name;

// The ID of the project that this Map is in.
@property (copy) NSString *projectId;

// Tags of this Map.
@property (retain) NSArray *tags;  // of NSString

// An array containing the available versions of this Map. Currently may only
// contain "published".
@property (retain) NSArray *versions;  // of NSString

@end
