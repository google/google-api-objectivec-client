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

// GTLQueryYouTube - BroadcastStatus
NSString * const kGTLYouTubeBroadcastStatusActive    = @"active";
NSString * const kGTLYouTubeBroadcastStatusAll       = @"all";
NSString * const kGTLYouTubeBroadcastStatusComplete  = @"complete";
NSString * const kGTLYouTubeBroadcastStatusCompleted = @"completed";
NSString * const kGTLYouTubeBroadcastStatusLive      = @"live";
NSString * const kGTLYouTubeBroadcastStatusTesting   = @"testing";
NSString * const kGTLYouTubeBroadcastStatusUpcoming  = @"upcoming";

// GTLQueryYouTube - ChannelType
NSString * const kGTLYouTubeChannelTypeAny  = @"any";
NSString * const kGTLYouTubeChannelTypeShow = @"show";

// GTLQueryYouTube - Chart
NSString * const kGTLYouTubeChartMostPopular = @"mostPopular";

// GTLQueryYouTube - EventType
NSString * const kGTLYouTubeEventTypeCompleted = @"completed";
NSString * const kGTLYouTubeEventTypeLive      = @"live";
NSString * const kGTLYouTubeEventTypeUpcoming  = @"upcoming";

// GTLQueryYouTube - MyRating
NSString * const kGTLYouTubeMyRatingDislike = @"dislike";
NSString * const kGTLYouTubeMyRatingLike    = @"like";

// GTLQueryYouTube - Order
NSString * const kGTLYouTubeOrderAlphabetical = @"alphabetical";
NSString * const kGTLYouTubeOrderDate         = @"date";
NSString * const kGTLYouTubeOrderRating       = @"rating";
NSString * const kGTLYouTubeOrderRelevance    = @"relevance";
NSString * const kGTLYouTubeOrderTitle        = @"title";
NSString * const kGTLYouTubeOrderUnread       = @"unread";
NSString * const kGTLYouTubeOrderVideoCount   = @"videoCount";
NSString * const kGTLYouTubeOrderViewCount    = @"viewCount";

// GTLQueryYouTube - Rating
NSString * const kGTLYouTubeRatingDislike = @"dislike";
NSString * const kGTLYouTubeRatingLike    = @"like";
NSString * const kGTLYouTubeRatingNone    = @"none";

// GTLQueryYouTube - SafeSearch
NSString * const kGTLYouTubeSafeSearchModerate = @"moderate";
NSString * const kGTLYouTubeSafeSearchNone     = @"none";
NSString * const kGTLYouTubeSafeSearchStrict   = @"strict";

// GTLQueryYouTube - VideoCaption
NSString * const kGTLYouTubeVideoCaptionAny           = @"any";
NSString * const kGTLYouTubeVideoCaptionClosedCaption = @"closedCaption";
NSString * const kGTLYouTubeVideoCaptionNone          = @"none";

// GTLQueryYouTube - VideoDefinition
NSString * const kGTLYouTubeVideoDefinitionAny      = @"any";
NSString * const kGTLYouTubeVideoDefinitionHigh     = @"high";
NSString * const kGTLYouTubeVideoDefinitionStandard = @"standard";

// GTLQueryYouTube - VideoDimension
NSString * const kGTLYouTubeVideoDimensionAny = @"any";
NSString * const kGTLYouTubeVideoDimensionX2d = @"2d";
NSString * const kGTLYouTubeVideoDimensionX3d = @"3d";

// GTLQueryYouTube - VideoDuration
NSString * const kGTLYouTubeVideoDurationAny    = @"any";
NSString * const kGTLYouTubeVideoDurationLong   = @"long";
NSString * const kGTLYouTubeVideoDurationMedium = @"medium";
NSString * const kGTLYouTubeVideoDurationShort  = @"short";

// GTLQueryYouTube - VideoEmbeddable
NSString * const kGTLYouTubeVideoEmbeddableAny  = @"any";
NSString * const kGTLYouTubeVideoEmbeddableTrue = @"true";

// GTLQueryYouTube - VideoLicense
NSString * const kGTLYouTubeVideoLicenseAny            = @"any";
NSString * const kGTLYouTubeVideoLicenseCreativeCommon = @"creativeCommon";
NSString * const kGTLYouTubeVideoLicenseYoutube        = @"youtube";

// GTLQueryYouTube - VideoSyndicated
NSString * const kGTLYouTubeVideoSyndicatedAny  = @"any";
NSString * const kGTLYouTubeVideoSyndicatedTrue = @"true";

// GTLQueryYouTube - VideoType
NSString * const kGTLYouTubeVideoTypeAny     = @"any";
NSString * const kGTLYouTubeVideoTypeEpisode = @"episode";
NSString * const kGTLYouTubeVideoTypeMovie   = @"movie";

// GTLYouTubeActivityContentDetailsPromotedItem - CtaType
NSString * const kGTLYouTubeActivityContentDetailsPromotedItem_CtaType_Unspecified = @"unspecified";
NSString * const kGTLYouTubeActivityContentDetailsPromotedItem_CtaType_VisitAdvertiserSite = @"visitAdvertiserSite";

