/* Copyright (c) 2014 Google Inc.
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
//  GTLAnalyticsEntityAdWordsLink.m
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
//   GTLAnalyticsEntityAdWordsLink (0 custom class methods, 7 custom properties)
//   GTLAnalyticsEntityAdWordsLinkEntity (0 custom class methods, 1 custom properties)

#import "GTLAnalyticsEntityAdWordsLink.h"

#import "GTLAnalyticsAdWordsAccount.h"
#import "GTLAnalyticsWebPropertyRef.h"

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsEntityAdWordsLink
//

@implementation GTLAnalyticsEntityAdWordsLink
@dynamic adWordsAccounts, entity, identifier, kind, name, profileIds, selfLink;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLAnalyticsAdWordsAccount class], @"adWordsAccounts",
      [NSString class], @"profileIds",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"analytics#entityAdWordsLink"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsEntityAdWordsLinkEntity
//

@implementation GTLAnalyticsEntityAdWordsLinkEntity
@dynamic webPropertyRef;
@end
