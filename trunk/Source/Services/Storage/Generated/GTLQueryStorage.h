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
//  GTLQueryStorage.h
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
//   GTLQueryStorage (24 custom class methods, 11 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLStorageBucket;
@class GTLStorageBucketAccessControl;
@class GTLStorageObject;
@class GTLStorageObjectAccessControl;

@interface GTLQueryStorage : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (copy) NSString *bucket;
@property (copy) NSString *delimiter;
@property (copy) NSString *entity;
@property (assign) NSUInteger maxResults;
@property (copy) NSString *name;
@property (copy) NSString *object;
@property (copy) NSString *pageToken;
@property (copy) NSString *prefix;
@property (assign) unsigned long long projectId;
@property (copy) NSString *projection;

#pragma mark -
#pragma mark "bucketAccessControls" methods
// These create a GTLQueryStorage object.

// Method: storage.bucketAccessControls.delete
// Deletes the ACL entry for the specified entity on the specified bucket.
//  Required:
//   bucket: Name of a bucket.
//   entity: The entity holding the permission. Can be user-userId,
//     group-groupId, allUsers, or allAuthenticatedUsers.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
+ (id)queryForBucketAccessControlsDeleteWithBucket:(NSString *)bucket
                                            entity:(NSString *)entity;

// Method: storage.bucketAccessControls.get
// Returns the ACL entry for the specified entity on the specified bucket.
//  Required:
//   bucket: Name of a bucket.
//   entity: The entity holding the permission. Can be user-userId,
//     group-groupId, allUsers, or allAuthenticatedUsers.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageBucketAccessControl.
+ (id)queryForBucketAccessControlsGetWithBucket:(NSString *)bucket
                                         entity:(NSString *)entity;

// Method: storage.bucketAccessControls.insert
// Creates a new ACL entry on the specified bucket.
//  Required:
//   bucket: Name of a bucket.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageBucketAccessControl.
+ (id)queryForBucketAccessControlsInsertWithObject:(GTLStorageBucketAccessControl *)object
                                            bucket:(NSString *)bucket;

// Method: storage.bucketAccessControls.list
// Retrieves ACL entries on the specified bucket.
//  Required:
//   bucket: Name of a bucket.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageBucketAccessControls.
+ (id)queryForBucketAccessControlsListWithBucket:(NSString *)bucket;

// Method: storage.bucketAccessControls.patch
// Updates an ACL entry on the specified bucket. This method supports patch
// semantics.
//  Required:
//   bucket: Name of a bucket.
//   entity: The entity holding the permission. Can be user-userId,
//     group-groupId, allUsers, or allAuthenticatedUsers.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageBucketAccessControl.
+ (id)queryForBucketAccessControlsPatchWithObject:(GTLStorageBucketAccessControl *)object
                                           bucket:(NSString *)bucket
                                           entity:(NSString *)entity;

// Method: storage.bucketAccessControls.update
// Updates an ACL entry on the specified bucket.
//  Required:
//   bucket: Name of a bucket.
//   entity: The entity holding the permission. Can be user-userId,
//     group-groupId, allUsers, or allAuthenticatedUsers.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageBucketAccessControl.
+ (id)queryForBucketAccessControlsUpdateWithObject:(GTLStorageBucketAccessControl *)object
                                            bucket:(NSString *)bucket
                                            entity:(NSString *)entity;

#pragma mark -
#pragma mark "buckets" methods
// These create a GTLQueryStorage object.

// Method: storage.buckets.delete
// Deletes an empty bucket.
//  Required:
//   bucket: Name of a bucket.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
+ (id)queryForBucketsDeleteWithBucket:(NSString *)bucket;

// Method: storage.buckets.get
// Returns metadata for the specified bucket.
//  Required:
//   bucket: Name of a bucket.
//  Optional:
//   projection: Set of properties to return. Defaults to no_acl.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit acl and defaultObjectAcl properties.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadOnly
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageBucket.
+ (id)queryForBucketsGetWithBucket:(NSString *)bucket;

