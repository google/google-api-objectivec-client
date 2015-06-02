/* Copyright (c) 2015 Google Inc.
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
//   Cloud Storage API (storage/v1)
// Description:
//   Lets you store and retrieve potentially-large, immutable data objects.
// Documentation:
//   https://developers.google.com/storage/docs/json_api/
// Classes:
//   GTLQueryStorage (35 custom class methods, 36 custom properties)
//   GTLStorageObjectsComposeSourceObjectsItem (0 custom class methods, 3 custom properties)
//   GTLStorageObjectsComposeSourceObjectsItemObjectPreconditions (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLStorageBucket;
@class GTLStorageBucketAccessControl;
@class GTLStorageChannel;
@class GTLStorageObject;
@class GTLStorageObjectAccessControl;
@class GTLStorageObjectsComposeSourceObjectsItem;

@interface GTLQueryStorage : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (nonatomic, copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (nonatomic, copy) NSString *bucket;
@property (nonatomic, copy) NSString *contentEncoding;
@property (nonatomic, copy) NSString *delimiter;
@property (nonatomic, retain) GTLStorageObject *destination;
@property (nonatomic, retain) GTLStorageObject *destinationResource;
@property (nonatomic, copy) NSString *destinationBucket;
@property (nonatomic, copy) NSString *destinationObject;
@property (nonatomic, copy) NSString *destinationPredefinedAcl;
@property (nonatomic, copy) NSString *entity;
@property (nonatomic, assign) long long generation;
@property (nonatomic, assign) long long ifGenerationMatch;
@property (nonatomic, assign) long long ifGenerationNotMatch;
@property (nonatomic, assign) long long ifMetagenerationMatch;
@property (nonatomic, assign) long long ifMetagenerationNotMatch;
@property (nonatomic, assign) long long ifSourceGenerationMatch;
@property (nonatomic, assign) long long ifSourceGenerationNotMatch;
@property (nonatomic, assign) long long ifSourceMetagenerationMatch;
@property (nonatomic, assign) long long ifSourceMetagenerationNotMatch;
@property (nonatomic, copy) NSString *kind;
@property (nonatomic, assign) long long maxBytesRewrittenPerCall;
@property (nonatomic, assign) NSUInteger maxResults;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *object;
@property (nonatomic, copy) NSString *pageToken;
@property (nonatomic, copy) NSString *predefinedAcl;
@property (nonatomic, copy) NSString *predefinedDefaultObjectAcl;
@property (nonatomic, copy) NSString *prefix;
@property (nonatomic, copy) NSString *project;
@property (nonatomic, copy) NSString *projection;
@property (nonatomic, copy) NSString *rewriteToken;
@property (nonatomic, copy) NSString *sourceBucket;
@property (nonatomic, assign) long long sourceGeneration;
@property (nonatomic, copy) NSString *sourceObject;
@property (nonatomic, retain) NSArray *sourceObjects;  // of GTLStorageObjectsComposeSourceObjectsItem
@property (nonatomic, assign) BOOL versions;

#pragma mark -
#pragma mark "bucketAccessControls" methods
// These create a GTLQueryStorage object.

// Method: storage.bucketAccessControls.delete
// Permanently deletes the ACL entry for the specified entity on the specified
// bucket.
//  Required:
//   bucket: Name of a bucket.
//   entity: The entity holding the permission. Can be user-userId,
//     user-emailAddress, group-groupId, group-emailAddress, allUsers, or
//     allAuthenticatedUsers.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
+ (instancetype)queryForBucketAccessControlsDeleteWithBucket:(NSString *)bucket
                                                      entity:(NSString *)entity;

// Method: storage.bucketAccessControls.get
// Returns the ACL entry for the specified entity on the specified bucket.
//  Required:
//   bucket: Name of a bucket.
//   entity: The entity holding the permission. Can be user-userId,
//     user-emailAddress, group-groupId, group-emailAddress, allUsers, or
//     allAuthenticatedUsers.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageBucketAccessControl.
+ (instancetype)queryForBucketAccessControlsGetWithBucket:(NSString *)bucket
                                                   entity:(NSString *)entity;

// Method: storage.bucketAccessControls.insert
// Creates a new ACL entry on the specified bucket.
//  Required:
//   bucket: Name of a bucket.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageBucketAccessControl.
+ (instancetype)queryForBucketAccessControlsInsertWithObject:(GTLStorageBucketAccessControl *)object
                                                      bucket:(NSString *)bucket;

// Method: storage.bucketAccessControls.list
// Retrieves ACL entries on the specified bucket.
//  Required:
//   bucket: Name of a bucket.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageBucketAccessControls.
+ (instancetype)queryForBucketAccessControlsListWithBucket:(NSString *)bucket;

// Method: storage.bucketAccessControls.patch
// Updates an ACL entry on the specified bucket. This method supports patch
// semantics.
//  Required:
//   bucket: Name of a bucket.
//   entity: The entity holding the permission. Can be user-userId,
//     user-emailAddress, group-groupId, group-emailAddress, allUsers, or
//     allAuthenticatedUsers.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageBucketAccessControl.
+ (instancetype)queryForBucketAccessControlsPatchWithObject:(GTLStorageBucketAccessControl *)object
                                                     bucket:(NSString *)bucket
                                                     entity:(NSString *)entity;

// Method: storage.bucketAccessControls.update
// Updates an ACL entry on the specified bucket.
//  Required:
//   bucket: Name of a bucket.
//   entity: The entity holding the permission. Can be user-userId,
//     user-emailAddress, group-groupId, group-emailAddress, allUsers, or
//     allAuthenticatedUsers.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageBucketAccessControl.
+ (instancetype)queryForBucketAccessControlsUpdateWithObject:(GTLStorageBucketAccessControl *)object
                                                      bucket:(NSString *)bucket
                                                      entity:(NSString *)entity;

#pragma mark -
#pragma mark "buckets" methods
// These create a GTLQueryStorage object.

// Method: storage.buckets.delete
// Permanently deletes an empty bucket.
//  Required:
//   bucket: Name of a bucket.
//  Optional:
//   ifMetagenerationMatch: If set, only deletes the bucket if its
//     metageneration matches this value.
//   ifMetagenerationNotMatch: If set, only deletes the bucket if its
//     metageneration does not match this value.
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
+ (instancetype)queryForBucketsDeleteWithBucket:(NSString *)bucket;

// Method: storage.buckets.get
// Returns metadata for the specified bucket.
//  Required:
//   bucket: Name of a bucket.
//  Optional:
//   ifMetagenerationMatch: Makes the return of the bucket metadata conditional
//     on whether the bucket's current metageneration matches the given value.
//   ifMetagenerationNotMatch: Makes the return of the bucket metadata
//     conditional on whether the bucket's current metageneration does not match
//     the given value.
//   projection: Set of properties to return. Defaults to noAcl.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit acl and defaultObjectAcl properties.
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadOnly
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageBucket.
+ (instancetype)queryForBucketsGetWithBucket:(NSString *)bucket;

// Method: storage.buckets.insert
// Creates a new bucket.
//  Required:
//   project: A valid API project identifier.
//  Optional:
//   predefinedAcl: Apply a predefined set of access controls to this bucket.
//      kGTLStoragePredefinedAclAuthenticatedRead: Project team owners get OWNER
//        access, and allAuthenticatedUsers get READER access.
//      kGTLStoragePredefinedAclPrivate: Project team owners get OWNER access.
//      kGTLStoragePredefinedAclProjectPrivate: Project team members get access
//        according to their roles.
//      kGTLStoragePredefinedAclPublicRead: Project team owners get OWNER
//        access, and allUsers get READER access.
//      kGTLStoragePredefinedAclPublicReadWrite: Project team owners get OWNER
//        access, and allUsers get WRITER access.
//   predefinedDefaultObjectAcl: Apply a predefined set of default object access
//     controls to this bucket.
//      kGTLStoragePredefinedDefaultObjectAclAuthenticatedRead: Object owner
//        gets OWNER access, and allAuthenticatedUsers get READER access.
//      kGTLStoragePredefinedDefaultObjectAclBucketOwnerFullControl: Object
//        owner gets OWNER access, and project team owners get OWNER access.
//      kGTLStoragePredefinedDefaultObjectAclBucketOwnerRead: Object owner gets
//        OWNER access, and project team owners get READER access.
//      kGTLStoragePredefinedDefaultObjectAclPrivate: Object owner gets OWNER
//        access.
//      kGTLStoragePredefinedDefaultObjectAclProjectPrivate: Object owner gets
//        OWNER access, and project team members get access according to their
//        roles.
//      kGTLStoragePredefinedDefaultObjectAclPublicRead: Object owner gets OWNER
//        access, and allUsers get READER access.
//   projection: Set of properties to return. Defaults to noAcl, unless the
//     bucket resource specifies acl or defaultObjectAcl properties, when it
//     defaults to full.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit acl and defaultObjectAcl properties.
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageBucket.
+ (instancetype)queryForBucketsInsertWithObject:(GTLStorageBucket *)object
                                        project:(NSString *)project;

// Method: storage.buckets.list
// Retrieves a list of buckets for a given project.
//  Required:
//   project: A valid API project identifier.
//  Optional:
//   maxResults: Maximum number of buckets to return.
//   pageToken: A previously-returned page token representing part of the larger
//     set of results to view.
//   prefix: Filter results to buckets whose names begin with this prefix.
//   projection: Set of properties to return. Defaults to noAcl.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit acl and defaultObjectAcl properties.
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadOnly
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageBuckets.
+ (instancetype)queryForBucketsListWithProject:(NSString *)project;

// Method: storage.buckets.patch
// Updates a bucket. This method supports patch semantics.
//  Required:
//   bucket: Name of a bucket.
//  Optional:
//   ifMetagenerationMatch: Makes the return of the bucket metadata conditional
//     on whether the bucket's current metageneration matches the given value.
//   ifMetagenerationNotMatch: Makes the return of the bucket metadata
//     conditional on whether the bucket's current metageneration does not match
//     the given value.
//   predefinedAcl: Apply a predefined set of access controls to this bucket.
//      kGTLStoragePredefinedAclAuthenticatedRead: Project team owners get OWNER
//        access, and allAuthenticatedUsers get READER access.
//      kGTLStoragePredefinedAclPrivate: Project team owners get OWNER access.
//      kGTLStoragePredefinedAclProjectPrivate: Project team members get access
//        according to their roles.
//      kGTLStoragePredefinedAclPublicRead: Project team owners get OWNER
//        access, and allUsers get READER access.
//      kGTLStoragePredefinedAclPublicReadWrite: Project team owners get OWNER
//        access, and allUsers get WRITER access.
//   predefinedDefaultObjectAcl: Apply a predefined set of default object access
//     controls to this bucket.
//      kGTLStoragePredefinedDefaultObjectAclAuthenticatedRead: Object owner
//        gets OWNER access, and allAuthenticatedUsers get READER access.
//      kGTLStoragePredefinedDefaultObjectAclBucketOwnerFullControl: Object
//        owner gets OWNER access, and project team owners get OWNER access.
//      kGTLStoragePredefinedDefaultObjectAclBucketOwnerRead: Object owner gets
//        OWNER access, and project team owners get READER access.
//      kGTLStoragePredefinedDefaultObjectAclPrivate: Object owner gets OWNER
//        access.
//      kGTLStoragePredefinedDefaultObjectAclProjectPrivate: Object owner gets
//        OWNER access, and project team members get access according to their
//        roles.
//      kGTLStoragePredefinedDefaultObjectAclPublicRead: Object owner gets OWNER
//        access, and allUsers get READER access.
//   projection: Set of properties to return. Defaults to full.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit acl and defaultObjectAcl properties.
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageBucket.
+ (instancetype)queryForBucketsPatchWithObject:(GTLStorageBucket *)object
                                        bucket:(NSString *)bucket;

// Method: storage.buckets.update
// Updates a bucket.
//  Required:
//   bucket: Name of a bucket.
//  Optional:
//   ifMetagenerationMatch: Makes the return of the bucket metadata conditional
//     on whether the bucket's current metageneration matches the given value.
//   ifMetagenerationNotMatch: Makes the return of the bucket metadata
//     conditional on whether the bucket's current metageneration does not match
//     the given value.
//   predefinedAcl: Apply a predefined set of access controls to this bucket.
//      kGTLStoragePredefinedAclAuthenticatedRead: Project team owners get OWNER
//        access, and allAuthenticatedUsers get READER access.
//      kGTLStoragePredefinedAclPrivate: Project team owners get OWNER access.
//      kGTLStoragePredefinedAclProjectPrivate: Project team members get access
//        according to their roles.
//      kGTLStoragePredefinedAclPublicRead: Project team owners get OWNER
//        access, and allUsers get READER access.
//      kGTLStoragePredefinedAclPublicReadWrite: Project team owners get OWNER
//        access, and allUsers get WRITER access.
//   predefinedDefaultObjectAcl: Apply a predefined set of default object access
//     controls to this bucket.
//      kGTLStoragePredefinedDefaultObjectAclAuthenticatedRead: Object owner
//        gets OWNER access, and allAuthenticatedUsers get READER access.
//      kGTLStoragePredefinedDefaultObjectAclBucketOwnerFullControl: Object
//        owner gets OWNER access, and project team owners get OWNER access.
//      kGTLStoragePredefinedDefaultObjectAclBucketOwnerRead: Object owner gets
//        OWNER access, and project team owners get READER access.
//      kGTLStoragePredefinedDefaultObjectAclPrivate: Object owner gets OWNER
//        access.
//      kGTLStoragePredefinedDefaultObjectAclProjectPrivate: Object owner gets
//        OWNER access, and project team members get access according to their
//        roles.
//      kGTLStoragePredefinedDefaultObjectAclPublicRead: Object owner gets OWNER
//        access, and allUsers get READER access.
//   projection: Set of properties to return. Defaults to full.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit acl and defaultObjectAcl properties.
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageBucket.
+ (instancetype)queryForBucketsUpdateWithObject:(GTLStorageBucket *)object
                                         bucket:(NSString *)bucket;

#pragma mark -
#pragma mark "channels" methods
// These create a GTLQueryStorage object.

// Method: storage.channels.stop
// Stop watching resources through this channel
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadOnly
//   kGTLAuthScopeStorageDevstorageReadWrite
+ (instancetype)queryForChannelsStopWithObject:(GTLStorageChannel *)object;

#pragma mark -
#pragma mark "defaultObjectAccessControls" methods
// These create a GTLQueryStorage object.

// Method: storage.defaultObjectAccessControls.delete
// Permanently deletes the default object ACL entry for the specified entity on
// the specified bucket.
//  Required:
//   bucket: Name of a bucket.
//   entity: The entity holding the permission. Can be user-userId,
//     user-emailAddress, group-groupId, group-emailAddress, allUsers, or
//     allAuthenticatedUsers.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
+ (instancetype)queryForDefaultObjectAccessControlsDeleteWithBucket:(NSString *)bucket
                                                             entity:(NSString *)entity;

// Method: storage.defaultObjectAccessControls.get
// Returns the default object ACL entry for the specified entity on the
// specified bucket.
//  Required:
//   bucket: Name of a bucket.
//   entity: The entity holding the permission. Can be user-userId,
//     user-emailAddress, group-groupId, group-emailAddress, allUsers, or
//     allAuthenticatedUsers.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageObjectAccessControl.
+ (instancetype)queryForDefaultObjectAccessControlsGetWithBucket:(NSString *)bucket
                                                          entity:(NSString *)entity;

// Method: storage.defaultObjectAccessControls.insert
// Creates a new default object ACL entry on the specified bucket.
//  Required:
//   bucket: Name of a bucket.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageObjectAccessControl.
+ (instancetype)queryForDefaultObjectAccessControlsInsertWithObject:(GTLStorageObjectAccessControl *)object
                                                             bucket:(NSString *)bucket;

// Method: storage.defaultObjectAccessControls.list
// Retrieves default object ACL entries on the specified bucket.
//  Required:
//   bucket: Name of a bucket.
//  Optional:
//   ifMetagenerationMatch: If present, only return default ACL listing if the
//     bucket's current metageneration matches this value.
//   ifMetagenerationNotMatch: If present, only return default ACL listing if
//     the bucket's current metageneration does not match the given value.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageObjectAccessControls.
+ (instancetype)queryForDefaultObjectAccessControlsListWithBucket:(NSString *)bucket;

// Method: storage.defaultObjectAccessControls.patch
// Updates a default object ACL entry on the specified bucket. This method
// supports patch semantics.
//  Required:
//   bucket: Name of a bucket.
//   entity: The entity holding the permission. Can be user-userId,
//     user-emailAddress, group-groupId, group-emailAddress, allUsers, or
//     allAuthenticatedUsers.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageObjectAccessControl.
+ (instancetype)queryForDefaultObjectAccessControlsPatchWithObject:(GTLStorageObjectAccessControl *)object
                                                            bucket:(NSString *)bucket
                                                            entity:(NSString *)entity;

// Method: storage.defaultObjectAccessControls.update
// Updates a default object ACL entry on the specified bucket.
//  Required:
//   bucket: Name of a bucket.
//   entity: The entity holding the permission. Can be user-userId,
//     user-emailAddress, group-groupId, group-emailAddress, allUsers, or
//     allAuthenticatedUsers.
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageObjectAccessControl.
+ (instancetype)queryForDefaultObjectAccessControlsUpdateWithObject:(GTLStorageObjectAccessControl *)object
                                                             bucket:(NSString *)bucket
                                                             entity:(NSString *)entity;

#pragma mark -
#pragma mark "objectAccessControls" methods
// These create a GTLQueryStorage object.

// Method: storage.objectAccessControls.delete
// Permanently deletes the ACL entry for the specified entity on the specified
// object.
//  Required:
//   bucket: Name of a bucket.
//   object: Name of the object.
//   entity: The entity holding the permission. Can be user-userId,
//     user-emailAddress, group-groupId, group-emailAddress, allUsers, or
//     allAuthenticatedUsers.
//  Optional:
//   generation: If present, selects a specific revision of this object (as
//     opposed to the latest version, the default).
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
+ (instancetype)queryForObjectAccessControlsDeleteWithBucket:(NSString *)bucket
                                                      object:(NSString *)object
                                                      entity:(NSString *)entity;

// Method: storage.objectAccessControls.get
// Returns the ACL entry for the specified entity on the specified object.
//  Required:
//   bucket: Name of a bucket.
//   object: Name of the object.
//   entity: The entity holding the permission. Can be user-userId,
//     user-emailAddress, group-groupId, group-emailAddress, allUsers, or
//     allAuthenticatedUsers.
//  Optional:
//   generation: If present, selects a specific revision of this object (as
//     opposed to the latest version, the default).
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageObjectAccessControl.
+ (instancetype)queryForObjectAccessControlsGetWithBucket:(NSString *)bucket
                                                   object:(NSString *)object
                                                   entity:(NSString *)entity;

// Method: storage.objectAccessControls.insert
// Creates a new ACL entry on the specified object.
//  Required:
//   bucket: Name of a bucket.
//   object: Name of the object.
//  Optional:
//   generation: If present, selects a specific revision of this object (as
//     opposed to the latest version, the default).
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageObjectAccessControl.
+ (instancetype)queryForObjectAccessControlsInsertWithObject:(GTLStorageObjectAccessControl *)object
                                                      bucket:(NSString *)bucket
                                                      object:(NSString *)object;

// Method: storage.objectAccessControls.list
// Retrieves ACL entries on the specified object.
//  Required:
//   bucket: Name of a bucket.
//   object: Name of the object.
//  Optional:
//   generation: If present, selects a specific revision of this object (as
//     opposed to the latest version, the default).
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageObjectAccessControls.
+ (instancetype)queryForObjectAccessControlsListWithBucket:(NSString *)bucket
                                                    object:(NSString *)object;

// Method: storage.objectAccessControls.patch
// Updates an ACL entry on the specified object. This method supports patch
// semantics.
//  Required:
//   bucket: Name of a bucket.
//   object: Name of the object.
//   entity: The entity holding the permission. Can be user-userId,
//     user-emailAddress, group-groupId, group-emailAddress, allUsers, or
//     allAuthenticatedUsers.
//  Optional:
//   generation: If present, selects a specific revision of this object (as
//     opposed to the latest version, the default).
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageObjectAccessControl.
+ (instancetype)queryForObjectAccessControlsPatchWithObject:(GTLStorageObjectAccessControl *)object
                                                     bucket:(NSString *)bucket
                                                     object:(NSString *)object
                                                     entity:(NSString *)entity;

// Method: storage.objectAccessControls.update
// Updates an ACL entry on the specified object.
//  Required:
//   bucket: Name of a bucket.
//   object: Name of the object.
//   entity: The entity holding the permission. Can be user-userId,
//     user-emailAddress, group-groupId, group-emailAddress, allUsers, or
//     allAuthenticatedUsers.
//  Optional:
//   generation: If present, selects a specific revision of this object (as
//     opposed to the latest version, the default).
//  Authorization scope(s):
//   kGTLAuthScopeStorageDevstorageFullControl
// Fetches a GTLStorageObjectAccessControl.
+ (instancetype)queryForObjectAccessControlsUpdateWithObject:(GTLStorageObjectAccessControl *)object
                                                      bucket:(NSString *)bucket
                                                      object:(NSString *)object
                                                      entity:(NSString *)entity;

#pragma mark -
#pragma mark "objects" methods
// These create a GTLQueryStorage object.

// Method: storage.objects.compose
// Concatenates a list of existing objects into a new object in the same bucket.
//  Required:
//   destinationBucket: Name of the bucket in which to store the new object.
//   destinationObject: Name of the new object.
//  Optional:
//   sourceObjects: The list of source objects that will be concatenated into a
//     single object.
//   destination: Properties of the resulting object.
//   destinationPredefinedAcl: Apply a predefined set of access controls to the
//     destination object.
//      kGTLStorageDestinationPredefinedAclAuthenticatedRead: Object owner gets
//        OWNER access, and allAuthenticatedUsers get READER access.
//      kGTLStorageDestinationPredefinedAclBucketOwnerFullControl: Object owner
//        gets OWNER access, and project team owners get OWNER access.
//      kGTLStorageDestinationPredefinedAclBucketOwnerRead: Object owner gets
//        OWNER access, and project team owners get READER access.
//      kGTLStorageDestinationPredefinedAclPrivate: Object owner gets OWNER
//        access.
//      kGTLStorageDestinationPredefinedAclProjectPrivate: Object owner gets
//        OWNER access, and project team members get access according to their
//        roles.
//      kGTLStorageDestinationPredefinedAclPublicRead: Object owner gets OWNER
//        access, and allUsers get READER access.
//   ifGenerationMatch: Makes the operation conditional on whether the object's
//     current generation matches the given value.
//   ifMetagenerationMatch: Makes the operation conditional on whether the
//     object's current metageneration matches the given value.
//   kind: The kind of item this is. (Default storage#composeRequest)
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageObject.
+ (instancetype)queryForObjectsComposeWithDestinationBucket:(NSString *)destinationBucket
                                          destinationObject:(NSString *)destinationObject;

// Method: storage.objects.copy
// Copies a source object to a destination object. Optionally overrides
// metadata.
//  Required:
//   sourceBucket: Name of the bucket in which to find the source object.
//   sourceObject: Name of the source object.
//   destinationBucket: Name of the bucket in which to store the new object.
//     Overrides the provided object metadata's bucket value, if any.
//   destinationObject: Name of the new object. Required when the object
//     metadata is not otherwise provided. Overrides the object metadata's name
//     value, if any.
//  Optional:
//   destinationResource: GTLStorageObject
//   destinationPredefinedAcl: Apply a predefined set of access controls to the
//     destination object.
//      kGTLStorageDestinationPredefinedAclAuthenticatedRead: Object owner gets
//        OWNER access, and allAuthenticatedUsers get READER access.
//      kGTLStorageDestinationPredefinedAclBucketOwnerFullControl: Object owner
//        gets OWNER access, and project team owners get OWNER access.
//      kGTLStorageDestinationPredefinedAclBucketOwnerRead: Object owner gets
//        OWNER access, and project team owners get READER access.
//      kGTLStorageDestinationPredefinedAclPrivate: Object owner gets OWNER
//        access.
//      kGTLStorageDestinationPredefinedAclProjectPrivate: Object owner gets
//        OWNER access, and project team members get access according to their
//        roles.
//      kGTLStorageDestinationPredefinedAclPublicRead: Object owner gets OWNER
//        access, and allUsers get READER access.
//   ifGenerationMatch: Makes the operation conditional on whether the
//     destination object's current generation matches the given value.
//   ifGenerationNotMatch: Makes the operation conditional on whether the
//     destination object's current generation does not match the given value.
//   ifMetagenerationMatch: Makes the operation conditional on whether the
//     destination object's current metageneration matches the given value.
//   ifMetagenerationNotMatch: Makes the operation conditional on whether the
//     destination object's current metageneration does not match the given
//     value.
//   ifSourceGenerationMatch: Makes the operation conditional on whether the
//     source object's generation matches the given value.
//   ifSourceGenerationNotMatch: Makes the operation conditional on whether the
//     source object's generation does not match the given value.
//   ifSourceMetagenerationMatch: Makes the operation conditional on whether the
//     source object's current metageneration matches the given value.
//   ifSourceMetagenerationNotMatch: Makes the operation conditional on whether
//     the source object's current metageneration does not match the given
//     value.
//   projection: Set of properties to return. Defaults to noAcl, unless the
//     object resource specifies the acl property, when it defaults to full.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit the acl property.
//   sourceGeneration: If present, selects a specific revision of the source
//     object (as opposed to the latest version, the default).
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageObject.
+ (instancetype)queryForObjectsCopyWithSourceBucket:(NSString *)sourceBucket
                                       sourceObject:(NSString *)sourceObject
                                  destinationBucket:(NSString *)destinationBucket
                                  destinationObject:(NSString *)destinationObject;

// Method: storage.objects.delete
// Deletes an object and its metadata. Deletions are permanent if versioning is
// not enabled for the bucket, or if the generation parameter is used.
//  Required:
//   bucket: Name of the bucket in which the object resides.
//   object: Name of the object.
//  Optional:
//   generation: If present, permanently deletes a specific revision of this
//     object (as opposed to the latest version, the default).
//   ifGenerationMatch: Makes the operation conditional on whether the object's
//     current generation matches the given value.
//   ifGenerationNotMatch: Makes the operation conditional on whether the
//     object's current generation does not match the given value.
//   ifMetagenerationMatch: Makes the operation conditional on whether the
//     object's current metageneration matches the given value.
//   ifMetagenerationNotMatch: Makes the operation conditional on whether the
//     object's current metageneration does not match the given value.
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
+ (instancetype)queryForObjectsDeleteWithBucket:(NSString *)bucket
                                         object:(NSString *)object;

// Method: storage.objects.get
// Retrieves an object or its metadata.
//  Required:
//   bucket: Name of the bucket in which the object resides.
//   object: Name of the object.
//  Optional:
//   generation: If present, selects a specific revision of this object (as
//     opposed to the latest version, the default).
//   ifGenerationMatch: Makes the operation conditional on whether the object's
//     generation matches the given value.
//   ifGenerationNotMatch: Makes the operation conditional on whether the
//     object's generation does not match the given value.
//   ifMetagenerationMatch: Makes the operation conditional on whether the
//     object's current metageneration matches the given value.
//   ifMetagenerationNotMatch: Makes the operation conditional on whether the
//     object's current metageneration does not match the given value.
//   projection: Set of properties to return. Defaults to noAcl.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit the acl property.
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadOnly
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageObject.
+ (instancetype)queryForObjectsGetWithBucket:(NSString *)bucket
                                      object:(NSString *)object;

// Method: storage.objects.insert
// Stores a new object and metadata.
//  Required:
//   bucket: Name of the bucket in which to store the new object. Overrides the
//     provided object metadata's bucket value, if any.
//  Optional:
//   contentEncoding: If set, sets the contentEncoding property of the final
//     object to this value. Setting this parameter is equivalent to setting the
//     contentEncoding metadata property. This can be useful when uploading an
//     object with uploadType=media to indicate the encoding of the content
//     being uploaded.
//   ifGenerationMatch: Makes the operation conditional on whether the object's
//     current generation matches the given value.
//   ifGenerationNotMatch: Makes the operation conditional on whether the
//     object's current generation does not match the given value.
//   ifMetagenerationMatch: Makes the operation conditional on whether the
//     object's current metageneration matches the given value.
//   ifMetagenerationNotMatch: Makes the operation conditional on whether the
//     object's current metageneration does not match the given value.
//   name: Name of the object. Required when the object metadata is not
//     otherwise provided. Overrides the object metadata's name value, if any.
//   predefinedAcl: Apply a predefined set of access controls to this object.
//      kGTLStoragePredefinedAclAuthenticatedRead: Object owner gets OWNER
//        access, and allAuthenticatedUsers get READER access.
//      kGTLStoragePredefinedAclBucketOwnerFullControl: Object owner gets OWNER
//        access, and project team owners get OWNER access.
//      kGTLStoragePredefinedAclBucketOwnerRead: Object owner gets OWNER access,
//        and project team owners get READER access.
//      kGTLStoragePredefinedAclPrivate: Object owner gets OWNER access.
//      kGTLStoragePredefinedAclProjectPrivate: Object owner gets OWNER access,
//        and project team members get access according to their roles.
//      kGTLStoragePredefinedAclPublicRead: Object owner gets OWNER access, and
//        allUsers get READER access.
//   projection: Set of properties to return. Defaults to noAcl, unless the
//     object resource specifies the acl property, when it defaults to full.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit the acl property.
//  Upload Parameters:
//   Accepted MIME type(s): */*
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageObject.
+ (instancetype)queryForObjectsInsertWithObject:(GTLStorageObject *)object
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
//     The default value of this parameter is 1,000 items.
//   pageToken: A previously-returned page token representing part of the larger
//     set of results to view.
//   prefix: Filter results to objects whose names begin with this prefix.
//   projection: Set of properties to return. Defaults to noAcl.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit the acl property.
//   versions: If true, lists all versions of an object as distinct results. The
//     default is false. For more information, see Object Versioning.
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadOnly
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageObjects.
+ (instancetype)queryForObjectsListWithBucket:(NSString *)bucket;

