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
//  GTLQueryOrkut.m
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
//   GTLQueryOrkut (35 custom class methods, 16 custom properties)

#import "GTLQueryOrkut.h"

#import "GTLOrkutActivity.h"
#import "GTLOrkutActivityList.h"
#import "GTLOrkutBadge.h"
#import "GTLOrkutBadgeList.h"
#import "GTLOrkutComment.h"
#import "GTLOrkutCommentList.h"
#import "GTLOrkutCommunity.h"
#import "GTLOrkutCommunityList.h"
#import "GTLOrkutCommunityMembers.h"
#import "GTLOrkutCommunityMembersList.h"
#import "GTLOrkutCommunityMessage.h"
#import "GTLOrkutCommunityMessageList.h"
#import "GTLOrkutCommunityPoll.h"
#import "GTLOrkutCommunityPollComment.h"
#import "GTLOrkutCommunityPollCommentList.h"
#import "GTLOrkutCommunityPollList.h"
#import "GTLOrkutCommunityPollVote.h"
#import "GTLOrkutCommunityTopic.h"
#import "GTLOrkutCommunityTopicList.h"
#import "GTLOrkutCounters.h"
#import "GTLOrkutVisibility.h"

@implementation GTLQueryOrkut

@dynamic activityId, badgeId, collection, commentId, communityId, fields,
         friendsOnly, hl, isShout, maxResults, messageId, orderBy, pageToken,
         pollId, topicId, userId;

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
#pragma mark "communities" methods
// These create a GTLQueryOrkut object.

+ (id)queryForCommunitiesGetWithCommunityId:(NSInteger)communityId {
  NSString *methodName = @"orkut.communities.get";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.communityId = communityId;
  query.expectedObjectClass = [GTLOrkutCommunity class];
  return query;
}

+ (id)queryForCommunitiesListWithUserId:(NSString *)userId {
  NSString *methodName = @"orkut.communities.list";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLOrkutCommunityList class];
  return query;
}

#pragma mark -
#pragma mark "communityFollow" methods
// These create a GTLQueryOrkut object.

+ (id)queryForCommunityFollowDeleteWithCommunityId:(NSInteger)communityId
                                            userId:(NSString *)userId {
  NSString *methodName = @"orkut.communityFollow.delete";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.communityId = communityId;
  query.userId = userId;
  return query;
}

+ (id)queryForCommunityFollowInsertWithCommunityId:(NSInteger)communityId
                                            userId:(NSString *)userId {
  NSString *methodName = @"orkut.communityFollow.insert";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.communityId = communityId;
  query.userId = userId;
  query.expectedObjectClass = [GTLOrkutCommunityMembers class];
  return query;
}

#pragma mark -
#pragma mark "communityMembers" methods
// These create a GTLQueryOrkut object.

+ (id)queryForCommunityMembersDeleteWithCommunityId:(NSInteger)communityId
                                             userId:(NSString *)userId {
  NSString *methodName = @"orkut.communityMembers.delete";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.communityId = communityId;
  query.userId = userId;
  return query;
}

+ (id)queryForCommunityMembersGetWithCommunityId:(NSInteger)communityId
                                          userId:(NSString *)userId {
  NSString *methodName = @"orkut.communityMembers.get";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.communityId = communityId;
  query.userId = userId;
  query.expectedObjectClass = [GTLOrkutCommunityMembers class];
  return query;
}

+ (id)queryForCommunityMembersInsertWithCommunityId:(NSInteger)communityId
                                             userId:(NSString *)userId {
  NSString *methodName = @"orkut.communityMembers.insert";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.communityId = communityId;
  query.userId = userId;
  query.expectedObjectClass = [GTLOrkutCommunityMembers class];
  return query;
}

+ (id)queryForCommunityMembersListWithCommunityId:(NSInteger)communityId {
  NSString *methodName = @"orkut.communityMembers.list";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.communityId = communityId;
  query.expectedObjectClass = [GTLOrkutCommunityMembersList class];
  return query;
}

#pragma mark -
#pragma mark "communityMessages" methods
// These create a GTLQueryOrkut object.

+ (id)queryForCommunityMessagesDeleteWithCommunityId:(NSInteger)communityId
                                             topicId:(long long)topicId
                                           messageId:(long long)messageId {
  NSString *methodName = @"orkut.communityMessages.delete";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.communityId = communityId;
  query.topicId = topicId;
  query.messageId = messageId;
  return query;
}

