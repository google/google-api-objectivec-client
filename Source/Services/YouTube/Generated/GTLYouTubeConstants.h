/* Copyright (c) 2014 Google Inc.
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
// View private information of your YouTube channel relevant during the audit
// process with a YouTube partner
GTL_EXTERN NSString * const kGTLAuthScopeYouTubeYoutubepartnerChannelAudit;  // "https://www.googleapis.com/auth/youtubepartner-channel-audit"

// GTLQueryYouTube - BroadcastStatus
GTL_EXTERN NSString * const kGTLYouTubeBroadcastStatusActive;   // "active"
GTL_EXTERN NSString * const kGTLYouTubeBroadcastStatusAll;      // "all"
GTL_EXTERN NSString * const kGTLYouTubeBroadcastStatusComplete;  // "complete"
GTL_EXTERN NSString * const kGTLYouTubeBroadcastStatusCompleted;  // "completed"
GTL_EXTERN NSString * const kGTLYouTubeBroadcastStatusLive;     // "live"
GTL_EXTERN NSString * const kGTLYouTubeBroadcastStatusTesting;  // "testing"
GTL_EXTERN NSString * const kGTLYouTubeBroadcastStatusUpcoming;  // "upcoming"

// GTLQueryYouTube - ChannelType
GTL_EXTERN NSString * const kGTLYouTubeChannelTypeAny;   // "any"
GTL_EXTERN NSString * const kGTLYouTubeChannelTypeShow;  // "show"

// GTLQueryYouTube - Chart
GTL_EXTERN NSString * const kGTLYouTubeChartMostPopular;  // "mostPopular"

// GTLQueryYouTube - EventType
GTL_EXTERN NSString * const kGTLYouTubeEventTypeCompleted;  // "completed"
GTL_EXTERN NSString * const kGTLYouTubeEventTypeLive;       // "live"
GTL_EXTERN NSString * const kGTLYouTubeEventTypeUpcoming;   // "upcoming"

// GTLQueryYouTube - MyRating
GTL_EXTERN NSString * const kGTLYouTubeMyRatingDislike;  // "dislike"
GTL_EXTERN NSString * const kGTLYouTubeMyRatingLike;     // "like"

// GTLQueryYouTube - Order
GTL_EXTERN NSString * const kGTLYouTubeOrderAlphabetical;  // "alphabetical"
GTL_EXTERN NSString * const kGTLYouTubeOrderDate;          // "date"
GTL_EXTERN NSString * const kGTLYouTubeOrderRating;        // "rating"
GTL_EXTERN NSString * const kGTLYouTubeOrderRelevance;     // "relevance"
GTL_EXTERN NSString * const kGTLYouTubeOrderTitle;         // "title"
GTL_EXTERN NSString * const kGTLYouTubeOrderUnread;        // "unread"
GTL_EXTERN NSString * const kGTLYouTubeOrderVideoCount;    // "videoCount"
GTL_EXTERN NSString * const kGTLYouTubeOrderViewCount;     // "viewCount"

// GTLQueryYouTube - Rating
GTL_EXTERN NSString * const kGTLYouTubeRatingDislike;  // "dislike"
GTL_EXTERN NSString * const kGTLYouTubeRatingLike;     // "like"
GTL_EXTERN NSString * const kGTLYouTubeRatingNone;     // "none"

// GTLQueryYouTube - SafeSearch
GTL_EXTERN NSString * const kGTLYouTubeSafeSearchModerate;  // "moderate"
GTL_EXTERN NSString * const kGTLYouTubeSafeSearchNone;      // "none"
GTL_EXTERN NSString * const kGTLYouTubeSafeSearchStrict;    // "strict"

// GTLQueryYouTube - VideoCaption
GTL_EXTERN NSString * const kGTLYouTubeVideoCaptionAny;         // "any"
GTL_EXTERN NSString * const kGTLYouTubeVideoCaptionClosedCaption;  // "closedCaption"
GTL_EXTERN NSString * const kGTLYouTubeVideoCaptionNone;        // "none"

// GTLQueryYouTube - VideoDefinition
GTL_EXTERN NSString * const kGTLYouTubeVideoDefinitionAny;      // "any"
GTL_EXTERN NSString * const kGTLYouTubeVideoDefinitionHigh;     // "high"
GTL_EXTERN NSString * const kGTLYouTubeVideoDefinitionStandard;  // "standard"

// GTLQueryYouTube - VideoDimension
GTL_EXTERN NSString * const kGTLYouTubeVideoDimensionAny;  // "any"
GTL_EXTERN NSString * const kGTLYouTubeVideoDimensionX2d;  // "2d"
GTL_EXTERN NSString * const kGTLYouTubeVideoDimensionX3d;  // "3d"

// GTLQueryYouTube - VideoDuration
GTL_EXTERN NSString * const kGTLYouTubeVideoDurationAny;     // "any"
GTL_EXTERN NSString * const kGTLYouTubeVideoDurationLong;    // "long"
GTL_EXTERN NSString * const kGTLYouTubeVideoDurationMedium;  // "medium"
GTL_EXTERN NSString * const kGTLYouTubeVideoDurationShort;   // "short"

// GTLQueryYouTube - VideoEmbeddable
GTL_EXTERN NSString * const kGTLYouTubeVideoEmbeddableAny;   // "any"
GTL_EXTERN NSString * const kGTLYouTubeVideoEmbeddableTrue;  // "true"

// GTLQueryYouTube - VideoLicense
GTL_EXTERN NSString * const kGTLYouTubeVideoLicenseAny;         // "any"
GTL_EXTERN NSString * const kGTLYouTubeVideoLicenseCreativeCommon;  // "creativeCommon"
GTL_EXTERN NSString * const kGTLYouTubeVideoLicenseYoutube;     // "youtube"

// GTLQueryYouTube - VideoSyndicated
GTL_EXTERN NSString * const kGTLYouTubeVideoSyndicatedAny;   // "any"
GTL_EXTERN NSString * const kGTLYouTubeVideoSyndicatedTrue;  // "true"

// GTLQueryYouTube - VideoType
GTL_EXTERN NSString * const kGTLYouTubeVideoTypeAny;      // "any"
GTL_EXTERN NSString * const kGTLYouTubeVideoTypeEpisode;  // "episode"
GTL_EXTERN NSString * const kGTLYouTubeVideoTypeMovie;    // "movie"

// GTLYouTubeActivityContentDetailsPromotedItem - CtaType
GTL_EXTERN NSString * const kGTLYouTubeActivityContentDetailsPromotedItem_CtaType_Unspecified;  // "unspecified"
GTL_EXTERN NSString * const kGTLYouTubeActivityContentDetailsPromotedItem_CtaType_VisitAdvertiserSite;  // "visitAdvertiserSite"

// GTLYouTubeActivityContentDetailsRecommendation - Reason
GTL_EXTERN NSString * const kGTLYouTubeActivityContentDetailsRecommendation_Reason_Unspecified;  // "unspecified"
GTL_EXTERN NSString * const kGTLYouTubeActivityContentDetailsRecommendation_Reason_VideoFavorited;  // "videoFavorited"
GTL_EXTERN NSString * const kGTLYouTubeActivityContentDetailsRecommendation_Reason_VideoLiked;  // "videoLiked"
GTL_EXTERN NSString * const kGTLYouTubeActivityContentDetailsRecommendation_Reason_VideoWatched;  // "videoWatched"

// GTLYouTubeActivityContentDetailsSocial - Type
GTL_EXTERN NSString * const kGTLYouTubeActivityContentDetailsSocial_Type_Facebook;  // "facebook"
GTL_EXTERN NSString * const kGTLYouTubeActivityContentDetailsSocial_Type_GooglePlus;  // "googlePlus"
GTL_EXTERN NSString * const kGTLYouTubeActivityContentDetailsSocial_Type_Twitter;  // "twitter"
GTL_EXTERN NSString * const kGTLYouTubeActivityContentDetailsSocial_Type_Unspecified;  // "unspecified"

// GTLYouTubeActivitySnippet - Type
GTL_EXTERN NSString * const kGTLYouTubeActivitySnippet_Type_Bulletin;  // "bulletin"
GTL_EXTERN NSString * const kGTLYouTubeActivitySnippet_Type_ChannelItem;  // "channelItem"
GTL_EXTERN NSString * const kGTLYouTubeActivitySnippet_Type_Comment;  // "comment"
GTL_EXTERN NSString * const kGTLYouTubeActivitySnippet_Type_Favorite;  // "favorite"
GTL_EXTERN NSString * const kGTLYouTubeActivitySnippet_Type_Like;  // "like"
GTL_EXTERN NSString * const kGTLYouTubeActivitySnippet_Type_PlaylistItem;  // "playlistItem"
GTL_EXTERN NSString * const kGTLYouTubeActivitySnippet_Type_PromotedItem;  // "promotedItem"
GTL_EXTERN NSString * const kGTLYouTubeActivitySnippet_Type_Recommendation;  // "recommendation"
GTL_EXTERN NSString * const kGTLYouTubeActivitySnippet_Type_Social;  // "social"
GTL_EXTERN NSString * const kGTLYouTubeActivitySnippet_Type_Subscription;  // "subscription"
GTL_EXTERN NSString * const kGTLYouTubeActivitySnippet_Type_Upload;  // "upload"

// GTLYouTubeCdnSettings - IngestionType
GTL_EXTERN NSString * const kGTLYouTubeCdnSettings_IngestionType_Rtmp;  // "rtmp"

// GTLYouTubeChannelConversionPing - Context
GTL_EXTERN NSString * const kGTLYouTubeChannelConversionPing_Context_Cview;  // "cview"
GTL_EXTERN NSString * const kGTLYouTubeChannelConversionPing_Context_Subscribe;  // "subscribe"
GTL_EXTERN NSString * const kGTLYouTubeChannelConversionPing_Context_Unsubscribe;  // "unsubscribe"

// GTLYouTubeChannelSectionSnippet - Style
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Style_ChannelsectionStyleUndefined;  // "channelsectionStyleUndefined"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Style_HorizontalRow;  // "horizontalRow"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Style_VerticalList;  // "verticalList"

// GTLYouTubeChannelSectionSnippet - Type
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_AllPlaylists;  // "allPlaylists"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_ChannelsectionTypeUndefined;  // "channelsectionTypeUndefined"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_CompletedEvents;  // "completedEvents"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_LikedPlaylists;  // "likedPlaylists"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_Likes;  // "likes"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_LiveEvents;  // "liveEvents"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_MultipleChannels;  // "multipleChannels"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_MultiplePlaylists;  // "multiplePlaylists"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_PopularUploads;  // "popularUploads"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_PostedPlaylists;  // "postedPlaylists"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_PostedVideos;  // "postedVideos"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_RecentActivity;  // "recentActivity"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_RecentPosts;  // "recentPosts"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_RecentUploads;  // "recentUploads"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_SinglePlaylist;  // "singlePlaylist"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_Subscriptions;  // "subscriptions"
GTL_EXTERN NSString * const kGTLYouTubeChannelSectionSnippet_Type_UpcomingEvents;  // "upcomingEvents"

// GTLYouTubeChannelStatus - PrivacyStatus
GTL_EXTERN NSString * const kGTLYouTubeChannelStatus_PrivacyStatus_Private;  // "private"
GTL_EXTERN NSString * const kGTLYouTubeChannelStatus_PrivacyStatus_Public;  // "public"
GTL_EXTERN NSString * const kGTLYouTubeChannelStatus_PrivacyStatus_Unlisted;  // "unlisted"

// GTLYouTubeContentRating - AcbRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_AcbRating_AcbC;  // "acbC"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_AcbRating_AcbE;  // "acbE"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_AcbRating_AcbG;  // "acbG"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_AcbRating_AcbM;  // "acbM"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_AcbRating_AcbMa15plus;  // "acbMa15plus"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_AcbRating_AcbP;  // "acbP"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_AcbRating_AcbPg;  // "acbPg"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_AcbRating_AcbR18plus;  // "acbR18plus"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_AcbRating_AcbUnrated;  // "acbUnrated"

// GTLYouTubeContentRating - BbfcRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_BbfcRating_Bbfc12;  // "bbfc12"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_BbfcRating_Bbfc12a;  // "bbfc12a"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_BbfcRating_Bbfc15;  // "bbfc15"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_BbfcRating_Bbfc18;  // "bbfc18"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_BbfcRating_BbfcPg;  // "bbfcPg"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_BbfcRating_BbfcR18;  // "bbfcR18"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_BbfcRating_BbfcU;  // "bbfcU"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_BbfcRating_BbfcUnrated;  // "bbfcUnrated"

// GTLYouTubeContentRating - CatvfrRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CatvfrRating_Catvfr13plus;  // "catvfr13plus"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CatvfrRating_Catvfr16plus;  // "catvfr16plus"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CatvfrRating_Catvfr18plus;  // "catvfr18plus"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CatvfrRating_Catvfr8plus;  // "catvfr8plus"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CatvfrRating_CatvfrG;  // "catvfrG"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CatvfrRating_CatvfrUnrated;  // "catvfrUnrated"

// GTLYouTubeContentRating - CatvRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CatvRating_Catv14plus;  // "catv14plus"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CatvRating_Catv18plus;  // "catv18plus"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CatvRating_CatvC;  // "catvC"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CatvRating_CatvC8;  // "catvC8"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CatvRating_CatvG;  // "catvG"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CatvRating_CatvPg;  // "catvPg"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CatvRating_CatvUnrated;  // "catvUnrated"

// GTLYouTubeContentRating - CbfcRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CbfcRating_CbfcA;  // "cbfcA"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CbfcRating_CbfcS;  // "cbfcS"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CbfcRating_CbfcU;  // "cbfcU"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CbfcRating_CbfcUA;  // "cbfcUA"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_CbfcRating_CbfcUnrated;  // "cbfcUnrated"

// GTLYouTubeContentRating - ChvrsRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_ChvrsRating_Chvrs14a;  // "chvrs14a"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_ChvrsRating_Chvrs18a;  // "chvrs18a"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_ChvrsRating_ChvrsE;  // "chvrsE"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_ChvrsRating_ChvrsG;  // "chvrsG"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_ChvrsRating_ChvrsPg;  // "chvrsPg"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_ChvrsRating_ChvrsR;  // "chvrsR"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_ChvrsRating_ChvrsUnrated;  // "chvrsUnrated"

// GTLYouTubeContentRating - DjctqRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_DjctqRating_Djctq10;  // "djctq10"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_DjctqRating_Djctq12;  // "djctq12"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_DjctqRating_Djctq14;  // "djctq14"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_DjctqRating_Djctq16;  // "djctq16"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_DjctqRating_Djctq18;  // "djctq18"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_DjctqRating_DjctqL;  // "djctqL"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_DjctqRating_DjctqUnrated;  // "djctqUnrated"

// GTLYouTubeContentRating - EirinRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_EirinRating_EirinG;  // "eirinG"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_EirinRating_EirinPg12;  // "eirinPg12"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_EirinRating_EirinR15plus;  // "eirinR15plus"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_EirinRating_EirinR18plus;  // "eirinR18plus"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_EirinRating_EirinUnrated;  // "eirinUnrated"

// GTLYouTubeContentRating - FmocRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_FmocRating_Fmoc10;  // "fmoc10"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_FmocRating_Fmoc12;  // "fmoc12"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_FmocRating_Fmoc16;  // "fmoc16"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_FmocRating_Fmoc18;  // "fmoc18"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_FmocRating_FmocE;  // "fmocE"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_FmocRating_FmocU;  // "fmocU"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_FmocRating_FmocUnrated;  // "fmocUnrated"

// GTLYouTubeContentRating - FskRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_FskRating_Fsk0;  // "fsk0"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_FskRating_Fsk12;  // "fsk12"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_FskRating_Fsk16;  // "fsk16"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_FskRating_Fsk18;  // "fsk18"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_FskRating_Fsk6;  // "fsk6"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_FskRating_FskUnrated;  // "fskUnrated"

// GTLYouTubeContentRating - IcaaRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_IcaaRating_Icaa12;  // "icaa12"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_IcaaRating_Icaa13;  // "icaa13"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_IcaaRating_Icaa16;  // "icaa16"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_IcaaRating_Icaa18;  // "icaa18"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_IcaaRating_Icaa7;  // "icaa7"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_IcaaRating_IcaaApta;  // "icaaApta"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_IcaaRating_IcaaUnrated;  // "icaaUnrated"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_IcaaRating_IcaaX;  // "icaaX"

// GTLYouTubeContentRating - KmrbRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_KmrbRating_Kmrb12plus;  // "kmrb12plus"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_KmrbRating_Kmrb15plus;  // "kmrb15plus"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_KmrbRating_KmrbAll;  // "kmrbAll"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_KmrbRating_KmrbR;  // "kmrbR"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_KmrbRating_KmrbTeenr;  // "kmrbTeenr"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_KmrbRating_KmrbUnrated;  // "kmrbUnrated"

// GTLYouTubeContentRating - MibacRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_MibacRating_MibacT;  // "mibacT"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_MibacRating_MibacUnrated;  // "mibacUnrated"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_MibacRating_MibacVap;  // "mibacVap"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_MibacRating_MibacVm12;  // "mibacVm12"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_MibacRating_MibacVm14;  // "mibacVm14"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_MibacRating_MibacVm18;  // "mibacVm18"

// GTLYouTubeContentRating - MpaaRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_MpaaRating_MpaaG;  // "mpaaG"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_MpaaRating_MpaaNc17;  // "mpaaNc17"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_MpaaRating_MpaaPg;  // "mpaaPg"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_MpaaRating_MpaaPg13;  // "mpaaPg13"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_MpaaRating_MpaaR;  // "mpaaR"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_MpaaRating_MpaaUnrated;  // "mpaaUnrated"

// GTLYouTubeContentRating - OflcRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_OflcRating_OflcG;  // "oflcG"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_OflcRating_OflcM;  // "oflcM"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_OflcRating_OflcPg;  // "oflcPg"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_OflcRating_OflcR13;  // "oflcR13"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_OflcRating_OflcR15;  // "oflcR15"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_OflcRating_OflcR16;  // "oflcR16"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_OflcRating_OflcR18;  // "oflcR18"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_OflcRating_OflcUnrated;  // "oflcUnrated"

// GTLYouTubeContentRating - RtcRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_RtcRating_RtcA;  // "rtcA"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_RtcRating_RtcAa;  // "rtcAa"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_RtcRating_RtcB;  // "rtcB"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_RtcRating_RtcB15;  // "rtcB15"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_RtcRating_RtcC;  // "rtcC"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_RtcRating_RtcD;  // "rtcD"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_RtcRating_RtcUnrated;  // "rtcUnrated"

// GTLYouTubeContentRating - RussiaRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_RussiaRating_Russia0;  // "russia0"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_RussiaRating_Russia12;  // "russia12"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_RussiaRating_Russia16;  // "russia16"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_RussiaRating_Russia18;  // "russia18"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_RussiaRating_Russia6;  // "russia6"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_RussiaRating_RussiaUnrated;  // "russiaUnrated"

// GTLYouTubeContentRating - TvpgRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_TvpgRating_Pg14;  // "pg14"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_TvpgRating_TvpgG;  // "tvpgG"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_TvpgRating_TvpgMa;  // "tvpgMa"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_TvpgRating_TvpgPg;  // "tvpgPg"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_TvpgRating_TvpgUnrated;  // "tvpgUnrated"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_TvpgRating_TvpgY;  // "tvpgY"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_TvpgRating_TvpgY7;  // "tvpgY7"
GTL_EXTERN NSString * const kGTLYouTubeContentRating_TvpgRating_TvpgY7Fv;  // "tvpgY7Fv"

// GTLYouTubeContentRating - YtRating
GTL_EXTERN NSString * const kGTLYouTubeContentRating_YtRating_YtAgeRestricted;  // "ytAgeRestricted"

// GTLYouTubeInvideoPosition - CornerPosition
GTL_EXTERN NSString * const kGTLYouTubeInvideoPosition_CornerPosition_BottomLeft;  // "bottomLeft"
GTL_EXTERN NSString * const kGTLYouTubeInvideoPosition_CornerPosition_BottomRight;  // "bottomRight"
GTL_EXTERN NSString * const kGTLYouTubeInvideoPosition_CornerPosition_TopLeft;  // "topLeft"
GTL_EXTERN NSString * const kGTLYouTubeInvideoPosition_CornerPosition_TopRight;  // "topRight"

// GTLYouTubeInvideoPosition - Type
GTL_EXTERN NSString * const kGTLYouTubeInvideoPosition_Type_Corner;  // "corner"

// GTLYouTubeInvideoTiming - Type
GTL_EXTERN NSString * const kGTLYouTubeInvideoTiming_Type_OffsetFromEnd;  // "offsetFromEnd"
GTL_EXTERN NSString * const kGTLYouTubeInvideoTiming_Type_OffsetFromStart;  // "offsetFromStart"

// GTLYouTubeLiveBroadcastStatus - LifeCycleStatus
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_Abandoned;  // "abandoned"
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_Complete;  // "complete"
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_CompleteStarting;  // "completeStarting"
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_Created;  // "created"
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_Live;  // "live"
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_LiveStarting;  // "liveStarting"
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_Ready;  // "ready"
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_Reclaimed;  // "reclaimed"
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_Revoked;  // "revoked"
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_Testing;  // "testing"
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_TestStarting;  // "testStarting"

// GTLYouTubeLiveBroadcastStatus - PrivacyStatus
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_PrivacyStatus_Private;  // "private"
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_PrivacyStatus_Public;  // "public"
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_PrivacyStatus_Unlisted;  // "unlisted"

// GTLYouTubeLiveBroadcastStatus - RecordingStatus
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_RecordingStatus_NotRecording;  // "notRecording"
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_RecordingStatus_Recorded;  // "recorded"
GTL_EXTERN NSString * const kGTLYouTubeLiveBroadcastStatus_RecordingStatus_Recording;  // "recording"

// GTLYouTubeLiveStreamStatus - StreamStatus
GTL_EXTERN NSString * const kGTLYouTubeLiveStreamStatus_StreamStatus_Active;  // "active"
GTL_EXTERN NSString * const kGTLYouTubeLiveStreamStatus_StreamStatus_Created;  // "created"
GTL_EXTERN NSString * const kGTLYouTubeLiveStreamStatus_StreamStatus_Error;  // "error"
GTL_EXTERN NSString * const kGTLYouTubeLiveStreamStatus_StreamStatus_Inactive;  // "inactive"
GTL_EXTERN NSString * const kGTLYouTubeLiveStreamStatus_StreamStatus_Ready;  // "ready"

// GTLYouTubePlaylistItemStatus - PrivacyStatus
GTL_EXTERN NSString * const kGTLYouTubePlaylistItemStatus_PrivacyStatus_Private;  // "private"
GTL_EXTERN NSString * const kGTLYouTubePlaylistItemStatus_PrivacyStatus_Public;  // "public"
GTL_EXTERN NSString * const kGTLYouTubePlaylistItemStatus_PrivacyStatus_Unlisted;  // "unlisted"

// GTLYouTubePlaylistStatus - PrivacyStatus
GTL_EXTERN NSString * const kGTLYouTubePlaylistStatus_PrivacyStatus_Private;  // "private"
GTL_EXTERN NSString * const kGTLYouTubePlaylistStatus_PrivacyStatus_Public;  // "public"
GTL_EXTERN NSString * const kGTLYouTubePlaylistStatus_PrivacyStatus_Unlisted;  // "unlisted"

// GTLYouTubePromotedItemId - Type
GTL_EXTERN NSString * const kGTLYouTubePromotedItemId_Type_RecentUpload;  // "recentUpload"
GTL_EXTERN NSString * const kGTLYouTubePromotedItemId_Type_Video;  // "video"
GTL_EXTERN NSString * const kGTLYouTubePromotedItemId_Type_Website;  // "website"

// GTLYouTubeSearchResultSnippet - LiveBroadcastContent
GTL_EXTERN NSString * const kGTLYouTubeSearchResultSnippet_LiveBroadcastContent_Live;  // "live"
GTL_EXTERN NSString * const kGTLYouTubeSearchResultSnippet_LiveBroadcastContent_None;  // "none"
GTL_EXTERN NSString * const kGTLYouTubeSearchResultSnippet_LiveBroadcastContent_Upcoming;  // "upcoming"

// GTLYouTubeSubscriptionContentDetails - ActivityType
GTL_EXTERN NSString * const kGTLYouTubeSubscriptionContentDetails_ActivityType_All;  // "all"
GTL_EXTERN NSString * const kGTLYouTubeSubscriptionContentDetails_ActivityType_Uploads;  // "uploads"

// GTLYouTubeVideoAgeGating - VideoGameRating
GTL_EXTERN NSString * const kGTLYouTubeVideoAgeGating_VideoGameRating_Anyone;  // "anyone"
GTL_EXTERN NSString * const kGTLYouTubeVideoAgeGating_VideoGameRating_M15Plus;  // "m15Plus"
GTL_EXTERN NSString * const kGTLYouTubeVideoAgeGating_VideoGameRating_M16Plus;  // "m16Plus"
GTL_EXTERN NSString * const kGTLYouTubeVideoAgeGating_VideoGameRating_M17Plus;  // "m17Plus"

// GTLYouTubeVideoContentDetails - Caption
GTL_EXTERN NSString * const kGTLYouTubeVideoContentDetails_Caption_False;  // "false"
GTL_EXTERN NSString * const kGTLYouTubeVideoContentDetails_Caption_True;  // "true"

// GTLYouTubeVideoContentDetails - Definition
GTL_EXTERN NSString * const kGTLYouTubeVideoContentDetails_Definition_Hd;  // "hd"
GTL_EXTERN NSString * const kGTLYouTubeVideoContentDetails_Definition_Sd;  // "sd"

// GTLYouTubeVideoConversionPing - Context
GTL_EXTERN NSString * const kGTLYouTubeVideoConversionPing_Context_Comment;  // "comment"
GTL_EXTERN NSString * const kGTLYouTubeVideoConversionPing_Context_Dislike;  // "dislike"
GTL_EXTERN NSString * const kGTLYouTubeVideoConversionPing_Context_Like;  // "like"
GTL_EXTERN NSString * const kGTLYouTubeVideoConversionPing_Context_Share;  // "share"

// GTLYouTubeVideoFileDetails - FileType
GTL_EXTERN NSString * const kGTLYouTubeVideoFileDetails_FileType_Archive;  // "archive"
GTL_EXTERN NSString * const kGTLYouTubeVideoFileDetails_FileType_Audio;  // "audio"
GTL_EXTERN NSString * const kGTLYouTubeVideoFileDetails_FileType_Document;  // "document"
GTL_EXTERN NSString * const kGTLYouTubeVideoFileDetails_FileType_Image;  // "image"
GTL_EXTERN NSString * const kGTLYouTubeVideoFileDetails_FileType_Other;  // "other"
GTL_EXTERN NSString * const kGTLYouTubeVideoFileDetails_FileType_Project;  // "project"
GTL_EXTERN NSString * const kGTLYouTubeVideoFileDetails_FileType_Video;  // "video"

// GTLYouTubeVideoFileDetailsVideoStream - Rotation
GTL_EXTERN NSString * const kGTLYouTubeVideoFileDetailsVideoStream_Rotation_Clockwise;  // "clockwise"
GTL_EXTERN NSString * const kGTLYouTubeVideoFileDetailsVideoStream_Rotation_CounterClockwise;  // "counterClockwise"
GTL_EXTERN NSString * const kGTLYouTubeVideoFileDetailsVideoStream_Rotation_None;  // "none"
GTL_EXTERN NSString * const kGTLYouTubeVideoFileDetailsVideoStream_Rotation_Other;  // "other"
GTL_EXTERN NSString * const kGTLYouTubeVideoFileDetailsVideoStream_Rotation_UpsideDown;  // "upsideDown"

// GTLYouTubeVideoProcessingDetails - ProcessingFailureReason
GTL_EXTERN NSString * const kGTLYouTubeVideoProcessingDetails_ProcessingFailureReason_Other;  // "other"
GTL_EXTERN NSString * const kGTLYouTubeVideoProcessingDetails_ProcessingFailureReason_StreamingFailed;  // "streamingFailed"
GTL_EXTERN NSString * const kGTLYouTubeVideoProcessingDetails_ProcessingFailureReason_TranscodeFailed;  // "transcodeFailed"
GTL_EXTERN NSString * const kGTLYouTubeVideoProcessingDetails_ProcessingFailureReason_UploadFailed;  // "uploadFailed"

// GTLYouTubeVideoProcessingDetails - ProcessingStatus
GTL_EXTERN NSString * const kGTLYouTubeVideoProcessingDetails_ProcessingStatus_Failed;  // "failed"
GTL_EXTERN NSString * const kGTLYouTubeVideoProcessingDetails_ProcessingStatus_Processing;  // "processing"
GTL_EXTERN NSString * const kGTLYouTubeVideoProcessingDetails_ProcessingStatus_Succeeded;  // "succeeded"
GTL_EXTERN NSString * const kGTLYouTubeVideoProcessingDetails_ProcessingStatus_Terminated;  // "terminated"

// GTLYouTubeVideoRating - Rating
GTL_EXTERN NSString * const kGTLYouTubeVideoRating_Rating_Dislike;  // "dislike"
GTL_EXTERN NSString * const kGTLYouTubeVideoRating_Rating_Like;  // "like"
GTL_EXTERN NSString * const kGTLYouTubeVideoRating_Rating_None;  // "none"
GTL_EXTERN NSString * const kGTLYouTubeVideoRating_Rating_Unspecified;  // "unspecified"

// GTLYouTubeVideoSnippet - LiveBroadcastContent
GTL_EXTERN NSString * const kGTLYouTubeVideoSnippet_LiveBroadcastContent_Live;  // "live"
GTL_EXTERN NSString * const kGTLYouTubeVideoSnippet_LiveBroadcastContent_None;  // "none"
GTL_EXTERN NSString * const kGTLYouTubeVideoSnippet_LiveBroadcastContent_Upcoming;  // "upcoming"

// GTLYouTubeVideoStatus - FailureReason
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_FailureReason_Codec;  // "codec"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_FailureReason_Conversion;  // "conversion"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_FailureReason_EmptyFile;  // "emptyFile"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_FailureReason_InvalidFile;  // "invalidFile"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_FailureReason_TooSmall;  // "tooSmall"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_FailureReason_UploadAborted;  // "uploadAborted"

// GTLYouTubeVideoStatus - License
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_License_CreativeCommon;  // "creativeCommon"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_License_Youtube;  // "youtube"

// GTLYouTubeVideoStatus - PrivacyStatus
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_PrivacyStatus_Private;  // "private"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_PrivacyStatus_Public;  // "public"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_PrivacyStatus_Unlisted;  // "unlisted"

// GTLYouTubeVideoStatus - RejectionReason
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_RejectionReason_Claim;  // "claim"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_RejectionReason_Copyright;  // "copyright"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_RejectionReason_Duplicate;  // "duplicate"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_RejectionReason_Inappropriate;  // "inappropriate"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_RejectionReason_Length;  // "length"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_RejectionReason_TermsOfUse;  // "termsOfUse"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_RejectionReason_Trademark;  // "trademark"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_RejectionReason_UploaderAccountClosed;  // "uploaderAccountClosed"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_RejectionReason_UploaderAccountSuspended;  // "uploaderAccountSuspended"

// GTLYouTubeVideoStatus - UploadStatus
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_UploadStatus_Deleted;  // "deleted"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_UploadStatus_Failed;  // "failed"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_UploadStatus_Processed;  // "processed"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_UploadStatus_Rejected;  // "rejected"
GTL_EXTERN NSString * const kGTLYouTubeVideoStatus_UploadStatus_Uploaded;  // "uploaded"

// GTLYouTubeVideoSuggestions - EditorSuggestions
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_EditorSuggestions_AudioQuietAudioSwap;  // "audioQuietAudioSwap"
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_EditorSuggestions_VideoAutoLevels;  // "videoAutoLevels"
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_EditorSuggestions_VideoCrop;  // "videoCrop"
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_EditorSuggestions_VideoStabilize;  // "videoStabilize"

// GTLYouTubeVideoSuggestions - ProcessingErrors
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_ProcessingErrors_ArchiveFile;  // "archiveFile"
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_ProcessingErrors_AudioFile;  // "audioFile"
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_ProcessingErrors_DocFile;  // "docFile"
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_ProcessingErrors_ImageFile;  // "imageFile"
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_ProcessingErrors_NotAVideoFile;  // "notAVideoFile"
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_ProcessingErrors_ProjectFile;  // "projectFile"

// GTLYouTubeVideoSuggestions - ProcessingHints
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_ProcessingHints_NonStreamableMov;  // "nonStreamableMov"
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_ProcessingHints_SendBestQualityVideo;  // "sendBestQualityVideo"

// GTLYouTubeVideoSuggestions - ProcessingWarnings
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_ProcessingWarnings_HasEditlist;  // "hasEditlist"
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_ProcessingWarnings_InconsistentResolution;  // "inconsistentResolution"
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_ProcessingWarnings_ProblematicAudioCodec;  // "problematicAudioCodec"
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_ProcessingWarnings_ProblematicVideoCodec;  // "problematicVideoCodec"
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_ProcessingWarnings_UnknownAudioCodec;  // "unknownAudioCodec"
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_ProcessingWarnings_UnknownContainer;  // "unknownContainer"
GTL_EXTERN NSString * const kGTLYouTubeVideoSuggestions_ProcessingWarnings_UnknownVideoCodec;  // "unknownVideoCodec"
