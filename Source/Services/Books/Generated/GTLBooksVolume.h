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
//  GTLBooksVolume.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Books API (books/v1)
// Description:
//   Lets you search for books and manage your Google Books library.
// Documentation:
//   https://code.google.com/apis/books/docs/v1/getting_started.html
// Classes:
//   GTLBooksVolume (0 custom class methods, 9 custom properties)
//   GTLBooksVolumeAccessInfo (0 custom class methods, 11 custom properties)
//   GTLBooksVolumeSaleInfo (0 custom class methods, 7 custom properties)
//   GTLBooksVolumeSearchInfo (0 custom class methods, 1 custom properties)
//   GTLBooksVolumeUserInfo (0 custom class methods, 6 custom properties)
//   GTLBooksVolumeVolumeInfo (0 custom class methods, 20 custom properties)
//   GTLBooksVolumeAccessInfoEpub (0 custom class methods, 3 custom properties)
//   GTLBooksVolumeAccessInfoPdf (0 custom class methods, 3 custom properties)
//   GTLBooksVolumeSaleInfoListPrice (0 custom class methods, 2 custom properties)
//   GTLBooksVolumeSaleInfoRetailPrice (0 custom class methods, 2 custom properties)
//   GTLBooksVolumeVolumeInfoDimensions (0 custom class methods, 3 custom properties)
//   GTLBooksVolumeVolumeInfoImageLinks (0 custom class methods, 6 custom properties)
//   GTLBooksVolumeVolumeInfoIndustryIdentifiersItem (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBooksDownloadAccessRestriction;
@class GTLBooksReadingPosition;
@class GTLBooksReview;
@class GTLBooksVolumeAccessInfo;
@class GTLBooksVolumeAccessInfoEpub;
@class GTLBooksVolumeAccessInfoPdf;
@class GTLBooksVolumeSaleInfo;
@class GTLBooksVolumeSaleInfoListPrice;
@class GTLBooksVolumeSaleInfoRetailPrice;
@class GTLBooksVolumeSearchInfo;
@class GTLBooksVolumeUserInfo;
@class GTLBooksVolumeVolumeInfo;
@class GTLBooksVolumeVolumeInfoDimensions;
@class GTLBooksVolumeVolumeInfoImageLinks;
@class GTLBooksVolumeVolumeInfoIndustryIdentifiersItem;

// ----------------------------------------------------------------------------
//
//   GTLBooksVolume
//

@interface GTLBooksVolume : GTLObject

// Any information about a volume related to reading or obtaining that volume
// text. This information can depend on country (books may be public domain in
// one country but not in another, e.g.).
@property (retain) GTLBooksVolumeAccessInfo *accessInfo;

// Opaque identifier for a specific version of a volume resource. (In LITE
// projection)
@property (copy) NSString *ETag;

// Unique identifier for a volume. (In LITE projection.)
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Resource type for a volume. (In LITE projection.)
@property (copy) NSString *kind;

// Any information about a volume related to the eBookstore and/or
// purchaseability. This information can depend on the country where the request
// originates from (i.e. books may not be for sale in certain countries).
@property (retain) GTLBooksVolumeSaleInfo *saleInfo;

// Search result information related to this volume.
@property (retain) GTLBooksVolumeSearchInfo *searchInfo;

// URL to this resource. (In LITE projection.)
@property (copy) NSString *selfLink;

// User specific information related to this volume. (e.g. page this user last
// read or whether they purchased this book)
@property (retain) GTLBooksVolumeUserInfo *userInfo;

// General volume information.
@property (retain) GTLBooksVolumeVolumeInfo *volumeInfo;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksVolumeAccessInfo
//

@interface GTLBooksVolumeAccessInfo : GTLObject

// Combines the access and viewability of this volume into a single status field
// for this user. Values can be FULL_PURCHASED, FULL_PUBLIC_DOMAIN, SAMPLE or
// NONE. (In LITE projection.)
@property (copy) NSString *accessViewStatus;

// The two-letter ISO_3166-1 country code for which this access information is
// valid. (In LITE projection.)
@property (copy) NSString *country;

// Information about a volume's download license access restrictions.
@property (retain) GTLBooksDownloadAccessRestriction *downloadAccess;

// Whether this volume can be embedded in a viewport using the Embedded Viewer
// API.
@property (retain) NSNumber *embeddable;  // boolValue

// Information about epub content. (In LITE projection.)
@property (retain) GTLBooksVolumeAccessInfoEpub *epub;

// Information about pdf content. (In LITE projection.)
@property (retain) GTLBooksVolumeAccessInfoPdf *pdf;

