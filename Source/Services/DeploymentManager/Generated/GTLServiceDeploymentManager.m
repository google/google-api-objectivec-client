/* Copyright (c) 2016 Google Inc.
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
//  GTLServiceDeploymentManager.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Cloud Deployment Manager API (deploymentmanager/v2)
// Description:
//   Declares, configures, and deploys complex solutions on Google Cloud
//   Platform.
// Documentation:
//   https://cloud.google.com/deployment-manager/
// Classes:
//   GTLServiceDeploymentManager (0 custom class methods, 0 custom properties)

#import "GTLDeploymentManager.h"

@implementation GTLServiceDeploymentManager

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = @[
    [GTLQueryDeploymentManager class],
    [GTLDeploymentManagerConfigFile class],
    [GTLDeploymentManagerDeployment class],
    [GTLDeploymentManagerDeploymentLabelEntry class],
    [GTLDeploymentManagerDeploymentsListResponse class],
    [GTLDeploymentManagerDeploymentUpdate class],
    [GTLDeploymentManagerDeploymentUpdateLabelEntry class],
    [GTLDeploymentManagerImportFile class],
    [GTLDeploymentManagerManifest class],
    [GTLDeploymentManagerManifestsListResponse class],
    [GTLDeploymentManagerOperation class],
    [GTLDeploymentManagerOperationsListResponse class],
    [GTLDeploymentManagerResource class],
    [GTLDeploymentManagerResourcesListResponse class],
    [GTLDeploymentManagerResourceUpdate class],
    [GTLDeploymentManagerTargetConfiguration class],
    [GTLDeploymentManagerType class],
    [GTLDeploymentManagerTypesListResponse class]
  ];
  return classes;
}
#endif  // DEBUG

- (instancetype)init {
  self = [super init];
  if (self) {
    // Version from discovery.
    self.apiVersion = @"v2";

    // From discovery.  Where to send JSON-RPC.
    // Turn off prettyPrint for this service to save bandwidth (especially on
    // mobile). The fetcher logging will pretty print.
    self.rpcURL = [NSURL URLWithString:@"https://www.googleapis.com/rpc?prettyPrint=false"];
  }
  return self;
}

@end
