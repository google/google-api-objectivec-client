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
//  GTLQueryOrkut.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLOrkutComment;
@class GTLOrkutVisibility;

@interface GTLQueryOrkut : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (retain) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (retain) NSString *activityId;
@property (assign) long long badgeId;
@property (retain) NSString *collection;
@property (retain) NSString *commentId;
@property (retain) NSString *hl;
@property (assign) NSUInteger maxResults;
@property (retain) NSString *orderBy;
@property (retain) NSString *pageToken;
@property (retain) NSString *userId;

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
//     (1-100)
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
//   orderBy: Sort search results. (Default kGTLOrkutOrderByDescending)
//      kGTLOrkutOrderByAscending: Use ascending sort order.
//      kGTLOrkutOrderByDescending: Use descending sort order.
//   pageToken: A continuation token that allows pagination.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
//   kGTLAuthScopeOrkutReadonly
// Fetches a GTLOrkutCommentList.
+ (id)queryForCommentsListWithActivityId:(NSString *)activityId;

#pragma mark -
#pragma mark "counters" methods
// These create a GTLQueryOrkut object.

// Method: orkut.counters.list
// Retrieves the counters of an user.
//  Required:
//   userId: The ID of the user whose counters will be listed. Can be me to
//     refer to caller.
//  Authorization scope(s):
//   kGTLAuthScopeOrkut
// Fetches a GTLOrkutCounters.
+ (id)queryForCountersListWithUserId:(NSString *)userId;

@end