// Method: storage.objects.patch
// Updates an object's metadata. This method supports patch semantics.
//  Required:
//   bucket: Name of the bucket in which the object resides.
//   object: Name of the object.
//  Optional:
//   generation: If present, selects a specific revision of this object (as
//     opposed to the latest version, the default).
//   ifGenerationMatch: Makes the operation conditional on whether the object's
//     current generation matches the given value.
//   ifGenerationNotMatch: Makes the operation conditional on whether the
//     object's current generation does not match the given value.
//   ifMetagenerationMatch: Makes the operation conditional on whether the
//     object's current metageneration matches the given value.
//   ifMetagenerationNotMatch: Makes the operation conditional on whether the
//     object's current metageneration does not match the given value.
//   predefinedAcl: Apply a predefined set of access controls to this object.
//      kGTLStoragePredefinedAclAuthenticatedRead: Object owner gets OWNER
//        access, and allAuthenticatedUsers get READER access.
//      kGTLStoragePredefinedAclBucketOwnerFullControl: Object owner gets OWNER
//        access, and project team owners get OWNER access.
//      kGTLStoragePredefinedAclBucketOwnerRead: Object owner gets OWNER access,
//        and project team owners get READER access.
//      kGTLStoragePredefinedAclPrivate: Object owner gets OWNER access.
//      kGTLStoragePredefinedAclProjectPrivate: Object owner gets OWNER access,
//        and project team members get access according to their roles.
//      kGTLStoragePredefinedAclPublicRead: Object owner gets OWNER access, and
//        allUsers get READER access.
//   projection: Set of properties to return. Defaults to full.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit the acl property.
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageObject.
+ (instancetype)queryForObjectsPatchWithObject:(GTLStorageObject *)object
                                        bucket:(NSString *)bucket
                                        object:(NSString *)object;

