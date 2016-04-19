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
//  GTLDeploymentManagerDeployment.m
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
//   GTLDeploymentManagerDeployment (0 custom class methods, 11 custom properties)

#import "GTLDeploymentManagerDeployment.h"

#import "GTLDeploymentManagerDeploymentLabelEntry.h"
#import "GTLDeploymentManagerDeploymentUpdate.h"
#import "GTLDeploymentManagerOperation.h"
#import "GTLDeploymentManagerTargetConfiguration.h"

// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerDeployment
//

@implementation GTLDeploymentManagerDeployment
@dynamic descriptionProperty, fingerprint, identifier, insertTime, labels,
         manifest, name, operation, selfLink, target, update;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"descriptionProperty" : @"description",
    @"identifier" : @"id"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"labels" : [GTLDeploymentManagerDeploymentLabelEntry class]
  };
  return map;
}

@end
