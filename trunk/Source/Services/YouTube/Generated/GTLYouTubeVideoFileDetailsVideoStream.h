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
//  GTLYouTubeVideoFileDetailsVideoStream.h
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
//   GTLYouTubeVideoFileDetailsVideoStream (0 custom class methods, 8 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLYouTubeVideoFileDetailsVideoStream
//

// Information about a video stream.

@interface GTLYouTubeVideoFileDetailsVideoStream : GTLObject

// Display aspect ratio, which might differ from width_pixels / height_pixels.
@property (retain) NSNumber *aspectRatio;  // doubleValue

// Video stream bitrate, in bits per second.
@property (retain) NSNumber *bitrateBps;  // unsignedLongLongValue

// Video codec used.
@property (copy) NSString *codec;

// Video frame rate, in frames per second.
@property (retain) NSNumber *frameRateFps;  // doubleValue

// Video height in pixels.
@property (retain) NSNumber *heightPixels;  // unsignedIntValue

// Rotation that is necessary to display the video properly.
@property (copy) NSString *rotation;

// Video vendor identifier, typically a four-letter vendor code.
@property (copy) NSString *vendor;

// Video width in pixels.
@property (retain) NSNumber *widthPixels;  // unsignedIntValue

@end
