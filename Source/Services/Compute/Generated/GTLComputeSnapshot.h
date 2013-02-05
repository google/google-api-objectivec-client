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
//  GTLComputeSnapshot.h
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
//   GTLComputeSnapshot (0 custom class methods, 10 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLComputeSnapshot
//

// A persistent disk snapshot resource.

@interface GTLComputeSnapshot : GTLObject

// Creation timestamp in RFC3339 text format (output only).
@property (copy) NSString *creationTimestamp;

// An optional textual description of the resource; provided by the client when
// the resource is created.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Size of the persistent disk snapshot, specified in GB (output only).
@property (retain) NSNumber *diskSizeGb;  // longLongValue

// Unique identifier for the resource; defined by the server (output only).
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSNumber *identifier;  // unsignedLongLongValue

// Type of the resource.
@property (copy) NSString *kind;

// Name of the resource; provided by the client when the resource is created.
// The name must be 1-63 characters long, and comply with RFC1035.
@property (copy) NSString *name;

// Server defined URL for the resource (output only).
@property (copy) NSString *selfLink;

// The source disk used to create this snapshot. Once the source disk has been
// deleted from the system, this field will be cleared, and will not be set even
// if a disk with the same name has been re-created.
@property (copy) NSString *sourceDisk;

// The 'id' value of the disk used to create this snapshot. This value may be
// used to determine whether the snapshot was taken from the current or a
// previous instance of a given disk name.
@property (copy) NSString *sourceDiskId;

// The status of the persistent disk snapshot (output only).
@property (copy) NSString *status;

@end
