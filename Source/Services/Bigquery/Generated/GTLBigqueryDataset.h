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
//  GTLBigqueryDataset.h
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
//   GTLBigqueryDataset (0 custom class methods, 10 custom properties)
//   GTLBigqueryDatasetAccessItem (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryDatasetAccessItem;
@class GTLBigqueryDatasetReference;

// ----------------------------------------------------------------------------
//
//   GTLBigqueryDataset
//

@interface GTLBigqueryDataset : GTLObject

// [Optional] An array of objects that define dataset access for one or more
// entities. You can set this property when inserting or updating a dataset in
// order to control who is allowed to access the data. If unspecified at dataset
// creation time, BigQuery adds default dataset access for the following
// entities: access.specialGroup: projectReaders; access.role: READER;
// access.specialGroup: projectWriters; access.role: WRITER;
// access.specialGroup: projectOwners; access.role: OWNER; access.userByEmail:
// [dataset creator email]; access.role: OWNER;
@property (retain) NSArray *access;  // of GTLBigqueryDatasetAccessItem

// [Output-only] The time when this dataset was created, in milliseconds since
// the epoch.
@property (retain) NSNumber *creationTime;  // longLongValue

// [Required] A reference that identifies the dataset.
@property (retain) GTLBigqueryDatasetReference *datasetReference;

// [Optional] A user-friendly description of the dataset.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// [Output-only] A hash of the resource.
@property (copy) NSString *ETag;

// [Optional] A descriptive name for the dataset.
@property (copy) NSString *friendlyName;

// [Output-only] The fully-qualified unique name of the dataset in the format
// projectId:datasetId. The dataset name without the project name is given in
// the datasetId field. When creating a new dataset, leave this field blank, and
// instead specify the datasetId field.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// [Output-only] The resource type.
@property (copy) NSString *kind;

// [Output-only] The date when this dataset or any of its tables was last
// modified, in milliseconds since the epoch.
@property (retain) NSNumber *lastModifiedTime;  // longLongValue

// [Output-only] A URL that can be used to access the resource again. You can
// use this URL in Get or Update requests to the resource.
@property (copy) NSString *selfLink;

@end


// ----------------------------------------------------------------------------
//
//   GTLBigqueryDatasetAccessItem
//

@interface GTLBigqueryDatasetAccessItem : GTLObject

// [Pick one] A domain to grant access to. Any users signed in with the domain
// specified will be granted the specified access. Example: "example.com".
@property (copy) NSString *domain;

// [Pick one] An email address of a Google Group to grant access to.
@property (copy) NSString *groupByEmail;

// [Required] Describes the rights granted to the user specified by the other
// member of the access object. The following string values are supported:
// READER, WRITER, OWNER.
@property (copy) NSString *role;

// [Pick one] A special group to grant access to. Possible values include:
// projectOwners: Owners of the enclosing project. projectReaders: Readers of
// the enclosing project. projectWriters: Writers of the enclosing project.
// allAuthenticatedUsers: All authenticated BigQuery users.
@property (copy) NSString *specialGroup;

// [Pick one] An email address of a user to grant access to. For example:
// fred@example.com.
@property (copy) NSString *userByEmail;

@end
