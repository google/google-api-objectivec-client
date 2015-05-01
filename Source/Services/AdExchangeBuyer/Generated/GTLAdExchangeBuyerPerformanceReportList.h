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
//  GTLAdExchangeBuyerPerformanceReportList.h
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
//   GTLAdExchangeBuyerPerformanceReportList (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeBuyerPerformanceReport;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerPerformanceReportList
//

// The configuration data for an Ad Exchange performance report list.
// https://sites.google.com/a/google.com/adx-integration/Home/engineering/binary-releases/rtb-api-release
// https://cs.corp.google.com/#piper///depot/google3/contentads/adx/tools/rtb_api/adxrtb.py

@interface GTLAdExchangeBuyerPerformanceReportList : GTLObject

// Resource type.
@property (nonatomic, copy) NSString *kind;

// A list of performance reports relevant for the account.
@property (nonatomic, retain) NSArray *performanceReport;  // of GTLAdExchangeBuyerPerformanceReport

@end
