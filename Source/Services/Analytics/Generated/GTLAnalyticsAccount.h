/* Copyright (c) 2012 Google Inc.
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
//  GTLAnalyticsAccount.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Analytics API (analytics/v3)
// Description:
//   View and manage your Google Analytics data
// Documentation:
//   http://code.google.com/apis/analytics
// Classes:
//   GTLAnalyticsAccount (0 custom class methods, 7 custom properties)
//   GTLAnalyticsAccountChildLink (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsAccountChildLink;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsAccount
//

// JSON template for Analytics account entry.

@interface GTLAnalyticsAccount : GTLObject

// Child link for an account entry. Points to the list of web properties for
// this account.
@property (retain) GTLAnalyticsAccountChildLink *childLink;

// Time the account was created.
@property (retain) GTLDateTime *created;

// Account ID.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Resource type for Analytics account.
@property (copy) NSString *kind;

// Account name.
@property (copy) NSString *name;

// Link for this account.
@property (copy) NSString *selfLink;

// Time the account was last modified.
@property (retain) GTLDateTime *updated;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsAccountChildLink
//

@interface GTLAnalyticsAccountChildLink : GTLObject

// Link to the list of web properties for this account.
@property (copy) NSString *href;

// Type of the child link. Its value is "analytics#webproperties".
@property (copy) NSString *type;

@end
