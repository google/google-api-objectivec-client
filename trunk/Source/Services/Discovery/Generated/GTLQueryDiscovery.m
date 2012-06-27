/* Copyright (c) 2011 Google Inc.
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
//  GTLQueryDiscovery.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   APIs Discovery Service (discovery/v1)
// Description:
//   Lets you discover information about other Google APIs, such as what APIs
//   are available, the resource and method details for each API
// Documentation:
//   http://code.google.com/apis/discovery
// Classes:
//   GTLQueryDiscovery (3 custom class methods, 6 custom properties)

#import "GTLQueryDiscovery.h"

#import "GTLDiscoveryDirectoryList.h"
#import "GTLDiscoveryRestDescription.h"
#import "GTLDiscoveryRpcDescription.h"

@implementation GTLQueryDiscovery

@dynamic api, fields, label, name, preferred, version;

#pragma mark -
#pragma mark "apis" methods
// These create a GTLQueryDiscovery object.

+ (id)queryForApisGetRestWithApi:(NSString *)api
                         version:(NSString *)version {
  NSString *methodName = @"discovery.apis.getRest";
  GTLQueryDiscovery *query = [self queryWithMethodName:methodName];
  query.api = api;
  query.version = version;
  query.expectedObjectClass = [GTLDiscoveryRestDescription class];
  return query;
}

+ (id)queryForApisGetRpcWithApi:(NSString *)api
                        version:(NSString *)version {
  NSString *methodName = @"discovery.apis.getRpc";
  GTLQueryDiscovery *query = [self queryWithMethodName:methodName];
  query.api = api;
  query.version = version;
  query.expectedObjectClass = [GTLDiscoveryRpcDescription class];
  return query;
}

+ (id)queryForApisList {
  NSString *methodName = @"discovery.apis.list";
  GTLQueryDiscovery *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLDiscoveryDirectoryList class];
  return query;
}

@end
