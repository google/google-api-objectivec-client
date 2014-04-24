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
//  GTLSQLAdminCloneContext.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Cloud SQL Administration API (sqladmin/v1beta3)
// Description:
//   API for Cloud SQL database instance management.
// Documentation:
//   https://developers.google.com/cloud-sql/docs/admin-api/
// Classes:
//   GTLSQLAdminCloneContext (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSQLAdminBinLogCoordinates;

// ----------------------------------------------------------------------------
//
//   GTLSQLAdminCloneContext
//

// Database instance clone context.

@interface GTLSQLAdminCloneContext : GTLObject

// Binary log coordinates, if specified, indentify the the position up to which
// the source instance should be cloned. If not specified, the source instance
// is cloned up to the most recent binary log coordintes.
@property (retain) GTLSQLAdminBinLogCoordinates *binLogCoordinates;

// Name of the Cloud SQL instance to be created as a clone.
@property (copy) NSString *destinationInstanceName;

// This is always sql#cloneContext.
@property (copy) NSString *kind;

// Name of the Cloud SQL instance to be cloned.
@property (copy) NSString *sourceInstanceName;

@end
