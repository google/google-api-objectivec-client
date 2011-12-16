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
//  GTLBooksDownloadAccesses.m
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
//   GTLBooksDownloadAccesses (0 custom class methods, 2 custom properties)

#import "GTLBooksDownloadAccesses.h"

#import "GTLBooksDownloadAccessRestriction.h"

// ----------------------------------------------------------------------------
//
//   GTLBooksDownloadAccesses
//

@implementation GTLBooksDownloadAccesses
@dynamic downloadAccessList, kind;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLBooksDownloadAccessRestriction class]
                                forKey:@"downloadAccessList"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"books#downloadAccesses"];
}

@end
