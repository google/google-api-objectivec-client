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
//  GTLQueryOrkut.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLOrkutActivity;
@class GTLOrkutComment;
@class GTLOrkutCommunityMessage;
@class GTLOrkutCommunityPollComment;
@class GTLOrkutCommunityPollVote;
@class GTLOrkutCommunityTopic;
@class GTLOrkutVisibility;

@interface GTLQueryOrkut : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (copy) NSString *activityId;
@property (assign) long long badgeId;
@property (copy) NSString *collection;
@property (copy) NSString *commentId;
@property (assign) NSInteger communityId;
@property (assign) BOOL friendsOnly;
@property (copy) NSString *hl;
@property (assign) BOOL isShout;
@property (assign) NSUInteger maxResults;
@property (assign) long long messageId;
@property (copy) NSString *orderBy;
@property (copy) NSString *pageToken;
@property (copy) NSString *pollId;
@property (assign) long long topicId;
@property (copy) NSString *userId;

#pragma mark -
#pragma mark "acl" methods
// These create a GTLQueryOrkut object.

// Method: orkut.acl.delete
// Excludes an element from the ACL of the activity.
//  Required:
//   activityId: ID of the activity.
//   userId: ID of the user to be removed from the activity.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
+ (id)queryForAclDeleteWithActivityId:(NSString *)activityId
                               userId:(NSString *)userId;

#pragma mark -
#pragma mark "activities" methods
// These create a GTLQueryOrkut object.

// Method: orkut.activities.delete
// Deletes an existing activity, if the access controls allow it.
//  Required:
//   activityId: ID of the activity to remove.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
+ (id)queryForActivitiesDeleteWithActivityId:(NSString *)activityId;

// Method: orkut.activities.list
// Retrieves a list of activities.
//  Required:
//   userId: The ID of the user whose activities will be listed. Can be me to
//     refer to the viewer (i.e. the authenticated user).
//   collection: The collection of activities to list.
//      kGTLOrkutCollectionAll: All activities created by the specified user
//        that the authenticated user is authorized to view.
//      kGTLOrkutCollectionScraps: The specified user's scrapbook.
//      kGTLOrkutCollectionStream: The specified user's stream feed, intended
//        for consumption. This includes activities posted by people that the
//        user is following, and activities in which the user has been
//        mentioned.
//  Optional:
//   hl: Specifies the interface language (host language) of your user
//     interface.
//   maxResults: The maximum number of activities to include in the response.
//     (1..100)
//   pageToken: A continuation token that allows pagination.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutActivityList.
+ (id)queryForActivitiesListWithUserId:(NSString *)userId
                            collection:(NSString *)collection;

#pragma mark -
#pragma mark "activityVisibility" methods
// These create a GTLQueryOrkut object.

// Method: orkut.activityVisibility.get
// Gets the visibility of an existing activity.
//  Required:
//   activityId: ID of the activity to get the visibility.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutVisibility.
+ (id)queryForActivityVisibilityGetWithActivityId:(NSString *)activityId;

// Method: orkut.activityVisibility.patch
// Updates the visibility of an existing activity. This method supports patch
// semantics.
//  Required:
//   activityId: ID of the activity.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
// Fetches a GTLOrkutVisibility.
+ (id)queryForActivityVisibilityPatchWithObject:(GTLOrkutVisibility *)object
                                     activityId:(NSString *)activityId;

// Method: orkut.activityVisibility.update
// Updates the visibility of an existing activity.
//  Required:
//   activityId: ID of the activity.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
// Fetches a GTLOrkutVisibility.
+ (id)queryForActivityVisibilityUpdateWithObject:(GTLOrkutVisibility *)object
                                      activityId:(NSString *)activityId;

#pragma mark -
#pragma mark "badges" methods
// These create a GTLQueryOrkut object.

// Method: orkut.badges.get
// Retrieves a badge from a user.
//  Required:
//   userId: The ID of the user whose badges will be listed. Can be me to refer
//     to caller.
//   badgeId: The ID of the badge that will be retrieved.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutBadge.
+ (id)queryForBadgesGetWithUserId:(NSString *)userId
                          badgeId:(long long)badgeId;

