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
//  GTLYouTubeAnalyticsResultTable.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   YouTube Analytics API (youtubeAnalytics/v1)
// Description:
//   Retrieve your YouTube Analytics reports.
// Documentation:
//   http://developers.google.com/youtube/analytics/
// Classes:
//   GTLYouTubeAnalyticsResultTable (0 custom class methods, 3 custom properties)
//   GTLYouTubeAnalyticsResultTableColumnHeadersItem (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeAnalyticsResultTableColumnHeadersItem;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeAnalyticsResultTable
//

// Contains a single result table. The table is returned as an array of rows
// that contain the values for the cells of the table. Depending on the metric
// or dimension, the cell can contain a string (video ID, country code) or a
// number (number of views or number of likes).

@interface GTLYouTubeAnalyticsResultTable : GTLObject

// This value specifies information about the data returned in the rows fields.
// Each item in the columnHeaders list identifies a field returned in the rows
// value, which contains a list of comma-delimited data. The columnHeaders list
// will begin with the dimensions specified in the API request, which will be
// followed by the metrics specified in the API request. The order of both
// dimensions and metrics will match the ordering in the API request. For
// example, if the API request contains the parameters
// dimensions=ageGroup,gender&metrics=viewerPercentage, the API response will
// return columns in this order: ageGroup,gender,viewerPercentage.
@property (retain) NSArray *columnHeaders;  // of GTLYouTubeAnalyticsResultTableColumnHeadersItem

// This value specifies the type of data included in the API response. For the
// query method, the kind property value will be youtubeAnalytics#resultTable.
@property (copy) NSString *kind;

// The list contains all rows of the result table. Each item in the list is an
// array that contains comma-delimited data corresponding to a single row of
// data. The order of the comma-delimited data fields will match the order of
// the columns listed in the columnHeaders field. If no data is available for
// the given query, the rows element will be omitted from the response. The
// response for a query with the day dimension will not contain rows for the
// most recent days.
@property (retain) NSArray *rows;  // of NSArray of any JSON type

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeAnalyticsResultTableColumnHeadersItem
//

@interface GTLYouTubeAnalyticsResultTableColumnHeadersItem : GTLObject

// The type of the column (DIMENSION or METRIC).
@property (copy) NSString *columnType;

// The type of the data in the column (STRING, INTEGER, FLOAT, etc.).
@property (copy) NSString *dataType;

// The name of the dimension or metric.
@property (copy) NSString *name;

@end
