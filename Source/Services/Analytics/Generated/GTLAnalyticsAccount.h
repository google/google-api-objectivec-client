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
//  GTLAnalyticsAccount.h
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
//   GTLAnalyticsAccount (0 custom class methods, 8 custom properties)
//   GTLAnalyticsAccountChildLink (0 custom class methods, 2 custom properties)
//   GTLAnalyticsAccountPermissions (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsAccountChildLink;
@class GTLAnalyticsAccountPermissions;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsAccount
//

// JSON template for Analytics account entry.

@interface GTLAnalyticsAccount : GTLObject

// Child link for an account entry. Points to the list of web properties for
// this account.
@property (nonatomic, retain) GTLAnalyticsAccountChildLink *childLink;

// Time the account was created.
@property (nonatomic, retain) GTLDateTime *created;

// Account ID.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Resource type for Analytics account.
@property (nonatomic, copy) NSString *kind;

// Account name.
@property (nonatomic, copy) NSString *name;

// Permissions the user has for this account.
@property (nonatomic, retain) GTLAnalyticsAccountPermissions *permissions;

// Link for this account.
@property (nonatomic, copy) NSString *selfLink;

// Time the account was last modified.
@property (nonatomic, retain) GTLDateTime *updated;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsAccountChildLink
//

@interface GTLAnalyticsAccountChildLink : GTLObject

// Link to the list of web properties for this account.
@property (nonatomic, copy) NSString *href;

// Type of the child link. Its value is "analytics#webproperties".
@property (nonatomic, copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsAccountPermissions
//

@interface GTLAnalyticsAccountPermissions : GTLObject

// All the permissions that the user has for this account. These include any
// implied permissions (e.g., EDIT implies VIEW).
@property (nonatomic, retain) NSArray *effective;  // of NSString

@end
