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
//  GTLQueryYouTube.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   YouTube API (youtube/v3)
// Description:
//   Programmatic access to YouTube features.
// Documentation:
//   https://developers.google.com/youtube
// Classes:
//   GTLQueryYouTube (21 custom class methods, 28 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLYouTubeActivity;
@class GTLYouTubePlaylist;
@class GTLYouTubePlaylistItem;
@class GTLYouTubeSubscription;
@class GTLYouTubeVideo;

@interface GTLQueryYouTube : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (copy) NSString *categoryId;
@property (copy) NSString *channelId;
@property (copy) NSString *forChannelId;
@property (copy) NSString *hl;
@property (copy) NSString *home;
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;
@property (assign) NSUInteger maxResults;
@property (copy) NSString *mine;
@property (copy) NSString *mySubscribers;
@property (copy) NSString *onBehalfOfContentOwner;
@property (copy) NSString *order;
@property (copy) NSString *pageToken;
@property (copy) NSString *part;
@property (copy) NSString *playlistId;
@property (copy) NSString *published;
@property (retain) GTLDateTime *publishedAfter;
@property (retain) GTLDateTime *publishedBefore;
@property (copy) NSString *q;
@property (copy) NSString *regionCode;
@property (copy) NSString *relatedToVideo;
@property (copy) NSString *topicId;
@property (copy) NSString *type;
@property (copy) NSString *videoCaption;
@property (copy) NSString *videoDefinition;
@property (copy) NSString *videoDimension;
@property (copy) NSString *videoDuration;
@property (copy) NSString *videoLicense;

#pragma mark -
#pragma mark "activities" methods
// These create a GTLQueryYouTube object.

// Method: youtube.activities.insert
// Post a channel bulletin.
//  Required:
//   part: One or more parts to return on the current request.
//  Optional:
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
// Fetches a GTLYouTubeActivity.
+ (id)queryForActivitiesInsertWithObject:(GTLYouTubeActivity *)object
                                    part:(NSString *)part;

// Method: youtube.activities.list
// Browse the YouTube channel activity collection.
//  Required:
//   part: Activity parts to include in the returned response. Valid values are:
//     id, snippet and contentDetails.
//  Optional:
//   channelId: YouTube ID of the channel.
//   home: Flag indicating to return user's homepage feed.
//   maxResults: Maximum number of results to return (0..50, default 5)
//   mine: Flag indicating to return user's activities.
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//   pageToken: Token for the page selection.
//   publishedAfter: Only return activities published after given date
//     (inclusive).
//   publishedBefore: Only return activities published before given date
//     (exclusive).
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeReadonly
// Fetches a GTLYouTubeActivityListResponse.
+ (id)queryForActivitiesListWithPart:(NSString *)part;

#pragma mark -
#pragma mark "channels" methods
// These create a GTLQueryYouTube object.

// Method: youtube.channels.list
// Browse the YouTube channel collection. Either the 'id' or 'mine' parameter
// must be set.
//  Required:
//   part: Channel parts to include in the returned response. Valid values are:
//     id, snippet, contentDetails and topicDetails.
//  Optional:
//   categoryId: Filter to retrieve the channels within the given category ID.
//   identifier: YouTube IDs of the channels to be returned.
//   maxResults: Maximum number of results to return (0..50, default 5)
//   mine: Filter to only channels owned by authenticated user.
//   mySubscribers: Filter to channels that subscribed to the channel of the
//     authenticated user.
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//   pageToken: Token for the page selection.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeReadonly
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubeChannelListResponse.
+ (id)queryForChannelsListWithPart:(NSString *)part;

#pragma mark -
#pragma mark "guideCategories" methods
// These create a GTLQueryYouTube object.

// Method: youtube.guideCategories.list
// Browse the YouTube guide category collection.
//  Required:
//   part: Guide category parts to include in the returned response. Valid
//     values are: id and snippet.
//  Optional:
//   hl: Language for the returned channelCategories. (Default en-US)
//   identifier: Comma-separated YouTube IDs of the channelCategories to be
//     returned.
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//   regionCode: Return the channelCategories in the given region code.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeReadonly
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubeGuideCategoryListResponse.
+ (id)queryForGuideCategoriesListWithPart:(NSString *)part;

#pragma mark -
#pragma mark "playlistItems" methods
// These create a GTLQueryYouTube object.

// Method: youtube.playlistItems.delete
// Deletes playlist items by IDs.
//  Required:
//   identifier: YouTube IDs of the playlist items to be deleted.
//  Optional:
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
+ (id)queryForPlaylistItemsDeleteWithIdentifier:(NSString *)identifier;

