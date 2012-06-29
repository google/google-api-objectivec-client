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
//  GTLStorageObject.m
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

#import "GTLStorageObject.h"

#import "GTLStorageObjectAccessControl.h"

// ----------------------------------------------------------------------------
//
//   GTLStorageObject
//

@implementation GTLStorageObject
@dynamic acl, bucket, cacheControl, contentDisposition, contentEncoding,
         identifier, kind, media, metadata, name, owner, selfLink;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLStorageObjectAccessControl class]
                                forKey:@"acl"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"storage#object"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLStorageObjectMedia
//

@implementation GTLStorageObjectMedia
@dynamic algorithm, contentType, data, hashProperty, length, link, timeCreated;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"hash"
                                forKey:@"hashProperty"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLStorageObjectMetadata
//

@implementation GTLStorageObjectMetadata

+ (Class)classForAdditionalProperties {
  return [NSString class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLStorageObjectOwner
//

@implementation GTLStorageObjectOwner
@dynamic entity, entityId;
@end
