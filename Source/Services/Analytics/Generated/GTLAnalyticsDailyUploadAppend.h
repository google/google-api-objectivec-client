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
//  GTLAnalyticsDailyUploadAppend.h
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
//   GTLAnalyticsDailyUploadAppend (0 custom class methods, 7 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsDailyUploadAppend
//

// Metadata returned for a successful append operation.

@interface GTLAnalyticsDailyUploadAppend : GTLObject

// Account Id to which this daily upload append belongs.
@property (copy) NSString *accountId;

// Append number.
@property (retain) NSNumber *appendNumber;  // intValue

// Custom data source Id to which this daily upload append belongs.
@property (copy) NSString *customDataSourceId;

// Date associated with daily upload append.
@property (copy) NSString *date;

// Resource type for Analytics daily upload append.
@property (copy) NSString *kind;

@property (copy) NSString *nextAppendLink;

// Web property Id of the form UA-XXXXX-YY to which this daily upload append
// belongs.
@property (copy) NSString *webPropertyId;

@end
