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
//  GTLDeploymentManagerDeploymentUpdate.h
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
//   GTLDeploymentManagerDeploymentUpdate (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLDeploymentManagerDeploymentUpdateLabelEntry;

// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerDeploymentUpdate
//

@interface GTLDeploymentManagerDeploymentUpdate : GTLObject

// [Output Only] Map of labels; provided by the client when the resource is
// created or updated. Specifically: Label keys must be between 1 and 63
// characters long and must conform to the following regular expression:
// [a-z]([-a-z0-9]*[a-z0-9])? Label values must be between 0 and 63 characters
// long and must conform to the regular expression ([a-z]([-a-z0-9]*[a-z0-9])?)?
@property (nonatomic, retain) NSArray *labels;  // of GTLDeploymentManagerDeploymentUpdateLabelEntry

// [Output Only] URL of the manifest representing the update configuration of
// this deployment.
@property (nonatomic, copy) NSString *manifest;

@end
