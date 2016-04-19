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
//  GTLDeploymentManagerResource.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Cloud Deployment Manager API (deploymentmanager/v2)
// Description:
//   Declares, configures, and deploys complex solutions on Google Cloud
//   Platform.
// Documentation:
//   https://cloud.google.com/deployment-manager/
// Classes:
//   GTLDeploymentManagerResource (0 custom class methods, 11 custom properties)
//   GTLDeploymentManagerResourceWarningsItem (0 custom class methods, 3 custom properties)
//   GTLDeploymentManagerResourceWarningsItemDataItem (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLDeploymentManagerResourceUpdate;
@class GTLDeploymentManagerResourceWarningsItem;
@class GTLDeploymentManagerResourceWarningsItemDataItem;

// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerResource
//

@interface GTLDeploymentManagerResource : GTLObject

// [Output Only] The evaluated properties of the resource with references
// expanded. Returned as serialized YAML.
@property (nonatomic, copy) NSString *finalProperties;

// [Output Only] Unique identifier for the resource; defined by the server.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, retain) NSNumber *identifier;  // unsignedLongLongValue

// [Output Only] Timestamp when the resource was created or acquired, in RFC3339
// text format .
@property (nonatomic, copy) NSString *insertTime;

// [Output Only] URL of the manifest representing the current configuration of
// this resource.
@property (nonatomic, copy) NSString *manifest;

// [Output Only] The name of the resource as it appears in the YAML config.
@property (nonatomic, copy) NSString *name;

// [Output Only] The current properties of the resource before any references
// have been filled in. Returned as serialized YAML.
@property (nonatomic, copy) NSString *properties;

// [Output Only] The type of the resource, for example compute.v1.instance, or
// replicaPools.v1beta2.instanceGroupManager.
@property (nonatomic, copy) NSString *type;

// [Output Only] If Deployment Manager is currently updating or previewing an
// update to this resource, the updated configuration appears here.
@property (nonatomic, retain) GTLDeploymentManagerResourceUpdate *update;

// [Output Only] Timestamp when the resource was updated, in RFC3339 text format
// .
@property (nonatomic, copy) NSString *updateTime;

// [Output Only] The URL of the actual resource.
@property (nonatomic, copy) NSString *url;

// [Output Only] If warning messages are generated during processing of this
// resource, this field will be populated.
@property (nonatomic, retain) NSArray *warnings;  // of GTLDeploymentManagerResourceWarningsItem

@end


// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerResourceWarningsItem
//

@interface GTLDeploymentManagerResourceWarningsItem : GTLObject

// [Output Only] A warning code, if applicable. For example, Compute Engine
// returns NO_RESULTS_ON_PAGE if there are no results in the response.
@property (nonatomic, copy) NSString *code;

// [Output Only] Metadata about this warning in key: value format. For example:
// "data": [ { "key": "scope", "value": "zones/us-east1-d" }
@property (nonatomic, retain) NSArray *data;  // of GTLDeploymentManagerResourceWarningsItemDataItem

// [Output Only] A human-readable description of the warning code.
@property (nonatomic, copy) NSString *message;

@end


// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerResourceWarningsItemDataItem
//

@interface GTLDeploymentManagerResourceWarningsItemDataItem : GTLObject

// [Output Only] A key that provides more detail on the warning being returned.
// For example, for warnings where there are no results in a list request for a
// particular zone, this key might be scope and the key value might be the zone
// name. Other examples might be a key indicating a deprecated resource and a
// suggested replacement, or a warning about invalid network settings (for
// example, if an instance attempts to perform IP forwarding but is not enabled
// for IP forwarding).
@property (nonatomic, copy) NSString *key;

// [Output Only] A warning data value corresponding to the key.
@property (nonatomic, copy) NSString *value;

@end
