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
//  GTLBooksReview.h
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
//   GTLBooksReview (0 custom class methods, 10 custom properties)
//   GTLBooksReviewAuthor (0 custom class methods, 1 custom properties)
//   GTLBooksReviewSource (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBooksReviewAuthor;
@class GTLBooksReviewSource;

// ----------------------------------------------------------------------------
//
//   GTLBooksReview
//

@interface GTLBooksReview : GTLObject

// Author of this review.
@property (retain) GTLBooksReviewAuthor *author;

// Review text.
@property (copy) NSString *content;

// Date of this review.
@property (copy) NSString *date;

// URL for the full review text, for reviews gathered from the web.
@property (copy) NSString *fullTextUrl;

// Resource type for a review.
@property (copy) NSString *kind;

// Star rating for this review. Possible values are ONE, TWO, THREE, FOUR, FIVE
// or NOT_RATED.
@property (copy) NSString *rating;

// Information regarding the source of this review, when the review is not from
// a Google Books user.
@property (retain) GTLBooksReviewSource *source;

// Title for this review.
@property (copy) NSString *title;

// Source type for this review. Possible values are EDITORIAL, WEB_USER or
// GOOGLE_USER.
@property (copy) NSString *type;

// Volume that this review is for.
@property (copy) NSString *volumeId;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksReviewAuthor
//

@interface GTLBooksReviewAuthor : GTLObject

// Name of this person.
@property (copy) NSString *displayName;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksReviewSource
//

@interface GTLBooksReviewSource : GTLObject

// Name of the source.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Extra text about the source of the review.
@property (copy) NSString *extraDescription;

// URL of the source of the review.
@property (copy) NSString *url;

@end