// Method: youtube.playlistItems.insert
// Insert a resource into a playlist.
//  Required:
//   part: One or more parts to return on the current request.
//  Optional:
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubePlaylistItem.
+ (id)queryForPlaylistItemsInsertWithObject:(GTLYouTubePlaylistItem *)object
                                       part:(NSString *)part;

// Method: youtube.playlistItems.list
// Browse the YouTube playlist collection.
//  Required:
//   part: Playlist item parts to include in the returned response. Valid values
//     are: id, snippet and contentDetails.
//  Optional:
//   identifier: YouTube IDs of the playlist items to be returned.
//   maxResults: Maximum number of results to return (0..50, default 5)
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//   pageToken: Token for the page selection.
//   playlistId: Retrieves playlist items from the given playlist id.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeReadonly
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubePlaylistItemListResponse.
+ (id)queryForPlaylistItemsListWithPart:(NSString *)part;

// Method: youtube.playlistItems.update
// Update a playlist item.
//  Required:
//   part: One or more parts to return on the current request.
//  Optional:
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubePlaylistItem.
+ (id)queryForPlaylistItemsUpdateWithObject:(GTLYouTubePlaylistItem *)object
                                       part:(NSString *)part;

#pragma mark -
#pragma mark "playlists" methods
// These create a GTLQueryYouTube object.

// Method: youtube.playlists.delete
// Deletes playlists by IDs.
//  Required:
//   identifier: YouTube IDs of the playlists to be deleted.
//  Optional:
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
+ (id)queryForPlaylistsDeleteWithIdentifier:(NSString *)identifier;

// Method: youtube.playlists.insert
// Create a playlist.
//  Required:
//   part: One or more parts to return on the current request.
//  Optional:
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubePlaylist.
+ (id)queryForPlaylistsInsertWithObject:(GTLYouTubePlaylist *)object
                                   part:(NSString *)part;

// Method: youtube.playlists.list
// Browse the YouTube playlist collection.
//  Required:
//   part: Playlist parts to include in the returned response. Valid values are:
//     id, snippet and status.
//  Optional:
//   identifier: Comma-separated YouTube IDs of the playlists to be returned.
//   maxResults: Maximum number of results to return (0..50, default 5)
//   mine: Flag indicating only return the playlists of the authenticated user.
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//   pageToken: Token for the page selection.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeReadonly
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubePlaylistListResponse.
+ (id)queryForPlaylistsListWithPart:(NSString *)part;

// Method: youtube.playlists.update
// Update a playlist.
//  Required:
//   part: One or more parts to return on the current request.
//  Optional:
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubePlaylist.
+ (id)queryForPlaylistsUpdateWithObject:(GTLYouTubePlaylist *)object
                                   part:(NSString *)part;

#pragma mark -
#pragma mark "search" methods
// These create a GTLQueryYouTube object.

// Method: youtube.search.list
// Universal search for youtube.
//  Required:
//   part: Search result parts to include in the returned response. Valid values
//     are: id and snippet.
//  Optional:
//   maxResults: Maximum number of search results to return per page. (0..50,
//     default 5)
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//   order: Sort order. (Default "SEARCH_SORT_RELEVANCE")
//      kGTLYouTubeOrderDate: Sort according to the date.
//      kGTLYouTubeOrderRating: Sort according to the rating.
//      kGTLYouTubeOrderRelevance: Sort according to the relevance.
//      kGTLYouTubeOrderViewCount: Sort according to the view count.
//   pageToken: Token for the page selection.
//   published: Only search for resources uploaded at a specific pediod
//      kGTLYouTubePublishedAny: No filter on the release date
//      kGTLYouTubePublishedThisWeek: Videos uploaded this month
//      kGTLYouTubePublishedToday: Videos uploaded today
//   q: Query to search in Youtube.
//   relatedToVideo: Search for resources related to this video. Need to be used
//     with type set to 'video'
//   topicId: Only search for resources with the specified topic
//   type: Type of resource to search. (Default video,channel,playlist)
//   videoCaption: Add a filter on the the presence of captions on the videos.
//      kGTLYouTubeVideoCaptionAny: No filter on the captions.
//      kGTLYouTubeVideoCaptionClosedCaption: Videos with closed captions.
//      kGTLYouTubeVideoCaptionNone: Videos without captions.
//   videoDefinition: Add a filter for the definition of the videos.
//      kGTLYouTubeVideoDefinitionAny: No filter on the definition.
//      kGTLYouTubeVideoDefinitionHigh: Videos in high definition.
//      kGTLYouTubeVideoDefinitionStandard: Videos in standard definition.
//   videoDimension: Add a filter for the number of dimensions in the videos.
//      kGTLYouTubeVideoDimensionX2d: Videos in two dimensions.
//      kGTLYouTubeVideoDimensionX3d: Videos in three dimensions.
//      kGTLYouTubeVideoDimensionAny: No filter on the dimension.
//   videoDuration: Add a filter on the duration of the videos.
//      kGTLYouTubeVideoDurationAny: No filter on the duration.
//      kGTLYouTubeVideoDurationLong: Videos with a duration longer than 20
//        minutes.
//      kGTLYouTubeVideoDurationMedium: Videos with a duration between 4 and 20
//        minutes.
//      kGTLYouTubeVideoDurationShort: Videos with a duration under 4 minutes.
//   videoLicense: Add a filter on the licensing of the videos.
//      kGTLYouTubeVideoLicenseAny: No filter on the license.
//      kGTLYouTubeVideoLicenseCreativeCommon: Videos under the Creative Common
//        license.
//      kGTLYouTubeVideoLicenseYoutube: Videos under the YouTube license.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeReadonly
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubeSearchListResponse.
+ (id)queryForSearchListWithPart:(NSString *)part;

