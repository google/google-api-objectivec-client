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
//  GTLYouTubeFeaturedChannel.h
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
//   GTLYouTubeFeaturedChannel (0 custom class methods, 7 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeChannelSnippet;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeFeaturedChannel
//

@interface GTLYouTubeFeaturedChannel : GTLObject
@property (copy) NSString *channelId;
@property (retain) GTLYouTubeChannelSnippet *channelSnippet;
@property (retain) NSNumber *endTimeMs;  // longLongValue
@property (copy) NSString *featureId;
@property (copy) NSString *imageUrl;
@property (retain) NSNumber *startTimeMs;  // longLongValue
@property (retain) NSNumber *subscriberCount;  // unsignedLongLongValue
@end
