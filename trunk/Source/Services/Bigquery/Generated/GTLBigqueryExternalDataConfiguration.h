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
//  GTLBigqueryExternalDataConfiguration.h
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
//   GTLBigqueryExternalDataConfiguration (0 custom class methods, 7 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryCsvOptions;
@class GTLBigqueryTableSchema;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryExternalDataConfiguration
//

@interface GTLBigqueryExternalDataConfiguration : GTLObject

// [Optional] The compression type of the data source. Possible values include
// GZIP and NONE. The default value is NONE.
@property (nonatomic, copy) NSString *compression;

// Additional properties to set if sourceFormat is set to CSV.
@property (nonatomic, retain) GTLBigqueryCsvOptions *csvOptions;

// [Optional] Indicates if BigQuery should allow extra values that are not
// represented in the table schema. If true, the extra values are ignored. If
// false, records with extra columns are treated as bad records, and if there
// are too many bad records, an invalid error is returned in the job result. The
// default value is false. The sourceFormat property determines what BigQuery
// treats as an extra value: CSV: Trailing columns
@property (nonatomic, retain) NSNumber *ignoreUnknownValues;  // boolValue

// [Optional] The maximum number of bad records that BigQuery can ignore when
// reading data. If the number of bad records exceeds this value, an invalid
// error is returned in the job result. The default value is 0, which requires
// that all records are valid.
@property (nonatomic, retain) NSNumber *maxBadRecords;  // intValue

// [Required] The schema for the data.
@property (nonatomic, retain) GTLBigqueryTableSchema *schema;

// [Optional] The data format. External data sources must be in CSV format. The
// default value is CSV.
@property (nonatomic, copy) NSString *sourceFormat;

// [Required] The fully-qualified URIs that point to your data in Google Cloud
// Storage. Each URI can contain one '*' wildcard character and it must come
// after the 'bucket' name. CSV limits related to load jobs apply to external
// data sources, plus an additional limit of 10 GB maximum size across all URIs.
@property (nonatomic, retain) NSArray *sourceUris;  // of NSString

@end
