/* Copyright (c) 2011 Google Inc.
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
//  GTLAdsenseAdsenseReportsGenerateResponse.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Management API (adsense/v1.1)
// Description:
//   Gives AdSense publishers access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://code.google.com/apis/adsense/management/
// Classes:
//   GTLAdsenseAdsenseReportsGenerateResponse (0 custom class methods, 7 custom properties)
//   GTLAdsenseAdsenseReportsGenerateResponseHeadersItem (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdsenseAdsenseReportsGenerateResponseHeadersItem;

// ----------------------------------------------------------------------------
//
//   GTLAdsenseAdsenseReportsGenerateResponse
//

@interface GTLAdsenseAdsenseReportsGenerateResponse : GTLObject

// The averages of the report. This is the same length as any other row in the
// report; cells corresponding to dimension columns are empty.
@property (retain) NSArray *averages;  // of NSString

// The header information of the columns requested in the report. This is a list
// of headers; one for each dimension in the request, followed by one for each
// metric in the request.
@property (retain) NSArray *headers;  // of GTLAdsenseAdsenseReportsGenerateResponseHeadersItem

// Kind this is, in this case adsense#report.
@property (copy) NSString *kind;

// The output rows of the report. Each row is a list of cells; one for each
// dimension in the request, followed by one for each metric in the request. The
// dimension cells contain strings, and the metric cells contain numbers.
@property (retain) NSArray *rows;  // of NSArray of NSString

// The total number of rows matched by the report request. Fewer rows may be
// returned in the response due to being limited by the row count requested or
// the report row limit.
@property (retain) NSNumber *totalMatchedRows;  // longLongValue

// The totals of the report. This is the same length as any other row in the
// report; cells corresponding to dimension columns are empty.
@property (retain) NSArray *totals;  // of NSString

// Any warnings associated with generation of the report.
@property (retain) NSArray *warnings;  // of NSString

@end


// ----------------------------------------------------------------------------
//
//   GTLAdsenseAdsenseReportsGenerateResponseHeadersItem
//

@interface GTLAdsenseAdsenseReportsGenerateResponseHeadersItem : GTLObject

// The currency of this column. Only present if the header type is
// METRIC_CURRENCY.
@property (copy) NSString *currency;

// The name of the header.
@property (copy) NSString *name;

// The type of the header; one of DIMENSION, METRIC_TALLY, METRIC_RATIO, or
// METRIC_CURRENCY.
@property (copy) NSString *type;

@end
