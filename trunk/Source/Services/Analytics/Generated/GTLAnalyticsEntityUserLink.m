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
//  GTLAnalyticsEntityUserLink.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Analytics API (analytics/v3)
// Description:
//   View and manage your Google Analytics data
// Documentation:
//   https://developers.google.com/analytics/
// Classes:
//   GTLAnalyticsEntityUserLink (0 custom class methods, 6 custom properties)
//   GTLAnalyticsEntityUserLinkEntity (0 custom class methods, 3 custom properties)
//   GTLAnalyticsEntityUserLinkPermissions (0 custom class methods, 2 custom properties)

#import "GTLAnalyticsEntityUserLink.h"

#import "GTLAnalyticsAccountRef.h"
#import "GTLAnalyticsProfileRef.h"
#import "GTLAnalyticsUserRef.h"
#import "GTLAnalyticsWebPropertyRef.h"

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsEntityUserLink
//

@implementation GTLAnalyticsEntityUserLink
@dynamic entity, identifier, kind, permissions, selfLink, userRef;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"analytics#entityUserLink"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsEntityUserLinkEntity
//

@implementation GTLAnalyticsEntityUserLinkEntity
@dynamic accountRef, profileRef, webPropertyRef;
@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsEntityUserLinkPermissions
//

@implementation GTLAnalyticsEntityUserLinkPermissions
@dynamic effective, local;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [NSString class], @"effective",
      [NSString class], @"local",
      nil];
  return map;
}

@end
