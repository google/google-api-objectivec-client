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
//  GTLQueryDoubleClickBidManager.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   DoubleClick Bid Manager API (doubleclickbidmanager/v1)
// Description:
//   API for viewing and managing your reports in DoubleClick Bid Manager.
// Documentation:
//   https://developers.google.com/bid-manager/
// Classes:
//   GTLQueryDoubleClickBidManager (8 custom class methods, 12 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLDoubleClickBidManagerQuery;

@interface GTLQueryDoubleClickBidManager : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (nonatomic, copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (nonatomic, copy) NSString *dataRange;
@property (nonatomic, assign) BOOL dryRun;
@property (nonatomic, retain) NSArray *filterIds;  // of NSNumber (longLongValue)
@property (nonatomic, copy) NSString *filterType;
@property (nonatomic, copy) NSString *format;
@property (nonatomic, copy) NSString *lineItems;
@property (nonatomic, retain) GTLDoubleClickBidManagerQuery *query;
@property (nonatomic, assign) long long queryId;
@property (nonatomic, assign) long long reportDataEndTimeMs;
@property (nonatomic, assign) long long reportDataStartTimeMs;
@property (nonatomic, copy) NSString *timezoneCode;

#pragma mark -
#pragma mark "lineitems" methods
// These create a GTLQueryDoubleClickBidManager object.

// Method: doubleclickbidmanager.lineitems.downloadlineitems
// Retrieves line items in CSV format.
//  Optional:
//   filterIds: Ids of the specified filter type used to filter line items to
//     fetch. If omitted, all the line items will be returned.
//   filterType: Filter type used to filter line items to fetch.
//      kGTLDoubleClickBidManagerFilterTypeAdvertiserId: "ADVERTISER_ID"
//      kGTLDoubleClickBidManagerFilterTypeInsertionOrderId: "INSERTION_ORDER_ID"
//      kGTLDoubleClickBidManagerFilterTypeLineItemId: "LINE_ITEM_ID"
//   format: Format in which the line items will be returned. Default to CSV.
//      kGTLDoubleClickBidManagerFormatCsv: "CSV"
// Fetches a GTLDoubleClickBidManagerDownloadLineItemsResponse.
+ (instancetype)queryForLineitemsDownloadlineitems;

// Method: doubleclickbidmanager.lineitems.uploadlineitems
// Uploads line items in CSV format.
//  Optional:
//   dryRun: Set to true to get upload status without actually persisting the
//     line items.
//   format: Format the line items are in. Default to CSV.
//      kGTLDoubleClickBidManagerFormatCsv: "CSV"
//   lineItems: Line items in CSV to upload. Refer to Entity Write File Format
//     for more information on file format.
// Fetches a GTLDoubleClickBidManagerUploadLineItemsResponse.
+ (instancetype)queryForLineitemsUploadlineitems;

#pragma mark -
#pragma mark "queries" methods
// These create a GTLQueryDoubleClickBidManager object.

// Method: doubleclickbidmanager.queries.createquery
// Creates a query.
//  Optional:
//   query: GTLDoubleClickBidManagerQuery
// Fetches a GTLDoubleClickBidManagerQuery.
+ (instancetype)queryForQueriesCreatequery;

// Method: doubleclickbidmanager.queries.deletequery
// Deletes a stored query as well as the associated stored reports.
//  Required:
//   queryId: Query ID to delete.
+ (instancetype)queryForQueriesDeletequeryWithQueryId:(long long)queryId;

// Method: doubleclickbidmanager.queries.getquery
// Retrieves a stored query.
//  Required:
//   queryId: Query ID to retrieve.
// Fetches a GTLDoubleClickBidManagerQuery.
+ (instancetype)queryForQueriesGetqueryWithQueryId:(long long)queryId;

// Method: doubleclickbidmanager.queries.listqueries
// Retrieves stored queries.
// Fetches a GTLDoubleClickBidManagerListQueriesResponse.
+ (instancetype)queryForQueriesListqueries;

// Method: doubleclickbidmanager.queries.runquery
// Runs a stored query to generate a report.
//  Required:
//   queryId: Query ID to run.
//  Optional:
//   dataRange: Report data range used to generate the report.
//      kGTLDoubleClickBidManagerDataRangeAllTime: "ALL_TIME"
//      kGTLDoubleClickBidManagerDataRangeCurrentDay: "CURRENT_DAY"
//      kGTLDoubleClickBidManagerDataRangeCustomDates: "CUSTOM_DATES"
//      kGTLDoubleClickBidManagerDataRangeLast14Days: "LAST_14_DAYS"
//      kGTLDoubleClickBidManagerDataRangeLast30Days: "LAST_30_DAYS"
//      kGTLDoubleClickBidManagerDataRangeLast365Days: "LAST_365_DAYS"
//      kGTLDoubleClickBidManagerDataRangeLast7Days: "LAST_7_DAYS"
//      kGTLDoubleClickBidManagerDataRangeLast90Days: "LAST_90_DAYS"
//      kGTLDoubleClickBidManagerDataRangeMonthToDate: "MONTH_TO_DATE"
//      kGTLDoubleClickBidManagerDataRangePreviousDay: "PREVIOUS_DAY"
//      kGTLDoubleClickBidManagerDataRangePreviousHalfMonth: "PREVIOUS_HALF_MONTH"
//      kGTLDoubleClickBidManagerDataRangePreviousMonth: "PREVIOUS_MONTH"
//      kGTLDoubleClickBidManagerDataRangePreviousQuarter: "PREVIOUS_QUARTER"
//      kGTLDoubleClickBidManagerDataRangePreviousWeek: "PREVIOUS_WEEK"
//      kGTLDoubleClickBidManagerDataRangePreviousYear: "PREVIOUS_YEAR"
//      kGTLDoubleClickBidManagerDataRangeQuarterToDate: "QUARTER_TO_DATE"
//      kGTLDoubleClickBidManagerDataRangeWeekToDate: "WEEK_TO_DATE"
//      kGTLDoubleClickBidManagerDataRangeYearToDate: "YEAR_TO_DATE"
//   reportDataEndTimeMs: The ending time for the data that is shown in the
//     report. Note, reportDataEndTimeMs is required if dataRange is
//     CUSTOM_DATES and ignored otherwise.
//   reportDataStartTimeMs: The starting time for the data that is shown in the
//     report. Note, reportDataStartTimeMs is required if dataRange is
//     CUSTOM_DATES and ignored otherwise.
//   timezoneCode: Canonical timezone code for report data time. Defaults to
//     America/New_York.
+ (instancetype)queryForQueriesRunqueryWithQueryId:(long long)queryId;

#pragma mark -
#pragma mark "reports" methods
// These create a GTLQueryDoubleClickBidManager object.

// Method: doubleclickbidmanager.reports.listreports
// Retrieves stored reports.
//  Required:
//   queryId: Query ID with which the reports are associated.
// Fetches a GTLDoubleClickBidManagerListReportsResponse.
+ (instancetype)queryForReportsListreportsWithQueryId:(long long)queryId;

@end
