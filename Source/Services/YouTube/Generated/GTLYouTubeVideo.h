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
//  GTLYouTubeVideo.h
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
//   GTLYouTubeVideo (0 custom class methods, 9 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeVideoContentDetails;
@class GTLYouTubeVideoPlayer;
@class GTLYouTubeVideoSnippet;
@class GTLYouTubeVideoStatistics;
@class GTLYouTubeVideoStatus;
@class GTLYouTubeVideoTopicDetails;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeVideo
//

// A video resource represents a single YouTube video.

@interface GTLYouTubeVideo : GTLObject

// Information about the video content, media file.
@property (retain) GTLYouTubeVideoContentDetails *contentDetails;

// The eTag of the video.
@property (copy) NSString *ETag;

// The unique id of the video.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The type of this API resource.
@property (copy) NSString *kind;

// Information used to play the video.
@property (retain) GTLYouTubeVideoPlayer *player;

// Basic details about the video: title, description, thumbnails.
@property (retain) GTLYouTubeVideoSnippet *snippet;

// Statistics about the video: number of views, ratings.
@property (retain) GTLYouTubeVideoStatistics *statistics;

// Status of the video upload, privacy status.
@property (retain) GTLYouTubeVideoStatus *status;

// Topics related to the video
@property (retain) GTLYouTubeVideoTopicDetails *topicDetails;

@end