// Whether or not this book is public domain in the country listed above.
@property (retain) NSNumber *publicDomain;  // boolValue

// Whether text-to-speech is permitted for this volume. Values can be ALLOWED,
// ALLOWED_FOR_ACCESSIBILITY, or NOT_ALLOWED.
@property (copy) NSString *textToSpeechPermission;

// The read access of a volume. Possible values are PARTIAL, ALL_PAGES, NO_PAGES
// or UNKNOWN. This value depends on the country listed above. A value of
// PARTIAL means that the publisher has allowed some portion of the volume to be
// viewed publicly, without purchase. This can apply to eBooks as well as
// non-eBooks. Public domain books will always have a value of ALL_PAGES.
@property (copy) NSString *viewability;

// For ordered but not yet processed orders, we give a URL that can be used to
// go to the appropriate Google Wallet page.
@property (copy) NSString *viewOrderUrl;

// URL to read this volume on the Google Books site. Link will not allow users
// to read non-viewable volumes.
@property (copy) NSString *webReaderLink;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksVolumeSaleInfo
//

@interface GTLBooksVolumeSaleInfo : GTLObject

// URL to purchase this volume on the Google Books site. (In LITE projection)
@property (copy) NSString *buyLink;

// The two-letter ISO_3166-1 country code for which this sale information is
// valid. (In LITE projection.)
@property (copy) NSString *country;

// Whether or not this volume is an eBook (can be added to the My eBooks shelf).
@property (retain) NSNumber *isEbook;  // boolValue

// Suggested retail price. (In LITE projection.)
@property (retain) GTLBooksVolumeSaleInfoListPrice *listPrice;

// The date on which this book is available for sale.
@property (retain) GTLDateTime *onSaleDate;

// The actual selling price of the book. This is the same as the suggested
// retail or list price unless there are offers or discounts on this volume. (In
// LITE projection.)
@property (retain) GTLBooksVolumeSaleInfoRetailPrice *retailPrice;

// Whether or not this book is available for sale or offered for free in the
// Google eBookstore for the country listed above. Possible values are FOR_SALE,
// FREE, NOT_FOR_SALE, or FOR_PREORDER.
@property (copy) NSString *saleability;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksVolumeSearchInfo
//

@interface GTLBooksVolumeSearchInfo : GTLObject

// A text snippet containing the search query.
@property (copy) NSString *textSnippet;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksVolumeUserInfo
//

@interface GTLBooksVolumeUserInfo : GTLObject

// Whether or not this volume is currently in "my books."
@property (retain) NSNumber *isInMyBooks;  // boolValue

// Whether or not this volume was pre-ordered by the authenticated user making
// the request. (In LITE projection.)
@property (retain) NSNumber *isPreordered;  // boolValue

// Whether or not this volume was purchased by the authenticated user making the
// request. (In LITE projection.)
@property (retain) NSNumber *isPurchased;  // boolValue

// The user's current reading position in the volume, if one is available. (In
// LITE projection.)
@property (retain) GTLBooksReadingPosition *readingPosition;

// This user's review of this volume, if one exists.
@property (retain) GTLBooksReview *review;

// Timestamp when this volume was last modified by a user action, such as a
// reading position update, volume purchase or writing a review. (RFC 3339 UTC
// date-time format).
@property (retain) GTLDateTime *updated;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksVolumeVolumeInfo
//

@interface GTLBooksVolumeVolumeInfo : GTLObject

// The names of the authors and/or editors for this volume. (In LITE projection)
@property (retain) NSArray *authors;  // of NSString

// The mean review rating for this volume. (min = 1.0, max = 5.0)
@property (retain) NSNumber *averageRating;  // doubleValue

// Canonical URL for a volume. (In LITE projection.)
@property (copy) NSString *canonicalVolumeLink;

// A list of subject categories, such as "Fiction", "Suspense", etc.
@property (retain) NSArray *categories;  // of NSString

// An identifier for the version of the volume content (text & images). (In LITE
// projection)
@property (copy) NSString *contentVersion;

// A synopsis of the volume. The text of the description is formatted in HTML
// and includes simple formatting elements, such as b, i, and br tags. (In LITE
// projection.)
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Physical dimensions of this volume.
@property (retain) GTLBooksVolumeVolumeInfoDimensions *dimensions;

// A list of image links for all the sizes that are available. (In LITE
// projection.)
@property (retain) GTLBooksVolumeVolumeInfoImageLinks *imageLinks;

