/* Copyright (c) 2013 Google Inc.
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
//  GTLBigqueryTableFieldSchema.h
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
//   GTLBigqueryTableFieldSchema (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryTableFieldSchema;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryTableFieldSchema
//

@interface GTLBigqueryTableFieldSchema : GTLObject

// [Optional] The field description.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// [Optional] Describes the nested schema fields if the type property is set to
// RECORD.
@property (retain) NSArray *fields;  // of GTLBigqueryTableFieldSchema

// [Optional] The field mode. Possible values include NULLABLE, REQUIRED and
// REPEATED. The default value is NULLABLE.
@property (copy) NSString *mode;

// [Required] The field name.
@property (copy) NSString *name;

// [Required] The field data type. Possible values include STRING, INTEGER,
// FLOAT, BOOLEAN, TIMESTAMP or RECORD (where RECORD indicates that the field
// contains a nested schema).
@property (copy) NSString *type;

@end
