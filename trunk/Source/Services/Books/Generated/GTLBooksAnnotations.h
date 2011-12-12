/* Copyright (c) 2011 Google Inc.
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
//  GTLBooksAnnotations.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Books API (books/v1)
// Description:
//   Lets you search for books and manage your Google Books library.
// Documentation:
//   https://code.google.com/apis/books/docs/v1/getting_started.html
// Classes:
//   GTLBooksAnnotations (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBooksAnnotation;

// ----------------------------------------------------------------------------
//
//   GTLBooksAnnotations
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLBooksAnnotations : GTLCollectionObject

// A list of annotations.
@property (retain) NSArray *items;  // of GTLBooksAnnotation

// Resource type.
@property (copy) NSString *kind;

// Token to pass in for pagination for the next page. This will not be present
// if this request does not have more results.
@property (copy) NSString *nextPageToken;

// Total number of annotations found. This may be greater than the number of
// notes returned in this response if results have been paginated.
@property (retain) NSNumber *totalItems;  // intValue

@end