// GTLYouTubeActivityContentDetailsRecommendation - Reason
NSString * const kGTLYouTubeActivityContentDetailsRecommendation_Reason_Unspecified = @"unspecified";
NSString * const kGTLYouTubeActivityContentDetailsRecommendation_Reason_VideoFavorited = @"videoFavorited";
NSString * const kGTLYouTubeActivityContentDetailsRecommendation_Reason_VideoLiked = @"videoLiked";
NSString * const kGTLYouTubeActivityContentDetailsRecommendation_Reason_VideoWatched = @"videoWatched";

// GTLYouTubeActivityContentDetailsSocial - Type
NSString * const kGTLYouTubeActivityContentDetailsSocial_Type_Facebook = @"facebook";
NSString * const kGTLYouTubeActivityContentDetailsSocial_Type_GooglePlus = @"googlePlus";
NSString * const kGTLYouTubeActivityContentDetailsSocial_Type_Twitter = @"twitter";
NSString * const kGTLYouTubeActivityContentDetailsSocial_Type_Unspecified = @"unspecified";

// GTLYouTubeActivitySnippet - Type
NSString * const kGTLYouTubeActivitySnippet_Type_Bulletin      = @"bulletin";
NSString * const kGTLYouTubeActivitySnippet_Type_ChannelItem   = @"channelItem";
NSString * const kGTLYouTubeActivitySnippet_Type_Comment       = @"comment";
NSString * const kGTLYouTubeActivitySnippet_Type_Favorite      = @"favorite";
NSString * const kGTLYouTubeActivitySnippet_Type_Like          = @"like";
NSString * const kGTLYouTubeActivitySnippet_Type_PlaylistItem  = @"playlistItem";
NSString * const kGTLYouTubeActivitySnippet_Type_PromotedItem  = @"promotedItem";
NSString * const kGTLYouTubeActivitySnippet_Type_Recommendation = @"recommendation";
NSString * const kGTLYouTubeActivitySnippet_Type_Social        = @"social";
NSString * const kGTLYouTubeActivitySnippet_Type_Subscription  = @"subscription";
NSString * const kGTLYouTubeActivitySnippet_Type_Upload        = @"upload";

// GTLYouTubeCdnSettings - IngestionType
NSString * const kGTLYouTubeCdnSettings_IngestionType_Rtmp = @"rtmp";

// GTLYouTubeChannelConversionPing - Context
NSString * const kGTLYouTubeChannelConversionPing_Context_Cview = @"cview";
NSString * const kGTLYouTubeChannelConversionPing_Context_Subscribe = @"subscribe";
NSString * const kGTLYouTubeChannelConversionPing_Context_Unsubscribe = @"unsubscribe";

// GTLYouTubeChannelSectionSnippet - Style
NSString * const kGTLYouTubeChannelSectionSnippet_Style_ChannelsectionStyleUndefined = @"channelsectionStyleUndefined";
NSString * const kGTLYouTubeChannelSectionSnippet_Style_HorizontalRow = @"horizontalRow";
NSString * const kGTLYouTubeChannelSectionSnippet_Style_VerticalList = @"verticalList";

// GTLYouTubeChannelSectionSnippet - Type
NSString * const kGTLYouTubeChannelSectionSnippet_Type_AllPlaylists = @"allPlaylists";
NSString * const kGTLYouTubeChannelSectionSnippet_Type_ChannelsectionTypeUndefined = @"channelsectionTypeUndefined";
NSString * const kGTLYouTubeChannelSectionSnippet_Type_CompletedEvents = @"completedEvents";
NSString * const kGTLYouTubeChannelSectionSnippet_Type_LikedPlaylists = @"likedPlaylists";
NSString * const kGTLYouTubeChannelSectionSnippet_Type_Likes   = @"likes";
NSString * const kGTLYouTubeChannelSectionSnippet_Type_LiveEvents = @"liveEvents";
NSString * const kGTLYouTubeChannelSectionSnippet_Type_MultipleChannels = @"multipleChannels";
NSString * const kGTLYouTubeChannelSectionSnippet_Type_MultiplePlaylists = @"multiplePlaylists";
NSString * const kGTLYouTubeChannelSectionSnippet_Type_PopularUploads = @"popularUploads";
NSString * const kGTLYouTubeChannelSectionSnippet_Type_PostedPlaylists = @"postedPlaylists";
NSString * const kGTLYouTubeChannelSectionSnippet_Type_PostedVideos = @"postedVideos";
NSString * const kGTLYouTubeChannelSectionSnippet_Type_RecentActivity = @"recentActivity";
NSString * const kGTLYouTubeChannelSectionSnippet_Type_RecentPosts = @"recentPosts";
NSString * const kGTLYouTubeChannelSectionSnippet_Type_RecentUploads = @"recentUploads";
NSString * const kGTLYouTubeChannelSectionSnippet_Type_SinglePlaylist = @"singlePlaylist";
NSString * const kGTLYouTubeChannelSectionSnippet_Type_Subscriptions = @"subscriptions";
NSString * const kGTLYouTubeChannelSectionSnippet_Type_UpcomingEvents = @"upcomingEvents";

