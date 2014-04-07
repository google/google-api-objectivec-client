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
//  GTLAnalyticsWebPropertySummary.h
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
//   GTLAnalyticsWebPropertySummary (0 custom class methods, 7 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsProfileSummary;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsWebPropertySummary
//

// JSON template for an Analytics WebPropertySummary. WebPropertySummary returns
// basic information (i.e., summary) for a web property.

@interface GTLAnalyticsWebPropertySummary : GTLObject

// Web property ID of the form UA-XXXXX-YY.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Internal ID for this web property.
@property (copy) NSString *internalWebPropertyId;

// Resource type for Analytics WebPropertySummary.
@property (copy) NSString *kind;

// Level for this web property. Possible values are STANDARD or PREMIUM.
@property (copy) NSString *level;

// Web property name.
@property (copy) NSString *name;

// List of profiles under this web property.
@property (retain) NSArray *profiles;  // of GTLAnalyticsProfileSummary

// Website url for this web property.
@property (copy) NSString *websiteUrl;

@end
