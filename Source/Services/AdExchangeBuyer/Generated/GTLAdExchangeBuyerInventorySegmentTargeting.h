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
//  GTLAdExchangeBuyerInventorySegmentTargeting.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerAdSize;
@class GTLAdExchangeBuyerRuleKeyValuePair;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerInventorySegmentTargeting
//

@interface GTLAdExchangeBuyerInventorySegmentTargeting : GTLObject
@property (nonatomic, retain) NSArray *negativeAdSizes;  // of GTLAdExchangeBuyerAdSize
@property (nonatomic, retain) NSArray *negativeAdTypeSegments;  // of NSString
@property (nonatomic, retain) NSArray *negativeAudienceSegments;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *negativeDeviceCategories;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *negativeIcmBrands;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *negativeIcmInterests;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *negativeInventorySlots;  // of NSString
@property (nonatomic, retain) NSArray *negativeKeyValues;  // of GTLAdExchangeBuyerRuleKeyValuePair
@property (nonatomic, retain) NSArray *negativeLocations;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *negativeMobileApps;  // of NSString
@property (nonatomic, retain) NSArray *negativeOperatingSystems;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *negativeOperatingSystemVersions;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *negativeSiteUrls;  // of NSString
@property (nonatomic, retain) NSArray *negativeSizes;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *negativeVideoAdPositionSegments;  // of NSString
@property (nonatomic, retain) NSArray *negativeVideoDurationSegments;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *negativeXfpAdSlots;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *negativeXfpPlacements;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *positiveAdSizes;  // of GTLAdExchangeBuyerAdSize
@property (nonatomic, retain) NSArray *positiveAdTypeSegments;  // of NSString
@property (nonatomic, retain) NSArray *positiveAudienceSegments;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *positiveDeviceCategories;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *positiveIcmBrands;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *positiveIcmInterests;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *positiveInventorySlots;  // of NSString
@property (nonatomic, retain) NSArray *positiveKeyValues;  // of GTLAdExchangeBuyerRuleKeyValuePair
@property (nonatomic, retain) NSArray *positiveLocations;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *positiveMobileApps;  // of NSString
@property (nonatomic, retain) NSArray *positiveOperatingSystems;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *positiveOperatingSystemVersions;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *positiveSiteUrls;  // of NSString
@property (nonatomic, retain) NSArray *positiveSizes;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *positiveVideoAdPositionSegments;  // of NSString
@property (nonatomic, retain) NSArray *positiveVideoDurationSegments;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *positiveXfpAdSlots;  // of NSNumber (longLongValue)
@property (nonatomic, retain) NSArray *positiveXfpPlacements;  // of NSNumber (longLongValue)
@end
