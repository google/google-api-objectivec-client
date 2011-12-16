/* Copyright (c) 2011 Google Inc.
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
//  GTLAdsenseAdUnit.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Management API (adsense/v1.1)
// Description:
//   Gives AdSense publishers access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://code.google.com/apis/adsense/management/
// Classes:
//   GTLAdsenseAdUnit (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLAdsenseAdUnit
//

@interface GTLAdsenseAdUnit : GTLObject

// Identity code of this ad unit, not necessarily unique across ad clients.
@property (copy) NSString *code;

// Unique identifier of this ad unit. This should be considered an opaque
// identifier; it is not safe to rely on it being in any particular format.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Kind of resource this is, in this case adsense#adUnit.
@property (copy) NSString *kind;

// Name of this ad unit.
@property (copy) NSString *name;

// Status of this ad unit. Possible values are:
// NEW: Indicates that the ad unit was created within the last seven days and
// does not yet have any activity associated with it.
// ACTIVE: Indicates that there has been activity on this ad unit in the last
// seven days.
// INACTIVE: Indicates that there has been no activity on this ad unit in the
// last seven days.
@property (copy) NSString *status;

@end
