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
//  GTLServiceCompute.m
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
//   GTLServiceCompute (0 custom class methods, 0 custom properties)

#import "GTLCompute.h"

@implementation GTLServiceCompute

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = [NSArray arrayWithObjects:
                      [GTLQueryCompute class],
                      [GTLComputeAccessConfig class],
                      [GTLComputeAttachedDisk class],
                      [GTLComputeDisk class],
                      [GTLComputeDiskList class],
                      [GTLComputeFirewall class],
                      [GTLComputeFirewallList class],
                      [GTLComputeImage class],
                      [GTLComputeImageList class],
                      [GTLComputeInstance class],
                      [GTLComputeInstanceList class],
                      [GTLComputeKernel class],
                      [GTLComputeKernelList class],
                      [GTLComputeMachineType class],
                      [GTLComputeMachineTypeList class],
                      [GTLComputeMetadata class],
                      [GTLComputeNetwork class],
                      [GTLComputeNetworkInterface class],
                      [GTLComputeNetworkList class],
                      [GTLComputeOperation class],
                      [GTLComputeOperationList class],
                      [GTLComputeProject class],
                      [GTLComputeServiceAccount class],
                      [GTLComputeSnapshot class],
                      [GTLComputeSnapshotList class],
                      [GTLComputeZone class],
                      [GTLComputeZoneList class],
                      nil];
  return classes;
}
#endif  // DEBUG

- (id)init {
  self = [super init];
  if (self) {
    // Version from discovery.
    self.apiVersion = @"v1beta12";

    // From discovery.  Where to send JSON-RPC.
    // Turn off prettyPrint for this service to save bandwidth (especially on
    // mobile). The fetcher logging will pretty print.
    self.rpcURL = [NSURL URLWithString:@"https://www.googleapis.com/rpc?prettyPrint=false"];
  }
  return self;
}

@end
