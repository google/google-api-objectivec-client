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
//  GTLBigqueryJobConfigurationLoad.h
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
//   GTLBigqueryJobConfigurationLoad (0 custom class methods, 16 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryTableReference;
@class GTLBigqueryTableSchema;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryJobConfigurationLoad
//

@interface GTLBigqueryJobConfigurationLoad : GTLObject

// [Optional] Accept rows that are missing trailing optional columns. The
// missing values are treated as nulls. Default is false which treats short rows
// as errors. Only applicable to CSV, ignored for other formats.
@property (retain) NSNumber *allowJaggedRows;  // boolValue

// Indicates if BigQuery should allow quoted data sections that contain newline
// characters in a CSV file. The default value is false.
@property (retain) NSNumber *allowQuotedNewlines;  // boolValue

// [Optional] Specifies whether the job is allowed to create new tables. The
// following values are supported: CREATE_IF_NEEDED: If the table does not
// exist, BigQuery creates the table. CREATE_NEVER: The table must already
// exist. If it does not, a 'notFound' error is returned in the job result. The
// default value is CREATE_IF_NEEDED. Creation, truncation and append actions
// occur as one atomic update upon job completion.
@property (copy) NSString *createDisposition;

// [Required] The destination table to load the data into.
@property (retain) GTLBigqueryTableReference *destinationTable;

// [Optional] The character encoding of the data. The supported values are UTF-8
// or ISO-8859-1. The default value is UTF-8. BigQuery decodes the data after
// the raw, binary data has been split using the values of the quote and
// fieldDelimiter properties.
@property (copy) NSString *encoding;

// [Optional] The separator for fields in a CSV file. BigQuery converts the
// string to ISO-8859-1 encoding, and then uses the first byte of the encoded
// string to split the data in its raw, binary state. BigQuery also supports the
// escape sequence "\t" to specify a tab separator. The default value is a comma
// (',').
@property (copy) NSString *fieldDelimiter;

// [Optional] Accept rows that contain values that do not match the schema. The
// unknown values are ignored. Default is false which treats unknown values as
// errors. For CSV this ignores extra values at the end of a line. For JSON this
// ignores named values that do not match any column name.
@property (retain) NSNumber *ignoreUnknownValues;  // boolValue

// [Optional] The maximum number of bad records that BigQuery can ignore when
// running the job. If the number of bad records exceeds this value, an
// 'invalid' error is returned in the job result and the job fails. The default
// value is 0, which requires that all records are valid.
@property (retain) NSNumber *maxBadRecords;  // intValue

// [Optional] The value that is used to quote data sections in a CSV file.
// BigQuery converts the string to ISO-8859-1 encoding, and then uses the first
// byte of the encoded string to split the data in its raw, binary state. The
// default value is a double-quote ('"'). If your data does not contain quoted
// sections, set the property value to an empty string. If your data contains
// quoted newline characters, you must also set the allowQuotedNewlines property
// to true.
@property (copy) NSString *quote;

// [Optional] The schema for the destination table. The schema can be omitted if
// the destination table already exists or if the schema can be inferred from
// the loaded data.
@property (retain) GTLBigqueryTableSchema *schema;

// [Deprecated] The inline schema. For CSV schemas, specify as
// "Field1:Type1[,Field2:Type2]*". For example, "foo:STRING, bar:INTEGER,
// baz:FLOAT".
@property (copy) NSString *schemaInline;

// [Deprecated] The format of the schemaInline property.
@property (copy) NSString *schemaInlineFormat;

// [Optional] The number of rows at the top of a CSV file that BigQuery will
// skip when loading the data. The default value is 0. This property is useful
// if you have header rows in the file that should be skipped.
@property (retain) NSNumber *skipLeadingRows;  // intValue

// [Optional] The format of the data files. For CSV files, specify "CSV". For
// datastore backups, specify "DATASTORE_BACKUP". For newline-delimited JSON,
// specify "NEWLINE_DELIMITED_JSON". The default value is CSV.
@property (copy) NSString *sourceFormat;

// [Required] The fully-qualified URIs that point to your data on Google Cloud
// Storage.
@property (retain) NSArray *sourceUris;  // of NSString

// [Optional] Specifies the action that occurs if the destination table already
// exists. The following values are supported: WRITE_TRUNCATE: If the table
// already exists, BigQuery overwrites the table data. WRITE_APPEND: If the
// table already exists, BigQuery appends the data to the table. WRITE_EMPTY: If
// the table already exists and contains data, a 'duplicate' error is returned
// in the job result. The default value is WRITE_EMPTY. Each action is atomic
// and only occurs if BigQuery is able to complete the job successfully.
// Creation, truncation and append actions occur as one atomic update upon job
// completion.
@property (copy) NSString *writeDisposition;

@end
