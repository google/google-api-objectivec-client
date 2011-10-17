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
//  GTLShoppingModelProduct.m
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
//   GTLShoppingModelProduct (0 custom class methods, 19 custom properties)
//   GTLShoppingModelProductAttributesItem (0 custom class methods, 5 custom properties)
//   GTLShoppingModelProductAuthor (0 custom class methods, 5 custom properties)
//   GTLShoppingModelProductImagesItem (0 custom class methods, 2 custom properties)
//   GTLShoppingModelProductInventoriesItem (0 custom class methods, 9 custom properties)
//   GTLShoppingModelProductImagesItemThumbnailsItem (0 custom class methods, 4 custom properties)

#import "GTLShoppingModelProduct.h"

// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProduct
//

@implementation GTLShoppingModelProduct
@dynamic attributes, author, brand, categories, condition, country,
         creationTime, descriptionProperty, googleId, gtin, gtins, images,
         inventories, language, link, modificationTime, plusOne, providedId,
         title;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"description"
                                forKey:@"descriptionProperty"];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLShoppingModelProductAttributesItem class], @"attributes",
      [NSString class], @"categories",
      [NSString class], @"gtins",
      [GTLShoppingModelProductImagesItem class], @"images",
      [GTLShoppingModelProductInventoriesItem class], @"inventories",
      nil];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductAttributesItem
//

@implementation GTLShoppingModelProductAttributesItem
@dynamic displayName, name, type, unit, value;
@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductAuthor
//

@implementation GTLShoppingModelProductAuthor
@dynamic accountId, aggregatorId, email, name, uri;
@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductImagesItem
//

@implementation GTLShoppingModelProductImagesItem
@dynamic link, thumbnails;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLShoppingModelProductImagesItemThumbnailsItem class]
                                forKey:@"thumbnails"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductInventoriesItem
//

@implementation GTLShoppingModelProductInventoriesItem
@dynamic availability, channel, currency, distance, distanceUnit, price,
         shipping, storeId, tax;
@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductImagesItemThumbnailsItem
//

@implementation GTLShoppingModelProductImagesItemThumbnailsItem
@dynamic content, height, link, width;
@end
