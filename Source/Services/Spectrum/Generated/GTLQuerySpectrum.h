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
//  GTLQuerySpectrum.h
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
//   GTLQuerySpectrum (6 custom class methods, 14 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLSpectrumAntennaCharacteristics;
@class GTLSpectrumDeviceCapabilities;
@class GTLSpectrumDeviceDescriptor;
@class GTLSpectrumDeviceOwner;
@class GTLSpectrumGeoLocation;
@class GTLSpectrumMessage;

@interface GTLQuerySpectrum : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (nonatomic, copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (nonatomic, retain) GTLSpectrumAntennaCharacteristics *antenna;
@property (nonatomic, retain) GTLSpectrumDeviceCapabilities *capabilities;
@property (nonatomic, retain) GTLSpectrumDeviceDescriptor *deviceDesc;
@property (nonatomic, retain) NSArray *deviceDescs;  // of GTLSpectrumDeviceDescriptor
@property (nonatomic, retain) GTLSpectrumDeviceOwner *deviceOwner;
@property (nonatomic, retain) GTLSpectrumGeoLocation *location;
@property (nonatomic, retain) NSArray *locations;  // of GTLSpectrumGeoLocation
@property (nonatomic, retain) GTLSpectrumDeviceDescriptor *masterDeviceDesc;
@property (nonatomic, retain) GTLSpectrumDeviceOwner *owner;
@property (nonatomic, copy) NSString *requestType;
@property (nonatomic, retain) NSArray *spectra;  // of GTLSpectrumMessage
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *version;

#pragma mark -
#pragma mark "paws" methods
// These create a GTLQuerySpectrum object.

// Method: spectrum.paws.getSpectrum
// Requests information about the available spectrum for a device at a location.
// Requests from a fixed-mode device must include owner information so the
// device can be registered with the database.
//  Optional:
//   antenna: Depending on device type and regulatory domain, the
//     characteristics of the antenna may be required.
//   capabilities: The master device may include its device capabilities to
//     limit the available-spectrum response to the spectrum that is compatible
//     with its capabilities. The database should not return spectrum that is
//     incompatible with the specified capabilities.
//   deviceDesc: When the available spectrum request is made on behalf of a
//     specific device (a master or slave device), device descriptor information
//     for that device is required (in such cases, the requestType parameter
//     must be empty). When a requestType value is specified, device descriptor
//     information may be optional or required according to the rules of the
//     applicable regulatory domain.
//   location: The geolocation of the master device (a device with geolocation
//     capability that makes an available spectrum request) is required whether
//     the master device is making the request on its own behalf or on behalf of
//     a slave device (one without geolocation capability). The location must be
//     the location of the radiation center of the master device's antenna. To
//     support mobile devices, a regulatory domain may allow the anticipated
//     position of the master device to be given instead. If the location
//     specifies a region, rather than a point, the database may return an
//     UNIMPLEMENTED error code if it does not support query by region.
//   masterDeviceDesc: When an available spectrum request is made by the master
//     device (a device with geolocation capability) on behalf of a slave device
//     (a device without geolocation capability), the rules of the applicable
//     regulatory domain may require the master device to provide its own device
//     descriptor information (in addition to device descriptor information for
//     the slave device, which is provided in a separate parameter).
//   owner: Depending on device type and regulatory domain, device owner
//     information may be included in an available spectrum request. This allows
//     the device to register and get spectrum-availability information in a
//     single request.
//   requestType: The request type parameter is an optional parameter that can
//     be used to modify an available spectrum request, but its use depends on
//     applicable regulatory rules. It may be used, for example, to request
//     generic slave device parameters without having to specify the device
//     descriptor for a specific device. When the requestType parameter is
//     missing, the request is for a specific device (master or slave), and the
//     deviceDesc parameter for the device on whose behalf the request is made
//     is required.
//   type: The message type (e.g., INIT_REQ, AVAIL_SPECTRUM_REQ, ...).
//     Required field.
//   version: The PAWS version. Must be exactly 1.0.
//     Required field.
// Fetches a GTLSpectrumPawsGetSpectrumResponse.
+ (instancetype)queryForPawsGetSpectrum;

// Method: spectrum.paws.getSpectrumBatch
// The Google Spectrum Database does not support batch requests, so this method
// always yields an UNIMPLEMENTED error.
//  Optional:
//   antenna: Depending on device type and regulatory domain, antenna
//     characteristics may be required.
//   capabilities: The master device may include its device capabilities to
//     limit the available-spectrum batch response to the spectrum that is
//     compatible with its capabilities. The database should not return spectrum
//     that is incompatible with the specified capabilities.
//   deviceDesc: When the available spectrum request is made on behalf of a
//     specific device (a master or slave device), device descriptor information
//     for the device on whose behalf the request is made is required (in such
//     cases, the requestType parameter must be empty). When a requestType value
//     is specified, device descriptor information may be optional or required
//     according to the rules of the applicable regulatory domain.
//   locations: A geolocation list is required. This allows a device to specify
//     its current location plus additional anticipated locations when allowed
//     by the regulatory domain. At least one location must be included.
//     Geolocation must be given as the location of the radiation center of the
//     device's antenna. If a location specifies a region, rather than a point,
//     the database may return an UNIMPLEMENTED error if it does not support
//     query by region.
//     There is no upper limit on the number of locations included in a
//     available spectrum batch request, but the database may restrict the
//     number of locations it supports by returning a response with fewer
//     locations than specified in the batch request. Note that geolocations
//     must be those of the master device (a device with geolocation capability
//     that makes an available spectrum batch request), whether the master
//     device is making the request on its own behalf or on behalf of a slave
//     device (one without geolocation capability).
//   masterDeviceDesc: When an available spectrum batch request is made by the
//     master device (a device with geolocation capability) on behalf of a slave
//     device (a device without geolocation capability), the rules of the
//     applicable regulatory domain may require the master device to provide its
//     own device descriptor information (in addition to device descriptor
//     information for the slave device in a separate parameter).
//   owner: Depending on device type and regulatory domain, device owner
//     information may be included in an available spectrum batch request. This
//     allows the device to register and get spectrum-availability information
//     in a single request.
//   requestType: The request type parameter is an optional parameter that can
//     be used to modify an available spectrum batch request, but its use
//     depends on applicable regulatory rules. For example, It may be used to
//     request generic slave device parameters without having to specify the
//     device descriptor for a specific device. When the requestType parameter
//     is missing, the request is for a specific device (master or slave), and
//     the device descriptor parameter for the device on whose behalf the batch
//     request is made is required.
//   type: The message type (e.g., INIT_REQ, AVAIL_SPECTRUM_REQ, ...).
//     Required field.
//   version: The PAWS version. Must be exactly 1.0.
//     Required field.
// Fetches a GTLSpectrumPawsGetSpectrumBatchResponse.
+ (instancetype)queryForPawsGetSpectrumBatch;

// Method: spectrum.paws.init
// Initializes the connection between a white space device and the database.
//  Optional:
//   deviceDesc: The DeviceDescriptor parameter is required. If the database
//     does not support the device or any of the rulesets specified in the
//     device descriptor, it must return an UNSUPPORTED error code in the error
//     response.
//   location: A device's geolocation is required.
//   type: The message type (e.g., INIT_REQ, AVAIL_SPECTRUM_REQ, ...).
//     Required field.
//   version: The PAWS version. Must be exactly 1.0.
//     Required field.
// Fetches a GTLSpectrumPawsInitResponse.
+ (instancetype)queryForPawsInit;

// Method: spectrum.paws.notifySpectrumUse
// Notifies the database that the device has selected certain frequency ranges
// for transmission. Only to be invoked when required by the regulator. The
// Google Spectrum Database does not operate in domains that require
// notification, so this always yields an UNIMPLEMENTED error.
//  Optional:
//   deviceDesc: Device descriptor information is required in the spectrum-use
//     notification message.
//   location: The geolocation of the master device (the device that is sending
//     the spectrum-use notification) to the database is required in the
//     spectrum-use notification message.
//   spectra: A spectrum list is required in the spectrum-use notification. The
//     list specifies the spectrum that the device expects to use, which
//     includes frequency ranges and maximum power levels. The list may be empty
//     if the device decides not to use any of spectrum. For consistency, the
//     psdBandwidthHz value should match that from one of the spectrum elements
//     in the corresponding available spectrum response previously sent to the
//     device by the database. Note that maximum power levels in the spectrum
//     element must be expressed as power spectral density over the specified
//     psdBandwidthHz value. The actual bandwidth to be used (as computed from
//     the start and stop frequencies) may be different from the psdBandwidthHz
//     value. As an example, when regulatory rules express maximum power
//     spectral density in terms of maximum power over any 100 kHz band, then
//     the psdBandwidthHz value should be set to 100 kHz, even though the actual
//     bandwidth used can be 20 kHz.
//   type: The message type (e.g., INIT_REQ, AVAIL_SPECTRUM_REQ, ...).
//     Required field.
//   version: The PAWS version. Must be exactly 1.0.
//     Required field.
// Fetches a GTLSpectrumPawsNotifySpectrumUseResponse.
+ (instancetype)queryForPawsNotifySpectrumUse;

// Method: spectrum.paws.register
// The Google Spectrum Database implements registration in the getSpectrum
// method. As such this always returns an UNIMPLEMENTED error.
//  Optional:
//   antenna: Antenna characteristics, including its height and height type.
//   deviceDesc: A DeviceDescriptor is required.
//   deviceOwner: Device owner information is required.
//   location: A device's geolocation is required.
//   type: The message type (e.g., INIT_REQ, AVAIL_SPECTRUM_REQ, ...).
//     Required field.
//   version: The PAWS version. Must be exactly 1.0.
//     Required field.
// Fetches a GTLSpectrumPawsRegisterResponse.
+ (instancetype)queryForPawsRegister;

// Method: spectrum.paws.verifyDevice
// Validates a device for white space use in accordance with regulatory rules.
// The Google Spectrum Database does not support master/slave configurations, so
// this always yields an UNIMPLEMENTED error.
//  Optional:
//   deviceDescs: A list of device descriptors, which specifies the slave
//     devices to be validated, is required.
//   type: The message type (e.g., INIT_REQ, AVAIL_SPECTRUM_REQ, ...).
//     Required field.
//   version: The PAWS version. Must be exactly 1.0.
//     Required field.
// Fetches a GTLSpectrumPawsVerifyDeviceResponse.
+ (instancetype)queryForPawsVerifyDevice;

@end
