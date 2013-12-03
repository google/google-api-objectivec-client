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
//  GTLSpectrumMessage.h
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
//   GTLSpectrumMessage (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSpectrumFrequencyRange;

// ----------------------------------------------------------------------------
//
//   GTLSpectrumMessage
//

// Available spectrum can be logically characterized by a list of frequency
// ranges and permissible power levels for each range.

@interface GTLSpectrumMessage : GTLObject

// The bandwidth (in Hertz) for which permissible power levels are specified.
// For example, FCC regulation would require only one spectrum specification at
// 6MHz bandwidth, but Ofcom regulation would require two specifications, at
// 0.1MHz and 8MHz. This parameter may be empty if there is no available
// spectrum. It will be present otherwise.
@property (retain) NSNumber *bandwidth;  // doubleValue

// The list of frequency ranges and permissible power levels. The list may be
// empty if there is no available spectrum, otherwise it will be present.
@property (retain) NSArray *frequencyRanges;  // of GTLSpectrumFrequencyRange

@end
