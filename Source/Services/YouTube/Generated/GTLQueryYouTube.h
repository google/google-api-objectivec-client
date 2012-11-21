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
//   GTLQueryYouTube (21 custom class methods, 27 custom properties)

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
@property (assign) BOOL mine;
@property (copy) NSString *mySubscribers;
@property (copy) NSString *order;
@property (copy) NSString *pageToken;
@property (copy) NSString *part;
@property (copy) NSString *playlistId;
@property (copy) NSString *published;
@property (retain) GTLDateTime *publishedAfter;
@property (retain) GTLDateTime *publishedBefore;
@property (copy) NSString *q;
@property (copy) NSString *regionCode;
@property (copy) NSString *relatedToVideoId;
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
// Posts a bulletin for a specific channel. (The user submitting the request
// must be authorized to act on the channel's behalf.)
//  Required:
//   part: The part parameter serves two purposes in this operation. It
//     identifies the properties that the write operation will set as well as
//     the properties that the API response will include.
//     The part names that you can include in the parameter value are snippet
//     and contentDetails.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
// Fetches a GTLYouTubeActivity.
+ (id)queryForActivitiesInsertWithObject:(GTLYouTubeActivity *)object
                                    part:(NSString *)part;

// Method: youtube.activities.list
// Returns a list of channel activity events that match the request criteria.
// For example, you can retrieve events associated with a particular channel,
// events associated with the user's subscriptions and Google+ friends, or the
// YouTube home page feed, which is customized for each user.
//  Required:
//   part: The part parameter specifies a comma-separated list of one or more
//     activity resource properties that the API response will include. The part
//     names that you can include in the parameter value are id, snippet, and
//     contentDetails.
//     If the parameter identifies a property that contains child properties,
//     the child properties will be included in the response. For example, in a
//     activity resource, the snippet property contains other properties that
//     identify the type of activity, a display title for the activity, and so
//     forth. If you set part=snippet, the API response will also contain all of
//     those nested properties.
//  Optional:
//   channelId: The channelId parameter specifies a unique YouTube channel ID.
//     The API will then return a list of that channel's activities.
//   home: Set this parameter's value to true to retrieve the activity feed that
//     displays on the YouTube home page for the currently authenticated user.
//   maxResults: USE_DESCRIPTION --- channels:list:maxResults (0..50, default 5)
//   mine: Set this parameter's value to true to retrieve a feed of the
//     authenticated user's activities.
//   pageToken: USE_DESCRIPTION --- channels:list:pageToken
//   publishedAfter: The publishedAfter parameter specifies the earliest date
//     and time that an activity could have occurred for that activity to be
//     included in the API response. If the parameter value specifies a day, but
//     not a time, then any activities that occurred that day will be included
//     in the result set. The value is specified in ISO 8601
//     (YYYY-MM-DDThh:mm:ss.sZ) format.
//   publishedBefore: The publishedBefore parameter specifies the date and time
//     before which an activity must have occurred for that activity to be
//     included in the API response. If the parameter value specifies a day, but
//     not a time, then any activities that occurred that day will be excluded
//     from the result set. The value is specified in ISO 8601
//     (YYYY-MM-DDThh:mm:ss.sZ) format.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeReadonly
// Fetches a GTLYouTubeActivityListResponse.
+ (id)queryForActivitiesListWithPart:(NSString *)part;

#pragma mark -
#pragma mark "channels" methods
// These create a GTLQueryYouTube object.

