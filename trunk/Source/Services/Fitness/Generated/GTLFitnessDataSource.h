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
//  GTLFitnessDataSource.h
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
//   GTLFitnessDataSource (0 custom class methods, 7 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLFitnessApplication;
@class GTLFitnessDataType;
@class GTLFitnessDevice;

// ----------------------------------------------------------------------------
//
//   GTLFitnessDataSource
//

// Definition of a unique source of sensor data. Data sources can expose raw
// data coming from hardware sensors on local or companion devices. They can
// also expose derived data, created by transforming or merging other data
// sources. Multiple data sources can exist for the same data type. Every data
// point inserted into or read from this service has an associated data source.
// The data source contains enough information to uniquely identify its data,
// including the hardware device and the application that collected and/or
// transformed the data. It also holds useful metadata, such as the hardware and
// application versions, and the device type.
// Each data source produces a unique stream of data, with a unique identifier.
// Not all changes to data source affect the stream identifier, so that data
// collected by updated versions of the same application/device can still be
// considered to belong to the same data stream.

@interface GTLFitnessDataSource : GTLObject

// Information about an application which feeds sensor data into the platform.
@property (nonatomic, retain) GTLFitnessApplication *application;

// A unique identifier for the data stream produced by this data source. The
// identifier includes:
// - The physical device's manufacturer, model, and serial number (UID).
// - The application's package name or name. Package name is used when the data
// source was created by an Android application. The developer project number is
// used when the data source was created by a REST client.
// - The data source's type.
// - The data source's stream name. Note that not all attributes of the data
// source are used as part of the stream identifier. In particular, the version
// of the hardware/the application isn't used. This allows us to preserve the
// same stream through version updates. This also means that two DataSource
// objects may represent the same data stream even if they're not equal.
// The exact format of the data stream ID created by an Android application is:
// type:dataType.name:application.packageName:device.manufacturer:device.model:device.uid:dataStreamName
// The exact format of the data stream ID created by a REST client is:
// type:dataType.name:developer project
// number:device.manufacturer:device.model:device.uid:dataStreamName
// When any of the optional fields that comprise of the data stream ID are
// blank, they will be omitted from the data stream ID. The minnimum viable data
// stream ID would be: type:dataType.name:developer project number
// Finally, the developer project number is obfuscated when read by any REST or
// Android client that did not create the data source. Only the data source
// creator will see the developer project number in clear and normal form.
@property (nonatomic, copy) NSString *dataStreamId;

// The stream name uniquely identifies this particular data source among other
// data sources of the same type from the same underlying producer. Setting the
// stream name is optional, but should be done whenever an application exposes
// two streams for the same data type, or when a device has two equivalent
// sensors.
@property (nonatomic, copy) NSString *dataStreamName;

// The data type defines the schema for a stream of data being collected by,
// inserted into, or queried from the Fitness API.
@property (nonatomic, retain) GTLFitnessDataType *dataType;

// Representation of an integrated device (such as a phone or a wearable) that
// can hold sensors.
@property (nonatomic, retain) GTLFitnessDevice *device;

// An end-user visible name for this data source.
@property (nonatomic, copy) NSString *name;

// A constant describing the type of this data source. Indicates whether this
// data source produces raw or derived data.
@property (nonatomic, copy) NSString *type;

@end
