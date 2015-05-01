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
//  GTLMapsEngineSchema.h
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
//   GTLMapsEngineSchema (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLMapsEngineTableColumn;

// ----------------------------------------------------------------------------
//
//   GTLMapsEngineSchema
//

// A schema indicating the properties which may be associated with features
// within a Table, and the types of those properties.

@interface GTLMapsEngineSchema : GTLObject

// An array of TableColumn objects. The first object in the array must be named
// geometry and be of type points, lineStrings, polygons, or mixedGeometry.
@property (nonatomic, retain) NSArray *columns;  // of GTLMapsEngineTableColumn

// The name of the column that contains a feature's geometry. This field can be
// omitted during table create; Google Maps Engine supports only a single
// geometry column, which must be named geometry and be the first object in the
// columns array.
@property (nonatomic, copy) NSString *primaryGeometry;

// The name of the column that contains the unique identifier of a Feature.
@property (nonatomic, copy) NSString *primaryKey;

@end