// Method: youtube.channels.list
// Returns a collection of zero or more channel resources that match the request
// criteria.
//  Required:
//   part: The part parameter specifies a comma-separated list of one or more
//     channel resource properties that the API response will include. The part
//     names that you can include in the parameter value are id, snippet,
//     contentDetails, statistics, and topicDetails.
//     If the parameter identifies a property that contains child properties,
//     the child properties will be included in the response. For example, in a
//     channel resource, the contentDetails property contains other properties,
//     such as the uploads properties. As such, if you set part=contentDetails,
//     the API response will also contain all of those nested properties.
//  Optional:
//   categoryId: The categoryId parameter specifies a YouTube guide category,
//     thereby requesting YouTube channels associated with that category.
//   identifier: The id parameter specifies a comma-separated list of the
//     YouTube channel ID(s) for the resource(s) that are being retrieved. In a
//     channel resource, the id property specifies the channel's YouTube channel
//     ID.
//   maxResults: The maxResults parameter specifies the maximum number of items
//     that should be returned in the result set. (0..50, default 5)
//   mine: Set this parameter's value to true to instruct the API to only return
//     channels owned by the authenticated user.
//   mySubscribers: Set this parameter's value to true to retrieve a list of
//     channels that subscribed to the authenticated user's channel.
//   pageToken: The pageToken parameter identifies a specific page in the result
//     set that should be returned. In an API response, the nextPageToken and
//     prevPageToken properties identify other pages that could be retrieved.
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
// Returns a list of categories that can be associated with YouTube channels.
//  Required:
//   part: The part parameter specifies a comma-separated list of one or more
//     guideCategory resource properties that the API response will include. The
//     part names that you can include in the parameter value are id and
//     snippet.
//     If the parameter identifies a property that contains child properties,
//     the child properties will be included in the response. For example, in a
//     guideCategory resource, the snippet property contains other properties,
//     such as the category's title. If you set part=snippet, the API response
//     will also contain all of those nested properties.
//  Optional:
//   hl: The hl parameter specifies the language that will be used for text
//     values in the API response. (Default en-US)
//   identifier: The id parameter specifies a comma-separated list of the
//     YouTube channel category ID(s) for the resource(s) that are being
//     retrieved. In a guideCategory resource, the id property specifies the
//     YouTube channel category ID.
//   regionCode: The regionCode parameter instructs the API to return the list
//     of guide categories available in the specified country. The parameter
//     value is an ISO 3166-1 alpha-2 country code.
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
// Deletes a playlist item.
//  Required:
//   identifier: The id parameter specifies the YouTube playlist item ID for the
//     playlist item that is being deleted. In a playlistItem resource, the id
//     property specifies the playlist item's ID.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
+ (id)queryForPlaylistItemsDeleteWithIdentifier:(NSString *)identifier;

// Method: youtube.playlistItems.insert
// Adds a resource to a playlist.
//  Required:
//   part: The part parameter serves two purposes in this operation. It
//     identifies the properties that the write operation will set as well as
//     the properties that the API response will include.
//     The part names that you can include in the parameter value are snippet
//     and contentDetails.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubePlaylistItem.
+ (id)queryForPlaylistItemsInsertWithObject:(GTLYouTubePlaylistItem *)object
                                       part:(NSString *)part;

// Method: youtube.playlistItems.list
// Returns a collection of playlist items that match the API request parameters.
// You can retrieve all of the playlist items in a specified playlist or
// retrieve one or more playlist items by their unique IDs.
//  Required:
//   part: The part parameter specifies a comma-separated list of one or more
//     playlistItem resource properties that the API response will include. The
//     part names that you can include in the parameter value are id, snippet,
//     and contentDetails.
//     If the parameter identifies a property that contains child properties,
//     the child properties will be included in the response. For example, in a
//     playlistItem resource, the snippet property contains numerous fields,
//     including the title, description, position, and resourceId properties. As
//     such, if you set part=snippet, the API response will contain all of those
//     properties.
//  Optional:
//   identifier: The id parameter specifies a comma-separated list of one or
//     more unique playlist item IDs.
//   maxResults: USE_DESCRIPTION --- channels:list:maxResults (0..50, default 5)
//   pageToken: USE_DESCRIPTION --- channels:list:pageToken
//   playlistId: The playlistId parameter specifies the unique ID of the
//     playlist for which you want to retrieve playlist items. Note that even
//     though this is an optional parameter, every request to retrieve playlist
//     items must specify a value for either the id parameter or the playlistId
//     parameter.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeReadonly
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubePlaylistItemListResponse.
+ (id)queryForPlaylistItemsListWithPart:(NSString *)part;