// Method: storage.objects.rewrite
// Rewrites a source object to a destination object. Optionally overrides
// metadata.
//  Required:
//   sourceBucket: Name of the bucket in which to find the source object.
//   sourceObject: Name of the source object.
//   destinationBucket: Name of the bucket in which to store the new object.
//     Overrides the provided object metadata's bucket value, if any.
//   destinationObject: Name of the new object. Required when the object
//     metadata is not otherwise provided. Overrides the object metadata's name
//     value, if any.
//  Optional:
//   destinationResource: GTLStorageObject
//   destinationPredefinedAcl: Apply a predefined set of access controls to the
//     destination object.
//      kGTLStorageDestinationPredefinedAclAuthenticatedRead: Object owner gets
//        OWNER access, and allAuthenticatedUsers get READER access.
//      kGTLStorageDestinationPredefinedAclBucketOwnerFullControl: Object owner
//        gets OWNER access, and project team owners get OWNER access.
//      kGTLStorageDestinationPredefinedAclBucketOwnerRead: Object owner gets
//        OWNER access, and project team owners get READER access.
//      kGTLStorageDestinationPredefinedAclPrivate: Object owner gets OWNER
//        access.
//      kGTLStorageDestinationPredefinedAclProjectPrivate: Object owner gets
//        OWNER access, and project team members get access according to their
//        roles.
//      kGTLStorageDestinationPredefinedAclPublicRead: Object owner gets OWNER
//        access, and allUsers get READER access.
//   ifGenerationMatch: Makes the operation conditional on whether the
//     destination object's current generation matches the given value.
//   ifGenerationNotMatch: Makes the operation conditional on whether the
//     destination object's current generation does not match the given value.
//   ifMetagenerationMatch: Makes the operation conditional on whether the
//     destination object's current metageneration matches the given value.
//   ifMetagenerationNotMatch: Makes the operation conditional on whether the
//     destination object's current metageneration does not match the given
//     value.
//   ifSourceGenerationMatch: Makes the operation conditional on whether the
//     source object's generation matches the given value.
//   ifSourceGenerationNotMatch: Makes the operation conditional on whether the
//     source object's generation does not match the given value.
//   ifSourceMetagenerationMatch: Makes the operation conditional on whether the
//     source object's current metageneration matches the given value.
//   ifSourceMetagenerationNotMatch: Makes the operation conditional on whether
//     the source object's current metageneration does not match the given
//     value.
//   maxBytesRewrittenPerCall: The maximum number of bytes that will be
//     rewritten per rewrite request. Most callers shouldn't need to specify
//     this parameter - it is primarily in place to support testing. If
//     specified the value must be an integral multiple of 1 MiB (1048576).
//     Also, this only applies to requests where the source and destination span
//     locations and/or storage classes. Finally, this value must not change
//     across rewrite calls else you'll get an error that the rewriteToken is
//     invalid.
//   projection: Set of properties to return. Defaults to noAcl, unless the
//     object resource specifies the acl property, when it defaults to full.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit the acl property.
//   rewriteToken: Include this field (from the previous rewrite response) on
//     each rewrite request after the first one, until the rewrite response
//     'done' flag is true. Calls that provide a rewriteToken can omit all other
//     request fields, but if included those fields must match the values
//     provided in the first rewrite request.
//   sourceGeneration: If present, selects a specific revision of the source
//     object (as opposed to the latest version, the default).
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageRewriteResponse.
+ (instancetype)queryForObjectsRewriteWithSourceBucket:(NSString *)sourceBucket
                                          sourceObject:(NSString *)sourceObject
                                     destinationBucket:(NSString *)destinationBucket
                                     destinationObject:(NSString *)destinationObject;

