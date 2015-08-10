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
//  GTLFitnessAggregateBucket.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Fitness (fitness/v1)
// Description:
//   Google Fit API
// Documentation:
//   https://developers.google.com/fit/rest/
// Classes:
//   GTLFitnessAggregateBucket (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLFitnessDataset;
@class GTLFitnessSession;

// ----------------------------------------------------------------------------
//
//   GTLFitnessAggregateBucket
//

@interface GTLFitnessAggregateBucket : GTLObject

// Available for Bucket.Type.ACTIVITY_TYPE, Bucket.Type.ACTIVITY_SEGMENT
@property (nonatomic, retain) NSNumber *activity;  // intValue

// There will be one dataset per AggregateBy in the request.
@property (nonatomic, retain) NSArray *dataset;  // of GTLFitnessDataset

// The end time for the aggregated data, in milliseconds since epoch, inclusive.
@property (nonatomic, retain) NSNumber *endTimeMillis;  // longLongValue

// Available for Bucket.Type.SESSION
@property (nonatomic, retain) GTLFitnessSession *session;

// The start time for the aggregated data, in milliseconds since epoch,
// inclusive.
@property (nonatomic, retain) NSNumber *startTimeMillis;  // longLongValue

// The type of a bucket signifies how the data aggregation is performed in the
// bucket.
@property (nonatomic, copy) NSString *type;

@end
