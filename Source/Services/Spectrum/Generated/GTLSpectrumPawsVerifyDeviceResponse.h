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
//  GTLSpectrumPawsVerifyDeviceResponse.h
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
//   GTLSpectrumPawsVerifyDeviceResponse (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSpectrumDbUpdateSpec;
@class GTLSpectrumDeviceValidity;

// ----------------------------------------------------------------------------
//
//   GTLSpectrumPawsVerifyDeviceResponse
//

// The device validation response message.

@interface GTLSpectrumPawsVerifyDeviceResponse : GTLObject

// A database may include the databaseChange parameter to notify a device of a
// change to its database URI, providing one or more alternate database URIs.
// The device should use this information to update its list of pre-configured
// databases by (only) replacing its entry for the responding database with the
// list of alternate URIs.
@property (nonatomic, retain) GTLSpectrumDbUpdateSpec *databaseChange;

// A device validities list is required in the device validation response to
// report whether each slave device listed in a previous device validation
// request is valid. The number of entries must match the number of device
// descriptors listed in the previous device validation request.
@property (nonatomic, retain) NSArray *deviceValidities;  // of GTLSpectrumDeviceValidity

// Identifies what kind of resource this is. Value: the fixed string
// "spectrum#pawsVerifyDeviceResponse".
@property (nonatomic, copy) NSString *kind;

// The message type (e.g., INIT_REQ, AVAIL_SPECTRUM_REQ, ...).
// Required field.
@property (nonatomic, copy) NSString *type;

// The PAWS version. Must be exactly 1.0.
// Required field.
@property (nonatomic, copy) NSString *version;

@end
