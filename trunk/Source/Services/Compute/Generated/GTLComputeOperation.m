/* Copyright (c) 2012 Google Inc.
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
//  GTLComputeOperation.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Compute Engine API (compute/v1beta12)
// Description:
//   API for the Google Compute Engine service.
// Documentation:
//   https://developers.google.com/compute/docs/reference/v1beta12
// Classes:
//   GTLComputeOperation (0 custom class methods, 19 custom properties)
//   GTLComputeOperationError (0 custom class methods, 1 custom properties)
//   GTLComputeOperationErrorErrorsItem (0 custom class methods, 3 custom properties)

#import "GTLComputeOperation.h"

// ----------------------------------------------------------------------------
//
//   GTLComputeOperation
//

@implementation GTLComputeOperation
@dynamic clientOperationId, creationTimestamp, endTime, error, httpErrorMessage,
         httpErrorStatusCode, identifier, insertTime, kind, name, operationType,
         progress, selfLink, startTime, status, statusMessage, targetId,
         targetLink, user;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"compute#operation"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLComputeOperationError
//

@implementation GTLComputeOperationError
@dynamic errors;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLComputeOperationErrorErrorsItem class]
                                forKey:@"errors"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLComputeOperationErrorErrorsItem
//

@implementation GTLComputeOperationErrorErrorsItem
@dynamic code, location, message;
@end
