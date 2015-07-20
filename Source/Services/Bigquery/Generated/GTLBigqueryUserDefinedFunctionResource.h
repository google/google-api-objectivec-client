/* Copyright (c) 2015 Google Inc.
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
//  GTLBigqueryUserDefinedFunctionResource.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   BigQuery API (bigquery/v2)
// Description:
//   A data platform for customers to create, manage, share and query data.
// Documentation:
//   https://cloud.google.com/bigquery/
// Classes:
//   GTLBigqueryUserDefinedFunctionResource (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLBigqueryUserDefinedFunctionResource
//

@interface GTLBigqueryUserDefinedFunctionResource : GTLObject

// [Pick one] An inline resource that contains code for a user-defined function
// (UDF). Providing a inline code resource is equivalent to providing a URI for
// a file containing the same code.
@property (nonatomic, copy) NSString *inlineCode;

// [Pick one] A code resource to load from a Google Cloud Storage URI
// (gs://bucket/path).
@property (nonatomic, copy) NSString *resourceUri;

@end
