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
//  GTLYouTubeConstants.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   YouTube Data API (youtube/v3)
// Description:
//   Programmatic access to YouTube features.
// Documentation:
//   https://developers.google.com/youtube/v3

#import "GTLYouTubeConstants.h"

// Authorization scope
NSString * const kGTLAuthScopeYouTube                          = @"https://www.googleapis.com/auth/youtube";
NSString * const kGTLAuthScopeYouTubeReadonly                  = @"https://www.googleapis.com/auth/youtube.readonly";
NSString * const kGTLAuthScopeYouTubeUpload                    = @"https://www.googleapis.com/auth/youtube.upload";
NSString * const kGTLAuthScopeYouTubeYoutubepartner            = @"https://www.googleapis.com/auth/youtubepartner";
NSString * const kGTLAuthScopeYouTubeYoutubepartnerChannelAudit = @"https://www.googleapis.com/auth/youtubepartner-channel-audit";

// BroadcastStatus
NSString * const kGTLYouTubeBroadcastStatusActive    = @"active";
NSString * const kGTLYouTubeBroadcastStatusAll       = @"all";
NSString * const kGTLYouTubeBroadcastStatusComplete  = @"complete";
NSString * const kGTLYouTubeBroadcastStatusCompleted = @"completed";
NSString * const kGTLYouTubeBroadcastStatusLive      = @"live";
NSString * const kGTLYouTubeBroadcastStatusTesting   = @"testing";
NSString * const kGTLYouTubeBroadcastStatusUpcoming  = @"upcoming";

// ChannelType
NSString * const kGTLYouTubeChannelTypeAny  = @"any";
NSString * const kGTLYouTubeChannelTypeShow = @"show";

// Chart
NSString * const kGTLYouTubeChartMostPopular = @"mostPopular";

// EventType
NSString * const kGTLYouTubeEventTypeCompleted = @"completed";
NSString * const kGTLYouTubeEventTypeLive      = @"live";
NSString * const kGTLYouTubeEventTypeUpcoming  = @"upcoming";

// MyRating
NSString * const kGTLYouTubeMyRatingDislike = @"dislike";
NSString * const kGTLYouTubeMyRatingLike    = @"like";

// Order
NSString * const kGTLYouTubeOrderAlphabetical = @"alphabetical";
NSString * const kGTLYouTubeOrderDate         = @"date";
NSString * const kGTLYouTubeOrderRating       = @"rating";
NSString * const kGTLYouTubeOrderRelevance    = @"relevance";
NSString * const kGTLYouTubeOrderTitle        = @"title";
NSString * const kGTLYouTubeOrderUnread       = @"unread";
NSString * const kGTLYouTubeOrderVideoCount   = @"videoCount";
NSString * const kGTLYouTubeOrderViewCount    = @"viewCount";

// Rating
NSString * const kGTLYouTubeRatingDislike = @"dislike";
NSString * const kGTLYouTubeRatingLike    = @"like";
NSString * const kGTLYouTubeRatingNone    = @"none";

// SafeSearch
NSString * const kGTLYouTubeSafeSearchModerate = @"moderate";
NSString * const kGTLYouTubeSafeSearchNone     = @"none";
NSString * const kGTLYouTubeSafeSearchStrict   = @"strict";

// VideoCaption
NSString * const kGTLYouTubeVideoCaptionAny           = @"any";
NSString * const kGTLYouTubeVideoCaptionClosedCaption = @"closedCaption";
NSString * const kGTLYouTubeVideoCaptionNone          = @"none";

// VideoDefinition
NSString * const kGTLYouTubeVideoDefinitionAny      = @"any";
NSString * const kGTLYouTubeVideoDefinitionHigh     = @"high";
NSString * const kGTLYouTubeVideoDefinitionStandard = @"standard";

// VideoDimension
NSString * const kGTLYouTubeVideoDimensionAny = @"any";
NSString * const kGTLYouTubeVideoDimensionX2d = @"2d";
NSString * const kGTLYouTubeVideoDimensionX3d = @"3d";

// VideoDuration
NSString * const kGTLYouTubeVideoDurationAny    = @"any";
NSString * const kGTLYouTubeVideoDurationLong   = @"long";
NSString * const kGTLYouTubeVideoDurationMedium = @"medium";
NSString * const kGTLYouTubeVideoDurationShort  = @"short";

// VideoEmbeddable
NSString * const kGTLYouTubeVideoEmbeddableAny  = @"any";
NSString * const kGTLYouTubeVideoEmbeddableTrue = @"true";

// VideoLicense
NSString * const kGTLYouTubeVideoLicenseAny            = @"any";
NSString * const kGTLYouTubeVideoLicenseCreativeCommon = @"creativeCommon";
NSString * const kGTLYouTubeVideoLicenseYoutube        = @"youtube";

// VideoSyndicated
NSString * const kGTLYouTubeVideoSyndicatedAny  = @"any";
NSString * const kGTLYouTubeVideoSyndicatedTrue = @"true";

// VideoType
NSString * const kGTLYouTubeVideoTypeAny     = @"any";
NSString * const kGTLYouTubeVideoTypeEpisode = @"episode";
NSString * const kGTLYouTubeVideoTypeMovie   = @"movie";
