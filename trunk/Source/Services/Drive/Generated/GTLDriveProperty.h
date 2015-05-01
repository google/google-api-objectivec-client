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
//  GTLDriveProperty.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Drive API (drive/v2)
// Description:
//   The API to interact with Drive.
// Documentation:
//   https://developers.google.com/drive/
// Classes:
//   GTLDriveProperty (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLDriveProperty
//

// A key-value pair attached to a file that is either public or private to an
// application.
// The following limits apply to file properties:
// - Maximum of 100 properties total per file
// - Maximum of 30 private properties per app
// - Maximum of 30 public properties
// - Maximum of 124 bytes size limit on (key + value) string in UTF-8 encoding
// for a single property.

@interface GTLDriveProperty : GTLObject

// ETag of the property.
@property (nonatomic, copy) NSString *ETag;

// The key of this property.
@property (nonatomic, copy) NSString *key;

// This is always drive#property.
@property (nonatomic, copy) NSString *kind;

// The link back to this property.
@property (nonatomic, copy) NSString *selfLink;

// The value of this property.
@property (nonatomic, copy) NSString *value;

// The visibility of this property.
@property (nonatomic, copy) NSString *visibility;

@end
