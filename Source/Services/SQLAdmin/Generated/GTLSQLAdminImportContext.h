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
//  GTLSQLAdminImportContext.h
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
//   GTLSQLAdminImportContext (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLSQLAdminImportContext
//

// Database instance import context.

@interface GTLSQLAdminImportContext : GTLObject

// The database (for example, guestbook) to which the import is made. If not
// set, it is assumed that the database is specified in the file to be imported.
@property (copy) NSString *database;

// This is always sql#importContext.
@property (copy) NSString *kind;

// A path to the MySQL dump file in Google Cloud Storage from which the import
// is made. The URI is in the form gs://bucketName/fileName. Compressed gzip
// files (.gz) are also supported.
@property (retain) NSArray *uri;  // of NSString

@end
