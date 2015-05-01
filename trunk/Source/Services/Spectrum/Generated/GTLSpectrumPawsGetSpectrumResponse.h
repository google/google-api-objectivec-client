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
//  GTLSpectrumPawsGetSpectrumResponse.h
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
//   GTLSpectrumPawsGetSpectrumResponse (0 custom class methods, 11 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSpectrumDbUpdateSpec;
@class GTLSpectrumDeviceDescriptor;
@class GTLSpectrumRulesetInfo;
@class GTLSpectrumSchedule;

// ----------------------------------------------------------------------------
//
//   GTLSpectrumPawsGetSpectrumResponse
//

// The response message for the available spectrum query which contains a
// schedule of available spectrum for the device.

@interface GTLSpectrumPawsGetSpectrumResponse : GTLObject

// A database may include the databaseChange parameter to notify a device of a
// change to its database URI, providing one or more alternate database URIs.
// The device should use this information to update its list of pre-configured
// databases by (only) replacing its entry for the responding database with the
// list of alternate URIs.
@property (nonatomic, retain) GTLSpectrumDbUpdateSpec *databaseChange;

// The database must return, in its available spectrum response, the device
// descriptor information it received in the master device's available spectrum
// request.
@property (nonatomic, retain) GTLSpectrumDeviceDescriptor *deviceDesc;

// Identifies what kind of resource this is. Value: the fixed string
// "spectrum#pawsGetSpectrumResponse".
@property (nonatomic, copy) NSString *kind;

// The database may return a constraint on the allowed maximum contiguous
// bandwidth (in Hertz). A regulatory domain may require the database to return
// this parameter. When this parameter is present in the response, the device
// must apply this constraint to its spectrum-selection logic to ensure that no
// single block of spectrum has bandwidth that exceeds this value.
@property (nonatomic, retain) NSNumber *maxContiguousBwHz;  // doubleValue

// The database may return a constraint on the allowed maximum total bandwidth
// (in Hertz), which need not be contiguous. A regulatory domain may require the
// database to return this parameter. When this parameter is present in the
// available spectrum response, the device must apply this constraint to its
// spectrum-selection logic to ensure that total bandwidth does not exceed this
// value.
@property (nonatomic, retain) NSNumber *maxTotalBwHz;  // doubleValue

// For regulatory domains that require a spectrum-usage report from devices, the
// database must return true for this parameter if the spectrum schedule list is
// not empty; otherwise, the database will either return false or omit this
// parameter. If this parameter is present and its value is true, the device
// must send a spectrum use notify message to the database; otherwise, the
// device must not send the notification.
@property (nonatomic, retain) NSNumber *needsSpectrumReport;  // boolValue

// The database should return ruleset information, which identifies the
// applicable regulatory authority and ruleset for the available spectrum
// response. If included, the device must use the corresponding ruleset to
// interpret the response. Values provided in the returned ruleset information,
// such as maxLocationChange, take precedence over any conflicting values
// provided in the ruleset information returned in a prior initialization
// response sent by the database to the device.
@property (nonatomic, retain) GTLSpectrumRulesetInfo *rulesetInfo;

// The available spectrum response must contain a spectrum schedule list. The
// list may be empty if spectrum is not available. The database may return more
// than one spectrum schedule to represent future changes to the available
// spectrum. How far in advance a schedule may be provided depends on the
// applicable regulatory domain.
@property (nonatomic, retain) NSArray *spectrumSchedules;  // of GTLSpectrumSchedule

// The database includes a timestamp of the form YYYY-MM-DDThh:mm:ssZ (Internet
// timestamp format per RFC3339) in its available spectrum response. The
// timestamp should be used by the device as a reference for the start and stop
// times specified in the response spectrum schedules.
@property (nonatomic, copy) NSString *timestamp;

// The message type (e.g., INIT_REQ, AVAIL_SPECTRUM_REQ, ...).
// Required field.
@property (nonatomic, copy) NSString *type;

// The PAWS version. Must be exactly 1.0.
// Required field.
@property (nonatomic, copy) NSString *version;

@end
