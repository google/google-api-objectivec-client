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
//  GTLDiscoveryRestDescription.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLDiscoveryJsonSchema;
@class GTLDiscoveryRestDescriptionAuth;
@class GTLDiscoveryRestDescriptionAuthOauth2;
@class GTLDiscoveryRestDescriptionAuthOauth2Scopes;
@class GTLDiscoveryRestDescriptionAuthOauth2ScopesScope;
@class GTLDiscoveryRestDescriptionIcons;
@class GTLDiscoveryRestDescriptionMethods;
@class GTLDiscoveryRestDescriptionParameters;
@class GTLDiscoveryRestDescriptionResources;
@class GTLDiscoveryRestDescriptionSchemas;
@class GTLDiscoveryRestMethod;
@class GTLDiscoveryRestResource;

// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescription
//

@interface GTLDiscoveryRestDescription : GTLObject

// Authentication information.
@property (retain) GTLDiscoveryRestDescriptionAuth *auth;

// [DEPRECATED] The base path for REST requests.
@property (copy) NSString *basePath;

// [DEPRECATED] The base URL for REST requests.
@property (copy) NSString *baseUrl;

// The path for REST batch requests.
@property (copy) NSString *batchPath;

// The description of this API.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Indicate the version of the Discovery API used to generate this doc.
@property (copy) NSString *discoveryVersion;

// A link to human readable documentation for the API.
@property (copy) NSString *documentationLink;

// A list of supported features for this API.
@property (retain) NSArray *features;  // of NSString

// Links to 16x16 and 32x32 icons representing the API.
@property (retain) GTLDiscoveryRestDescriptionIcons *icons;

// The id of this API.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The kind for this response.
@property (copy) NSString *kind;

// Labels for the status of this API, such as labs or deprecated.
@property (retain) NSArray *labels;  // of NSString

// API-level methods for this API.
@property (retain) GTLDiscoveryRestDescriptionMethods *methods;

// The name of this API.
@property (copy) NSString *name;

// Common parameters that apply across all apis.
@property (retain) GTLDiscoveryRestDescriptionParameters *parameters;

// The protocol described by this document.
@property (copy) NSString *protocol;

// The resources in this API.
@property (retain) GTLDiscoveryRestDescriptionResources *resources;

// The version of this API.
@property (copy) NSString *revision;

// The root url under which all API services live.
@property (copy) NSString *rootUrl;

// The schemas for this API.
@property (retain) GTLDiscoveryRestDescriptionSchemas *schemas;

// The base path for all REST requests.
@property (copy) NSString *servicePath;

// The title of this API.
@property (copy) NSString *title;

// The version of this API.
@property (copy) NSString *version;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionAuth
//

@interface GTLDiscoveryRestDescriptionAuth : GTLObject

// OAuth 2.0 authentication information.
@property (retain) GTLDiscoveryRestDescriptionAuthOauth2 *oauth2;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionIcons
//

@interface GTLDiscoveryRestDescriptionIcons : GTLObject

// The url of the 16x16 icon.
@property (copy) NSString *x16;

// The url of the 32x32 icon.
@property (copy) NSString *x32;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionMethods
//

@interface GTLDiscoveryRestDescriptionMethods : GTLObject
// This object is documented as having more properties that are
// GTLDiscoveryRestMethod. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionParameters
//

@interface GTLDiscoveryRestDescriptionParameters : GTLObject
// This object is documented as having more properties that are
// GTLDiscoveryJsonSchema. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionResources
//

@interface GTLDiscoveryRestDescriptionResources : GTLObject
// This object is documented as having more properties that are
// GTLDiscoveryRestResource. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionSchemas
//

@interface GTLDiscoveryRestDescriptionSchemas : GTLObject
// This object is documented as having more properties that are
// GTLDiscoveryJsonSchema. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionAuthOauth2
//

@interface GTLDiscoveryRestDescriptionAuthOauth2 : GTLObject

// Available OAuth 2.0 scopes.
@property (retain) GTLDiscoveryRestDescriptionAuthOauth2Scopes *scopes;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionAuthOauth2Scopes
//

@interface GTLDiscoveryRestDescriptionAuthOauth2Scopes : GTLObject
// This object is documented as having more properties that are
// GTLDiscoveryRestDescriptionAuthOauth2ScopesScope. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestDescriptionAuthOauth2ScopesScope
//

@interface GTLDiscoveryRestDescriptionAuthOauth2ScopesScope : GTLObject

// Description of scope.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

@end
