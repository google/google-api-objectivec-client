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
//  GTLSpectrumRulesetInfo.h
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
//   GTLSpectrumRulesetInfo (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLSpectrumRulesetInfo
//

// This contains parameters for the ruleset of a regulatory domain that is
// communicated using the initialization and available-spectrum processes.

@interface GTLSpectrumRulesetInfo : GTLObject

// The regulatory domain to which the ruleset belongs is required. It must be a
// 2-letter country code. The device should use this to determine additional
// device behavior required by the associated regulatory domain.
@property (nonatomic, copy) NSString *authority;

// The maximum location change in meters is required in the initialization
// response, but optional otherwise. When the device changes location by more
// than this specified distance, it must contact the database to get the
// available spectrum for the new location. If the device is using spectrum that
// is no longer available, it must immediately cease use of the spectrum under
// rules for database-managed spectrum. If this value is provided within the
// context of an available-spectrum response, it takes precedence over the value
// within the initialization response.
@property (nonatomic, retain) NSNumber *maxLocationChange;  // doubleValue

// The maximum duration, in seconds, between requests for available spectrum. It
// is required in the initialization response, but optional otherwise. The
// device must contact the database to get available spectrum no less frequently
// than this duration. If the new spectrum information indicates that the device
// is using spectrum that is no longer available, it must immediately cease use
// of those frequencies under rules for database-managed spectrum. If this value
// is provided within the context of an available-spectrum response, it takes
// precedence over the value within the initialization response.
@property (nonatomic, retain) NSNumber *maxPollingSecs;  // intValue

// The identifiers of the rulesets supported for the device's location. The
// database should include at least one applicable ruleset in the initialization
// response. The device may use the ruleset identifiers to determine parameters
// to include in subsequent requests. Within the context of the
// available-spectrum responses, the database should include the identifier of
// the ruleset that it used to determine the available-spectrum response. If
// included, the device must use the specified ruleset to interpret the
// response. If the device does not support the indicated ruleset, it must not
// operate in the spectrum governed by the ruleset.
@property (nonatomic, retain) NSArray *rulesetIds;  // of NSString

@end
