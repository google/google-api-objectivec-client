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
//  GTLAnalyticsConstants.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Analytics API (analytics/v3)
// Description:
//   View and manage your Google Analytics data
// Documentation:
//   https://developers.google.com/analytics/

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// View and manage your Google Analytics data
GTL_EXTERN NSString * const kGTLAuthScopeAnalytics;             // "https://www.googleapis.com/auth/analytics"
// Edit Google Analytics management entities
GTL_EXTERN NSString * const kGTLAuthScopeAnalyticsEdit;         // "https://www.googleapis.com/auth/analytics.edit"
// Manage Google Analytics Account users by email address
GTL_EXTERN NSString * const kGTLAuthScopeAnalyticsManageUsers;  // "https://www.googleapis.com/auth/analytics.manage.users"
// View your Google Analytics data
GTL_EXTERN NSString * const kGTLAuthScopeAnalyticsReadonly;     // "https://www.googleapis.com/auth/analytics.readonly"

// Output
GTL_EXTERN NSString * const kGTLAnalyticsOutputDataTable;  // "dataTable"
GTL_EXTERN NSString * const kGTLAnalyticsOutputJson;       // "json"

// SamplingLevel
GTL_EXTERN NSString * const kGTLAnalyticsSamplingLevelDefault;  // "DEFAULT"
GTL_EXTERN NSString * const kGTLAnalyticsSamplingLevelFaster;   // "FASTER"
GTL_EXTERN NSString * const kGTLAnalyticsSamplingLevelHigherPrecision;  // "HIGHER_PRECISION"

// Type
GTL_EXTERN NSString * const kGTLAnalyticsTypeCost;  // "cost"
