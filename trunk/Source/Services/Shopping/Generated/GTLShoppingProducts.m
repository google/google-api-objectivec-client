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
//  GTLShoppingProducts.m
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

#import "GTLShoppingProducts.h"

#import "GTLShoppingModelCategory.h"
#import "GTLShoppingModelDebug.h"
#import "GTLShoppingModelProduct.h"
#import "GTLShoppingModelRecommendations.h"
#import "GTLShoppingProduct.h"

// ----------------------------------------------------------------------------
//
//   GTLShoppingProducts
//

@implementation GTLShoppingProducts
@dynamic categories, categoryRecommendations, currentItemCount, debug, ETag,
         facets, identifier, items, itemsPerPage, kind, nextLink, previousLink,
         promotions, redirects, relatedQueries, requestId, selfLink, spelling,
         startIndex, stores, totalItems;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"etag", @"ETag",
      @"id", @"identifier",
      nil];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLShoppingModelCategory class], @"categories",
      [GTLShoppingModelRecommendations class], @"categoryRecommendations",
      [GTLShoppingProductsFacetsItem class], @"facets",
      [GTLShoppingProduct class], @"items",
      [GTLShoppingProductsPromotionsItem class], @"promotions",
      [NSString class], @"redirects",
      [NSString class], @"relatedQueries",
      [GTLShoppingProductsStoresItem class], @"stores",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"shopping#products"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsFacetsItem
//

@implementation GTLShoppingProductsFacetsItem
@dynamic buckets, count, displayName, name, property, type, unit;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLShoppingProductsFacetsItemBucketsItem class]
                                forKey:@"buckets"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsPromotionsItem
//

@implementation GTLShoppingProductsPromotionsItem
@dynamic customFields, customHtml, descriptionProperty, destLink, imageLink,
         name, product, type;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"description"
                                forKey:@"descriptionProperty"];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLShoppingProductsPromotionsItemCustomFieldsItem class]
                                forKey:@"customFields"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsSpelling
//

@implementation GTLShoppingProductsSpelling
@dynamic suggestion;
@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsStoresItem
//

@implementation GTLShoppingProductsStoresItem
@dynamic address, location, name, storeCode, storeId, storeName, telephone;
@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsFacetsItemBucketsItem
//

@implementation GTLShoppingProductsFacetsItemBucketsItem
@dynamic count, max, maxExclusive, min, minExclusive, value;
@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingProductsPromotionsItemCustomFieldsItem
//

@implementation GTLShoppingProductsPromotionsItemCustomFieldsItem
@dynamic name, value;
@end