// Method: orkut.badges.list
// Retrieves the list of visible badges of a user.
//  Required:
//   userId: The id of the user whose badges will be listed. Can be me to refer
//     to caller.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutBadgeList.
+ (id)queryForBadgesListWithUserId:(NSString *)userId;

#pragma mark -
#pragma mark "comments" methods
// These create a GTLQueryOrkut object.

// Method: orkut.comments.delete
// Deletes an existing comment.
//  Required:
//   commentId: ID of the comment to remove.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
+ (id)queryForCommentsDeleteWithCommentId:(NSString *)commentId;

// Method: orkut.comments.get
// Retrieves an existing comment.
//  Required:
//   commentId: ID of the comment to get.
//  Optional:
//   hl: Specifies the interface language (host language) of your user
//     interface.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutComment.
+ (id)queryForCommentsGetWithCommentId:(NSString *)commentId;

// Method: orkut.comments.insert
// Inserts a new comment to an activity.
//  Required:
//   activityId: The ID of the activity to contain the new comment.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
// Fetches a GTLOrkutComment.
+ (id)queryForCommentsInsertWithObject:(GTLOrkutComment *)object
                            activityId:(NSString *)activityId;

// Method: orkut.comments.list
// Retrieves a list of comments, possibly filtered.
//  Required:
//   activityId: The ID of the activity containing the comments.
//  Optional:
//   hl: Specifies the interface language (host language) of your user
//     interface.
//   maxResults: The maximum number of activities to include in the response.
//   orderBy: Sort search results. (Default "DESCENDING_SORT")
//      kGTLOrkutOrderByAscending: Use ascending sort order.
//      kGTLOrkutOrderByDescending: Use descending sort order.
//   pageToken: A continuation token that allows pagination.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutCommentList.
+ (id)queryForCommentsListWithActivityId:(NSString *)activityId;

#pragma mark -
#pragma mark "communities" methods
// These create a GTLQueryOrkut object.

// Method: orkut.communities.get
// Retrieves the basic information (aka. profile) of a community.
//  Required:
//   communityId: The ID of the community to get.
//  Optional:
//   hl: Specifies the interface language (host language) of your user
//     interface.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutCommunity.
+ (id)queryForCommunitiesGetWithCommunityId:(NSInteger)communityId;

// Method: orkut.communities.list
// Retrieves the list of communities the current user is a member of.
//  Required:
//   userId: The ID of the user whose communities will be listed. Can be me to
//     refer to caller.
//  Optional:
//   hl: Specifies the interface language (host language) of your user
//     interface.
//   maxResults: The maximum number of communities to include in the response.
//   orderBy: How to order the communities by.
//      kGTLOrkutOrderById: Returns the communities sorted by a fixed, natural
//        order.
//      kGTLOrkutOrderByRanked: Returns the communities ranked accordingly to
//        how they are displayed on the orkut web application.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutCommunityList.
+ (id)queryForCommunitiesListWithUserId:(NSString *)userId;

#pragma mark -
#pragma mark "communityFollow" methods
// These create a GTLQueryOrkut object.

// Method: orkut.communityFollow.delete
// Removes a user from the followers of a community.
//  Required:
//   communityId: ID of the community.
//   userId: ID of the user.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
+ (id)queryForCommunityFollowDeleteWithCommunityId:(NSInteger)communityId
                                            userId:(NSString *)userId;

// Method: orkut.communityFollow.insert
// Adds a user as a follower of a community.
//  Required:
//   communityId: ID of the community.
//   userId: ID of the user.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
// Fetches a GTLOrkutCommunityMembers.
+ (id)queryForCommunityFollowInsertWithCommunityId:(NSInteger)communityId
                                            userId:(NSString *)userId;

#pragma mark -
#pragma mark "communityMembers" methods
// These create a GTLQueryOrkut object.

// Method: orkut.communityMembers.delete
// Makes the user leave a community.
//  Required:
//   communityId: ID of the community.
//   userId: ID of the user.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
+ (id)queryForCommunityMembersDeleteWithCommunityId:(NSInteger)communityId
                                             userId:(NSString *)userId;

// Method: orkut.communityMembers.get
// Retrieves the relationship between a user and a community.
//  Required:
//   communityId: ID of the community.
//   userId: ID of the user.
//  Optional:
//   hl: Specifies the interface language (host language) of your user
//     interface.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutCommunityMembers.
+ (id)queryForCommunityMembersGetWithCommunityId:(NSInteger)communityId
                                          userId:(NSString *)userId;

