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
//  GTLSQLAdminFlag.h
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
//   GTLSQLAdminFlag (0 custom class methods, 7 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLSQLAdminFlag
//

// A Google Cloud SQL service flag resource.

@interface GTLSQLAdminFlag : GTLObject

// For STRING flags, a list of strings that the value can be set to.
@property (retain) NSArray *allowedStringValues;  // of NSString

// The database version this flag applies to. Currently this can only be
// [MYSQL_5_5].
@property (retain) NSArray *appliesTo;  // of NSString

// This is always sql#flag.
@property (copy) NSString *kind;

// For INTEGER flags, the maximum allowed value.
@property (retain) NSNumber *maxValue;  // longLongValue

// For INTEGER flags, the minimum allowed value.
@property (retain) NSNumber *minValue;  // longLongValue

// This is the name of the flag. Flag names always use underscores, not hyphens,
// e.g. max_allowed_packet
@property (copy) NSString *name;

// The type of the flag. Flags are typed to being BOOLEAN, STRING, INTEGER or
// NONE. NONE is used for flags which do not take a value, such as
// skip_grant_tables.
@property (copy) NSString *type;

@end
