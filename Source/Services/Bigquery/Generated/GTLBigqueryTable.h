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
//  GTLBigqueryTable.h
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
//   GTLBigqueryTable (0 custom class methods, 20 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryExternalDataConfiguration;
@class GTLBigqueryStreamingbuffer;
@class GTLBigqueryTableReference;
@class GTLBigqueryTableSchema;
@class GTLBigqueryTimePartitioning;
@class GTLBigqueryViewDefinition;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryTable
//

@interface GTLBigqueryTable : GTLObject

// [Output-only] The time when this table was created, in milliseconds since the
// epoch.
@property (nonatomic, retain) NSNumber *creationTime;  // longLongValue

// [Optional] A user-friendly description of this table.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// [Output-only] A hash of this resource.
@property (nonatomic, copy) NSString *ETag;

// [Optional] The time when this table expires, in milliseconds since the epoch.
// If not present, the table will persist indefinitely. Expired tables will be
// deleted and their storage reclaimed.
@property (nonatomic, retain) NSNumber *expirationTime;  // longLongValue

// [Optional] Describes the data format, location, and other properties of a
// table stored outside of BigQuery. By defining these properties, the data
// source can then be queried as if it were a standard BigQuery table.
@property (nonatomic, retain) GTLBigqueryExternalDataConfiguration *externalDataConfiguration;

// [Optional] A descriptive name for this table.
@property (nonatomic, copy) NSString *friendlyName;

// [Output-only] An opaque ID uniquely identifying the table.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// [Output-only] The type of the resource.
@property (nonatomic, copy) NSString *kind;

// [Output-only] The time when this table was last modified, in milliseconds
// since the epoch.
@property (nonatomic, retain) NSNumber *lastModifiedTime;  // unsignedLongLongValue

// [Output-only] The geographic location where the table resides. This value is
// inherited from the dataset.
@property (nonatomic, copy) NSString *location;

// [Output-only] The size of this table in bytes, excluding any data in the
// streaming buffer.
@property (nonatomic, retain) NSNumber *numBytes;  // longLongValue

// [Output-only] The number of bytes in the table that are considered "long-term
// storage".
@property (nonatomic, retain) NSNumber *numLongTermBytes;  // longLongValue

// [Output-only] The number of rows of data in this table, excluding any data in
// the streaming buffer.
@property (nonatomic, retain) NSNumber *numRows;  // unsignedLongLongValue

// [Optional] Describes the schema of this table.
@property (nonatomic, retain) GTLBigqueryTableSchema *schema;

// [Output-only] A URL that can be used to access this resource again.
@property (nonatomic, copy) NSString *selfLink;

// [Output-only] Contains information regarding this table's streaming buffer,
// if one is present. This field will be absent if the table is not being
// streamed to or if there is no data in the streaming buffer.
@property (nonatomic, retain) GTLBigqueryStreamingbuffer *streamingBuffer;

// [Required] Reference describing the ID of this table.
@property (nonatomic, retain) GTLBigqueryTableReference *tableReference;

// [Experimental] If specified, configures time-based partitioning for this
// table.
@property (nonatomic, retain) GTLBigqueryTimePartitioning *timePartitioning;

// [Output-only] Describes the table type. The following values are supported:
// TABLE: A normal BigQuery table. VIEW: A virtual table defined by a SQL query.
// EXTERNAL: A table that references data stored in an external storage system,
// such as Google Cloud Storage. The default value is TABLE.
@property (nonatomic, copy) NSString *type;

// [Optional] The view definition.
@property (nonatomic, retain) GTLBigqueryViewDefinition *view;

@end
