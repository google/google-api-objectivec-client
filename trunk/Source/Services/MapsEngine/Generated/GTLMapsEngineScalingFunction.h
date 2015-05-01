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
//  GTLMapsEngineScalingFunction.h
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
//   GTLMapsEngineScalingFunction (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLMapsEngineSizeRange;
@class GTLMapsEngineValueRange;

// ----------------------------------------------------------------------------
//
//   GTLMapsEngineScalingFunction
//

// Parameters for scaling scaled shapes.

@interface GTLMapsEngineScalingFunction : GTLObject

// Name of the numeric column used to scale a shape.
@property (nonatomic, copy) NSString *column;

// The type of scaling function to use. Defaults to SQRT. Currently only linear
// and square root scaling are supported.
@property (nonatomic, copy) NSString *scalingType;

// The range of shape sizes, in pixels. For circles, the size corresponds to the
// diameter.
@property (nonatomic, retain) GTLMapsEngineSizeRange *sizeRange;

// The range of values to display across the size range.
@property (nonatomic, retain) GTLMapsEngineValueRange *valueRange;

@end
