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
//  GTLQuerySQLAdmin.m
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
//   GTLQuerySQLAdmin (23 custom class methods, 14 custom properties)

#import "GTLQuerySQLAdmin.h"

#import "GTLSQLAdminBackupRun.h"
#import "GTLSQLAdminBackupRunsListResponse.h"
#import "GTLSQLAdminCloneContext.h"
#import "GTLSQLAdminDatabaseInstance.h"
#import "GTLSQLAdminExportContext.h"
#import "GTLSQLAdminFlagsListResponse.h"
#import "GTLSQLAdminImportContext.h"
#import "GTLSQLAdminInstanceOperation.h"
#import "GTLSQLAdminInstancesCloneResponse.h"
#import "GTLSQLAdminInstancesDeleteResponse.h"
#import "GTLSQLAdminInstancesExportResponse.h"
#import "GTLSQLAdminInstancesImportResponse.h"
#import "GTLSQLAdminInstancesInsertResponse.h"
#import "GTLSQLAdminInstancesListResponse.h"
#import "GTLSQLAdminInstancesResetSslConfigResponse.h"
#import "GTLSQLAdminInstancesRestartResponse.h"
#import "GTLSQLAdminInstancesRestoreBackupResponse.h"
#import "GTLSQLAdminInstancesSetRootPasswordResponse.h"
#import "GTLSQLAdminInstancesUpdateResponse.h"
#import "GTLSQLAdminOperationsListResponse.h"
#import "GTLSQLAdminSetRootPasswordContext.h"
#import "GTLSQLAdminSslCert.h"
#import "GTLSQLAdminSslCertsDeleteResponse.h"
#import "GTLSQLAdminSslCertsInsertResponse.h"
#import "GTLSQLAdminSslCertsListResponse.h"
#import "GTLSQLAdminTiersListResponse.h"

@implementation GTLQuerySQLAdmin

@dynamic backupConfiguration, cloneContext, commonName, dueTime, exportContext,
         fields, importContext, instance, maxResults, operation, pageToken,
         project, setRootPasswordContext, sha1Fingerprint;

#pragma mark -
#pragma mark "backupRuns" methods
// These create a GTLQuerySQLAdmin object.

+ (id)queryForBackupRunsGetWithProject:(NSString *)project
                              instance:(NSString *)instance
                   backupConfiguration:(NSString *)backupConfiguration
                               dueTime:(NSString *)dueTime {
  NSString *methodName = @"sql.backupRuns.get";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.instance = instance;
  query.backupConfiguration = backupConfiguration;
  query.dueTime = dueTime;
  query.expectedObjectClass = [GTLSQLAdminBackupRun class];
  return query;
}

