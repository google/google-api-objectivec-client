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
//  GTLAnalyticsProfile.h
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
//   GTLAnalyticsProfile (0 custom class methods, 17 custom properties)
//   GTLAnalyticsProfileChildLink (0 custom class methods, 2 custom properties)
//   GTLAnalyticsProfileParentLink (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsProfileChildLink;
@class GTLAnalyticsProfileParentLink;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsProfile
//

// JSON template for an Analytics profile.

@interface GTLAnalyticsProfile : GTLObject

// Account ID to which this profile belongs.
@property (copy) NSString *accountId;

// Child link for this profile. Points to the list of goals for this profile.
@property (retain) GTLAnalyticsProfileChildLink *childLink;

// Time this profile was created.
@property (retain) GTLDateTime *created;

// The currency type associated with this profile.
@property (copy) NSString *currency;

// Default page for this profile.
@property (copy) NSString *defaultPage;

// The query parameters that are excluded from this profile.
@property (copy) NSString *excludeQueryParameters;

// Profile ID.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Internal ID for the web property to which this profile belongs.
@property (copy) NSString *internalWebPropertyId;

// Resource type for Analytics profile.
@property (copy) NSString *kind;

// Name of this profile.
@property (copy) NSString *name;

// Parent link for this profile. Points to the web property to which this
// profile belongs.
@property (retain) GTLAnalyticsProfileParentLink *parentLink;

// Link for this profile.
@property (copy) NSString *selfLink;

// Site search category parameters for this profile.
@property (copy) NSString *siteSearchCategoryParameters;

// The site search query parameters for this profile.
@property (copy) NSString *siteSearchQueryParameters;

// Time zone for which this profile has been configured.
@property (copy) NSString *timezone;

// Time this profile was last modified.
@property (retain) GTLDateTime *updated;

// Web property ID of the form UA-XXXXX-YY to which this profile belongs.
@property (copy) NSString *webPropertyId;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsProfileChildLink
//

@interface GTLAnalyticsProfileChildLink : GTLObject

// Link to the list of goals for this profile.
@property (copy) NSString *href;

// Value is "analytics#goals".
@property (copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsProfileParentLink
//

@interface GTLAnalyticsProfileParentLink : GTLObject

// Link to the web property to which this profile belongs.
@property (copy) NSString *href;

// Value is "analytics#webproperty".
@property (copy) NSString *type;

@end
