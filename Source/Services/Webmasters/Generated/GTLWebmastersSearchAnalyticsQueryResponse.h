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
//  GTLWebmastersSearchAnalyticsQueryResponse.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Webmaster Tools API (webmasters/v3)
// Description:
//   Lets you view Google Webmaster Tools data for your verified sites.
// Documentation:
//   https://developers.google.com/webmaster-tools/
// Classes:
//   GTLWebmastersSearchAnalyticsQueryResponse (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLWebmastersApiDataRow;

// ----------------------------------------------------------------------------
//
//   GTLWebmastersSearchAnalyticsQueryResponse
//

// A list of rows, one per result, grouped by key. Metrics in each row are
// aggregated for all data grouped by that key either by page or property, as
// specified by the aggregation type parameter.

@interface GTLWebmastersSearchAnalyticsQueryResponse : GTLObject

// How the results were aggregated.
@property (nonatomic, copy) NSString *responseAggregationType;

// A list of rows grouped by the key values in the order given in the query.
@property (nonatomic, retain) NSArray *rows;  // of GTLWebmastersApiDataRow

@end
