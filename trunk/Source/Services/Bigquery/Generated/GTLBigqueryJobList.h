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
//  GTLBigqueryJobList.h
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
//   GTLBigqueryJobList (0 custom class methods, 4 custom properties)
//   GTLBigqueryJobListJobsItem (0 custom class methods, 9 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryErrorProto;
@class GTLBigqueryJobConfiguration;
@class GTLBigqueryJobListJobsItem;
@class GTLBigqueryJobReference;
@class GTLBigqueryJobStatistics;
@class GTLBigqueryJobStatus;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryJobList
//

@interface GTLBigqueryJobList : GTLObject

// A hash of this page of results.
@property (nonatomic, copy) NSString *ETag;

// List of jobs that were requested.
@property (nonatomic, retain) NSArray *jobs;  // of GTLBigqueryJobListJobsItem

// The resource type of the response.
@property (nonatomic, copy) NSString *kind;

// A token to request the next page of results.
@property (nonatomic, copy) NSString *nextPageToken;

@end


// ----------------------------------------------------------------------------
//
//   GTLBigqueryJobListJobsItem
//

@interface GTLBigqueryJobListJobsItem : GTLObject

// [Full-projection-only] Specifies the job configuration.
@property (nonatomic, retain) GTLBigqueryJobConfiguration *configuration;

// A result object that will be present only if the job has failed.
@property (nonatomic, retain) GTLBigqueryErrorProto *errorResult;

// Unique opaque ID of the job.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Job reference uniquely identifying the job.
@property (nonatomic, retain) GTLBigqueryJobReference *jobReference;

// The resource type.
@property (nonatomic, copy) NSString *kind;

// Running state of the job. When the state is DONE, errorResult can be checked
// to determine whether the job succeeded or failed.
@property (nonatomic, copy) NSString *state;

// [Output-only] Information about the job, including starting time and ending
// time of the job.
@property (nonatomic, retain) GTLBigqueryJobStatistics *statistics;

// [Full-projection-only] Describes the state of the job.
@property (nonatomic, retain) GTLBigqueryJobStatus *status;

// [Full-projection-only] Email address of the user who ran the job.
@property (nonatomic, copy) NSString *userEmail;

@end
