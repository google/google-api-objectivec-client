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
//  GTLDeploymentManagerResourceUpdate.h
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
//   GTLDeploymentManagerResourceUpdate (0 custom class methods, 7 custom properties)
//   GTLDeploymentManagerResourceUpdateError (0 custom class methods, 1 custom properties)
//   GTLDeploymentManagerResourceUpdateWarningsItem (0 custom class methods, 3 custom properties)
//   GTLDeploymentManagerResourceUpdateErrorErrorsItem (0 custom class methods, 3 custom properties)
//   GTLDeploymentManagerResourceUpdateWarningsItemDataItem (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLDeploymentManagerResourceUpdateError;
@class GTLDeploymentManagerResourceUpdateErrorErrorsItem;
@class GTLDeploymentManagerResourceUpdateWarningsItem;
@class GTLDeploymentManagerResourceUpdateWarningsItemDataItem;

// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerResourceUpdate
//

@interface GTLDeploymentManagerResourceUpdate : GTLObject

// [Output Only] If errors are generated during update of the resource, this
// field will be populated.
@property (nonatomic, retain) GTLDeploymentManagerResourceUpdateError *error;

// [Output Only] The expanded properties of the resource with reference values
// expanded. Returned as serialized YAML.
@property (nonatomic, copy) NSString *finalProperties;

// [Output Only] The intent of the resource: PREVIEW, UPDATE, or CANCEL.
@property (nonatomic, copy) NSString *intent;

// [Output Only] URL of the manifest representing the update configuration of
// this resource.
@property (nonatomic, copy) NSString *manifest;

// [Output Only] The set of updated properties for this resource, before
// references are expanded. Returned as serialized YAML.
@property (nonatomic, copy) NSString *properties;

// [Output Only] The state of the resource.
@property (nonatomic, copy) NSString *state;

// [Output Only] If warning messages are generated during processing of this
// resource, this field will be populated.
@property (nonatomic, retain) NSArray *warnings;  // of GTLDeploymentManagerResourceUpdateWarningsItem

@end


// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerResourceUpdateError
//

@interface GTLDeploymentManagerResourceUpdateError : GTLObject

// [Output Only] The array of errors encountered while processing this
// operation.
@property (nonatomic, retain) NSArray *errors;  // of GTLDeploymentManagerResourceUpdateErrorErrorsItem

@end


// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerResourceUpdateWarningsItem
//

@interface GTLDeploymentManagerResourceUpdateWarningsItem : GTLObject

// [Output Only] A warning code, if applicable. For example, Compute Engine
// returns NO_RESULTS_ON_PAGE if there are no results in the response.
@property (nonatomic, copy) NSString *code;

// [Output Only] Metadata about this warning in key: value format. For example:
// "data": [ { "key": "scope", "value": "zones/us-east1-d" }
@property (nonatomic, retain) NSArray *data;  // of GTLDeploymentManagerResourceUpdateWarningsItemDataItem

// [Output Only] A human-readable description of the warning code.
@property (nonatomic, copy) NSString *message;

@end


// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerResourceUpdateErrorErrorsItem
//

@interface GTLDeploymentManagerResourceUpdateErrorErrorsItem : GTLObject

// [Output Only] The error type identifier for this error.
@property (nonatomic, copy) NSString *code;

// [Output Only] Indicates the field in the request that caused the error. This
// property is optional.
@property (nonatomic, copy) NSString *location;

// [Output Only] An optional, human-readable error message.
@property (nonatomic, copy) NSString *message;

@end


// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerResourceUpdateWarningsItemDataItem
//

@interface GTLDeploymentManagerResourceUpdateWarningsItemDataItem : GTLObject

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
