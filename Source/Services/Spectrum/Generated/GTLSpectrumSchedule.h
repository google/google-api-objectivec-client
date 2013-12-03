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
//  GTLSpectrumSchedule.h
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
//   GTLSpectrumSchedule (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSpectrumEventTime;
@class GTLSpectrumMessage;

// ----------------------------------------------------------------------------
//
//   GTLSpectrumSchedule
//

// The spectrum schedule element combines an event time with spectrum profile to
// define a time period in which the profile is valid.

@interface GTLSpectrumSchedule : GTLObject

// The event time expresses when the spectrum profile is valid. It will always
// be present.
@property (retain) GTLSpectrumEventTime *eventTime;

// A list of spectrum messages representing the usable profile. It will always
// be present, but may be empty when there is no available spectrum.
@property (retain) NSArray *spectra;  // of GTLSpectrumMessage

@end
