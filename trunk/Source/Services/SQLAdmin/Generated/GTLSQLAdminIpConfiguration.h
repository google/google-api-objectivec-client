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
//  GTLSQLAdminIpConfiguration.h
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
//   GTLSQLAdminIpConfiguration (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLSQLAdminIpConfiguration
//

// IP Management configuration.

@interface GTLSQLAdminIpConfiguration : GTLObject

// The list of external networks that are allowed to connect to the instance
// using the IP. In CIDR notation, also known as 'slash' notation (e.g.
// 192.168.100.0/24).
@property (retain) NSArray *authorizedNetworks;  // of NSString

// Whether the instance should be assigned an IP address or not.
@property (retain) NSNumber *enabled;  // boolValue

// Whether the mysqld should default to 'REQUIRE X509' for users connecting over
// IP.
@property (retain) NSNumber *requireSsl;  // boolValue

@end
