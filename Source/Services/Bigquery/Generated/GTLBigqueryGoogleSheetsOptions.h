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
//  GTLBigqueryGoogleSheetsOptions.h
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
//   GTLBigqueryGoogleSheetsOptions (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLBigqueryGoogleSheetsOptions
//

@interface GTLBigqueryGoogleSheetsOptions : GTLObject

// [Optional] The number of rows at the top of a sheet that BigQuery will skip
// when reading the data. The default value is 0. This property is useful if you
// have header rows that should be skipped. When autodetect is on, behavior is
// the following: * skipLeadingRows unspecified - Autodetect tries to detect
// headers in the first row. If they are not detected, the row is read as data.
// Otherwise data is read starting from the second row. * skipLeadingRows is 0 -
// Instructs autodetect that there are no headers and data should be read
// starting from the first row. * skipLeadingRows = N > 0 - Autodetect skips N-1
// rows and tries to detect headers in row N. If headers are not detected, row N
// is just skipped. Otherwise row N is used to extract column names for the
// detected schema.
@property (nonatomic, retain) NSNumber *skipLeadingRows;  // longLongValue

@end
