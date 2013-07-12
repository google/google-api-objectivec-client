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
//  GTLYouTubeConstants.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   YouTube Data API (youtube/v3)
// Description:
//   Programmatic access to YouTube features.
// Documentation:
//   https://developers.google.com/youtube/v3

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// Manage your YouTube account
GTL_EXTERN NSString * const kGTLAuthScopeYouTube;               // "https://www.googleapis.com/auth/youtube"
// View your YouTube account
GTL_EXTERN NSString * const kGTLAuthScopeYouTubeReadonly;       // "https://www.googleapis.com/auth/youtube.readonly"
// Manage your YouTube videos
GTL_EXTERN NSString * const kGTLAuthScopeYouTubeUpload;         // "https://www.googleapis.com/auth/youtube.upload"
// View and manage your assets and associated content on YouTube
GTL_EXTERN NSString * const kGTLAuthScopeYouTubeYoutubepartner;  // "https://www.googleapis.com/auth/youtubepartner"

// BroadcastStatus
GTL_EXTERN NSString * const kGTLYouTubeBroadcastStatusActive;   // "active"
GTL_EXTERN NSString * const kGTLYouTubeBroadcastStatusAll;      // "all"
GTL_EXTERN NSString * const kGTLYouTubeBroadcastStatusComplete;  // "complete"
GTL_EXTERN NSString * const kGTLYouTubeBroadcastStatusCompleted;  // "completed"
GTL_EXTERN NSString * const kGTLYouTubeBroadcastStatusLive;     // "live"
GTL_EXTERN NSString * const kGTLYouTubeBroadcastStatusTesting;  // "testing"
GTL_EXTERN NSString * const kGTLYouTubeBroadcastStatusUpcoming;  // "upcoming"

// ChannelType
GTL_EXTERN NSString * const kGTLYouTubeChannelTypeAny;   // "any"
GTL_EXTERN NSString * const kGTLYouTubeChannelTypeShow;  // "show"

// Chart
GTL_EXTERN NSString * const kGTLYouTubeChartMostPopular;  // "mostPopular"

// MyRating
GTL_EXTERN NSString * const kGTLYouTubeMyRatingDislike;  // "dislike"
GTL_EXTERN NSString * const kGTLYouTubeMyRatingLike;     // "like"

// Order
GTL_EXTERN NSString * const kGTLYouTubeOrderAlphabetical;  // "alphabetical"
GTL_EXTERN NSString * const kGTLYouTubeOrderDate;          // "date"
GTL_EXTERN NSString * const kGTLYouTubeOrderRating;        // "rating"
GTL_EXTERN NSString * const kGTLYouTubeOrderRelevance;     // "relevance"
GTL_EXTERN NSString * const kGTLYouTubeOrderTitle;         // "title"
GTL_EXTERN NSString * const kGTLYouTubeOrderUnread;        // "unread"
GTL_EXTERN NSString * const kGTLYouTubeOrderVideoCount;    // "videoCount"
GTL_EXTERN NSString * const kGTLYouTubeOrderViewCount;     // "viewCount"

// Rating
GTL_EXTERN NSString * const kGTLYouTubeRatingDislike;  // "dislike"
GTL_EXTERN NSString * const kGTLYouTubeRatingLike;     // "like"
GTL_EXTERN NSString * const kGTLYouTubeRatingNone;     // "none"

// SafeSearch
GTL_EXTERN NSString * const kGTLYouTubeSafeSearchModerate;  // "moderate"
GTL_EXTERN NSString * const kGTLYouTubeSafeSearchNone;      // "none"
GTL_EXTERN NSString * const kGTLYouTubeSafeSearchStrict;    // "strict"

// VideoCaption
GTL_EXTERN NSString * const kGTLYouTubeVideoCaptionAny;         // "any"
GTL_EXTERN NSString * const kGTLYouTubeVideoCaptionClosedCaption;  // "closedCaption"
GTL_EXTERN NSString * const kGTLYouTubeVideoCaptionNone;        // "none"

// VideoDefinition
GTL_EXTERN NSString * const kGTLYouTubeVideoDefinitionAny;      // "any"
GTL_EXTERN NSString * const kGTLYouTubeVideoDefinitionHigh;     // "high"
GTL_EXTERN NSString * const kGTLYouTubeVideoDefinitionStandard;  // "standard"

// VideoDimension
GTL_EXTERN NSString * const kGTLYouTubeVideoDimensionAny;  // "any"
GTL_EXTERN NSString * const kGTLYouTubeVideoDimensionX2d;  // "2d"
GTL_EXTERN NSString * const kGTLYouTubeVideoDimensionX3d;  // "3d"

// VideoDuration
GTL_EXTERN NSString * const kGTLYouTubeVideoDurationAny;     // "any"
GTL_EXTERN NSString * const kGTLYouTubeVideoDurationLong;    // "long"
GTL_EXTERN NSString * const kGTLYouTubeVideoDurationMedium;  // "medium"
GTL_EXTERN NSString * const kGTLYouTubeVideoDurationShort;   // "short"

// VideoEmbeddable
GTL_EXTERN NSString * const kGTLYouTubeVideoEmbeddableAny;   // "any"
GTL_EXTERN NSString * const kGTLYouTubeVideoEmbeddableTrue;  // "true"

// VideoLicense
GTL_EXTERN NSString * const kGTLYouTubeVideoLicenseAny;         // "any"
GTL_EXTERN NSString * const kGTLYouTubeVideoLicenseCreativeCommon;  // "creativeCommon"
GTL_EXTERN NSString * const kGTLYouTubeVideoLicenseYoutube;     // "youtube"

// VideoSyndicated
GTL_EXTERN NSString * const kGTLYouTubeVideoSyndicatedAny;   // "any"
GTL_EXTERN NSString * const kGTLYouTubeVideoSyndicatedTrue;  // "true"

// VideoType
GTL_EXTERN NSString * const kGTLYouTubeVideoTypeAny;      // "any"
GTL_EXTERN NSString * const kGTLYouTubeVideoTypeEpisode;  // "episode"
GTL_EXTERN NSString * const kGTLYouTubeVideoTypeMovie;    // "movie"
