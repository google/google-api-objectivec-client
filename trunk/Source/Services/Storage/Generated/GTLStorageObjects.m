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
//  GTLStorageObjects.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Cloud Storage API (storage/v1beta1)
// Description:
//   Lets you store and retrieve potentially-large, immutable data objects.
// Documentation:
//   https://code.google.com/apis/storage/docs/developer-guide.html
// Classes:
//   GTLStorageObjects (0 custom class methods, 4 custom properties)

#import "GTLStorageObjects.h"

#import "GTLStorageObject.h"

// ----------------------------------------------------------------------------
//
//   GTLStorageObjects
//

@implementation GTLStorageObjects
@dynamic items, kind, nextPageToken, prefixes;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLStorageObject class], @"items",
      [NSString class], @"prefixes",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"storage#objects"];
}

@end
