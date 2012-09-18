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
//  GTLBooksVolumeannotation.h
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
//   GTLBooksVolumeannotation (0 custom class methods, 14 custom properties)
//   GTLBooksVolumeannotationContentRanges (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBooksAnnotationsRange;
@class GTLBooksVolumeannotationContentRanges;

// ----------------------------------------------------------------------------
//
//   GTLBooksVolumeannotation
//

@interface GTLBooksVolumeannotation : GTLObject

// The annotation data id for this volume annotation.
@property (copy) NSString *annotationDataId;

// Link to get data for this annotation.
@property (copy) NSString *annotationDataLink;

// The type of annotation this is.
@property (copy) NSString *annotationType;

// The content ranges to identify the selected text.
@property (retain) GTLBooksVolumeannotationContentRanges *contentRanges;

// Data for this annotation.
@property (copy) NSString *data;

// Indicates that this annotation is deleted.
@property (retain) NSNumber *deleted;  // boolValue

// Unique id of this volume annotation.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Resource Type
@property (copy) NSString *kind;

// The Layer this annotation is for.
@property (copy) NSString *layerId;

// Pages the annotation spans.
@property (retain) NSArray *pageIds;  // of NSString

// Excerpt from the volume.
@property (copy) NSString *selectedText;

// URL to this resource.
@property (copy) NSString *selfLink;

// Timestamp for the last time this anntoation was updated. (RFC 3339 UTC
// date-time format).
@property (retain) GTLDateTime *updated;

// The Volume this annotation is for.
@property (copy) NSString *volumeId;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksVolumeannotationContentRanges
//

@interface GTLBooksVolumeannotationContentRanges : GTLObject

// Range in CFI format for this annotation for version above.
@property (retain) GTLBooksAnnotationsRange *cfiRange;

// Content version applicable to ranges below.
@property (copy) NSString *contentVersion;

// Range in GB image format for this annotation for version above.
@property (retain) GTLBooksAnnotationsRange *gbImageRange;

// Range in GB text format for this annotation for version above.
@property (retain) GTLBooksAnnotationsRange *gbTextRange;

@end
