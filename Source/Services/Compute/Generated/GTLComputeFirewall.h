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
//  GTLComputeFirewall.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Compute Engine API (compute/v1beta14)
// Description:
//   API for the Google Compute Engine service.
// Documentation:
//   https://developers.google.com/compute/docs/reference/v1beta14
// Classes:
//   GTLComputeFirewall (0 custom class methods, 11 custom properties)
//   GTLComputeFirewallAllowedItem (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLComputeFirewallAllowedItem;

// ----------------------------------------------------------------------------
//
//   GTLComputeFirewall
//

// A firewall resource.

@interface GTLComputeFirewall : GTLObject

// The list of rules specified by this firewall. Each rule specifies a protocol
// and port-range tuple that describes a permitted connection.
@property (retain) NSArray *allowed;  // of GTLComputeFirewallAllowedItem

// Creation timestamp in RFC3339 text format (output only).
@property (copy) NSString *creationTimestamp;

// An optional textual description of the resource; provided by the client when
// the resource is created.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Unique identifier for the resource; defined by the server (output only).
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSNumber *identifier;  // unsignedLongLongValue

// Type of the resource.
@property (copy) NSString *kind;

// Name of the resource; provided by the client when the resource is created.
// The name must be 1-63 characters long, and comply with RFC1035.
@property (copy) NSString *name;

// URL of the network to which this firewall is applied; provided by the client
// when the firewall is created.
@property (copy) NSString *network;

// Server defined URL for the resource (output only).
@property (copy) NSString *selfLink;

// A list of IP address blocks expressed in CIDR format which this rule applies
// to. One or both of sourceRanges and sourceTags may be set; an inbound
// connection is allowed if either the range or the tag of the source matches.
@property (retain) NSArray *sourceRanges;  // of NSString

// A list of instance tags which this rule applies to. One or both of
// sourceRanges and sourceTags may be set; an inbound connection is allowed if
// either the range or the tag of the source matches.
@property (retain) NSArray *sourceTags;  // of NSString

// A list of instance tags indicating sets of instances located on network which
// may make network connections as specified in allowed. If no targetTags are
// specified, the firewall rule applies to all instances on the specified
// network.
@property (retain) NSArray *targetTags;  // of NSString

@end


// ----------------------------------------------------------------------------
//
//   GTLComputeFirewallAllowedItem
//

@interface GTLComputeFirewallAllowedItem : GTLObject

// Required; this is the IP protocol that is allowed for this rule. This can
// either be a well known protocol string (tcp, udp or icmp) or the IP protocol
// number.
@property (copy) NSString *IPProtocol;

// An optional list of ports which are allowed. It is an error to specify this
// for any protocol that isn't UDP or TCP. Each entry must be either an integer
// or a range. If not specified, connections through any port are allowed.
// Example inputs include: ["22"], ["80","443"] and ["12345-12349"].
@property (retain) NSArray *ports;  // of NSString

@end
