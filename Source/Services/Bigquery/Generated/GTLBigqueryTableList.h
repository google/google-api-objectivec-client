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
//  GTLBigqueryTableList.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   BigQuery API (bigquery/v2)
// Description:
//   A data platform for customers to create, manage, share and query data.
// Documentation:
//   https://developers.google.com/bigquery/docs/overview
// Classes:
//   GTLBigqueryTableList (0 custom class methods, 5 custom properties)
//   GTLBigqueryTableListTablesItem (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryTableListTablesItem;
@class GTLBigqueryTableReference;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryTableList
//

@interface GTLBigqueryTableList : GTLObject

// A hash of this page of results.
@property (copy) NSString *ETag;

// The type of list.
@property (copy) NSString *kind;

// A token to request the next page of results.
@property (copy) NSString *nextPageToken;

// Tables in the requested dataset.
@property (retain) NSArray *tables;  // of GTLBigqueryTableListTablesItem

// The total number of tables in the dataset.
@property (retain) NSNumber *totalItems;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLBigqueryTableListTablesItem
//

@interface GTLBigqueryTableListTablesItem : GTLObject

// The user-friendly name for this table.
@property (copy) NSString *friendlyName;

// An opaque ID of the table
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The resource type.
@property (copy) NSString *kind;

// A reference uniquely identifying the table.
@property (retain) GTLBigqueryTableReference *tableReference;

// The type of table. Possible values are: TABLE, VIEW.
@property (copy) NSString *type;

@end