// Industry standard identifiers for this volume.
@property (retain) NSArray *industryIdentifiers;  // of GTLBooksVolumeVolumeInfoIndustryIdentifiersItem

// URL to view information about this volume on the Google Books site. (In LITE
// projection)
@property (copy) NSString *infoLink;

// Best language for this volume (based on content). It is the two-letter ISO
// 639-1 code such as 'fr', 'en', etc.
@property (copy) NSString *language;

// The main category to which this volume belongs. It will be the category from
// the categories list returned below that has the highest weight.
@property (copy) NSString *mainCategory;

// Total number of pages.
@property (retain) NSNumber *pageCount;  // intValue

// URL to preview this volume on the Google Books site.
@property (copy) NSString *previewLink;

// Type of publication of this volume. Possible values are BOOK or MAGAZINE.
@property (copy) NSString *printType;

// Date of publication. (In LITE projection.)
@property (copy) NSString *publishedDate;

// Publisher of this volume. (In LITE projection.)
@property (copy) NSString *publisher;

// The number of review ratings for this volume.
@property (retain) NSNumber *ratingsCount;  // intValue

// Volume subtitle. (In LITE projection.)
@property (copy) NSString *subtitle;

// Volume title. (In LITE projection.)
@property (copy) NSString *title;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksVolumeAccessInfoEpub
//

@interface GTLBooksVolumeAccessInfoEpub : GTLObject

// URL to retrieve ACS token for epub download. (In LITE projection.)
@property (copy) NSString *acsTokenLink;

// URL to download epub. (In LITE projection.)
@property (copy) NSString *downloadLink;

// Is a flowing text epub available either as public domain or for purchase. (In
// LITE projection.)
@property (retain) NSNumber *isAvailable;  // boolValue

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksVolumeAccessInfoPdf
//

@interface GTLBooksVolumeAccessInfoPdf : GTLObject

// URL to retrieve ACS token for pdf download. (In LITE projection.)
@property (copy) NSString *acsTokenLink;

// URL to download pdf. (In LITE projection.)
@property (copy) NSString *downloadLink;

// Is a scanned image pdf available either as public domain or for purchase. (In
// LITE projection.)
@property (retain) NSNumber *isAvailable;  // boolValue

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksVolumeSaleInfoListPrice
//

@interface GTLBooksVolumeSaleInfoListPrice : GTLObject

// Amount in the currency listed below. (In LITE projection.)
@property (retain) NSNumber *amount;  // doubleValue

// An ISO 4217, three-letter currency code. (In LITE projection.)
@property (copy) NSString *currencyCode;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksVolumeSaleInfoRetailPrice
//

@interface GTLBooksVolumeSaleInfoRetailPrice : GTLObject

// Amount in the currency listed below. (In LITE projection.)
@property (retain) NSNumber *amount;  // doubleValue

// An ISO 4217, three-letter currency code. (In LITE projection.)
@property (copy) NSString *currencyCode;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksVolumeVolumeInfoDimensions
//

@interface GTLBooksVolumeVolumeInfoDimensions : GTLObject

// Height or length of this volume (in cm).
@property (copy) NSString *height;

// Thickness of this volume (in cm).
@property (copy) NSString *thickness;

// Width of this volume (in cm).
@property (copy) NSString *width;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksVolumeVolumeInfoImageLinks
//

@interface GTLBooksVolumeVolumeInfoImageLinks : GTLObject

// Image link for extra large size (width of ~1280 pixels). (In LITE projection)
@property (copy) NSString *extraLarge;

// Image link for large size (width of ~800 pixels). (In LITE projection)
@property (copy) NSString *large;

// Image link for medium size (width of ~575 pixels). (In LITE projection)
@property (copy) NSString *medium;

// Image link for small size (width of ~300 pixels). (In LITE projection)
@property (copy) NSString *small;

// Image link for small thumbnail size (width of ~80 pixels). (In LITE
// projection)
@property (copy) NSString *smallThumbnail;

// Image link for thumbnail size (width of ~128 pixels). (In LITE projection)
@property (copy) NSString *thumbnail;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksVolumeVolumeInfoIndustryIdentifiersItem
//

@interface GTLBooksVolumeVolumeInfoIndustryIdentifiersItem : GTLObject

// Industry specific volume identifier.
// identifierProperty property maps to 'identifier' in the JSON ('identifier' is
// reserved for remapping 'id').
@property (copy) NSString *identifierProperty;

// Identifier type. Possible values are ISBN_10, ISBN_13, ISSN and OTHER.
@property (copy) NSString *type;

@end
