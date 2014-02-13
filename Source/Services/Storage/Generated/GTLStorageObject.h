/* Copyright (c) 2014 Google Inc.
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
//  GTLStorageObject.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Cloud Storage API (storage/v1beta2)
// Description:
//   Lets you store and retrieve potentially-large, immutable data objects.
// Documentation:
//   https://developers.google.com/storage/docs/json_api/
// Classes:
//   GTLStorageObject (0 custom class methods, 23 custom properties)
//   GTLStorageObjectMetadata (0 custom class methods, 0 custom properties)
//   GTLStorageObjectOwner (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLStorageObjectAccessControl;
@class GTLStorageObjectMetadata;
@class GTLStorageObjectOwner;

// ----------------------------------------------------------------------------
//
//   GTLStorageObject
//

// An object.

@interface GTLStorageObject : GTLObject

// Access controls on the object.
@property (retain) NSArray *acl;  // of GTLStorageObjectAccessControl

// The bucket containing this object.
@property (copy) NSString *bucket;

// Cache-Control directive for the object data.
@property (copy) NSString *cacheControl;

// Number of underlying components that make up this object. Components are
// accumulated by compose operations and are limited to a count of 32.
@property (retain) NSNumber *componentCount;  // intValue

// Content-Disposition of the object data.
@property (copy) NSString *contentDisposition;

// Content-Encoding of the object data.
@property (copy) NSString *contentEncoding;

// Content-Language of the object data.
@property (copy) NSString *contentLanguage;

// Content-Type of the object data.
@property (copy) NSString *contentType;

// CRC32c checksum, as described in RFC 4960, Appendix B; encoded using base64.
@property (copy) NSString *crc32c;

// HTTP 1.1 Entity tag for the object.
@property (copy) NSString *ETag;

// The content generation of this object. Used for object versioning.
@property (retain) NSNumber *generation;  // longLongValue

// The ID of the object.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The kind of item this is. For objects, this is always storage#object.
@property (copy) NSString *kind;

// MD5 hash of the data; encoded using base64.
@property (copy) NSString *md5Hash;

// Media download link.
@property (copy) NSString *mediaLink;

// User-provided metadata, in key/value pairs.
@property (retain) GTLStorageObjectMetadata *metadata;

// The generation of the metadata for this object at this generation. Used for
// metadata versioning. Has no meaning outside of the context of this
// generation.
@property (retain) NSNumber *metageneration;  // longLongValue

// The name of this object. Required if not specified by URL parameter.
@property (copy) NSString *name;

// The owner of the object. This will always be the uploader of the object.
@property (retain) GTLStorageObjectOwner *owner;

// The link to this object.
@property (copy) NSString *selfLink;

// Content-Length of the data in bytes.
@property (retain) NSNumber *size;  // unsignedLongLongValue

// Deletion time of the object in RFC 3339 format. Will be returned if and only
// if this version of the object has been deleted.
@property (retain) GTLDateTime *timeDeleted;

// Modification time of the object metadata in RFC 3339 format.
@property (retain) GTLDateTime *updated;

@end


// ----------------------------------------------------------------------------
//
//   GTLStorageObjectMetadata
//

@interface GTLStorageObjectMetadata : GTLObject
// This object is documented as having more properties that are NSString. Use
// -additionalJSONKeys and -additionalPropertyForName: to get the list of
// properties and then fetch them; or -additionalProperties to fetch them all at
// once.
@end


// ----------------------------------------------------------------------------
//
//   GTLStorageObjectOwner
//

@interface GTLStorageObjectOwner : GTLObject

// The entity, in the form user-userId.
@property (copy) NSString *entity;

// The ID for the entity.
@property (copy) NSString *entityId;

@end
