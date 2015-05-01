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
//  GTLSpectrumAntennaCharacteristics.h
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
//   GTLSpectrumAntennaCharacteristics (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLSpectrumAntennaCharacteristics
//

// Antenna characteristics provide additional information, such as the antenna
// height, antenna type, etc. Whether antenna characteristics must be provided
// in a request depends on the device type and regulatory domain.

@interface GTLSpectrumAntennaCharacteristics : GTLObject

// The antenna height in meters. Whether the antenna height is required depends
// on the device type and the regulatory domain. Note that the height may be
// negative.
@property (nonatomic, retain) NSNumber *height;  // doubleValue

// If the height is required, then the height type (AGL for above ground level
// or AMSL for above mean sea level) is also required. The default is AGL.
@property (nonatomic, copy) NSString *heightType;

// The height uncertainty in meters. Whether this is required depends on the
// regulatory domain.
@property (nonatomic, retain) NSNumber *heightUncertainty;  // doubleValue

@end
