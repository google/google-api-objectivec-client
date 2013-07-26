/* Copyright (c) 2013 Google Inc.
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
//  GTLAnalyticsMcfData.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Analytics API (analytics/v3)
// Description:
//   View and manage your Google Analytics data
// Documentation:
//   https://developers.google.com/analytics/
// Classes:
//   GTLAnalyticsMcfData (0 custom class methods, 13 custom properties)
//   GTLAnalyticsMcfDataColumnHeadersItem (0 custom class methods, 3 custom properties)
//   GTLAnalyticsMcfDataProfileInfo (0 custom class methods, 6 custom properties)
//   GTLAnalyticsMcfDataQuery (0 custom class methods, 10 custom properties)
//   GTLAnalyticsMcfDataRowsItem (0 custom class methods, 2 custom properties)
//   GTLAnalyticsMcfDataTotalsForAllResults (0 custom class methods, 0 custom properties)
//   GTLAnalyticsMcfDataRowsItemConversionPathValueItem (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsMcfDataColumnHeadersItem;
@class GTLAnalyticsMcfDataProfileInfo;
@class GTLAnalyticsMcfDataQuery;
@class GTLAnalyticsMcfDataRowsItem;
@class GTLAnalyticsMcfDataRowsItemConversionPathValueItem;
@class GTLAnalyticsMcfDataTotalsForAllResults;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsMcfData
//

// Multi-Channel Funnels data for a given view (profile).

@interface GTLAnalyticsMcfData : GTLObject

// Column headers that list dimension names followed by the metric names. The
// order of dimensions and metrics is same as specified in the request.
@property (retain) NSArray *columnHeaders;  // of GTLAnalyticsMcfDataColumnHeadersItem

// Determines if the Analytics data contains sampled data.
@property (retain) NSNumber *containsSampledData;  // boolValue

// Unique ID for this data response.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The maximum number of rows the response can contain, regardless of the actual
// number of rows returned. Its value ranges from 1 to 10,000 with a value of
// 1000 by default, or otherwise specified by the max-results query parameter.
@property (retain) NSNumber *itemsPerPage;  // intValue

// Resource type.
@property (copy) NSString *kind;

// Link to next page for this Analytics data query.
@property (copy) NSString *nextLink;

// Link to previous page for this Analytics data query.
@property (copy) NSString *previousLink;

// Information for the view (profile), for which the Analytics data was
// requested.
@property (retain) GTLAnalyticsMcfDataProfileInfo *profileInfo;

// Analytics data request query parameters.
@property (retain) GTLAnalyticsMcfDataQuery *query;

// Analytics data rows, where each row contains a list of dimension values
// followed by the metric values. The order of dimensions and metrics is same as
// specified in the request.
@property (retain) NSArray *rows;  // of NSArray of GTLAnalyticsMcfDataRowsItem

// Link to this page.
@property (copy) NSString *selfLink;

// The total number of rows for the query, regardless of the number of rows in
// the response.
@property (retain) NSNumber *totalResults;  // intValue

// Total values for the requested metrics over all the results, not just the
// results returned in this response. The order of the metric totals is same as
// the metric order specified in the request.
@property (retain) GTLAnalyticsMcfDataTotalsForAllResults *totalsForAllResults;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsMcfDataColumnHeadersItem
//

@interface GTLAnalyticsMcfDataColumnHeadersItem : GTLObject

// Column Type. Either DIMENSION or METRIC.
@property (copy) NSString *columnType;

// Data type. Dimension and metric values data types such as INTEGER, DOUBLE,
// CURRENCY, MCF_SEQUENCE etc.
@property (copy) NSString *dataType;

// Column name.
@property (copy) NSString *name;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsMcfDataProfileInfo
//

@interface GTLAnalyticsMcfDataProfileInfo : GTLObject

// Account ID to which this view (profile) belongs.
@property (copy) NSString *accountId;

// Internal ID for the web property to which this view (profile) belongs.
@property (copy) NSString *internalWebPropertyId;

// View (Profile) ID.
@property (copy) NSString *profileId;

// View (Profile) name.
@property (copy) NSString *profileName;

// Table ID for view (profile).
@property (copy) NSString *tableId;

// Web Property ID to which this view (profile) belongs.
@property (copy) NSString *webPropertyId;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsMcfDataQuery
//

@interface GTLAnalyticsMcfDataQuery : GTLObject

// List of analytics dimensions.
@property (copy) NSString *dimensions;

// End date.
@property (copy) NSString *endDate;

// Comma-separated list of dimension or metric filters.
@property (copy) NSString *filters;

// Unique table ID.
@property (copy) NSString *ids;

// Maximum results per page.
@property (retain) NSNumber *maxResults;  // intValue

// List of analytics metrics.
@property (retain) NSArray *metrics;  // of NSString

// Analytics advanced segment.
@property (copy) NSString *segment;

// List of dimensions or metrics based on which Analytics data is sorted.
@property (retain) NSArray *sort;  // of NSString

// Start date.
@property (copy) NSString *startDate;

// Start index.
@property (retain) NSNumber *startIndex;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsMcfDataRowsItem
//

@interface GTLAnalyticsMcfDataRowsItem : GTLObject

// A conversion path dimension value, containing a list of interactions with
// their attributes.
@property (retain) NSArray *conversionPathValue;  // of GTLAnalyticsMcfDataRowsItemConversionPathValueItem

// A primitive dimension value. A primitive metric value.
@property (copy) NSString *primitiveValue;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsMcfDataTotalsForAllResults
//

@interface GTLAnalyticsMcfDataTotalsForAllResults : GTLObject
// This object is documented as having more properties that are NSString. Use
// -additionalJSONKeys and -additionalPropertyForName: to get the list of
// properties and then fetch them; or -additionalProperties to fetch them all at
// once.
@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsMcfDataRowsItemConversionPathValueItem
//

@interface GTLAnalyticsMcfDataRowsItemConversionPathValueItem : GTLObject

// Type of an interaction on conversion path. Such as CLICK, IMPRESSION etc.
@property (copy) NSString *interactionType;

// Node value of an interaction on conversion path. Such as source, medium etc.
@property (copy) NSString *nodeValue;

@end
