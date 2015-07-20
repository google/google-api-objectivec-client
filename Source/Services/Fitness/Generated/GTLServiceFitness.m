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
//  GTLServiceFitness.m
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
//   GTLServiceFitness (0 custom class methods, 0 custom properties)

#import "GTLFitness.h"

@implementation GTLServiceFitness

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = @[
    [GTLQueryFitness class],
    [GTLFitnessAggregateBucket class],
    [GTLFitnessAggregateBy class],
    [GTLFitnessAggregateResponse class],
    [GTLFitnessApplication class],
    [GTLFitnessBucketByActivity class],
    [GTLFitnessBucketBySession class],
    [GTLFitnessBucketByTime class],
    [GTLFitnessDataPoint class],
    [GTLFitnessDataset class],
    [GTLFitnessDataSource class],
    [GTLFitnessDataType class],
    [GTLFitnessDataTypeField class],
    [GTLFitnessDevice class],
    [GTLFitnessListDataSourcesResponse class],
    [GTLFitnessListSessionsResponse class],
    [GTLFitnessMapValue class],
    [GTLFitnessSession class],
    [GTLFitnessValue class],
    [GTLFitnessValueMapValEntry class]
  ];
  return classes;
}
#endif  // DEBUG

- (instancetype)init {
  self = [super init];
  if (self) {
    // Version from discovery.
    self.apiVersion = @"v1";

    // From discovery.  Where to send JSON-RPC.
    // Turn off prettyPrint for this service to save bandwidth (especially on
    // mobile). The fetcher logging will pretty print.
    self.rpcURL = [NSURL URLWithString:@"https://www.googleapis.com/rpc?prettyPrint=false"];
  }
  return self;
}

@end
