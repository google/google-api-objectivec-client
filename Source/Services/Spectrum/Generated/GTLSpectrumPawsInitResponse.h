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
//  GTLSpectrumPawsInitResponse.h
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
//   GTLSpectrumPawsInitResponse (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSpectrumDbUpdateSpec;
@class GTLSpectrumRulesetInfo;

// ----------------------------------------------------------------------------
//
//   GTLSpectrumPawsInitResponse
//

// The initialization response message communicates database parameters to the
// requesting device.

@interface GTLSpectrumPawsInitResponse : GTLObject

// A database may include the databaseChange parameter to notify a device of a
// change to its database URI, providing one or more alternate database URIs.
// The device should use this information to update its list of pre-configured
// databases by (only) replacing its entry for the responding database with the
// list of alternate URIs.
@property (retain) GTLSpectrumDbUpdateSpec *databaseChange;

// Identifies what kind of resource this is. Value: the fixed string
// "spectrum#pawsInitResponse".
@property (copy) NSString *kind;

// The rulesetInfo parameter must be included in the response. This parameter
// specifies the regulatory domain and parameters applicable to that domain. The
// database must include the authority field, which defines the regulatory
// domain for the location specified in the INIT_REQ message.
@property (retain) GTLSpectrumRulesetInfo *rulesetInfo;

// The message type (e.g., INIT_REQ, AVAIL_SPECTRUM_REQ, ...).
// Required field.
@property (copy) NSString *type;

// The PAWS version. Must be exactly 1.0.
// Required field.
@property (copy) NSString *version;

@end
