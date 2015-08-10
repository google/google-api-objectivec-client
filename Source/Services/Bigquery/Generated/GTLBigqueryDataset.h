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
//  GTLBigqueryDataset.h
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
//   GTLBigqueryDataset (0 custom class methods, 12 custom properties)
//   GTLBigqueryDatasetAccessItem (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBigqueryDatasetAccessItem;
@class GTLBigqueryDatasetReference;
@class GTLBigqueryTableReference;

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
@property (nonatomic, retain) NSArray *access;  // of GTLBigqueryDatasetAccessItem

// [Output-only] The time when this dataset was created, in milliseconds since
// the epoch.
@property (nonatomic, retain) NSNumber *creationTime;  // longLongValue

// [Required] A reference that identifies the dataset.
@property (nonatomic, retain) GTLBigqueryDatasetReference *datasetReference;

// [Experimental] The default lifetime of all tables in the dataset, in
// milliseconds. The minimum value is 3600000 milliseconds (one hour). Once this
// property is set, all newly-created tables in the dataset will have an
// expirationTime property set to the creation time plus the value in this
// property, and changing the value will only affect new tables, not existing
// ones. When the expirationTime for a given table is reached, that table will
// be deleted automatically. If a table's expirationTime is modified or removed
// before the table expires, or if you provide an explicit expirationTime when
// creating a table, that value takes precedence over the default expiration
// time indicated by this property.
@property (nonatomic, retain) NSNumber *defaultTableExpirationMs;  // longLongValue

// [Optional] A user-friendly description of the dataset.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// [Output-only] A hash of the resource.
@property (nonatomic, copy) NSString *ETag;

// [Optional] A descriptive name for the dataset.
@property (nonatomic, copy) NSString *friendlyName;

// [Output-only] The fully-qualified unique name of the dataset in the format
// projectId:datasetId. The dataset name without the project name is given in
// the datasetId field. When creating a new dataset, leave this field blank, and
// instead specify the datasetId field.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// [Output-only] The resource type.
@property (nonatomic, copy) NSString *kind;

// [Output-only] The date when this dataset or any of its tables was last
// modified, in milliseconds since the epoch.
@property (nonatomic, retain) NSNumber *lastModifiedTime;  // longLongValue

// [Experimental] The geographic location where the dataset should reside.
// Possible values include EU and US. The default value is US.
@property (nonatomic, copy) NSString *location;

// [Output-only] A URL that can be used to access the resource again. You can
// use this URL in Get or Update requests to the resource.
@property (nonatomic, copy) NSString *selfLink;

@end


// ----------------------------------------------------------------------------
//
//   GTLBigqueryDatasetAccessItem
//

@interface GTLBigqueryDatasetAccessItem : GTLObject

// [Pick one] A domain to grant access to. Any users signed in with the domain
// specified will be granted the specified access. Example: "example.com".
@property (nonatomic, copy) NSString *domain;

// [Pick one] An email address of a Google Group to grant access to.
@property (nonatomic, copy) NSString *groupByEmail;

// [Required] Describes the rights granted to the user specified by the other
// member of the access object. The following string values are supported:
// READER, WRITER, OWNER.
@property (nonatomic, copy) NSString *role;

// [Pick one] A special group to grant access to. Possible values include:
// projectOwners: Owners of the enclosing project. projectReaders: Readers of
// the enclosing project. projectWriters: Writers of the enclosing project.
// allAuthenticatedUsers: All authenticated BigQuery users.
@property (nonatomic, copy) NSString *specialGroup;

// [Pick one] An email address of a user to grant access to. For example:
// fred@example.com.
@property (nonatomic, copy) NSString *userByEmail;

// [Pick one] A view from a different dataset to grant access to. Queries
// executed against that view will have read access to tables in this dataset.
// The role field is not required when this field is set. If that view is
// updated by any user, access to the view needs to be granted again via an
// update operation.
@property (nonatomic, retain) GTLBigqueryTableReference *view;

@end