// Method: orkut.communityMembers.insert
// Makes the user join a community.
//  Required:
//   communityId: ID of the community.
//   userId: ID of the user.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
// Fetches a GTLOrkutCommunityMembers.
+ (id)queryForCommunityMembersInsertWithCommunityId:(NSInteger)communityId
                                             userId:(NSString *)userId;

// Method: orkut.communityMembers.list
// Lists members of a community. Use the pagination tokens to retrieve the full
// list; do not rely on the member count available in the community profile
// information to know when to stop iterating, as that count may be approximate.
//  Required:
//   communityId: The ID of the community whose members will be listed.
//  Optional:
//   friendsOnly: Whether to list only community members who are friends of the
//     user.
//   hl: Specifies the interface language (host language) of your user
//     interface.
//   maxResults: The maximum number of members to include in the response.
//   pageToken: A continuation token that allows pagination.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutCommunityMembersList.
+ (id)queryForCommunityMembersListWithCommunityId:(NSInteger)communityId;

#pragma mark -
#pragma mark "communityMessages" methods
// These create a GTLQueryOrkut object.

// Method: orkut.communityMessages.delete
// Moves a message of the community to the trash folder.
//  Required:
//   communityId: The ID of the community whose message will be moved to the
//     trash folder.
//   topicId: The ID of the topic whose message will be moved to the trash
//     folder.
//   messageId: The ID of the message to be moved to the trash folder.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
+ (id)queryForCommunityMessagesDeleteWithCommunityId:(NSInteger)communityId
                                             topicId:(long long)topicId
                                           messageId:(long long)messageId;

// Method: orkut.communityMessages.insert
// Adds a message to a given community topic.
//  Required:
//   communityId: The ID of the community the message should be added to.
//   topicId: The ID of the topic the message should be added to.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
// Fetches a GTLOrkutCommunityMessage.
+ (id)queryForCommunityMessagesInsertWithObject:(GTLOrkutCommunityMessage *)object
                                    communityId:(NSInteger)communityId
                                        topicId:(long long)topicId;

// Method: orkut.communityMessages.list
// Retrieves the messages of a topic of a community.
//  Required:
//   communityId: The ID of the community which messages will be listed.
//   topicId: The ID of the topic which messages will be listed.
//  Optional:
//   hl: Specifies the interface language (host language) of your user
//     interface.
//   maxResults: The maximum number of messages to include in the response.
//     (1..100)
//   pageToken: A continuation token that allows pagination.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutCommunityMessageList.
+ (id)queryForCommunityMessagesListWithCommunityId:(NSInteger)communityId
                                           topicId:(long long)topicId;

#pragma mark -
#pragma mark "communityPollComments" methods
// These create a GTLQueryOrkut object.

// Method: orkut.communityPollComments.insert
// Adds a comment on a community poll.
//  Required:
//   communityId: The ID of the community whose poll is being commented.
//   pollId: The ID of the poll being commented.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
// Fetches a GTLOrkutCommunityPollComment.
+ (id)queryForCommunityPollCommentsInsertWithObject:(GTLOrkutCommunityPollComment *)object
                                        communityId:(NSInteger)communityId
                                             pollId:(NSString *)pollId;

// Method: orkut.communityPollComments.list
// Retrieves the comments of a community poll.
//  Required:
//   communityId: The ID of the community whose poll is having its comments
//     listed.
//   pollId: The ID of the community whose polls will be listed.
//  Optional:
//   hl: Specifies the interface language (host language) of your user
//     interface.
//   maxResults: The maximum number of comments to include in the response.
//   pageToken: A continuation token that allows pagination.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutCommunityPollCommentList.
+ (id)queryForCommunityPollCommentsListWithCommunityId:(NSInteger)communityId
                                                pollId:(NSString *)pollId;

#pragma mark -
#pragma mark "communityPolls" methods
// These create a GTLQueryOrkut object.

