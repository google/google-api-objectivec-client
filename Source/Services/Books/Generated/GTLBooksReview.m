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
//  GTLBooksReview.m
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
//   GTLBooksReview (0 custom class methods, 10 custom properties)
//   GTLBooksReviewAuthor (0 custom class methods, 1 custom properties)
//   GTLBooksReviewSource (0 custom class methods, 3 custom properties)

#import "GTLBooksReview.h"

// ----------------------------------------------------------------------------
//
//   GTLBooksReview
//

@implementation GTLBooksReview
@dynamic author, content, date, fullTextUrl, kind, rating, source, title, type,
         volumeId;

+ (void)load {
  [self registerObjectClassForKind:@"books#review"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksReviewAuthor
//

@implementation GTLBooksReviewAuthor
@dynamic displayName;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksReviewSource
//

@implementation GTLBooksReviewSource
@dynamic descriptionProperty, extraDescription, url;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"description"
                                forKey:@"descriptionProperty"];
  return map;
}

@end