#pragma mark -
#pragma mark "subscriptions" methods
// These create a GTLQueryYouTube object.

// Method: youtube.subscriptions.delete
// Deletes subscriptions by IDs.
//  Required:
//   identifier: YouTube IDs of the subscription to be deleted.
//  Optional:
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
+ (id)queryForSubscriptionsDeleteWithIdentifier:(NSString *)identifier;

// Method: youtube.subscriptions.insert
// Insert a subscription.
//  Required:
//   part: One or more parts to return on the current request.
//  Optional:
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubeSubscription.
+ (id)queryForSubscriptionsInsertWithObject:(GTLYouTubeSubscription *)object
                                       part:(NSString *)part;

// Method: youtube.subscriptions.list
// Browses the subscriptions collection.
//  Required:
//   part: Subscription parts to include in the returned response. Valid values
//     are: id, snippet and contentDetails.
//  Optional:
//   channelId: Only return subscriptions to given channelId.
//   forChannelId: Comma separated list of channel IDs to return subscriptions
//     for.
//   identifier: YouTube IDs of the subscriptions to be returned.
//   maxResults: Maximum number of search results to return per page. (0..50,
//     default 5)
//   mine: Flag indicating only return the subscriptions of the authenticated
//     user.
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//   order: Sort order. (Default "SUBSCRIPTION_ORDER_RELEVANCE")
//      kGTLYouTubeOrderAlphabetical: Sort alphabetically
//      kGTLYouTubeOrderRelevance: Sort by relevance.
//      kGTLYouTubeOrderUnread: Sort by order of activity.
//   pageToken: Token for the page selection.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubeSubscriptionListResponse.
+ (id)queryForSubscriptionsListWithPart:(NSString *)part;

#pragma mark -
#pragma mark "videoCategories" methods
// These create a GTLQueryYouTube object.

// Method: youtube.videoCategories.list
// Browse list of video categories.
//  Required:
//   part: Video category parts to include in the returned response. Valid
//     values are: id and snippet.
//  Optional:
//   hl: Language used for the title of the categories. (Default en_US)
//   identifier: IDs of the categories to be returned.
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//   regionCode: Return all the categories in this region.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeReadonly
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubeVideoCategoryListResponse.
+ (id)queryForVideoCategoriesListWithPart:(NSString *)part;

#pragma mark -
#pragma mark "videos" methods
// These create a GTLQueryYouTube object.

// Method: youtube.videos.delete
// Delete a YouTube video.
//  Required:
//   identifier: YouTube ID of the video to be deleted.
//  Optional:
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
+ (id)queryForVideosDeleteWithIdentifier:(NSString *)identifier;

// Method: youtube.videos.insert
// Upload a video to YouTube.
//  Required:
//   part: One or more parts to return on the current request.
//  Optional:
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//  Upload Parameters:
//   Maximum size: 64GB
//   Accepted MIME type(s): application/octet-stream, video/*
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeUpload
// Fetches a GTLYouTubeVideo.
+ (id)queryForVideosInsertWithObject:(GTLYouTubeVideo *)object
                                part:(NSString *)part
                    uploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

// Method: youtube.videos.list
// Browse the YouTube video collection.
//  Required:
//   identifier: YouTube IDs of the videos to be returned.
//   part: Video parts to include in the returned response. Valid values are:
//     id, snippet, contentDetails, player, statistics, status and topicDetails.
//  Optional:
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeReadonly
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubeVideoListResponse.
+ (id)queryForVideosListWithIdentifier:(NSString *)identifier
                                  part:(NSString *)part;

// Method: youtube.videos.update
// Update a video.
//  Required:
//   part: One or more parts to return on the current request.
//  Optional:
//   onBehalfOfContentOwner: The authenticated user acts on behalf of this
//     content owner.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubeVideo.
+ (id)queryForVideosUpdateWithObject:(GTLYouTubeVideo *)object
                                part:(NSString *)part;

@end
