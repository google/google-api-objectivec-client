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
//  GTLSQLAdminBackupRun.h
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
//   GTLSQLAdminBackupRun (0 custom class methods, 9 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSQLAdminOperationError;

// ----------------------------------------------------------------------------
//
//   GTLSQLAdminBackupRun
//

// A database instance backup run resource.

@interface GTLSQLAdminBackupRun : GTLObject

// Backup Configuration identifier.
@property (copy) NSString *backupConfiguration;

// The due time of this run in UTC timezone in RFC 3339 format, for example
// 2012-11-15T16:19:00.094Z.
@property (retain) GTLDateTime *dueTime;

// The time the backup operation completed in UTC timezone in RFC 3339 format,
// for example 2012-11-15T16:19:00.094Z.
@property (retain) GTLDateTime *endTime;

// The time the run was enqueued in UTC timezone in RFC 3339 format, for example
// 2012-11-15T16:19:00.094Z.
@property (retain) GTLDateTime *enqueuedTime;

// Information about why the backup operation failed. This is only present if
// the run has the FAILED status.
@property (retain) GTLSQLAdminOperationError *error;

// Name of the database instance.
@property (copy) NSString *instance;

// This is always sql#backupRun.
@property (copy) NSString *kind;

// The time the backup operation actually started in UTC timezone in RFC 3339
// format, for example 2012-11-15T16:19:00.094Z.
@property (retain) GTLDateTime *startTime;

// The status of this run.
@property (copy) NSString *status;

@end
