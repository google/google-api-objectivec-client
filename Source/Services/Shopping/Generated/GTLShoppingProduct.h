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
//  GTLShoppingProduct.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Search API For Shopping (shopping/v1)
// Description:
//   Lets you search over product data.
// Documentation:
//   http://code.google.com/apis/shopping/search/v1/getting_started.html
// Classes:
//   GTLShoppingProduct (0 custom class methods, 8 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLShoppingModelCategory;
@class GTLShoppingModelDebug;
@class GTLShoppingModelProduct;
@class GTLShoppingModelRecommendations;

// ----------------------------------------------------------------------------
//
//   GTLShoppingProduct
//

@interface GTLShoppingProduct : GTLObject

// List of categories for product.
@property (retain) NSArray *categories;  // of GTLShoppingModelCategory

// Google internal.
@property (retain) GTLShoppingModelDebug *debug;

// Id of product.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The kind of item, always shopping#product.
@property (copy) NSString *kind;

// Product.
@property (retain) GTLShoppingModelProduct *product;

// Recommendations for product.
@property (retain) NSArray *recommendations;  // of GTLShoppingModelRecommendations

// Unique identifier for this request.
@property (copy) NSString *requestId;

// Self link of product when generated for a search request. Self link of
// product when generated for a lookup request.
@property (copy) NSString *selfLink;

@end
