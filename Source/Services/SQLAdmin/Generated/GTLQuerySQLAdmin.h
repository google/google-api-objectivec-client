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
//  GTLQuerySQLAdmin.h
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
//   GTLQuerySQLAdmin (15 custom class methods, 10 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLSQLAdminDatabaseInstance;
@class GTLSQLAdminExportContext;
@class GTLSQLAdminImportContext;

@interface GTLQuerySQLAdmin : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (copy) NSString *backupConfiguration;
@property (copy) NSString *dueTime;
@property (retain) GTLSQLAdminExportContext *exportContext;
@property (retain) GTLSQLAdminImportContext *importContext;
@property (copy) NSString *instance;
// "maxResults" has different types for some query methods; see the
// documentation for the right type for each query method.
@property (retain) id maxResults;
@property (copy) NSString *operation;
@property (copy) NSString *pageToken;
@property (copy) NSString *project;

#pragma mark -
#pragma mark "backupRuns" methods
// These create a GTLQuerySQLAdmin object.

// Method: sql.backupRuns.get
// Retrieves a resource containing information about a backup run.
//  Required:
//   project: Project ID of the project that contains the instance. You can find
//     this on the project summary page of the Google APIs Console.
//   instance: Database instance ID. This does not include the project ID.
//   backupConfiguration: Identifier for the backup configuration. This gets
//     generated automatically when a backup configuration is created.
//   dueTime: The time when this run is due to start in RFC 3339 format, for
//     example 2012-11-15T16:19:00.094Z.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminBackupRun.
+ (id)queryForBackupRunsGetWithProject:(NSString *)project
                              instance:(NSString *)instance
                   backupConfiguration:(NSString *)backupConfiguration
                               dueTime:(NSString *)dueTime;

// Method: sql.backupRuns.list
// Lists all backup runs associated with a given instance and configuration in
// the reverse chronological order of the enqueued time.
//  Required:
//   project: Project ID of the project that contains the instance. You can find
//     this on the project summary page of the Google APIs Console.
//   instance: Database instance ID. This does not include the project ID.
//   backupConfiguration: Identifier for the backup configuration. This gets
//     generated automatically when a backup configuration is created.
//  Optional:
//   maxResults: Maximum number of backup runs per response.
//     Note: For this method, "maxResults" should be of type NSInteger.
//   pageToken: A previously-returned page token representing part of the larger
//     set of results to view.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminBackupRunsListResponse.
+ (id)queryForBackupRunsListWithProject:(NSString *)project
                               instance:(NSString *)instance
                    backupConfiguration:(NSString *)backupConfiguration;

#pragma mark -
#pragma mark "instances" methods
// These create a GTLQuerySQLAdmin object.

// Method: sql.instances.delete
// Deletes a database instance.
//  Required:
//   project: Project ID of the project that contains the instance to be
//     deleted. You can find this on the project summary page of the Google APIs
//     Console.
//   instance: Database instance ID. This does not include the project ID.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstancesDeleteResponse.
+ (id)queryForInstancesDeleteWithProject:(NSString *)project
                                instance:(NSString *)instance;

// Method: sql.instances.export
// Exports data from a database instance to a Google Cloud Storage bucket as a
// MySQL dump file.
//  Required:
//   project: Project ID of the project that contains the instance to be
//     exported. You can find this on the project summary page of the Google
//     APIs Console.
//   instance: Database instance ID. This does not include the project ID.
//  Optional:
//   exportContext: Contains details about the export operation.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminCloudPlatform
// Fetches a GTLSQLAdminInstancesExportResponse.
+ (id)queryForInstancesExportWithProject:(NSString *)project
                                instance:(NSString *)instance;

// Method: sql.instances.get
// Retrieves a resource containing information about a database instance.
//  Required:
//   project: Project ID of the project that contains the instance. You can find
//     this on the project summary page of the Google APIs Console.
//   instance: Database instance ID. This does not include the project ID.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminDatabaseInstance.
+ (id)queryForInstancesGetWithProject:(NSString *)project
                             instance:(NSString *)instance;

// Method: sql.instances.import
// Imports data into a database instance from a MySQL dump file in Google Cloud
// Storage.
//  Required:
//   project: Project ID of the project that contains the instance. You can find
//     this on the project summary page of the Google APIs Console.
//   instance: Database instance ID. This does not include the project ID.
//  Optional:
//   importContext: Contains details about the import operation.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminCloudPlatform
// Fetches a GTLSQLAdminInstancesImportResponse.
+ (id)queryForInstancesImportWithProject:(NSString *)project
                                instance:(NSString *)instance;

