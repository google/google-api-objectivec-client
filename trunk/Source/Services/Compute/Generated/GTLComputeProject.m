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
//  GTLComputeProject.m
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
//   GTLComputeProject (0 custom class methods, 9 custom properties)
//   GTLComputeProjectQuotasItem (0 custom class methods, 3 custom properties)

#import "GTLComputeProject.h"

#import "GTLComputeMetadata.h"

// ----------------------------------------------------------------------------
//
//   GTLComputeProject
//

@implementation GTLComputeProject
@dynamic commonInstanceMetadata, creationTimestamp, descriptionProperty,
         externalIpAddresses, identifier, kind, name, quotas, selfLink;

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
      [NSString class], @"externalIpAddresses",
      [GTLComputeProjectQuotasItem class], @"quotas",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"compute#project"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLComputeProjectQuotasItem
//

@implementation GTLComputeProjectQuotasItem
@dynamic limit, metric, usage;
@end
