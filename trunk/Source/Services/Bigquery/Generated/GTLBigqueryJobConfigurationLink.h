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
//  GTLBigqueryJobConfigurationLink.h
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
//   GTLBigqueryJobConfigurationLink (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryTableReference;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryJobConfigurationLink
//

@interface GTLBigqueryJobConfigurationLink : GTLObject

// [Optional] Specifies whether the job is allowed to create new tables. The
// following values are supported: CREATE_IF_NEEDED: If the table does not
// exist, BigQuery creates the table. CREATE_NEVER: The table must already
// exist. If it does not, a 'notFound' error is returned in the job result. The
// default value is CREATE_IF_NEEDED. Creation, truncation and append actions
// occur as one atomic update upon job completion.
@property (copy) NSString *createDisposition;

// [Required] The destination table of the link job.
@property (retain) GTLBigqueryTableReference *destinationTable;

// [Required] URI of source table to link.
@property (retain) NSArray *sourceUri;  // of NSString

// [Optional] Specifies the action that occurs if the destination table already
// exists. The following values are supported: WRITE_TRUNCATE: If the table
// already exists, BigQuery overwrites the table data. WRITE_APPEND: If the
// table already exists, BigQuery appends the data to the table. WRITE_EMPTY: If
// the table already exists and contains data, a 'duplicate' error is returned
// in the job result. The default value is WRITE_EMPTY. Each action is atomic
// and only occurs if BigQuery is able to complete the job successfully.
// Creation, truncation and append actions occur as one atomic update upon job
// completion.
@property (copy) NSString *writeDisposition;

@end
