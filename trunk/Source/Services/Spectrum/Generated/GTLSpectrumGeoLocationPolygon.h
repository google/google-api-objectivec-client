/* Copyright (c) 2013 Google Inc.
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
//  GTLSpectrumGeoLocationPolygon.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Spectrum Database API (spectrum/v1explorer)
// Description:
//   API for spectrum-management functions.
// Documentation:
//   http://developers.google.com/spectrum
// Classes:
//   GTLSpectrumGeoLocationPolygon (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSpectrumGeoLocationPoint;

// ----------------------------------------------------------------------------
//
//   GTLSpectrumGeoLocationPolygon
//

// A region is represented using the polygonal shape.

@interface GTLSpectrumGeoLocationPolygon : GTLObject

// When the geolocation describes a region, the exterior field refers to a list
// of latitude/longitude points that represent the vertices of a polygon. The
// first and last points must be the same. Thus, a minimum of four points is
// required. The following polygon restrictions from RFC5491 apply:
// - A connecting line shall not cross another connecting line of the same
// polygon.
// - The vertices must be defined in a counterclockwise order.
// - The edges of a polygon are defined by the shortest path between two points
// in space (not a geodesic curve). Consequently, the length between two
// adjacent vertices should be restricted to a maximum of 130 km.
// - All vertices are assumed to be at the same altitude.
// - Polygon shapes should be restricted to a maximum of 15 vertices (16 points
// that include the repeated vertex).
@property (retain) NSArray *exterior;  // of GTLSpectrumGeoLocationPoint

@end
