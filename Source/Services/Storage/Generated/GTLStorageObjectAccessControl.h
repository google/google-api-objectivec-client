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
//  GTLStorageObjectAccessControl.h
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
//   GTLStorageObjectAccessControl (0 custom class methods, 12 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLStorageObjectAccessControl
//

// An access-control entry.

@interface GTLStorageObjectAccessControl : GTLObject

// The name of the bucket.
@property (copy) NSString *bucket;

// The domain associated with the entity, if any.
@property (copy) NSString *domain;

// The email address associated with the entity, if any.
@property (copy) NSString *email;

// The entity holding the permission, in one of the following forms:
// - user-userId
// - user-email
// - group-groupId
// - group-email
// - domain-domain
// - allUsers
// - allAuthenticatedUsers Examples:
// - The user liz@example.com would be user-liz@example.com.
// - The group example@googlegroups.com would be group-example@googlegroups.com.
// - To refer to all members of the Google Apps for Business domain example.com,
// the entity would be domain-example.com.
@property (copy) NSString *entity;

// The ID for the entity, if any.
@property (copy) NSString *entityId;

// HTTP 1.1 Entity tag for the access-control entry.
@property (copy) NSString *ETag;

// The content generation of the object.
@property (retain) NSNumber *generation;  // longLongValue

// The ID of the access-control entry.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The kind of item this is. For object access control entries, this is always
// storage#objectAccessControl.
@property (copy) NSString *kind;

// The name of the object.
@property (copy) NSString *object;

// The access permission for the entity. Can be READER or OWNER.
@property (copy) NSString *role;

// The link to this access-control entry.
@property (copy) NSString *selfLink;

@end
