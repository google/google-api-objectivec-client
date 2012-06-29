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
//  GTLStorageBucket.h
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
//   GTLStorageBucket (0 custom class methods, 10 custom properties)
//   GTLStorageBucketOwner (0 custom class methods, 2 custom properties)
//   GTLStorageBucketWebsite (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLStorageBucketAccessControl;
@class GTLStorageBucketOwner;
@class GTLStorageBucketWebsite;
@class GTLStorageObjectAccessControl;

// ----------------------------------------------------------------------------
//
//   GTLStorageBucket
//

// A bucket.

@interface GTLStorageBucket : GTLObject

// Access controls on the bucket.
@property (retain) NSArray *acl;  // of GTLStorageBucketAccessControl

// Default access controls to apply to new objects when no ACL is provided.
@property (retain) NSArray *defaultObjectAcl;  // of GTLStorageObjectAccessControl

// The name of the bucket.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The kind of item this is. For buckets, this is always storage#bucket.
@property (copy) NSString *kind;

// The location of the bucket. Object data for objects in the bucket resides in
// physical storage in this location. Can be US or EU. Defaults to US.
@property (copy) NSString *location;

// The owner of the bucket. This will always be the project team's owner group.
@property (retain) GTLStorageBucketOwner *owner;

// The project the bucket belongs to.
@property (retain) NSNumber *projectId;  // unsignedLongLongValue

// The URI of this bucket.
@property (copy) NSString *selfLink;

// Creation time of the bucket in RFC 3339 format.
@property (retain) GTLDateTime *timeCreated;

// The bucket's website configuration.
@property (retain) GTLStorageBucketWebsite *website;

@end


// ----------------------------------------------------------------------------
//
//   GTLStorageBucketOwner
//

@interface GTLStorageBucketOwner : GTLObject

// The entity, in the form group-groupId.
@property (copy) NSString *entity;

// The ID for the entity.
@property (copy) NSString *entityId;

@end


// ----------------------------------------------------------------------------
//
//   GTLStorageBucketWebsite
//

@interface GTLStorageBucketWebsite : GTLObject

// Behaves as the bucket's directory index where missing objects are treated as
// potential directories.
@property (copy) NSString *mainPageSuffix;

// The custom object to return when a requested resource is not found.
@property (copy) NSString *notFoundPage;

@end