// Method: youtube.playlistItems.update
// Modifies a playlist item. For example, you could update the item's position
// in the playlist.
//  Required:
//   part: The part parameter serves two purposes in this operation. It
//     identifies the properties that the write operation will set as well as
//     the properties that the API response will include.
//     The part names that you can include in the parameter value are snippet
//     and contentDetails.
//     Note that this method will override the existing values for all of the
//     mutable properties that are contained in any parts that the parameter
//     value specifies. For example, a playlist item can specify a start time
//     and end time, which identify the times portion of the video that should
//     play when users watch the video in the playlist. If your request is
//     updating a playlist item that sets these values, and the request's part
//     parameter value includes the contentDetails part, the playlist item's
//     start and end times will be updated to whatever value the request body
//     specifies. If the request body does not specify values, the existing
//     start and end times will be removed and replaced with the default
//     settings.
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
// Deletes a playlist.
//  Required:
//   identifier: The id parameter specifies the YouTube playlist ID for the
//     playlist that is being deleted. In a playlist resource, the id property
//     specifies the playlist's ID.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
+ (id)queryForPlaylistsDeleteWithIdentifier:(NSString *)identifier;

// Method: youtube.playlists.insert
// Creates a playlist.
//  Required:
//   part: The part parameter serves two purposes in this operation. It
//     identifies the properties that the write operation will set as well as
//     the properties that the API response will include.
//     The part names that you can include in the parameter value are snippet
//     and status.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubePlaylist.
+ (id)queryForPlaylistsInsertWithObject:(GTLYouTubePlaylist *)object
                                   part:(NSString *)part;

// Method: youtube.playlists.list
// Returns a collection of playlists that match the API request parameters. For
// example, you can retrieve all playlists that the authenticated user owns, or
// you can retrieve one or more playlists by their unique IDs.
//  Required:
//   part: The part parameter specifies a comma-separated list of one or more
//     playlist resource properties that the API response will include. The part
//     names that you can include in the parameter value are id, snippet, and
//     status.
//     If the parameter identifies a property that contains child properties,
//     the child properties will be included in the response. For example, in a
//     playlist resource, the snippet property contains properties like author,
//     title, description, tags, and timeCreated. As such, if you set
//     part=snippet, the API response will contain all of those properties.
//  Optional:
//   channelId: This value indicates that the API should only return the
//     specified channel's playlists.
//   identifier: The id parameter specifies a comma-separated list of the
//     YouTube playlist ID(s) for the resource(s) that are being retrieved. In a
//     playlist resource, the id property specifies the playlist's YouTube
//     playlist ID.
//   maxResults: USE_DESCRIPTION --- channels:list:maxResults (0..50, default 5)
//   mine: Set this parameter's value to true to instruct the API to only return
//     playlists owned by the authenticated user.
//   pageToken: USE_DESCRIPTION --- channels:list:pageToken
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeReadonly
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubePlaylistListResponse.
+ (id)queryForPlaylistsListWithPart:(NSString *)part;

