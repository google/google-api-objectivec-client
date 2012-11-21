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

// A video resource represents a YouTube video.

@interface GTLYouTubeVideo : GTLObject

// The contentDetails object contains information about the video content,
// including the length of the video and its aspect ratio.
@property (retain) GTLYouTubeVideoContentDetails *contentDetails;

// The ETag of the video resource.
@property (copy) NSString *ETag;

// The ID that YouTube uses to uniquely identify the video.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The type of the API resource. For video resources, the value will be
// youtube#video.
@property (copy) NSString *kind;

// The player object contains information that you would use to play the video
// in an embedded player.
@property (retain) GTLYouTubeVideoPlayer *player;

// The snippet object contains basic details about the video, such as its title,
// description, and category.
@property (retain) GTLYouTubeVideoSnippet *snippet;

// The statistics object contains statistics about the video.
@property (retain) GTLYouTubeVideoStatistics *statistics;

// The status object contains information about the video's uploading,
// processing, and privacy statuses.
@property (retain) GTLYouTubeVideoStatus *status;

// The topicDetails object encapsulates information about Freebase topics
// associated with the video.
@property (retain) GTLYouTubeVideoTopicDetails *topicDetails;

@end
