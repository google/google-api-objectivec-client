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
//  GTLServiceServiceRegistry.m
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
//   GTLServiceServiceRegistry (0 custom class methods, 0 custom properties)

#import "GTLServiceRegistry.h"

@implementation GTLServiceServiceRegistry

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = @[
    [GTLQueryServiceRegistry class],
    [GTLServiceRegistryEndpoint class],
    [GTLServiceRegistryEndpointEndpointVisibility class],
    [GTLServiceRegistryEndpointsListResponse class],
    [GTLServiceRegistryOperation class],
    [GTLServiceRegistryOperationsListResponse class]
  ];
  return classes;
}
#endif  // DEBUG

- (instancetype)init {
  self = [super init];
  if (self) {
    // Version from discovery.
    self.apiVersion = @"alpha";

    // From discovery.  Where to send JSON-RPC.
    // Turn off prettyPrint for this service to save bandwidth (especially on
    // mobile). The fetcher logging will pretty print.
    self.rpcURL = [NSURL URLWithString:@"https://www.googleapis.com/rpc?prettyPrint=false"];
  }
  return self;
}

@end
