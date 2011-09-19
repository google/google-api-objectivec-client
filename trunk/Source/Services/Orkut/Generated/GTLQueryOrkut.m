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
//  GTLQueryOrkut.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Orkut API (orkut/v2)
// Description:
//   Lets you manage activities, comments and badges in orkut. More stuff coming
//   in time.
// Documentation:
//   http://code.google.com/apis/orkut/v2/reference.html
// Classes:
//   GTLQueryOrkut (13 custom class methods, 10 custom properties)

#import "GTLQueryOrkut.h"

#import "GTLOrkutActivityList.h"
#import "GTLOrkutBadge.h"
#import "GTLOrkutBadgeList.h"
#import "GTLOrkutComment.h"
#import "GTLOrkutCommentList.h"
#import "GTLOrkutCounters.h"
#import "GTLOrkutVisibility.h"

@implementation GTLQueryOrkut

@dynamic activityId, badgeId, collection, commentId, fields, hl, maxResults,
         orderBy, pageToken, userId;

+ (NSDictionary *)defaultValueMap {
  NSDictionary *allMethodsMap =
    [NSDictionary dictionaryWithObject:@"descending"
                                forKey:@"orderBy"];

  NSDictionary *map =
    [NSDictionary dictionaryWithObject:allMethodsMap
                                forKey:@"***"];
  return map;
}

#pragma mark -
#pragma mark "acl" methods
// These create a GTLQueryOrkut object.

+ (id)queryForAclDeleteWithActivityId:(NSString *)activityId
                               userId:(NSString *)userId {
  NSString *methodName = @"orkut.acl.delete";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.activityId = activityId;
  query.userId = userId;
  return query;
}

#pragma mark -
#pragma mark "activities" methods
// These create a GTLQueryOrkut object.

+ (id)queryForActivitiesDeleteWithActivityId:(NSString *)activityId {
  NSString *methodName = @"orkut.activities.delete";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.activityId = activityId;
  return query;
}

+ (id)queryForActivitiesListWithUserId:(NSString *)userId
                            collection:(NSString *)collection {
  NSString *methodName = @"orkut.activities.list";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.collection = collection;
  query.expectedObjectClass = [GTLOrkutActivityList class];
  return query;
}

#pragma mark -
#pragma mark "activityVisibility" methods
// These create a GTLQueryOrkut object.

+ (id)queryForActivityVisibilityGetWithActivityId:(NSString *)activityId {
  NSString *methodName = @"orkut.activityVisibility.get";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.activityId = activityId;
  query.expectedObjectClass = [GTLOrkutVisibility class];
  return query;
}

+ (id)queryForActivityVisibilityPatchWithObject:(GTLOrkutVisibility *)object
                                     activityId:(NSString *)activityId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"orkut.activityVisibility.patch";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.activityId = activityId;
  query.expectedObjectClass = [GTLOrkutVisibility class];
  return query;
}

+ (id)queryForActivityVisibilityUpdateWithObject:(GTLOrkutVisibility *)object
                                      activityId:(NSString *)activityId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"orkut.activityVisibility.update";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.activityId = activityId;
  query.expectedObjectClass = [GTLOrkutVisibility class];
  return query;
}

#pragma mark -
#pragma mark "badges" methods
// These create a GTLQueryOrkut object.

+ (id)queryForBadgesGetWithUserId:(NSString *)userId
                          badgeId:(long long)badgeId {
  NSString *methodName = @"orkut.badges.get";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.badgeId = badgeId;
  query.expectedObjectClass = [GTLOrkutBadge class];
  return query;
}

+ (id)queryForBadgesListWithUserId:(NSString *)userId {
  NSString *methodName = @"orkut.badges.list";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLOrkutBadgeList class];
  return query;
}

#pragma mark -
#pragma mark "comments" methods
// These create a GTLQueryOrkut object.

+ (id)queryForCommentsDeleteWithCommentId:(NSString *)commentId {
  NSString *methodName = @"orkut.comments.delete";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.commentId = commentId;
  return query;
}

+ (id)queryForCommentsGetWithCommentId:(NSString *)commentId {
  NSString *methodName = @"orkut.comments.get";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.commentId = commentId;
  query.expectedObjectClass = [GTLOrkutComment class];
  return query;
}

+ (id)queryForCommentsInsertWithObject:(GTLOrkutComment *)object
                            activityId:(NSString *)activityId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"orkut.comments.insert";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.activityId = activityId;
  query.expectedObjectClass = [GTLOrkutComment class];
  return query;
}

+ (id)queryForCommentsListWithActivityId:(NSString *)activityId {
  NSString *methodName = @"orkut.comments.list";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.activityId = activityId;
  query.expectedObjectClass = [GTLOrkutCommentList class];
  return query;
}

#pragma mark -
#pragma mark "counters" methods
// These create a GTLQueryOrkut object.

+ (id)queryForCountersListWithUserId:(NSString *)userId {
  NSString *methodName = @"orkut.counters.list";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLOrkutCounters class];
  return query;
}

@end
