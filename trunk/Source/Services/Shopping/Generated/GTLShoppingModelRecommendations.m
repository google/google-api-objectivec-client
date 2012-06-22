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
//  GTLShoppingModelRecommendations.m
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
//   GTLShoppingModelRecommendations (0 custom class methods, 2 custom properties)
//   GTLShoppingModelRecommendationsRecommendationListItem (0 custom class methods, 1 custom properties)

#import "GTLShoppingModelRecommendations.h"

#import "GTLShoppingModelProduct.h"

// ----------------------------------------------------------------------------
//
//   GTLShoppingModelRecommendations
//

@implementation GTLShoppingModelRecommendations
@dynamic recommendationList, type;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLShoppingModelRecommendationsRecommendationListItem class]
                                forKey:@"recommendationList"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelRecommendationsRecommendationListItem
//

@implementation GTLShoppingModelRecommendationsRecommendationListItem
@dynamic product;
@end
