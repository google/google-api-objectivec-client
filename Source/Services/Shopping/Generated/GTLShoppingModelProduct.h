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
//  GTLShoppingModelProduct.h
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
//   GTLShoppingModelProduct (0 custom class methods, 35 custom properties)
//   GTLShoppingModelProductAttributesItem (0 custom class methods, 5 custom properties)
//   GTLShoppingModelProductAuthor (0 custom class methods, 2 custom properties)
//   GTLShoppingModelProductImagesItem (0 custom class methods, 3 custom properties)
//   GTLShoppingModelProductInternal4Item (0 custom class methods, 2 custom properties)
//   GTLShoppingModelProductInventoriesItem (0 custom class methods, 15 custom properties)
//   GTLShoppingModelProductVariantsItem (0 custom class methods, 1 custom properties)
//   GTLShoppingModelProductImagesItemThumbnailsItem (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLShoppingModelProduct;
@class GTLShoppingModelProductAttributesItem;
@class GTLShoppingModelProductAuthor;
@class GTLShoppingModelProductImagesItem;
@class GTLShoppingModelProductImagesItemThumbnailsItem;
@class GTLShoppingModelProductInternal4Item;
@class GTLShoppingModelProductInventoriesItem;
@class GTLShoppingModelProductVariantsItem;

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
@property (copy) NSString *brand;

// Categories of product according to the selected taxonomy, omitted if no
// taxonomy is selected.
@property (retain) NSArray *categories;  // of NSString

// Condition of product (one of: new, refurbished, used).
@property (copy) NSString *condition;

// ISO 3166 code of target country of product.
@property (copy) NSString *country;

// RFC 3339 formatted creation time and date of product.
@property (retain) GTLDateTime *creationTime;

// Description of product.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Google id of product.
@property (retain) NSNumber *googleId;  // unsignedLongLongValue

// The first GTIN of the product. Deprecated in favor of "gtins".
@property (copy) NSString *gtin;

// List of all the product's GTINs (in GTIN-14 format).
@property (retain) NSArray *gtins;  // of NSString

// Images of product.
@property (retain) NSArray *images;  // of GTLShoppingModelProductImagesItem

// Google Internal.
@property (retain) NSArray *internal1;  // of NSString

// Google Internal.
@property (retain) NSArray *internal10;  // of NSString

// Google Internal.
@property (copy) NSString *internal12;

// Google Internal.
@property (retain) NSNumber *internal13;  // doubleValue

// Google Internal.
@property (retain) NSNumber *internal14;  // doubleValue

// Google Internal.
@property (retain) NSNumber *internal15;  // doubleValue

// Google Internal.
@property (copy) NSString *internal3;

// Google Internal.
@property (retain) NSArray *internal4;  // of GTLShoppingModelProductInternal4Item

// Google Internal.
@property (copy) NSString *internal6;

// Google Internal.
@property (retain) NSNumber *internal7;  // boolValue

// Google Internal.
@property (retain) NSArray *internal8;  // of NSString

// Inventories of product.
@property (retain) NSArray *inventories;  // of GTLShoppingModelProductInventoriesItem

// BCP 47 language tag of language of product.
@property (copy) NSString *language;

// Link to product.
@property (copy) NSString *link;

// RFC 3339 formatted modification time and date of product.
@property (retain) GTLDateTime *modificationTime;

// List of all the product's MPNs.
@property (retain) NSArray *mpns;  // of NSString

// Code to add to the page to render the +1 content.
@property (copy) NSString *plusOne;

// Merchant-provided id of product (available only with a cx source).
@property (copy) NSString *providedId;

// Whether this product matched the user query. Only set for the variant offers
// (if any) attached to a product offer.
@property (retain) NSNumber *queryMatched;  // boolValue

// Google Internal
@property (retain) NSNumber *score;  // floatValue

// Title of product.
@property (copy) NSString *title;

// The number of variant offers returned that matched the query.
@property (retain) NSNumber *totalMatchingVariants;  // intValue

// A list of variant offers associated with this product.
@property (retain) NSArray *variants;  // of GTLShoppingModelProductVariantsItem

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductAttributesItem
//

@interface GTLShoppingModelProductAttributesItem : GTLObject

// Display Name of prodct attribute.
@property (copy) NSString *displayName;

// Name of product attribute.
@property (copy) NSString *name;

// Type of product attribute (one of: text, bool, int, float, dateRange, url).
@property (copy) NSString *type;

// Unit of product attribute.
@property (copy) NSString *unit;

// Value of product attribute.
@property (retain) id value;

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductAuthor
//

@interface GTLShoppingModelProductAuthor : GTLObject

// Account id of product author.
@property (retain) NSNumber *accountId;  // unsignedLongLongValue

// Name of product author.
@property (copy) NSString *name;

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductImagesItem
//

@interface GTLShoppingModelProductImagesItem : GTLObject

// Link to product image.
@property (copy) NSString *link;

@property (copy) NSString *status;

// Thumbnails of product image.
@property (retain) NSArray *thumbnails;  // of GTLShoppingModelProductImagesItemThumbnailsItem

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductInternal4Item
//

@interface GTLShoppingModelProductInternal4Item : GTLObject

// Google Internal.
@property (retain) NSNumber *confidence;  // doubleValue

// Google Internal.
@property (retain) NSNumber *node;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductInventoriesItem
//

@interface GTLShoppingModelProductInventoriesItem : GTLObject

// Availability of product inventory.
@property (copy) NSString *availability;

// Channel of product inventory (one of: online, local).
@property (copy) NSString *channel;

// Currency of product inventory (an ISO 4217 alphabetic code).
@property (copy) NSString *currency;

// Distance of product inventory.
@property (retain) NSNumber *distance;  // floatValue

// Distance unit of product inventory.
@property (copy) NSString *distanceUnit;

// Number of months for installment price.
@property (retain) NSNumber *installmentMonths;  // intValue

// Installment price of product inventory.
@property (retain) NSNumber *installmentPrice;  // floatValue

// Original price of product inventory. Only returned for products that are on
// sale.
@property (retain) NSNumber *originalPrice;  // floatValue

// Price of product inventory.
@property (retain) NSNumber *price;  // floatValue

// Sale end date.
@property (retain) GTLDateTime *saleEndDate;

// Sale price of product inventory.
@property (retain) NSNumber *salePrice;  // floatValue

// Sale start date.
@property (retain) GTLDateTime *saleStartDate;

// Shipping cost of product inventory.
@property (retain) NSNumber *shipping;  // floatValue

// Store ID of product inventory.
@property (copy) NSString *storeId;

// Tax of product inventory.
@property (retain) NSNumber *tax;  // floatValue

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductVariantsItem
//

@interface GTLShoppingModelProductVariantsItem : GTLObject

// The detailed offer data for a particular variant offer.
@property (retain) GTLShoppingModelProduct *variant;

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelProductImagesItemThumbnailsItem
//

@interface GTLShoppingModelProductImagesItemThumbnailsItem : GTLObject

// Content of thumbnail (only available for the first thumbnail of the top
// results if SAYT is enabled).
@property (copy) NSString *content;

// Height of thumbnail (omitted if not specified in the request).
@property (retain) NSNumber *height;  // intValue

// Link to thumbnail.
@property (copy) NSString *link;

// Width of thumbnail (omitted if not specified in the request).
@property (retain) NSNumber *width;  // intValue

@end
