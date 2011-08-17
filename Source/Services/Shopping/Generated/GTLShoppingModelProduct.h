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
//  GTLShoppingModelProduct.h
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
//   GTLShoppingModelProduct (0 custom class methods, 18 custom properties)
//   GTLShoppingModelProductAttributesItem (0 custom class methods, 5 custom properties)
//   GTLShoppingModelProductAuthor (0 custom class methods, 5 custom properties)
//   GTLShoppingModelProductImagesItem (0 custom class methods, 2 custom properties)
//   GTLShoppingModelProductInventoriesItem (0 custom class methods, 7 custom properties)
//   GTLShoppingModelProductImagesItemThumbnailsItem (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLShoppingModelProductAttributesItem;
@class GTLShoppingModelProductAuthor;
@class GTLShoppingModelProductImagesItem;
@class GTLShoppingModelProductImagesItemThumbnailsItem;
@class GTLShoppingModelProductInventoriesItem;

// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProduct
//

@interface GTLShoppingModelProduct : GTLObject

// Attributes of product (available only with a cx source).
@property (retain) NSArray *attributes;  // of GTLShoppingModelProductAttributesItem

// Author of product.
@property (retain) GTLShoppingModelProductAuthor *author;

// Brand of product.
@property (retain) NSString *brand;

// Categories of product according to the selected taxonomy, omitted if no
// taxonomy is selected.
@property (retain) NSArray *categories;  // of NSString

// Condition of product (one of: new, refurbished, used).
@property (retain) NSString *condition;

// ISO 3166 code of target country of product.
@property (retain) NSString *country;

// RFC 3339 formatted creation time and date of product.
@property (retain) GTLDateTime *creationTime;

// Description of product.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (retain) NSString *descriptionProperty;

// Google id of product.
@property (retain) NSString *googleId;

// The first GTIN of the product. Deprecated in favor of "gtins".
@property (retain) NSString *gtin;

// List of all the product's GTINs (in GTIN-14 format).
@property (retain) NSArray *gtins;  // of NSString

// Images of product.
@property (retain) NSArray *images;  // of GTLShoppingModelProductImagesItem

// Inventories of product.
@property (retain) NSArray *inventories;  // of GTLShoppingModelProductInventoriesItem

// BCP 47 language tag of language of product.
@property (retain) NSString *language;

// Link to product.
@property (retain) NSString *link;

// RFC 3339 formatted modification time and date of product.
@property (retain) GTLDateTime *modificationTime;

// Merchant-provided id of product (available only with a cx source).
@property (retain) NSString *providedId;

// Title of product.
@property (retain) NSString *title;

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductAttributesItem
//

@interface GTLShoppingModelProductAttributesItem : GTLObject

// Display Name of prodct attribute.
@property (retain) NSString *displayName;

// Name of product attribute.
@property (retain) NSString *name;

// Type of product attribute (one of: text, bool, int, float, dateRange, url).
@property (retain) NSString *type;

// Unit of product attribute.
@property (retain) NSString *unit;

// Value of product attribute.
@property (retain) id value;

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductAuthor
//

@interface GTLShoppingModelProductAuthor : GTLObject

// Account id of product author.
@property (retain) NSString *accountId;

// Aggregator id of product author.
@property (retain) NSString *aggregatorId;

// Email address of product author.
@property (retain) NSString *email;

// Name of product author.
@property (retain) NSString *name;

// URI of product author.
@property (retain) NSString *uri;

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductImagesItem
//

@interface GTLShoppingModelProductImagesItem : GTLObject

// Link to product image.
@property (retain) NSString *link;

// Thumbnails of product image.
@property (retain) NSArray *thumbnails;  // of GTLShoppingModelProductImagesItemThumbnailsItem

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductInventoriesItem
//

@interface GTLShoppingModelProductInventoriesItem : GTLObject

// Availability of product inventory.
@property (retain) NSString *availability;

// Channel of product inventory (one of: online, local).
@property (retain) NSString *channel;

// Currency of product inventory (an ISO 4217 alphabetic code).
@property (retain) NSString *currency;

// Distance of product inventory.
@property (retain) NSNumber *distance;  // floatValue

// Distance unit of product inventory.
@property (retain) NSString *distanceUnit;

// Price of product inventory.
@property (retain) NSNumber *price;  // floatValue

// Store ID of product inventory.
@property (retain) NSString *storeId;

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductImagesItemThumbnailsItem
//

@interface GTLShoppingModelProductImagesItemThumbnailsItem : GTLObject

// Content of thumbnail (only available for the first thumbnail of the top
// results if SAYT is enabled).
@property (retain) NSString *content;

// Height of thumbnail (omitted if not specified in the request).
@property (retain) NSNumber *height;  // intValue

// Link to thumbnail.
@property (retain) NSString *link;

// Width of thumbnail (omitted if not specified in the request).
@property (retain) NSNumber *width;  // intValue

@end
