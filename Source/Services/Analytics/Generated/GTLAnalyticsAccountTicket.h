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
//  GTLAnalyticsAccountTicket.h
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
//   GTLAnalyticsAccountTicket (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsAccount;
@class GTLAnalyticsProfile;
@class GTLAnalyticsWebproperty;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsAccountTicket
//

// JSON template for an Analytics account ticket. The account ticket consists of
// the ticket ID and the basic information for the account, property and
// profile.

@interface GTLAnalyticsAccountTicket : GTLObject

// Account for this ticket.
@property (retain) GTLAnalyticsAccount *account;

// Account ticket ID used to access the account ticket.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Resource type for account ticket.
@property (copy) NSString *kind;

// View (Profile) for the account.
@property (retain) GTLAnalyticsProfile *profile;

// Redirect URI where the user will be sent after accepting Terms of Service.
// Must be configured in APIs console as a callback URL.
@property (copy) NSString *redirectUri;

// Web property for the account.
@property (retain) GTLAnalyticsWebproperty *webproperty;

@end
