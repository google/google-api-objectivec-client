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
//  GTLAnalyticsProfileFilterLink.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Analytics API (analytics/v3)
// Description:
//   View and manage your Google Analytics data
// Documentation:
//   https://developers.google.com/analytics/
// Classes:
//   GTLAnalyticsProfileFilterLink (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsFilterRef;
@class GTLAnalyticsProfileRef;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsProfileFilterLink
//

// JSON template for an Analytics profile filter link.

@interface GTLAnalyticsProfileFilterLink : GTLObject

// Filter for this link.
@property (retain) GTLAnalyticsFilterRef *filterRef;

// Profile filter link ID.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Resource type for Analytics filter.
@property (copy) NSString *kind;

// View (Profile) for this link.
@property (retain) GTLAnalyticsProfileRef *profileRef;

// The rank of this profile filter link relative to the other filters linked to
// the same profile.
// For readonly (i.e., list and get) operations, the rank always starts at 1.
// For write (i.e., create, update, or delete) operations, you may specify a
// value between 0 and 255 inclusively, [0, 255]. In order to insert a link at
// the end of the list, either don't specify a rank or set a rank to a number
// greater than the largest rank in the list. In order to insert a link to the
// beginning of the list specify a rank that is less than or equal to 1. The new
// link will move all existing filters with the same or lower rank down the
// list. After the link is inserted/updated/deleted all profile filter links
// will be renumbered starting at 1.
@property (retain) NSNumber *rank;  // intValue

// Link for this profile filter link.
@property (copy) NSString *selfLink;

@end
