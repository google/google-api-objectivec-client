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
//  GTLSQLAdminExportContext.h
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
//   GTLSQLAdminExportContext (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLSQLAdminExportContext
//

// Database instance export context.

@interface GTLSQLAdminExportContext : GTLObject

// Databases (for example, guestbook) from which the export is made. If
// unspecified, all databases are exported.
@property (retain) NSArray *database;  // of NSString

// This is always sql#exportContext.
@property (copy) NSString *kind;

// Tables to export, or that were exported, from the specified database. If you
// specify tables, specify one and only one database.
@property (retain) NSArray *table;  // of NSString

// The path to the file in Google Cloud Storage where the export will be stored,
// or where it was already stored. The URI is in the form
// gs://bucketName/fileName. If the file already exists, the operation fails. If
// the filename ends with .gz, the contents are compressed.
@property (copy) NSString *uri;

@end
