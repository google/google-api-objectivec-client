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
//  GTLStorageObject.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Cloud Storage API (storage/v1beta1)
// Description:
//   Lets you store and retrieve potentially-large, immutable data objects.
// Documentation:
//   https://code.google.com/apis/storage/docs/developer-guide.html
// Classes:
//   GTLStorageObject (0 custom class methods, 12 custom properties)
//   GTLStorageObjectMedia (0 custom class methods, 7 custom properties)
//   GTLStorageObjectMetadata (0 custom class methods, 0 custom properties)
//   GTLStorageObjectOwner (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLStorageObjectAccessControl;
@class GTLStorageObjectMedia;
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

// Content-Disposition of the object data.
@property (copy) NSString *contentDisposition;

// Content-Encoding of the object data.
@property (copy) NSString *contentEncoding;

// The ID of the object.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The kind of item this is. For objects, this is always storage#object.
@property (copy) NSString *kind;

// Object media data. Provided on your behalf when uploading raw media or
// multipart/related with an auxiliary media part.
@property (retain) GTLStorageObjectMedia *media;

// User-provided metadata, in key/value pairs.
@property (retain) GTLStorageObjectMetadata *metadata;

// The name of this object. Required if not specified by URL parameter.
@property (copy) NSString *name;

// The owner of the object. This will always be the uploader of the object.
@property (retain) GTLStorageObjectOwner *owner;

// The link to this object.
@property (copy) NSString *selfLink;

@end


// ----------------------------------------------------------------------------
//
//   GTLStorageObjectMedia
//

@interface GTLStorageObjectMedia : GTLObject

// Hash algorithm used. Currently only MD5 is supported. Required if a hash is
// provided.
@property (copy) NSString *algorithm;

// Content-Type of the object data.
@property (copy) NSString *contentType;

// URL-safe Base64-encoded data. This property can be used to insert objects
// under 64KB in size, and will only be returned in response to the get method
// for objects so created. When this resource is returned in response to the
// list method, this property is omitted.
@property (copy) NSString *data;  // GTLBase64 can encode/decode (probably web-safe format)

// Hash of the data. Required if a hash algorithm is provided.
// Remapped to 'hashProperty' to avoid NSObject's 'hash'.
@property (copy) NSString *hashProperty;

// Content-Length of the data in bytes.
@property (retain) NSNumber *length;  // longLongValue

// Media download link.
@property (copy) NSString *link;

// Creation time of the data in RFC 3339 format.
@property (retain) GTLDateTime *timeCreated;

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
