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
//  GTLBigqueryJobStatistics.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   BigQuery API (bigquery/v2)
// Description:
//   A data platform for customers to create, manage, share and query data.
// Documentation:
//   https://developers.google.com/bigquery/docs/overview
// Classes:
//   GTLBigqueryJobStatistics (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryJobStatistics2;
@class GTLBigqueryJobStatistics3;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryJobStatistics
//

@interface GTLBigqueryJobStatistics : GTLObject

// [Output-only] Creation time of this job, in milliseconds since the epoch.
// This field will be present on all jobs.
@property (retain) NSNumber *creationTime;  // longLongValue

// [Output-only] End time of this job, in milliseconds since the epoch. This
// field will be present whenever a job is in the DONE state.
@property (retain) NSNumber *endTime;  // longLongValue

// [Output-only] Statistics for a load job.
@property (retain) GTLBigqueryJobStatistics3 *load;

// [Output-only] Statistics for a query job.
@property (retain) GTLBigqueryJobStatistics2 *query;

// [Output-only] Start time of this job, in milliseconds since the epoch. This
// field will be present when the job transitions from the PENDING state to
// either RUNNING or DONE.
@property (retain) NSNumber *startTime;  // longLongValue

// [Output-only] [Deprecated] Use the bytes processed in the query statistics
// instead.
@property (retain) NSNumber *totalBytesProcessed;  // longLongValue

@end
