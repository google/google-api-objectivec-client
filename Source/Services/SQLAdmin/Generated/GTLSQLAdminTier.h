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
//  GTLSQLAdminTier.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Cloud SQL Administration API (sqladmin/v1beta3)
// Description:
//   API for Cloud SQL database instance management.
// Documentation:
//   https://developers.google.com/cloud-sql/docs/admin-api/
// Classes:
//   GTLSQLAdminTier (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLSQLAdminTier
//

// A Google Cloud SQL service tier resource.

@interface GTLSQLAdminTier : GTLObject

// The maximum disk size of this tier in bytes.
@property (retain) NSNumber *DiskQuota;  // longLongValue

// This is always sql#tier.
@property (copy) NSString *kind;

// The maximum RAM usage of this tier in bytes.
@property (retain) NSNumber *RAM;  // longLongValue

// The applicable regions for this tier. Can be us-east1, europe-west1, or
// asia-east1.
@property (retain) NSArray *region;  // of NSString

// An identifier for the service tier, for example D1, D2 etc. For related
// information, see Pricing.
@property (copy) NSString *tier;

@end
