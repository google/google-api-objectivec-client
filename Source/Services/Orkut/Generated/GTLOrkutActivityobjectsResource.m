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
//  GTLOrkutActivityobjectsResource.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Orkut API (orkut/v2)
// Description:
//   Lets you manage activities, comments and badges in Orkut. More stuff coming
//   in time.
// Documentation:
//   http://code.google.com/apis/orkut/v2/reference.html
// Classes:
//   GTLOrkutActivityobjectsResource (0 custom class methods, 7 custom properties)

#import "GTLOrkutActivityobjectsResource.h"

#import "GTLOrkutActivitypersonResource.h"
#import "GTLOrkutCommunity.h"
#import "GTLOrkutLinkResource.h"

// ----------------------------------------------------------------------------
//
//   GTLOrkutActivityobjectsResource
//

@implementation GTLOrkutActivityobjectsResource
@dynamic community, content, displayName, identifier, links, objectType, person;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLOrkutLinkResource class]
                                forKey:@"links"];
  return map;
}

@end
