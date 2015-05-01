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
//  GTLSpectrumGeoSpectrumSchedule.m
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
//   GTLSpectrumGeoSpectrumSchedule (0 custom class methods, 2 custom properties)

#import "GTLSpectrumGeoSpectrumSchedule.h"

#import "GTLSpectrumGeoLocation.h"
#import "GTLSpectrumSchedule.h"

// ----------------------------------------------------------------------------
//
//   GTLSpectrumGeoSpectrumSchedule
//

@implementation GTLSpectrumGeoSpectrumSchedule
@dynamic location, spectrumSchedules;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"spectrumSchedules" : [GTLSpectrumSchedule class]
  };
  return map;
}

@end
