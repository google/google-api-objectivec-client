/* Copyright (c) 2012 Google Inc.
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
//  GTLComputeNetworkInterface.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Compute Engine API (compute/v1beta12)
// Description:
//   API for the Google Compute Engine service.
// Documentation:
//   https://developers.google.com/compute/docs/reference/v1beta12
// Classes:
//   GTLComputeNetworkInterface (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLComputeAccessConfig;

// ----------------------------------------------------------------------------
//
//   GTLComputeNetworkInterface
//

@interface GTLComputeNetworkInterface : GTLObject

// Array of configurations for this interface. This specifies how this interface
// is configured to interact with other network services, such as connecting to
// the internet. Currently, ONE_TO_ONE_NAT is the only access config supported.
// If there are no accessConfigs specified, then this instance will have no
// external internet access.
@property (retain) NSArray *accessConfigs;  // of GTLComputeAccessConfig

// Type of the resource.
@property (copy) NSString *kind;

// Name of the resource, determined by the server; for network devices, these
// are e.g. eth0, eth1, etc. (output only).
@property (copy) NSString *name;

// URL of the network resource attached to this interface.
@property (copy) NSString *network;

// An optional IPV4 internal network address to assign to this instance. If not
// specified, one will be assigned from the available range.
@property (copy) NSString *networkIP;

@end
