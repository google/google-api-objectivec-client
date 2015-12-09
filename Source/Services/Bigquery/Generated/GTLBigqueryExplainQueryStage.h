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
//  GTLBigqueryExplainQueryStage.h
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
//   GTLBigqueryExplainQueryStage (0 custom class methods, 13 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryExplainQueryStep;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryExplainQueryStage
//

@interface GTLBigqueryExplainQueryStage : GTLObject

// Relative amount of time the average shard spent on CPU-bound tasks.
@property (nonatomic, retain) NSNumber *computeRatioAvg;  // doubleValue

// Relative amount of time the slowest shard spent on CPU-bound tasks.
@property (nonatomic, retain) NSNumber *computeRatioMax;  // doubleValue

// Unique ID for stage within plan.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, retain) NSNumber *identifier;  // longLongValue

// Human-readable name for stage.
@property (nonatomic, copy) NSString *name;

// Relative amount of time the average shard spent reading input.
@property (nonatomic, retain) NSNumber *readRatioAvg;  // doubleValue

// Relative amount of time the slowest shard spent reading input.
@property (nonatomic, retain) NSNumber *readRatioMax;  // doubleValue

// Number of records read into the stage.
@property (nonatomic, retain) NSNumber *recordsRead;  // longLongValue

// Number of records written by the stage.
@property (nonatomic, retain) NSNumber *recordsWritten;  // longLongValue

// List of operations within the stage in dependency order (approximately
// chronological).
@property (nonatomic, retain) NSArray *steps;  // of GTLBigqueryExplainQueryStep

// Relative amount of time the average shard spent waiting to be scheduled.
@property (nonatomic, retain) NSNumber *waitRatioAvg;  // doubleValue

// Relative amount of time the slowest shard spent waiting to be scheduled.
@property (nonatomic, retain) NSNumber *waitRatioMax;  // doubleValue

// Relative amount of time the average shard spent on writing output.
@property (nonatomic, retain) NSNumber *writeRatioAvg;  // doubleValue

// Relative amount of time the slowest shard spent on writing output.
@property (nonatomic, retain) NSNumber *writeRatioMax;  // doubleValue

@end
