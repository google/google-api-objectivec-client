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
//  GTLYouTubeVideoFileDetails.h
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
//   GTLYouTubeVideoFileDetails (0 custom class methods, 10 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeGeoPoint;
@class GTLYouTubeVideoFileDetailsAudioStream;
@class GTLYouTubeVideoFileDetailsVideoStream;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeVideoFileDetails
//

// Describes original video file properties, including technical details about
// audio and video streams, but also metadata information like content length,
// digitization time, or geotagging information.

@interface GTLYouTubeVideoFileDetails : GTLObject

// Audio streams.
@property (retain) NSArray *audioStreams;  // of GTLYouTubeVideoFileDetailsAudioStream

// Combined audio and video bitrate, in bits per second.
@property (retain) NSNumber *bitrateBps;  // unsignedLongLongValue

// Container format used.
@property (copy) NSString *container;

// Date and time when the video file was created, in ISO 8601 format. Currently
// the only ISO 8601 formats produced are: - Date only: YYYY-MM-DD - Naive time:
// YYYY-MM-DDTHH:MM:SS - Time with timezone: YYYY-MM-DDTHH:MM:SS+HH:MM
@property (copy) NSString *creationTime;

// Video duration in milliseconds.
@property (retain) NSNumber *durationMs;  // unsignedLongLongValue

// File name.
@property (copy) NSString *fileName;

// File size.
@property (retain) NSNumber *fileSize;  // unsignedLongLongValue

// File type.
@property (copy) NSString *fileType;

// Location of the place where the video was recorded.
@property (retain) GTLYouTubeGeoPoint *recordingLocation;

// Video streams.
@property (retain) NSArray *videoStreams;  // of GTLYouTubeVideoFileDetailsVideoStream

@end
