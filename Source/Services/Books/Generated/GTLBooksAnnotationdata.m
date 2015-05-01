/* Copyright (c) 2015 Google Inc.
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
//  GTLBooksAnnotationdata.m
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
//   GTLBooksAnnotationdata (0 custom class methods, 9 custom properties)

#import "GTLBooksAnnotationdata.h"

// ----------------------------------------------------------------------------
//
//   GTLBooksAnnotationdata
//

@implementation GTLBooksAnnotationdata
@dynamic annotationType, data, encodedData, identifier, kind, layerId, selfLink,
         updated, volumeId;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"encodedData" : @"encoded_data",
    @"identifier" : @"id"
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"books#annotationdata"];
}

@end
