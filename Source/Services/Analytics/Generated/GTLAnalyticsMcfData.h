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
//   GTLAnalyticsMcfData (0 custom class methods, 15 custom properties)
//   GTLAnalyticsMcfDataColumnHeadersItem (0 custom class methods, 3 custom properties)
//   GTLAnalyticsMcfDataProfileInfo (0 custom class methods, 6 custom properties)
//   GTLAnalyticsMcfDataQuery (0 custom class methods, 11 custom properties)
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
@property (nonatomic, retain) NSArray *columnHeaders;  // of GTLAnalyticsMcfDataColumnHeadersItem

// Determines if the Analytics data contains sampled data.
@property (nonatomic, retain) NSNumber *containsSampledData;  // boolValue

// Unique ID for this data response.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The maximum number of rows the response can contain, regardless of the actual
// number of rows returned. Its value ranges from 1 to 10,000 with a value of
// 1000 by default, or otherwise specified by the max-results query parameter.
@property (nonatomic, retain) NSNumber *itemsPerPage;  // intValue

// Resource type.
@property (nonatomic, copy) NSString *kind;

// Link to next page for this Analytics data query.
@property (nonatomic, copy) NSString *nextLink;

// Link to previous page for this Analytics data query.
@property (nonatomic, copy) NSString *previousLink;

// Information for the view (profile), for which the Analytics data was
// requested.
@property (nonatomic, retain) GTLAnalyticsMcfDataProfileInfo *profileInfo;

// Analytics data request query parameters.
@property (nonatomic, retain) GTLAnalyticsMcfDataQuery *query;

// Analytics data rows, where each row contains a list of dimension values
// followed by the metric values. The order of dimensions and metrics is same as
// specified in the request.
@property (nonatomic, retain) NSArray *rows;  // of NSArray of GTLAnalyticsMcfDataRowsItem

// The number of samples used to calculate the result.
@property (nonatomic, retain) NSNumber *sampleSize;  // longLongValue

// Total size of the sample space from which the samples were selected.
@property (nonatomic, retain) NSNumber *sampleSpace;  // longLongValue

// Link to this page.
@property (nonatomic, copy) NSString *selfLink;

// The total number of rows for the query, regardless of the number of rows in
// the response.
@property (nonatomic, retain) NSNumber *totalResults;  // intValue

// Total values for the requested metrics over all the results, not just the
// results returned in this response. The order of the metric totals is same as
// the metric order specified in the request.
@property (nonatomic, retain) GTLAnalyticsMcfDataTotalsForAllResults *totalsForAllResults;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsMcfDataColumnHeadersItem
//

@interface GTLAnalyticsMcfDataColumnHeadersItem : GTLObject

// Column Type. Either DIMENSION or METRIC.
@property (nonatomic, copy) NSString *columnType;

// Data type. Dimension and metric values data types such as INTEGER, DOUBLE,
// CURRENCY, MCF_SEQUENCE etc.
@property (nonatomic, copy) NSString *dataType;

// Column name.
@property (nonatomic, copy) NSString *name;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsMcfDataProfileInfo
//

@interface GTLAnalyticsMcfDataProfileInfo : GTLObject

// Account ID to which this view (profile) belongs.
@property (nonatomic, copy) NSString *accountId;

// Internal ID for the web property to which this view (profile) belongs.
@property (nonatomic, copy) NSString *internalWebPropertyId;

// View (Profile) ID.
@property (nonatomic, copy) NSString *profileId;

// View (Profile) name.
@property (nonatomic, copy) NSString *profileName;

// Table ID for view (profile).
@property (nonatomic, copy) NSString *tableId;

// Web Property ID to which this view (profile) belongs.
@property (nonatomic, copy) NSString *webPropertyId;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsMcfDataQuery
//

@interface GTLAnalyticsMcfDataQuery : GTLObject

// List of analytics dimensions.
@property (nonatomic, copy) NSString *dimensions;

// End date.
@property (nonatomic, copy) NSString *endDate;

// Comma-separated list of dimension or metric filters.
@property (nonatomic, copy) NSString *filters;

// Unique table ID.
@property (nonatomic, copy) NSString *ids;

// Maximum results per page.
@property (nonatomic, retain) NSNumber *maxResults;  // intValue

// List of analytics metrics.
@property (nonatomic, retain) NSArray *metrics;  // of NSString

// Desired sampling level
@property (nonatomic, copy) NSString *samplingLevel;

// Analytics advanced segment.
@property (nonatomic, copy) NSString *segment;

// List of dimensions or metrics based on which Analytics data is sorted.
@property (nonatomic, retain) NSArray *sort;  // of NSString

// Start date.
@property (nonatomic, copy) NSString *startDate;

// Start index.
@property (nonatomic, retain) NSNumber *startIndex;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsMcfDataRowsItem
//

@interface GTLAnalyticsMcfDataRowsItem : GTLObject

// A conversion path dimension value, containing a list of interactions with
// their attributes.
@property (nonatomic, retain) NSArray *conversionPathValue;  // of GTLAnalyticsMcfDataRowsItemConversionPathValueItem

// A primitive dimension value. A primitive metric value.
@property (nonatomic, copy) NSString *primitiveValue;

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
@property (nonatomic, copy) NSString *interactionType;

// Node value of an interaction on conversion path. Such as source, medium etc.
@property (nonatomic, copy) NSString *nodeValue;

@end
