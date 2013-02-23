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
//  GTLYouTubeLiveStream.h
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
//   GTLYouTubeLiveStream (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeLiveStreamCdn;
@class GTLYouTubeLiveStreamSnippet;
@class GTLYouTubeLiveStreamStatus;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeLiveStream
//

// A live stream describes a live ingestion point.

@interface GTLYouTubeLiveStream : GTLObject

// Cdn settings of the live stream.
@property (retain) GTLYouTubeLiveStreamCdn *cdn;

// The eTag of the stream.
@property (copy) NSString *ETag;

// The unique id of the stream.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The type of this API resource.
@property (copy) NSString *kind;

// Basic details about the live stream.
@property (retain) GTLYouTubeLiveStreamSnippet *snippet;

// Status of the live stream.
@property (retain) GTLYouTubeLiveStreamStatus *status;

@end
