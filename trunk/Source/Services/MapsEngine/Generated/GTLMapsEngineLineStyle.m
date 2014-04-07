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
//  GTLMapsEngineLineStyle.m
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
//   GTLMapsEngineLineStyle (0 custom class methods, 4 custom properties)
//   GTLMapsEngineLineStyleStroke (0 custom class methods, 3 custom properties)

#import "GTLMapsEngineLineStyle.h"

#import "GTLMapsEngineBorder.h"
#import "GTLMapsEngineLabelStyle.h"

// ----------------------------------------------------------------------------
//
//   GTLMapsEngineLineStyle
//

@implementation GTLMapsEngineLineStyle
@dynamic border, dash, label, stroke;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[NSNumber class]
                                forKey:@"dash"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLMapsEngineLineStyleStroke
//

@implementation GTLMapsEngineLineStyleStroke
@dynamic color, opacity, width;
@end