// Method: storage.buckets.insert
// Creates a new bucket.
//  Optional:
//   projection: Set of properties to return. Defaults to no_acl, unless the
//     bucket resource specifies acl or defaultObjectAcl properties, when it
//     defaults to full.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit acl and defaultObjectAcl properties.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageBucket.
+ (id)queryForBucketsInsertWithObject:(GTLStorageBucket *)object;

// Method: storage.buckets.list
// Retrieves a list of buckets for a given project.
//  Required:
//   projectId: A valid API project identifier.
//  Optional:
//   maxResults: Maximum number of buckets to return.
//   pageToken: A previously-returned page token representing part of the larger
//     set of results to view.
//   projection: Set of properties to return. Defaults to no_acl.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit acl and defaultObjectAcl properties.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadOnly
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageBuckets.
+ (id)queryForBucketsListWithProjectId:(unsigned long long)projectId;

// Method: storage.buckets.patch
// Updates a bucket. This method supports patch semantics.
//  Required:
//   bucket: Name of a bucket.
//  Optional:
//   projection: Set of properties to return. Defaults to full.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit acl and defaultObjectAcl properties.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageBucket.
+ (id)queryForBucketsPatchWithObject:(GTLStorageBucket *)object
                              bucket:(NSString *)bucket;

// Method: storage.buckets.update
// Updates a bucket.
//  Required:
//   bucket: Name of a bucket.
//  Optional:
//   projection: Set of properties to return. Defaults to full.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit acl and defaultObjectAcl properties.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageBucket.
+ (id)queryForBucketsUpdateWithObject:(GTLStorageBucket *)object
                               bucket:(NSString *)bucket;

#pragma mark -
#pragma mark "objectAccessControls" methods
// These create a GTLQueryStorage object.

// Method: storage.objectAccessControls.delete
// Deletes the ACL entry for the specified entity on the specified object.
//  Required:
//   bucket: Name of a bucket.
//   object: Name of the object.
//   entity: The entity holding the permission. Can be user-userId,
//     group-groupId, allUsers, or allAuthenticatedUsers.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
+ (id)queryForObjectAccessControlsDeleteWithBucket:(NSString *)bucket
                                            object:(NSString *)object
                                            entity:(NSString *)entity;

// Method: storage.objectAccessControls.get
// Returns the ACL entry for the specified entity on the specified object.
//  Required:
//   bucket: Name of a bucket.
//   object: Name of the object.
//   entity: The entity holding the permission. Can be user-userId,
//     group-groupId, allUsers, or allAuthenticatedUsers.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageObjectAccessControl.
+ (id)queryForObjectAccessControlsGetWithBucket:(NSString *)bucket
                                         object:(NSString *)object
                                         entity:(NSString *)entity;

// Method: storage.objectAccessControls.insert
// Creates a new ACL entry on the specified object.
//  Required:
//   bucket: Name of a bucket.
//   object: Name of the object.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageObjectAccessControl.
+ (id)queryForObjectAccessControlsInsertWithObject:(GTLStorageObjectAccessControl *)object
                                            bucket:(NSString *)bucket
                                            object:(NSString *)object;

// Method: storage.objectAccessControls.list
// Retrieves ACL entries on the specified object.
//  Required:
//   bucket: Name of a bucket.
//   object: Name of the object.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageObjectAccessControls.
+ (id)queryForObjectAccessControlsListWithBucket:(NSString *)bucket
                                          object:(NSString *)object;

// Method: storage.objectAccessControls.patch
// Updates an ACL entry on the specified object. This method supports patch
// semantics.
//  Required:
//   bucket: Name of a bucket.
//   object: Name of the object.
//   entity: The entity holding the permission. Can be user-userId,
//     group-groupId, allUsers, or allAuthenticatedUsers.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageObjectAccessControl.
+ (id)queryForObjectAccessControlsPatchWithObject:(GTLStorageObjectAccessControl *)object
                                           bucket:(NSString *)bucket
                                           object:(NSString *)object
                                           entity:(NSString *)entity;

