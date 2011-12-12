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
//  GTLBooksBookshelf.h
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
//   GTLBooksBookshelf (0 custom class methods, 10 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLBooksBookshelf
//

@interface GTLBooksBookshelf : GTLObject

// Whether this bookshelf is PUBLIC or PRIVATE.
@property (copy) NSString *access;

// Created time for this bookshelf (formatted UTC timestamp with millisecond
// resolution).
@property (retain) GTLDateTime *created;

// Description of this bookshelf.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Id of this bookshelf, only unique by user.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSNumber *identifier;  // intValue

// Resource type for bookshelf metadata.
@property (copy) NSString *kind;

// URL to this resource.
@property (copy) NSString *selfLink;

// Title of this bookshelf.
@property (copy) NSString *title;

// Last modified time of this bookshelf (formatted UTC timestamp with
// millisecond resolution).
@property (retain) GTLDateTime *updated;

// Number of volumes in this bookshelf.
@property (retain) NSNumber *volumeCount;  // intValue

// Last time a volume was added or removed from this bookshelf (formatted UTC
// timestamp with millisecond resolution).
@property (retain) GTLDateTime *volumesLastUpdated;

@end
