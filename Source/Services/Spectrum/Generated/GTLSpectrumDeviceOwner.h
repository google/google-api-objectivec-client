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
//  GTLSpectrumDeviceOwner.h
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
//   GTLSpectrumDeviceOwner (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSpectrumVcard;

// ----------------------------------------------------------------------------
//
//   GTLSpectrumDeviceOwner
//

// This parameter contains device-owner information required as part of device
// registration. The regulatory domains may require additional parameters.
// All contact information must be expressed using the structure defined by the
// vCard format specification. Only the contact fields of vCard are supported:
// - fn: Full name of an individual
// - org: Name of the organization
// - adr: Address fields
// - tel: Telephone numbers
// - email: Email addresses
// Note that the vCard specification defines maximum lengths for each field.

@interface GTLSpectrumDeviceOwner : GTLObject

// The vCard contact information for the device operator is optional, but may be
// required by specific regulatory domains.
// Remapped to 'operatorProperty' to avoid language reserved word 'operator'.
@property (nonatomic, retain) GTLSpectrumVcard *operatorProperty;

// The vCard contact information for the individual or business that owns the
// device is required.
@property (nonatomic, retain) GTLSpectrumVcard *owner;

@end