+ (id)queryForBackupRunsListWithProject:(NSString *)project
                               instance:(NSString *)instance
                    backupConfiguration:(NSString *)backupConfiguration {
  NSString *methodName = @"sql.backupRuns.list";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.instance = instance;
  query.backupConfiguration = backupConfiguration;
  query.expectedObjectClass = [GTLSQLAdminBackupRunsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "flags" methods
// These create a GTLQuerySQLAdmin object.

+ (id)queryForFlagsList {
  NSString *methodName = @"sql.flags.list";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLSQLAdminFlagsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "instances" methods
// These create a GTLQuerySQLAdmin object.

+ (id)queryForInstancesCloneWithProject:(NSString *)project {
  NSString *methodName = @"sql.instances.clone";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLSQLAdminInstancesCloneResponse class];
  return query;
}

+ (id)queryForInstancesDeleteWithProject:(NSString *)project
                                instance:(NSString *)instance {
  NSString *methodName = @"sql.instances.delete";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.instance = instance;
  query.expectedObjectClass = [GTLSQLAdminInstancesDeleteResponse class];
  return query;
}

+ (id)queryForInstancesExportWithProject:(NSString *)project
                                instance:(NSString *)instance {
  NSString *methodName = @"sql.instances.export";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.instance = instance;
  query.expectedObjectClass = [GTLSQLAdminInstancesExportResponse class];
  return query;
}

+ (id)queryForInstancesGetWithProject:(NSString *)project
                             instance:(NSString *)instance {
  NSString *methodName = @"sql.instances.get";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.instance = instance;
  query.expectedObjectClass = [GTLSQLAdminDatabaseInstance class];
  return query;
}

+ (id)queryForInstancesImportWithProject:(NSString *)project
                                instance:(NSString *)instance {
  NSString *methodName = @"sql.instances.import";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.instance = instance;
  query.expectedObjectClass = [GTLSQLAdminInstancesImportResponse class];
  return query;
}

+ (id)queryForInstancesInsertWithObject:(GTLSQLAdminDatabaseInstance *)object
                                project:(NSString *)project {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"sql.instances.insert";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.project = project;
  query.expectedObjectClass = [GTLSQLAdminInstancesInsertResponse class];
  return query;
}

+ (id)queryForInstancesListWithProject:(NSString *)project {
  NSString *methodName = @"sql.instances.list";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLSQLAdminInstancesListResponse class];
  return query;
}

+ (id)queryForInstancesPatchWithObject:(GTLSQLAdminDatabaseInstance *)object
                               project:(NSString *)project
                              instance:(NSString *)instance {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"sql.instances.patch";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.project = project;
  query.instance = instance;
  query.expectedObjectClass = [GTLSQLAdminInstancesUpdateResponse class];
  return query;
}

+ (id)queryForInstancesResetSslConfigWithProject:(NSString *)project
                                        instance:(NSString *)instance {
  NSString *methodName = @"sql.instances.resetSslConfig";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.instance = instance;
  query.expectedObjectClass = [GTLSQLAdminInstancesResetSslConfigResponse class];
  return query;
}

+ (id)queryForInstancesRestartWithProject:(NSString *)project
                                 instance:(NSString *)instance {
  NSString *methodName = @"sql.instances.restart";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.instance = instance;
  query.expectedObjectClass = [GTLSQLAdminInstancesRestartResponse class];
  return query;
}

+ (id)queryForInstancesRestoreBackupWithProject:(NSString *)project
                                       instance:(NSString *)instance
                            backupConfiguration:(NSString *)backupConfiguration
                                        dueTime:(NSString *)dueTime {
  NSString *methodName = @"sql.instances.restoreBackup";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.instance = instance;
  query.backupConfiguration = backupConfiguration;
  query.dueTime = dueTime;
  query.expectedObjectClass = [GTLSQLAdminInstancesRestoreBackupResponse class];
  return query;
}

+ (id)queryForInstancesSetRootPasswordWithProject:(NSString *)project
                                         instance:(NSString *)instance {
  NSString *methodName = @"sql.instances.setRootPassword";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.instance = instance;
  query.expectedObjectClass = [GTLSQLAdminInstancesSetRootPasswordResponse class];
  return query;
}

+ (id)queryForInstancesUpdateWithObject:(GTLSQLAdminDatabaseInstance *)object
                                project:(NSString *)project
                               instance:(NSString *)instance {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"sql.instances.update";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.project = project;
  query.instance = instance;
  query.expectedObjectClass = [GTLSQLAdminInstancesUpdateResponse class];
  return query;
}

#pragma mark -
#pragma mark "operations" methods
// These create a GTLQuerySQLAdmin object.

+ (id)queryForOperationsGetWithProject:(NSString *)project
                              instance:(NSString *)instance
                             operation:(NSString *)operation {
  NSString *methodName = @"sql.operations.get";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.instance = instance;
  query.operation = operation;
  query.expectedObjectClass = [GTLSQLAdminInstanceOperation class];
  return query;
}

+ (id)queryForOperationsListWithProject:(NSString *)project
                               instance:(NSString *)instance {
  NSString *methodName = @"sql.operations.list";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.instance = instance;
  query.expectedObjectClass = [GTLSQLAdminOperationsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "sslCerts" methods
// These create a GTLQuerySQLAdmin object.

+ (id)queryForSslCertsDeleteWithProject:(NSString *)project
                               instance:(NSString *)instance
                        sha1Fingerprint:(NSString *)sha1Fingerprint {
  NSString *methodName = @"sql.sslCerts.delete";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.instance = instance;
  query.sha1Fingerprint = sha1Fingerprint;
  query.expectedObjectClass = [GTLSQLAdminSslCertsDeleteResponse class];
  return query;
}

+ (id)queryForSslCertsGetWithProject:(NSString *)project
                            instance:(NSString *)instance
                     sha1Fingerprint:(NSString *)sha1Fingerprint {
  NSString *methodName = @"sql.sslCerts.get";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.instance = instance;
  query.sha1Fingerprint = sha1Fingerprint;
  query.expectedObjectClass = [GTLSQLAdminSslCert class];
  return query;
}

+ (id)queryForSslCertsInsertWithProject:(NSString *)project
                               instance:(NSString *)instance {
  NSString *methodName = @"sql.sslCerts.insert";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.instance = instance;
  query.expectedObjectClass = [GTLSQLAdminSslCertsInsertResponse class];
  return query;
}

+ (id)queryForSslCertsListWithProject:(NSString *)project
                             instance:(NSString *)instance {
  NSString *methodName = @"sql.sslCerts.list";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.instance = instance;
  query.expectedObjectClass = [GTLSQLAdminSslCertsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "tiers" methods
// These create a GTLQuerySQLAdmin object.

+ (id)queryForTiersListWithProject:(NSString *)project {
  NSString *methodName = @"sql.tiers.list";
  GTLQuerySQLAdmin *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLSQLAdminTiersListResponse class];
  return query;
}

@end
