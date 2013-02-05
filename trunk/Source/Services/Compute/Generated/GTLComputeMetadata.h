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
//  GTLComputeMetadata.h
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
//   GTLComputeMetadata (0 custom class methods, 3 custom properties)
//   GTLComputeMetadataItemsItem (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLComputeMetadataItemsItem;

// ----------------------------------------------------------------------------
//
//   GTLComputeMetadata
//

// A metadata key/value entry.

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLComputeMetadata : GTLCollectionObject

// Fingerprint of this resource. A hash of the metadata's contents. This field
// is used for optimistic locking. An up-to-date metadata fingerprint must be
// provided in order to modify metadata.
@property (copy) NSString *fingerprint;  // GTLBase64 can encode/decode (probably web-safe format)

// Array of key/value pairs. The total size of all keys and values must be less
// than 512 KB.
@property (retain) NSArray *items;  // of GTLComputeMetadataItemsItem

// Type of the resource.
@property (copy) NSString *kind;

@end


// ----------------------------------------------------------------------------
//
//   GTLComputeMetadataItemsItem
//

@interface GTLComputeMetadataItemsItem : GTLObject

// Key for the metadata entry. Keys must conform to the following regexp:
// [a-zA-Z0-9-_]+, and be less than 128 bytes in length. This is reflected as
// part of a URL in the metadata server. Additionally, to avoid ambiguity, keys
// must not conflict with any other metadata keys for the project.
@property (copy) NSString *key;

// Value for the metadata entry. These are free-form strings, and only have
// meaning as interpreted by the image running in the instance. The only
// restriction placed on values is that their size must be less than or equal to
// 32768 bytes.
@property (copy) NSString *value;

@end
