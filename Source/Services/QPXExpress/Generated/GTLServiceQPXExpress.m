/* Copyright (c) 2014 Google Inc.
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
//  GTLServiceQPXExpress.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   QPX Express API (qpxExpress/v1)
// Description:
//   Lets you find the least expensive flights between an origin and a
//   destination.
// Documentation:
//   http://developers.google.com/qpx-express
// Classes:
//   GTLServiceQPXExpress (0 custom class methods, 0 custom properties)

#import "GTLQPXExpress.h"

@implementation GTLServiceQPXExpress

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = [NSArray arrayWithObjects:
                      [GTLQueryQPXExpress class],
                      [GTLQPXExpressAircraftData class],
                      [GTLQPXExpressAirportData class],
                      [GTLQPXExpressBagDescriptor class],
                      [GTLQPXExpressCarrierData class],
                      [GTLQPXExpressCityData class],
                      [GTLQPXExpressData class],
                      [GTLQPXExpressFareInfo class],
                      [GTLQPXExpressFlightInfo class],
                      [GTLQPXExpressFreeBaggageAllowance class],
                      [GTLQPXExpressLegInfo class],
                      [GTLQPXExpressPassengerCounts class],
                      [GTLQPXExpressPricingInfo class],
                      [GTLQPXExpressSegmentInfo class],
                      [GTLQPXExpressSegmentPricing class],
                      [GTLQPXExpressSliceInfo class],
                      [GTLQPXExpressSliceInput class],
                      [GTLQPXExpressTaxData class],
                      [GTLQPXExpressTaxInfo class],
                      [GTLQPXExpressTimeOfDayRange class],
                      [GTLQPXExpressTripOption class],
                      [GTLQPXExpressTripOptionsRequest class],
                      [GTLQPXExpressTripOptionsResponse class],
                      [GTLQPXExpressTripsSearchResponse class],
                      nil];
  return classes;
}
#endif  // DEBUG

- (id)init {
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