// Method: youtube.playlists.update
// Modifies a playlist. For example, you could change a playlist's title,
// description, or privacy status.
//  Required:
//   part: The part parameter serves two purposes in this operation. It
//     identifies the properties that the write operation will set as well as
//     the properties that the API response will include.
//     The part names that you can include in the parameter value are snippet
//     and status.
//     Note that this method will override the existing values for all of the
//     mutable properties that are contained in any parts that the parameter
//     value specifies. For example, a playlist's privacy setting is contained
//     in the status part. As such, if your request is updating a private
//     playlist, and the request's part parameter value includes the status
//     part, the playlist's privacy setting will be updated to whatever value
//     the request body specifies. If the request body does not specify a value,
//     the existing privacy setting will be removed and the playlist will revert
//     to the default privacy setting.
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
// Returns a collection of search results that match the query parameters
// specified in the API request. By default, a search result set identifies
// matching video, channel, and playlist resources, but you can also configure
// queries to only retrieve a specific type of resource.
//  Required:
//   part: The part parameter specifies a comma-separated list of one or more
//     search resource properties that the API response will include. The part
//     names that you can include in the parameter value are id and snippet.
//     If the parameter identifies a property that contains child properties,
//     the child properties will be included in the response. For example, in a
//     search result, the snippet property contains other properties that
//     identify the result's title, description, and so forth. If you set
//     part=snippet, the API response will also contain all of those nested
//     properties.
//  Optional:
//   maxResults: USE_DESCRIPTION --- channels:list:maxResults (0..50, default 5)
//   order: The order parameter specifies the method that will be used to order
//     resources in the API response. (Default "SEARCH_SORT_RELEVANCE")
//      kGTLYouTubeOrderDate: Resources are sorted in reverse chronological
//        order based on the date they were created.
//      kGTLYouTubeOrderRating: Resources are sorted from highest to lowest
//        rating.
//      kGTLYouTubeOrderRelevance: Resources are sorted based on their relevance
//        to the search query. This is the default value for this parameter.
//      kGTLYouTubeOrderViewCount: Resources are sorted from highest to lowest
//        number of views.
//   pageToken: USE_DESCRIPTION --- channels:list:pageToken
//   published: The published parameter indicates that the API response should
//     only contain resources created within the specified time period.
//      kGTLYouTubePublishedAny: Do not filter results based on their creation
//        date. This is the default value.
//      kGTLYouTubePublishedThisMonth: Return videos that were uploaded within
//        the past month.
//      kGTLYouTubePublishedThisWeek: Return videos that were uploaded within
//        the past week.
//      kGTLYouTubePublishedToday: Return videos that were uploaded today.
//   q: The q parameter specifies the query term to search for.
//   relatedToVideoId: The relatedToVideoId parameter retrieves a list of videos
//     that are related to the video that the parameter value identifies. The
//     parameter value must be set to a YouTube video ID and, if you are using
//     this parameter, the type parameter must be set to video.
//   topicId: The topicId parameter indicates that the API response should only
//     contain resources associated with the specified topic. The value
//     identifies a Freebase topic ID.
//   type: The type parameter restricts a search query to only retrieve a
//     particular type of resource. (Default video,channel,playlist)
//   videoCaption: The videoCaption parameter indicates whether the API should
//     filter video search results based on whether they have captions.
//      kGTLYouTubeVideoCaptionAny: Do not filter results based on caption
//        availability.
//      kGTLYouTubeVideoCaptionClosedCaption: Only include videos that have
//        captions.
//      kGTLYouTubeVideoCaptionNone: Only include videos that do not have
//        captions.
//   videoDefinition: The videoDefinition parameter lets you restrict a search
//     to only include either high definition (HD) or standard definition (SD)
//     videos. HD videos are available for playback in at least 720p, though
//     higher resolutions, like 1080p, might also be available.
//      kGTLYouTubeVideoDefinitionAny: Return all videos, regardless of their
//        resolution.
//      kGTLYouTubeVideoDefinitionHigh: Only retrieve HD videos.
//      kGTLYouTubeVideoDefinitionStandard: Only retrieve videos in standard
//        definition.
//   videoDimension: The videoDimension parameter lets you restrict a search to
//     only retrieve 2D or 3D videos.
//      kGTLYouTubeVideoDimensionX2d: Restrict search results to exclude 3D
//        videos.
//      kGTLYouTubeVideoDimensionX3d: Restrict search results to only include 3D
//        videos.
//      kGTLYouTubeVideoDimensionAny: Include both 3D and non-3D videos in
//        returned results. This is the default value.
//   videoDuration: The videoDuration parameter filters video search results
//     based on their duration.
//      kGTLYouTubeVideoDurationAny: Do not filter video search results based on
//        their duration. This is the default value.
//      kGTLYouTubeVideoDurationLong: Only include videos longer than 20
//        minutes.
//      kGTLYouTubeVideoDurationMedium: Only include videos that are between
//        four and 20 minutes long (inclusive).
//      kGTLYouTubeVideoDurationShort: Only include videos that are less than
//        four minutes long.
//   videoLicense: The videoLicense parameter filters search results to only
//     include videos with a particular license. YouTube lets video uploaders
//     choose to attach either the Creative Commons license or the standard
//     YouTube license to each of their videos.
//      kGTLYouTubeVideoLicenseAny: Return all videos, regardless of which
//        license they have, that match the query parameters.
//      kGTLYouTubeVideoLicenseCreativeCommon: Only return videos that have a
//        Creative Commons license. Users can reuse videos with this license in
//        other videos that they create. Learn more.
//      kGTLYouTubeVideoLicenseYoutube: Only return videos that have the
//        standard YouTube license.
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
// Deletes a subscription.
//  Required:
//   identifier: The id parameter specifies the YouTube subscription ID for the
//     resource that is being deleted. In a subscription resource, the id
//     property specifies the YouTube subscription ID.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
+ (id)queryForSubscriptionsDeleteWithIdentifier:(NSString *)identifier;

