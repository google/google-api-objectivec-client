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
//  GTLBigqueryJobConfigurationExtract.h
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
//   GTLBigqueryJobConfigurationExtract (0 custom class methods, 6 custom properties)

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

// [Experimental] Optional and defaults to CSV. Format with which files should
// be exported. To export to CSV, specify "CSV". Tables with nested or repeated
// fields cannot be exported as CSV. To export to newline-delimited JSON,
// specify "NEWLINE_DELIMITED_JSON".
@property (copy) NSString *destinationFormat;

// [Pick one] DEPRECATED: Use destinationUris instead, passing only one URI as
// necessary. The fully-qualified Google Cloud Storage URI where the extracted
// table should be written.
@property (copy) NSString *destinationUri;

// [Pick one] A list of fully-qualified Google Cloud Storage URIs where the
// extracted table should be written.
@property (retain) NSArray *destinationUris;  // of NSString

// [Optional] Delimiter to use between fields in the exported data. Default is
// ','
@property (copy) NSString *fieldDelimiter;

// [Optional] Whether to print out a header row in the results. Default is true.
@property (retain) NSNumber *printHeader;  // boolValue

// [Required] A reference to the table being exported.
@property (retain) GTLBigqueryTableReference *sourceTable;

@end
