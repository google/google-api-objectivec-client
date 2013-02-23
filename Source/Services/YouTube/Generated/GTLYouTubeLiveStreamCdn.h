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
//  GTLYouTubeLiveStreamCdn.h
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
//   GTLYouTubeLiveStreamCdn (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeLiveStreamCdnIngestionInfo;
@class GTLYouTubeLiveStreamCdnMulticastIngestionInfo;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeLiveStreamCdn
//

// Brief description of the live stream cdn settings.

@interface GTLYouTubeLiveStreamCdn : GTLObject

// The format of the inbound data. Allowed values: 240p, 360p, 480p, 720p,
// 1080p, webm_360p, multicast_qcif, multicast_240p, multicast_360p,
// multicast_480p, multicast_720p, multicast_1080p.
@property (copy) NSString *format;

// Encapsulates information for ingesting an RTMP or an HTTP stream.
@property (retain) GTLYouTubeLiveStreamCdnIngestionInfo *ingestionInfo;

// The live stream ingestion type. Allowed values: rtmp, http, multicast.
@property (copy) NSString *ingestionType;

// Encapsulates information for ingesting a multicast stream.
@property (retain) GTLYouTubeLiveStreamCdnMulticastIngestionInfo *multicastIngestionInfo;

@end
