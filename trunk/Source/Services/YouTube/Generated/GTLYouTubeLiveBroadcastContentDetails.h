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

// This value uniquely identifies the live stream bound to the broadcast.
@property (copy) NSString *boundStreamId;

// This setting indicates whether the live event should be archived so that
// YouTube viewers can watch it at a later date. The default value for this
// property is true.
// Important: You must also set the enableDvr property's value to true if you
// want the playback to be available immediately after the broadcast ends. If
// you set this property's value to true but do not also set the enableDvr
// property to true, there may be a delay of around one day before the archived
// video will be available for playback.
@property (retain) NSNumber *enableArchive;  // boolValue

// This setting indicates whether YouTube should enable content encryption for
// the broadcast.
@property (retain) NSNumber *enableContentEncryption;  // boolValue

// This setting determines whether viewers can access DVR controls while
// watching the video. DVR controls enable the viewer to control the video
// playback experience by pausing, rewinding, or fast forwarding content. The
// default value for this property is true.
// Important: You must set the value to true and also set the enableArchive
// property's value to true if you want to make playback available immediately
// after the broadcast ends.
@property (retain) NSNumber *enableDvr;  // boolValue

// This setting indicates whether the broadcast video can be played in an
// embedded player. If you choose to archive the video (using the enableArchive
// property), this setting will also apply to the archived video.
@property (retain) NSNumber *enableEmbed;  // boolValue

// The monitorStream object contains information about the monitor stream, which
// the broadcaster can use to review the event content before the broadcast
// stream is shown publicly.
@property (retain) GTLYouTubeLiveBroadcastContentDetailsMonitorStream *monitorStream;

// This setting indicates whether the broadcast should automatically begin with
// an in-stream slate when you update the broadcast's status to live. After
// updating the status, you then need to send a liveCuepoints.insert request
// that sets the cuepoint's eventState to end to remove the in-stream slate and
// make your broadcast stream visible to viewers.
@property (retain) NSNumber *startWithSlateCuepoint;  // boolValue

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeLiveBroadcastContentDetailsMonitorStream
//

@interface GTLYouTubeLiveBroadcastContentDetailsMonitorStream : GTLObject

// If you have set the enableMonitorStream property to true, then this property
// determines the length of the live broadcast delay.
@property (retain) NSNumber *broadcastStreamDelayMs;  // unsignedIntValue

// HTML code that embeds a player that plays the monitor stream.
@property (copy) NSString *embedHtml;

// This value determines whether the monitor stream is enabled for the
// broadcast. If the monitor stream is enabled, then YouTube will broadcast the
// event content on a special stream intended only for the broadcaster's
// consumption. The broadcaster can use the stream to review the event content
// and also to identify the optimal times to insert cuepoints.
// You need to set this value to true if you intend to have a broadcast delay
// for your event.
// Note: This property cannot be updated once the broadcast is in the testing or
// live state.
@property (retain) NSNumber *enableMonitorStream;  // boolValue

@end
