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
//  GTLFitnessDataset.h
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
//   GTLFitnessDataset (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLFitnessDataPoint;

// ----------------------------------------------------------------------------
//
//   GTLFitnessDataset
//

// A dataset represents a projection container for data points. They do not
// carry any info of their own. Datasets represent a set of data points from a
// particular data source. A data point can be found in more than one dataset.

@interface GTLFitnessDataset : GTLObject

// The data stream ID of the data source that created the points in this
// dataset.
@property (nonatomic, copy) NSString *dataSourceId;

// The largest end time of all data points in this possibly partial
// representation of the dataset. Time is in nanoseconds from epoch. This should
// also match the first part of the dataset identifier.
@property (nonatomic, retain) NSNumber *maxEndTimeNs;  // longLongValue

// The smallest start time of all data points in this possibly partial
// representation of the dataset. Time is in nanoseconds from epoch. This should
// also match the first part of the dataset identifier.
@property (nonatomic, retain) NSNumber *minStartTimeNs;  // longLongValue

// This token will be set when a dataset is received in response to a GET
// request and the dataset is too large to be included in a single response.
// Provide this value in a subsequent GET request to return the next page of
// data points within this dataset.
@property (nonatomic, copy) NSString *nextPageToken;

// A partial list of data points contained in the dataset, ordered by largest
// endTimeNanos first. This list is considered complete when retrieving a small
// dataset and partial when patching a dataset or retrieving a dataset that is
// too large to include in a single response.
@property (nonatomic, retain) NSArray *point;  // of GTLFitnessDataPoint

@end
