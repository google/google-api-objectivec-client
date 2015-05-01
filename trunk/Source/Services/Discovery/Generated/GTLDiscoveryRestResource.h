/* Copyright (c) 2015 Google Inc.
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
//  GTLDiscoveryRestResource.h
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
//   GTLDiscoveryRestResource (0 custom class methods, 2 custom properties)
//   GTLDiscoveryRestResourceMethods (0 custom class methods, 0 custom properties)
//   GTLDiscoveryRestResourceResources (0 custom class methods, 0 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLDiscoveryRestMethod;
@class GTLDiscoveryRestResource;
@class GTLDiscoveryRestResourceMethods;
@class GTLDiscoveryRestResourceResources;

// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestResource
//

@interface GTLDiscoveryRestResource : GTLObject

// Methods on this resource.
@property (nonatomic, retain) GTLDiscoveryRestResourceMethods *methods;

// Sub-resources on this resource.
@property (nonatomic, retain) GTLDiscoveryRestResourceResources *resources;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestResourceMethods
//

@interface GTLDiscoveryRestResourceMethods : GTLObject
// This object is documented as having more properties that are
// GTLDiscoveryRestMethod. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestResourceResources
//

@interface GTLDiscoveryRestResourceResources : GTLObject
// This object is documented as having more properties that are
// GTLDiscoveryRestResource. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end
