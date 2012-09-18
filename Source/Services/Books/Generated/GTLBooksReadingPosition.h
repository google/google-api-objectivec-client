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
//  GTLBooksReadingPosition.h
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
//   GTLBooksReadingPosition (0 custom class methods, 7 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLBooksReadingPosition
//

@interface GTLBooksReadingPosition : GTLObject

// Position in an EPUB as a CFI.
@property (copy) NSString *epubCfiPosition;

// Position in a volume for image-based content.
@property (copy) NSString *gbImagePosition;

// Position in a volume for text-based content.
@property (copy) NSString *gbTextPosition;

// Resource type for a reading position.
@property (copy) NSString *kind;

// Position in a PDF file.
@property (copy) NSString *pdfPosition;

// Timestamp when this reading position was last updated (formatted UTC
// timestamp with millisecond resolution).
@property (retain) GTLDateTime *updated;

// Volume id associated with this reading position.
@property (copy) NSString *volumeId;

@end
