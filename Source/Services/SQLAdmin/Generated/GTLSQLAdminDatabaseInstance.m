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
//  GTLSQLAdminDatabaseInstance.m
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
//   GTLSQLAdminDatabaseInstance (0 custom class methods, 12 custom properties)

#import "GTLSQLAdminDatabaseInstance.h"

#import "GTLSQLAdminIpMapping.h"
#import "GTLSQLAdminSettings.h"
#import "GTLSQLAdminSslCert.h"

// ----------------------------------------------------------------------------
//
//   GTLSQLAdminDatabaseInstance
//

@implementation GTLSQLAdminDatabaseInstance
@dynamic currentDiskSize, databaseVersion, ETag, instance, ipAddresses, kind,
         maxDiskSize, project, region, serverCaCert, settings, state;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"etag"
                                forKey:@"ETag"];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLSQLAdminIpMapping class]
                                forKey:@"ipAddresses"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"sql#instance"];
}

@end
