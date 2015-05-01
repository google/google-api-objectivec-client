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
//   Ad Exchange Buyer API (adexchangebuyer/v1.3)
// Description:
//   Accesses your bidding-account information, submits creatives for
//   validation, finds available direct deals, and retrieves performance
//   reports.
// Documentation:
//   https://developers.google.com/ad-exchange/buyer-rest
// Classes:
//   GTLAdExchangeBuyerCreative (0 custom class methods, 20 custom properties)
//   GTLAdExchangeBuyerCreativeCorrectionsItem (0 custom class methods, 2 custom properties)
//   GTLAdExchangeBuyerCreativeDisapprovalReasonsItem (0 custom class methods, 2 custom properties)
//   GTLAdExchangeBuyerCreativeFilteringReasons (0 custom class methods, 2 custom properties)
//   GTLAdExchangeBuyerCreativeFilteringReasonsReasonsItem (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerCreativeCorrectionsItem;
@class GTLAdExchangeBuyerCreativeDisapprovalReasonsItem;
@class GTLAdExchangeBuyerCreativeFilteringReasons;
@class GTLAdExchangeBuyerCreativeFilteringReasonsReasonsItem;

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

// The reasons for disapproval, if any. Note that not all disapproval reasons
// may be categorized, so it is possible for the creative to have a status of
// DISAPPROVED with an empty list for disapproval_reasons. In this case, please
// reach out to your TAM to help debug the issue. Read-only. This field should
// not be set in requests.
@property (nonatomic, retain) NSArray *disapprovalReasons;  // of GTLAdExchangeBuyerCreativeDisapprovalReasonsItem

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

// Detected product categories, if any. Read-only. This field should not be set
// in requests.
@property (nonatomic, retain) NSArray *productCategories;  // of NSNumber (intValue)

// All restricted categories for the ads that may be shown from this snippet.
@property (nonatomic, retain) NSArray *restrictedCategories;  // of NSNumber (intValue)

// Detected sensitive categories, if any. Read-only. This field should not be
// set in requests.
@property (nonatomic, retain) NSArray *sensitiveCategories;  // of NSNumber (intValue)

// Creative serving status. Read-only. This field should not be set in requests.
@property (nonatomic, copy) NSString *status;

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
//   GTLAdExchangeBuyerCreativeDisapprovalReasonsItem
//

@interface GTLAdExchangeBuyerCreativeDisapprovalReasonsItem : GTLObject

// Additional details about the reason for disapproval.
@property (nonatomic, retain) NSArray *details;  // of NSString

// The categorized reason for disapproval.
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
