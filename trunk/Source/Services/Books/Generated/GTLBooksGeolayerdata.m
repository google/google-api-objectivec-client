/* Copyright (c) 2013 Google Inc.
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
//  GTLBooksGeolayerdata.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Books API (books/v1)
// Description:
//   Lets you search for books and manage your Google Books library.
// Documentation:
//   https://developers.google.com/books/docs/v1/getting_started
// Classes:
//   GTLBooksGeolayerdata (0 custom class methods, 3 custom properties)
//   GTLBooksGeolayerdataCommon (0 custom class methods, 5 custom properties)
//   GTLBooksGeolayerdataGeo (0 custom class methods, 8 custom properties)
//   GTLBooksGeolayerdataGeoBoundaryItem (0 custom class methods, 2 custom properties)
//   GTLBooksGeolayerdataGeoViewport (0 custom class methods, 2 custom properties)
//   GTLBooksGeolayerdataGeoViewportHi (0 custom class methods, 2 custom properties)
//   GTLBooksGeolayerdataGeoViewportLo (0 custom class methods, 2 custom properties)

#import "GTLBooksGeolayerdata.h"

// ----------------------------------------------------------------------------
//
//   GTLBooksGeolayerdata
//

@implementation GTLBooksGeolayerdata
@dynamic common, geo, kind;

+ (void)load {
  [self registerObjectClassForKind:@"books#geolayerdata"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksGeolayerdataCommon
//

@implementation GTLBooksGeolayerdataCommon
@dynamic lang, previewImageUrl, snippet, snippetUrl, title;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksGeolayerdataGeo
//

@implementation GTLBooksGeolayerdataGeo
@dynamic boundary, cachePolicy, countryCode, latitude, longitude, mapType,
         viewport, zoom;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLBooksGeolayerdataGeoBoundaryItem class]
                                forKey:@"boundary"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksGeolayerdataGeoBoundaryItem
//

@implementation GTLBooksGeolayerdataGeoBoundaryItem
@dynamic latitude, longitude;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksGeolayerdataGeoViewport
//

@implementation GTLBooksGeolayerdataGeoViewport
@dynamic hi, lo;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksGeolayerdataGeoViewportHi
//

@implementation GTLBooksGeolayerdataGeoViewportHi
@dynamic latitude, longitude;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksGeolayerdataGeoViewportLo
//

@implementation GTLBooksGeolayerdataGeoViewportLo
@dynamic latitude, longitude;
@end