// Method: youtube.subscriptions.insert
// Adds a subscription for the authenticated user's channel.
//  Required:
//   part: The part parameter serves two purposes in this operation. It
//     identifies the properties that the write operation will set as well as
//     the properties that the API response will include.
//     The part names that you can include in the parameter value are snippet
//     and contentDetails.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubeSubscription.
+ (id)queryForSubscriptionsInsertWithObject:(GTLYouTubeSubscription *)object
                                       part:(NSString *)part;

// Method: youtube.subscriptions.list
// Returns subscription resources that match the API request criteria.
//  Required:
//   part: The part parameter specifies a comma-separated list of one or more
//     subscription resource properties that the API response will include. The
//     part names that you can include in the parameter value are id, snippet,
//     and contentDetails.
//     If the parameter identifies a property that contains child properties,
//     the child properties will be included in the response. For example, in a
//     subscription resource, the snippet property contains other properties,
//     such as a display title for the subscription. If you set part=snippet,
//     the API response will also contain all of those nested properties.
//  Optional:
//   channelId: The channelId parameter specifies a YouTube channel ID. The API
//     will only return that channel's subscriptions.
//   forChannelId: The forChannelId parameter specifies a comma-separated list
//     of channel IDs. The API response will then only contain subscriptions
//     matching those channels.
//   identifier: The id parameter specifies a comma-separated list of the
//     YouTube subscription ID(s) for the resource(s) that are being retrieved.
//     In a subscription resource, the id property specifies the YouTube
//     subscription ID.
//   maxResults: USE_DESCRIPTION --- channels:list:maxResults (0..50, default 5)
//   mine: Set this parameter's value to true to retrieve a feed of the
//     authenticated user's subscriptions.
//   order: The order parameter specifies the method that will be used to sort
//     resources in the API response. (Default "SUBSCRIPTION_ORDER_RELEVANCE")
//      kGTLYouTubeOrderAlphabetical: Sort alphabetically.
//      kGTLYouTubeOrderRelevance: Sort by relevance.
//      kGTLYouTubeOrderUnread: Sort by order of activity.
//   pageToken: USE_DESCRIPTION --- channels:list:pageToken
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubeSubscriptionListResponse.
+ (id)queryForSubscriptionsListWithPart:(NSString *)part;

#pragma mark -
#pragma mark "videoCategories" methods
// These create a GTLQueryYouTube object.

