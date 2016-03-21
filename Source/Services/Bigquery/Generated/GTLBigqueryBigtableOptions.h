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
//  GTLBigqueryBigtableOptions.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   BigQuery API (bigquery/v2)
// Description:
//   A data platform for customers to create, manage, share and query data.
// Documentation:
//   https://cloud.google.com/bigquery/
// Classes:
//   GTLBigqueryBigtableOptions (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryBigtableColumnFamily;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryBigtableOptions
//

@interface GTLBigqueryBigtableOptions : GTLObject

// [Optional] List of column families to expose in the table schema along with
// their types. This list restricts the column families that can be referenced
// in queries and specifies their value types. You can use this list to do type
// conversions - see the 'type' field for more details. If you leave this list
// empty, all column families are present in the table schema and their values
// are read as BYTES. During a query only the column families referenced in that
// query are read from Bigtable.
@property (nonatomic, retain) NSArray *columnFamilies;  // of GTLBigqueryBigtableColumnFamily

// [Optional] If field is true, then the column families that are not specified
// in columnFamilies list are not exposed in the table schema. Otherwise, they
// are read with BYTES type values. The default value is false.
@property (nonatomic, retain) NSNumber *ignoreUnspecifiedColumnFamilies;  // boolValue

@end
