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
//  GTLMapsEngineLabelStyle.h
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
//   GTLMapsEngineLabelStyle (0 custom class methods, 7 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLMapsEngineColor;

// ----------------------------------------------------------------------------
//
//   GTLMapsEngineLabelStyle
//

// Text label style.

@interface GTLMapsEngineLabelStyle : GTLObject

// Color of the text. If not provided, default to black.
@property (nonatomic, copy) NSString *color;

// The column value of the feature to be displayed.
@property (nonatomic, copy) NSString *column;

// Font style of the label, defaults to 'normal'.
@property (nonatomic, copy) NSString *fontStyle;

// Font weight of the label, defaults to 'normal'.
@property (nonatomic, copy) NSString *fontWeight;

// Opacity of the text.
@property (nonatomic, retain) NSNumber *opacity;  // doubleValue

// Outline color of the text.
@property (nonatomic, retain) GTLMapsEngineColor *outline;

// Font size of the label, in pixels. 8 <= size <= 15. If not provided, a
// default size will be provided.
@property (nonatomic, retain) NSNumber *size;  // doubleValue

@end