// GTLYouTubeChannelStatus - PrivacyStatus
NSString * const kGTLYouTubeChannelStatus_PrivacyStatus_Private = @"private";
NSString * const kGTLYouTubeChannelStatus_PrivacyStatus_Public = @"public";
NSString * const kGTLYouTubeChannelStatus_PrivacyStatus_Unlisted = @"unlisted";

// GTLYouTubeContentRating - AcbRating
NSString * const kGTLYouTubeContentRating_AcbRating_AcbC       = @"acbC";
NSString * const kGTLYouTubeContentRating_AcbRating_AcbE       = @"acbE";
NSString * const kGTLYouTubeContentRating_AcbRating_AcbG       = @"acbG";
NSString * const kGTLYouTubeContentRating_AcbRating_AcbM       = @"acbM";
NSString * const kGTLYouTubeContentRating_AcbRating_AcbMa15plus = @"acbMa15plus";
NSString * const kGTLYouTubeContentRating_AcbRating_AcbP       = @"acbP";
NSString * const kGTLYouTubeContentRating_AcbRating_AcbPg      = @"acbPg";
NSString * const kGTLYouTubeContentRating_AcbRating_AcbR18plus = @"acbR18plus";
NSString * const kGTLYouTubeContentRating_AcbRating_AcbUnrated = @"acbUnrated";

// GTLYouTubeContentRating - BbfcRating
NSString * const kGTLYouTubeContentRating_BbfcRating_Bbfc12    = @"bbfc12";
NSString * const kGTLYouTubeContentRating_BbfcRating_Bbfc12a   = @"bbfc12a";
NSString * const kGTLYouTubeContentRating_BbfcRating_Bbfc15    = @"bbfc15";
NSString * const kGTLYouTubeContentRating_BbfcRating_Bbfc18    = @"bbfc18";
NSString * const kGTLYouTubeContentRating_BbfcRating_BbfcPg    = @"bbfcPg";
NSString * const kGTLYouTubeContentRating_BbfcRating_BbfcR18   = @"bbfcR18";
NSString * const kGTLYouTubeContentRating_BbfcRating_BbfcU     = @"bbfcU";
NSString * const kGTLYouTubeContentRating_BbfcRating_BbfcUnrated = @"bbfcUnrated";

// GTLYouTubeContentRating - CatvfrRating
NSString * const kGTLYouTubeContentRating_CatvfrRating_Catvfr13plus = @"catvfr13plus";
NSString * const kGTLYouTubeContentRating_CatvfrRating_Catvfr16plus = @"catvfr16plus";
NSString * const kGTLYouTubeContentRating_CatvfrRating_Catvfr18plus = @"catvfr18plus";
NSString * const kGTLYouTubeContentRating_CatvfrRating_Catvfr8plus = @"catvfr8plus";
NSString * const kGTLYouTubeContentRating_CatvfrRating_CatvfrG = @"catvfrG";
NSString * const kGTLYouTubeContentRating_CatvfrRating_CatvfrUnrated = @"catvfrUnrated";

// GTLYouTubeContentRating - CatvRating
NSString * const kGTLYouTubeContentRating_CatvRating_Catv14plus = @"catv14plus";
NSString * const kGTLYouTubeContentRating_CatvRating_Catv18plus = @"catv18plus";
NSString * const kGTLYouTubeContentRating_CatvRating_CatvC     = @"catvC";
NSString * const kGTLYouTubeContentRating_CatvRating_CatvC8    = @"catvC8";
NSString * const kGTLYouTubeContentRating_CatvRating_CatvG     = @"catvG";
NSString * const kGTLYouTubeContentRating_CatvRating_CatvPg    = @"catvPg";
NSString * const kGTLYouTubeContentRating_CatvRating_CatvUnrated = @"catvUnrated";

// GTLYouTubeContentRating - CbfcRating
NSString * const kGTLYouTubeContentRating_CbfcRating_CbfcA     = @"cbfcA";
NSString * const kGTLYouTubeContentRating_CbfcRating_CbfcS     = @"cbfcS";
NSString * const kGTLYouTubeContentRating_CbfcRating_CbfcU     = @"cbfcU";
NSString * const kGTLYouTubeContentRating_CbfcRating_CbfcUA    = @"cbfcUA";
NSString * const kGTLYouTubeContentRating_CbfcRating_CbfcUnrated = @"cbfcUnrated";

