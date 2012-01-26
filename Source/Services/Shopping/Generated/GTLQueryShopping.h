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
//  GTLQueryShopping.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Search API for Shopping (shopping/v1)
// Description:
//   Lets you search over product data
// Documentation:
//   http://code.google.com/apis/shopping/search/v1/getting_started.html
// Classes:
//   GTLQueryShopping (2 custom class methods, 35 custom properties)
//   GTLShoppingProductsGetCategories (0 custom class methods, 3 custom properties)
//   GTLShoppingProductsGetDebug (0 custom class methods, 4 custom properties)
//   GTLShoppingProductsGetRecommendations (0 custom class methods, 3 custom properties)
//   GTLShoppingProductsListCategories (0 custom class methods, 3 custom properties)
//   GTLShoppingProductsListDebug (0 custom class methods, 8 custom properties)
//   GTLShoppingProductsListFacets (0 custom class methods, 4 custom properties)
//   GTLShoppingProductsListPromotions (0 custom class methods, 2 custom properties)
//   GTLShoppingProductsListRedirects (0 custom class methods, 2 custom properties)
//   GTLShoppingProductsListRelatedQueries (0 custom class methods, 2 custom properties)
//   GTLShoppingProductsListSayt (0 custom class methods, 2 custom properties)
//   GTLShoppingProductsListSpelling (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLShoppingProductsGetCategories;
@class GTLShoppingProductsGetDebug;
@class GTLShoppingProductsGetRecommendations;
@class GTLShoppingProductsListCategories;
@class GTLShoppingProductsListDebug;
@class GTLShoppingProductsListFacets;
@class GTLShoppingProductsListPromotions;
@class GTLShoppingProductsListRedirects;
@class GTLShoppingProductsListRelatedQueries;
@class GTLShoppingProductsListSayt;
@class GTLShoppingProductsListSpelling;

@interface GTLQueryShopping : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (assign) NSUInteger accountId;
@property (copy) NSString *attributeFilter;
@property (copy) NSString *boostBy;
// "categories" has different types for some query methods; see the
// documentation for the right type for each query method.
@property (retain) id categories;
@property (copy) NSString *channels;
@property (copy) NSString *country;
@property (copy) NSString *crowdBy;
@property (copy) NSString *currency;
// "debug" has different types for some query methods; see the documentation for
// the right type for each query method.
@property (retain) id debug;
@property (retain) GTLShoppingProductsListFacets *facets;
@property (copy) NSString *language;
@property (copy) NSString *location;
@property (assign) NSUInteger maxResults;
@property (assign) NSUInteger maxVariants;
@property (copy) NSString *minAvailability;
@property (copy) NSString *plusOne;
@property (copy) NSString *productFields;
@property (copy) NSString *productId;
@property (copy) NSString *productIdType;
@property (retain) GTLShoppingProductsListPromotions *promotions;
@property (copy) NSString *q;
@property (copy) NSString *rankBy;
@property (retain) GTLShoppingProductsGetRecommendations *recommendations;
@property (retain) GTLShoppingProductsListRedirects *redirects;
@property (retain) GTLShoppingProductsListRelatedQueries *relatedQueries;
@property (copy) NSString *restrictBy;
@property (assign) BOOL safe;
@property (retain) GTLShoppingProductsListSayt *sayt;
@property (copy) NSString *source;
@property (retain) GTLShoppingProductsListSpelling *spelling;
@property (assign) NSUInteger startIndex;
@property (copy) NSString *taxonomy;
@property (copy) NSString *thumbnails;
@property (copy) NSString *useCase;

#pragma mark -
#pragma mark "products" methods
// These create a GTLQueryShopping object.

// Method: shopping.products.get
// Returns a single product
//  Required:
//   source: Query source
//   accountId: Merchant center account id
//   productIdType: Type of productId
//   productId: Id of product
//  Optional:
//   attributeFilter: Comma separated list of attributes to return
//   location: Location used to determine tax and shipping
//   plusOne: +1 rendering specification.
//   productFields: Google Internal
//   taxonomy: Merchant taxonomy
//   thumbnails: Thumbnail specification
//  Authorization scope(s):
//   kGTLAuthScopeShoppingShoppingapi
// Fetches a GTLShoppingProduct.
+ (id)queryForProductsGetWithSource:(NSString *)source
                          accountId:(NSUInteger)accountId
                      productIdType:(NSString *)productIdType
                          productId:(NSString *)productId;

// Method: shopping.products.list
// Returns a list of products and content modules
//  Required:
//   source: Query source
//  Optional:
//   attributeFilter: Comma separated list of attributes to return
//   boostBy: Boosting specification
//   channels: Channels specification
//   country: Country restriction (ISO 3166)
//   crowdBy: Crowding specification
//   currency: Currency restriction (ISO 4217)
//   language: Language restriction (BCP 47)
//   location: Location used to determine tax and shipping
//   maxResults: Maximum number of results to return
//   maxVariants: Maximum number of variant results to return per result
//   minAvailability:
//      kGTLShoppingMinAvailabilityInStock: Only in stcok prodicts will be
//        returned
//      kGTLShoppingMinAvailabilityLimited: Limited availability and in stock
//        products will be returned
//      kGTLShoppingMinAvailabilityOutOfStock: Out of stock, limited
//        availability and in stock products will be returned
//      kGTLShoppingMinAvailabilityUnknown: All products will be returned
//   plusOne: +1 rendering specification.
//   productFields: Google Internal
//   q: Search query
//   rankBy: Ranking specification
//   restrictBy: Restriction specification
//   safe: Whether safe search is enabled. Default: true
//   startIndex: Index (1-based) of first product to return
//   taxonomy: Taxonomy name
//   thumbnails: Image thumbnails specification
//   useCase: One of CommerceSearchUseCase, ShoppingApiUseCase
//  Authorization scope(s):
//   kGTLAuthScopeShoppingShoppingapi
// Fetches a GTLShoppingProducts.
+ (id)queryForProductsListWithSource:(NSString *)source;

