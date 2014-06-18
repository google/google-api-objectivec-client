/* Copyright (c) 2014 Google Inc.
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
//  GTLPlusDomainsPlace.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google+ Domains API (plusDomains/v1)
// Description:
//   The Google+ API enables developers to build on top of the Google+ platform.
// Documentation:
//   https://developers.google.com/+/domains/
// Classes:
//   GTLPlusDomainsPlace (0 custom class methods, 5 custom properties)
//   GTLPlusDomainsPlaceAddress (0 custom class methods, 1 custom properties)
//   GTLPlusDomainsPlacePosition (0 custom class methods, 2 custom properties)

#import "GTLPlusDomainsPlace.h"

// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPlace
//

@implementation GTLPlusDomainsPlace
@dynamic address, displayName, identifier, kind, position;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"plus#place"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPlaceAddress
//

@implementation GTLPlusDomainsPlaceAddress
@dynamic formatted;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsPlacePosition
//

@implementation GTLPlusDomainsPlacePosition
@dynamic latitude, longitude;
@end
