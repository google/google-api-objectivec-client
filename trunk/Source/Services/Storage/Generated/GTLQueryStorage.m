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
//  GTLQueryStorage.m
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
//   GTLQueryStorage (34 custom class methods, 30 custom properties)
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

@implementation GTLQueryStorage

@dynamic bucket, delimiter, destination, destinationResource, destinationBucket,
         destinationObject, entity, fields, generation, ifGenerationMatch,
         ifGenerationNotMatch, ifMetagenerationMatch, ifMetagenerationNotMatch,
         ifSourceGenerationMatch, ifSourceGenerationNotMatch,
         ifSourceMetagenerationMatch, ifSourceMetagenerationNotMatch, kind,
         maxResults, name, object, pageToken, prefix, project, projection,
         sourceBucket, sourceGeneration, sourceObject, sourceObjects, versions;

+ (NSDictionary *)parameterNameMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"destination_resource"
                                forKey:@"destinationResource"];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLStorageObjectsComposeSourceObjectsItem class]
                                forKey:@"sourceObjects"];
  return map;
}

#pragma mark -
#pragma mark "bucketAccessControls" methods
// These create a GTLQueryStorage object.

+ (id)queryForBucketAccessControlsDeleteWithBucket:(NSString *)bucket
                                            entity:(NSString *)entity {
  NSString *methodName = @"storage.bucketAccessControls.delete";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.entity = entity;
  return query;
}

+ (id)queryForBucketAccessControlsGetWithBucket:(NSString *)bucket
                                         entity:(NSString *)entity {
  NSString *methodName = @"storage.bucketAccessControls.get";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.entity = entity;
  query.expectedObjectClass = [GTLStorageBucketAccessControl class];
  return query;
}

+ (id)queryForBucketAccessControlsInsertWithObject:(GTLStorageBucketAccessControl *)object
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

+ (id)queryForBucketAccessControlsListWithBucket:(NSString *)bucket {
  NSString *methodName = @"storage.bucketAccessControls.list";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.expectedObjectClass = [GTLStorageBucketAccessControls class];
  return query;
}

+ (id)queryForBucketAccessControlsPatchWithObject:(GTLStorageBucketAccessControl *)object
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

+ (id)queryForBucketAccessControlsUpdateWithObject:(GTLStorageBucketAccessControl *)object
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

#pragma mark -
#pragma mark "buckets" methods
// These create a GTLQueryStorage object.

+ (id)queryForBucketsDeleteWithBucket:(NSString *)bucket {
  NSString *methodName = @"storage.buckets.delete";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  return query;
}

+ (id)queryForBucketsGetWithBucket:(NSString *)bucket {
  NSString *methodName = @"storage.buckets.get";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.expectedObjectClass = [GTLStorageBucket class];
  return query;
}

+ (id)queryForBucketsInsertWithObject:(GTLStorageBucket *)object
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

+ (id)queryForBucketsListWithProject:(NSString *)project {
  NSString *methodName = @"storage.buckets.list";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLStorageBuckets class];
  return query;
}

+ (id)queryForBucketsPatchWithObject:(GTLStorageBucket *)object
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

+ (id)queryForBucketsUpdateWithObject:(GTLStorageBucket *)object
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

#pragma mark -
#pragma mark "channels" methods
// These create a GTLQueryStorage object.

+ (id)queryForChannelsStopWithObject:(GTLStorageChannel *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"storage.channels.stop";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  return query;
}

#pragma mark -
#pragma mark "defaultObjectAccessControls" methods
// These create a GTLQueryStorage object.

+ (id)queryForDefaultObjectAccessControlsDeleteWithBucket:(NSString *)bucket
                                                   entity:(NSString *)entity {
  NSString *methodName = @"storage.defaultObjectAccessControls.delete";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.entity = entity;
  return query;
}

+ (id)queryForDefaultObjectAccessControlsGetWithBucket:(NSString *)bucket
                                                entity:(NSString *)entity {
  NSString *methodName = @"storage.defaultObjectAccessControls.get";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.entity = entity;
  query.expectedObjectClass = [GTLStorageObjectAccessControl class];
  return query;
}

+ (id)queryForDefaultObjectAccessControlsInsertWithObject:(GTLStorageObjectAccessControl *)object
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

+ (id)queryForDefaultObjectAccessControlsListWithBucket:(NSString *)bucket {
  NSString *methodName = @"storage.defaultObjectAccessControls.list";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.expectedObjectClass = [GTLStorageObjectAccessControls class];
  return query;
}

+ (id)queryForDefaultObjectAccessControlsPatchWithObject:(GTLStorageObjectAccessControl *)object
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

+ (id)queryForDefaultObjectAccessControlsUpdateWithObject:(GTLStorageObjectAccessControl *)object
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

#pragma mark -
#pragma mark "objectAccessControls" methods
// These create a GTLQueryStorage object.

+ (id)queryForObjectAccessControlsDeleteWithBucket:(NSString *)bucket
                                            object:(NSString *)object_param
                                            entity:(NSString *)entity {
  NSString *methodName = @"storage.objectAccessControls.delete";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.object = object_param;
  query.entity = entity;
  return query;
}

+ (id)queryForObjectAccessControlsGetWithBucket:(NSString *)bucket
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

+ (id)queryForObjectAccessControlsInsertWithObject:(GTLStorageObjectAccessControl *)object
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

+ (id)queryForObjectAccessControlsListWithBucket:(NSString *)bucket
                                          object:(NSString *)object_param {
  NSString *methodName = @"storage.objectAccessControls.list";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.object = object_param;
  query.expectedObjectClass = [GTLStorageObjectAccessControls class];
  return query;
}

+ (id)queryForObjectAccessControlsPatchWithObject:(GTLStorageObjectAccessControl *)object
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

+ (id)queryForObjectAccessControlsUpdateWithObject:(GTLStorageObjectAccessControl *)object
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

#pragma mark -
#pragma mark "objects" methods
// These create a GTLQueryStorage object.

+ (id)queryForObjectsComposeWithDestinationBucket:(NSString *)destinationBucket
                                destinationObject:(NSString *)destinationObject {
  NSString *methodName = @"storage.objects.compose";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.destinationBucket = destinationBucket;
  query.destinationObject = destinationObject;
  query.expectedObjectClass = [GTLStorageObject class];
  return query;
}

+ (id)queryForObjectsCopyWithSourceBucket:(NSString *)sourceBucket
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

+ (id)queryForObjectsDeleteWithBucket:(NSString *)bucket
                               object:(NSString *)object_param {
  NSString *methodName = @"storage.objects.delete";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.object = object_param;
  return query;
}

+ (id)queryForObjectsGetWithBucket:(NSString *)bucket
                            object:(NSString *)object_param {
  NSString *methodName = @"storage.objects.get";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.object = object_param;
  query.expectedObjectClass = [GTLStorageObject class];
  return query;
}

+ (id)queryForObjectsInsertWithObject:(GTLStorageObject *)object
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

+ (id)queryForObjectsListWithBucket:(NSString *)bucket {
  NSString *methodName = @"storage.objects.list";
  GTLQueryStorage *query = [self queryWithMethodName:methodName];
  query.bucket = bucket;
  query.expectedObjectClass = [GTLStorageObjects class];
  return query;
}

+ (id)queryForObjectsPatchWithObject:(GTLStorageObject *)object
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

+ (id)queryForObjectsUpdateWithObject:(GTLStorageObject *)object
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

+ (id)queryForObjectsWatchAllWithObject:(GTLStorageChannel *)object
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

#pragma mark -
#pragma mark method parameter objects
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
