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
//  GTLSQLAdminInstanceOperation.h
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
//   GTLSQLAdminInstanceOperation (0 custom class methods, 12 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSQLAdminExportContext;
@class GTLSQLAdminImportContext;
@class GTLSQLAdminOperationError;

// ----------------------------------------------------------------------------
//
//   GTLSQLAdminInstanceOperation
//

// An Operations resource contains information about database instance
// operations such as create, delete, and restart. Operations resources are
// created in response to operations that were initiated; you never create them
// directly.

@interface GTLSQLAdminInstanceOperation : GTLObject

// The time this operation finished in UTC timezone in RFC 3339 format, for
// example 2012-11-15T16:19:00.094Z.
@property (retain) GTLDateTime *endTime;

// The time this operation was enqueued in UTC timezone in RFC 3339 format, for
// example 2012-11-15T16:19:00.094Z.
@property (retain) GTLDateTime *enqueuedTime;

// The error(s) encountered by this operation. Only set if the operation results
// in an error.
@property (retain) NSArray *error;  // of GTLSQLAdminOperationError

// The context for export operation, if applicable.
@property (retain) GTLSQLAdminExportContext *exportContext;

// The context for import operation, if applicable.
@property (retain) GTLSQLAdminImportContext *importContext;

// Name of the database instance.
@property (copy) NSString *instance;

// This is always sql#instanceOperation.
@property (copy) NSString *kind;

// An identifier that uniquely identifies the operation. You can use this
// identifier to retrieve the Operations resource that has information about the
// operation.
@property (copy) NSString *operation;

// The type of the operation. Valid values are CREATE, DELETE, UPDATE, RESTART,
// IMPORT, EXPORT, BACKUP_VOLUME, RESTORE_VOLUME.
@property (copy) NSString *operationType;

// The time this operation actually started in UTC timezone in RFC 3339 format,
// for example 2012-11-15T16:19:00.094Z.
@property (retain) GTLDateTime *startTime;

// The state of an operation. Valid values are PENDING, RUNNING, DONE, UNKNOWN.
@property (copy) NSString *state;

// The email address of the user who initiated this operation.
@property (copy) NSString *userEmailAddress;

@end
