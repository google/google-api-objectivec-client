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
//  GTLSQLAdminIpMapping.h
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
//   GTLSQLAdminIpMapping (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLSQLAdminIpMapping
//

// Database instance IP Mapping.

@interface GTLSQLAdminIpMapping : GTLObject

// The IP address assigned.
@property (copy) NSString *ipAddress;

// The due time for this IP to be retired in RFC 3339 format, for example
// 2012-11-15T16:19:00.094Z. This field is only available when the IP is
// scheduled to be retired.
@property (retain) GTLDateTime *timeToRetire;

@end
