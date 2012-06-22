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
//  GTLShoppingModelRecommendations.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLShoppingModelProduct;
@class GTLShoppingModelRecommendationsRecommendationListItem;

// ----------------------------------------------------------------------------
//
//   GTLShoppingModelRecommendations
//

@interface GTLShoppingModelRecommendations : GTLObject

// List of recommendations.
@property (retain) NSArray *recommendationList;  // of GTLShoppingModelRecommendationsRecommendationListItem

// Type of recommendation list (for offer-based recommendations, one of: all,
// purchaseToPurchase, visitToVisit, visitToPurchase, relatedItems; for
// category-based recommendations, one of: all, categoryMostVisited,
// categoryBestSeller).
@property (copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelRecommendationsRecommendationListItem
//

@interface GTLShoppingModelRecommendationsRecommendationListItem : GTLObject

// Recommended product.
@property (retain) GTLShoppingModelProduct *product;

@end
