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
//  GTLSpectrumGeoLocationPoint.h
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
//   GTLSpectrumGeoLocationPoint (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLSpectrumGeoLocationPoint
//

// A single geolocation on the globe.

@interface GTLSpectrumGeoLocationPoint : GTLObject

// A required floating-point number that expresses the latitude in degrees using
// the WGS84 datum. For details on this encoding, see the National Imagery and
// Mapping Agency's Technical Report TR8350.2.
@property (retain) NSNumber *latitude;  // doubleValue

// A required floating-point number that expresses the longitude in degrees
// using the WGS84 datum. For details on this encoding, see the National Imagery
// and Mapping Agency's Technical Report TR8350.2.
@property (retain) NSNumber *longitude;  // doubleValue

@end
