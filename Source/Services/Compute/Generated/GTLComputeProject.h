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
//  GTLComputeProject.h
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
//   GTLComputeProject (0 custom class methods, 9 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLComputeMetadata;
@class GTLComputeQuota;

// ----------------------------------------------------------------------------
//
//   GTLComputeProject
//

// A project resource. Projects can be created only in the APIs Console. Unless
// marked otherwise, values can only be modified in the console.

@interface GTLComputeProject : GTLObject

// Metadata key/value pairs available to all instances contained in this
// project.
@property (retain) GTLComputeMetadata *commonInstanceMetadata;

// Creation timestamp in RFC3339 text format (output only).
@property (copy) NSString *creationTimestamp;

// An optional textual description of the resource.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Internet available IP addresses available for use in this project.
@property (retain) NSArray *externalIpAddresses;  // of NSString

// Unique identifier for the resource; defined by the server (output only).
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSNumber *identifier;  // unsignedLongLongValue

// Type of the resource.
@property (copy) NSString *kind;

// Name of the resource.
@property (copy) NSString *name;

// Quotas assigned to this project.
@property (retain) NSArray *quotas;  // of GTLComputeQuota

// Server defined URL for the resource (output only).
@property (copy) NSString *selfLink;

@end
