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
//  GTLDiscoveryRpcMethod.m
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
//   GTLDiscoveryRpcMethod (0 custom class methods, 13 custom properties)
//   GTLDiscoveryRpcMethodMediaUpload (0 custom class methods, 2 custom properties)
//   GTLDiscoveryRpcMethodParameters (0 custom class methods, 0 custom properties)
//   GTLDiscoveryRpcMethodReturns (0 custom class methods, 1 custom properties)

#import "GTLDiscoveryRpcMethod.h"

#import "GTLDiscoveryJsonSchema.h"

// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRpcMethod
//

@implementation GTLDiscoveryRpcMethod
@dynamic allowGet, descriptionProperty, etagRequired, identifier, mediaUpload,
         parameterOrder, parameters, returns, scopes, supportsMediaDownload,
         supportsMediaUpload, supportsPatch, supportsSubscription;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"description", @"descriptionProperty",
      @"id", @"identifier",
      nil];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [NSString class], @"parameterOrder",
      [NSString class], @"scopes",
      nil];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRpcMethodMediaUpload
//

@implementation GTLDiscoveryRpcMethodMediaUpload
@dynamic accept, maxSize;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[NSString class]
                                forKey:@"accept"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRpcMethodParameters
//

@implementation GTLDiscoveryRpcMethodParameters

+ (Class)classForAdditionalProperties {
  return [GTLDiscoveryJsonSchema class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRpcMethodReturns
//

@implementation GTLDiscoveryRpcMethodReturns
@dynamic xRef;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"$ref"
                                forKey:@"xRef"];
  return map;
}

@end
