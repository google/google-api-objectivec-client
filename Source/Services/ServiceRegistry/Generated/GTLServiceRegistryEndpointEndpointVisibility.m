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
//  GTLServiceRegistryEndpointEndpointVisibility.m
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
//   GTLServiceRegistryEndpointEndpointVisibility (0 custom class methods, 2 custom properties)

#import "GTLServiceRegistryEndpointEndpointVisibility.h"

// ----------------------------------------------------------------------------
//
//   GTLServiceRegistryEndpointEndpointVisibility
//

@implementation GTLServiceRegistryEndpointEndpointVisibility
@dynamic internalDnsName, networks;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"networks" : [NSString class]
  };
  return map;
}

@end