// GTLYouTubeContentRating - ChvrsRating
NSString * const kGTLYouTubeContentRating_ChvrsRating_Chvrs14a = @"chvrs14a";
NSString * const kGTLYouTubeContentRating_ChvrsRating_Chvrs18a = @"chvrs18a";
NSString * const kGTLYouTubeContentRating_ChvrsRating_ChvrsE   = @"chvrsE";
NSString * const kGTLYouTubeContentRating_ChvrsRating_ChvrsG   = @"chvrsG";
NSString * const kGTLYouTubeContentRating_ChvrsRating_ChvrsPg  = @"chvrsPg";
NSString * const kGTLYouTubeContentRating_ChvrsRating_ChvrsR   = @"chvrsR";
NSString * const kGTLYouTubeContentRating_ChvrsRating_ChvrsUnrated = @"chvrsUnrated";

// GTLYouTubeContentRating - DjctqRating
NSString * const kGTLYouTubeContentRating_DjctqRating_Djctq10  = @"djctq10";
NSString * const kGTLYouTubeContentRating_DjctqRating_Djctq12  = @"djctq12";
NSString * const kGTLYouTubeContentRating_DjctqRating_Djctq14  = @"djctq14";
NSString * const kGTLYouTubeContentRating_DjctqRating_Djctq16  = @"djctq16";
NSString * const kGTLYouTubeContentRating_DjctqRating_Djctq18  = @"djctq18";
NSString * const kGTLYouTubeContentRating_DjctqRating_DjctqL   = @"djctqL";
NSString * const kGTLYouTubeContentRating_DjctqRating_DjctqUnrated = @"djctqUnrated";

// GTLYouTubeContentRating - EirinRating
NSString * const kGTLYouTubeContentRating_EirinRating_EirinG   = @"eirinG";
NSString * const kGTLYouTubeContentRating_EirinRating_EirinPg12 = @"eirinPg12";
NSString * const kGTLYouTubeContentRating_EirinRating_EirinR15plus = @"eirinR15plus";
NSString * const kGTLYouTubeContentRating_EirinRating_EirinR18plus = @"eirinR18plus";
NSString * const kGTLYouTubeContentRating_EirinRating_EirinUnrated = @"eirinUnrated";

// GTLYouTubeContentRating - FmocRating
NSString * const kGTLYouTubeContentRating_FmocRating_Fmoc10    = @"fmoc10";
NSString * const kGTLYouTubeContentRating_FmocRating_Fmoc12    = @"fmoc12";
NSString * const kGTLYouTubeContentRating_FmocRating_Fmoc16    = @"fmoc16";
NSString * const kGTLYouTubeContentRating_FmocRating_Fmoc18    = @"fmoc18";
NSString * const kGTLYouTubeContentRating_FmocRating_FmocE     = @"fmocE";
NSString * const kGTLYouTubeContentRating_FmocRating_FmocU     = @"fmocU";
NSString * const kGTLYouTubeContentRating_FmocRating_FmocUnrated = @"fmocUnrated";

// GTLYouTubeContentRating - FskRating
NSString * const kGTLYouTubeContentRating_FskRating_Fsk0       = @"fsk0";
NSString * const kGTLYouTubeContentRating_FskRating_Fsk12      = @"fsk12";
NSString * const kGTLYouTubeContentRating_FskRating_Fsk16      = @"fsk16";
NSString * const kGTLYouTubeContentRating_FskRating_Fsk18      = @"fsk18";
NSString * const kGTLYouTubeContentRating_FskRating_Fsk6       = @"fsk6";
NSString * const kGTLYouTubeContentRating_FskRating_FskUnrated = @"fskUnrated";

// GTLYouTubeContentRating - IcaaRating
NSString * const kGTLYouTubeContentRating_IcaaRating_Icaa12    = @"icaa12";
NSString * const kGTLYouTubeContentRating_IcaaRating_Icaa13    = @"icaa13";
NSString * const kGTLYouTubeContentRating_IcaaRating_Icaa16    = @"icaa16";
NSString * const kGTLYouTubeContentRating_IcaaRating_Icaa18    = @"icaa18";
NSString * const kGTLYouTubeContentRating_IcaaRating_Icaa7     = @"icaa7";
NSString * const kGTLYouTubeContentRating_IcaaRating_IcaaApta  = @"icaaApta";
NSString * const kGTLYouTubeContentRating_IcaaRating_IcaaUnrated = @"icaaUnrated";
NSString * const kGTLYouTubeContentRating_IcaaRating_IcaaX     = @"icaaX";

// GTLYouTubeContentRating - KmrbRating
NSString * const kGTLYouTubeContentRating_KmrbRating_Kmrb12plus = @"kmrb12plus";
NSString * const kGTLYouTubeContentRating_KmrbRating_Kmrb15plus = @"kmrb15plus";
NSString * const kGTLYouTubeContentRating_KmrbRating_KmrbAll   = @"kmrbAll";
NSString * const kGTLYouTubeContentRating_KmrbRating_KmrbR     = @"kmrbR";
NSString * const kGTLYouTubeContentRating_KmrbRating_KmrbTeenr = @"kmrbTeenr";
NSString * const kGTLYouTubeContentRating_KmrbRating_KmrbUnrated = @"kmrbUnrated";

