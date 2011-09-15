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
//  GTLQueryShopping.m
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
//   GTLQueryShopping (2 custom class methods, 34 custom properties)
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
//   GTLShoppingProductsListShelfSpaceAds (0 custom class methods, 3 custom properties)
//   GTLShoppingProductsListSpelling (0 custom class methods, 2 custom properties)

#import "GTLQueryShopping.h"

#import "GTLShoppingProduct.h"
#import "GTLShoppingProducts.h"

@implementation GTLQueryShopping

@dynamic accountId, attributeFilter, boostBy, categories, channels, country,
         crowdBy, currency, debug, facets, fields, language, location,
         maxResults, minAvailability, productFields, productId, productIdType,
         promotions, q, rankBy, recommendations, redirects, relatedQueries,
         restrictBy, safe, sayt, shelfSpaceAds, source, spelling, startIndex,
         taxonomy, thumbnails, useCase;

#pragma mark -
#pragma mark "products" methods
// These create a GTLQueryShopping object.

+ (id)queryForProductsGetWithSource:(NSString *)source
                          accountId:(NSUInteger)accountId
                      productIdType:(NSString *)productIdType
                          productId:(NSString *)productId {
  NSString *methodName = @"shopping.products.get";
  GTLQueryShopping *query = [self queryWithMethodName:methodName];
  query.source = source;
  query.accountId = accountId;
  query.productIdType = productIdType;
  query.productId = productId;
  query.expectedObjectClass = [GTLShoppingProduct class];
  return query;
}

+ (id)queryForProductsListWithSource:(NSString *)source {
  NSString *methodName = @"shopping.products.list";
  GTLQueryShopping *query = [self queryWithMethodName:methodName];
  query.source = source;
  query.expectedObjectClass = [GTLShoppingProducts class];
  return query;
}

@end

#pragma mark -
#pragma mark method parameter objects
// These object are used only to pass a collection of parameters to a
// method as a single item.

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsGetCategories
//

@implementation GTLShoppingProductsGetCategories
@dynamic enabled, include, useGcsConfig;
@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsGetDebug
//

@implementation GTLShoppingProductsGetDebug
@dynamic enabled, enableLogging, searchRequest, searchResponse;
@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsGetRecommendations
//

@implementation GTLShoppingProductsGetRecommendations
@dynamic enabled, include, useGcsConfig;
@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListCategories
//

@implementation GTLShoppingProductsListCategories
@dynamic enabled, include, useGcsConfig;
@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListDebug
//

@implementation GTLShoppingProductsListDebug
@dynamic enabled, enableLogging, geocodeRequest, geocodeResponse, rdcRequest,
         rdcResponse, searchRequest, searchResponse;
@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListFacets
//

@implementation GTLShoppingProductsListFacets
@dynamic discover, enabled, include, useGcsConfig;
@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListPromotions
//

@implementation GTLShoppingProductsListPromotions
@dynamic enabled, useGcsConfig;
@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListRedirects
//

@implementation GTLShoppingProductsListRedirects
@dynamic enabled, useGcsConfig;
@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListRelatedQueries
//

@implementation GTLShoppingProductsListRelatedQueries
@dynamic enabled, useGcsConfig;
@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListSayt
//

@implementation GTLShoppingProductsListSayt
@dynamic enabled, useGcsConfig;
@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListShelfSpaceAds
//

@implementation GTLShoppingProductsListShelfSpaceAds
@dynamic enabled, maxResults, useGcsConfig;
@end

// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsListSpelling
//

@implementation GTLShoppingProductsListSpelling
@dynamic enabled, useGcsConfig;
@end
