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
//  GTLYouTubeVideoCategoryListResponse.h
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
//   GTLYouTubeVideoCategoryListResponse (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeVideoCategory;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeVideoCategoryListResponse
//

// A paginated list of video categories returned as the response to a
// youtube.videoCategory.list call.

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLYouTubeVideoCategoryListResponse : GTLCollectionObject

// The ETag of the response.
@property (copy) NSString *ETag;

// A list of video categories that can be associated with YouTube videos. In
// this map, the video category ID is the map key, and its value is the
// corresponding videoCategory resource.
@property (retain) NSArray *items;  // of GTLYouTubeVideoCategory

// The type of the API response. For this operation, the value will be
// youtube#videoCategoryListResponse.
@property (copy) NSString *kind;

@end
