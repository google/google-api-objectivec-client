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
//  GTLDiscoveryRpcDescription.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   APIs Discovery Service (discovery/v1)
// Description:
//   Lets you discover information about other Google APIs, such as what APIs
//   are available, the resource and method details for each API.
// Documentation:
//   https://developers.google.com/discovery/
// Classes:
//   GTLDiscoveryRpcDescription (0 custom class methods, 25 custom properties)
//   GTLDiscoveryRpcDescriptionAuth (0 custom class methods, 1 custom properties)
//   GTLDiscoveryRpcDescriptionIcons (0 custom class methods, 2 custom properties)
//   GTLDiscoveryRpcDescriptionMethods (0 custom class methods, 0 custom properties)
//   GTLDiscoveryRpcDescriptionParameters (0 custom class methods, 0 custom properties)
//   GTLDiscoveryRpcDescriptionSchemas (0 custom class methods, 0 custom properties)
//   GTLDiscoveryRpcDescriptionAuthOauth2 (0 custom class methods, 1 custom properties)
//   GTLDiscoveryRpcDescriptionAuthOauth2Scopes (0 custom class methods, 0 custom properties)
//   GTLDiscoveryRpcDescriptionAuthOauth2ScopesScope (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLDiscoveryJsonSchema;
@class GTLDiscoveryRpcDescriptionAuth;
@class GTLDiscoveryRpcDescriptionAuthOauth2;
@class GTLDiscoveryRpcDescriptionAuthOauth2Scopes;
@class GTLDiscoveryRpcDescriptionAuthOauth2ScopesScope;
@class GTLDiscoveryRpcDescriptionIcons;
@class GTLDiscoveryRpcDescriptionMethods;
@class GTLDiscoveryRpcDescriptionParameters;
@class GTLDiscoveryRpcDescriptionSchemas;
@class GTLDiscoveryRpcMethod;

// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRpcDescription
//

@interface GTLDiscoveryRpcDescription : GTLObject

// Authentication information.
@property (retain) GTLDiscoveryRpcDescriptionAuth *auth;

// Indicates how the API name should be capitalized and split into various
// parts. Useful for generating pretty class names.
@property (copy) NSString *canonicalName;

// The description of the API.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Indicate the version of the Discovery API used to generate this doc.
@property (copy) NSString *discoveryVersion;

// A link to human readable documentation for the API.
@property (copy) NSString *documentationLink;

// The ETag for this response.
@property (copy) NSString *ETag;

// A list of supported features for this API.
@property (retain) NSArray *features;  // of NSString

// Links to 16x16 and 32x32 icons representing the API.
@property (retain) GTLDiscoveryRpcDescriptionIcons *icons;

// The ID of this API.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The kind for this response.
@property (copy) NSString *kind;

// Labels for the status of this API, such as labs or deprecated.
@property (retain) NSArray *labels;  // of NSString

// API-level methods for this API.
@property (retain) GTLDiscoveryRpcDescriptionMethods *methods;

// The name of this API.
@property (copy) NSString *name;

// The domain of the owner of the API. Together with the ownerName and a
// packagePath values, this can be used to generate a library for the API which
// would have a unique fully qualified name.
@property (copy) NSString *ownerDomain;

// The name of the owner of the API. See ownerDomain
@property (copy) NSString *ownerName;

// The package of the owner of the API. See ownerDomain
@property (copy) NSString *packagePath;

// Common parameters that apply across all apis.
@property (retain) GTLDiscoveryRpcDescriptionParameters *parameters;

// The protocol described by this document.
@property (copy) NSString *protocol;

// The version of the API.
@property (copy) NSString *revision;

// The root URL under which all API services live.
@property (copy) NSString *rootUrl;

// The path for JSON-RPC requests.
@property (copy) NSString *rpcPath;

// [DEPRECATED] The URL for JSON-RPC requests.
@property (copy) NSString *rpcUrl;

// The schemas for this API.
@property (retain) GTLDiscoveryRpcDescriptionSchemas *schemas;

// The title of the API.
@property (copy) NSString *title;

// The version of the API.
@property (copy) NSString *version;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRpcDescriptionAuth
//

@interface GTLDiscoveryRpcDescriptionAuth : GTLObject

// OAuth 2.0 authentication information.
@property (retain) GTLDiscoveryRpcDescriptionAuthOauth2 *oauth2;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRpcDescriptionIcons
//

@interface GTLDiscoveryRpcDescriptionIcons : GTLObject

// The URL of the 16x16 icon.
@property (copy) NSString *x16;

// The URL of the 32x32 icon.
@property (copy) NSString *x32;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRpcDescriptionMethods
//

@interface GTLDiscoveryRpcDescriptionMethods : GTLObject
// This object is documented as having more properties that are
// GTLDiscoveryRpcMethod. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRpcDescriptionParameters
//

@interface GTLDiscoveryRpcDescriptionParameters : GTLObject
// This object is documented as having more properties that are
// GTLDiscoveryJsonSchema. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRpcDescriptionSchemas
//

@interface GTLDiscoveryRpcDescriptionSchemas : GTLObject
// This object is documented as having more properties that are
// GTLDiscoveryJsonSchema. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRpcDescriptionAuthOauth2
//

@interface GTLDiscoveryRpcDescriptionAuthOauth2 : GTLObject

// Available OAuth 2.0 scopes.
@property (retain) GTLDiscoveryRpcDescriptionAuthOauth2Scopes *scopes;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRpcDescriptionAuthOauth2Scopes
//

@interface GTLDiscoveryRpcDescriptionAuthOauth2Scopes : GTLObject
// This object is documented as having more properties that are
// GTLDiscoveryRpcDescriptionAuthOauth2ScopesScope. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRpcDescriptionAuthOauth2ScopesScope
//

@interface GTLDiscoveryRpcDescriptionAuthOauth2ScopesScope : GTLObject

// Description of scope.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

@end
