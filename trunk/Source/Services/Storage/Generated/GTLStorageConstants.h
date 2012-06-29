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
//  GTLStorageConstants.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Cloud Storage API (storage/v1beta1)
// Description:
//   Lets you store and retrieve potentially-large, immutable data objects.
// Documentation:
//   https://code.google.com/apis/storage/docs/developer-guide.html

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// Manage your data and permissions in Google Cloud Storage
GTL_EXTERN NSString * const kGTLAuthScopeStorageDevstorageFullControl;  // "https://www.googleapis.com/auth/devstorage.full_control"
// View your data in Google Cloud Storage
GTL_EXTERN NSString * const kGTLAuthScopeStorageDevstorageReadOnly;  // "https://www.googleapis.com/auth/devstorage.read_only"
// Manage your data in Google Cloud Storage
GTL_EXTERN NSString * const kGTLAuthScopeStorageDevstorageReadWrite;  // "https://www.googleapis.com/auth/devstorage.read_write"

// Projection
GTL_EXTERN NSString * const kGTLStorageProjectionFull;   // "full"
GTL_EXTERN NSString * const kGTLStorageProjectionNoAcl;  // "no_acl"
