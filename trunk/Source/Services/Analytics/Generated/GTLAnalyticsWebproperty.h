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
//  GTLAnalyticsWebproperty.h
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
//   GTLAnalyticsWebproperty (0 custom class methods, 14 custom properties)
//   GTLAnalyticsWebpropertyChildLink (0 custom class methods, 2 custom properties)
//   GTLAnalyticsWebpropertyParentLink (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsWebpropertyChildLink;
@class GTLAnalyticsWebpropertyParentLink;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsWebproperty
//

// JSON template for an Analytics web property.

@interface GTLAnalyticsWebproperty : GTLObject

// Account ID to which this web property belongs.
@property (copy) NSString *accountId;

// Child link for this web property. Points to the list of views (profiles) for
// this web property.
@property (retain) GTLAnalyticsWebpropertyChildLink *childLink;

// Time this web property was created.
@property (retain) GTLDateTime *created;

// Web property ID of the form UA-XXXXX-YY.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The industry vertical/category selected for this web property.
@property (copy) NSString *industryVertical;

// Internal ID for this web property.
@property (copy) NSString *internalWebPropertyId;

// Resource type for Analytics WebProperty.
@property (copy) NSString *kind;

// Level for this web property. Possible values are STANDARD or PREMIUM.
@property (copy) NSString *level;

// Name of this web property.
@property (copy) NSString *name;

// Parent link for this web property. Points to the account to which this web
// property belongs.
@property (retain) GTLAnalyticsWebpropertyParentLink *parentLink;

// View (Profile) count for this web property.
@property (retain) NSNumber *profileCount;  // intValue

// Link for this web property.
@property (copy) NSString *selfLink;

// Time this web property was last modified.
@property (retain) GTLDateTime *updated;

// Website url for this web property.
@property (copy) NSString *websiteUrl;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsWebpropertyChildLink
//

@interface GTLAnalyticsWebpropertyChildLink : GTLObject

// Link to the list of views (profiles) for this web property.
@property (copy) NSString *href;

// Type of the parent link. Its value is "analytics#profiles".
@property (copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsWebpropertyParentLink
//

@interface GTLAnalyticsWebpropertyParentLink : GTLObject

// Link to the account for this web property.
@property (copy) NSString *href;

// Type of the parent link. Its value is "analytics#account".
@property (copy) NSString *type;

@end
