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
//  GTLSQLAdminSettings.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Cloud SQL Administration API (sqladmin/v1beta1)
// Description:
//   API for Cloud SQL database instance management.
// Documentation:
//   https://developers.google.com/cloud-sql/docs/admin-api/
// Classes:
//   GTLSQLAdminSettings (0 custom class methods, 7 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSQLAdminBackupConfiguration;

// ----------------------------------------------------------------------------
//
//   GTLSQLAdminSettings
//

// Database instance settings.

@interface GTLSQLAdminSettings : GTLObject

// The activation policy for this instance. This specifies when the instance
// should be activated and is applicable only when the instance state is
// RUNNABLE. This can be one of the following.
// ALWAYS: The instance should always be active.
// NEVER: The instance should never be activated.
// ON_DEMAND: The instance is activated upon receiving requests.
@property (copy) NSString *activationPolicy;

// The AppEngine app ids that can access this instance.
@property (retain) NSArray *authorizedGaeApplications;  // of NSString

// The daily backup configuration for the instance.
@property (retain) NSArray *backupConfiguration;  // of GTLSQLAdminBackupConfiguration

// This is always sql#settings.
@property (copy) NSString *kind;

// The pricing plan for this instance. This can be either PER_USE or PACKAGE.
@property (copy) NSString *pricingPlan;

// The type of replication this instance uses. This can be either ASYNCHRONOUS
// or SYNCHRONOUS.
@property (copy) NSString *replicationType;

// The tier of service for this instance, for example D1, D2. For more
// information, see pricing.
@property (copy) NSString *tier;

@end