// Method: sql.instances.insert
// Creates a new database instance.
//  Required:
//   project: Project ID of the project to which the newly created database
//     instances should belong. You can find this on the project summary page of
//     the Google APIs Console.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstancesInsertResponse.
+ (id)queryForInstancesInsertWithObject:(GTLSQLAdminDatabaseInstance *)object
                                project:(NSString *)project;

// Method: sql.instances.list
// Lists instances under a given project in the alphabetical order of the
// instance name.
//  Required:
//   project: Project ID of the project for which to list database instances.
//     You can find this on the project summary page of the Google APIs Console.
//  Optional:
//   maxResults: The maximum number of results to return per response.
//     Note: For this method, "maxResults" should be of type NSUInteger.
//   pageToken: A previously-returned page token representing part of the larger
//     set of results to view.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstancesListResponse.
+ (id)queryForInstancesListWithProject:(NSString *)project;

// Method: sql.instances.patch
// Updates settings of a database instance. Caution: This is not a partial
// update, so you must include values for all the settings that you want to
// retain. For partial updates, use patch.. This method supports patch
// semantics.
//  Required:
//   project: Project ID of the project that contains the instance. You can find
//     this on the project summary page of the Google APIs Console.
//   instance: Database instance ID. This does not include the project ID.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstancesUpdateResponse.
+ (id)queryForInstancesPatchWithObject:(GTLSQLAdminDatabaseInstance *)object
                               project:(NSString *)project
                              instance:(NSString *)instance;

// Method: sql.instances.restart
// Restarts a database instance.
//  Required:
//   project: Project ID of the project that contains the instance to be
//     restarted. You can find this on the project summary page of the Google
//     APIs Console.
//   instance: Database instance ID. This does not include the project ID.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstancesRestartResponse.
+ (id)queryForInstancesRestartWithProject:(NSString *)project
                                 instance:(NSString *)instance;

// Method: sql.instances.restoreBackup
// Restores a backup of a database instance.
//  Required:
//   project: Project ID of the project that contains the instance. You can find
//     this on the project summary page of the Google APIs Console.
//   instance: Database instance ID. This does not include the project ID.
//   backupConfiguration: The identifier of the backup configuration. This gets
//     generated automatically when a backup configuration is created.
//   dueTime: The time when this run is due to start in RFC 3339 format, for
//     example 2012-11-15T16:19:00.094Z.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstancesRestoreBackupResponse.
+ (id)queryForInstancesRestoreBackupWithProject:(NSString *)project
                                       instance:(NSString *)instance
                            backupConfiguration:(NSString *)backupConfiguration
                                        dueTime:(NSString *)dueTime;

// Method: sql.instances.update
// Updates settings of a database instance. Caution: This is not a partial
// update, so you must include values for all the settings that you want to
// retain. For partial updates, use patch.
//  Required:
//   project: Project ID of the project that contains the instance. You can find
//     this on the project summary page of the Google APIs Console.
//   instance: Database instance ID. This does not include the project ID.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstancesUpdateResponse.
+ (id)queryForInstancesUpdateWithObject:(GTLSQLAdminDatabaseInstance *)object
                                project:(NSString *)project
                               instance:(NSString *)instance;

#pragma mark -
#pragma mark "operations" methods
// These create a GTLQuerySQLAdmin object.

// Method: sql.operations.get
// Retrieves an instance operation that has been performed on an instance.
//  Required:
//   project: Project ID of the project that contains the instance. You can find
//     this on the project summary page of the Google APIs Console.
//   instance: Database instance ID. This does not include the project ID.
//   operation: Instance operation ID.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstanceOperation.
+ (id)queryForOperationsGetWithProject:(NSString *)project
                              instance:(NSString *)instance
                             operation:(NSString *)operation;

// Method: sql.operations.list
// Lists all instance operations that have been performed on the given database
// instance in the reverse chronological order of the start time.
//  Required:
//   project: Project ID of the project that contains the instance. You can find
//     this on the project summary page of the Google APIs Console.
//   instance: Database instance ID. This does not include the project ID.
//  Optional:
//   maxResults: Maximum number of operations per response.
//     Note: For this method, "maxResults" should be of type NSUInteger.
//   pageToken: A previously-returned page token representing part of the larger
//     set of results to view.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminOperationsListResponse.
+ (id)queryForOperationsListWithProject:(NSString *)project
                               instance:(NSString *)instance;

#pragma mark -
#pragma mark "tiers" methods
// These create a GTLQuerySQLAdmin object.

// Method: sql.tiers.list
// Lists all available service tiers for Google Cloud SQL, for example D1, D2.
// For related information, see Pricing.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminTiersListResponse.
+ (id)queryForTiersList;

@end