+ (id)queryForCommunityMessagesInsertWithObject:(GTLOrkutCommunityMessage *)object
                                    communityId:(NSInteger)communityId
                                        topicId:(long long)topicId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"orkut.communityMessages.insert";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.communityId = communityId;
  query.topicId = topicId;
  query.expectedObjectClass = [GTLOrkutCommunityMessage class];
  return query;
}

+ (id)queryForCommunityMessagesListWithCommunityId:(NSInteger)communityId
                                           topicId:(long long)topicId {
  NSString *methodName = @"orkut.communityMessages.list";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.communityId = communityId;
  query.topicId = topicId;
  query.expectedObjectClass = [GTLOrkutCommunityMessageList class];
  return query;
}

#pragma mark -
#pragma mark "communityPollComments" methods
// These create a GTLQueryOrkut object.

+ (id)queryForCommunityPollCommentsInsertWithObject:(GTLOrkutCommunityPollComment *)object
                                        communityId:(NSInteger)communityId
                                             pollId:(NSString *)pollId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"orkut.communityPollComments.insert";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.communityId = communityId;
  query.pollId = pollId;
  query.expectedObjectClass = [GTLOrkutCommunityPollComment class];
  return query;
}

+ (id)queryForCommunityPollCommentsListWithCommunityId:(NSInteger)communityId
                                                pollId:(NSString *)pollId {
  NSString *methodName = @"orkut.communityPollComments.list";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.communityId = communityId;
  query.pollId = pollId;
  query.expectedObjectClass = [GTLOrkutCommunityPollCommentList class];
  return query;
}

#pragma mark -
#pragma mark "communityPolls" methods
// These create a GTLQueryOrkut object.

+ (id)queryForCommunityPollsGetWithCommunityId:(NSInteger)communityId
                                        pollId:(NSString *)pollId {
  NSString *methodName = @"orkut.communityPolls.get";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.communityId = communityId;
  query.pollId = pollId;
  query.expectedObjectClass = [GTLOrkutCommunityPoll class];
  return query;
}

+ (id)queryForCommunityPollsListWithCommunityId:(NSInteger)communityId {
  NSString *methodName = @"orkut.communityPolls.list";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.communityId = communityId;
  query.expectedObjectClass = [GTLOrkutCommunityPollList class];
  return query;
}

#pragma mark -
#pragma mark "communityPollVotes" methods
// These create a GTLQueryOrkut object.

+ (id)queryForCommunityPollVotesInsertWithObject:(GTLOrkutCommunityPollVote *)object
                                     communityId:(NSInteger)communityId
                                          pollId:(NSString *)pollId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"orkut.communityPollVotes.insert";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.communityId = communityId;
  query.pollId = pollId;
  query.expectedObjectClass = [GTLOrkutCommunityPollVote class];
  return query;
}

#pragma mark -
#pragma mark "communityRelated" methods
// These create a GTLQueryOrkut object.

+ (id)queryForCommunityRelatedListWithCommunityId:(NSInteger)communityId {
  NSString *methodName = @"orkut.communityRelated.list";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.communityId = communityId;
  query.expectedObjectClass = [GTLOrkutCommunityList class];
  return query;
}

#pragma mark -
#pragma mark "communityTopics" methods
// These create a GTLQueryOrkut object.

+ (id)queryForCommunityTopicsDeleteWithCommunityId:(NSInteger)communityId
                                           topicId:(long long)topicId {
  NSString *methodName = @"orkut.communityTopics.delete";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.communityId = communityId;
  query.topicId = topicId;
  return query;
}

+ (id)queryForCommunityTopicsGetWithCommunityId:(NSInteger)communityId
                                        topicId:(long long)topicId {
  NSString *methodName = @"orkut.communityTopics.get";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.communityId = communityId;
  query.topicId = topicId;
  query.expectedObjectClass = [GTLOrkutCommunityTopic class];
  return query;
}

+ (id)queryForCommunityTopicsInsertWithObject:(GTLOrkutCommunityTopic *)object
                                  communityId:(NSInteger)communityId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"orkut.communityTopics.insert";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.communityId = communityId;
  query.expectedObjectClass = [GTLOrkutCommunityTopic class];
  return query;
}

+ (id)queryForCommunityTopicsListWithCommunityId:(NSInteger)communityId {
  NSString *methodName = @"orkut.communityTopics.list";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.communityId = communityId;
  query.expectedObjectClass = [GTLOrkutCommunityTopicList class];
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

#pragma mark -
#pragma mark "scraps" methods
// These create a GTLQueryOrkut object.

+ (id)queryForScrapsInsertWithObject:(GTLOrkutActivity *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"orkut.scraps.insert";
  GTLQueryOrkut *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.expectedObjectClass = [GTLOrkutActivity class];
  return query;
}

@end