// Method: storage.objects.update
// Updates an object's metadata.
//  Required:
//   bucket: Name of the bucket in which the object resides.
//   object: Name of the object.
//  Optional:
//   generation: If present, selects a specific revision of this object (as
//     opposed to the latest version, the default).
//   ifGenerationMatch: Makes the operation conditional on whether the object's
//     current generation matches the given value.
//   ifGenerationNotMatch: Makes the operation conditional on whether the
//     object's current generation does not match the given value.
//   ifMetagenerationMatch: Makes the operation conditional on whether the
//     object's current metageneration matches the given value.
//   ifMetagenerationNotMatch: Makes the operation conditional on whether the
//     object's current metageneration does not match the given value.
//   predefinedAcl: Apply a predefined set of access controls to this object.
//      kGTLStoragePredefinedAclAuthenticatedRead: Object owner gets OWNER
//        access, and allAuthenticatedUsers get READER access.
//      kGTLStoragePredefinedAclBucketOwnerFullControl: Object owner gets OWNER
//        access, and project team owners get OWNER access.
//      kGTLStoragePredefinedAclBucketOwnerRead: Object owner gets OWNER access,
//        and project team owners get READER access.
//      kGTLStoragePredefinedAclPrivate: Object owner gets OWNER access.
//      kGTLStoragePredefinedAclProjectPrivate: Object owner gets OWNER access,
//        and project team members get access according to their roles.
//      kGTLStoragePredefinedAclPublicRead: Object owner gets OWNER access, and
//        allUsers get READER access.
//   projection: Set of properties to return. Defaults to full.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit the acl property.
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageObject.
+ (instancetype)queryForObjectsUpdateWithObject:(GTLStorageObject *)object
                                         bucket:(NSString *)bucket
                                         object:(NSString *)object;

