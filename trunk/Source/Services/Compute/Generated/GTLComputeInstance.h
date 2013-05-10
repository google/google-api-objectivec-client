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
//  GTLComputeInstance.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Compute Engine API (compute/v1beta14)
// Description:
//   API for the Google Compute Engine service.
// Documentation:
//   https://developers.google.com/compute/docs/reference/v1beta14
// Classes:
//   GTLComputeInstance (0 custom class methods, 18 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLComputeAttachedDisk;
@class GTLComputeMetadata;
@class GTLComputeNetworkInterface;
@class GTLComputeServiceAccount;
@class GTLComputeTags;

// ----------------------------------------------------------------------------
//
//   GTLComputeInstance
//

// An instance resource.

@interface GTLComputeInstance : GTLObject

// Reserved for future use.
@property (retain) NSNumber *canIpForward;  // boolValue

// Creation timestamp in RFC3339 text format (output only).
@property (copy) NSString *creationTimestamp;

// An optional textual description of the resource; provided by the client when
// the resource is created.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Array of disks associated with this instance. Persistent disks must be
// created before you can assign them.
@property (retain) NSArray *disks;  // of GTLComputeAttachedDisk

// Unique identifier for the resource; defined by the server (output only).
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSNumber *identifier;  // unsignedLongLongValue

// An optional URL of the disk image resource to be installed on this instance;
// provided by the client when the instance is created. Alternatively to passing
// the image, the client may choose to boot from a persistent disk, by setting
// boot=true flag on one of the entries in disks[] collection.
@property (copy) NSString *image;

// URL of the kernel resource to use when booting. In case of booting from
// persistent disk, this parameter is required. When booting from a disk image,
// it is optional, but may be provided to use a different kernel than the one
// associated with the image.
@property (copy) NSString *kernel;

// Type of the resource.
@property (copy) NSString *kind;

// URL of the machine type resource describing which machine type to use to host
// the instance; provided by the client when the instance is created.
@property (copy) NSString *machineType;

// Metadata key/value pairs assigned to this instance. Consists of custom
// metadata or predefined keys; see Instance documentation for more information.
@property (retain) GTLComputeMetadata *metadata;

// Name of the resource; provided by the client when the resource is created.
// The name must be 1-63 characters long, and comply with RFC1035.
@property (copy) NSString *name;

// Array of configurations for this interface. This specifies how this interface
// is configured to interact with other network services, such as connecting to
// the internet. Currently, ONE_TO_ONE_NAT is the only access config supported.
// If there are no accessConfigs specified, then this instance will have no
// external internet access.
@property (retain) NSArray *networkInterfaces;  // of GTLComputeNetworkInterface

// Server defined URL for this resource (output only).
@property (copy) NSString *selfLink;

// A list of service accounts each with specified scopes, for which access
// tokens are to be made available to the instance through metadata queries.
@property (retain) NSArray *serviceAccounts;  // of GTLComputeServiceAccount

// Instance status. One of the following values: "PROVISIONING", "STAGING",
// "RUNNING", "STOPPING", "STOPPED", "TERMINATED" (output only).
@property (copy) NSString *status;

// An optional, human-readable explanation of the status (output only).
@property (copy) NSString *statusMessage;

// A list of tags to be applied to this instance. Used to identify valid sources
// or targets for network firewalls. Provided by the client on instance
// creation. The tags can be later modified by the setTags method. Each tag
// within the list must comply with RFC1035.
@property (retain) GTLComputeTags *tags;

// URL of the zone where the instance resides (output only).
// Remapped to 'zoneProperty' to avoid NSObject's 'zone'.
@property (copy) NSString *zoneProperty;

@end
