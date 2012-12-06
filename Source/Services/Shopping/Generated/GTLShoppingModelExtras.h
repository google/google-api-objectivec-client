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
//  GTLShoppingModelExtras.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Search API For Shopping (shopping/v1)
// Description:
//   Lets you search over product data.
// Documentation:
//   https://developers.google.com/shopping-search/v1/getting_started
// Classes:
//   GTLShoppingModelExtras (0 custom class methods, 2 custom properties)
//   GTLShoppingModelExtrasFacetRulesItem (0 custom class methods, 1 custom properties)
//   GTLShoppingModelExtrasRankingRulesItem (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLShoppingModelExtrasFacetRulesItem;
@class GTLShoppingModelExtrasRankingRulesItem;

// ----------------------------------------------------------------------------
//
//   GTLShoppingModelExtras
//

@interface GTLShoppingModelExtras : GTLObject
@property (retain) NSArray *facetRules;  // of GTLShoppingModelExtrasFacetRulesItem

// Names of boost (ranking) rules applicable to this search.
@property (retain) NSArray *rankingRules;  // of GTLShoppingModelExtrasRankingRulesItem

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelExtrasFacetRulesItem
//

@interface GTLShoppingModelExtrasFacetRulesItem : GTLObject
@property (copy) NSString *name;
@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelExtrasRankingRulesItem
//

@interface GTLShoppingModelExtrasRankingRulesItem : GTLObject
@property (copy) NSString *name;
@end
