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
//   Search API For Shopping (shopping/v1)
// Description:
//   Lets you search over product data.
// Documentation:
//   http://code.google.com/apis/shopping/search/v1/getting_started.html
// Classes:
//   GTLQueryShopping (2 custom class methods, 34 custom properties)
//   GTLShoppingProductsGetCategories (0 custom class methods, 3 custom properties)
//   GTLShoppingProductsGetPlusOne (0 custom class methods, 3 custom properties)
//   GTLShoppingProductsGetRecommendations (0 custom class methods, 3 custom properties)
//   GTLShoppingProductsListCategories (0 custom class methods, 3 custom properties)
//   GTLShoppingProductsListCategoryRecommendations (0 custom class methods, 4 custom properties)
//   GTLShoppingProductsListFacets (0 custom class methods, 4 custom properties)
//   GTLShoppingProductsListPlusOne (0 custom class methods, 3 custom properties)
//   GTLShoppingProductsListPromotions (0 custom class methods, 2 custom properties)
//   GTLShoppingProductsListRedirects (0 custom class methods, 2 custom properties)
//   GTLShoppingProductsListRelatedQueries (0 custom class methods, 2 custom properties)
//   GTLShoppingProductsListSpelling (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLShoppingProductsGetCategories;
@class GTLShoppingProductsGetPlusOne;
@class GTLShoppingProductsGetRecommendations;
@class GTLShoppingProductsListCategories;
@class GTLShoppingProductsListCategoryRecommendations;
@class GTLShoppingProductsListFacets;
@class GTLShoppingProductsListPlusOne;
@class GTLShoppingProductsListPromotions;
@class GTLShoppingProductsListRedirects;
@class GTLShoppingProductsListRelatedQueries;
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
@property (copy) NSString *availability;
@property (copy) NSString *boostBy;
// "categories" has different types for some query methods; see the
// documentation for the right type for each query method.
@property (retain) id categories;
@property (retain) GTLShoppingProductsListCategoryRecommendations *categoryRecommendations;
@property (copy) NSString *channels;
@property (assign) BOOL clickTracking;
@property (copy) NSString *country;
@property (copy) NSString *crowdBy;
@property (copy) NSString *currency;
@property (retain) GTLShoppingProductsListFacets *facets;
@property (copy) NSString *language;
@property (copy) NSString *location;
@property (assign) NSUInteger maxResults;
@property (assign) NSInteger maxVariants;
// "plusOne" has different types for some query methods; see the documentation
// for the right type for each query method.
@property (retain) id plusOne;
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
//   categories: For this method, "categories" should be of type
//     GTLShoppingProductsGetCategories.
//   location: Location used to determine tax and shipping
//   plusOne: For this method, "plusOne" should be of type
//     GTLShoppingProductsGetPlusOne.
//   recommendations: GTLShoppingProductsGetRecommendations
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
//   availability: Comma separated list of availabilities (outOfStock, limited,
//     inStock, backOrder, preOrder, onDisplayToOrder) to return
//   boostBy: Boosting specification
//   categories: For this method, "categories" should be of type
//     GTLShoppingProductsListCategories.
//   categoryRecommendations: GTLShoppingProductsListCategoryRecommendations
//   channels: Channels specification
//   clickTracking: Whether to add a click tracking parameter to offer URLs
//   country: Country restriction (ISO 3166)
//   crowdBy: Crowding specification
//   currency: Currency restriction (ISO 4217)
//   facets: GTLShoppingProductsListFacets
//   language: Language restriction (BCP 47)
//   location: Location used to determine tax and shipping
//   maxResults: Maximum number of results to return
//   maxVariants: Maximum number of variant results to return per result
//   plusOne: For this method, "plusOne" should be of type
//     GTLShoppingProductsListPlusOne.
//   promotions: GTLShoppingProductsListPromotions
//   q: Search query
//   rankBy: Ranking specification
//   redirects: GTLShoppingProductsListRedirects
//   relatedQueries: GTLShoppingProductsListRelatedQueries
//   restrictBy: Restriction specification
//   safe: Whether safe search is enabled. Default: true
//   spelling: GTLShoppingProductsListSpelling
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
//   GTLShoppingProductsGetPlusOne
//

// Used for 'plusOne' parameter on 'shopping.products.get'.

@interface GTLShoppingProductsGetPlusOne : GTLObject

// Whether to return +1 button code
@property (retain) NSNumber *enabled;  // boolValue

// +1 button rendering styles
@property (copy) NSString *styles;

// Whether to use +1 button styles configured in the GCS account
@property (retain) NSNumber *useGcsConfig;  // boolValue

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
//   GTLShoppingProductsListCategoryRecommendations
//

// Used for 'categoryRecommendations' parameter on 'shopping.products.list'.

@interface GTLShoppingProductsListCategoryRecommendations : GTLObject

// Category for which to retrieve recommendations
@property (copy) NSString *category;

// Whether to return category recommendation information
@property (retain) NSNumber *enabled;  // boolValue

// Category recommendation specification
@property (copy) NSString *include;

// This parameter is currently ignored
@property (retain) NSNumber *useGcsConfig;  // boolValue

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
//   GTLShoppingProductsListPlusOne
//

// Used for 'plusOne' parameter on 'shopping.products.list'.

@interface GTLShoppingProductsListPlusOne : GTLObject

// Whether to return +1 button code
@property (retain) NSNumber *enabled;  // boolValue

// +1 button rendering styles
@property (copy) NSString *styles;

// Whether to use +1 button styles configured in the GCS account
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
//   GTLShoppingProductsListSpelling
//

// Used for 'spelling' parameter on 'shopping.products.list'.

@interface GTLShoppingProductsListSpelling : GTLObject

// Whether to return spelling suggestions
@property (retain) NSNumber *enabled;  // boolValue

// This parameter is currently ignored
@property (retain) NSNumber *useGcsConfig;  // boolValue

@end
