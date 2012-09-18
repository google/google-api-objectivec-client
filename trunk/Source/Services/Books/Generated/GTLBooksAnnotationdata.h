/* Copyright (c) 2012 Google Inc.
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
//  GTLBooksAnnotationdata.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Books API (books/v1)
// Description:
//   Lets you search for books and manage your Google Books library.
// Documentation:
//   https://developers.google.com/books/docs/v1/getting_started
// Classes:
//   GTLBooksAnnotationdata (0 custom class methods, 9 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLBooksAnnotationdata
//

@interface GTLBooksAnnotationdata : GTLObject

// The type of annotation this data is for.
@property (copy) NSString *annotationType;

@property (retain) id data;

// Base64 encoded data for this annotation data.
@property (copy) NSString *encodedData;  // GTLBase64 can encode/decode (probably web-safe format)

// Unique id for this annotation data.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Resource Type
@property (copy) NSString *kind;

// The Layer id for this data. *
@property (copy) NSString *layerId;

// URL for this resource. *
@property (copy) NSString *selfLink;

// Timestamp for the last time this data was updated. (RFC 3339 UTC date-time
// format).
@property (retain) GTLDateTime *updated;

// The volume id for this data. *
@property (copy) NSString *volumeId;

@end
