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
//  GTLQueryStorage.m
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

#import "GTLQueryStorage.h"

#import "GTLStorageBucket.h"
#import "GTLStorageBucketAccessControl.h"
#import "GTLStorageBucketAccessControls.h"
#import "GTLStorageBuckets.h"
#import "GTLStorageChannel.h"
#import "GTLStorageObject.h"
#import "GTLStorageObjectAccessControl.h"
#import "GTLStorageObjectAccessControls.h"
#import "GTLStorageObjects.h"
#import "GTLStorageRewriteResponse.h"

@implementation GTLQueryStorage

@dynamic bucket, contentEncoding, delimiter, destination, destinationResource,
         destinationBucket, destinationObject, destinationPredefinedAcl, entity,
         fields, generation, ifGenerationMatch, ifGenerationNotMatch,
         ifMetagenerationMatch, ifMetagenerationNotMatch,
         ifSourceGenerationMatch, ifSourceGenerationNotMatch,
         ifSourceMetagenerationMatch, ifSourceMetagenerationNotMatch, kind,
         maxBytesRewrittenPerCall, maxResults, name, object, pageToken,
         predefinedAcl, predefinedDefaultObjectAcl, prefix, project, projection,
         rewriteToken, sourceBucket, sourceGeneration, sourceObject,
         sourceObjects, versions;

+ (NSDictionary *)parameterNameMap {
  NSDictionary *map = @{
    @"destinationResource" : @"destination_resource"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"sourceObjects" : [GTLStorageObjectsComposeSourceObjectsItem class]
  };
  return map;
}

#pragma mark - "bucketAccessControls" methods
// These create a GTLQueryStorage object.

+ (instancetype)queryForBucketAccessControlsDeleteWithBucket:(NSString *)bucket
                                                      entity:(NSString *)entity {
  NSString *methodName = @"storage.bucketAccessControls.delete";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.entity = entity;
  return query;
}

+ (instancetype)queryForBucketAccessControlsGetWithBucket:(NSString *)bucket
                                                   entity:(NSString *)entity {
  NSString *methodName = @"storage.bucketAccessControls.get";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.entity = entity;
  query.expectedObjectClass = [GTLStorageBucketAccessControl class];
  return query;
}

+ (instancetype)queryForBucketAccessControlsInsertWithObject:(GTLStorageBucketAccessControl *)object
                                                      bucket:(NSString *)bucket {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.bucketAccessControls.insert";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.bucket = bucket;
  query.expectedObjectClass = [GTLStorageBucketAccessControl class];
  return query;
}

+ (instancetype)queryForBucketAccessControlsListWithBucket:(NSString *)bucket {
  NSString *methodName = @"storage.bucketAccessControls.list";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.expectedObjectClass = [GTLStorageBucketAccessControls class];
  return query;
}

+ (instancetype)queryForBucketAccessControlsPatchWithObject:(GTLStorageBucketAccessControl *)object
                                                     bucket:(NSString *)bucket
                                                     entity:(NSString *)entity {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.bucketAccessControls.patch";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.bucket = bucket;
  query.entity = entity;
  query.expectedObjectClass = [GTLStorageBucketAccessControl class];
  return query;
}

+ (instancetype)queryForBucketAccessControlsUpdateWithObject:(GTLStorageBucketAccessControl *)object
                                                      bucket:(NSString *)bucket
                                                      entity:(NSString *)entity {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.bucketAccessControls.update";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.bucket = bucket;
  query.entity = entity;
  query.expectedObjectClass = [GTLStorageBucketAccessControl class];
  return query;
}

#pragma mark - "buckets" methods
// These create a GTLQueryStorage object.

+ (instancetype)queryForBucketsDeleteWithBucket:(NSString *)bucket {
  NSString *methodName = @"storage.buckets.delete";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  return query;
}

+ (instancetype)queryForBucketsGetWithBucket:(NSString *)bucket {
  NSString *methodName = @"storage.buckets.get";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.expectedObjectClass = [GTLStorageBucket class];
  return query;
}

+ (instancetype)queryForBucketsInsertWithObject:(GTLStorageBucket *)object
                                        project:(NSString *)project {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.buckets.insert";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.project = project;
  query.expectedObjectClass = [GTLStorageBucket class];
  return query;
}

+ (instancetype)queryForBucketsListWithProject:(NSString *)project {
  NSString *methodName = @"storage.buckets.list";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLStorageBuckets class];
  return query;
}

+ (instancetype)queryForBucketsPatchWithObject:(GTLStorageBucket *)object
                                        bucket:(NSString *)bucket {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.buckets.patch";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.bucket = bucket;
  query.expectedObjectClass = [GTLStorageBucket class];
  return query;
}

