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
//  GTLStorageConstants.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Cloud Storage API (storage/v1)
// Description:
//   Lets you store and retrieve potentially-large, immutable data objects.
// Documentation:
//   https://developers.google.com/storage/docs/json_api/

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// View and manage your data across Google Cloud Platform services
GTL_EXTERN NSString * const kGTLAuthScopeStorageCloudPlatform;  // "https://www.googleapis.com/auth/cloud-platform"
// MESSAGE UNDER CONSTRUCTION View your data across Google Cloud Platform
// services
GTL_EXTERN NSString * const kGTLAuthScopeStorageCloudPlatformReadOnly;  // "https://www.googleapis.com/auth/cloud-platform.read-only"
// Manage your data and permissions in Google Cloud Storage
GTL_EXTERN NSString * const kGTLAuthScopeStorageDevstorageFullControl;  // "https://www.googleapis.com/auth/devstorage.full_control"
// View your data in Google Cloud Storage
GTL_EXTERN NSString * const kGTLAuthScopeStorageDevstorageReadOnly;  // "https://www.googleapis.com/auth/devstorage.read_only"
// Manage your data in Google Cloud Storage
GTL_EXTERN NSString * const kGTLAuthScopeStorageDevstorageReadWrite;  // "https://www.googleapis.com/auth/devstorage.read_write"

// GTLQueryStorage - DestinationPredefinedAcl
GTL_EXTERN NSString * const kGTLStorageDestinationPredefinedAclAuthenticatedRead;  // "authenticatedRead"
GTL_EXTERN NSString * const kGTLStorageDestinationPredefinedAclBucketOwnerFullControl;  // "bucketOwnerFullControl"
GTL_EXTERN NSString * const kGTLStorageDestinationPredefinedAclBucketOwnerRead;  // "bucketOwnerRead"
GTL_EXTERN NSString * const kGTLStorageDestinationPredefinedAclPrivate;  // "private"
GTL_EXTERN NSString * const kGTLStorageDestinationPredefinedAclProjectPrivate;  // "projectPrivate"
GTL_EXTERN NSString * const kGTLStorageDestinationPredefinedAclPublicRead;  // "publicRead"

// GTLQueryStorage - PredefinedAcl
GTL_EXTERN NSString * const kGTLStoragePredefinedAclAuthenticatedRead;  // "authenticatedRead"
GTL_EXTERN NSString * const kGTLStoragePredefinedAclBucketOwnerFullControl;  // "bucketOwnerFullControl"
GTL_EXTERN NSString * const kGTLStoragePredefinedAclBucketOwnerRead;  // "bucketOwnerRead"
GTL_EXTERN NSString * const kGTLStoragePredefinedAclPrivate;    // "private"
GTL_EXTERN NSString * const kGTLStoragePredefinedAclProjectPrivate;  // "projectPrivate"
GTL_EXTERN NSString * const kGTLStoragePredefinedAclPublicRead;  // "publicRead"
GTL_EXTERN NSString * const kGTLStoragePredefinedAclPublicReadWrite;  // "publicReadWrite"

// GTLQueryStorage - PredefinedDefaultObjectAcl
GTL_EXTERN NSString * const kGTLStoragePredefinedDefaultObjectAclAuthenticatedRead;  // "authenticatedRead"
GTL_EXTERN NSString * const kGTLStoragePredefinedDefaultObjectAclBucketOwnerFullControl;  // "bucketOwnerFullControl"
GTL_EXTERN NSString * const kGTLStoragePredefinedDefaultObjectAclBucketOwnerRead;  // "bucketOwnerRead"
GTL_EXTERN NSString * const kGTLStoragePredefinedDefaultObjectAclPrivate;  // "private"
GTL_EXTERN NSString * const kGTLStoragePredefinedDefaultObjectAclProjectPrivate;  // "projectPrivate"
GTL_EXTERN NSString * const kGTLStoragePredefinedDefaultObjectAclPublicRead;  // "publicRead"

// GTLQueryStorage - Projection
GTL_EXTERN NSString * const kGTLStorageProjectionFull;   // "full"
GTL_EXTERN NSString * const kGTLStorageProjectionNoAcl;  // "noAcl"
