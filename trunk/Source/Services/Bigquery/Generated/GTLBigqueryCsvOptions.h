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
//  GTLBigqueryCsvOptions.h
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
//   GTLBigqueryCsvOptions (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLBigqueryCsvOptions
//

@interface GTLBigqueryCsvOptions : GTLObject

// [Optional] Indicates if BigQuery should accept rows that are missing trailing
// optional columns. If true, BigQuery treats missing trailing columns as null
// values. If false, records with missing trailing columns are treated as bad
// records, and if there are too many bad records, an invalid error is returned
// in the job result. The default value is false.
@property (nonatomic, retain) NSNumber *allowJaggedRows;  // boolValue

// [Optional] Indicates if BigQuery should allow quoted data sections that
// contain newline characters in a CSV file. The default value is false.
@property (nonatomic, retain) NSNumber *allowQuotedNewlines;  // boolValue

// [Optional] The character encoding of the data. The supported values are UTF-8
// or ISO-8859-1. The default value is UTF-8. BigQuery decodes the data after
// the raw, binary data has been split using the values of the quote and
// fieldDelimiter properties.
@property (nonatomic, copy) NSString *encoding;

// [Optional] The separator for fields in a CSV file. BigQuery converts the
// string to ISO-8859-1 encoding, and then uses the first byte of the encoded
// string to split the data in its raw, binary state. BigQuery also supports the
// escape sequence "\t" to specify a tab separator. The default value is a comma
// (',').
@property (nonatomic, copy) NSString *fieldDelimiter;

// [Optional] The value that is used to quote data sections in a CSV file.
// BigQuery converts the string to ISO-8859-1 encoding, and then uses the first
// byte of the encoded string to split the data in its raw, binary state. The
// default value is a double-quote ('"'). If your data does not contain quoted
// sections, set the property value to an empty string. If your data contains
// quoted newline characters, you must also set the allowQuotedNewlines property
// to true.
@property (nonatomic, copy) NSString *quote;

// [Optional] The number of rows at the top of a CSV file that BigQuery will
// skip when reading the data. The default value is 0. This property is useful
// if you have header rows in the file that should be skipped.
@property (nonatomic, retain) NSNumber *skipLeadingRows;  // intValue

@end