// GTLYouTubeContentRating - MibacRating
NSString * const kGTLYouTubeContentRating_MibacRating_MibacT   = @"mibacT";
NSString * const kGTLYouTubeContentRating_MibacRating_MibacUnrated = @"mibacUnrated";
NSString * const kGTLYouTubeContentRating_MibacRating_MibacVap = @"mibacVap";
NSString * const kGTLYouTubeContentRating_MibacRating_MibacVm12 = @"mibacVm12";
NSString * const kGTLYouTubeContentRating_MibacRating_MibacVm14 = @"mibacVm14";
NSString * const kGTLYouTubeContentRating_MibacRating_MibacVm18 = @"mibacVm18";

// GTLYouTubeContentRating - MpaaRating
NSString * const kGTLYouTubeContentRating_MpaaRating_MpaaG     = @"mpaaG";
NSString * const kGTLYouTubeContentRating_MpaaRating_MpaaNc17  = @"mpaaNc17";
NSString * const kGTLYouTubeContentRating_MpaaRating_MpaaPg    = @"mpaaPg";
NSString * const kGTLYouTubeContentRating_MpaaRating_MpaaPg13  = @"mpaaPg13";
NSString * const kGTLYouTubeContentRating_MpaaRating_MpaaR     = @"mpaaR";
NSString * const kGTLYouTubeContentRating_MpaaRating_MpaaUnrated = @"mpaaUnrated";

// GTLYouTubeContentRating - OflcRating
NSString * const kGTLYouTubeContentRating_OflcRating_OflcG     = @"oflcG";
NSString * const kGTLYouTubeContentRating_OflcRating_OflcM     = @"oflcM";
NSString * const kGTLYouTubeContentRating_OflcRating_OflcPg    = @"oflcPg";
NSString * const kGTLYouTubeContentRating_OflcRating_OflcR13   = @"oflcR13";
NSString * const kGTLYouTubeContentRating_OflcRating_OflcR15   = @"oflcR15";
NSString * const kGTLYouTubeContentRating_OflcRating_OflcR16   = @"oflcR16";
NSString * const kGTLYouTubeContentRating_OflcRating_OflcR18   = @"oflcR18";
NSString * const kGTLYouTubeContentRating_OflcRating_OflcUnrated = @"oflcUnrated";

// GTLYouTubeContentRating - RtcRating
NSString * const kGTLYouTubeContentRating_RtcRating_RtcA       = @"rtcA";
NSString * const kGTLYouTubeContentRating_RtcRating_RtcAa      = @"rtcAa";
NSString * const kGTLYouTubeContentRating_RtcRating_RtcB       = @"rtcB";
NSString * const kGTLYouTubeContentRating_RtcRating_RtcB15     = @"rtcB15";
NSString * const kGTLYouTubeContentRating_RtcRating_RtcC       = @"rtcC";
NSString * const kGTLYouTubeContentRating_RtcRating_RtcD       = @"rtcD";
NSString * const kGTLYouTubeContentRating_RtcRating_RtcUnrated = @"rtcUnrated";

// GTLYouTubeContentRating - RussiaRating
NSString * const kGTLYouTubeContentRating_RussiaRating_Russia0 = @"russia0";
NSString * const kGTLYouTubeContentRating_RussiaRating_Russia12 = @"russia12";
NSString * const kGTLYouTubeContentRating_RussiaRating_Russia16 = @"russia16";
NSString * const kGTLYouTubeContentRating_RussiaRating_Russia18 = @"russia18";
NSString * const kGTLYouTubeContentRating_RussiaRating_Russia6 = @"russia6";
NSString * const kGTLYouTubeContentRating_RussiaRating_RussiaUnrated = @"russiaUnrated";

// GTLYouTubeContentRating - TvpgRating
NSString * const kGTLYouTubeContentRating_TvpgRating_Pg14      = @"pg14";
NSString * const kGTLYouTubeContentRating_TvpgRating_TvpgG     = @"tvpgG";
NSString * const kGTLYouTubeContentRating_TvpgRating_TvpgMa    = @"tvpgMa";
NSString * const kGTLYouTubeContentRating_TvpgRating_TvpgPg    = @"tvpgPg";
NSString * const kGTLYouTubeContentRating_TvpgRating_TvpgUnrated = @"tvpgUnrated";
NSString * const kGTLYouTubeContentRating_TvpgRating_TvpgY     = @"tvpgY";
NSString * const kGTLYouTubeContentRating_TvpgRating_TvpgY7    = @"tvpgY7";
NSString * const kGTLYouTubeContentRating_TvpgRating_TvpgY7Fv  = @"tvpgY7Fv";

// GTLYouTubeContentRating - YtRating
NSString * const kGTLYouTubeContentRating_YtRating_YtAgeRestricted = @"ytAgeRestricted";

