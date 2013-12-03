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
//  GTLSpectrumFrequencyRange.h
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
//   GTLSpectrumFrequencyRange (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLSpectrumFrequencyRange
//

// A specific range of frequencies together with the associated maximum power
// level and channel identifier.

@interface GTLSpectrumFrequencyRange : GTLObject

// The database may include a channel identifier, when applicable. When it is
// included, the device should treat it as informative. The length of the
// identifier should not exceed 16 characters.
@property (copy) NSString *channelId;

// The maximum total power level (EIRP)—computed over the corresponding
// operating bandwidth—that is permitted within the frequency range. Depending
// on the context in which the frequency-range element appears, this value may
// be required. For example, it is required in the available-spectrum response,
// available-spectrum-batch response, and spectrum-use notification message, but
// it should not be present (it is not applicable) when the frequency range
// appears inside a device-capabilities message.
@property (retain) NSNumber *maxPowerDBm;  // doubleValue

// The required inclusive start of the frequency range (in Hertz).
@property (retain) NSNumber *startHz;  // doubleValue

// The required exclusive end of the frequency range (in Hertz).
@property (retain) NSNumber *stopHz;  // doubleValue

@end
