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
//  GTLQueryPlus.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google+ API (plus/v1)
// Description:
//   The Google+ API enables developers to build on top of the Google+ platform.
// Documentation:
//   https://developers.google.com/+/api/
// Classes:
//   GTLQueryPlus (8 custom class methods, 12 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@interface GTLQueryPlus : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (copy) NSString *activityId;
@property (copy) NSString *alt;
@property (copy) NSString *collection;
@property (copy) NSString *commentId;
@property (copy) NSString *language;
@property (assign) NSUInteger maxResults;
@property (copy) NSString *orderBy;
@property (copy) NSString *pageToken;
@property (copy) NSString *query;
@property (copy) NSString *sortOrder;
@property (copy) NSString *userId;

#pragma mark -
#pragma mark "activities" methods
// These create a GTLQueryPlus object.

// Method: plus.activities.get
// Get an activity.
//  Required:
//   activityId: The ID of the activity to get.
//  Optional:
//   alt: Specifies an alternative representation type. (Default
//     kGTLPlusAltJson)
//      kGTLPlusAltJson: Use JSON format
//  Authorization scope(s):
//   kGTLAuthScopePlusMe
// Fetches a GTLPlusActivity.
+ (id)queryForActivitiesGetWithActivityId:(NSString *)activityId;

// Method: plus.activities.list
// List all of the activities in the specified collection for a particular user.
//  Required:
//   userId: The ID of the user to get activities for. The special value "me"
//     can be used to indicate the authenticated user.
//   collection: The collection of activities to list.
//      kGTLPlusCollectionPublic: All public activities created by the specified
//        user.
//  Optional:
//   alt: Specifies an alternative representation type. (Default
//     kGTLPlusAltJson)
//      kGTLPlusAltJson: Use JSON format
//   maxResults: The maximum number of activities to include in the response,
//     used for paging. For any response, the actual number returned may be less
//     than the specified maxResults. (1..100, default 20)
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopePlusMe
// Fetches a GTLPlusActivityFeed.
+ (id)queryForActivitiesListWithUserId:(NSString *)userId
                            collection:(NSString *)collection;

// Method: plus.activities.search
// Search public activities.
//  Required:
//   query: Full-text search query string.
//  Optional:
//   language: Specify the preferred language to search with. See search
//     language codes for available values.
//   maxResults: The maximum number of activities to include in the response,
//     used for paging. For any response, the actual number returned may be less
//     than the specified maxResults. (1..20, default 10)
//   orderBy: Specifies how to order search results. (Default
//     kGTLPlusOrderByRecent)
//      kGTLPlusOrderByBest: Sort activities by relevance to the user, most
//        relevant first.
//      kGTLPlusOrderByRecent: Sort activities by published date, most recent
//        first.
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     "nextPageToken" from the previous response. This token may be of any
//     length.
//  Authorization scope(s):
//   kGTLAuthScopePlusMe
// Fetches a GTLPlusActivityFeed.
+ (id)queryForActivitiesSearchWithQuery:(NSString *)query;

#pragma mark -
#pragma mark "comments" methods
// These create a GTLQueryPlus object.

// Method: plus.comments.get
// Get a comment.
//  Required:
//   commentId: The ID of the comment to get.
//  Authorization scope(s):
//   kGTLAuthScopePlusMe
// Fetches a GTLPlusComment.
+ (id)queryForCommentsGetWithCommentId:(NSString *)commentId;

// Method: plus.comments.list
// List all of the comments for an activity.
//  Required:
//   activityId: The ID of the activity to get comments for.
//  Optional:
//   alt: Specifies an alternative representation type. (Default
//     kGTLPlusAltJson)
//      kGTLPlusAltJson: Use JSON format
//   maxResults: The maximum number of comments to include in the response, used
//     for paging. For any response, the actual number returned may be less than
//     the specified maxResults. (0..100, default 20)
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     "nextPageToken" from the previous response.
//   sortOrder: The order in which to sort the list of comments. (Default
//     kGTLPlusSortOrderAscending)
//      kGTLPlusSortOrderAscending: Sort oldest comments first.
//      kGTLPlusSortOrderDescending: Sort newest comments first.
//  Authorization scope(s):
//   kGTLAuthScopePlusMe
// Fetches a GTLPlusCommentFeed.
+ (id)queryForCommentsListWithActivityId:(NSString *)activityId;

#pragma mark -
#pragma mark "people" methods
// These create a GTLQueryPlus object.

// Method: plus.people.get
// Get a person's profile.
//  Required:
//   userId: The ID of the person to get the profile for. The special value "me"
//     can be used to indicate the authenticated user.
//  Authorization scope(s):
//   kGTLAuthScopePlusMe
//   kGTLAuthScopePlusUserinfoEmail
// Fetches a GTLPlusPerson.
+ (id)queryForPeopleGetWithUserId:(NSString *)userId;

// Method: plus.people.listByActivity
// List all of the people in the specified collection for a particular activity.
//  Required:
//   activityId: The ID of the activity to get the list of people for.
//   collection: The collection of people to list.
//      kGTLPlusCollectionPlusoners: List all people who have +1'd this
//        activity.
//      kGTLPlusCollectionResharers: List all people who have reshared this
//        activity.
//  Optional:
//   maxResults: The maximum number of people to include in the response, used
//     for paging. For any response, the actual number returned may be less than
//     the specified maxResults. (1..100, default 20)
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopePlusMe
// Fetches a GTLPlusPeopleFeed.
+ (id)queryForPeopleListByActivityWithActivityId:(NSString *)activityId
                                      collection:(NSString *)collection;

// Method: plus.people.search
// Search all public profiles.
//  Required:
//   query: Specify a query string for full text search of public text in all
//     profiles.
//  Optional:
//   language: Specify the preferred language to search with. See search
//     language codes for available values.
//   maxResults: The maximum number of people to include in the response, used
//     for paging. For any response, the actual number returned may be less than
//     the specified maxResults. (1..20, default 10)
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     "nextPageToken" from the previous response. This token may be of any
//     length.
//  Authorization scope(s):
//   kGTLAuthScopePlusMe
// Fetches a GTLPlusPeopleFeed.
+ (id)queryForPeopleSearchWithQuery:(NSString *)query;

@end
