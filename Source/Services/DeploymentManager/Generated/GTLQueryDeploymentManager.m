/* Copyright (c) 2016 Google Inc.
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
//  GTLQueryDeploymentManager.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Cloud Deployment Manager API (deploymentmanager/v2)
// Description:
//   Declares, configures, and deploys complex solutions on Google Cloud
//   Platform.
// Documentation:
//   https://cloud.google.com/deployment-manager/
// Classes:
//   GTLQueryDeploymentManager (15 custom class methods, 13 custom properties)

#import "GTLQueryDeploymentManager.h"

#import "GTLDeploymentManagerDeployment.h"
#import "GTLDeploymentManagerDeploymentsListResponse.h"
#import "GTLDeploymentManagerManifest.h"
#import "GTLDeploymentManagerManifestsListResponse.h"
#import "GTLDeploymentManagerOperation.h"
#import "GTLDeploymentManagerOperationsListResponse.h"
#import "GTLDeploymentManagerResource.h"
#import "GTLDeploymentManagerResourcesListResponse.h"
#import "GTLDeploymentManagerTypesListResponse.h"

@implementation GTLQueryDeploymentManager

@dynamic createPolicy, deletePolicy, deployment, fields, filter, fingerprint,
         manifest, maxResults, operation, pageToken, preview, project, resource;

#pragma mark - "deployments" methods
// These create a GTLQueryDeploymentManager object.

+ (instancetype)queryForDeploymentsCancelPreviewWithProject:(NSString *)project
                                                 deployment:(NSString *)deployment {
  NSString *methodName = @"deploymentmanager.deployments.cancelPreview";
  GTLQueryDeploymentManager *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.deployment = deployment;
  query.expectedObjectClass = [GTLDeploymentManagerOperation class];
  return query;
}

+ (instancetype)queryForDeploymentsDeleteWithProject:(NSString *)project
                                          deployment:(NSString *)deployment {
  NSString *methodName = @"deploymentmanager.deployments.delete";
  GTLQueryDeploymentManager *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.deployment = deployment;
  query.expectedObjectClass = [GTLDeploymentManagerOperation class];
  return query;
}

+ (instancetype)queryForDeploymentsGetWithProject:(NSString *)project
                                       deployment:(NSString *)deployment {
  NSString *methodName = @"deploymentmanager.deployments.get";
  GTLQueryDeploymentManager *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.deployment = deployment;
  query.expectedObjectClass = [GTLDeploymentManagerDeployment class];
  return query;
}

+ (instancetype)queryForDeploymentsInsertWithObject:(GTLDeploymentManagerDeployment *)object
                                            project:(NSString *)project {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"deploymentmanager.deployments.insert";
  GTLQueryDeploymentManager *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.project = project;
  query.expectedObjectClass = [GTLDeploymentManagerOperation class];
  return query;
}

+ (instancetype)queryForDeploymentsListWithProject:(NSString *)project {
  NSString *methodName = @"deploymentmanager.deployments.list";
  GTLQueryDeploymentManager *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLDeploymentManagerDeploymentsListResponse class];
  return query;
}

+ (instancetype)queryForDeploymentsPatchWithObject:(GTLDeploymentManagerDeployment *)object
                                           project:(NSString *)project
                                        deployment:(NSString *)deployment {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"deploymentmanager.deployments.patch";
  GTLQueryDeploymentManager *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.project = project;
  query.deployment = deployment;
  query.expectedObjectClass = [GTLDeploymentManagerOperation class];
  return query;
}

+ (instancetype)queryForDeploymentsStopWithProject:(NSString *)project
                                        deployment:(NSString *)deployment {
  NSString *methodName = @"deploymentmanager.deployments.stop";
  GTLQueryDeploymentManager *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.deployment = deployment;
  query.expectedObjectClass = [GTLDeploymentManagerOperation class];
  return query;
}

+ (instancetype)queryForDeploymentsUpdateWithObject:(GTLDeploymentManagerDeployment *)object
                                            project:(NSString *)project
                                         deployment:(NSString *)deployment {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"deploymentmanager.deployments.update";
  GTLQueryDeploymentManager *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.project = project;
  query.deployment = deployment;
  query.expectedObjectClass = [GTLDeploymentManagerOperation class];
  return query;
}

#pragma mark - "manifests" methods
// These create a GTLQueryDeploymentManager object.

+ (instancetype)queryForManifestsGetWithProject:(NSString *)project
                                     deployment:(NSString *)deployment
                                       manifest:(NSString *)manifest {
  NSString *methodName = @"deploymentmanager.manifests.get";
  GTLQueryDeploymentManager *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.deployment = deployment;
  query.manifest = manifest;
  query.expectedObjectClass = [GTLDeploymentManagerManifest class];
  return query;
}

+ (instancetype)queryForManifestsListWithProject:(NSString *)project
                                      deployment:(NSString *)deployment {
  NSString *methodName = @"deploymentmanager.manifests.list";
  GTLQueryDeploymentManager *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.deployment = deployment;
  query.expectedObjectClass = [GTLDeploymentManagerManifestsListResponse class];
  return query;
}

#pragma mark - "operations" methods
// These create a GTLQueryDeploymentManager object.

+ (instancetype)queryForOperationsGetWithProject:(NSString *)project
                                       operation:(NSString *)operation {
  NSString *methodName = @"deploymentmanager.operations.get";
  GTLQueryDeploymentManager *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.operation = operation;
  query.expectedObjectClass = [GTLDeploymentManagerOperation class];
  return query;
}

+ (instancetype)queryForOperationsListWithProject:(NSString *)project {
  NSString *methodName = @"deploymentmanager.operations.list";
  GTLQueryDeploymentManager *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLDeploymentManagerOperationsListResponse class];
  return query;
}

#pragma mark - "resources" methods
// These create a GTLQueryDeploymentManager object.

+ (instancetype)queryForResourcesGetWithProject:(NSString *)project
                                     deployment:(NSString *)deployment
                                       resource:(NSString *)resource {
  NSString *methodName = @"deploymentmanager.resources.get";
  GTLQueryDeploymentManager *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.deployment = deployment;
  query.resource = resource;
  query.expectedObjectClass = [GTLDeploymentManagerResource class];
  return query;
}

+ (instancetype)queryForResourcesListWithProject:(NSString *)project
                                      deployment:(NSString *)deployment {
  NSString *methodName = @"deploymentmanager.resources.list";
  GTLQueryDeploymentManager *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.deployment = deployment;
  query.expectedObjectClass = [GTLDeploymentManagerResourcesListResponse class];
  return query;
}

#pragma mark - "types" methods
// These create a GTLQueryDeploymentManager object.

+ (instancetype)queryForTypesListWithProject:(NSString *)project {
  NSString *methodName = @"deploymentmanager.types.list";
  GTLQueryDeploymentManager *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLDeploymentManagerTypesListResponse class];
  return query;
}

@end
