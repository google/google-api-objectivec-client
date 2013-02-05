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
//  GTLComputeDeprecationStatus.h
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
//   GTLComputeDeprecationStatus (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLComputeDeprecationStatus
//

// Deprecation status for a public resource.

@interface GTLComputeDeprecationStatus : GTLObject

// An optional RFC3339 timestamp on or after which the deprecation state of this
// resource will be changed to DELETED.
@property (copy) NSString *deleted;

// An optional RFC3339 timestamp on or after which the deprecation state of this
// resource will be changed to DEPRECATED.
@property (copy) NSString *deprecated;

// An optional RFC3339 timestamp on or after which the deprecation state of this
// resource will be changed to OBSOLETE.
@property (copy) NSString *obsolete;

// A URL of the suggested replacement for the deprecated resource. The
// deprecated resource and its replacement must be resources of the same kind.
@property (copy) NSString *replacement;

// The deprecation state. Can be "DEPRECATED", "OBSOLETE", or "DELETED".
// Operations which create a new resource using a "DEPRECATED" resource will
// return successfully, but with a warning indicating the deprecated resource
// and recommending its replacement. New uses of "OBSOLETE" or "DELETED"
// resources will result in an error.
@property (copy) NSString *state;

@end
