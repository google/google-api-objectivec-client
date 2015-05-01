/* Copyright (c) 2015 Google Inc.
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
//  GTLQueryDiscovery.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   APIs Discovery Service (discovery/v1)
// Description:
//   Lets you discover information about other Google APIs, such as what APIs
//   are available, the resource and method details for each API.
// Documentation:
//   https://developers.google.com/discovery/
// Classes:
//   GTLQueryDiscovery (3 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@interface GTLQueryDiscovery : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (nonatomic, copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (nonatomic, copy) NSString *api;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) BOOL preferred;
@property (nonatomic, copy) NSString *version;

#pragma mark -
#pragma mark "apis" methods
// These create a GTLQueryDiscovery object.

// Method: discovery.apis.getRest
// Retrieve the description of a particular version of an api.
//  Required:
//   api: The name of the API.
//   version: The version of the API.
// Fetches a GTLDiscoveryRestDescription.
+ (instancetype)queryForApisGetRestWithApi:(NSString *)api
                                   version:(NSString *)version;

// Method: discovery.apis.getRpc
// Retrieve the description of a particular version of an api.
//  Required:
//   api: The name of the API.
//   version: The version of the API.
// Fetches a GTLDiscoveryRpcDescription.
+ (instancetype)queryForApisGetRpcWithApi:(NSString *)api
                                  version:(NSString *)version;

// Method: discovery.apis.list
// Retrieve the list of APIs supported at this endpoint.
//  Optional:
//   name: Only include APIs with the given name.
//   preferred: Return only the preferred version of an API. (Default false)
// Fetches a GTLDiscoveryDirectoryList.
+ (instancetype)queryForApisList;

@end
