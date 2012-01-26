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
//  GTLOrkutCommunity.m
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
//   GTLOrkutCommunity (0 custom class methods, 14 custom properties)

#import "GTLOrkutCommunity.h"

#import "GTLOrkutAuthorResource.h"
#import "GTLOrkutLinkResource.h"

// ----------------------------------------------------------------------------
//
//   GTLOrkutCommunity
//

@implementation GTLOrkutCommunity
@dynamic category, coOwners, creationDate, descriptionProperty, identifier,
         kind, language, links, location, memberCount, moderators, name, owner,
         photoUrl;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"co_owners", @"coOwners",
      @"creation_date", @"creationDate",
      @"description", @"descriptionProperty",
      @"id", @"identifier",
      @"member_count", @"memberCount",
      @"photo_url", @"photoUrl",
      nil];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLOrkutAuthorResource class], @"co_owners",
      [GTLOrkutLinkResource class], @"links",
      [GTLOrkutAuthorResource class], @"moderators",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"orkut#community"];
}

@end
