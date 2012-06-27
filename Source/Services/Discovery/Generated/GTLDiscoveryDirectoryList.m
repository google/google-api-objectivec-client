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
//  GTLDiscoveryDirectoryList.m
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
//   GTLDiscoveryDirectoryList (0 custom class methods, 3 custom properties)
//   GTLDiscoveryDirectoryListItemsItem (0 custom class methods, 12 custom properties)
//   GTLDiscoveryDirectoryListItemsItemIcons (0 custom class methods, 2 custom properties)

#import "GTLDiscoveryDirectoryList.h"

// ----------------------------------------------------------------------------
//
//   GTLDiscoveryDirectoryList
//

@implementation GTLDiscoveryDirectoryList
@dynamic discoveryVersion, items, kind;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLDiscoveryDirectoryListItemsItem class]
                                forKey:@"items"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"discovery#directoryList"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryDirectoryListItemsItem
//

@implementation GTLDiscoveryDirectoryListItemsItem
@dynamic descriptionProperty, discoveryLink, discoveryRestUrl,
         documentationLink, icons, identifier, kind, labels, name, preferred,
         title, version;

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
    [NSDictionary dictionaryWithObject:[NSString class]
                                forKey:@"labels"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"discovery#directoryItem"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryDirectoryListItemsItemIcons
//

@implementation GTLDiscoveryDirectoryListItemsItemIcons
@dynamic x16, x32;
@end
