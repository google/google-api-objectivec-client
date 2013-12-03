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
//  GTLSpectrumDeviceDescriptor.h
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
//   GTLSpectrumDeviceDescriptor (0 custom class methods, 10 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLSpectrumDeviceDescriptor
//

// The device descriptor contains parameters that identify the specific device,
// such as its manufacturer serial number, regulatory-specific identifier (e.g.,
// FCC ID), and any other device characteristics required by regulatory domains.

@interface GTLSpectrumDeviceDescriptor : GTLObject

// Specifies the ETSI white space device category. Valid values are the strings
// master and slave. This field is case-insensitive. Consult the ETSI
// documentation for details about the device types.
@property (copy) NSString *etsiEnDeviceCategory;

// Specifies the ETSI white space device emissions class. The values are
// represented by numeric strings, such as 1, 2, etc. Consult the ETSI
// documentation for details about the device types.
@property (copy) NSString *etsiEnDeviceEmissionsClass;

// Specifies the ETSI white space device type. Valid values are single-letter
// strings, such as A, B, etc. Consult the ETSI documentation for details about
// the device types.
@property (copy) NSString *etsiEnDeviceType;

// Specifies the ETSI white space device technology identifier. The string value
// must not exceed 64 characters in length. Consult the ETSI documentation for
// details about the device types.
@property (copy) NSString *etsiEnTechnologyId;

// Specifies the device's FCC certification identifier. The value is an
// identifier string whose length should not exceed 32 characters. Note that, in
// practice, a valid FCC ID may be limited to 19 characters.
@property (copy) NSString *fccId;

// Specifies the TV Band White Space device type, as defined by the FCC. Valid
// values are FIXED, MODE_1, MODE_2.
@property (copy) NSString *fccTvbdDeviceType;

// The manufacturer's ID may be required by the regulatory domain. This should
// represent the name of the device manufacturer, should be consistent across
// all devices from the same manufacturer, and should be distinct from that of
// other manufacturers. The string value must not exceed 64 characters in
// length.
@property (copy) NSString *manufacturerId;

// The device's model ID may be required by the regulatory domain. The string
// value must not exceed 64 characters in length.
@property (copy) NSString *modelId;

// The list of identifiers for rulesets supported by the device. A database may
// require that the device provide this list before servicing the device
// requests. If the database does not support any of the rulesets specified in
// the list, the database may refuse to service the device requests. If present,
// the list must contain at least one entry.
// For information about the valid requests, see section 9.2 of the PAWS
// specification. Currently, FccTvBandWhiteSpace-2010 is the only supported
// ruleset.
@property (retain) NSArray *rulesetIds;  // of NSString

// The manufacturer's device serial number; required by the applicable
// regulatory domain. The length of the value must not exceed 64 characters.
@property (copy) NSString *serialNumber;

@end
