/* Copyright (c) 2011 Google Inc.
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
//  GTLQueryPlus.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google+ API (plus/v1)
// Description:
//   The Google+ API enables developers to build on top of the Google+ platform.
// Documentation:
//   http://developers.google.com/+/api/
// Classes:
//   GTLQueryPlus (3 custom class methods, 7 custom properties)

#import "GTLQueryPlus.h"

#import "GTLPlusActivity.h"
#import "GTLPlusActivityFeed.h"
#import "GTLPlusPerson.h"

@implementation GTLQueryPlus

@dynamic activityId, alt, collection, fields, maxResults, pageToken, userId;

+ (NSDictionary *)defaultValueMap {
  NSDictionary *allMethodsMap =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"json", @"alt",
      [NSNumber numberWithInteger:20], @"maxResults",
      nil];

  NSDictionary *map =
    [NSDictionary dictionaryWithObject:allMethodsMap
                                forKey:@"***"];
  return map;
}

#pragma mark -
#pragma mark "activities" methods
// These create a GTLQueryPlus object.

+ (id)queryForActivitiesGetWithActivityId:(NSString *)activityId {
  NSString *methodName = @"plus.activities.get";
  GTLQueryPlus *query = [self queryWithMethodName:methodName];
  query.activityId = activityId;
  query.expectedObjectClass = [GTLPlusActivity class];
  return query;
}

+ (id)queryForActivitiesListWithUserId:(NSString *)userId
                            collection:(NSString *)collection {
  NSString *methodName = @"plus.activities.list";
  GTLQueryPlus *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.collection = collection;
  query.expectedObjectClass = [GTLPlusActivityFeed class];
  return query;
}

#pragma mark -
#pragma mark "people" methods
// These create a GTLQueryPlus object.

+ (id)queryForPeopleGetWithUserId:(NSString *)userId {
  NSString *methodName = @"plus.people.get";
  GTLQueryPlus *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLPlusPerson class];
  return query;
}

@end
