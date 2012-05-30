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
//  GTLBooksConstants.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Books API (books/v1)
// Description:
//   Lets you search for books and manage your Google Books library.
// Documentation:
//   https://code.google.com/apis/books/docs/v1/getting_started.html

#import "GTLBooksConstants.h"

// Authorization scope
NSString * const kGTLAuthScopeBooks = @"https://www.googleapis.com/auth/books";

// Action
NSString * const kGTLBooksActionBookmark = @"bookmark";
NSString * const kGTLBooksActionChapter  = @"chapter";
NSString * const kGTLBooksActionNextPage = @"next-page";
NSString * const kGTLBooksActionPrevPage = @"prev-page";
NSString * const kGTLBooksActionScroll   = @"scroll";
NSString * const kGTLBooksActionSearch   = @"search";

// Association
NSString * const kGTLBooksAssociationComplementary = @"complementary";

// Download
NSString * const kGTLBooksDownloadEpub = @"epub";

// Filter
NSString * const kGTLBooksFilterEbooks     = @"ebooks";
NSString * const kGTLBooksFilterFreeEbooks = @"free-ebooks";
NSString * const kGTLBooksFilterFull       = @"full";
NSString * const kGTLBooksFilterPaidEbooks = @"paid-ebooks";
NSString * const kGTLBooksFilterPartial    = @"partial";

// LibraryRestrict
NSString * const kGTLBooksLibraryRestrictMyLibrary  = @"my-library";
NSString * const kGTLBooksLibraryRestrictNoRestrict = @"no-restrict";

// OrderBy
NSString * const kGTLBooksOrderByNewest    = @"newest";
NSString * const kGTLBooksOrderByRelevance = @"relevance";

// PrintType
NSString * const kGTLBooksPrintTypeAll       = @"all";
NSString * const kGTLBooksPrintTypeBooks     = @"books";
NSString * const kGTLBooksPrintTypeMagazines = @"magazines";

// Projection
NSString * const kGTLBooksProjectionFull = @"full";
NSString * const kGTLBooksProjectionLite = @"lite";
