/* Copyright (c) 2012 Google Inc.
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
//  GTLBigqueryJob.h
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
//   GTLBigqueryJob (0 custom class methods, 8 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryJobConfiguration;
@class GTLBigqueryJobReference;
@class GTLBigqueryJobStatistics;
@class GTLBigqueryJobStatus;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryJob
//

@interface GTLBigqueryJob : GTLObject

// [Required] Describes the job configuration.
@property (retain) GTLBigqueryJobConfiguration *configuration;

// [Output-only] A hash of this resource.
@property (copy) NSString *ETag;

// [Output-only] Opaque ID field of the job
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// [Optional] Reference describing the unique-per-user name of the job.
@property (retain) GTLBigqueryJobReference *jobReference;

// [Output-only] The type of the resource.
@property (copy) NSString *kind;

// [Output-only] A URL that can be used to access this resource again.
@property (copy) NSString *selfLink;

// [Output-only] Information about the job, including starting time and ending
// time of the job.
@property (retain) GTLBigqueryJobStatistics *statistics;

// [Output-only] The status of this job. Examine this value when polling an
// asynchronous job to see if the job is complete.
@property (retain) GTLBigqueryJobStatus *status;

@end
