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
//  GTLComputeZone.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Compute Engine API (compute/v1beta14)
// Description:
//   API for the Google Compute Engine service.
// Documentation:
//   https://developers.google.com/compute/docs/reference/v1beta14
// Classes:
//   GTLComputeZone (0 custom class methods, 11 custom properties)
//   GTLComputeZoneMaintenanceWindowsItem (0 custom class methods, 4 custom properties)

#import "GTLComputeZone.h"

#import "GTLComputeDeprecationStatus.h"
#import "GTLComputeQuota.h"

// ----------------------------------------------------------------------------
//
//   GTLComputeZone
//

@implementation GTLComputeZone
@dynamic availableMachineType, creationTimestamp, deprecated,
         descriptionProperty, identifier, kind, maintenanceWindows, name,
         quotas, selfLink, status;

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
      [NSString class], @"availableMachineType",
      [GTLComputeZoneMaintenanceWindowsItem class], @"maintenanceWindows",
      [GTLComputeQuota class], @"quotas",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"compute#zone"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLComputeZoneMaintenanceWindowsItem
//

@implementation GTLComputeZoneMaintenanceWindowsItem
@dynamic beginTime, descriptionProperty, endTime, name;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"description"
                                forKey:@"descriptionProperty"];
  return map;
}

@end
