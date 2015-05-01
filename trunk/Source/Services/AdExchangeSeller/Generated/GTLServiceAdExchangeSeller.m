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
//  GTLServiceAdExchangeSeller.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Ad Exchange Seller API (adexchangeseller/v2.0)
// Description:
//   Gives Ad Exchange seller users access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://developers.google.com/ad-exchange/seller-rest/
// Classes:
//   GTLServiceAdExchangeSeller (0 custom class methods, 0 custom properties)

#import "GTLAdExchangeSeller.h"

@implementation GTLServiceAdExchangeSeller

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = @[
    [GTLQueryAdExchangeSeller class],
    [GTLAdExchangeSellerAccount class],
    [GTLAdExchangeSellerAccounts class],
    [GTLAdExchangeSellerAdClient class],
    [GTLAdExchangeSellerAdClients class],
    [GTLAdExchangeSellerAlert class],
    [GTLAdExchangeSellerAlerts class],
    [GTLAdExchangeSellerCustomChannel class],
    [GTLAdExchangeSellerCustomChannels class],
    [GTLAdExchangeSellerMetadata class],
    [GTLAdExchangeSellerPreferredDeal class],
    [GTLAdExchangeSellerPreferredDeals class],
    [GTLAdExchangeSellerReport class],
    [GTLAdExchangeSellerReportingMetadataEntry class],
    [GTLAdExchangeSellerSavedReport class],
    [GTLAdExchangeSellerSavedReports class],
    [GTLAdExchangeSellerUrlChannel class],
    [GTLAdExchangeSellerUrlChannels class]
  ];
  return classes;
}
#endif  // DEBUG

- (instancetype)init {
  self = [super init];
  if (self) {
    // Version from discovery.
    self.apiVersion = @"v2.0";

    // From discovery.  Where to send JSON-RPC.
    // Turn off prettyPrint for this service to save bandwidth (especially on
    // mobile). The fetcher logging will pretty print.
    self.rpcURL = [NSURL URLWithString:@"https://www.googleapis.com/rpc?prettyPrint=false"];
  }
  return self;
}

@end