// Method: storage.objectAccessControls.update
// Updates an ACL entry on the specified object.
//  Required:
//   bucket: Name of a bucket.
//   object: Name of the object.
//   entity: The entity holding the permission. Can be user-userId,
//     group-groupId, allUsers, or allAuthenticatedUsers.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageObjectAccessControl.
+ (id)queryForObjectAccessControlsUpdateWithObject:(GTLStorageObjectAccessControl *)object
                                            bucket:(NSString *)bucket
                                            object:(NSString *)object
                                            entity:(NSString *)entity;

#pragma mark -
#pragma mark "objects" methods
// These create a GTLQueryStorage object.

// Method: storage.objects.delete
// Deletes data blobs and associated metadata.
//  Required:
//   bucket: Name of the bucket in which the object resides.
//   object: Name of the object.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
+ (id)queryForObjectsDeleteWithBucket:(NSString *)bucket
                               object:(NSString *)object;

// Method: storage.objects.get
// Retrieves objects or their associated metadata.
//  Required:
//   bucket: Name of the bucket in which the object resides.
//   object: Name of the object.
//  Optional:
//   projection: Set of properties to return. Defaults to no_acl.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit the acl property.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadOnly
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageObject.
+ (id)queryForObjectsGetWithBucket:(NSString *)bucket
                            object:(NSString *)object;

// Method: storage.objects.insert
// Stores new data blobs and associated metadata.
//  Required:
//   bucket: Name of the bucket in which to store the new object. Overrides the
//     provided object metadata's bucket value, if any.
//  Optional:
//   name: Name of the object. Required when the object metadata is not
//     otherwise provided. Overrides the object metadata's name value, if any.
//   projection: Set of properties to return. Defaults to no_acl, unless the
//     object resource specifies the acl property, when it defaults to full.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit the acl property.
//  Upload Parameters:
//   Accepted MIME type(s): */*
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageObject.
+ (id)queryForObjectsInsertWithObject:(GTLStorageObject *)object
                               bucket:(NSString *)bucket
                     uploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

// Method: storage.objects.list
// Retrieves a list of objects matching the criteria.
//  Required:
//   bucket: Name of the bucket in which to look for objects.
//  Optional:
//   delimiter: Returns results in a directory-like mode. items will contain
//     only objects whose names, aside from the prefix, do not contain
//     delimiter. Objects whose names, aside from the prefix, contain delimiter
//     will have their name, truncated after the delimiter, returned in
//     prefixes. Duplicate prefixes are omitted.
//   maxResults: Maximum number of items plus prefixes to return. As duplicate
//     prefixes are omitted, fewer total results may be returned than requested.
//   pageToken: A previously-returned page token representing part of the larger
//     set of results to view.
//   prefix: Filter results to objects whose names begin with this prefix.
//   projection: Set of properties to return. Defaults to no_acl.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit the acl property.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadOnly
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageObjects.
+ (id)queryForObjectsListWithBucket:(NSString *)bucket;

// Method: storage.objects.patch
// Updates a data blob's associated metadata. This method supports patch
// semantics.
//  Required:
//   bucket: Name of the bucket in which the object resides.
//   object: Name of the object.
//  Optional:
//   projection: Set of properties to return. Defaults to full.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit the acl property.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageObject.
+ (id)queryForObjectsPatchWithObject:(GTLStorageObject *)object
                              bucket:(NSString *)bucket
                              object:(NSString *)object;

// Method: storage.objects.update
// Updates a data blob's associated metadata.
//  Required:
//   bucket: Name of the bucket in which the object resides.
//   object: Name of the object.
//  Optional:
//   projection: Set of properties to return. Defaults to full.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit the acl property.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageObject.
+ (id)queryForObjectsUpdateWithObject:(GTLStorageObject *)object
                               bucket:(NSString *)bucket
                               object:(NSString *)object;

@end
