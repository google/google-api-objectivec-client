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
//  GTLSQLAdminDatabaseFlags.h
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
//   GTLSQLAdminDatabaseFlags (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLSQLAdminDatabaseFlags
//

// MySQL flags for Cloud SQL instances.

@interface GTLSQLAdminDatabaseFlags : GTLObject

// The name of the flag. These flags are passed at instance startup, so include
// both MySQL server options and MySQL system variables. Flags should be
// specified with underscores, not hyphens. Refer to the official MySQL
// documentation on server options and system variables for descriptions of what
// these flags do. Acceptable values are: event_scheduler on or off (Note: The
// event scheduler will only work reliably if the instance activationPolicy is
// set to ALWAYS.) general_log on or off group_concat_max_len 4..17179869184
// innodb_flush_log_at_trx_commit 0..2 innodb_lock_wait_timeout 1..1073741824
// log_bin_trust_function_creators on or off log_output Can be either TABLE or
// NONE, FILE is not supported. log_queries_not_using_indexes on or off
// long_query_time 0..30000000 lower_case_table_names 0..2 max_allowed_packet
// 16384..1073741824 read_only on or off skip_show_database on or off
// slow_query_log on or off wait_timeout 1..31536000
@property (copy) NSString *name;

// The value of the flag. Booleans should be set using 1 for true, and 0 for
// false. This field must be omitted if the flag doesn't take a value.
@property (copy) NSString *value;

@end
