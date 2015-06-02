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
//  GTLStorageRewriteResponse.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Cloud Storage API (storage/v1)
// Description:
//   Lets you store and retrieve potentially-large, immutable data objects.
// Documentation:
//   https://developers.google.com/storage/docs/json_api/
// Classes:
//   GTLStorageRewriteResponse (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLStorageObject;

// ----------------------------------------------------------------------------
//
//   GTLStorageRewriteResponse
//

// A rewrite response.

@interface GTLStorageRewriteResponse : GTLObject

// true if the copy is finished; otherwise, false if the copy is in progress.
// This property is always present in the response.
@property (nonatomic, retain) NSNumber *done;  // boolValue

// The kind of item this is.
@property (nonatomic, copy) NSString *kind;

// The total size of the object being copied in bytes. This property is always
// present in the response.
@property (nonatomic, retain) NSNumber *objectSize;  // unsignedLongLongValue

// A resource containing the metadata for the copied-to object. This property is
// present in the response only when copying completes.
@property (nonatomic, retain) GTLStorageObject *resource;

// A token to use in subsequent requests to continue copying data. This token is
// present in the response only when there is more data to copy.
@property (nonatomic, copy) NSString *rewriteToken;

// The total bytes written so far, which can be used to provide a waiting user
// with a progress indicator. This property is always present in the response.
@property (nonatomic, retain) NSNumber *totalBytesRewritten;  // unsignedLongLongValue

@end
