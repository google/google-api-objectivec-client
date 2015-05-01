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
//  GTLBigqueryQueryResponse.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   BigQuery API (bigquery/v2)
// Description:
//   A data platform for customers to create, manage, share and query data.
// Documentation:
//   https://cloud.google.com/bigquery/
// Classes:
//   GTLBigqueryQueryResponse (0 custom class methods, 9 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryJobReference;
@class GTLBigqueryTableRow;
@class GTLBigqueryTableSchema;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryQueryResponse
//

@interface GTLBigqueryQueryResponse : GTLObject

// Whether the query result was fetched from the query cache.
@property (nonatomic, retain) NSNumber *cacheHit;  // boolValue

// Whether the query has completed or not. If rows or totalRows are present,
// this will always be true. If this is false, totalRows will not be available.
@property (nonatomic, retain) NSNumber *jobComplete;  // boolValue

// Reference to the Job that was created to run the query. This field will be
// present even if the original request timed out, in which case GetQueryResults
// can be used to read the results once the query has completed. Since this API
// only returns the first page of results, subsequent pages can be fetched via
// the same mechanism (GetQueryResults).
@property (nonatomic, retain) GTLBigqueryJobReference *jobReference;

// The resource type.
@property (nonatomic, copy) NSString *kind;

// A token used for paging results.
@property (nonatomic, copy) NSString *pageToken;

// An object with as many results as can be contained within the maximum
// permitted reply size. To get any additional rows, you can call
// GetQueryResults and specify the jobReference returned above.
@property (nonatomic, retain) NSArray *rows;  // of GTLBigqueryTableRow

// The schema of the results. Present only when the query completes
// successfully.
@property (nonatomic, retain) GTLBigqueryTableSchema *schema;

// The total number of bytes processed for this query. If this query was a dry
// run, this is the number of bytes that would be processed if the query were
// run.
@property (nonatomic, retain) NSNumber *totalBytesProcessed;  // longLongValue

// The total number of rows in the complete query result set, which can be more
// than the number of rows in this single page of results.
@property (nonatomic, retain) NSNumber *totalRows;  // unsignedLongLongValue

@end