// Method: orkut.communityPolls.get
// Retrieves one specific poll of a community.
//  Required:
//   communityId: The ID of the community for whose poll will be retrieved.
//   pollId: The ID of the poll to get.
//  Optional:
//   hl: Specifies the interface language (host language) of your user
//     interface.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutCommunityPoll.
+ (id)queryForCommunityPollsGetWithCommunityId:(NSInteger)communityId
                                        pollId:(NSString *)pollId;

// Method: orkut.communityPolls.list
// Retrieves the polls of a community.
//  Required:
//   communityId: The ID of the community which polls will be listed.
//  Optional:
//   hl: Specifies the interface language (host language) of your user
//     interface.
//   maxResults: The maximum number of polls to include in the response.
//   pageToken: A continuation token that allows pagination.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutCommunityPollList.
+ (id)queryForCommunityPollsListWithCommunityId:(NSInteger)communityId;

#pragma mark -
#pragma mark "communityPollVotes" methods
// These create a GTLQueryOrkut object.

// Method: orkut.communityPollVotes.insert
// Votes on a community poll.
//  Required:
//   communityId: The ID of the community whose poll is being voted.
//   pollId: The ID of the poll being voted.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
// Fetches a GTLOrkutCommunityPollVote.
+ (id)queryForCommunityPollVotesInsertWithObject:(GTLOrkutCommunityPollVote *)object
                                     communityId:(NSInteger)communityId
                                          pollId:(NSString *)pollId;

#pragma mark -
#pragma mark "communityRelated" methods
// These create a GTLQueryOrkut object.

// Method: orkut.communityRelated.list
// Retrieves the communities related to another one.
//  Required:
//   communityId: The ID of the community whose related communities will be
//     listed.
//  Optional:
//   hl: Specifies the interface language (host language) of your user
//     interface.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutCommunityList.
+ (id)queryForCommunityRelatedListWithCommunityId:(NSInteger)communityId;

#pragma mark -
#pragma mark "communityTopics" methods
// These create a GTLQueryOrkut object.

// Method: orkut.communityTopics.delete
// Moves a topic of the community to the trash folder.
//  Required:
//   communityId: The ID of the community whose topic will be moved to the trash
//     folder.
//   topicId: The ID of the topic to be moved to the trash folder.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
+ (id)queryForCommunityTopicsDeleteWithCommunityId:(NSInteger)communityId
                                           topicId:(long long)topicId;

// Method: orkut.communityTopics.get
// Retrieves a topic of a community.
//  Required:
//   communityId: The ID of the community whose topic will be retrieved.
//   topicId: The ID of the topic to get.
//  Optional:
//   hl: Specifies the interface language (host language) of your user
//     interface.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutCommunityTopic.
+ (id)queryForCommunityTopicsGetWithCommunityId:(NSInteger)communityId
                                        topicId:(long long)topicId;

// Method: orkut.communityTopics.insert
// Adds a topic to a given community.
//  Required:
//   communityId: The ID of the community the topic should be added to.
//  Optional:
//   isShout: Whether this topic is a shout.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
// Fetches a GTLOrkutCommunityTopic.
+ (id)queryForCommunityTopicsInsertWithObject:(GTLOrkutCommunityTopic *)object
                                  communityId:(NSInteger)communityId;

// Method: orkut.communityTopics.list
// Retrieves the topics of a community.
//  Required:
//   communityId: The ID of the community which topics will be listed.
//  Optional:
//   hl: Specifies the interface language (host language) of your user
//     interface.
//   maxResults: The maximum number of topics to include in the response.
//     (1..100)
//   pageToken: A continuation token that allows pagination.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutCommunityTopicList.
+ (id)queryForCommunityTopicsListWithCommunityId:(NSInteger)communityId;

#pragma mark -
#pragma mark "counters" methods
// These create a GTLQueryOrkut object.

// Method: orkut.counters.list
// Retrieves the counters of a user.
//  Required:
//   userId: The ID of the user whose counters will be listed. Can be me to
//     refer to caller.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutCounters.
+ (id)queryForCountersListWithUserId:(NSString *)userId;

#pragma mark -
#pragma mark "scraps" methods
// These create a GTLQueryOrkut object.

// Method: orkut.scraps.insert
// Creates a new scrap.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
// Fetches a GTLOrkutActivity.
+ (id)queryForScrapsInsertWithObject:(GTLOrkutActivity *)object;

@end
