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
//  GTLBigqueryJobConfigurationExtract.h
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
//   GTLBigqueryJobConfigurationExtract (0 custom class methods, 7 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryTableReference;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryJobConfigurationExtract
//

@interface GTLBigqueryJobConfigurationExtract : GTLObject

// [Optional] The compression type to use for exported files. Possible values
// include GZIP and NONE. The default value is NONE.
@property (nonatomic, copy) NSString *compression;

// [Optional] The exported file format. Possible values include CSV,
// NEWLINE_DELIMITED_JSON and AVRO. The default value is CSV. Tables with nested
// or repeated fields cannot be exported as CSV.
@property (nonatomic, copy) NSString *destinationFormat;

// [Pick one] DEPRECATED: Use destinationUris instead, passing only one URI as
// necessary. The fully-qualified Google Cloud Storage URI where the extracted
// table should be written.
@property (nonatomic, copy) NSString *destinationUri;

// [Pick one] A list of fully-qualified Google Cloud Storage URIs where the
// extracted table should be written.
@property (nonatomic, retain) NSArray *destinationUris;  // of NSString

// [Optional] Delimiter to use between fields in the exported data. Default is
// ','
@property (nonatomic, copy) NSString *fieldDelimiter;

// [Optional] Whether to print out a header row in the results. Default is true.
@property (nonatomic, retain) NSNumber *printHeader;  // boolValue

// [Required] A reference to the table being exported.
@property (nonatomic, retain) GTLBigqueryTableReference *sourceTable;

@end
