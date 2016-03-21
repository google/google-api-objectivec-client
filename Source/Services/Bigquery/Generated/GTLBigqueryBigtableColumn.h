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
//  GTLBigqueryBigtableColumn.h
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
//   GTLBigqueryBigtableColumn (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLBigqueryBigtableColumn
//

@interface GTLBigqueryBigtableColumn : GTLObject

// [Optional] The encoding of the values when the type is not STRING. Acceptable
// encoding values are: TEXT - indicates values are alphanumeric text strings.
// BINARY - indicates values are encoded using HBase Bytes.toBytes family of
// functions. 'encoding' can also be set at the column family level. However,
// the setting at this level takes precedence if 'encoding' is set at both
// levels.
@property (nonatomic, copy) NSString *encoding;

// [Optional] If the qualifier is not a valid BigQuery field identifier i.e.
// does not match [a-zA-Z][a-zA-Z0-9_]*, a valid identifier must be provided as
// the column field name and is used as field name in queries.
@property (nonatomic, copy) NSString *fieldName;

// [Optional] If this is set, only the latest version of value in this column
// are exposed. 'onlyReadLatest' can also be set at the column family level.
// However, the setting at this level takes precedence if 'onlyReadLatest' is
// set at both levels.
@property (nonatomic, retain) NSNumber *onlyReadLatest;  // boolValue

// [Required] Qualifier of the column. Columns in the parent column family that
// has this exact qualifier are exposed as . field. If the qualifier is valid
// UTF-8 string, it can be specified in the qualifier_string field. Otherwise, a
// base-64 encoded value must be set to qualifier_encoded. The column field name
// is the same as the column qualifier. However, if the qualifier is not a valid
// BigQuery field identifier i.e. does not match [a-zA-Z][a-zA-Z0-9_]*, a valid
// identifier must be provided as field_name.
@property (nonatomic, copy) NSString *qualifierEncoded;  // GTLBase64 can encode/decode (probably web-safe format)

@property (nonatomic, copy) NSString *qualifierString;

// [Optional] The type to convert the value in cells of this column. The values
// are expected to be encoded using HBase Bytes.toBytes function when using the
// BINARY encoding value. Following BigQuery types are allowed (case-sensitive)
// - BYTES STRING INTEGER FLOAT BOOLEAN Defaut type is BYTES. 'type' can also be
// set at the column family level. However, the setting at this level takes
// precedence if 'type' is set at both levels.
@property (nonatomic, copy) NSString *type;

@end
