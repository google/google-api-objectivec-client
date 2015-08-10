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
//  GTLAdExchangeBuyerCreative.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerCreativeCorrectionsItem;
@class GTLAdExchangeBuyerCreativeFilteringReasons;
@class GTLAdExchangeBuyerCreativeFilteringReasonsReasonsItem;
@class GTLAdExchangeBuyerCreativeServingRestrictionsItem;
@class GTLAdExchangeBuyerCreativeServingRestrictionsItemContextsItem;
@class GTLAdExchangeBuyerCreativeServingRestrictionsItemDisapprovalReasonsItem;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerCreative
//

// A creative and its classification data.

@interface GTLAdExchangeBuyerCreative : GTLObject

// Account id.
@property (nonatomic, retain) NSNumber *accountId;  // intValue

// Detected advertiser id, if any. Read-only. This field should not be set in
// requests.
@property (nonatomic, retain) NSArray *advertiserId;  // of NSNumber (longLongValue)

// The name of the company being advertised in the creative.
@property (nonatomic, copy) NSString *advertiserName;

// The agency id for this creative.
@property (nonatomic, retain) NSNumber *agencyId;  // longLongValue

// All attributes for the ads that may be shown from this snippet.
@property (nonatomic, retain) NSArray *attribute;  // of NSNumber (intValue)

// A buyer-specific id identifying the creative in this ad.
@property (nonatomic, copy) NSString *buyerCreativeId;

// The set of destination urls for the snippet.
@property (nonatomic, retain) NSArray *clickThroughUrl;  // of NSString

// Shows any corrections that were applied to this creative. Read-only. This
// field should not be set in requests.
@property (nonatomic, retain) NSArray *corrections;  // of GTLAdExchangeBuyerCreativeCorrectionsItem

// Top-level deals status. Read-only. This field should not be set in requests.
// If disapproved, an entry for auctionType=DIRECT_DEALS (or ALL) in
// servingRestrictions will also exist. Note that this may be nuanced with other
// contextual restrictions, in which case it may be preferable to read from
// servingRestrictions directly.
@property (nonatomic, copy) NSString *dealsStatus;

// The filtering reasons for the creative. Read-only. This field should not be
// set in requests.
@property (nonatomic, retain) GTLAdExchangeBuyerCreativeFilteringReasons *filteringReasons;

// Ad height.
@property (nonatomic, retain) NSNumber *height;  // intValue

// The HTML snippet that displays the ad when inserted in the web page. If set,
// videoURL should not be set.
@property (nonatomic, copy) NSString *HTMLSnippet;

// Resource type.
@property (nonatomic, copy) NSString *kind;

// Top-level open auction status. Read-only. This field should not be set in
// requests. If disapproved, an entry for auctionType=OPEN_AUCTION (or ALL) in
// servingRestrictions will also exist. Note that this may be nuanced with other
// contextual restrictions, in which case it may be preferable to read from
// ServingRestrictions directly.
@property (nonatomic, copy) NSString *openAuctionStatus;

// Detected product categories, if any. Read-only. This field should not be set
// in requests.
@property (nonatomic, retain) NSArray *productCategories;  // of NSNumber (intValue)

// All restricted categories for the ads that may be shown from this snippet.
@property (nonatomic, retain) NSArray *restrictedCategories;  // of NSNumber (intValue)

// Detected sensitive categories, if any. Read-only. This field should not be
// set in requests.
@property (nonatomic, retain) NSArray *sensitiveCategories;  // of NSNumber (intValue)

// The granular status of this ad in specific contexts. A context here relates
// to where something ultimately serves (for example, a physical location, a
// platform, an HTTPS vs HTTP request, or the type of auction). Read-only. This
// field should not be set in requests.
@property (nonatomic, retain) NSArray *servingRestrictions;  // of GTLAdExchangeBuyerCreativeServingRestrictionsItem

// All vendor types for the ads that may be shown from this snippet.
@property (nonatomic, retain) NSArray *vendorType;  // of NSNumber (intValue)

// The url to fetch a video ad. If set, HTMLSnippet should not be set.
@property (nonatomic, copy) NSString *videoURL;

// Ad width.
@property (nonatomic, retain) NSNumber *width;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerCreativeCorrectionsItem
//

@interface GTLAdExchangeBuyerCreativeCorrectionsItem : GTLObject

// Additional details about the correction.
@property (nonatomic, retain) NSArray *details;  // of NSString

// The type of correction that was applied to the creative.
@property (nonatomic, copy) NSString *reason;

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerCreativeFilteringReasons
//

@interface GTLAdExchangeBuyerCreativeFilteringReasons : GTLObject

// The date in ISO 8601 format for the data. The data is collected from 00:00:00
// to 23:59:59 in PST.
@property (nonatomic, copy) NSString *date;

// The filtering reasons.
@property (nonatomic, retain) NSArray *reasons;  // of GTLAdExchangeBuyerCreativeFilteringReasonsReasonsItem

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerCreativeServingRestrictionsItem
//

@interface GTLAdExchangeBuyerCreativeServingRestrictionsItem : GTLObject

// All known contexts/restrictions.
@property (nonatomic, retain) NSArray *contexts;  // of GTLAdExchangeBuyerCreativeServingRestrictionsItemContextsItem

// The reasons for disapproval within this restriction, if any. Note that not
// all disapproval reasons may be categorized, so it is possible for the
// creative to have a status of DISAPPROVED or CONDITIONALLY_APPROVED with an
// empty list for disapproval_reasons. In this case, please reach out to your
// TAM to help debug the issue.
@property (nonatomic, retain) NSArray *disapprovalReasons;  // of GTLAdExchangeBuyerCreativeServingRestrictionsItemDisapprovalReasonsItem

// Why the creative is ineligible to serve in this context (e.g., it has been
// explicitly disapproved or is pending review).
@property (nonatomic, copy) NSString *reason;

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerCreativeFilteringReasonsReasonsItem
//

@interface GTLAdExchangeBuyerCreativeFilteringReasonsReasonsItem : GTLObject

// The number of times the creative was filtered for the status. The count is
// aggregated across all publishers on the exchange.
@property (nonatomic, retain) NSNumber *filteringCount;  // longLongValue

// The filtering status code. Please refer to the creative-status-codes.txt file
// for different statuses.
@property (nonatomic, retain) NSNumber *filteringStatus;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerCreativeServingRestrictionsItemContextsItem
//

@interface GTLAdExchangeBuyerCreativeServingRestrictionsItemContextsItem : GTLObject

// Only set when contextType=AUCTION_TYPE. Represents the auction types this
// restriction applies to.
@property (nonatomic, retain) NSArray *auctionType;  // of NSString

// The type of context (e.g., location, platform, auction type, SSL-ness).
@property (nonatomic, copy) NSString *contextType;

// Only set when contextType=LOCATION. Represents the geo criterias this
// restriction applies to.
@property (nonatomic, retain) NSArray *geoCriteriaId;  // of NSNumber (intValue)

// Only set when contextType=PLATFORM. Represents the platforms this restriction
// applies to.
@property (nonatomic, retain) NSArray *platform;  // of NSString

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerCreativeServingRestrictionsItemDisapprovalReasonsItem
//

@interface GTLAdExchangeBuyerCreativeServingRestrictionsItemDisapprovalReasonsItem : GTLObject

// Additional details about the reason for disapproval.
@property (nonatomic, retain) NSArray *details;  // of NSString

// The categorized reason for disapproval.
@property (nonatomic, copy) NSString *reason;

@end
