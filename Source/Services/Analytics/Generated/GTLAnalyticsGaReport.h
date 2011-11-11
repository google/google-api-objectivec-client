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
//  GTLAnalyticsGaReport.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Analytics API (analytics/v3)
// Description:
//   View and manage your Google Analytics data
// Documentation:
//   http://code.google.com/apis/analytics
// Classes:
//   GTLAnalyticsGaReport (0 custom class methods, 13 custom properties)
//   GTLAnalyticsGaReportColumnHeadersItem (0 custom class methods, 3 custom properties)
//   GTLAnalyticsGaReportProfileInfo (0 custom class methods, 5 custom properties)
//   GTLAnalyticsGaReportQuery (0 custom class methods, 10 custom properties)
//   GTLAnalyticsGaReportTotalsForAllResults (0 custom class methods, 0 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsGaReportColumnHeadersItem;
@class GTLAnalyticsGaReportProfileInfo;
@class GTLAnalyticsGaReportQuery;
@class GTLAnalyticsGaReportTotalsForAllResults;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaReport
//

@interface GTLAnalyticsGaReport : GTLObject

// Column headers that list dimension names followed by the metric names. The
// order of dimensions and metrics is same as specified in the request.
@property (retain) NSArray *columnHeaders;  // of GTLAnalyticsGaReportColumnHeadersItem

// Determines if the report contains sampled data.
@property (retain) NSNumber *containsSampledData;  // boolValue

// Report ID.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSString *identifier;

// The maximum number of rows the response can contain, regardless of the actual
// number of rows returned. Its value ranges from 1 to 10,000 with a value of
// 1000 by default, or otherwise specified by the max-results query parameter.
@property (retain) NSNumber *itemsPerPage;  // intValue

// Resource type.
@property (retain) NSString *kind;

// Link to next page for this report query.
@property (retain) NSString *nextLink;

// Link to previous page for this report query.
@property (retain) NSString *previousLink;

// Information for the profile, for which the report data was requested.
@property (retain) GTLAnalyticsGaReportProfileInfo *profileInfo;

// Report request query parameters.
@property (retain) GTLAnalyticsGaReportQuery *query;

// Report data rows, where each row contains a list of dimension values followed
// by the metric values. The order of dimensions and metrics is same as
// specified in the request.
@property (retain) NSArray *rows;  // of NSArray of NSString

// Link to this page.
@property (retain) NSString *selfLink;

// The total number of rows for the query, regardless of the number of rows in
// the response.
@property (retain) NSNumber *totalResults;  // intValue

// Total values for the requested metrics over all the results, not just the
// results returned in this response. The order of the metric totals is same as
// the metric order specified in the request.
@property (retain) GTLAnalyticsGaReportTotalsForAllResults *totalsForAllResults;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaReportColumnHeadersItem
//

@interface GTLAnalyticsGaReportColumnHeadersItem : GTLObject

// Column Type. Either DIMENSION or METRIC.
@property (retain) NSString *columnType;

// Data type. Dimension column headers have only STRING as the data type. Metric
// column headers have data types for metric values such as INTEGER, DOUBLE,
// CURRENCY etc.
@property (retain) NSString *dataType;

// Column name.
@property (retain) NSString *name;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaReportProfileInfo
//

@interface GTLAnalyticsGaReportProfileInfo : GTLObject

// Account ID to which this profile belongs.
@property (retain) NSString *accountId;

// Profile ID.
@property (retain) NSString *profileId;

// Profile name.
@property (retain) NSString *profileName;

// Table ID for profile.
@property (retain) NSString *tableId;

// Web Property ID to which this profile belongs.
@property (retain) NSString *webPropertyId;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaReportQuery
//

@interface GTLAnalyticsGaReportQuery : GTLObject

// List of analytics dimensions.
@property (retain) NSArray *dimensions;  // of NSString

// End date.
@property (retain) NSString *endDate;

// Comma-separated list of dimension or metric filters.
@property (retain) NSString *filters;

// Unique table ID.
@property (retain) NSString *ids;

// Maximum results per page.
@property (retain) NSNumber *maxResults;  // intValue

// List of analytics metrics.
@property (retain) NSArray *metrics;  // of NSString

// Analytics advanced segment.
@property (retain) NSString *segment;

// List of dimensions or metrics based on which report data is sorted.
@property (retain) NSArray *sort;  // of NSString

// Start date.
@property (retain) NSString *startDate;

// Start index.
@property (retain) NSNumber *startIndex;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGaReportTotalsForAllResults
//

@interface GTLAnalyticsGaReportTotalsForAllResults : GTLObject
// This object is documented as having more properties that are NSString. Use
// -additionalJSONKeys and -additionalPropertyForName: to get the list of
// properties and then fetch them; or -additionalProperties to fetch them all at
// once.
@end
