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
//  GTLMapsEngineScaledShape.h
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
//   GTLMapsEngineScaledShape (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLMapsEngineBorder;
@class GTLMapsEngineColor;

// ----------------------------------------------------------------------------
//
//   GTLMapsEngineScaledShape
//

// Parameters for styling points as scaled shapes.

@interface GTLMapsEngineScaledShape : GTLObject

// Border color/width of the shape. If not specified the shape won't have a
// border.
@property (nonatomic, retain) GTLMapsEngineBorder *border;

// The fill color of the shape. If not specified the shape will be transparent
// (although the borders may not be).
@property (nonatomic, retain) GTLMapsEngineColor *fill;

// Name of the shape.
@property (nonatomic, copy) NSString *shape;

@end
