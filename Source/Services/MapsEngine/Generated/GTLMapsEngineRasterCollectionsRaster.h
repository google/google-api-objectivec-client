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
//  GTLMapsEngineRasterCollectionsRaster.h
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
//   GTLMapsEngineRasterCollectionsRaster (0 custom class methods, 9 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLMapsEngineRasterCollectionsRaster
//

// A raster resource.

@interface GTLMapsEngineRasterCollectionsRaster : GTLObject

// A rectangular bounding box which contains all of the data in this Raster. The
// numbers represent latitude and longitude in decimal degrees.
@property (retain) NSArray *bbox;  // of NSNumber (doubleValue)

// The creation time of this raster. The value is an RFC 3339 formatted
// date-time value (e.g. 1970-01-01T00:00:00Z).
@property (retain) GTLDateTime *creationTime;

// The description of this Raster, supplied by the author.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// A globally unique ID, used to refer to this Raster.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The last modified time of this raster. The value is an RFC 3339 formatted
// date-time value (e.g. 1970-01-01T00:00:00Z).
@property (retain) GTLDateTime *lastModifiedTime;

// The name of this Raster, supplied by the author.
@property (copy) NSString *name;

// The ID of the project that this Raster is in.
@property (copy) NSString *projectId;

// The type of this Raster. Always "image" today.
@property (copy) NSString *rasterType;

// Tags of this Raster.
@property (retain) NSArray *tags;  // of NSString

@end
