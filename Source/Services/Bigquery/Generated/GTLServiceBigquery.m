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
//  GTLServiceBigquery.m
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
//   GTLServiceBigquery (0 custom class methods, 0 custom properties)

#import "GTLBigquery.h"

@implementation GTLServiceBigquery

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = @[
    [GTLQueryBigquery class],
    [GTLBigqueryCsvOptions class],
    [GTLBigqueryDataset class],
    [GTLBigqueryDatasetList class],
    [GTLBigqueryDatasetReference class],
    [GTLBigqueryErrorProto class],
    [GTLBigqueryExternalDataConfiguration class],
    [GTLBigqueryGetQueryResultsResponse class],
    [GTLBigqueryJob class],
    [GTLBigqueryJobCancelResponse class],
    [GTLBigqueryJobConfiguration class],
    [GTLBigqueryJobConfigurationExtract class],
    [GTLBigqueryJobConfigurationLink class],
    [GTLBigqueryJobConfigurationLoad class],
    [GTLBigqueryJobConfigurationQuery class],
    [GTLBigqueryJobConfigurationTableCopy class],
    [GTLBigqueryJobList class],
    [GTLBigqueryJobReference class],
    [GTLBigqueryJobStatistics class],
    [GTLBigqueryJobStatistics2 class],
    [GTLBigqueryJobStatistics3 class],
    [GTLBigqueryJobStatistics4 class],
    [GTLBigqueryJobStatus class],
    [GTLBigqueryJsonObject class],
    [GTLBigqueryProjectList class],
    [GTLBigqueryProjectReference class],
    [GTLBigqueryQueryResponse class],
    [GTLBigqueryTable class],
    [GTLBigqueryTableCell class],
    [GTLBigqueryTableDataInsertAllResponse class],
    [GTLBigqueryTableDataList class],
    [GTLBigqueryTableFieldSchema class],
    [GTLBigqueryTableList class],
    [GTLBigqueryTableReference class],
    [GTLBigqueryTableRow class],
    [GTLBigqueryTableSchema class],
    [GTLBigqueryUserDefinedFunctionResource class],
    [GTLBigqueryViewDefinition class]
  ];
  return classes;
}
#endif  // DEBUG

- (instancetype)init {
  self = [super init];
  if (self) {
    // Version from discovery.
    self.apiVersion = @"v2";

    // From discovery.  Where to send JSON-RPC.
    // Turn off prettyPrint for this service to save bandwidth (especially on
    // mobile). The fetcher logging will pretty print.
    self.rpcURL = [NSURL URLWithString:@"https://www.googleapis.com/rpc?prettyPrint=false"];
    self.rpcUploadURL = [NSURL URLWithString:@"https://www.googleapis.com/upload/rpc?uploadType=resumable&prettyPrint=false"];
  }
  return self;
}

@end
