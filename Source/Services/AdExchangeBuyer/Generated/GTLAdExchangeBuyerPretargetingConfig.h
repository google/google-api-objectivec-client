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
//  GTLAdExchangeBuyerPretargetingConfig.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Ad Exchange Buyer API (adexchangebuyer/v1.3)
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerPretargetingConfigDimensionsItem;
@class GTLAdExchangeBuyerPretargetingConfigExcludedPlacementsItem;
@class GTLAdExchangeBuyerPretargetingConfigPlacementsItem;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerPretargetingConfig
//

@interface GTLAdExchangeBuyerPretargetingConfig : GTLObject

// The id for billing purposes, provided for reference. Leave this field blank
// for insert requests; the id will be generated automatically.
@property (nonatomic, retain) NSNumber *billingId;  // longLongValue

// The config id; generated automatically. Leave this field blank for insert
// requests.
@property (nonatomic, retain) NSNumber *configId;  // longLongValue

// The name of the config. Must be unique. Required for all requests.
@property (nonatomic, copy) NSString *configName;

// List must contain exactly one of PRETARGETING_CREATIVE_TYPE_HTML or
// PRETARGETING_CREATIVE_TYPE_VIDEO.
@property (nonatomic, retain) NSArray *creativeType;  // of NSString

// Requests which allow one of these (width, height) pairs will match. All pairs
// must be supported ad dimensions.
@property (nonatomic, retain) NSArray *dimensions;  // of GTLAdExchangeBuyerPretargetingConfigDimensionsItem

// Requests with any of these content labels will not match. Values are from
// content-labels.txt in the downloadable files section.
@property (nonatomic, retain) NSArray *excludedContentLabels;  // of NSNumber (longLongValue)

// Requests containing any of these geo criteria ids will not match.
@property (nonatomic, retain) NSArray *excludedGeoCriteriaIds;  // of NSNumber (longLongValue)

// Requests containing any of these placements will not match.
@property (nonatomic, retain) NSArray *excludedPlacements;  // of GTLAdExchangeBuyerPretargetingConfigExcludedPlacementsItem

// Requests containing any of these users list ids will not match.
@property (nonatomic, retain) NSArray *excludedUserLists;  // of NSNumber (longLongValue)

// Requests containing any of these vertical ids will not match. Values are from
// the publisher-verticals.txt file in the downloadable files section.
@property (nonatomic, retain) NSArray *excludedVerticals;  // of NSNumber (longLongValue)

// Requests containing any of these geo criteria ids will match.
@property (nonatomic, retain) NSArray *geoCriteriaIds;  // of NSNumber (longLongValue)

// Whether this config is active. Required for all requests.
@property (nonatomic, retain) NSNumber *isActive;  // boolValue

// The kind of the resource, i.e. "adexchangebuyer#pretargetingConfig".
@property (nonatomic, copy) NSString *kind;

// Request containing any of these language codes will match.
@property (nonatomic, retain) NSArray *languages;  // of NSString

// Requests containing any of these mobile carrier ids will match. Values are
// from mobile-carriers.csv in the downloadable files section.
@property (nonatomic, retain) NSArray *mobileCarriers;  // of NSNumber (longLongValue)

// Requests containing any of these mobile device ids will match. Values are
// from mobile-devices.csv in the downloadable files section.
@property (nonatomic, retain) NSArray *mobileDevices;  // of NSNumber (longLongValue)

// Requests containing any of these mobile operating system version ids will
// match. Values are from mobile-os.csv in the downloadable files section.
@property (nonatomic, retain) NSArray *mobileOperatingSystemVersions;  // of NSNumber (longLongValue)

// Requests containing any of these placements will match.
@property (nonatomic, retain) NSArray *placements;  // of GTLAdExchangeBuyerPretargetingConfigPlacementsItem

// Requests matching any of these platforms will match. Possible values are
// PRETARGETING_PLATFORM_MOBILE, PRETARGETING_PLATFORM_DESKTOP, and
// PRETARGETING_PLATFORM_TABLET.
@property (nonatomic, retain) NSArray *platforms;  // of NSString

// Creative attributes should be declared here if all creatives corresponding to
// this pretargeting configuration have that creative attribute. Values are from
// pretargetable-creative-attributes.txt in the downloadable files section.
@property (nonatomic, retain) NSArray *supportedCreativeAttributes;  // of NSNumber (longLongValue)

// Requests containing any of these user list ids will match.
@property (nonatomic, retain) NSArray *userLists;  // of NSNumber (longLongValue)

// Requests that allow any of these vendor ids will match. Values are from
// vendors.txt in the downloadable files section.
@property (nonatomic, retain) NSArray *vendorTypes;  // of NSNumber (longLongValue)

// Requests containing any of these vertical ids will match.
@property (nonatomic, retain) NSArray *verticals;  // of NSNumber (longLongValue)

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerPretargetingConfigDimensionsItem
//

@interface GTLAdExchangeBuyerPretargetingConfigDimensionsItem : GTLObject

// Height in pixels.
@property (nonatomic, retain) NSNumber *height;  // longLongValue

// Width in pixels.
@property (nonatomic, retain) NSNumber *width;  // longLongValue

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerPretargetingConfigExcludedPlacementsItem
//

@interface GTLAdExchangeBuyerPretargetingConfigExcludedPlacementsItem : GTLObject

// The value of the placement. Interpretation depends on the placement type,
// e.g. URL for a site placement, channel name for a channel placement, app id
// for a mobile app placement.
@property (nonatomic, copy) NSString *token;

// The type of the placement.
@property (nonatomic, copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerPretargetingConfigPlacementsItem
//

@interface GTLAdExchangeBuyerPretargetingConfigPlacementsItem : GTLObject

// The value of the placement. Interpretation depends on the placement type,
// e.g. URL for a site placement, channel name for a channel placement, app id
// for a mobile app placement.
@property (nonatomic, copy) NSString *token;

// The type of the placement.
@property (nonatomic, copy) NSString *type;

@end
