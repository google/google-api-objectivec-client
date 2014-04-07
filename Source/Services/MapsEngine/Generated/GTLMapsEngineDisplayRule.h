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
//  GTLMapsEngineDisplayRule.h
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
//   GTLMapsEngineDisplayRule (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLMapsEngineFilter;
@class GTLMapsEngineLineStyle;
@class GTLMapsEnginePointStyle;
@class GTLMapsEnginePolygonStyle;
@class GTLMapsEngineZoomLevels;

// ----------------------------------------------------------------------------
//
//   GTLMapsEngineDisplayRule
//

// A display rule of the vector style.

@interface GTLMapsEngineDisplayRule : GTLObject

// This display rule will only be applied to features that match all of the
// filters here. If filters is empty, then the rule applies to all features.
@property (retain) NSArray *filters;  // of GTLMapsEngineFilter

// Style applied to lines. Required for LineString Geometry.
@property (retain) GTLMapsEngineLineStyle *lineOptions;

// Display rule name. Name is not unique and cannot be used for identification
// purpose.
@property (copy) NSString *name;

// Style applied to points. Required for Point Geometry.
@property (retain) GTLMapsEnginePointStyle *pointOptions;

// Style applied to polygons. Required for Polygon Geometry.
@property (retain) GTLMapsEnginePolygonStyle *polygonOptions;

// The zoom levels that this display rule apply.
@property (retain) GTLMapsEngineZoomLevels *zoomLevels;

@end
