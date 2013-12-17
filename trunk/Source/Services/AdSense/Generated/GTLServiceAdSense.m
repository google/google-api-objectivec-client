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
//  GTLServiceAdSense.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Management API (adsense/v1.4)
// Description:
//   Gives AdSense publishers access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://developers.google.com/adsense/management/
// Classes:
//   GTLServiceAdSense (0 custom class methods, 0 custom properties)

#import "GTLAdSense.h"

@implementation GTLServiceAdSense

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = [NSArray arrayWithObjects:
                      [GTLQueryAdSense class],
                      [GTLAdSenseAccount class],
                      [GTLAdSenseAccounts class],
                      [GTLAdSenseAdClient class],
                      [GTLAdSenseAdClients class],
                      [GTLAdSenseAdCode class],
                      [GTLAdSenseAdsenseReportsGenerateResponse class],
                      [GTLAdSenseAdStyle class],
                      [GTLAdSenseAdUnit class],
                      [GTLAdSenseAdUnits class],
                      [GTLAdSenseAlert class],
                      [GTLAdSenseAlerts class],
                      [GTLAdSenseCustomChannel class],
                      [GTLAdSenseCustomChannels class],
                      [GTLAdSenseMetadata class],
                      [GTLAdSensePayment class],
                      [GTLAdSensePayments class],
                      [GTLAdSenseReportingMetadataEntry class],
                      [GTLAdSenseSavedAdStyle class],
                      [GTLAdSenseSavedAdStyles class],
                      [GTLAdSenseSavedReport class],
                      [GTLAdSenseSavedReports class],
                      [GTLAdSenseUrlChannel class],
                      [GTLAdSenseUrlChannels class],
                      nil];
  return classes;
}
#endif  // DEBUG

- (id)init {
  self = [super init];
  if (self) {
    // Version from discovery.
    self.apiVersion = @"v1.4";

    // From discovery.  Where to send JSON-RPC.
    // Turn off prettyPrint for this service to save bandwidth (especially on
    // mobile). The fetcher logging will pretty print.
    self.rpcURL = [NSURL URLWithString:@"https://www.googleapis.com/rpc?prettyPrint=false"];
  }
  return self;
}

@end
