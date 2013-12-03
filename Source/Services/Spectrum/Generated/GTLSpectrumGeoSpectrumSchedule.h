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
//  GTLSpectrumGeoSpectrumSchedule.h
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
//   GTLSpectrumGeoSpectrumSchedule (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSpectrumGeoLocation;
@class GTLSpectrumSchedule;

// ----------------------------------------------------------------------------
//
//   GTLSpectrumGeoSpectrumSchedule
//

// The schedule of spectrum profiles available at a particular geolocation.

@interface GTLSpectrumGeoSpectrumSchedule : GTLObject

// The geolocation identifies the location at which the spectrum schedule
// applies. It will always be present.
@property (retain) GTLSpectrumGeoLocation *location;

// A list of available spectrum profiles and associated times. It will always be
// present, and at least one schedule must be included (though it may be empty
// if there is no available spectrum). More than one schedule may be included to
// represent future changes to the available spectrum.
@property (retain) NSArray *spectrumSchedules;  // of GTLSpectrumSchedule

@end
