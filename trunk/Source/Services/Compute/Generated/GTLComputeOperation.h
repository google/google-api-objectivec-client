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
//  GTLComputeOperation.h
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
//   GTLComputeOperation (0 custom class methods, 21 custom properties)
//   GTLComputeOperationError (0 custom class methods, 1 custom properties)
//   GTLComputeOperationWarningsItem (0 custom class methods, 3 custom properties)
//   GTLComputeOperationErrorErrorsItem (0 custom class methods, 3 custom properties)
//   GTLComputeOperationWarningsItemDataItem (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLComputeOperationError;
@class GTLComputeOperationErrorErrorsItem;
@class GTLComputeOperationWarningsItem;
@class GTLComputeOperationWarningsItemDataItem;

// ----------------------------------------------------------------------------
//
//   GTLComputeOperation
//

// An operation resource, used to manage asynchronous API requests.

@interface GTLComputeOperation : GTLObject

// An optional identifier specified by the client when the mutation was
// initiated. Must be unique for all operation resources in the project (output
// only).
@property (copy) NSString *clientOperationId;

// Creation timestamp in RFC3339 text format (output only).
@property (copy) NSString *creationTimestamp;

// The time that this operation was completed. This is in RFC 3339 format
// (output only).
@property (copy) NSString *endTime;

// If errors occurred during processing of this operation, this field will be
// populated (output only).
@property (retain) GTLComputeOperationError *error;

// If operation fails, the HTTP error message returned, e.g. NOT FOUND. (output
// only).
@property (copy) NSString *httpErrorMessage;

// If operation fails, the HTTP error status code returned, e.g. 404. (output
// only).
@property (retain) NSNumber *httpErrorStatusCode;  // intValue

// Unique identifier for the resource; defined by the server (output only).
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSNumber *identifier;  // unsignedLongLongValue

// The time that this operation was requested. This is in RFC 3339 format
// (output only).
@property (copy) NSString *insertTime;

// Type of the resource.
@property (copy) NSString *kind;

// Name of the resource (output only).
@property (copy) NSString *name;

// Type of the operation. Examples include "insert", "update", and "delete"
// (output only).
@property (copy) NSString *operationType;

// An optional progress indicator that ranges from 0 to 100. There is no
// requirement that this be linear or support any granularity of operations.
// This should not be used to guess at when the operation will be complete. This
// number should be monotonically increasing as the operation progresses (output
// only).
@property (retain) NSNumber *progress;  // intValue

// Server defined URL for the resource (output only).
@property (copy) NSString *selfLink;

// The time that this operation was started by the server. This is in RFC 3339
// format (output only).
@property (copy) NSString *startTime;

// Status of the operation. Can be one of the following: "PENDING", "RUNNING",
// or "DONE" (output only).
@property (copy) NSString *status;

// An optional textual description of the current status of the operation
// (output only).
@property (copy) NSString *statusMessage;

// Unique target id which identifies a particular incarnation of the target
// (output only).
@property (retain) NSNumber *targetId;  // unsignedLongLongValue

// URL of the resource the operation is mutating (output only).
@property (copy) NSString *targetLink;

// User who requested the operation, for example "user@example.com" (output
// only).
@property (copy) NSString *user;

// If warning messages generated during processing of this operation, this field
// will be populated (output only).
@property (retain) NSArray *warnings;  // of GTLComputeOperationWarningsItem

// URL of the zone where the operation resides (output only).
// Remapped to 'zoneProperty' to avoid NSObject's 'zone'.
@property (copy) NSString *zoneProperty;

@end


// ----------------------------------------------------------------------------
//
//   GTLComputeOperationError
//

@interface GTLComputeOperationError : GTLObject

// The array of errors encountered while processing this operation.
@property (retain) NSArray *errors;  // of GTLComputeOperationErrorErrorsItem

@end


// ----------------------------------------------------------------------------
//
//   GTLComputeOperationWarningsItem
//

@interface GTLComputeOperationWarningsItem : GTLObject

// The warning type identifier for this warning.
@property (copy) NSString *code;

// Metadata for this warning in 'key: value' format.
@property (retain) NSArray *data;  // of GTLComputeOperationWarningsItemDataItem

// Optional human-readable details for this warning.
@property (copy) NSString *message;

@end


// ----------------------------------------------------------------------------
//
//   GTLComputeOperationErrorErrorsItem
//

@interface GTLComputeOperationErrorErrorsItem : GTLObject

// The error type identifier for this error.
@property (copy) NSString *code;

// Indicates the field in the request which caused the error. This property is
// optional.
@property (copy) NSString *location;

// An optional, human-readable error message.
@property (copy) NSString *message;

@end


// ----------------------------------------------------------------------------
//
//   GTLComputeOperationWarningsItemDataItem
//

@interface GTLComputeOperationWarningsItemDataItem : GTLObject

// A key for the warning data.
@property (copy) NSString *key;

// A warning data value corresponding to the key.
@property (copy) NSString *value;

@end
