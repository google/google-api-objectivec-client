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
//  GTLYouTubeLiveBroadcastContentDetails.h
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
//   GTLYouTubeLiveBroadcastContentDetails (0 custom class methods, 7 custom properties)
//   GTLYouTubeLiveBroadcastContentDetailsMonitorStream (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeLiveBroadcastContentDetailsMonitorStream;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeLiveBroadcastContentDetails
//

// Slate settings of a broadcast.

@interface GTLYouTubeLiveBroadcastContentDetails : GTLObject

// The id of the stream bound to the broadcast.
@property (copy) NSString *boundStreamId;

// Whether the live event will be archived or not.
@property (retain) NSNumber *enableArchive;  // boolValue

// Whether to enable or disable content encryption.
@property (retain) NSNumber *enableContentEncryption;  // boolValue

// Whether the dvr (digital video recording) is enabled or not.
@property (retain) NSNumber *enableDvr;  // boolValue

// Whether to allow the broadcast to be played in an embedded player.
@property (retain) NSNumber *enableEmbed;  // boolValue

// Information about the monitor stream which helps the broadcaster to review
// the event content before shown to the public.
@property (retain) GTLYouTubeLiveBroadcastContentDetailsMonitorStream *monitorStream;

// Automatically start with a slate cuepoint.
@property (retain) NSNumber *startWithSlateCuepoint;  // boolValue

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeLiveBroadcastContentDetailsMonitorStream
//

@interface GTLYouTubeLiveBroadcastContentDetailsMonitorStream : GTLObject

// If enableMonitorStream is true, the public broadcast will be delayed by this
// value.
@property (retain) NSNumber *broadcastStreamDelayMs;  // unsignedIntValue

// The html code of the embedded player for the monitor stream.
@property (copy) NSString *embedHtml;

// Whether to enable the monitor stream for the broadcast.
@property (retain) NSNumber *enableMonitorStream;  // boolValue

@end
