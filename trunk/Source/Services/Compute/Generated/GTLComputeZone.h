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
//  GTLComputeZone.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLComputeDeprecationStatus;
@class GTLComputeQuota;
@class GTLComputeZoneMaintenanceWindowsItem;

// ----------------------------------------------------------------------------
//
//   GTLComputeZone
//

// A zone resource.

@interface GTLComputeZone : GTLObject

// The machine types that can be used in this zone (output only).
@property (retain) NSArray *availableMachineType;  // of NSString

// Creation timestamp in RFC3339 text format (output only).
@property (copy) NSString *creationTimestamp;

// The deprecation status associated with this zone.
@property (retain) GTLComputeDeprecationStatus *deprecated;

// Textual description of the resource.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Unique identifier for the resource; defined by the server (output only).
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSNumber *identifier;  // unsignedLongLongValue

// Type of the resource.
@property (copy) NSString *kind;

// Scheduled maintenance windows for the zone. When the zone is in a maintenance
// window, all resources which reside in the zone will be unavailable.
@property (retain) NSArray *maintenanceWindows;  // of GTLComputeZoneMaintenanceWindowsItem

// Name of the resource.
@property (copy) NSString *name;

// Quotas assigned to this zone.
@property (retain) NSArray *quotas;  // of GTLComputeQuota

// Server defined URL for the resource (output only).
@property (copy) NSString *selfLink;

// Status of the zone. "UP" or "DOWN".
@property (copy) NSString *status;

@end


// ----------------------------------------------------------------------------
//
//   GTLComputeZoneMaintenanceWindowsItem
//

@interface GTLComputeZoneMaintenanceWindowsItem : GTLObject

// Begin time of the maintenance window, in RFC 3339 format.
@property (copy) NSString *beginTime;

// Textual description of the maintenance window.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// End time of the maintenance window, in RFC 3339 format.
@property (copy) NSString *endTime;

// Name of the maintenance window.
@property (copy) NSString *name;

@end
