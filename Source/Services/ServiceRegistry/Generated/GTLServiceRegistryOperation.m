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
//  GTLServiceRegistryOperation.m
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
//   GTLServiceRegistryOperation (0 custom class methods, 23 custom properties)
//   GTLServiceRegistryOperationError (0 custom class methods, 1 custom properties)
//   GTLServiceRegistryOperationWarningsItem (0 custom class methods, 3 custom properties)
//   GTLServiceRegistryOperationErrorErrorsItem (0 custom class methods, 3 custom properties)
//   GTLServiceRegistryOperationWarningsItemDataItem (0 custom class methods, 2 custom properties)

#import "GTLServiceRegistryOperation.h"

// ----------------------------------------------------------------------------
//
//   GTLServiceRegistryOperation
//

@implementation GTLServiceRegistryOperation
@dynamic clientOperationId, creationTimestamp, descriptionProperty, endTime,
         error, httpErrorMessage, httpErrorStatusCode, identifier, insertTime,
         kind, name, operationType, progress, region, selfLink, startTime,
         status, statusMessage, targetId, targetLink, user, warnings,
         zoneProperty;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"descriptionProperty" : @"description",
    @"identifier" : @"id",
    @"zoneProperty" : @"zone"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"warnings" : [GTLServiceRegistryOperationWarningsItem class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"serviceregistry#operation"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLServiceRegistryOperationError
//

@implementation GTLServiceRegistryOperationError
@dynamic errors;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"errors" : [GTLServiceRegistryOperationErrorErrorsItem class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLServiceRegistryOperationWarningsItem
//

@implementation GTLServiceRegistryOperationWarningsItem
@dynamic code, data, message;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"data" : [GTLServiceRegistryOperationWarningsItemDataItem class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLServiceRegistryOperationErrorErrorsItem
//

@implementation GTLServiceRegistryOperationErrorErrorsItem
@dynamic code, location, message;
@end


// ----------------------------------------------------------------------------
//
//   GTLServiceRegistryOperationWarningsItemDataItem
//

@implementation GTLServiceRegistryOperationWarningsItemDataItem
@dynamic key, value;
@end
