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
//   GTLBigqueryExternalDataConfiguration (0 custom class methods, 8 custom properties)

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

// [Experimental] Try to detect schema and format options automatically. Any
// option specified explicitly will be honored.
@property (nonatomic, retain) NSNumber *autodetect;  // boolValue

// [Optional] The compression type of the data source. Possible values include
// GZIP and NONE. The default value is NONE. This setting is ignored for Google
// Cloud Datastore backups and Avro.
@property (nonatomic, copy) NSString *compression;

// Additional properties to set if sourceFormat is set to CSV.
@property (nonatomic, retain) GTLBigqueryCsvOptions *csvOptions;

// [Optional] Indicates if BigQuery should allow extra values that are not
// represented in the table schema. If true, the extra values are ignored. If
// false, records with extra columns are treated as bad records, and if there
// are too many bad records, an invalid error is returned in the job result. The
// default value is false. The sourceFormat property determines what BigQuery
// treats as an extra value: CSV: Trailing columns JSON: Named values that don't
// match any column names Google Cloud Datastore backups: This setting is
// ignored. Avro: This setting is ignored.
@property (nonatomic, retain) NSNumber *ignoreUnknownValues;  // boolValue

// [Optional] The maximum number of bad records that BigQuery can ignore when
// reading data. If the number of bad records exceeds this value, an invalid
// error is returned in the job result. The default value is 0, which requires
// that all records are valid. This setting is ignored for Google Cloud
// Datastore backups and Avro.
@property (nonatomic, retain) NSNumber *maxBadRecords;  // intValue

// [Optional] The schema for the data. Schema is required for CSV and JSON
// formats. Schema is disallowed for Google Cloud Datastore backups and Avro.
@property (nonatomic, retain) GTLBigqueryTableSchema *schema;

// [Required] The data format. For CSV files, specify "CSV". For
// newline-delimited JSON, specify "NEWLINE_DELIMITED_JSON". For Google Cloud
// Datastore backups, specify "DATASTORE_BACKUP". For Avro files, specify
// "AVRO".
@property (nonatomic, copy) NSString *sourceFormat;

// [Required] The fully-qualified URIs that point to your data in Google Cloud
// Storage. Each URI can contain one '*' wildcard character and it must come
// after the 'bucket' name. Size limits related to load jobs apply to external
// data sources, plus an additional limit of 10 GB maximum size across all URIs.
// For Google Cloud Datastore backups, exactly one URI can be specified, and it
// must end with '.backup_info'. Also, the '*' wildcard character is not
// allowed.
@property (nonatomic, retain) NSArray *sourceUris;  // of NSString

@end
