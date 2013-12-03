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
//  GTLServiceSpectrum.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Spectrum Database API (spectrum/v1explorer)
// Description:
//   API for spectrum-management functions.
// Documentation:
//   http://developers.google.com/spectrum
// Classes:
//   GTLServiceSpectrum (0 custom class methods, 0 custom properties)

#import "GTLSpectrum.h"

@implementation GTLServiceSpectrum

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = [NSArray arrayWithObjects:
                      [GTLQuerySpectrum class],
                      [GTLSpectrumAntennaCharacteristics class],
                      [GTLSpectrumDatabaseSpec class],
                      [GTLSpectrumDbUpdateSpec class],
                      [GTLSpectrumDeviceCapabilities class],
                      [GTLSpectrumDeviceDescriptor class],
                      [GTLSpectrumDeviceOwner class],
                      [GTLSpectrumDeviceValidity class],
                      [GTLSpectrumEventTime class],
                      [GTLSpectrumFrequencyRange class],
                      [GTLSpectrumGeoLocation class],
                      [GTLSpectrumGeoLocationEllipse class],
                      [GTLSpectrumGeoLocationPoint class],
                      [GTLSpectrumGeoLocationPolygon class],
                      [GTLSpectrumGeoSpectrumSchedule class],
                      [GTLSpectrumMessage class],
                      [GTLSpectrumPawsGetSpectrumBatchResponse class],
                      [GTLSpectrumPawsGetSpectrumResponse class],
                      [GTLSpectrumPawsInitResponse class],
                      [GTLSpectrumPawsNotifySpectrumUseResponse class],
                      [GTLSpectrumPawsRegisterResponse class],
                      [GTLSpectrumPawsVerifyDeviceResponse class],
                      [GTLSpectrumRulesetInfo class],
                      [GTLSpectrumSchedule class],
                      [GTLSpectrumVcard class],
                      [GTLSpectrumVcardAddress class],
                      [GTLSpectrumVcardTelephone class],
                      [GTLSpectrumVcardTypedText class],
                      nil];
  return classes;
}
#endif  // DEBUG

- (id)init {
  self = [super init];
  if (self) {
    // Version from discovery.
    self.apiVersion = @"v1explorer";

    // From discovery.  Where to send JSON-RPC.
    // Turn off prettyPrint for this service to save bandwidth (especially on
    // mobile). The fetcher logging will pretty print.
    self.rpcURL = [NSURL URLWithString:@"https://www.googleapis.com/rpc?prettyPrint=false"];
  }
  return self;
}

@end
