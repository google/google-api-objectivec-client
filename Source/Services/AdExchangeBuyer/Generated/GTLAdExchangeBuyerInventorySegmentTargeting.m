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
//  GTLAdExchangeBuyerInventorySegmentTargeting.m
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
//   GTLAdExchangeBuyerInventorySegmentTargeting (0 custom class methods, 36 custom properties)

#import "GTLAdExchangeBuyerInventorySegmentTargeting.h"

#import "GTLAdExchangeBuyerAdSize.h"
#import "GTLAdExchangeBuyerRuleKeyValuePair.h"

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerInventorySegmentTargeting
//

@implementation GTLAdExchangeBuyerInventorySegmentTargeting
@dynamic negativeAdSizes, negativeAdTypeSegments, negativeAudienceSegments,
         negativeDeviceCategories, negativeIcmBrands, negativeIcmInterests,
         negativeInventorySlots, negativeKeyValues, negativeLocations,
         negativeMobileApps, negativeOperatingSystems,
         negativeOperatingSystemVersions, negativeSiteUrls, negativeSizes,
         negativeVideoAdPositionSegments, negativeVideoDurationSegments,
         negativeXfpAdSlots, negativeXfpPlacements, positiveAdSizes,
         positiveAdTypeSegments, positiveAudienceSegments,
         positiveDeviceCategories, positiveIcmBrands, positiveIcmInterests,
         positiveInventorySlots, positiveKeyValues, positiveLocations,
         positiveMobileApps, positiveOperatingSystems,
         positiveOperatingSystemVersions, positiveSiteUrls, positiveSizes,
         positiveVideoAdPositionSegments, positiveVideoDurationSegments,
         positiveXfpAdSlots, positiveXfpPlacements;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"negativeAdSizes" : [GTLAdExchangeBuyerAdSize class],
    @"negativeAdTypeSegments" : [NSString class],
    @"negativeAudienceSegments" : [NSNumber class],
    @"negativeDeviceCategories" : [NSNumber class],
    @"negativeIcmBrands" : [NSNumber class],
    @"negativeIcmInterests" : [NSNumber class],
    @"negativeInventorySlots" : [NSString class],
    @"negativeKeyValues" : [GTLAdExchangeBuyerRuleKeyValuePair class],
    @"negativeLocations" : [NSNumber class],
    @"negativeMobileApps" : [NSString class],
    @"negativeOperatingSystems" : [NSNumber class],
    @"negativeOperatingSystemVersions" : [NSNumber class],
    @"negativeSiteUrls" : [NSString class],
    @"negativeSizes" : [NSNumber class],
    @"negativeVideoAdPositionSegments" : [NSString class],
    @"negativeVideoDurationSegments" : [NSNumber class],
    @"negativeXfpAdSlots" : [NSNumber class],
    @"negativeXfpPlacements" : [NSNumber class],
    @"positiveAdSizes" : [GTLAdExchangeBuyerAdSize class],
    @"positiveAdTypeSegments" : [NSString class],
    @"positiveAudienceSegments" : [NSNumber class],
    @"positiveDeviceCategories" : [NSNumber class],
    @"positiveIcmBrands" : [NSNumber class],
    @"positiveIcmInterests" : [NSNumber class],
    @"positiveInventorySlots" : [NSString class],
    @"positiveKeyValues" : [GTLAdExchangeBuyerRuleKeyValuePair class],
    @"positiveLocations" : [NSNumber class],
    @"positiveMobileApps" : [NSString class],
    @"positiveOperatingSystems" : [NSNumber class],
    @"positiveOperatingSystemVersions" : [NSNumber class],
    @"positiveSiteUrls" : [NSString class],
    @"positiveSizes" : [NSNumber class],
    @"positiveVideoAdPositionSegments" : [NSString class],
    @"positiveVideoDurationSegments" : [NSNumber class],
    @"positiveXfpAdSlots" : [NSNumber class],
    @"positiveXfpPlacements" : [NSNumber class]
  };
  return map;
}

@end
