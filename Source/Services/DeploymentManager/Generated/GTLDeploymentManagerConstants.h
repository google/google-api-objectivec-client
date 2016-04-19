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
//  GTLDeploymentManagerConstants.h
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

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// View and manage your data across Google Cloud Platform services
GTL_EXTERN NSString * const kGTLAuthScopeDeploymentManagerCloudPlatform;  // "https://www.googleapis.com/auth/cloud-platform"
// View your data across Google Cloud Platform services
GTL_EXTERN NSString * const kGTLAuthScopeDeploymentManagerCloudPlatformReadOnly;  // "https://www.googleapis.com/auth/cloud-platform.read-only"
// View and manage your Google Cloud Platform management resources and
// deployment status information
GTL_EXTERN NSString * const kGTLAuthScopeDeploymentManagerNdevCloudman;  // "https://www.googleapis.com/auth/ndev.cloudman"
// View your Google Cloud Platform management resources and deployment status
// information
GTL_EXTERN NSString * const kGTLAuthScopeDeploymentManagerNdevCloudmanReadonly;  // "https://www.googleapis.com/auth/ndev.cloudman.readonly"

// GTLQueryDeploymentManager - CreatePolicy
GTL_EXTERN NSString * const kGTLDeploymentManagerCreatePolicyAcquire;  // "ACQUIRE"
GTL_EXTERN NSString * const kGTLDeploymentManagerCreatePolicyCreateOrAcquire;  // "CREATE_OR_ACQUIRE"

// GTLQueryDeploymentManager - DeletePolicy
GTL_EXTERN NSString * const kGTLDeploymentManagerDeletePolicyAbandon;  // "ABANDON"
GTL_EXTERN NSString * const kGTLDeploymentManagerDeletePolicyDelete;  // "DELETE"
