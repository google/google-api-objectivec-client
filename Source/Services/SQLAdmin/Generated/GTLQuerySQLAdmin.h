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
//  GTLQuerySQLAdmin.h
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
//   GTLQuerySQLAdmin (24 custom class methods, 14 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLSQLAdminCloneContext;
@class GTLSQLAdminDatabaseInstance;
@class GTLSQLAdminExportContext;
@class GTLSQLAdminImportContext;
@class GTLSQLAdminSetRootPasswordContext;

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
@property (retain) GTLSQLAdminCloneContext *cloneContext;
@property (copy) NSString *commonName;
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
@property (retain) GTLSQLAdminSetRootPasswordContext *setRootPasswordContext;
@property (copy) NSString *sha1Fingerprint;

#pragma mark -
#pragma mark "backupRuns" methods
// These create a GTLQuerySQLAdmin object.

// Method: sql.backupRuns.get
// Retrieves information about a specified backup run for a Cloud SQL instance.
//  Required:
//   project: Project ID of the project that contains the instance.
//   instance: Cloud SQL instance ID. This does not include the project ID.
//   backupConfiguration: Identifier for the backup configuration. This gets
//     generated automatically when a backup configuration is created.
//   dueTime: The start time of the four-hour backup window. The backup can
//     occur any time in the window. The time is in RFC 3339 format, for example
//     2012-11-15T16:19:00.094Z.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminBackupRun.
+ (id)queryForBackupRunsGetWithProject:(NSString *)project
                              instance:(NSString *)instance
                   backupConfiguration:(NSString *)backupConfiguration
                               dueTime:(NSString *)dueTime;

// Method: sql.backupRuns.list
// Lists all backup runs associated with a Cloud SQL instance.
//  Required:
//   project: Project ID of the project that contains the instance.
//   instance: Cloud SQL instance ID. This does not include the project ID.
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
#pragma mark "flags" methods
// These create a GTLQuerySQLAdmin object.

// Method: sql.flags.list
// Lists all database flags that can be set for Google Cloud SQL instances.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminFlagsListResponse.
+ (id)queryForFlagsList;

#pragma mark -
#pragma mark "instances" methods
// These create a GTLQuerySQLAdmin object.

// Method: sql.instances.clone
// Creates a Cloud SQL instance as a clone of a source instance.
//  Required:
//   project: Project ID of the source as well as the clone Cloud SQL instance.
//  Optional:
//   cloneContext: Contains details about the clone operation.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstancesCloneResponse.
+ (id)queryForInstancesCloneWithProject:(NSString *)project;

// Method: sql.instances.delete
// Deletes a Cloud SQL instance.
//  Required:
//   project: Project ID of the project that contains the instance to be
//     deleted.
//   instance: Cloud SQL instance ID. This does not include the project ID.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstancesDeleteResponse.
+ (id)queryForInstancesDeleteWithProject:(NSString *)project
                                instance:(NSString *)instance;

// Method: sql.instances.export
// Exports data from a Cloud SQL instance to a Google Cloud Storage bucket as a
// MySQL dump file.
//  Required:
//   project: Project ID of the project that contains the instance to be
//     exported.
//   instance: Cloud SQL instance ID. This does not include the project ID.
//  Optional:
//   exportContext: Contains details about the export operation.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminCloudPlatform
// Fetches a GTLSQLAdminInstancesExportResponse.
+ (id)queryForInstancesExportWithProject:(NSString *)project
                                instance:(NSString *)instance;

// Method: sql.instances.get
// Retrieves information about a Cloud SQL instance.
//  Required:
//   project: Project ID of the project that contains the instance.
//   instance: Database instance ID. This does not include the project ID.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminDatabaseInstance.
+ (id)queryForInstancesGetWithProject:(NSString *)project
                             instance:(NSString *)instance;

// Method: sql.instances.import
// Imports data into a Cloud SQL instance from a MySQL dump file stored in a
// Google Cloud Storage bucket.
//  Required:
//   project: Project ID of the project that contains the instance.
//   instance: Cloud SQL instance ID. This does not include the project ID.
//  Optional:
//   importContext: Contains details about the import operation.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminCloudPlatform
// Fetches a GTLSQLAdminInstancesImportResponse.
+ (id)queryForInstancesImportWithProject:(NSString *)project
                                instance:(NSString *)instance;

// Method: sql.instances.insert
// Creates a new Cloud SQL instance.
//  Required:
//   project: Project ID of the project to which the newly created Cloud SQL
//     instances should belong.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstancesInsertResponse.
+ (id)queryForInstancesInsertWithObject:(GTLSQLAdminDatabaseInstance *)object
                                project:(NSString *)project;

// Method: sql.instances.list
// Lists instances for a given project, in alphabetical order by instance name.
//  Required:
//   project: Project ID of the project for which to list Cloud SQL instances.
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
// Updates the settings of a Cloud SQL instance. This method supports patch
// semantics.
//  Required:
//   project: Project ID of the project that contains the instance.
//   instance: Cloud SQL instance ID. This does not include the project ID.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstancesUpdateResponse.
+ (id)queryForInstancesPatchWithObject:(GTLSQLAdminDatabaseInstance *)object
                               project:(NSString *)project
                              instance:(NSString *)instance;

// Method: sql.instances.promoteReplica
// Promotes the read replica instance to be a stand-alone Cloud SQL instance.
//  Required:
//   project: ID of the project that contains the read replica.
//   instance: Cloud SQL read replica instance name.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstancesPromoteReplicaResponse.
+ (id)queryForInstancesPromoteReplicaWithProject:(NSString *)project
                                        instance:(NSString *)instance;