@end

#pragma mark -
#pragma mark method parameter objects
// These object are used only to pass a collection of parameters to a
// method as a single item.

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsGetCategories
//

// Used for 'categories' parameter on 'shopping.products.get'.

@interface GTLShoppingProductsGetCategories : GTLObject

// Whether to return category information
@property (retain) NSNumber *enabled;  // boolValue

// Category specification
@property (copy) NSString *include;

// This parameter is currently ignored
@property (retain) NSNumber *useGcsConfig;  // boolValue

@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsGetDebug
//

// Used for 'debug' parameter on 'shopping.products.get'.

@interface GTLShoppingProductsGetDebug : GTLObject

// Google Internal
@property (retain) NSNumber *enabled;  // boolValue

// Google Internal
@property (retain) NSNumber *enableLogging;  // boolValue

// Google Internal
@property (retain) NSNumber *searchRequest;  // boolValue

// Google Internal
@property (retain) NSNumber *searchResponse;  // boolValue

@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsGetRecommendations
//

// Used for 'recommendations' parameter on 'shopping.products.get'.

@interface GTLShoppingProductsGetRecommendations : GTLObject

// Whether to return recommendation information
@property (retain) NSNumber *enabled;  // boolValue

// Recommendation specification
@property (copy) NSString *include;

// This parameter is currently ignored
@property (retain) NSNumber *useGcsConfig;  // boolValue

@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListCategories
//

// Used for 'categories' parameter on 'shopping.products.list'.

@interface GTLShoppingProductsListCategories : GTLObject

// Whether to return category information
@property (retain) NSNumber *enabled;  // boolValue

// Category specification
@property (copy) NSString *include;

// This parameter is currently ignored
@property (retain) NSNumber *useGcsConfig;  // boolValue

@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListDebug
//

// Used for 'debug' parameter on 'shopping.products.list'.

@interface GTLShoppingProductsListDebug : GTLObject

// Google Internal
@property (retain) NSNumber *enabled;  // boolValue

// Google Internal
@property (retain) NSNumber *enableLogging;  // boolValue

// Google Internal
@property (retain) NSNumber *geocodeRequest;  // boolValue

// Google Internal
@property (retain) NSNumber *geocodeResponse;  // boolValue

// Google Internal
@property (retain) NSNumber *rdcRequest;  // boolValue

// Google Internal
@property (retain) NSNumber *rdcResponse;  // boolValue

// Google Internal
@property (retain) NSNumber *searchRequest;  // boolValue

// Google Internal
@property (retain) NSNumber *searchResponse;  // boolValue

@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListFacets
//

// Used for 'facets' parameter on 'shopping.products.list'.

@interface GTLShoppingProductsListFacets : GTLObject

// Facets to discover
@property (copy) NSString *discover;

// Whether to return facet information
@property (retain) NSNumber *enabled;  // boolValue

// Facets to include (applies when useGcsConfig == false)
@property (copy) NSString *include;

// Whether to return facet information as configured in the GCS account
@property (retain) NSNumber *useGcsConfig;  // boolValue

@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListPromotions
//

// Used for 'promotions' parameter on 'shopping.products.list'.

@interface GTLShoppingProductsListPromotions : GTLObject

// Whether to return promotion information
@property (retain) NSNumber *enabled;  // boolValue

// Whether to return promotion information as configured in the GCS account
@property (retain) NSNumber *useGcsConfig;  // boolValue

@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListRedirects
//

// Used for 'redirects' parameter on 'shopping.products.list'.

@interface GTLShoppingProductsListRedirects : GTLObject

// Whether to return redirect information
@property (retain) NSNumber *enabled;  // boolValue

// Whether to return redirect information as configured in the GCS account
@property (retain) NSNumber *useGcsConfig;  // boolValue

@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListRelatedQueries
//

// Used for 'relatedQueries' parameter on 'shopping.products.list'.

@interface GTLShoppingProductsListRelatedQueries : GTLObject

// Whether to return related queries
@property (retain) NSNumber *enabled;  // boolValue

// This parameter is currently ignored
@property (retain) NSNumber *useGcsConfig;  // boolValue

@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListSayt
//

// Used for 'sayt' parameter on 'shopping.products.list'.

@interface GTLShoppingProductsListSayt : GTLObject

// Google Internal
@property (retain) NSNumber *enabled;  // boolValue

// Google Internal
@property (retain) NSNumber *useGcsConfig;  // boolValue

@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListSpelling
//

// Used for 'spelling' parameter on 'shopping.products.list'.

@interface GTLShoppingProductsListSpelling : GTLObject

// Whether to return spelling suggestions
@property (retain) NSNumber *enabled;  // boolValue

// This parameter is currently ignored
@property (retain) NSNumber *useGcsConfig;  // boolValue

@end
