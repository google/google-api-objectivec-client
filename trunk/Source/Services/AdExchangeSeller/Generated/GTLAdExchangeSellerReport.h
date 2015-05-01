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
//  GTLAdExchangeSellerReport.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Ad Exchange Seller API (adexchangeseller/v2.0)
// Description:
//   Gives Ad Exchange seller users access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://developers.google.com/ad-exchange/seller-rest/
// Classes:
//   GTLAdExchangeSellerReport (0 custom class methods, 7 custom properties)
//   GTLAdExchangeSellerReportHeadersItem (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdExchangeSellerReportHeadersItem;

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeSellerReport
//

@interface GTLAdExchangeSellerReport : GTLObject

// The averages of the report. This is the same length as any other row in the
// report; cells corresponding to dimension columns are empty.
@property (nonatomic, retain) NSArray *averages;  // of NSString

// The header information of the columns requested in the report. This is a list
// of headers; one for each dimension in the request, followed by one for each
// metric in the request.
@property (nonatomic, retain) NSArray *headers;  // of GTLAdExchangeSellerReportHeadersItem

// Kind this is, in this case adexchangeseller#report.
@property (nonatomic, copy) NSString *kind;

// The output rows of the report. Each row is a list of cells; one for each
// dimension in the request, followed by one for each metric in the request. The
// dimension cells contain strings, and the metric cells contain numbers.
@property (nonatomic, retain) NSArray *rows;  // of NSArray of NSString

// The total number of rows matched by the report request. Fewer rows may be
// returned in the response due to being limited by the row count requested or
// the report row limit.
@property (nonatomic, retain) NSNumber *totalMatchedRows;  // longLongValue

// The totals of the report. This is the same length as any other row in the
// report; cells corresponding to dimension columns are empty.
@property (nonatomic, retain) NSArray *totals;  // of NSString

// Any warnings associated with generation of the report.
@property (nonatomic, retain) NSArray *warnings;  // of NSString

@end


// ----------------------------------------------------------------------------
//
//   GTLAdExchangeSellerReportHeadersItem
//

@interface GTLAdExchangeSellerReportHeadersItem : GTLObject

// The currency of this column. Only present if the header type is
// METRIC_CURRENCY.
@property (nonatomic, copy) NSString *currency;

// The name of the header.
@property (nonatomic, copy) NSString *name;

// The type of the header; one of DIMENSION, METRIC_TALLY, METRIC_RATIO, or
// METRIC_CURRENCY.
@property (nonatomic, copy) NSString *type;

@end
