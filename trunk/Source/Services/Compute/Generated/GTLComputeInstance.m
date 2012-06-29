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
//  GTLComputeInstance.m
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
//   GTLComputeInstance (0 custom class methods, 16 custom properties)

#import "GTLComputeInstance.h"

#import "GTLComputeAttachedDisk.h"
#import "GTLComputeMetadata.h"
#import "GTLComputeNetworkInterface.h"
#import "GTLComputeServiceAccount.h"

// ----------------------------------------------------------------------------
//
//   GTLComputeInstance
//

@implementation GTLComputeInstance
@dynamic creationTimestamp, descriptionProperty, disks, identifier, image, kind,
         machineType, metadata, name, networkInterfaces, selfLink,
         serviceAccounts, status, statusMessage, tags, zoneProperty;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"description", @"descriptionProperty",
      @"id", @"identifier",
      @"zone", @"zoneProperty",
      nil];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLComputeAttachedDisk class], @"disks",
      [GTLComputeNetworkInterface class], @"networkInterfaces",
      [GTLComputeServiceAccount class], @"serviceAccounts",
      [NSString class], @"tags",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"compute#instance"];
}

@end
