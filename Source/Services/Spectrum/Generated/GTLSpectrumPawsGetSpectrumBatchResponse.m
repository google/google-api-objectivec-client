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
//  GTLSpectrumPawsGetSpectrumBatchResponse.m
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
//   GTLSpectrumPawsGetSpectrumBatchResponse (0 custom class methods, 11 custom properties)

#import "GTLSpectrumPawsGetSpectrumBatchResponse.h"

#import "GTLSpectrumDbUpdateSpec.h"
#import "GTLSpectrumDeviceDescriptor.h"
#import "GTLSpectrumGeoSpectrumSchedule.h"
#import "GTLSpectrumRulesetInfo.h"

// ----------------------------------------------------------------------------
//
//   GTLSpectrumPawsGetSpectrumBatchResponse
//

@implementation GTLSpectrumPawsGetSpectrumBatchResponse
@dynamic databaseChange, deviceDesc, geoSpectrumSchedules, kind,
         maxContiguousBwHz, maxTotalBwHz, needsSpectrumReport, rulesetInfo,
         timestamp, type, version;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLSpectrumGeoSpectrumSchedule class]
                                forKey:@"geoSpectrumSchedules"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"spectrum#pawsGetSpectrumBatchResponse"];
}

@end
