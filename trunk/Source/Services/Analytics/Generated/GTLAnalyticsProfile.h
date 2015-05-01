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
//  GTLAnalyticsProfile.h
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
//   GTLAnalyticsProfile (0 custom class methods, 24 custom properties)
//   GTLAnalyticsProfileChildLink (0 custom class methods, 2 custom properties)
//   GTLAnalyticsProfileParentLink (0 custom class methods, 2 custom properties)
//   GTLAnalyticsProfilePermissions (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsProfileChildLink;
@class GTLAnalyticsProfileParentLink;
@class GTLAnalyticsProfilePermissions;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsProfile
//

// JSON template for an Analytics view (profile).

@interface GTLAnalyticsProfile : GTLObject

// Account ID to which this view (profile) belongs.
@property (nonatomic, copy) NSString *accountId;

// Child link for this view (profile). Points to the list of goals for this view
// (profile).
@property (nonatomic, retain) GTLAnalyticsProfileChildLink *childLink;

// Time this view (profile) was created.
@property (nonatomic, retain) GTLDateTime *created;

// The currency type associated with this view (profile). The supported values
// are:
// ARS, AUD, BGN, BRL, CAD, CHF, CNY, CZK, DKK, EUR, GBP, HKD, HUF, IDR, INR,
// JPY, KRW, LTL, MXN, NOK, NZD, PHP, PLN, RUB, SEK, THB, TRY, TWD, USD, VND,
// ZAR
@property (nonatomic, copy) NSString *currency;

// Default page for this view (profile).
@property (nonatomic, copy) NSString *defaultPage;

// Indicates whether ecommerce tracking is enabled for this view (profile).
@property (nonatomic, retain) NSNumber *eCommerceTracking;  // boolValue

// Indicates whether enhanced ecommerce tracking is enabled for this view
// (profile). This property can only be enabled if ecommerce tracking is
// enabled.
@property (nonatomic, retain) NSNumber *enhancedECommerceTracking;  // boolValue

// The query parameters that are excluded from this view (profile).
@property (nonatomic, copy) NSString *excludeQueryParameters;

// View (Profile) ID.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Internal ID for the web property to which this view (profile) belongs.
@property (nonatomic, copy) NSString *internalWebPropertyId;

// Resource type for Analytics view (profile).
@property (nonatomic, copy) NSString *kind;

// Name of this view (profile).
@property (nonatomic, copy) NSString *name;

// Parent link for this view (profile). Points to the web property to which this
// view (profile) belongs.
@property (nonatomic, retain) GTLAnalyticsProfileParentLink *parentLink;

// Permissions the user has for this view (profile).
@property (nonatomic, retain) GTLAnalyticsProfilePermissions *permissions;

// Link for this view (profile).
@property (nonatomic, copy) NSString *selfLink;

// Site search category parameters for this view (profile).
@property (nonatomic, copy) NSString *siteSearchCategoryParameters;

// The site search query parameters for this view (profile).
@property (nonatomic, copy) NSString *siteSearchQueryParameters;

// Whether or not Analytics will strip search category parameters from the URLs
// in your reports.
@property (nonatomic, retain) NSNumber *stripSiteSearchCategoryParameters;  // boolValue

// Whether or not Analytics will strip search query parameters from the URLs in
// your reports.
@property (nonatomic, retain) NSNumber *stripSiteSearchQueryParameters;  // boolValue

// Time zone for which this view (profile) has been configured. Time zones are
// identified by strings from the TZ database.
@property (nonatomic, copy) NSString *timezone;

// View (Profile) type. Supported types: WEB or APP.
@property (nonatomic, copy) NSString *type;

// Time this view (profile) was last modified.
@property (nonatomic, retain) GTLDateTime *updated;

// Web property ID of the form UA-XXXXX-YY to which this view (profile) belongs.
@property (nonatomic, copy) NSString *webPropertyId;

// Website URL for this view (profile).
@property (nonatomic, copy) NSString *websiteUrl;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsProfileChildLink
//

@interface GTLAnalyticsProfileChildLink : GTLObject

// Link to the list of goals for this view (profile).
@property (nonatomic, copy) NSString *href;

// Value is "analytics#goals".
@property (nonatomic, copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsProfileParentLink
//

@interface GTLAnalyticsProfileParentLink : GTLObject

// Link to the web property to which this view (profile) belongs.
@property (nonatomic, copy) NSString *href;

// Value is "analytics#webproperty".
@property (nonatomic, copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsProfilePermissions
//

@interface GTLAnalyticsProfilePermissions : GTLObject

// All the permissions that the user has for this view (profile). These include
// any implied permissions (e.g., EDIT implies VIEW) or inherited permissions
// from the parent web property.
@property (nonatomic, retain) NSArray *effective;  // of NSString

@end
