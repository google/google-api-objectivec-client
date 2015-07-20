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
//  GTLWebmastersConstants.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Webmaster Tools API (webmasters/v3)
// Description:
//   Lets you view Google Webmaster Tools data for your verified sites.
// Documentation:
//   https://developers.google.com/webmaster-tools/

#import "GTLWebmastersConstants.h"

// Authorization scope
NSString * const kGTLAuthScopeWebmasters         = @"https://www.googleapis.com/auth/webmasters";
NSString * const kGTLAuthScopeWebmastersReadonly = @"https://www.googleapis.com/auth/webmasters.readonly";

// GTLQueryWebmasters - Category
NSString * const kGTLWebmastersCategoryAuthPermissions   = @"authPermissions";
NSString * const kGTLWebmastersCategoryManyToOneRedirect = @"manyToOneRedirect";
NSString * const kGTLWebmastersCategoryNotFollowed       = @"notFollowed";
NSString * const kGTLWebmastersCategoryNotFound          = @"notFound";
NSString * const kGTLWebmastersCategoryOther             = @"other";
NSString * const kGTLWebmastersCategoryRoboted           = @"roboted";
NSString * const kGTLWebmastersCategoryServerError       = @"serverError";
NSString * const kGTLWebmastersCategorySoft404           = @"soft404";

// GTLQueryWebmasters - Platform
NSString * const kGTLWebmastersPlatformMobile         = @"mobile";
NSString * const kGTLWebmastersPlatformSmartphoneOnly = @"smartphoneOnly";
NSString * const kGTLWebmastersPlatformWeb            = @"web";
