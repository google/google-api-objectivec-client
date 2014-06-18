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
//  GTLBigqueryConstants.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   BigQuery API (bigquery/v2)
// Description:
//   A data platform for customers to create, manage, share and query data.
// Documentation:
//   https://developers.google.com/bigquery/docs/overview

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// View and manage your data in Google BigQuery
GTL_EXTERN NSString * const kGTLAuthScopeBigquery;              // "https://www.googleapis.com/auth/bigquery"
// View and manage your data across Google Cloud Platform services
GTL_EXTERN NSString * const kGTLAuthScopeBigqueryCloudPlatform;  // "https://www.googleapis.com/auth/cloud-platform"
// Manage your data and permissions in Google Cloud Storage
GTL_EXTERN NSString * const kGTLAuthScopeBigqueryDevstorageFullControl;  // "https://www.googleapis.com/auth/devstorage.full_control"
// View your data in Google Cloud Storage
GTL_EXTERN NSString * const kGTLAuthScopeBigqueryDevstorageReadOnly;  // "https://www.googleapis.com/auth/devstorage.read_only"
// Manage your data in Google Cloud Storage
GTL_EXTERN NSString * const kGTLAuthScopeBigqueryDevstorageReadWrite;  // "https://www.googleapis.com/auth/devstorage.read_write"
// Insert data into Google BigQuery
GTL_EXTERN NSString * const kGTLAuthScopeBigqueryInsertdata;    // "https://www.googleapis.com/auth/bigquery.insertdata"

// GTLQueryBigquery - Projection
GTL_EXTERN NSString * const kGTLBigqueryProjectionFull;     // "full"
GTL_EXTERN NSString * const kGTLBigqueryProjectionMinimal;  // "minimal"

// GTLQueryBigquery - StateFilter
GTL_EXTERN NSString * const kGTLBigqueryStateFilterDone;     // "done"
GTL_EXTERN NSString * const kGTLBigqueryStateFilterPending;  // "pending"
GTL_EXTERN NSString * const kGTLBigqueryStateFilterRunning;  // "running"
