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
//  GTLBooksCategory.h
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
//   GTLBooksCategory (0 custom class methods, 2 custom properties)
//   GTLBooksCategoryItemsItem (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBooksCategoryItemsItem;

// ----------------------------------------------------------------------------
//
//   GTLBooksCategory
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLBooksCategory : GTLCollectionObject

// A list of onboarding categories.
@property (nonatomic, retain) NSArray *items;  // of GTLBooksCategoryItemsItem

// Resource type.
@property (nonatomic, copy) NSString *kind;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksCategoryItemsItem
//

@interface GTLBooksCategoryItemsItem : GTLObject
@property (nonatomic, copy) NSString *badgeUrl;
@property (nonatomic, copy) NSString *categoryId;
@property (nonatomic, copy) NSString *name;
@end
