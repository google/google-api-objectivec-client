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
//  GTLShoppingProducts.h
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
//   GTLShoppingProducts (0 custom class methods, 21 custom properties)
//   GTLShoppingProductsFacetsItem (0 custom class methods, 7 custom properties)
//   GTLShoppingProductsPromotionsItem (0 custom class methods, 8 custom properties)
//   GTLShoppingProductsSpelling (0 custom class methods, 1 custom properties)
//   GTLShoppingProductsStoresItem (0 custom class methods, 7 custom properties)
//   GTLShoppingProductsFacetsItemBucketsItem (0 custom class methods, 6 custom properties)
//   GTLShoppingProductsPromotionsItemCustomFieldsItem (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLShoppingModelCategory;
@class GTLShoppingModelDebug;
@class GTLShoppingModelProduct;
@class GTLShoppingModelRecommendations;
@class GTLShoppingProduct;
@class GTLShoppingProductsFacetsItem;
@class GTLShoppingProductsFacetsItemBucketsItem;
@class GTLShoppingProductsPromotionsItem;
@class GTLShoppingProductsPromotionsItemCustomFieldsItem;
@class GTLShoppingProductsSpelling;
@class GTLShoppingProductsStoresItem;

// ----------------------------------------------------------------------------
//
//   GTLShoppingProducts
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLShoppingProducts : GTLCollectionObject

// List of categories.
@property (retain) NSArray *categories;  // of GTLShoppingModelCategory

// Recommendations for category.
@property (retain) NSArray *categoryRecommendations;  // of GTLShoppingModelRecommendations

// Current item count.
@property (retain) NSNumber *currentItemCount;  // intValue

// Google internal.
@property (retain) GTLShoppingModelDebug *debug;

// Etag of feed.
@property (copy) NSString *ETag;

// List of facets.
@property (retain) NSArray *facets;  // of GTLShoppingProductsFacetsItem

// Id of feed.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// List of returned products.
@property (retain) NSArray *items;  // of GTLShoppingProduct

// Number of items per page of results.
@property (retain) NSNumber *itemsPerPage;  // intValue

// The fixed string "shopping#products". The kind of feed returned.
@property (copy) NSString *kind;

// Next link of feed.
@property (copy) NSString *nextLink;

// Previous link of feed.
@property (copy) NSString *previousLink;

// List of promotions.
@property (retain) NSArray *promotions;  // of GTLShoppingProductsPromotionsItem

// Redirects.
@property (retain) NSArray *redirects;  // of NSString

// Related queries.
@property (retain) NSArray *relatedQueries;  // of NSString

// Unique identifier for this request.
@property (copy) NSString *requestId;

// Self link of feed.
@property (copy) NSString *selfLink;

// Spelling.
@property (retain) GTLShoppingProductsSpelling *spelling;

// 1-based index of the first item in the search results.
@property (retain) NSNumber *startIndex;  // intValue

// List of returned stores.
@property (retain) NSArray *stores;  // of GTLShoppingProductsStoresItem

// Total number of search results.
@property (retain) NSNumber *totalItems;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsFacetsItem
//

@interface GTLShoppingProductsFacetsItem : GTLObject

// List of Buckets within facet.
@property (retain) NSArray *buckets;  // of GTLShoppingProductsFacetsItemBucketsItem

// Number of products matching the query that have a value for the facet's
// property or attribute.
@property (retain) NSNumber *count;  // intValue

// Display name of facet.
@property (copy) NSString *displayName;

// Name of the facet's attribute (omitted for property facets).
@property (copy) NSString *name;

// Property of facet (omitted for attribute facets).
@property (copy) NSString *property;

// Type of facet's attribute (omitted for property facets, one of: text, bool,
// int, float).
@property (copy) NSString *type;

// Unit of the facet's property or attribute (omitted if the facet's property or
// attribute has no unit).
@property (copy) NSString *unit;

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsPromotionsItem
//

@interface GTLShoppingProductsPromotionsItem : GTLObject

// List of custom fields of promotion.
@property (retain) NSArray *customFields;  // of GTLShoppingProductsPromotionsItemCustomFieldsItem

// Custom HTML of promotion (omitted if type is not custom).
@property (copy) NSString *customHtml;

// Description of promotion (omitted if type is not standard).
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Link to promotion (omitted if type is not standard).
@property (copy) NSString *destLink;

// Link to promotion image (omitted if type is not standard).
@property (copy) NSString *imageLink;

// Name of promotion (omitted if type is not standard).
@property (copy) NSString *name;

// Product of promotion (omitted if type is not product).
@property (retain) GTLShoppingModelProduct *product;

// Type of promotion (one of: standard, product, custom).
@property (copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsSpelling
//

@interface GTLShoppingProductsSpelling : GTLObject

// Suggestion for spelling.
@property (copy) NSString *suggestion;

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsStoresItem
//

@interface GTLShoppingProductsStoresItem : GTLObject

// Address of store.
@property (copy) NSString *address;

// Location of store.
@property (copy) NSString *location;

// Name of merchant.
@property (copy) NSString *name;

// Merchant-supplied store code.
@property (copy) NSString *storeCode;

// Id of store.
@property (copy) NSString *storeId;

// Name of store.
@property (copy) NSString *storeName;

// Telephone number of store.
@property (copy) NSString *telephone;

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsFacetsItemBucketsItem
//

@interface GTLShoppingProductsFacetsItemBucketsItem : GTLObject

// Number of products matching the query that have a value for the facet's
// property or attribute that matches the bucket.
@property (retain) NSNumber *count;  // intValue

// Upper bound of the bucket (omitted for value buckets or if the range has no
// upper bound).
@property (retain) id max;

// Whether the upper bound of the bucket is exclusive (omitted for value buckets
// or if the range has no upper bound).
@property (retain) NSNumber *maxExclusive;  // boolValue

// Lower bound of the bucket (omitted for value buckets or if the range has no
// lower bound).
@property (retain) id min;

// Whether the lower bound of the bucket is exclusive (omitted for value buckets
// or if the range has no lower bound).
@property (retain) NSNumber *minExclusive;  // boolValue

// Value of the bucket (omitted for range buckets).
@property (retain) id value;

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsPromotionsItemCustomFieldsItem
//

@interface GTLShoppingProductsPromotionsItemCustomFieldsItem : GTLObject

// Name of field.
@property (copy) NSString *name;

// Value of field.
@property (copy) NSString *value;

@end
