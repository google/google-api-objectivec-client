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
//  GTLDeploymentManagerResourceUpdate.m
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
//   GTLDeploymentManagerResourceUpdate (0 custom class methods, 7 custom properties)
//   GTLDeploymentManagerResourceUpdateError (0 custom class methods, 1 custom properties)
//   GTLDeploymentManagerResourceUpdateWarningsItem (0 custom class methods, 3 custom properties)
//   GTLDeploymentManagerResourceUpdateErrorErrorsItem (0 custom class methods, 3 custom properties)
//   GTLDeploymentManagerResourceUpdateWarningsItemDataItem (0 custom class methods, 2 custom properties)

#import "GTLDeploymentManagerResourceUpdate.h"

// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerResourceUpdate
//

@implementation GTLDeploymentManagerResourceUpdate
@dynamic error, finalProperties, intent, manifest, properties, state, warnings;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"warnings" : [GTLDeploymentManagerResourceUpdateWarningsItem class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerResourceUpdateError
//

@implementation GTLDeploymentManagerResourceUpdateError
@dynamic errors;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"errors" : [GTLDeploymentManagerResourceUpdateErrorErrorsItem class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerResourceUpdateWarningsItem
//

@implementation GTLDeploymentManagerResourceUpdateWarningsItem
@dynamic code, data, message;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"data" : [GTLDeploymentManagerResourceUpdateWarningsItemDataItem class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerResourceUpdateErrorErrorsItem
//

@implementation GTLDeploymentManagerResourceUpdateErrorErrorsItem
@dynamic code, location, message;
@end


// ----------------------------------------------------------------------------
//
//   GTLDeploymentManagerResourceUpdateWarningsItemDataItem
//

@implementation GTLDeploymentManagerResourceUpdateWarningsItemDataItem
@dynamic key, value;
@end
