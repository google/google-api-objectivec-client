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
//  GTLDiscoveryDirectoryList.h
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
//   GTLDiscoveryDirectoryList (0 custom class methods, 3 custom properties)
//   GTLDiscoveryDirectoryListItemsItem (0 custom class methods, 12 custom properties)
//   GTLDiscoveryDirectoryListItemsItemIcons (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLDiscoveryDirectoryListItemsItem;
@class GTLDiscoveryDirectoryListItemsItemIcons;

// ----------------------------------------------------------------------------
//
//   GTLDiscoveryDirectoryList
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLDiscoveryDirectoryList : GTLCollectionObject

// Indicate the version of the Discovery API used to generate this doc.
@property (copy) NSString *discoveryVersion;

// The individual directory entries. One entry per api/version pair.
@property (retain) NSArray *items;  // of GTLDiscoveryDirectoryListItemsItem

// The kind for this response.
@property (copy) NSString *kind;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryDirectoryListItemsItem
//

@interface GTLDiscoveryDirectoryListItemsItem : GTLObject

// The description of this API.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// A link to the discovery document.
@property (copy) NSString *discoveryLink;

// The URL for the discovery REST document.
@property (copy) NSString *discoveryRestUrl;

// A link to human readable documentation for the API.
@property (copy) NSString *documentationLink;

// Links to 16x16 and 32x32 icons representing the API.
@property (retain) GTLDiscoveryDirectoryListItemsItemIcons *icons;

// The id of this API.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The kind for this response.
@property (copy) NSString *kind;

// Labels for the status of this API, such as labs or deprecated.
@property (retain) NSArray *labels;  // of NSString

// The name of the API.
@property (copy) NSString *name;

// True if this version is the preferred version to use.
@property (retain) NSNumber *preferred;  // boolValue

// The title of this API.
@property (copy) NSString *title;

// The version of the API.
@property (copy) NSString *version;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryDirectoryListItemsItemIcons
//

@interface GTLDiscoveryDirectoryListItemsItemIcons : GTLObject

// The URL of the 16x16 icon.
@property (copy) NSString *x16;

// The URL of the 32x32 icon.
@property (copy) NSString *x32;

@end