// GTLYouTubeInvideoPosition - CornerPosition
NSString * const kGTLYouTubeInvideoPosition_CornerPosition_BottomLeft = @"bottomLeft";
NSString * const kGTLYouTubeInvideoPosition_CornerPosition_BottomRight = @"bottomRight";
NSString * const kGTLYouTubeInvideoPosition_CornerPosition_TopLeft = @"topLeft";
NSString * const kGTLYouTubeInvideoPosition_CornerPosition_TopRight = @"topRight";

// GTLYouTubeInvideoPosition - Type
NSString * const kGTLYouTubeInvideoPosition_Type_Corner = @"corner";

// GTLYouTubeInvideoTiming - Type
NSString * const kGTLYouTubeInvideoTiming_Type_OffsetFromEnd   = @"offsetFromEnd";
NSString * const kGTLYouTubeInvideoTiming_Type_OffsetFromStart = @"offsetFromStart";

// GTLYouTubeLiveBroadcastStatus - LifeCycleStatus
NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_Abandoned = @"abandoned";
NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_Complete = @"complete";
NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_CompleteStarting = @"completeStarting";
NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_Created = @"created";
NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_Live = @"live";
NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_LiveStarting = @"liveStarting";
NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_Ready = @"ready";
NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_Reclaimed = @"reclaimed";
NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_Revoked = @"revoked";
NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_Testing = @"testing";
NSString * const kGTLYouTubeLiveBroadcastStatus_LifeCycleStatus_TestStarting = @"testStarting";

// GTLYouTubeLiveBroadcastStatus - PrivacyStatus
NSString * const kGTLYouTubeLiveBroadcastStatus_PrivacyStatus_Private = @"private";
NSString * const kGTLYouTubeLiveBroadcastStatus_PrivacyStatus_Public = @"public";
NSString * const kGTLYouTubeLiveBroadcastStatus_PrivacyStatus_Unlisted = @"unlisted";

// GTLYouTubeLiveBroadcastStatus - RecordingStatus
NSString * const kGTLYouTubeLiveBroadcastStatus_RecordingStatus_NotRecording = @"notRecording";
NSString * const kGTLYouTubeLiveBroadcastStatus_RecordingStatus_Recorded = @"recorded";
NSString * const kGTLYouTubeLiveBroadcastStatus_RecordingStatus_Recording = @"recording";

// GTLYouTubeLiveStreamStatus - StreamStatus
NSString * const kGTLYouTubeLiveStreamStatus_StreamStatus_Active = @"active";
NSString * const kGTLYouTubeLiveStreamStatus_StreamStatus_Created = @"created";
NSString * const kGTLYouTubeLiveStreamStatus_StreamStatus_Error = @"error";
NSString * const kGTLYouTubeLiveStreamStatus_StreamStatus_Inactive = @"inactive";
NSString * const kGTLYouTubeLiveStreamStatus_StreamStatus_Ready = @"ready";

// GTLYouTubePlaylistItemStatus - PrivacyStatus
NSString * const kGTLYouTubePlaylistItemStatus_PrivacyStatus_Private = @"private";
NSString * const kGTLYouTubePlaylistItemStatus_PrivacyStatus_Public = @"public";
NSString * const kGTLYouTubePlaylistItemStatus_PrivacyStatus_Unlisted = @"unlisted";

// GTLYouTubePlaylistStatus - PrivacyStatus
NSString * const kGTLYouTubePlaylistStatus_PrivacyStatus_Private = @"private";
NSString * const kGTLYouTubePlaylistStatus_PrivacyStatus_Public = @"public";
NSString * const kGTLYouTubePlaylistStatus_PrivacyStatus_Unlisted = @"unlisted";

// GTLYouTubePromotedItemId - Type
NSString * const kGTLYouTubePromotedItemId_Type_RecentUpload = @"recentUpload";
NSString * const kGTLYouTubePromotedItemId_Type_Video        = @"video";
NSString * const kGTLYouTubePromotedItemId_Type_Website      = @"website";

// GTLYouTubeSearchResultSnippet - LiveBroadcastContent
NSString * const kGTLYouTubeSearchResultSnippet_LiveBroadcastContent_Live = @"live";
NSString * const kGTLYouTubeSearchResultSnippet_LiveBroadcastContent_None = @"none";
NSString * const kGTLYouTubeSearchResultSnippet_LiveBroadcastContent_Upcoming = @"upcoming";

// GTLYouTubeSubscriptionContentDetails - ActivityType
NSString * const kGTLYouTubeSubscriptionContentDetails_ActivityType_All = @"all";
NSString * const kGTLYouTubeSubscriptionContentDetails_ActivityType_Uploads = @"uploads";

// GTLYouTubeVideoAgeGating - VideoGameRating
NSString * const kGTLYouTubeVideoAgeGating_VideoGameRating_Anyone = @"anyone";
NSString * const kGTLYouTubeVideoAgeGating_VideoGameRating_M15Plus = @"m15Plus";
NSString * const kGTLYouTubeVideoAgeGating_VideoGameRating_M16Plus = @"m16Plus";
NSString * const kGTLYouTubeVideoAgeGating_VideoGameRating_M17Plus = @"m17Plus";

