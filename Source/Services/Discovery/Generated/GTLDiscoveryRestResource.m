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
//  GTLDiscoveryRestResource.m
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
//   GTLDiscoveryRestResource (0 custom class methods, 2 custom properties)
//   GTLDiscoveryRestResourceMethods (0 custom class methods, 0 custom properties)
//   GTLDiscoveryRestResourceResources (0 custom class methods, 0 custom properties)

#import "GTLDiscoveryRestResource.h"

#import "GTLDiscoveryRestMethod.h"

// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestResource
//

@implementation GTLDiscoveryRestResource
@dynamic methods, resources;
@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestResourceMethods
//

@implementation GTLDiscoveryRestResourceMethods

+ (Class)classForAdditionalProperties {
  return [GTLDiscoveryRestMethod class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestResourceResources
//

@implementation GTLDiscoveryRestResourceResources

+ (Class)classForAdditionalProperties {
  return [GTLDiscoveryRestResource class];
}

@end
