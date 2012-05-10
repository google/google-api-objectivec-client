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
//  GTLBooksLayerGeoData.m
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
//   GTLBooksLayerGeoData (0 custom class methods, 2 custom properties)
//   GTLBooksLayerGeoDataCommon (0 custom class methods, 4 custom properties)
//   GTLBooksLayerGeoDataGeo (0 custom class methods, 9 custom properties)
//   GTLBooksLayerGeoDataGeoBoundaryItem (0 custom class methods, 2 custom properties)
//   GTLBooksLayerGeoDataGeoViewport (0 custom class methods, 2 custom properties)
//   GTLBooksLayerGeoDataGeoViewportHi (0 custom class methods, 2 custom properties)
//   GTLBooksLayerGeoDataGeoViewportLo (0 custom class methods, 2 custom properties)

#import "GTLBooksLayerGeoData.h"

// ----------------------------------------------------------------------------
//
//   GTLBooksLayerGeoData
//

@implementation GTLBooksLayerGeoData
@dynamic common, geo;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerGeoDataCommon
//

@implementation GTLBooksLayerGeoDataCommon
@dynamic lang, previewImageUrl, snippet, snippetUrl;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerGeoDataGeo
//

@implementation GTLBooksLayerGeoDataGeo
@dynamic boundary, cachePolicy, countryCode, latitude, longitude, mapType,
         resolution, viewport, zoom;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLBooksLayerGeoDataGeoBoundaryItem class]
                                forKey:@"boundary"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerGeoDataGeoBoundaryItem
//

@implementation GTLBooksLayerGeoDataGeoBoundaryItem
@dynamic latitude, longitude;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerGeoDataGeoViewport
//

@implementation GTLBooksLayerGeoDataGeoViewport
@dynamic hi, lo;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerGeoDataGeoViewportHi
//

@implementation GTLBooksLayerGeoDataGeoViewportHi
@dynamic latitude, longitude;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerGeoDataGeoViewportLo
//

@implementation GTLBooksLayerGeoDataGeoViewportLo
@dynamic latitude, longitude;
@end
