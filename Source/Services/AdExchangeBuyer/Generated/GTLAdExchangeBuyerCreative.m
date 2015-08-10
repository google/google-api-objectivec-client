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
//  GTLAdExchangeBuyerCreative.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Ad Exchange Buyer API (adexchangebuyer/v1.4)
// Description:
//   Accesses your bidding-account information, submits creatives for
//   validation, finds available direct deals, and retrieves performance
//   reports.
// Documentation:
//   https://developers.google.com/ad-exchange/buyer-rest
// Classes:
//   GTLAdExchangeBuyerCreative (0 custom class methods, 21 custom properties)
//   GTLAdExchangeBuyerCreativeCorrectionsItem (0 custom class methods, 2 custom properties)
//   GTLAdExchangeBuyerCreativeFilteringReasons (0 custom class methods, 2 custom properties)
//   GTLAdExchangeBuyerCreativeServingRestrictionsItem (0 custom class methods, 3 custom properties)
//   GTLAdExchangeBuyerCreativeFilteringReasonsReasonsItem (0 custom class methods, 2 custom properties)
//   GTLAdExchangeBuyerCreativeServingRestrictionsItemContextsItem (0 custom class methods, 4 custom properties)
//   GTLAdExchangeBuyerCreativeServingRestrictionsItemDisapprovalReasonsItem (0 custom class methods, 2 custom properties)

#import "GTLAdExchangeBuyerCreative.h"

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerCreative
//

@implementation GTLAdExchangeBuyerCreative
@dynamic accountId, advertiserId, advertiserName, agencyId, attribute,
         buyerCreativeId, clickThroughUrl, corrections, dealsStatus,
         filteringReasons, height, HTMLSnippet, kind, openAuctionStatus,
         productCategories, restrictedCategories, sensitiveCategories,
         servingRestrictions, vendorType, videoURL, width;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"advertiserId" : [NSNumber class],
    @"attribute" : [NSNumber class],
    @"clickThroughUrl" : [NSString class],
    @"corrections" : [GTLAdExchangeBuyerCreativeCorrectionsItem class],
    @"productCategories" : [NSNumber class],
    @"restrictedCategories" : [NSNumber class],
    @"sensitiveCategories" : [NSNumber class],
    @"servingRestrictions" : [GTLAdExchangeBuyerCreativeServingRestrictionsItem class],
    @"vendorType" : [NSNumber class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"adexchangebuyer#creative"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerCreativeCorrectionsItem
//

@implementation GTLAdExchangeBuyerCreativeCorrectionsItem
@dynamic details, reason;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"details" : [NSString class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerCreativeFilteringReasons
//

@implementation GTLAdExchangeBuyerCreativeFilteringReasons
@dynamic date, reasons;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"reasons" : [GTLAdExchangeBuyerCreativeFilteringReasonsReasonsItem class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerCreativeServingRestrictionsItem
//

@implementation GTLAdExchangeBuyerCreativeServingRestrictionsItem
@dynamic contexts, disapprovalReasons, reason;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"contexts" : [GTLAdExchangeBuyerCreativeServingRestrictionsItemContextsItem class],
    @"disapprovalReasons" : [GTLAdExchangeBuyerCreativeServingRestrictionsItemDisapprovalReasonsItem class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerCreativeFilteringReasonsReasonsItem
//

@implementation GTLAdExchangeBuyerCreativeFilteringReasonsReasonsItem
@dynamic filteringCount, filteringStatus;
@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerCreativeServingRestrictionsItemContextsItem
//

@implementation GTLAdExchangeBuyerCreativeServingRestrictionsItemContextsItem
@dynamic auctionType, contextType, geoCriteriaId, platform;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"auctionType" : [NSString class],
    @"geoCriteriaId" : [NSNumber class],
    @"platform" : [NSString class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerCreativeServingRestrictionsItemDisapprovalReasonsItem
//

@implementation GTLAdExchangeBuyerCreativeServingRestrictionsItemDisapprovalReasonsItem
@dynamic details, reason;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"details" : [NSString class]
  };
  return map;
}

@end