// GTLYouTubeVideoContentDetails - Caption
NSString * const kGTLYouTubeVideoContentDetails_Caption_False = @"false";
NSString * const kGTLYouTubeVideoContentDetails_Caption_True  = @"true";

// GTLYouTubeVideoContentDetails - Definition
NSString * const kGTLYouTubeVideoContentDetails_Definition_Hd = @"hd";
NSString * const kGTLYouTubeVideoContentDetails_Definition_Sd = @"sd";

// GTLYouTubeVideoConversionPing - Context
NSString * const kGTLYouTubeVideoConversionPing_Context_Comment = @"comment";
NSString * const kGTLYouTubeVideoConversionPing_Context_Dislike = @"dislike";
NSString * const kGTLYouTubeVideoConversionPing_Context_Like   = @"like";
NSString * const kGTLYouTubeVideoConversionPing_Context_Share  = @"share";

// GTLYouTubeVideoFileDetails - FileType
NSString * const kGTLYouTubeVideoFileDetails_FileType_Archive  = @"archive";
NSString * const kGTLYouTubeVideoFileDetails_FileType_Audio    = @"audio";
NSString * const kGTLYouTubeVideoFileDetails_FileType_Document = @"document";
NSString * const kGTLYouTubeVideoFileDetails_FileType_Image    = @"image";
NSString * const kGTLYouTubeVideoFileDetails_FileType_Other    = @"other";
NSString * const kGTLYouTubeVideoFileDetails_FileType_Project  = @"project";
NSString * const kGTLYouTubeVideoFileDetails_FileType_Video    = @"video";

// GTLYouTubeVideoFileDetailsVideoStream - Rotation
NSString * const kGTLYouTubeVideoFileDetailsVideoStream_Rotation_Clockwise = @"clockwise";
NSString * const kGTLYouTubeVideoFileDetailsVideoStream_Rotation_CounterClockwise = @"counterClockwise";
NSString * const kGTLYouTubeVideoFileDetailsVideoStream_Rotation_None = @"none";
NSString * const kGTLYouTubeVideoFileDetailsVideoStream_Rotation_Other = @"other";
NSString * const kGTLYouTubeVideoFileDetailsVideoStream_Rotation_UpsideDown = @"upsideDown";

// GTLYouTubeVideoProcessingDetails - ProcessingFailureReason
NSString * const kGTLYouTubeVideoProcessingDetails_ProcessingFailureReason_Other = @"other";
NSString * const kGTLYouTubeVideoProcessingDetails_ProcessingFailureReason_StreamingFailed = @"streamingFailed";
NSString * const kGTLYouTubeVideoProcessingDetails_ProcessingFailureReason_TranscodeFailed = @"transcodeFailed";
NSString * const kGTLYouTubeVideoProcessingDetails_ProcessingFailureReason_UploadFailed = @"uploadFailed";

// GTLYouTubeVideoProcessingDetails - ProcessingStatus
NSString * const kGTLYouTubeVideoProcessingDetails_ProcessingStatus_Failed = @"failed";
NSString * const kGTLYouTubeVideoProcessingDetails_ProcessingStatus_Processing = @"processing";
NSString * const kGTLYouTubeVideoProcessingDetails_ProcessingStatus_Succeeded = @"succeeded";
NSString * const kGTLYouTubeVideoProcessingDetails_ProcessingStatus_Terminated = @"terminated";

// GTLYouTubeVideoRating - Rating
NSString * const kGTLYouTubeVideoRating_Rating_Dislike     = @"dislike";
NSString * const kGTLYouTubeVideoRating_Rating_Like        = @"like";
NSString * const kGTLYouTubeVideoRating_Rating_None        = @"none";
NSString * const kGTLYouTubeVideoRating_Rating_Unspecified = @"unspecified";

// GTLYouTubeVideoSnippet - LiveBroadcastContent
NSString * const kGTLYouTubeVideoSnippet_LiveBroadcastContent_Live = @"live";
NSString * const kGTLYouTubeVideoSnippet_LiveBroadcastContent_None = @"none";
NSString * const kGTLYouTubeVideoSnippet_LiveBroadcastContent_Upcoming = @"upcoming";

// GTLYouTubeVideoStatus - FailureReason
NSString * const kGTLYouTubeVideoStatus_FailureReason_Codec    = @"codec";
NSString * const kGTLYouTubeVideoStatus_FailureReason_Conversion = @"conversion";
NSString * const kGTLYouTubeVideoStatus_FailureReason_EmptyFile = @"emptyFile";
NSString * const kGTLYouTubeVideoStatus_FailureReason_InvalidFile = @"invalidFile";
NSString * const kGTLYouTubeVideoStatus_FailureReason_TooSmall = @"tooSmall";
NSString * const kGTLYouTubeVideoStatus_FailureReason_UploadAborted = @"uploadAborted";

