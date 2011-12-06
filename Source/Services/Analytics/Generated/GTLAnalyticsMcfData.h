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
//  GTLAnalyticsMcfData.h
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

@interface GTLAnalyticsMcfData : GTLObject

// Column headers that list dimension names followed by the metric names. The
// order of dimensions and metrics is same as specified in the request.
@property (retain) NSArray *columnHeaders;  // of GTLAnalyticsMcfDataColumnHeadersItem

// Determines if the Analytics data contains sampled data.
@property (retain) NSNumber *containsSampledData;  // boolValue

// Unique ID for this data response.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSString *identifier;

// The maximum number of rows the response can contain, regardless of the actual
// number of rows returned. Its value ranges from 1 to 10,000 with a value of
// 1000 by default, or otherwise specified by the max-results query parameter.
@property (retain) NSNumber *itemsPerPage;  // intValue

// Resource type.
@property (retain) NSString *kind;

// Link to next page for this Analytics data query.
@property (retain) NSString *nextLink;

// Link to previous page for this Analytics data query.
@property (retain) NSString *previousLink;

// Information for the profile, for which the Analytics data was requested.
@property (retain) GTLAnalyticsMcfDataProfileInfo *profileInfo;

// Analytics data request query parameters.
@property (retain) GTLAnalyticsMcfDataQuery *query;

// Analytics data rows, where each row contains a list of dimension values
// followed by the metric values. The order of dimensions and metrics is same as
// specified in the request.
@property (retain) NSArray *rows;  // of NSArray of GTLAnalyticsMcfDataRowsItem

// Link to this page.
@property (retain) NSString *selfLink;

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
@property (retain) NSString *columnType;

// Data type. Dimension and metric values data types such as INTEGER, DOUBLE,
// CURRENCY, MCF_SEQUENCE etc.
@property (retain) NSString *dataType;

// Column name.
@property (retain) NSString *name;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsMcfDataProfileInfo
//

@interface GTLAnalyticsMcfDataProfileInfo : GTLObject

// Account ID to which this profile belongs.
@property (retain) NSString *accountId;

// Internal ID for the web property to which this profile belongs.
@property (retain) NSString *internalWebPropertyId;

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
//   GTLAnalyticsMcfDataQuery
//

@interface GTLAnalyticsMcfDataQuery : GTLObject

// List of analytics dimensions.
@property (retain) NSString *dimensions;

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

// List of dimensions or metrics based on which Analytics data is sorted.
@property (retain) NSArray *sort;  // of NSString

// Start date.
@property (retain) NSString *startDate;

// Start index.
@property (retain) NSNumber *startIndex;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsMcfDataRowsItem
//

@interface GTLAnalyticsMcfDataRowsItem : GTLObject

// A conversion path, containing a list of interactions with their attributes.
@property (retain) NSArray *conversionPathValue;  // of GTLAnalyticsMcfDataRowsItemConversionPathValueItem

@property (retain) NSString *primitiveValue;
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
@property (retain) NSString *interactionType;

// Node value of an interaction on conversion path. Such as source, medium etc.
@property (retain) NSString *nodeValue;

@end
