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
//  GTLLatitudeConstants.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Latitude API (latitude/v1)
// Description:
//   Lets you read and update your current location and work with your location
//   history
// Documentation:
//   https://developers.google.com/latitude/v1/using

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// Manage your best-available location and location history
GTL_EXTERN NSString * const kGTLAuthScopeLatitudeAllBest;      // "https://www.googleapis.com/auth/latitude.all.best"
// Manage your city-level location and location history
GTL_EXTERN NSString * const kGTLAuthScopeLatitudeAllCity;      // "https://www.googleapis.com/auth/latitude.all.city"
// Manage your best-available location
GTL_EXTERN NSString * const kGTLAuthScopeLatitudeCurrentBest;  // "https://www.googleapis.com/auth/latitude.current.best"
// Manage your city-level location
GTL_EXTERN NSString * const kGTLAuthScopeLatitudeCurrentCity;  // "https://www.googleapis.com/auth/latitude.current.city"

// Granularity
GTL_EXTERN NSString * const kGTLLatitudeGranularityBest;  // "best"
GTL_EXTERN NSString * const kGTLLatitudeGranularityCity;  // "city"
