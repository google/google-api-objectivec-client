/* Copyright (c) 2013 Google Inc.
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
//  GTLYouTube_Sources.m
//
// This file can be compiled into projects to avoid adding the individual
// source files for this service.
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   YouTube Data API (youtube/v3)
// Description:
//   Programmatic access to YouTube features.
// Documentation:
//   https://developers.google.com/youtube/v3

#import "GTLYouTubeConstants.m"

#import "GTLYouTubeAccessPolicy.m"
#import "GTLYouTubeActivity.m"
#import "GTLYouTubeActivityContentDetails.m"
#import "GTLYouTubeActivityListResponse.m"
#import "GTLYouTubeActivitySnippet.m"
#import "GTLYouTubeChannel.m"
#import "GTLYouTubeChannelBrandingSettings.m"
#import "GTLYouTubeChannelContentDetails.m"
#import "GTLYouTubeChannelListResponse.m"
#import "GTLYouTubeChannelSettings.m"
#import "GTLYouTubeChannelSnippet.m"
#import "GTLYouTubeChannelStatistics.m"
#import "GTLYouTubeChannelStatus.m"
#import "GTLYouTubeChannelTopicDetails.m"
#import "GTLYouTubeContentRating.m"
#import "GTLYouTubeFeaturedChannel.m"
#import "GTLYouTubeFeaturedVideo.m"
#import "GTLYouTubeGeoPoint.m"
#import "GTLYouTubeGuideCategory.m"
#import "GTLYouTubeGuideCategoryListResponse.m"
#import "GTLYouTubeGuideCategorySnippet.m"
#import "GTLYouTubeImageSettings.m"
#import "GTLYouTubeInvideoFeature.m"
#import "GTLYouTubeLiveBroadcast.m"
#import "GTLYouTubeLiveBroadcastContentDetails.m"
#import "GTLYouTubeLiveBroadcastList.m"
#import "GTLYouTubeLiveBroadcastSnippet.m"
#import "GTLYouTubeLiveBroadcastStatus.m"
#import "GTLYouTubeLiveStream.m"
#import "GTLYouTubeLiveStreamCdn.m"
#import "GTLYouTubeLiveStreamCdnIngestionInfo.m"
#import "GTLYouTubeLiveStreamList.m"
#import "GTLYouTubeLiveStreamSnippet.m"
#import "GTLYouTubeLiveStreamStatus.m"
#import "GTLYouTubeLocalizedProperty.m"
#import "GTLYouTubeLocalizedString.m"
#import "GTLYouTubePageInfo.m"
#import "GTLYouTubePlayer.m"
#import "GTLYouTubePlayerAdsPlaylist.m"
#import "GTLYouTubePlayerListResponse.m"
#import "GTLYouTubePlayerRestrictionDetails.m"
#import "GTLYouTubePlayerVideoUrl.m"
#import "GTLYouTubePlayerVideoUrls.m"
#import "GTLYouTubePlaylist.m"
#import "GTLYouTubePlaylistContentDetails.m"
#import "GTLYouTubePlaylistItem.m"
#import "GTLYouTubePlaylistItemContentDetails.m"
#import "GTLYouTubePlaylistItemListResponse.m"
#import "GTLYouTubePlaylistItemSnippet.m"
#import "GTLYouTubePlaylistItemStatus.m"
#import "GTLYouTubePlaylistListResponse.m"
#import "GTLYouTubePlaylistPlayer.m"
#import "GTLYouTubePlaylistSnippet.m"
#import "GTLYouTubePlaylistStatus.m"
#import "GTLYouTubePropertyValue.m"
#import "GTLYouTubeResourceId.m"
#import "GTLYouTubeSearchListResponse.m"
#import "GTLYouTubeSearchResult.m"
#import "GTLYouTubeSearchResultSnippet.m"
#import "GTLYouTubeSubscription.m"
#import "GTLYouTubeSubscriptionContentDetails.m"
#import "GTLYouTubeSubscriptionListResponse.m"
#import "GTLYouTubeSubscriptionSnippet.m"
#import "GTLYouTubeThumbnail.m"
#import "GTLYouTubeThumbnailDetails.m"
#import "GTLYouTubeVideo.m"
#import "GTLYouTubeVideoAgeGating.m"
#import "GTLYouTubeVideoCategory.m"
#import "GTLYouTubeVideoCategoryListResponse.m"
#import "GTLYouTubeVideoCategorySnippet.m"
#import "GTLYouTubeVideoContentDetails.m"
#import "GTLYouTubeVideoContentDetailsRegionRestriction.m"
#import "GTLYouTubeVideoFileDetails.m"
#import "GTLYouTubeVideoFileDetailsAudioStream.m"
#import "GTLYouTubeVideoFileDetailsVideoStream.m"
#import "GTLYouTubeVideoListResponse.m"
#import "GTLYouTubeVideoMonetizationDetails.m"
#import "GTLYouTubeVideoPlayer.m"
#import "GTLYouTubeVideoProcessingDetails.m"
#import "GTLYouTubeVideoProcessingDetailsProcessingProgress.m"
#import "GTLYouTubeVideoProjectDetails.m"
#import "GTLYouTubeVideoRecordingDetails.m"
#import "GTLYouTubeVideoSnippet.m"
#import "GTLYouTubeVideoStatistics.m"
#import "GTLYouTubeVideoStatus.m"
#import "GTLYouTubeVideoSuggestions.m"
#import "GTLYouTubeVideoSuggestionsTagSuggestion.m"
#import "GTLYouTubeVideoTopicDetails.m"
#import "GTLYouTubeWatchSettings.m"

#import "GTLQueryYouTube.m"
#import "GTLServiceYouTube.m"
