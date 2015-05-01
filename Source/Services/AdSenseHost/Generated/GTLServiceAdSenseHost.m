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
//  GTLServiceAdSenseHost.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Host API (adsensehost/v4.1)
// Description:
//   Gives AdSense Hosts access to report generation, ad code generation, and
//   publisher management capabilities.
// Documentation:
//   https://developers.google.com/adsense/host/
// Classes:
//   GTLServiceAdSenseHost (0 custom class methods, 0 custom properties)

#import "GTLAdSenseHost.h"

@implementation GTLServiceAdSenseHost

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = @[
    [GTLQueryAdSenseHost class],
    [GTLAdSenseHostAccount class],
    [GTLAdSenseHostAccounts class],
    [GTLAdSenseHostAdClient class],
    [GTLAdSenseHostAdClients class],
    [GTLAdSenseHostAdCode class],
    [GTLAdSenseHostAdStyle class],
    [GTLAdSenseHostAdUnit class],
    [GTLAdSenseHostAdUnits class],
    [GTLAdSenseHostAssociationSession class],
    [GTLAdSenseHostCustomChannel class],
    [GTLAdSenseHostCustomChannels class],
    [GTLAdSenseHostReport class],
    [GTLAdSenseHostUrlChannel class],
    [GTLAdSenseHostUrlChannels class]
  ];
  return classes;
}
#endif  // DEBUG

- (instancetype)init {
  self = [super init];
  if (self) {
    // Version from discovery.
    self.apiVersion = @"v4.1";

    // From discovery.  Where to send JSON-RPC.
    // Turn off prettyPrint for this service to save bandwidth (especially on
    // mobile). The fetcher logging will pretty print.
    self.rpcURL = [NSURL URLWithString:@"https://www.googleapis.com/rpc?prettyPrint=false"];
  }
  return self;
}

@end