// Method: storage.objects.watchAll
// Watch for changes on all objects in a bucket.
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
//     The default value of this parameter is 1,000 items.
//   pageToken: A previously-returned page token representing part of the larger
//     set of results to view.
//   prefix: Filter results to objects whose names begin with this prefix.
//   projection: Set of properties to return. Defaults to noAcl.
//      kGTLStorageProjectionFull: Include all properties.
//      kGTLStorageProjectionNoAcl: Omit the acl property.
//   versions: If true, lists all versions of an object as distinct results. The
//     default is false. For more information, see Object Versioning.
//  Authorization scope(s):
//   kGTLAuthScopeStorageCloudPlatform
//   kGTLAuthScopeStorageDevstorageFullControl
//   kGTLAuthScopeStorageDevstorageReadOnly
//   kGTLAuthScopeStorageDevstorageReadWrite
// Fetches a GTLStorageChannel.
+ (instancetype)queryForObjectsWatchAllWithObject:(GTLStorageChannel *)object
                                           bucket:(NSString *)bucket;

@end

#pragma mark -
#pragma mark method parameter objects
// These object are used only to pass a collection of parameters to a
// method as a single item.

@class GTLStorageObjectsComposeSourceObjectsItemObjectPreconditions;

// ----------------------------------------------------------------------------
//
//   GTLStorageObjectsComposeSourceObjectsItem
//

// Used for 'sourceObjects' parameter on 'storage.objects.compose'.

@interface GTLStorageObjectsComposeSourceObjectsItem : GTLObject

// The generation of this object to use as the source.
@property (nonatomic, retain) NSNumber *generation;  // longLongValue

// The source object's name. The source object's bucket is implicitly the
// destination bucket.
@property (nonatomic, copy) NSString *name;

// Conditions that must be met for this operation to execute.
@property (nonatomic, retain) GTLStorageObjectsComposeSourceObjectsItemObjectPreconditions *objectPreconditions;

@end

// ----------------------------------------------------------------------------
//
//   GTLStorageObjectsComposeSourceObjectsItemObjectPreconditions
//

@interface GTLStorageObjectsComposeSourceObjectsItemObjectPreconditions : GTLObject

// Only perform the composition if the generation of the source object that
// would be used matches this value. If this value and a generation are both
// specified, they must be the same value or the call will fail.
@property (nonatomic, retain) NSNumber *ifGenerationMatch;  // longLongValue

@end
