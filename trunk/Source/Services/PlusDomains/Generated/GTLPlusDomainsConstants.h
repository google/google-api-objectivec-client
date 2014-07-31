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
//  GTLPlusDomainsConstants.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google+ Domains API (plusDomains/v1)
// Description:
//   The Google+ API enables developers to build on top of the Google+ platform.
// Documentation:
//   https://developers.google.com/+/domains/

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// View your circles and the people and pages in them
GTL_EXTERN NSString * const kGTLAuthScopePlusDomainsPlusCirclesRead;  // "https://www.googleapis.com/auth/plus.circles.read"
// Manage your circles and add people and pages. People and pages you add to
// your circles will be notified. Others may see this information publicly.
// People you add to circles can use Hangouts with you.
GTL_EXTERN NSString * const kGTLAuthScopePlusDomainsPlusCirclesWrite;  // "https://www.googleapis.com/auth/plus.circles.write"
// Know your basic profile info and list of people in your circles.
GTL_EXTERN NSString * const kGTLAuthScopePlusDomainsPlusLogin;  // "https://www.googleapis.com/auth/plus.login"
// Know who you are on Google
GTL_EXTERN NSString * const kGTLAuthScopePlusDomainsPlusMe;     // "https://www.googleapis.com/auth/plus.me"
// Send your photos and videos to Google+
GTL_EXTERN NSString * const kGTLAuthScopePlusDomainsPlusMediaUpload;  // "https://www.googleapis.com/auth/plus.media.upload"
// View your own Google+ profile and profiles visible to you
GTL_EXTERN NSString * const kGTLAuthScopePlusDomainsPlusProfilesRead;  // "https://www.googleapis.com/auth/plus.profiles.read"
// View your Google+ posts, comments, and stream
GTL_EXTERN NSString * const kGTLAuthScopePlusDomainsPlusStreamRead;  // "https://www.googleapis.com/auth/plus.stream.read"
// Manage your Google+ posts, comments, and stream
GTL_EXTERN NSString * const kGTLAuthScopePlusDomainsPlusStreamWrite;  // "https://www.googleapis.com/auth/plus.stream.write"
// View your email address
GTL_EXTERN NSString * const kGTLAuthScopePlusDomainsUserinfoEmail;  // "https://www.googleapis.com/auth/userinfo.email"
// View your basic profile info
GTL_EXTERN NSString * const kGTLAuthScopePlusDomainsUserinfoProfile;  // "https://www.googleapis.com/auth/userinfo.profile"

// GTLQueryPlusDomains - Collection
GTL_EXTERN NSString * const kGTLPlusDomainsCollectionCircled;   // "circled"
GTL_EXTERN NSString * const kGTLPlusDomainsCollectionCloud;     // "cloud"
GTL_EXTERN NSString * const kGTLPlusDomainsCollectionPlusoners;  // "plusoners"
GTL_EXTERN NSString * const kGTLPlusDomainsCollectionResharers;  // "resharers"
GTL_EXTERN NSString * const kGTLPlusDomainsCollectionSharedto;  // "sharedto"
GTL_EXTERN NSString * const kGTLPlusDomainsCollectionUser;      // "user"

// GTLQueryPlusDomains - OrderBy
GTL_EXTERN NSString * const kGTLPlusDomainsOrderByAlphabetical;  // "alphabetical"
GTL_EXTERN NSString * const kGTLPlusDomainsOrderByBest;         // "best"

// GTLQueryPlusDomains - SortOrder
GTL_EXTERN NSString * const kGTLPlusDomainsSortOrderAscending;  // "ascending"
GTL_EXTERN NSString * const kGTLPlusDomainsSortOrderDescending;  // "descending"
