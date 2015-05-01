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
//  GTLServiceDoubleClickBidManager.m
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
//   GTLServiceDoubleClickBidManager (0 custom class methods, 0 custom properties)

#import "GTLDoubleClickBidManager.h"

@implementation GTLServiceDoubleClickBidManager

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = @[
    [GTLQueryDoubleClickBidManager class],
    [GTLDoubleClickBidManagerDownloadLineItemsResponse class],
    [GTLDoubleClickBidManagerFilterPair class],
    [GTLDoubleClickBidManagerListQueriesResponse class],
    [GTLDoubleClickBidManagerListReportsResponse class],
    [GTLDoubleClickBidManagerParameters class],
    [GTLDoubleClickBidManagerQuery class],
    [GTLDoubleClickBidManagerQueryMetadata class],
    [GTLDoubleClickBidManagerQuerySchedule class],
    [GTLDoubleClickBidManagerReport class],
    [GTLDoubleClickBidManagerReportFailure class],
    [GTLDoubleClickBidManagerReportKey class],
    [GTLDoubleClickBidManagerReportMetadata class],
    [GTLDoubleClickBidManagerReportStatus class],
    [GTLDoubleClickBidManagerRowStatus class],
    [GTLDoubleClickBidManagerUploadLineItemsResponse class],
    [GTLDoubleClickBidManagerUploadStatus class]
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
