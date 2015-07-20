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
//  GTLBigqueryJobConfigurationQuery.h
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
//   GTLBigqueryJobConfigurationQuery (0 custom class methods, 12 custom properties)
//   GTLBigqueryJobConfigurationQueryTableDefinitions (0 custom class methods, 0 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryDatasetReference;
@class GTLBigqueryExternalDataConfiguration;
@class GTLBigqueryJobConfigurationQueryTableDefinitions;
@class GTLBigqueryTableReference;
@class GTLBigqueryUserDefinedFunctionResource;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryJobConfigurationQuery
//

@interface GTLBigqueryJobConfigurationQuery : GTLObject

// If true, allows the query to produce arbitrarily large result tables at a
// slight cost in performance. Requires destinationTable to be set.
@property (nonatomic, retain) NSNumber *allowLargeResults;  // boolValue

// [Optional] Specifies whether the job is allowed to create new tables. The
// following values are supported: CREATE_IF_NEEDED: If the table does not
// exist, BigQuery creates the table. CREATE_NEVER: The table must already
// exist. If it does not, a 'notFound' error is returned in the job result. The
// default value is CREATE_IF_NEEDED. Creation, truncation and append actions
// occur as one atomic update upon job completion.
@property (nonatomic, copy) NSString *createDisposition;

// [Optional] Specifies the default dataset to use for unqualified table names
// in the query.
@property (nonatomic, retain) GTLBigqueryDatasetReference *defaultDataset;

// [Optional] Describes the table where the query results should be stored. If
// not present, a new table will be created to store the results.
@property (nonatomic, retain) GTLBigqueryTableReference *destinationTable;

// [Optional] Flattens all nested and repeated fields in the query results. The
// default value is true. allowLargeResults must be true if this is set to
// false.
@property (nonatomic, retain) NSNumber *flattenResults;  // boolValue

// [Deprecated] This property is deprecated.
@property (nonatomic, retain) NSNumber *preserveNulls;  // boolValue

// [Optional] Specifies a priority for the query. Possible values include
// INTERACTIVE and BATCH. The default value is INTERACTIVE.
@property (nonatomic, copy) NSString *priority;

// [Required] BigQuery SQL query to execute.
@property (nonatomic, copy) NSString *query;

// [Experimental] If querying an external data source outside of BigQuery,
// describes the data format, location and other properties of the data source.
// By defining these properties, the data source can then be queried as if it
// were a standard BigQuery table.
@property (nonatomic, retain) GTLBigqueryJobConfigurationQueryTableDefinitions *tableDefinitions;

// [Optional] Whether to look for the result in the query cache. The query cache
// is a best-effort cache that will be flushed whenever tables in the query are
// modified. Moreover, the query cache is only available when a query does not
// have a destination table specified. The default value is true.
@property (nonatomic, retain) NSNumber *useQueryCache;  // boolValue

// [Experimental] Describes user-defined function resources used in the query.
@property (nonatomic, retain) NSArray *userDefinedFunctionResources;  // of GTLBigqueryUserDefinedFunctionResource

// [Optional] Specifies the action that occurs if the destination table already
// exists. The following values are supported: WRITE_TRUNCATE: If the table
// already exists, BigQuery overwrites the table data. WRITE_APPEND: If the
// table already exists, BigQuery appends the data to the table. WRITE_EMPTY: If
// the table already exists and contains data, a 'duplicate' error is returned
// in the job result. The default value is WRITE_EMPTY. Each action is atomic
// and only occurs if BigQuery is able to complete the job successfully.
// Creation, truncation and append actions occur as one atomic update upon job
// completion.
@property (nonatomic, copy) NSString *writeDisposition;

@end


// ----------------------------------------------------------------------------
//
//   GTLBigqueryJobConfigurationQueryTableDefinitions
//

@interface GTLBigqueryJobConfigurationQueryTableDefinitions : GTLObject
// This object is documented as having more properties that are
// GTLBigqueryExternalDataConfiguration. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end
