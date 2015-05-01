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
//  GTLStorageObjects.h
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
//   GTLStorageObjects (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLStorageObject;

// ----------------------------------------------------------------------------
//
//   GTLStorageObjects
//

// A list of objects.

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLStorageObjects : GTLCollectionObject

// The list of items.
@property (nonatomic, retain) NSArray *items;  // of GTLStorageObject

// The kind of item this is. For lists of objects, this is always
// storage#objects.
@property (nonatomic, copy) NSString *kind;

// The continuation token, used to page through large result sets. Provide this
// value in a subsequent request to return the next page of results.
@property (nonatomic, copy) NSString *nextPageToken;

// The list of prefixes of objects matching-but-not-listed up to and including
// the requested delimiter.
@property (nonatomic, retain) NSArray *prefixes;  // of NSString

@end
