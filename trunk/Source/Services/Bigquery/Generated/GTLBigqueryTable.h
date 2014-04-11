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
//  GTLBigqueryTable.h
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
//   GTLBigqueryTable (0 custom class methods, 15 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryTableReference;
@class GTLBigqueryTableSchema;
@class GTLBigqueryViewDefinition;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryTable
//

@interface GTLBigqueryTable : GTLObject

// [Output-only] The time when this table was created, in milliseconds since the
// epoch.
@property (retain) NSNumber *creationTime;  // longLongValue

// [Optional] A user-friendly description of this table.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// [Output-only] A hash of this resource.
@property (copy) NSString *ETag;

// [Optional] The time when this table expires, in milliseconds since the epoch.
// If not present, the table will persist indefinitely. Expired tables will be
// deleted and their storage reclaimed.
@property (retain) NSNumber *expirationTime;  // longLongValue

// [Optional] A descriptive name for this table.
@property (copy) NSString *friendlyName;

// [Output-only] An opaque ID uniquely identifying the table.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// [Output-only] The type of the resource.
@property (copy) NSString *kind;

// [Output-only] The time when this table was last modified, in milliseconds
// since the epoch.
@property (retain) NSNumber *lastModifiedTime;  // longLongValue

// [Output-only] The size of the table in bytes.
@property (retain) NSNumber *numBytes;  // longLongValue

// [Output-only] The number of rows of data in this table.
@property (retain) NSNumber *numRows;  // unsignedLongLongValue

// [Optional] Describes the schema of this table.
@property (retain) GTLBigqueryTableSchema *schema;

// [Output-only] A URL that can be used to access this resource again.
@property (copy) NSString *selfLink;

// [Required] Reference describing the ID of this table.
@property (retain) GTLBigqueryTableReference *tableReference;

// [Output-only] Describes the table type. The following values are supported:
// TABLE: A normal BigQuery table. VIEW: A virtual table defined by a SQL query.
// The default value is TABLE.
@property (copy) NSString *type;

// [Optional] The view definition.
@property (retain) GTLBigqueryViewDefinition *view;

@end
