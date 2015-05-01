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
//  GTLQueryPlusDomains.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google+ Domains API (plusDomains/v1)
// Description:
//   The Google+ API enables developers to build on top of the Google+ platform.
// Documentation:
//   https://developers.google.com/+/domains/
// Classes:
//   GTLQueryPlusDomains (20 custom class methods, 12 custom properties)

#import "GTLQueryPlusDomains.h"

#import "GTLPlusDomainsActivity.h"
#import "GTLPlusDomainsActivityFeed.h"
#import "GTLPlusDomainsAudiencesFeed.h"
#import "GTLPlusDomainsCircle.h"
#import "GTLPlusDomainsCircleFeed.h"
#import "GTLPlusDomainsComment.h"
#import "GTLPlusDomainsCommentFeed.h"
#import "GTLPlusDomainsMedia.h"
#import "GTLPlusDomainsPeopleFeed.h"
#import "GTLPlusDomainsPerson.h"

@implementation GTLQueryPlusDomains

@dynamic activityId, circleId, collection, commentId, email, fields, maxResults,
         orderBy, pageToken, preview, sortOrder, userId;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"email" : [NSString class]
  };
  return map;
}

#pragma mark -
#pragma mark "activities" methods
// These create a GTLQueryPlusDomains object.

+ (instancetype)queryForActivitiesGetWithActivityId:(NSString *)activityId {
  NSString *methodName = @"plusDomains.activities.get";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.activityId = activityId;
  query.expectedObjectClass = [GTLPlusDomainsActivity class];
  return query;
}

+ (instancetype)queryForActivitiesInsertWithObject:(GTLPlusDomainsActivity *)object
                                            userId:(NSString *)userId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"plusDomains.activities.insert";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.userId = userId;
  query.expectedObjectClass = [GTLPlusDomainsActivity class];
  return query;
}

+ (instancetype)queryForActivitiesListWithUserId:(NSString *)userId
                                      collection:(NSString *)collection {
  NSString *methodName = @"plusDomains.activities.list";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.collection = collection;
  query.expectedObjectClass = [GTLPlusDomainsActivityFeed class];
  return query;
}

#pragma mark -
#pragma mark "audiences" methods
// These create a GTLQueryPlusDomains object.

+ (instancetype)queryForAudiencesListWithUserId:(NSString *)userId {
  NSString *methodName = @"plusDomains.audiences.list";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLPlusDomainsAudiencesFeed class];
  return query;
}

#pragma mark -
#pragma mark "circles" methods
// These create a GTLQueryPlusDomains object.

+ (instancetype)queryForCirclesAddPeopleWithCircleId:(NSString *)circleId {
  NSString *methodName = @"plusDomains.circles.addPeople";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.circleId = circleId;
  query.expectedObjectClass = [GTLPlusDomainsCircle class];
  return query;
}

+ (instancetype)queryForCirclesGetWithCircleId:(NSString *)circleId {
  NSString *methodName = @"plusDomains.circles.get";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.circleId = circleId;
  query.expectedObjectClass = [GTLPlusDomainsCircle class];
  return query;
}

+ (instancetype)queryForCirclesInsertWithObject:(GTLPlusDomainsCircle *)object
                                         userId:(NSString *)userId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"plusDomains.circles.insert";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.userId = userId;
  query.expectedObjectClass = [GTLPlusDomainsCircle class];
  return query;
}

+ (instancetype)queryForCirclesListWithUserId:(NSString *)userId {
  NSString *methodName = @"plusDomains.circles.list";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLPlusDomainsCircleFeed class];
  return query;
}

+ (instancetype)queryForCirclesPatchWithObject:(GTLPlusDomainsCircle *)object
                                      circleId:(NSString *)circleId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"plusDomains.circles.patch";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.circleId = circleId;
  query.expectedObjectClass = [GTLPlusDomainsCircle class];
  return query;
}

+ (instancetype)queryForCirclesRemoveWithCircleId:(NSString *)circleId {
  NSString *methodName = @"plusDomains.circles.remove";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.circleId = circleId;
  return query;
}

+ (instancetype)queryForCirclesRemovePeopleWithCircleId:(NSString *)circleId {
  NSString *methodName = @"plusDomains.circles.removePeople";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.circleId = circleId;
  return query;
}

+ (instancetype)queryForCirclesUpdateWithObject:(GTLPlusDomainsCircle *)object
                                       circleId:(NSString *)circleId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"plusDomains.circles.update";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.circleId = circleId;
  query.expectedObjectClass = [GTLPlusDomainsCircle class];
  return query;
}

#pragma mark -
#pragma mark "comments" methods
// These create a GTLQueryPlusDomains object.

+ (instancetype)queryForCommentsGetWithCommentId:(NSString *)commentId {
  NSString *methodName = @"plusDomains.comments.get";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.commentId = commentId;
  query.expectedObjectClass = [GTLPlusDomainsComment class];
  return query;
}

+ (instancetype)queryForCommentsInsertWithObject:(GTLPlusDomainsComment *)object
                                      activityId:(NSString *)activityId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"plusDomains.comments.insert";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.activityId = activityId;
  query.expectedObjectClass = [GTLPlusDomainsComment class];
  return query;
}

+ (instancetype)queryForCommentsListWithActivityId:(NSString *)activityId {
  NSString *methodName = @"plusDomains.comments.list";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.activityId = activityId;
  query.expectedObjectClass = [GTLPlusDomainsCommentFeed class];
  return query;
}

#pragma mark -
#pragma mark "media" methods
// These create a GTLQueryPlusDomains object.

+ (instancetype)queryForMediaInsertWithObject:(GTLPlusDomainsMedia *)object
                                       userId:(NSString *)userId
                                   collection:(NSString *)collection
                             uploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"plusDomains.media.insert";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.userId = userId;
  query.collection = collection;
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLPlusDomainsMedia class];
  return query;
}

#pragma mark -
#pragma mark "people" methods
// These create a GTLQueryPlusDomains object.

+ (instancetype)queryForPeopleGetWithUserId:(NSString *)userId {
  NSString *methodName = @"plusDomains.people.get";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLPlusDomainsPerson class];
  return query;
}

+ (instancetype)queryForPeopleListWithUserId:(NSString *)userId
                                  collection:(NSString *)collection {
  NSString *methodName = @"plusDomains.people.list";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.collection = collection;
  query.expectedObjectClass = [GTLPlusDomainsPeopleFeed class];
  return query;
}

+ (instancetype)queryForPeopleListByActivityWithActivityId:(NSString *)activityId
                                                collection:(NSString *)collection {
  NSString *methodName = @"plusDomains.people.listByActivity";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.activityId = activityId;
  query.collection = collection;
  query.expectedObjectClass = [GTLPlusDomainsPeopleFeed class];
  return query;
}

+ (instancetype)queryForPeopleListByCircleWithCircleId:(NSString *)circleId {
  NSString *methodName = @"plusDomains.people.listByCircle";
  GTLQueryPlusDomains *query = [self queryWithMethodName:methodName];
  query.circleId = circleId;
  query.expectedObjectClass = [GTLPlusDomainsPeopleFeed class];
  return query;
}

@end
