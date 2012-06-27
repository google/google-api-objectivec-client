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
//  GTLDiscoveryRestDescription.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   APIs Discovery Service (discovery/v1)
// Description:
//   Lets you discover information about other Google APIs, such as what APIs
//   are available, the resource and method details for each API
// Documentation:
//   http://code.google.com/apis/discovery
// Classes:
//   GTLDiscoveryRestDescription (0 custom class methods, 23 custom properties)
//   GTLDiscoveryRestDescriptionAuth (0 custom class methods, 1 custom properties)
//   GTLDiscoveryRestDescriptionIcons (0 custom class methods, 2 custom properties)
//   GTLDiscoveryRestDescriptionMethods (0 custom class methods, 0 custom properties)
//   GTLDiscoveryRestDescriptionParameters (0 custom class methods, 0 custom properties)
//   GTLDiscoveryRestDescriptionResources (0 custom class methods, 0 custom properties)
//   GTLDiscoveryRestDescriptionSchemas (0 custom class methods, 0 custom properties)
//   GTLDiscoveryRestDescriptionAuthOauth2 (0 custom class methods, 1 custom properties)
//   GTLDiscoveryRestDescriptionAuthOauth2Scopes (0 custom class methods, 0 custom properties)
//   GTLDiscoveryRestDescriptionAuthOauth2ScopesScope (0 custom class methods, 1 custom properties)

#import "GTLDiscoveryRestDescription.h"

#import "GTLDiscoveryJsonSchema.h"
#import "GTLDiscoveryRestMethod.h"
#import "GTLDiscoveryRestResource.h"

// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescription
//

@implementation GTLDiscoveryRestDescription
@dynamic auth, basePath, baseUrl, batchPath, descriptionProperty,
         discoveryVersion, documentationLink, features, icons, identifier, kind,
         labels, methods, name, parameters, protocol, resources, revision,
         rootUrl, schemas, servicePath, title, version;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"description", @"descriptionProperty",
      @"id", @"identifier",
      nil];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [NSString class], @"features",
      [NSString class], @"labels",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"discovery#restDescription"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionAuth
//

@implementation GTLDiscoveryRestDescriptionAuth
@dynamic oauth2;
@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionIcons
//

@implementation GTLDiscoveryRestDescriptionIcons
@dynamic x16, x32;
@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionMethods
//

@implementation GTLDiscoveryRestDescriptionMethods

+ (Class)classForAdditionalProperties {
  return [GTLDiscoveryRestMethod class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionParameters
//

@implementation GTLDiscoveryRestDescriptionParameters

+ (Class)classForAdditionalProperties {
  return [GTLDiscoveryJsonSchema class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionResources
//

@implementation GTLDiscoveryRestDescriptionResources

+ (Class)classForAdditionalProperties {
  return [GTLDiscoveryRestResource class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionSchemas
//

@implementation GTLDiscoveryRestDescriptionSchemas

+ (Class)classForAdditionalProperties {
  return [GTLDiscoveryJsonSchema class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionAuthOauth2
//

@implementation GTLDiscoveryRestDescriptionAuthOauth2
@dynamic scopes;
@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionAuthOauth2Scopes
//

@implementation GTLDiscoveryRestDescriptionAuthOauth2Scopes

+ (Class)classForAdditionalProperties {
  return [GTLDiscoveryRestDescriptionAuthOauth2ScopesScope class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionAuthOauth2ScopesScope
//

@implementation GTLDiscoveryRestDescriptionAuthOauth2ScopesScope
@dynamic descriptionProperty;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"description"
                                forKey:@"descriptionProperty"];
  return map;
}

@end
