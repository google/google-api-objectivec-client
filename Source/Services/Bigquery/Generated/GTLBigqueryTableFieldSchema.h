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
//  GTLBigqueryTableFieldSchema.h
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

// [Optional] The field description. The maximum length is 16K characters.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// [Optional] Describes the nested schema fields if the type property is set to
// RECORD.
@property (nonatomic, retain) NSArray *fields;  // of GTLBigqueryTableFieldSchema

// [Optional] The field mode. Possible values include NULLABLE, REQUIRED and
// REPEATED. The default value is NULLABLE.
@property (nonatomic, copy) NSString *mode;

// [Required] The field name. The name must contain only letters (a-z, A-Z),
// numbers (0-9), or underscores (_), and must start with a letter or
// underscore. The maximum length is 128 characters.
@property (nonatomic, copy) NSString *name;

// [Required] The field data type. Possible values include STRING, INTEGER,
// FLOAT, BOOLEAN, TIMESTAMP or RECORD (where RECORD indicates that the field
// contains a nested schema).
@property (nonatomic, copy) NSString *type;

@end
