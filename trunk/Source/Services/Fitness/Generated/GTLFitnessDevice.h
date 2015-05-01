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
//  GTLFitnessDevice.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Fitness (fitness/v1)
// Description:
//   Google Fit API
// Documentation:
//   https://developers.google.com/fit/rest/
// Classes:
//   GTLFitnessDevice (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLFitnessDevice
//

// Representation of an integrated device (such as a phone or a wearable) that
// can hold sensors. Each sensor is exposed as a data source.
// The main purpose of the device information contained in this class is to
// identify the hardware of a particular data source. This can be useful in
// different ways, including:
// - Distinguishing two similar sensors on different devices (the step counter
// on two nexus 5 phones, for instance)
// - Display the source of data to the user (by using the device make / model)
// - Treat data differently depending on sensor type (accelerometers on a watch
// may give different patterns than those on a phone)
// - Build different analysis models for each device/version.

@interface GTLFitnessDevice : GTLObject

// Manufacturer of the product/hardware.
@property (nonatomic, copy) NSString *manufacturer;

// End-user visible model name for the device.
@property (nonatomic, copy) NSString *model;

// A constant representing the type of the device.
@property (nonatomic, copy) NSString *type;

// The serial number or other unique ID for the hardware. This field is
// obfuscated when read by any REST or Android client that did not create the
// data source. Only the data source creator will see the uid field in clear and
// normal form.
@property (nonatomic, copy) NSString *uid;

// Version string for the device hardware/software.
@property (nonatomic, copy) NSString *version;

@end