+ (instancetype)queryForBucketsUpdateWithObject:(GTLStorageBucket *)object
                                         bucket:(NSString *)bucket {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.buckets.update";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.bucket = bucket;
  query.expectedObjectClass = [GTLStorageBucket class];
  return query;
}

#pragma mark - "channels" methods
// These create a GTLQueryStorage object.

+ (instancetype)queryForChannelsStopWithObject:(GTLStorageChannel *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.channels.stop";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  return query;
}

#pragma mark - "defaultObjectAccessControls" methods
// These create a GTLQueryStorage object.

+ (instancetype)queryForDefaultObjectAccessControlsDeleteWithBucket:(NSString *)bucket
                                                             entity:(NSString *)entity {
  NSString *methodName = @"storage.defaultObjectAccessControls.delete";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.entity = entity;
  return query;
}

+ (instancetype)queryForDefaultObjectAccessControlsGetWithBucket:(NSString *)bucket
                                                          entity:(NSString *)entity {
  NSString *methodName = @"storage.defaultObjectAccessControls.get";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.entity = entity;
  query.expectedObjectClass = [GTLStorageObjectAccessControl class];
  return query;
}

+ (instancetype)queryForDefaultObjectAccessControlsInsertWithObject:(GTLStorageObjectAccessControl *)object
                                                             bucket:(NSString *)bucket {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.defaultObjectAccessControls.insert";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.bucket = bucket;
  query.expectedObjectClass = [GTLStorageObjectAccessControl class];
  return query;
}

+ (instancetype)queryForDefaultObjectAccessControlsListWithBucket:(NSString *)bucket {
  NSString *methodName = @"storage.defaultObjectAccessControls.list";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.expectedObjectClass = [GTLStorageObjectAccessControls class];
  return query;
}

+ (instancetype)queryForDefaultObjectAccessControlsPatchWithObject:(GTLStorageObjectAccessControl *)object
                                                            bucket:(NSString *)bucket
                                                            entity:(NSString *)entity {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.defaultObjectAccessControls.patch";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.bucket = bucket;
  query.entity = entity;
  query.expectedObjectClass = [GTLStorageObjectAccessControl class];
  return query;
}

+ (instancetype)queryForDefaultObjectAccessControlsUpdateWithObject:(GTLStorageObjectAccessControl *)object
                                                             bucket:(NSString *)bucket
                                                             entity:(NSString *)entity {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.defaultObjectAccessControls.update";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.bucket = bucket;
  query.entity = entity;
  query.expectedObjectClass = [GTLStorageObjectAccessControl class];
  return query;
}

#pragma mark - "objectAccessControls" methods
// These create a GTLQueryStorage object.

+ (instancetype)queryForObjectAccessControlsDeleteWithBucket:(NSString *)bucket
                                                      object:(NSString *)object_param
                                                      entity:(NSString *)entity {
  NSString *methodName = @"storage.objectAccessControls.delete";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.object = object_param;
  query.entity = entity;
  return query;
}

+ (instancetype)queryForObjectAccessControlsGetWithBucket:(NSString *)bucket
                                                   object:(NSString *)object_param
                                                   entity:(NSString *)entity {
  NSString *methodName = @"storage.objectAccessControls.get";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.object = object_param;
  query.entity = entity;
  query.expectedObjectClass = [GTLStorageObjectAccessControl class];
  return query;
}

+ (instancetype)queryForObjectAccessControlsInsertWithObject:(GTLStorageObjectAccessControl *)object
                                                      bucket:(NSString *)bucket
                                                      object:(NSString *)object_param {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.objectAccessControls.insert";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.bucket = bucket;
  query.object = object_param;
  query.expectedObjectClass = [GTLStorageObjectAccessControl class];
  return query;
}

+ (instancetype)queryForObjectAccessControlsListWithBucket:(NSString *)bucket
                                                    object:(NSString *)object_param {
  NSString *methodName = @"storage.objectAccessControls.list";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.object = object_param;
  query.expectedObjectClass = [GTLStorageObjectAccessControls class];
  return query;
}

+ (instancetype)queryForObjectAccessControlsPatchWithObject:(GTLStorageObjectAccessControl *)object
                                                     bucket:(NSString *)bucket
                                                     object:(NSString *)object_param
                                                     entity:(NSString *)entity {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.objectAccessControls.patch";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.bucket = bucket;
  query.object = object_param;
  query.entity = entity;
  query.expectedObjectClass = [GTLStorageObjectAccessControl class];
  return query;
}

