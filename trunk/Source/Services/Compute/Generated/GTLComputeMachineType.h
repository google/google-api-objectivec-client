/* Copyright (c) 2012 Google Inc.
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
//  GTLComputeMachineType.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Compute Engine API (compute/v1beta12)
// Description:
//   API for the Google Compute Engine service.
// Documentation:
//   https://developers.google.com/compute/docs/reference/v1beta12
// Classes:
//   GTLComputeMachineType (0 custom class methods, 14 custom properties)
//   GTLComputeMachineTypeEphemeralDisksItem (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLComputeMachineTypeEphemeralDisksItem;

// ----------------------------------------------------------------------------
//
//   GTLComputeMachineType
//

@interface GTLComputeMachineType : GTLObject

// The zones that this machine type can run in.
@property (retain) NSArray *availableZone;  // of any JSON type

// Creation timestamp in RFC3339 text format (output only).
@property (copy) NSString *creationTimestamp;

// An optional textual description of the resource.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// List of extended ephemeral disks assigned to the instance.
@property (retain) NSArray *ephemeralDisks;  // of GTLComputeMachineTypeEphemeralDisksItem

// Count of CPUs exposed to the instance.
@property (retain) NSNumber *guestCpus;  // intValue

// Count of physical CPUs reserved on the virtual machine host.
@property (retain) NSNumber *hostCpus;  // intValue

// Unique identifier for the resource; defined by the server (output only).
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSNumber *identifier;  // unsignedLongLongValue

// Space allotted for the image, defined in GB.
@property (retain) NSNumber *imageSpaceGb;  // intValue

// Type of the resource.
@property (copy) NSString *kind;

// Maximum persistent disks allowed.
@property (retain) NSNumber *maximumPersistentDisks;  // intValue

// Maximum total persistent disks size (GB) allowed.
@property (retain) NSNumber *maximumPersistentDisksSizeGb;  // longLongValue

// Physical memory assigned to the instance, defined in MB.
@property (retain) NSNumber *memoryMb;  // intValue

// Name of the resource.
@property (copy) NSString *name;

// Server defined URL for the resource (output only).
@property (copy) NSString *selfLink;

@end


// ----------------------------------------------------------------------------
//
//   GTLComputeMachineTypeEphemeralDisksItem
//

@interface GTLComputeMachineTypeEphemeralDisksItem : GTLObject

// Size of the ephemeral disk, defined in GB.
@property (retain) NSNumber *diskGb;  // intValue

@end
