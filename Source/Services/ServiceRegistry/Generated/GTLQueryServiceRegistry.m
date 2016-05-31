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
//  GTLQueryServiceRegistry.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Cloud Service Registry API (serviceregistry/alpha)
// Description:
//   Manages service endpoints in Service Registry and provides integration with
//   DNS for service discovery and name resolution.
// Documentation:
//   https://cloud.google.com/service-registry/
// Classes:
//   GTLQueryServiceRegistry (8 custom class methods, 8 custom properties)

#import "GTLQueryServiceRegistry.h"

#import "GTLServiceRegistryEndpoint.h"
#import "GTLServiceRegistryEndpointsListResponse.h"
#import "GTLServiceRegistryOperation.h"
#import "GTLServiceRegistryOperationsListResponse.h"

@implementation GTLQueryServiceRegistry

@dynamic endpoint, fields, filter, maxResults, operation, orderBy, pageToken,
         project;

#pragma mark - "endpoints" methods
// These create a GTLQueryServiceRegistry object.

+ (instancetype)queryForEndpointsDeleteWithProject:(NSString *)project
                                          endpoint:(NSString *)endpoint {
  NSString *methodName = @"serviceregistry.endpoints.delete";
  GTLQueryServiceRegistry *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.endpoint = endpoint;
  query.expectedObjectClass = [GTLServiceRegistryOperation class];
  return query;
}

+ (instancetype)queryForEndpointsGetWithProject:(NSString *)project
                                       endpoint:(NSString *)endpoint {
  NSString *methodName = @"serviceregistry.endpoints.get";
  GTLQueryServiceRegistry *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.endpoint = endpoint;
  query.expectedObjectClass = [GTLServiceRegistryEndpoint class];
  return query;
}

+ (instancetype)queryForEndpointsInsertWithObject:(GTLServiceRegistryEndpoint *)object
                                          project:(NSString *)project {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"serviceregistry.endpoints.insert";
  GTLQueryServiceRegistry *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.project = project;
  query.expectedObjectClass = [GTLServiceRegistryOperation class];
  return query;
}

+ (instancetype)queryForEndpointsListWithProject:(NSString *)project {
  NSString *methodName = @"serviceregistry.endpoints.list";
  GTLQueryServiceRegistry *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLServiceRegistryEndpointsListResponse class];
  return query;
}

+ (instancetype)queryForEndpointsPatchWithObject:(GTLServiceRegistryEndpoint *)object
                                         project:(NSString *)project
                                        endpoint:(NSString *)endpoint {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"serviceregistry.endpoints.patch";
  GTLQueryServiceRegistry *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.project = project;
  query.endpoint = endpoint;
  query.expectedObjectClass = [GTLServiceRegistryOperation class];
  return query;
}

+ (instancetype)queryForEndpointsUpdateWithObject:(GTLServiceRegistryEndpoint *)object
                                          project:(NSString *)project
                                         endpoint:(NSString *)endpoint {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"serviceregistry.endpoints.update";
  GTLQueryServiceRegistry *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.project = project;
  query.endpoint = endpoint;
  query.expectedObjectClass = [GTLServiceRegistryOperation class];
  return query;
}

#pragma mark - "operations" methods
// These create a GTLQueryServiceRegistry object.

+ (instancetype)queryForOperationsGetWithProject:(NSString *)project
                                       operation:(NSString *)operation {
  NSString *methodName = @"serviceregistry.operations.get";
  GTLQueryServiceRegistry *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.operation = operation;
  query.expectedObjectClass = [GTLServiceRegistryOperation class];
  return query;
}

+ (instancetype)queryForOperationsListWithProject:(NSString *)project {
  NSString *methodName = @"serviceregistry.operations.list";
  GTLQueryServiceRegistry *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLServiceRegistryOperationsListResponse class];
  return query;
}

@end
