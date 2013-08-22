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
//  GTLAnalyticsColumns.h
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
//   GTLAnalyticsColumns (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsColumn;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsColumns
//

// Lists columns (dimensions and metrics) for a particular report type.

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLAnalyticsColumns : GTLCollectionObject

// List of attributes names returned by columns.
@property (retain) NSArray *attributeNames;  // of NSString

// Etag of collection. This etag can be compared with the last response etag to
// check if response has changed.
@property (copy) NSString *ETag;

// List of columns for a report type.
@property (retain) NSArray *items;  // of GTLAnalyticsColumn

// Collection type.
@property (copy) NSString *kind;

// Total number of columns returned in the response.
@property (retain) NSNumber *totalResults;  // intValue

@end
