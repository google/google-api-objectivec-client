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
//  GTLMapsEngineMapKmlLink.h
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
//   GTLMapsEngineMapKmlLink (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLMapsEngineMapKmlLink
//

@interface GTLMapsEngineMapKmlLink : GTLObject

// An array of four numbers (west, south, east, north) which defines the
// rectangular bounding box of the default viewport. The numbers represent
// latitude and longitude in decimal degrees.
@property (nonatomic, retain) NSArray *defaultViewport;  // of NSNumber (doubleValue)

// The URL to the KML file represented by this MapKmlLink.
@property (nonatomic, copy) NSString *kmlUrl;

// The name of this MapKmlLink.
@property (nonatomic, copy) NSString *name;

// Identifies this object as a MapKmlLink.
@property (nonatomic, copy) NSString *type;

// The visibility setting of this MapKmlLink. One of "defaultOn" or
// "defaultOff".
@property (nonatomic, copy) NSString *visibility;

@end