// Method: sql.instances.resetSslConfig
// Deletes all client certificates and generates a new server SSL certificate
// for a Cloud SQL instance.
//  Required:
//   project: Project ID of the project that contains the instance.
//   instance: Cloud SQL instance ID. This does not include the project ID.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstancesResetSslConfigResponse.
+ (id)queryForInstancesResetSslConfigWithProject:(NSString *)project
                                        instance:(NSString *)instance;

// Method: sql.instances.restart
// Restarts a Cloud SQL instance.
//  Required:
//   project: Project ID of the project that contains the instance to be
//     restarted.
//   instance: Cloud SQL instance ID. This does not include the project ID.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstancesRestartResponse.
+ (id)queryForInstancesRestartWithProject:(NSString *)project
                                 instance:(NSString *)instance;

// Method: sql.instances.restoreBackup
// Restores a backup of a Cloud SQL instance.
//  Required:
//   project: Project ID of the project that contains the instance.
//   instance: Cloud SQL instance ID. This does not include the project ID.
//   backupConfiguration: The identifier of the backup configuration. This gets
//     generated automatically when a backup configuration is created.
//   dueTime: The start time of the four-hour backup window. The backup can
//     occur any time in the window. The time is in RFC 3339 format, for example
//     2012-11-15T16:19:00.094Z.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstancesRestoreBackupResponse.
+ (id)queryForInstancesRestoreBackupWithProject:(NSString *)project
                                       instance:(NSString *)instance
                            backupConfiguration:(NSString *)backupConfiguration
                                        dueTime:(NSString *)dueTime;

// Method: sql.instances.setRootPassword
// Sets the password for the root user of the specified Cloud SQL instance.
//  Required:
//   project: Project ID of the project that contains the instance.
//   instance: Cloud SQL instance ID. This does not include the project ID.
//  Optional:
//   setRootPasswordContext: Set Root Password Context.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstancesSetRootPasswordResponse.
+ (id)queryForInstancesSetRootPasswordWithProject:(NSString *)project
                                         instance:(NSString *)instance;

// Method: sql.instances.update
// Updates the settings of a Cloud SQL instance.
//  Required:
//   project: Project ID of the project that contains the instance.
//   instance: Cloud SQL instance ID. This does not include the project ID.
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
// Retrieves information about a specific operation that was performed on a
// Cloud SQL instance.
//  Required:
//   project: Project ID of the project that contains the instance.
//   instance: Cloud SQL instance ID. This does not include the project ID.
//   operation: Instance operation ID.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminInstanceOperation.
+ (id)queryForOperationsGetWithProject:(NSString *)project
                              instance:(NSString *)instance
                             operation:(NSString *)operation;

// Method: sql.operations.list
// Lists all operations that have been performed on a Cloud SQL instance.
//  Required:
//   project: Project ID of the project that contains the instance.
//   instance: Cloud SQL instance ID. This does not include the project ID.
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
#pragma mark "sslCerts" methods
// These create a GTLQuerySQLAdmin object.

// Method: sql.sslCerts.delete
// Deletes an SSL certificate from a Cloud SQL instance.
//  Required:
//   project: Project ID of the project that contains the instance to be
//     deleted.
//   instance: Cloud SQL instance ID. This does not include the project ID.
//   sha1Fingerprint: Sha1 FingerPrint.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminSslCertsDeleteResponse.
+ (id)queryForSslCertsDeleteWithProject:(NSString *)project
                               instance:(NSString *)instance
                        sha1Fingerprint:(NSString *)sha1Fingerprint;

// Method: sql.sslCerts.get
// Retrieves an SSL certificate as specified by its SHA-1 fingerprint.
//  Required:
//   project: Project ID of the project that contains the instance.
//   instance: Cloud SQL instance ID. This does not include the project ID.
//   sha1Fingerprint: Sha1 FingerPrint.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminSslCert.
+ (id)queryForSslCertsGetWithProject:(NSString *)project
                            instance:(NSString *)instance
                     sha1Fingerprint:(NSString *)sha1Fingerprint;

// Method: sql.sslCerts.insert
// Creates an SSL certificate and returns the certificate, the associated
// private key, and the server certificate authority.
//  Required:
//   project: Project ID of the project to which the newly created Cloud SQL
//     instances should belong.
//   instance: Cloud SQL instance ID. This does not include the project ID.
//  Optional:
//   commonName: User supplied name. Must be a distinct name from the other
//     certificates for this instance. New certificates will not be usable until
//     the instance is restarted.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminSslCertsInsertResponse.
+ (id)queryForSslCertsInsertWithProject:(NSString *)project
                               instance:(NSString *)instance;

// Method: sql.sslCerts.list
// Lists all of the current SSL certificates defined for a Cloud SQL instance.
//  Required:
//   project: Project ID of the project for which to list Cloud SQL instances.
//   instance: Cloud SQL instance ID. This does not include the project ID.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminSslCertsListResponse.
+ (id)queryForSslCertsListWithProject:(NSString *)project
                             instance:(NSString *)instance;

#pragma mark -
#pragma mark "tiers" methods
// These create a GTLQuerySQLAdmin object.

// Method: sql.tiers.list
// Lists service tiers that can be used to create Google Cloud SQL instances.
//  Required:
//   project: Project ID of the project for which to list tiers.
//  Authorization scope(s):
//   kGTLAuthScopeSQLAdminSqlserviceAdmin
// Fetches a GTLSQLAdminTiersListResponse.
+ (id)queryForTiersListWithProject:(NSString *)project;

@end