// GTLYouTubeVideoStatus - License
NSString * const kGTLYouTubeVideoStatus_License_CreativeCommon = @"creativeCommon";
NSString * const kGTLYouTubeVideoStatus_License_Youtube        = @"youtube";

// GTLYouTubeVideoStatus - PrivacyStatus
NSString * const kGTLYouTubeVideoStatus_PrivacyStatus_Private  = @"private";
NSString * const kGTLYouTubeVideoStatus_PrivacyStatus_Public   = @"public";
NSString * const kGTLYouTubeVideoStatus_PrivacyStatus_Unlisted = @"unlisted";

// GTLYouTubeVideoStatus - RejectionReason
NSString * const kGTLYouTubeVideoStatus_RejectionReason_Claim  = @"claim";
NSString * const kGTLYouTubeVideoStatus_RejectionReason_Copyright = @"copyright";
NSString * const kGTLYouTubeVideoStatus_RejectionReason_Duplicate = @"duplicate";
NSString * const kGTLYouTubeVideoStatus_RejectionReason_Inappropriate = @"inappropriate";
NSString * const kGTLYouTubeVideoStatus_RejectionReason_Length = @"length";
NSString * const kGTLYouTubeVideoStatus_RejectionReason_TermsOfUse = @"termsOfUse";
NSString * const kGTLYouTubeVideoStatus_RejectionReason_Trademark = @"trademark";
NSString * const kGTLYouTubeVideoStatus_RejectionReason_UploaderAccountClosed = @"uploaderAccountClosed";
NSString * const kGTLYouTubeVideoStatus_RejectionReason_UploaderAccountSuspended = @"uploaderAccountSuspended";

// GTLYouTubeVideoStatus - UploadStatus
NSString * const kGTLYouTubeVideoStatus_UploadStatus_Deleted   = @"deleted";
NSString * const kGTLYouTubeVideoStatus_UploadStatus_Failed    = @"failed";
NSString * const kGTLYouTubeVideoStatus_UploadStatus_Processed = @"processed";
NSString * const kGTLYouTubeVideoStatus_UploadStatus_Rejected  = @"rejected";
NSString * const kGTLYouTubeVideoStatus_UploadStatus_Uploaded  = @"uploaded";

// GTLYouTubeVideoSuggestions - EditorSuggestions
NSString * const kGTLYouTubeVideoSuggestions_EditorSuggestions_AudioQuietAudioSwap = @"audioQuietAudioSwap";
NSString * const kGTLYouTubeVideoSuggestions_EditorSuggestions_VideoAutoLevels = @"videoAutoLevels";
NSString * const kGTLYouTubeVideoSuggestions_EditorSuggestions_VideoCrop = @"videoCrop";
NSString * const kGTLYouTubeVideoSuggestions_EditorSuggestions_VideoStabilize = @"videoStabilize";

// GTLYouTubeVideoSuggestions - ProcessingErrors
NSString * const kGTLYouTubeVideoSuggestions_ProcessingErrors_ArchiveFile = @"archiveFile";
NSString * const kGTLYouTubeVideoSuggestions_ProcessingErrors_AudioFile = @"audioFile";
NSString * const kGTLYouTubeVideoSuggestions_ProcessingErrors_DocFile = @"docFile";
NSString * const kGTLYouTubeVideoSuggestions_ProcessingErrors_ImageFile = @"imageFile";
NSString * const kGTLYouTubeVideoSuggestions_ProcessingErrors_NotAVideoFile = @"notAVideoFile";
NSString * const kGTLYouTubeVideoSuggestions_ProcessingErrors_ProjectFile = @"projectFile";

// GTLYouTubeVideoSuggestions - ProcessingHints
NSString * const kGTLYouTubeVideoSuggestions_ProcessingHints_NonStreamableMov = @"nonStreamableMov";
NSString * const kGTLYouTubeVideoSuggestions_ProcessingHints_SendBestQualityVideo = @"sendBestQualityVideo";

// GTLYouTubeVideoSuggestions - ProcessingWarnings
NSString * const kGTLYouTubeVideoSuggestions_ProcessingWarnings_HasEditlist = @"hasEditlist";
NSString * const kGTLYouTubeVideoSuggestions_ProcessingWarnings_InconsistentResolution = @"inconsistentResolution";
NSString * const kGTLYouTubeVideoSuggestions_ProcessingWarnings_ProblematicAudioCodec = @"problematicAudioCodec";
NSString * const kGTLYouTubeVideoSuggestions_ProcessingWarnings_ProblematicVideoCodec = @"problematicVideoCodec";
NSString * const kGTLYouTubeVideoSuggestions_ProcessingWarnings_UnknownAudioCodec = @"unknownAudioCodec";
NSString * const kGTLYouTubeVideoSuggestions_ProcessingWarnings_UnknownContainer = @"unknownContainer";
NSString * const kGTLYouTubeVideoSuggestions_ProcessingWarnings_UnknownVideoCodec = @"unknownVideoCodec";
