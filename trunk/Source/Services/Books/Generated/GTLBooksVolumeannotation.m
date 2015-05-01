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
//  GTLBooksVolumeannotation.m
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
//   GTLBooksVolumeannotation (0 custom class methods, 14 custom properties)
//   GTLBooksVolumeannotationContentRanges (0 custom class methods, 4 custom properties)

#import "GTLBooksVolumeannotation.h"

#import "GTLBooksAnnotationsRange.h"

// ----------------------------------------------------------------------------
//
//   GTLBooksVolumeannotation
//

@implementation GTLBooksVolumeannotation
@dynamic annotationDataId, annotationDataLink, annotationType, contentRanges,
         data, deleted, identifier, kind, layerId, pageIds, selectedText,
         selfLink, updated, volumeId;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"identifier" : @"id"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"pageIds" : [NSString class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"books#volumeannotation"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksVolumeannotationContentRanges
//

@implementation GTLBooksVolumeannotationContentRanges
@dynamic cfiRange, contentVersion, gbImageRange, gbTextRange;
@end
