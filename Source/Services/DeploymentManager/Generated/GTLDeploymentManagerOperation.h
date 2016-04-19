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
//  GTLDeploymentManagerOperation.h
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
//   GTLDeploymentManagerOperation (0 custom class methods, 23 custom properties)
//   GTLDeploymentManagerOperationError (0 custom class methods, 1 custom properties)
//   GTLDeploymentManagerOperationWarningsItem (0 custom class methods, 3 custom properties)
//   GTLDeploymentManagerOperationErrorErrorsItem (0 custom class methods, 3 custom properties)
//   GTLDeploymentManagerOperationWarningsItemDataItem (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLDeploymentManagerOperationError;
@class GTLDeploymentManagerOperationErrorErrorsItem;
@class GTLDeploymentManagerOperationWarningsItem;
@class GTLDeploymentManagerOperationWarningsItemDataItem;

// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerOperation
//

// An Operation resource, used to manage asynchronous API requests.

@interface GTLDeploymentManagerOperation : GTLObject

// [Output Only] Reserved for future use.
@property (nonatomic, copy) NSString *clientOperationId;

// [Output Only] Creation timestamp in RFC3339 text format.
@property (nonatomic, copy) NSString *creationTimestamp;

// [Output Only] A textual description of the operation, which is set when the
// operation is created.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// [Output Only] The time that this operation was completed. This value is in
// RFC3339 text format.
@property (nonatomic, copy) NSString *endTime;

// [Output Only] If errors are generated during processing of the operation,
// this field will be populated.
@property (nonatomic, retain) GTLDeploymentManagerOperationError *error;

// [Output Only] If the operation fails, this field contains the HTTP error
// message that was returned, such as NOT FOUND.
@property (nonatomic, copy) NSString *httpErrorMessage;

// [Output Only] If the operation fails, this field contains the HTTP error
// status code that was returned. For example, a 404 means the resource was not
// found.
@property (nonatomic, retain) NSNumber *httpErrorStatusCode;  // intValue

// [Output Only] The unique identifier for the resource. This identifier is
// defined by the server.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, retain) NSNumber *identifier;  // unsignedLongLongValue

// [Output Only] The time that this operation was requested. This value is in
// RFC3339 text format.
@property (nonatomic, copy) NSString *insertTime;

// [Output Only] Type of the resource. Always compute#operation for Operation
// resources.
@property (nonatomic, copy) NSString *kind;

// [Output Only] Name of the resource.
@property (nonatomic, copy) NSString *name;

// [Output Only] The type of operation, such as insert, update, or delete, and
// so on.
@property (nonatomic, copy) NSString *operationType;

// [Output Only] An optional progress indicator that ranges from 0 to 100. There
// is no requirement that this be linear or support any granularity of
// operations. This should not be used to guess when the operation will be
// complete. This number should monotonically increase as the operation
// progresses.
@property (nonatomic, retain) NSNumber *progress;  // intValue

// [Output Only] The URL of the region where the operation resides. Only
// available when performing regional operations.
@property (nonatomic, copy) NSString *region;

// [Output Only] Server-defined URL for the resource.
@property (nonatomic, copy) NSString *selfLink;

// [Output Only] The time that this operation was started by the server. This
// value is in RFC3339 text format.
@property (nonatomic, copy) NSString *startTime;

// [Output Only] The status of the operation, which can be one of the following:
// PENDING, RUNNING, or DONE.
@property (nonatomic, copy) NSString *status;

// [Output Only] An optional textual description of the current status of the
// operation.
@property (nonatomic, copy) NSString *statusMessage;

// [Output Only] The unique target ID, which identifies a specific incarnation
// of the target resource.
@property (nonatomic, retain) NSNumber *targetId;  // unsignedLongLongValue

// [Output Only] The URL of the resource that the operation modifies.
@property (nonatomic, copy) NSString *targetLink;

// [Output Only] User who requested the operation, for example:
// user@example.com.
@property (nonatomic, copy) NSString *user;

// [Output Only] If warning messages are generated during processing of the
// operation, this field will be populated.
@property (nonatomic, retain) NSArray *warnings;  // of GTLDeploymentManagerOperationWarningsItem

// [Output Only] The URL of the zone where the operation resides. Only available
// when performing per-zone operations.
// Remapped to 'zoneProperty' to avoid NSObject's 'zone'.
@property (nonatomic, copy) NSString *zoneProperty;

@end


// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerOperationError
//

@interface GTLDeploymentManagerOperationError : GTLObject

// [Output Only] The array of errors encountered while processing this
// operation.
@property (nonatomic, retain) NSArray *errors;  // of GTLDeploymentManagerOperationErrorErrorsItem

@end


// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerOperationWarningsItem
//

@interface GTLDeploymentManagerOperationWarningsItem : GTLObject

// [Output Only] A warning code, if applicable. For example, Compute Engine
// returns NO_RESULTS_ON_PAGE if there are no results in the response.
@property (nonatomic, copy) NSString *code;

// [Output Only] Metadata about this warning in key: value format. For example:
// "data": [ { "key": "scope", "value": "zones/us-east1-d" }
@property (nonatomic, retain) NSArray *data;  // of GTLDeploymentManagerOperationWarningsItemDataItem

// [Output Only] A human-readable description of the warning code.
@property (nonatomic, copy) NSString *message;

@end


// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerOperationErrorErrorsItem
//

@interface GTLDeploymentManagerOperationErrorErrorsItem : GTLObject

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
//   GTLDeploymentManagerOperationWarningsItemDataItem
//

@interface GTLDeploymentManagerOperationWarningsItemDataItem : GTLObject

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
