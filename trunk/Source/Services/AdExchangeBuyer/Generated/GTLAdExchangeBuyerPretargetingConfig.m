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
//  GTLAdExchangeBuyerPretargetingConfig.m
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
//   GTLAdExchangeBuyerPretargetingConfig (0 custom class methods, 23 custom properties)
//   GTLAdExchangeBuyerPretargetingConfigDimensionsItem (0 custom class methods, 2 custom properties)
//   GTLAdExchangeBuyerPretargetingConfigExcludedPlacementsItem (0 custom class methods, 2 custom properties)
//   GTLAdExchangeBuyerPretargetingConfigPlacementsItem (0 custom class methods, 2 custom properties)

#import "GTLAdExchangeBuyerPretargetingConfig.h"

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerPretargetingConfig
//

@implementation GTLAdExchangeBuyerPretargetingConfig
@dynamic billingId, configId, configName, creativeType, dimensions,
         excludedContentLabels, excludedGeoCriteriaIds, excludedPlacements,
         excludedUserLists, excludedVerticals, geoCriteriaIds, isActive, kind,
         languages, mobileCarriers, mobileDevices,
         mobileOperatingSystemVersions, placements, platforms,
         supportedCreativeAttributes, userLists, vendorTypes, verticals;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"creativeType" : [NSString class],
    @"dimensions" : [GTLAdExchangeBuyerPretargetingConfigDimensionsItem class],
    @"excludedContentLabels" : [NSNumber class],
    @"excludedGeoCriteriaIds" : [NSNumber class],
    @"excludedPlacements" : [GTLAdExchangeBuyerPretargetingConfigExcludedPlacementsItem class],
    @"excludedUserLists" : [NSNumber class],
    @"excludedVerticals" : [NSNumber class],
    @"geoCriteriaIds" : [NSNumber class],
    @"languages" : [NSString class],
    @"mobileCarriers" : [NSNumber class],
    @"mobileDevices" : [NSNumber class],
    @"mobileOperatingSystemVersions" : [NSNumber class],
    @"placements" : [GTLAdExchangeBuyerPretargetingConfigPlacementsItem class],
    @"platforms" : [NSString class],
    @"supportedCreativeAttributes" : [NSNumber class],
    @"userLists" : [NSNumber class],
    @"vendorTypes" : [NSNumber class],
    @"verticals" : [NSNumber class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"adexchangebuyer#pretargetingConfig"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerPretargetingConfigDimensionsItem
//

@implementation GTLAdExchangeBuyerPretargetingConfigDimensionsItem
@dynamic height, width;
@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerPretargetingConfigExcludedPlacementsItem
//

@implementation GTLAdExchangeBuyerPretargetingConfigExcludedPlacementsItem
@dynamic token, type;
@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerPretargetingConfigPlacementsItem
//

@implementation GTLAdExchangeBuyerPretargetingConfigPlacementsItem
@dynamic token, type;
@end
