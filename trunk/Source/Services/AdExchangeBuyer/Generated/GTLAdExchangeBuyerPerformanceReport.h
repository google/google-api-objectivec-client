/* Copyright (c) 2014 Google Inc.
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
//  GTLAdExchangeBuyerPerformanceReport.h
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
//   GTLAdExchangeBuyerPerformanceReport (0 custom class methods, 16 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerPerformanceReport
//

// The configuration data for an Ad Exchange performance report list.

@interface GTLAdExchangeBuyerPerformanceReport : GTLObject

// Rate of various prefiltering statuses per match. Please refer to the
// callout-status-codes.txt file for different statuses.
@property (retain) NSArray *calloutStatusRate;  // of any JSON type

// Average QPS for cookie matcher operations.
@property (retain) NSArray *cookieMatcherStatusRate;  // of any JSON type

// Rate of ads with a given status. Please refer to the
// creative-status-codes.txt file for different statuses.
@property (retain) NSArray *creativeStatusRate;  // of any JSON type

// Average QPS for hosted match operations.
@property (retain) NSArray *hostedMatchStatusRate;  // of any JSON type

// Resource type.
@property (copy) NSString *kind;

// The 50th percentile round trip latency(ms) as perceived from Google servers
// for the duration period covered by the report.
@property (retain) NSNumber *latency50thPercentile;  // doubleValue

// The 85th percentile round trip latency(ms) as perceived from Google servers
// for the duration period covered by the report.
@property (retain) NSNumber *latency85thPercentile;  // doubleValue

// The 95th percentile round trip latency(ms) as perceived from Google servers
// for the duration period covered by the report.
@property (retain) NSNumber *latency95thPercentile;  // doubleValue

// Rate of various quota account statuses per quota check.
@property (retain) NSNumber *noQuotaInRegion;  // doubleValue

// Rate of various quota account statuses per quota check.
@property (retain) NSNumber *outOfQuota;  // doubleValue

// Average QPS for pixel match requests from clients.
@property (retain) NSNumber *pixelMatchRequests;  // doubleValue

// Average QPS for pixel match responses from clients.
@property (retain) NSNumber *pixelMatchResponses;  // doubleValue

// The configured quota limits for this account.
@property (retain) NSNumber *quotaConfiguredLimit;  // doubleValue

// The throttled quota limits for this account.
@property (retain) NSNumber *quotaThrottledLimit;  // doubleValue

// The trading location of this data.
@property (copy) NSString *region;

// The unix timestamp of the starting time of this performance data.
@property (retain) NSNumber *timestamp;  // longLongValue

@end
