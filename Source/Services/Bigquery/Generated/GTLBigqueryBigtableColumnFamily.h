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
//  GTLBigqueryBigtableColumnFamily.h
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
//   GTLBigqueryBigtableColumnFamily (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryBigtableColumn;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryBigtableColumnFamily
//

@interface GTLBigqueryBigtableColumnFamily : GTLObject

// [Optional] Lists of columns that should be exposed as individual fields as
// opposed to a list of (column name, value) pairs. All columns whose qualifier
// matches a qualifier in this list can be accessed as .. Other columns can be
// accessed as a list through .Column field.
@property (nonatomic, retain) NSArray *columns;  // of GTLBigqueryBigtableColumn

// [Optional] The encoding of the values when the type is not STRING. Acceptable
// encoding values are: TEXT - indicates values are alphanumeric text strings.
// BINARY - indicates values are encoded using HBase Bytes.toBytes family of
// functions. This can be overridden for a specific column by listing that
// column in 'columns' and specifying an encoding for it.
@property (nonatomic, copy) NSString *encoding;

// Identifier of the column family.
@property (nonatomic, copy) NSString *familyId;

// [Optional] If this is set only the latest version of value are exposed for
// all columns in this column family. This can be overridden for a specific
// column by listing that column in 'columns' and specifying a different setting
// for that column.
@property (nonatomic, retain) NSNumber *onlyReadLatest;  // boolValue

// [Optional] The type to convert the value in cells of this column family. The
// values are expected to be encoded using HBase Bytes.toBytes function when
// using the BINARY encoding value. Following BigQuery types are allowed
// (case-sensitive) - BYTES STRING INTEGER FLOAT BOOLEAN Defaut type is BYTES.
// This can be overridden for a specific column by listing that column in
// 'columns' and specifying a type for it.
@property (nonatomic, copy) NSString *type;

@end
