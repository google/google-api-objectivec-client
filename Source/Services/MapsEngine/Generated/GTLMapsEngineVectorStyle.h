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
//  GTLMapsEngineVectorStyle.h
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
//   GTLMapsEngineVectorStyle (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLMapsEngineDisplayRule;
@class GTLMapsEngineFeatureInfo;

// ----------------------------------------------------------------------------
//
//   GTLMapsEngineVectorStyle
//

// A vector style contains styling information for vector layer.

@interface GTLMapsEngineVectorStyle : GTLObject
@property (retain) NSArray *displayRules;  // of GTLMapsEngineDisplayRule

// Individual feature info, this is called Info Window in Maps Engine UI. If not
// provided, a default template with all attributes will be generated.
@property (retain) GTLMapsEngineFeatureInfo *featureInfo;

// The type of the vector style. Currently, only displayRule is supported.
@property (copy) NSString *type;

@end
