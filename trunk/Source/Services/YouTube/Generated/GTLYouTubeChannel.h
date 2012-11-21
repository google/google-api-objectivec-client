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
//  GTLYouTubeChannel.h
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
//   GTLYouTubeChannel (0 custom class methods, 7 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeChannelContentDetails;
@class GTLYouTubeChannelSnippet;
@class GTLYouTubeChannelStatistics;
@class GTLYouTubeChannelTopicDetails;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeChannel
//

// A channel resource contains information about a YouTube channel.

@interface GTLYouTubeChannel : GTLObject

// The contentDetails object encapsulates information about the channel's
// content.
@property (retain) GTLYouTubeChannelContentDetails *contentDetails;

// The ETag for the channel resource.
@property (copy) NSString *ETag;

// The ID that YouTube uses to uniquely identify the channel.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The type of the API resource. For channel resources, the value will be
// youtube#channel.
@property (copy) NSString *kind;

// The snippet object contains basic details about the channel, such as its
// title, description, and thumbnail images.
@property (retain) GTLYouTubeChannelSnippet *snippet;

// The statistics object encapsulates statistics for the channel.
@property (retain) GTLYouTubeChannelStatistics *statistics;

// The topicDetails object encapsulates information about Freebase topics
// associated with the channel.
@property (retain) GTLYouTubeChannelTopicDetails *topicDetails;

@end
