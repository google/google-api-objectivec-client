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
//  GTLMapsEnginePublishedMap.h
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
//   GTLMapsEnginePublishedMap (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLMapsEngineMapItem;

// ----------------------------------------------------------------------------
//
//   GTLMapsEnginePublishedMap
//

// The published version of a map asset.

@interface GTLMapsEnginePublishedMap : GTLObject

// The contents of this Map.
@property (nonatomic, retain) NSArray *contents;  // of GTLMapsEngineMapItem

// An array of four numbers (west, south, east, north) which defines the
// rectangular bounding box of the default viewport. The numbers represent
// latitude and longitude in decimal degrees.
@property (nonatomic, retain) NSArray *defaultViewport;  // of NSNumber (doubleValue)

// The description of this Map, supplied by the author.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// A globally unique ID, used to refer to this Map.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The name of this Map, supplied by the author.
@property (nonatomic, copy) NSString *name;

// The ID of the project that this Map is in.
@property (nonatomic, copy) NSString *projectId;

@end
