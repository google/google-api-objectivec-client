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
//  GTLComputeAttachedDisk.h
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
//   GTLComputeAttachedDisk (0 custom class methods, 7 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLComputeAttachedDisk
//

@interface GTLComputeAttachedDisk : GTLObject

// Persistent disk only; If true, delete the disk and all its data when the
// associated instance is deleted. This property defaults to false if not
// specified.
@property (retain) NSNumber *deleteOnTerminate;  // boolValue

// Persistent disk only; must be unique within the instance when specified. This
// represents a unique device name that is reflected into the /dev/ tree of a
// Linux operating system running within the instance. If not specified, a
// default will be chosen by the system.
@property (copy) NSString *deviceName;

// A zero-based index to assign to this disk, where 0 is reserved for the boot
// disk. If not specified, the server will choose an appropriate value.
@property (retain) NSNumber *index;  // intValue

// Type of the resource.
@property (copy) NSString *kind;

// The mode in which to attach this disk, either "READ_WRITE" or "READ_ONLY".
@property (copy) NSString *mode;

// Persistent disk only; the URL of the persistent disk resource.
@property (copy) NSString *source;

// Type of the disk, either "EPHEMERAL" or "PERSISTENT". Note that persistent
// disks must be created before you can specify them here.
@property (copy) NSString *type;

@end
