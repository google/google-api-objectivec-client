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
//  GTLComputeImage.h
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
//   GTLComputeImage (0 custom class methods, 10 custom properties)
//   GTLComputeImageRawDisk (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLComputeDeprecationStatus;
@class GTLComputeImageRawDisk;

// ----------------------------------------------------------------------------
//
//   GTLComputeImage
//

// A disk image resource.

@interface GTLComputeImage : GTLObject

// Creation timestamp in RFC3339 text format (output only).
@property (copy) NSString *creationTimestamp;

// The deprecation status associated with this image.
@property (retain) GTLComputeDeprecationStatus *deprecated;

// Textual description of the resource; provided by the client when the resource
// is created.
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

// An optional URL of the preferred kernel for use with this disk image. If not
// specified, a server defined default kernel will be used.
@property (copy) NSString *preferredKernel;

// The raw disk image parameters.
@property (retain) GTLComputeImageRawDisk *rawDisk;

// Server defined URL for the resource (output only).
@property (copy) NSString *selfLink;

// Must be "RAW"; provided by the client when the disk image is created.
@property (copy) NSString *sourceType;

@end


// ----------------------------------------------------------------------------
//
//   GTLComputeImageRawDisk
//

@interface GTLComputeImageRawDisk : GTLObject

// The format used to encode and transmit the block device. Should be TAR. This
// is just a container and transmission format and not a runtime format.
// Provided by the client when the disk image is created.
@property (copy) NSString *containerType;

// An optional SHA1 checksum of the disk image before unpackaging; provided by
// the client when the disk image is created.
@property (copy) NSString *sha1Checksum;

// The full Google Cloud Storage URL where the disk image is stored; provided by
// the client when the disk image is created.
@property (copy) NSString *source;

@end
