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
//  GTLQueryServiceRegistry.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLServiceRegistryEndpoint;

@interface GTLQueryServiceRegistry : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (nonatomic, copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (nonatomic, copy) NSString *endpoint;
@property (nonatomic, copy) NSString *filter;
@property (nonatomic, assign) NSUInteger maxResults;
@property (nonatomic, copy) NSString *operation;
@property (nonatomic, copy) NSString *orderBy;
@property (nonatomic, copy) NSString *pageToken;
@property (nonatomic, copy) NSString *project;

#pragma mark - "endpoints" methods
// These create a GTLQueryServiceRegistry object.

// Method: serviceregistry.endpoints.delete
// Deletes an endpoint.
//  Required:
//   project: The project ID for this request.
//   endpoint: The name of the endpoint for this request.
//  Authorization scope(s):
//   kGTLAuthScopeServiceRegistryCloudPlatform
//   kGTLAuthScopeServiceRegistryNdevCloudman
// Fetches a GTLServiceRegistryOperation.
+ (instancetype)queryForEndpointsDeleteWithProject:(NSString *)project
                                          endpoint:(NSString *)endpoint;

// Method: serviceregistry.endpoints.get
// Gets an endpoint.
//  Required:
//   project: The project ID for this request.
//   endpoint: The name of the endpoint for this request.
//  Authorization scope(s):
//   kGTLAuthScopeServiceRegistryCloudPlatform
// Fetches a GTLServiceRegistryEndpoint.
+ (instancetype)queryForEndpointsGetWithProject:(NSString *)project
                                       endpoint:(NSString *)endpoint;

// Method: serviceregistry.endpoints.insert
// Creates an endpoint.
//  Required:
//   project: The project ID for this request.
//  Authorization scope(s):
//   kGTLAuthScopeServiceRegistryCloudPlatform
//   kGTLAuthScopeServiceRegistryNdevCloudman
// Fetches a GTLServiceRegistryOperation.
+ (instancetype)queryForEndpointsInsertWithObject:(GTLServiceRegistryEndpoint *)object
                                          project:(NSString *)project;

// Method: serviceregistry.endpoints.list
// Lists endpoints for a project.
//  Required:
//   project: The project ID for this request.
//  Optional:
//   filter: Sets a filter expression for filtering listed resources, in the
//     form filter={expression}. Your {expression} must be in the format:
//     field_name comparison_string literal_string.
//     The field_name is the name of the field you want to compare. Only atomic
//     field types are supported (string, number, boolean). The
//     comparison_string must be either eq (equals) or ne (not equals). The
//     literal_string is the string value to filter to. The literal value must
//     be valid for the type of field you are filtering by (string, number,
//     boolean). For string fields, the literal value is interpreted as a
//     regular expression using RE2 syntax. The literal value must match the
//     entire field.
//     For example, to filter for instances that do not have a name of
//     example-instance, you would use filter=name ne example-instance.
//     Compute Engine Beta API Only: When filtering in the Beta API, you can
//     also filter on nested fields. For example, you could filter on instances
//     that have set the scheduling.automaticRestart field to true. Use
//     filtering on nested fields to take advantage of labels to organize and
//     search for results based on label values.
//     The Beta API also supports filtering on multiple expressions by providing
//     each separate expression within parentheses. For example,
//     (scheduling.automaticRestart eq true) (zone eq us-central1-f). Multiple
//     expressions are treated as AND expressions, meaning that resources must
//     match all expressions to pass the filters.
//   maxResults: The maximum number of results per page that should be returned.
//     If the number of available results is larger than maxResults, Compute
//     Engine returns a nextPageToken that can be used to get the next page of
//     results in subsequent list requests. (0..500, default 500)
//   orderBy: Sorts list results by a certain order. By default, results are
//     returned in alphanumerical order based on the resource name.
//     You can also sort results in descending order based on the creation
//     timestamp using orderBy="creationTimestamp desc". This sorts results
//     based on the creationTimestamp field in reverse chronological order
//     (newest result first). Use this to sort resources like operations so that
//     the newest operation is returned first.
//     Currently, only sorting by name or creationTimestamp desc is supported.
//   pageToken: Specifies a page token to use. Set pageToken to the
//     nextPageToken returned by a previous list request to get the next page of
//     results.
//  Authorization scope(s):
//   kGTLAuthScopeServiceRegistryCloudPlatform
// Fetches a GTLServiceRegistryEndpointsListResponse.
+ (instancetype)queryForEndpointsListWithProject:(NSString *)project;

// Method: serviceregistry.endpoints.patch
// Updates an endpoint. This method supports patch semantics.
//  Required:
//   project: The project ID for this request.
//   endpoint: The name of the endpoint for this request.
//  Authorization scope(s):
//   kGTLAuthScopeServiceRegistryCloudPlatform
//   kGTLAuthScopeServiceRegistryNdevCloudman
// Fetches a GTLServiceRegistryOperation.
+ (instancetype)queryForEndpointsPatchWithObject:(GTLServiceRegistryEndpoint *)object
                                         project:(NSString *)project
                                        endpoint:(NSString *)endpoint;

// Method: serviceregistry.endpoints.update
// Updates an endpoint.
//  Required:
//   project: The project ID for this request.
//   endpoint: The name of the endpoint for this request.
//  Authorization scope(s):
//   kGTLAuthScopeServiceRegistryCloudPlatform
//   kGTLAuthScopeServiceRegistryNdevCloudman
// Fetches a GTLServiceRegistryOperation.
+ (instancetype)queryForEndpointsUpdateWithObject:(GTLServiceRegistryEndpoint *)object
                                          project:(NSString *)project
                                         endpoint:(NSString *)endpoint;

#pragma mark - "operations" methods
// These create a GTLQueryServiceRegistry object.

// Method: serviceregistry.operations.get
// Gets information about a specific operation.
//  Required:
//   project: The project ID for this request.
//   operation: The name of the operation for this request.
//  Authorization scope(s):
//   kGTLAuthScopeServiceRegistryCloudPlatform
//   kGTLAuthScopeServiceRegistryCloudPlatformReadOnly
//   kGTLAuthScopeServiceRegistryNdevCloudman
//   kGTLAuthScopeServiceRegistryNdevCloudmanReadonly
// Fetches a GTLServiceRegistryOperation.
+ (instancetype)queryForOperationsGetWithProject:(NSString *)project
                                       operation:(NSString *)operation;

// Method: serviceregistry.operations.list
// Lists all operations for a project.
//  Required:
//   project: The project ID for this request.
//  Optional:
//   filter: Sets a filter expression for filtering listed resources, in the
//     form filter={expression}. Your {expression} must be in the format:
//     field_name comparison_string literal_string.
//     The field_name is the name of the field you want to compare. Only atomic
//     field types are supported (string, number, boolean). The
//     comparison_string must be either eq (equals) or ne (not equals). The
//     literal_string is the string value to filter to. The literal value must
//     be valid for the type of field you are filtering by (string, number,
//     boolean). For string fields, the literal value is interpreted as a
//     regular expression using RE2 syntax. The literal value must match the
//     entire field.
//     For example, to filter for instances that do not have a name of
//     example-instance, you would use filter=name ne example-instance.
//     Compute Engine Beta API Only: When filtering in the Beta API, you can
//     also filter on nested fields. For example, you could filter on instances
//     that have set the scheduling.automaticRestart field to true. Use
//     filtering on nested fields to take advantage of labels to organize and
//     search for results based on label values.
//     The Beta API also supports filtering on multiple expressions by providing
//     each separate expression within parentheses. For example,
//     (scheduling.automaticRestart eq true) (zone eq us-central1-f). Multiple
//     expressions are treated as AND expressions, meaning that resources must
//     match all expressions to pass the filters.
//   maxResults: The maximum number of results per page that should be returned.
//     If the number of available results is larger than maxResults, Compute
//     Engine returns a nextPageToken that can be used to get the next page of
//     results in subsequent list requests. (0..500, default 500)
//   orderBy: Sorts list results by a certain order. By default, results are
//     returned in alphanumerical order based on the resource name.
//     You can also sort results in descending order based on the creation
//     timestamp using orderBy="creationTimestamp desc". This sorts results
//     based on the creationTimestamp field in reverse chronological order
//     (newest result first). Use this to sort resources like operations so that
//     the newest operation is returned first.
//     Currently, only sorting by name or creationTimestamp desc is supported.
//   pageToken: Specifies a page token to use. Set pageToken to the
//     nextPageToken returned by a previous list request to get the next page of
//     results.
//  Authorization scope(s):
//   kGTLAuthScopeServiceRegistryCloudPlatform
//   kGTLAuthScopeServiceRegistryCloudPlatformReadOnly
//   kGTLAuthScopeServiceRegistryNdevCloudman
//   kGTLAuthScopeServiceRegistryNdevCloudmanReadonly
// Fetches a GTLServiceRegistryOperationsListResponse.
+ (instancetype)queryForOperationsListWithProject:(NSString *)project;

@end
