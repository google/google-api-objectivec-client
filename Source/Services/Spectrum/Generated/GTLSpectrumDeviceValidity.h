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
//  GTLSpectrumDeviceValidity.h
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
//   GTLSpectrumDeviceValidity (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSpectrumDeviceDescriptor;

// ----------------------------------------------------------------------------
//
//   GTLSpectrumDeviceValidity
//

// The device validity element describes whether a particular device is valid to
// operate in the regulatory domain.

@interface GTLSpectrumDeviceValidity : GTLObject

// The descriptor of the device for which the validity check was requested. It
// will always be present.
@property (nonatomic, retain) GTLSpectrumDeviceDescriptor *deviceDesc;

// The validity status: true if the device is valid for operation, false
// otherwise. It will always be present.
@property (nonatomic, retain) NSNumber *isValid;  // boolValue

// If the device identifier is not valid, the database may include a reason. The
// reason may be in any language. The length of the value should not exceed 128
// characters.
@property (nonatomic, copy) NSString *reason;

@end
