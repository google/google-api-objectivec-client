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
//  GTLSpectrumGeoLocation.h
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
//   GTLSpectrumGeoLocation (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSpectrumGeoLocationEllipse;
@class GTLSpectrumGeoLocationPolygon;

// ----------------------------------------------------------------------------
//
//   GTLSpectrumGeoLocation
//

// This parameter is used to specify the geolocation of the device.

@interface GTLSpectrumGeoLocation : GTLObject

// The location confidence level, as an integer percentage, may be required,
// depending on the regulatory domain. When the parameter is optional and not
// provided, its value is assumed to be 95. Valid values range from 0 to 99,
// since, in practice, 100-percent confidence is not achievable. The confidence
// value is meaningful only when geolocation refers to a point with uncertainty.
@property (nonatomic, retain) NSNumber *confidence;  // intValue

// If present, indicates that the geolocation represents a point. Paradoxically,
// a point is parameterized using an ellipse, where the center represents the
// location of the point and the distances along the major and minor axes
// represent the uncertainty. The uncertainty values may be required, depending
// on the regulatory domain.
@property (nonatomic, retain) GTLSpectrumGeoLocationEllipse *point;

// If present, indicates that the geolocation represents a region. Database
// support for regions is optional.
@property (nonatomic, retain) GTLSpectrumGeoLocationPolygon *region;

@end
