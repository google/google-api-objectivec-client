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
//  GTLDeploymentManagerManifest.h
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
//   GTLDeploymentManagerManifest (0 custom class methods, 8 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLDeploymentManagerConfigFile;
@class GTLDeploymentManagerImportFile;

// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerManifest
//

@interface GTLDeploymentManagerManifest : GTLObject

// [Output Only] The YAML configuration for this manifest.
@property (nonatomic, retain) GTLDeploymentManagerConfigFile *config;

// [Output Only] The fully-expanded configuration file, including any templates
// and references.
@property (nonatomic, copy) NSString *expandedConfig;

// [Output Only] Unique identifier for the resource; defined by the server.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, retain) NSNumber *identifier;  // unsignedLongLongValue

// [Output Only] The imported files for this manifest.
@property (nonatomic, retain) NSArray *imports;  // of GTLDeploymentManagerImportFile

// [Output Only] Timestamp when the manifest was created, in RFC3339 text
// format.
@property (nonatomic, copy) NSString *insertTime;

// [Output Only] The YAML layout for this manifest.
@property (nonatomic, copy) NSString *layout;

// [Output Only] The name of the manifest.
@property (nonatomic, copy) NSString *name;

// [Output Only] Self link for the manifest.
@property (nonatomic, copy) NSString *selfLink;

@end
