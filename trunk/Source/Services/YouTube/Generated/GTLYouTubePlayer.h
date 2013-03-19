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
//  GTLYouTubePlayer.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   YouTube Data API (youtube/v3)
// Description:
//   Programmatic access to YouTube features.
// Documentation:
//   https://developers.google.com/youtube/v3
// Classes:
//   GTLYouTubePlayer (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeInvideoFeature;
@class GTLYouTubePlayerAdsPlaylist;
@class GTLYouTubePlayerVideoUrls;
@class GTLYouTubeResourceId;

// ----------------------------------------------------------------------------
//
//   GTLYouTubePlayer
//

// A player resource represents all the information needed to play a video.

@interface GTLYouTubePlayer : GTLObject

// The playlist of video ads to show for this playback.
@property (retain) GTLYouTubePlayerAdsPlaylist *adsPlaylist;

// The ETag for the player resource.
@property (copy) NSString *ETag;

// The ID that YouTube uses to uniquely identify the resource.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) GTLYouTubeResourceId *identifier;

// The invideo features for the video.
@property (retain) GTLYouTubeInvideoFeature *invideoFeature;

// The type of the API resource.
@property (copy) NSString *kind;

// The videoUrls object either contains restriction information or URLs giving
// access to the content.
@property (retain) GTLYouTubePlayerVideoUrls *videoUrls;

@end
