/* Copyright (c) 2014 Google Inc.
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
//  GTLBooksOffers.h
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
//   GTLBooksOffers (0 custom class methods, 2 custom properties)
//   GTLBooksOffersItemsItem (0 custom class methods, 3 custom properties)
//   GTLBooksOffersItemsItemItemsItem (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBooksOffersItemsItem;
@class GTLBooksOffersItemsItemItemsItem;

// ----------------------------------------------------------------------------
//
//   GTLBooksOffers
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLBooksOffers : GTLCollectionObject

// A list of offers.
@property (retain) NSArray *items;  // of GTLBooksOffersItemsItem

// Resource type.
@property (copy) NSString *kind;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksOffersItemsItem
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLBooksOffersItemsItem : GTLCollectionObject
@property (copy) NSString *artUrl;

// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

@property (retain) NSArray *items;  // of GTLBooksOffersItemsItemItemsItem
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksOffersItemsItemItemsItem
//

@interface GTLBooksOffersItemsItemItemsItem : GTLObject
@property (copy) NSString *author;
@property (copy) NSString *canonicalVolumeLink;
@property (copy) NSString *coverUrl;

// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

@property (copy) NSString *title;
@property (copy) NSString *volumeId;
@end
