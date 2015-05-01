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
//  GTLBooksLayersummary.h
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
//   GTLBooksLayersummary (0 custom class methods, 13 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLBooksLayersummary
//

@interface GTLBooksLayersummary : GTLObject

// The number of annotations for this layer.
@property (nonatomic, retain) NSNumber *annotationCount;  // intValue

// Link to get data for this annotation.
@property (nonatomic, copy) NSString *annotationsDataLink;

// The link to get the annotations for this layer.
@property (nonatomic, copy) NSString *annotationsLink;

// The list of annotation types contained for this layer.
@property (nonatomic, retain) NSArray *annotationTypes;  // of NSString

// The content version this resource is for.
@property (nonatomic, copy) NSString *contentVersion;

// The number of data items for this layer.
@property (nonatomic, retain) NSNumber *dataCount;  // intValue

// Unique id of this layer summary.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Resource Type
@property (nonatomic, copy) NSString *kind;

// The layer id for this summary.
@property (nonatomic, copy) NSString *layerId;

// URL to this resource.
@property (nonatomic, copy) NSString *selfLink;

// Timestamp for the last time an item in this layer was updated. (RFC 3339 UTC
// date-time format).
@property (nonatomic, retain) GTLDateTime *updated;

// The current version of this layer's volume annotations. Note that this
// version applies only to the data in the books.layers.volumeAnnotations.*
// responses. The actual annotation data is versioned separately.
@property (nonatomic, copy) NSString *volumeAnnotationsVersion;

// The volume id this resource is for.
@property (nonatomic, copy) NSString *volumeId;

@end