// Method: youtube.videoCategories.list
// Returns a list of categories that can be associated with YouTube videos.
//  Required:
//   part: The part parameter specifies the videoCategory resource parts that
//     the API response will include. Supported values are id and snippet.
//  Optional:
//   hl: The hl parameter specifies the language that should be used for text
//     values in the API response. (Default en_US)
//   identifier: The id parameter specifies a comma-separated list of video
//     category IDs for the resources that you are retrieving.
//   regionCode: The regionCode parameter instructs the API to return the list
//     of video categories available in the specified country. The parameter
//     value is an ISO 3166-1 alpha-2 country code.
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
// Deletes a YouTube video.
//  Required:
//   identifier: The id parameter specifies the YouTube video ID for the
//     resource that is being deleted. In a video resource, the id property
//     specifies the video's ID.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
+ (id)queryForVideosDeleteWithIdentifier:(NSString *)identifier;

// Method: youtube.videos.insert
// Uploads a video to YouTube and optionally sets the video's metadata.
//  Required:
//   part: The part parameter serves two purposes in this operation. It
//     identifies the properties that the write operation will set as well as
//     the properties that the API response will include.
//     The part names that you can include in the parameter value are snippet,
//     contentDetails, player, statistics, status, and topicDetails. However,
//     not all of those parts contain properties that can be set when setting or
//     updating a video's metadata. For example, the statistics object
//     encapsulates statistics that YouTube calculates for a video and does not
//     contain values that you can set or modify. If the parameter value
//     specifies a part that does not contain mutable values, that part will
//     still be included in the API response.
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
// Returns a list of videos that match the API request parameters.
//  Required:
//   identifier: The id parameter specifies a comma-separated list of the
//     YouTube video ID(s) for the resource(s) that are being retrieved. In a
//     video resource, the id property specifies the video's ID.
//   part: The part parameter specifies a comma-separated list of one or more
//     video resource properties that the API response will include. The part
//     names that you can include in the parameter value are id, snippet,
//     contentDetails, player, statistics, status, and topicDetails.
//     If the parameter identifies a property that contains child properties,
//     the child properties will be included in the response. For example, in a
//     video resource, the snippet property contains the channelId, title,
//     description, tags, and categoryId properties. As such, if you set
//     part=snippet, the API response will contain all of those properties.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeReadonly
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubeVideoListResponse.
+ (id)queryForVideosListWithIdentifier:(NSString *)identifier
                                  part:(NSString *)part;

// Method: youtube.videos.update
// Updates a video's metadata.
//  Required:
//   part: The part parameter serves two purposes in this operation. It
//     identifies the properties that the write operation will set as well as
//     the properties that the API response will include.
//     The part names that you can include in the parameter value are snippet,
//     contentDetails, player, statistics, status, and topicDetails.
//     Note that this method will override the existing values for all of the
//     mutable properties that are contained in any parts that the parameter
//     value specifies. For example, a video's privacy setting is contained in
//     the status part. As such, if your request is updating a private video,
//     and the request's part parameter value includes the status part, the
//     video's privacy setting will be updated to whatever value the request
//     body specifies. If the request body does not specify a value, the
//     existing privacy setting will be removed and the video will revert to the
//     default privacy setting.
//     In addition, not all of those parts contain properties that can be set
//     when setting or updating a video's metadata. For example, the statistics
//     object encapsulates statistics that YouTube calculates for a video and
//     does not contain values that you can set or modify. If the parameter
//     value specifies a part that does not contain mutable values, that part
//     will still be included in the API response.
//  Authorization scope(s):
//   kGTLAuthScopeYouTube
//   kGTLAuthScopeYouTubeYoutubepartner
// Fetches a GTLYouTubeVideo.
+ (id)queryForVideosUpdateWithObject:(GTLYouTubeVideo *)object
                                part:(NSString *)part;

@end
