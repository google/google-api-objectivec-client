/* Copyright (c) 2016 Google Inc.
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
//   Builds on top of the Google+ platform.
// Documentation:
//   https://developers.google.com/+/api/
// Classes:
//   GTLQueryPlus (9 custom class methods, 11 custom properties)

#import "GTLQueryPlus.h"

#import "GTLPlusActivity.h"
#import "GTLPlusActivityFeed.h"
#import "GTLPlusComment.h"
#import "GTLPlusCommentFeed.h"
#import "GTLPlusPeopleFeed.h"
#import "GTLPlusPerson.h"

@implementation GTLQueryPlus

@dynamic activityId, collection, commentId, fields, language, maxResults,
         orderBy, pageToken, query, sortOrder, userId;

#pragma mark - "activities" methods
// These create a GTLQueryPlus object.

+ (instancetype)queryForActivitiesGetWithActivityId:(NSString *)activityId {
  NSString *methodName = @"plus.activities.get";
  GTLQueryPlus *query = [self queryWithMethodName:methodName];
  query.activityId = activityId;
  query.expectedObjectClass = [GTLPlusActivity class];
  return query;
}

+ (instancetype)queryForActivitiesListWithUserId:(NSString *)userId
                                      collection:(NSString *)collection {
  NSString *methodName = @"plus.activities.list";
  GTLQueryPlus *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.collection = collection;
  query.expectedObjectClass = [GTLPlusActivityFeed class];
  return query;
}

+ (instancetype)queryForActivitiesSearchWithQuery:(NSString *)query_param {
  NSString *methodName = @"plus.activities.search";
  GTLQueryPlus *query = [self queryWithMethodName:methodName];
  query.query = query_param;
  query.expectedObjectClass = [GTLPlusActivityFeed class];
  return query;
}

#pragma mark - "comments" methods
// These create a GTLQueryPlus object.

+ (instancetype)queryForCommentsGetWithCommentId:(NSString *)commentId {
  NSString *methodName = @"plus.comments.get";
  GTLQueryPlus *query = [self queryWithMethodName:methodName];
  query.commentId = commentId;
  query.expectedObjectClass = [GTLPlusComment class];
  return query;
}

+ (instancetype)queryForCommentsListWithActivityId:(NSString *)activityId {
  NSString *methodName = @"plus.comments.list";
  GTLQueryPlus *query = [self queryWithMethodName:methodName];
  query.activityId = activityId;
  query.expectedObjectClass = [GTLPlusCommentFeed class];
  return query;
}

#pragma mark - "people" methods
// These create a GTLQueryPlus object.

+ (instancetype)queryForPeopleGetWithUserId:(NSString *)userId {
  NSString *methodName = @"plus.people.get";
  GTLQueryPlus *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLPlusPerson class];
  return query;
}

+ (instancetype)queryForPeopleListWithUserId:(NSString *)userId
                                  collection:(NSString *)collection {
  NSString *methodName = @"plus.people.list";
  GTLQueryPlus *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.collection = collection;
  query.expectedObjectClass = [GTLPlusPeopleFeed class];
  return query;
}

+ (instancetype)queryForPeopleListByActivityWithActivityId:(NSString *)activityId
                                                collection:(NSString *)collection {
  NSString *methodName = @"plus.people.listByActivity";
  GTLQueryPlus *query = [self queryWithMethodName:methodName];
  query.activityId = activityId;
  query.collection = collection;
  query.expectedObjectClass = [GTLPlusPeopleFeed class];
  return query;
}

+ (instancetype)queryForPeopleSearchWithQuery:(NSString *)query_param {
  NSString *methodName = @"plus.people.search";
  GTLQueryPlus *query = [self queryWithMethodName:methodName];
  query.query = query_param;
  query.expectedObjectClass = [GTLPlusPeopleFeed class];
  return query;
}

@end
