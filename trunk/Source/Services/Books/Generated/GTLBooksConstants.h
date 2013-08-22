/* Copyright (c) 2013 Google Inc.
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
//  GTLBooksConstants.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Books API (books/v1)
// Description:
//   Lets you search for books and manage your Google Books library.
// Documentation:
//   https://developers.google.com/books/docs/v1/getting_started

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// Manage your books
GTL_EXTERN NSString * const kGTLAuthScopeBooks;  // "https://www.googleapis.com/auth/books"

// AcquireMethod
GTL_EXTERN NSString * const kGTLBooksAcquireMethodPreordered;   // "PREORDERED"
GTL_EXTERN NSString * const kGTLBooksAcquireMethodPreviouslyRented;  // "PREVIOUSLY_RENTED"
GTL_EXTERN NSString * const kGTLBooksAcquireMethodPublicDomain;  // "PUBLIC_DOMAIN"
GTL_EXTERN NSString * const kGTLBooksAcquireMethodPurchased;    // "PURCHASED"
GTL_EXTERN NSString * const kGTLBooksAcquireMethodRented;       // "RENTED"
GTL_EXTERN NSString * const kGTLBooksAcquireMethodSample;       // "SAMPLE"
GTL_EXTERN NSString * const kGTLBooksAcquireMethodUploaded;     // "UPLOADED"

// Action
GTL_EXTERN NSString * const kGTLBooksActionBookmark;  // "bookmark"
GTL_EXTERN NSString * const kGTLBooksActionChapter;   // "chapter"
GTL_EXTERN NSString * const kGTLBooksActionNextPage;  // "next-page"
GTL_EXTERN NSString * const kGTLBooksActionPrevPage;  // "prev-page"
GTL_EXTERN NSString * const kGTLBooksActionScroll;    // "scroll"
GTL_EXTERN NSString * const kGTLBooksActionSearch;    // "search"

// Association
GTL_EXTERN NSString * const kGTLBooksAssociationEndOfSample;  // "end-of-sample"
GTL_EXTERN NSString * const kGTLBooksAssociationEndOfVolume;  // "end-of-volume"

// Download
GTL_EXTERN NSString * const kGTLBooksDownloadEpub;  // "epub"

// Features
GTL_EXTERN NSString * const kGTLBooksFeaturesRentals;  // "RENTALS"

// Filter
GTL_EXTERN NSString * const kGTLBooksFilterEbooks;      // "ebooks"
GTL_EXTERN NSString * const kGTLBooksFilterFreeEbooks;  // "free-ebooks"
GTL_EXTERN NSString * const kGTLBooksFilterFull;        // "full"
GTL_EXTERN NSString * const kGTLBooksFilterPaidEbooks;  // "paid-ebooks"
GTL_EXTERN NSString * const kGTLBooksFilterPartial;     // "partial"

// LibraryRestrict
GTL_EXTERN NSString * const kGTLBooksLibraryRestrictMyLibrary;  // "my-library"
GTL_EXTERN NSString * const kGTLBooksLibraryRestrictNoRestrict;  // "no-restrict"

// OrderBy
GTL_EXTERN NSString * const kGTLBooksOrderByNewest;     // "newest"
GTL_EXTERN NSString * const kGTLBooksOrderByRelevance;  // "relevance"

// PrintType
GTL_EXTERN NSString * const kGTLBooksPrintTypeAll;        // "all"
GTL_EXTERN NSString * const kGTLBooksPrintTypeBooks;      // "books"
GTL_EXTERN NSString * const kGTLBooksPrintTypeMagazines;  // "magazines"

// ProcessingState
GTL_EXTERN NSString * const kGTLBooksProcessingStateCompletedFailed;  // "COMPLETED_FAILED"
GTL_EXTERN NSString * const kGTLBooksProcessingStateCompletedSuccess;  // "COMPLETED_SUCCESS"
GTL_EXTERN NSString * const kGTLBooksProcessingStateRunning;    // "RUNNING"

// Projection
GTL_EXTERN NSString * const kGTLBooksProjectionFull;  // "full"
GTL_EXTERN NSString * const kGTLBooksProjectionLite;  // "lite"

// Rating
GTL_EXTERN NSString * const kGTLBooksRatingHaveIt;         // "HAVE_IT"
GTL_EXTERN NSString * const kGTLBooksRatingNotInterested;  // "NOT_INTERESTED"
