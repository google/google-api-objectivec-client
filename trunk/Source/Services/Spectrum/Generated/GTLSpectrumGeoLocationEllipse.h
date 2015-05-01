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
//  GTLSpectrumGeoLocationEllipse.h
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
//   GTLSpectrumGeoLocationEllipse (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSpectrumGeoLocationPoint;

// ----------------------------------------------------------------------------
//
//   GTLSpectrumGeoLocationEllipse
//

// A "point" with uncertainty is represented using the Ellipse shape.

@interface GTLSpectrumGeoLocationEllipse : GTLObject

// A required geo-spatial point representing the center of the ellipse.
@property (nonatomic, retain) GTLSpectrumGeoLocationPoint *center;

// A floating-point number that expresses the orientation of the ellipse,
// representing the rotation, in degrees, of the semi-major axis from North
// towards the East. For example, when the uncertainty is greatest along the
// North-South direction, orientation is 0 degrees; conversely, if the
// uncertainty is greatest along the East-West direction, orientation is 90
// degrees. When orientation is not present, the orientation is assumed to be 0.
@property (nonatomic, retain) NSNumber *orientation;  // doubleValue

// A floating-point number that expresses the location uncertainty along the
// major axis of the ellipse. May be required by the regulatory domain. When the
// uncertainty is optional, the default value is 0.
@property (nonatomic, retain) NSNumber *semiMajorAxis;  // doubleValue

// A floating-point number that expresses the location uncertainty along the
// minor axis of the ellipse. May be required by the regulatory domain. When the
// uncertainty is optional, the default value is 0.
@property (nonatomic, retain) NSNumber *semiMinorAxis;  // doubleValue

@end
