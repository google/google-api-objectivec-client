/* Copyright (c) 2011 Google Inc.
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
//  GTLPlusConstants.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   plus/v1
// Description:
//   Google+ API

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// View your Google+ information
GTL_EXTERN NSString * const kGTLAuthScopePlusMe;                // "https://www.googleapis.com/auth/plus.me"
// View a list of people from your circles, ordered based on your interactions
// with them across Google
GTL_EXTERN NSString * const kGTLAuthScopePlusPeopleRecommended;  // "https://www.googleapis.com/auth/plus.people.recommended"

// Alt
GTL_EXTERN NSString * const kGTLPlusAltJson;  // "json"

// Collection
GTL_EXTERN NSString * const kGTLPlusCollectionPublic;  // "public"
