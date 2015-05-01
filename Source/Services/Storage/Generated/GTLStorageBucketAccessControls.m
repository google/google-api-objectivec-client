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
//  GTLStorageBucketAccessControls.m
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
//   GTLStorageBucketAccessControls (0 custom class methods, 2 custom properties)

#import "GTLStorageBucketAccessControls.h"

#import "GTLStorageBucketAccessControl.h"

// ----------------------------------------------------------------------------
//
//   GTLStorageBucketAccessControls
//

@implementation GTLStorageBucketAccessControls
@dynamic items, kind;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"items" : [GTLStorageBucketAccessControl class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"storage#bucketAccessControls"];
}

@end
