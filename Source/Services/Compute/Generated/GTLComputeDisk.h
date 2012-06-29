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
//  GTLComputeDisk.h
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
//   GTLComputeDisk (0 custom class methods, 12 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLComputeDisk
//

@interface GTLComputeDisk : GTLObject

// Creation timestamp in RFC3339 text format (output only).
@property (copy) NSString *creationTimestamp;

// An optional textual description of the resource; provided by the client when
// the resource is created.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Unique identifier for the resource; defined by the server (output only).
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSNumber *identifier;  // unsignedLongLongValue

// Type of the resource.
@property (copy) NSString *kind;

// Name of the resource; provided by the client when the resource is created.
// The name must be 1-63 characters long, and comply with RFC1035.
@property (copy) NSString *name;

// Internal use only.
@property (copy) NSString *options;

// Server defined URL for the resource (output only).
@property (copy) NSString *selfLink;

// Size of the persistent disk, specified in GB.
@property (retain) NSNumber *sizeGb;  // longLongValue

// The source snapshot used to create this disk. Once the source snapshot has
// been deleted from the system, this field will be cleared, and will not be set
// even if a snapshot with the same name has been re-created.
@property (copy) NSString *sourceSnapshot;

// The 'id' value of the snapshot used to create this disk. This value may be
// used to determine whether the disk was created from the current or a previous
// instance of a given disk snapshot.
@property (copy) NSString *sourceSnapshotId;

// The status of disk creation.
@property (copy) NSString *status;

// URL for the zone where the persistent disk resides; provided by the client
// when the disk is created. A persistent disk must reside in the same zone as
// the instance to which it is attached.
// Remapped to 'zoneProperty' to avoid NSObject's 'zone'.
@property (copy) NSString *zoneProperty;

@end
