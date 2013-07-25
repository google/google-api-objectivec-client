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
//  GTLStorageBucket.m
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
//   GTLStorageBucket (0 custom class methods, 17 custom properties)
//   GTLStorageBucketCorsItem (0 custom class methods, 4 custom properties)
//   GTLStorageBucketLifecycle (0 custom class methods, 1 custom properties)
//   GTLStorageBucketLogging (0 custom class methods, 2 custom properties)
//   GTLStorageBucketOwner (0 custom class methods, 2 custom properties)
//   GTLStorageBucketVersioning (0 custom class methods, 1 custom properties)
//   GTLStorageBucketWebsite (0 custom class methods, 2 custom properties)
//   GTLStorageBucketLifecycleRuleItem (0 custom class methods, 2 custom properties)
//   GTLStorageBucketLifecycleRuleItemAction (0 custom class methods, 1 custom properties)
//   GTLStorageBucketLifecycleRuleItemCondition (0 custom class methods, 4 custom properties)

#import "GTLStorageBucket.h"

#import "GTLStorageBucketAccessControl.h"
#import "GTLStorageObjectAccessControl.h"

// ----------------------------------------------------------------------------
//
//   GTLStorageBucket
//

@implementation GTLStorageBucket
@dynamic acl, cors, defaultObjectAcl, ETag, identifier, kind, lifecycle,
         location, logging, metageneration, name, owner, selfLink, storageClass,
         timeCreated, versioning, website;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"etag", @"ETag",
      @"id", @"identifier",
      nil];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLStorageBucketAccessControl class], @"acl",
      [GTLStorageBucketCorsItem class], @"cors",
      [GTLStorageObjectAccessControl class], @"defaultObjectAcl",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"storage#bucket"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLStorageBucketCorsItem
//

@implementation GTLStorageBucketCorsItem
@dynamic maxAgeSeconds, method, origin, responseHeader;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [NSString class], @"method",
      [NSString class], @"origin",
      [NSString class], @"responseHeader",
      nil];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLStorageBucketLifecycle
//

@implementation GTLStorageBucketLifecycle
@dynamic rule;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLStorageBucketLifecycleRuleItem class]
                                forKey:@"rule"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLStorageBucketLogging
//

@implementation GTLStorageBucketLogging
@dynamic logBucket, logObjectPrefix;
@end


// ----------------------------------------------------------------------------
//
//   GTLStorageBucketOwner
//

@implementation GTLStorageBucketOwner
@dynamic entity, entityId;
@end


// ----------------------------------------------------------------------------
//
//   GTLStorageBucketVersioning
//

@implementation GTLStorageBucketVersioning
@dynamic enabled;
@end


// ----------------------------------------------------------------------------
//
//   GTLStorageBucketWebsite
//

@implementation GTLStorageBucketWebsite
@dynamic mainPageSuffix, notFoundPage;
@end


// ----------------------------------------------------------------------------
//
//   GTLStorageBucketLifecycleRuleItem
//

@implementation GTLStorageBucketLifecycleRuleItem
@dynamic action, condition;
@end


// ----------------------------------------------------------------------------
//
//   GTLStorageBucketLifecycleRuleItemAction
//

@implementation GTLStorageBucketLifecycleRuleItemAction
@dynamic type;
@end


// ----------------------------------------------------------------------------
//
//   GTLStorageBucketLifecycleRuleItemCondition
//

@implementation GTLStorageBucketLifecycleRuleItemCondition
@dynamic age, createdBefore, isLive, numNewerVersions;
@end
