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
//  GTLSpectrumDeviceCapabilities.h
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
//   GTLSpectrumDeviceCapabilities (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSpectrumFrequencyRange;

// ----------------------------------------------------------------------------
//
//   GTLSpectrumDeviceCapabilities
//

// Device capabilities provide additional information that may be used by a
// device to provide additional information to the database that may help it to
// determine available spectrum. If the database does not support device
// capabilities it will ignore the parameter altogether.

@interface GTLSpectrumDeviceCapabilities : GTLObject

// An optional list of frequency ranges supported by the device. Each element
// must contain start and stop frequencies in which the device can operate.
// Channel identifiers are optional. When specified, the database should not
// return available spectrum that falls outside these ranges or channel IDs.
@property (nonatomic, retain) NSArray *frequencyRanges;  // of GTLSpectrumFrequencyRange

@end