+ (instancetype)queryForObjectAccessControlsUpdateWithObject:(GTLStorageObjectAccessControl *)object
                                                      bucket:(NSString *)bucket
                                                      object:(NSString *)object_param
                                                      entity:(NSString *)entity {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.objectAccessControls.update";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.bucket = bucket;
  query.object = object_param;
  query.entity = entity;
  query.expectedObjectClass = [GTLStorageObjectAccessControl class];
  return query;
}

#pragma mark - "objects" methods
// These create a GTLQueryStorage object.

+ (instancetype)queryForObjectsComposeWithDestinationBucket:(NSString *)destinationBucket
                                          destinationObject:(NSString *)destinationObject {
  NSString *methodName = @"storage.objects.compose";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.destinationBucket = destinationBucket;
  query.destinationObject = destinationObject;
  query.expectedObjectClass = [GTLStorageObject class];
  return query;
}

+ (instancetype)queryForObjectsCopyWithSourceBucket:(NSString *)sourceBucket
                                       sourceObject:(NSString *)sourceObject
                                  destinationBucket:(NSString *)destinationBucket
                                  destinationObject:(NSString *)destinationObject {
  NSString *methodName = @"storage.objects.copy";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.sourceBucket = sourceBucket;
  query.sourceObject = sourceObject;
  query.destinationBucket = destinationBucket;
  query.destinationObject = destinationObject;
  query.expectedObjectClass = [GTLStorageObject class];
  return query;
}

+ (instancetype)queryForObjectsDeleteWithBucket:(NSString *)bucket
                                         object:(NSString *)object_param {
  NSString *methodName = @"storage.objects.delete";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.object = object_param;
  return query;
}

+ (instancetype)queryForObjectsGetWithBucket:(NSString *)bucket
                                      object:(NSString *)object_param {
  NSString *methodName = @"storage.objects.get";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.object = object_param;
  query.expectedObjectClass = [GTLStorageObject class];
  return query;
}

+ (instancetype)queryForObjectsInsertWithObject:(GTLStorageObject *)object
                                         bucket:(NSString *)bucket
                               uploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.objects.insert";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.bucket = bucket;
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLStorageObject class];
  return query;
}

+ (instancetype)queryForObjectsListWithBucket:(NSString *)bucket {
  NSString *methodName = @"storage.objects.list";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.expectedObjectClass = [GTLStorageObjects class];
  return query;
}

+ (instancetype)queryForObjectsPatchWithObject:(GTLStorageObject *)object
                                        bucket:(NSString *)bucket
                                        object:(NSString *)object_param {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.objects.patch";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.bucket = bucket;
  query.object = object_param;
  query.expectedObjectClass = [GTLStorageObject class];
  return query;
}

+ (instancetype)queryForObjectsRewriteWithSourceBucket:(NSString *)sourceBucket
                                          sourceObject:(NSString *)sourceObject
                                     destinationBucket:(NSString *)destinationBucket
                                     destinationObject:(NSString *)destinationObject {
  NSString *methodName = @"storage.objects.rewrite";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.sourceBucket = sourceBucket;
  query.sourceObject = sourceObject;
  query.destinationBucket = destinationBucket;
  query.destinationObject = destinationObject;
  query.expectedObjectClass = [GTLStorageRewriteResponse class];
  return query;
}

+ (instancetype)queryForObjectsUpdateWithObject:(GTLStorageObject *)object
                                         bucket:(NSString *)bucket
                                         object:(NSString *)object_param {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.objects.update";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.bucket = bucket;
  query.object = object_param;
  query.expectedObjectClass = [GTLStorageObject class];
  return query;
}

+ (instancetype)queryForObjectsWatchAllWithObject:(GTLStorageChannel *)object
                                           bucket:(NSString *)bucket {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.objects.watchAll";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.bucket = bucket;
  query.expectedObjectClass = [GTLStorageChannel class];
  return query;
}

@end

#pragma mark - method parameter objects
// These object are used only to pass a collection of parameters to a
// method as a single item.

// ----------------------------------------------------------------------------
//
//   GTLStorageObjectsComposeSourceObjectsItem
//

@implementation GTLStorageObjectsComposeSourceObjectsItem
@dynamic generation, name, objectPreconditions;
@end

// ----------------------------------------------------------------------------
//
//   GTLStorageObjectsComposeSourceObjectsItemObjectPreconditions
//

@implementation GTLStorageObjectsComposeSourceObjectsItemObjectPreconditions
@dynamic ifGenerationMatch;
@end
