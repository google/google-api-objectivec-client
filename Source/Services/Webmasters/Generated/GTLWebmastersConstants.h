/* Copyright (c) 2016 Google Inc.
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
//  GTLWebmastersConstants.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Search Console API (webmasters/v3)
// Description:
//   View Google Search Console data for your verified sites.
// Documentation:
//   https://developers.google.com/webmaster-tools/

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// View and manage Search Console data for your verified sites
GTL_EXTERN NSString * const kGTLAuthScopeWebmasters;          // "https://www.googleapis.com/auth/webmasters"
// View Search Console data for your verified sites
GTL_EXTERN NSString * const kGTLAuthScopeWebmastersReadonly;  // "https://www.googleapis.com/auth/webmasters.readonly"

// GTLQueryWebmasters - Category
GTL_EXTERN NSString * const kGTLWebmastersCategoryAuthPermissions;  // "authPermissions"
GTL_EXTERN NSString * const kGTLWebmastersCategoryFlashContent;  // "flashContent"
GTL_EXTERN NSString * const kGTLWebmastersCategoryManyToOneRedirect;  // "manyToOneRedirect"
GTL_EXTERN NSString * const kGTLWebmastersCategoryNotFollowed;  // "notFollowed"
GTL_EXTERN NSString * const kGTLWebmastersCategoryNotFound;     // "notFound"
GTL_EXTERN NSString * const kGTLWebmastersCategoryOther;        // "other"
GTL_EXTERN NSString * const kGTLWebmastersCategoryRoboted;      // "roboted"
GTL_EXTERN NSString * const kGTLWebmastersCategoryServerError;  // "serverError"
GTL_EXTERN NSString * const kGTLWebmastersCategorySoft404;      // "soft404"

// GTLQueryWebmasters - Platform
GTL_EXTERN NSString * const kGTLWebmastersPlatformMobile;       // "mobile"
GTL_EXTERN NSString * const kGTLWebmastersPlatformSmartphoneOnly;  // "smartphoneOnly"
GTL_EXTERN NSString * const kGTLWebmastersPlatformWeb;          // "web"
