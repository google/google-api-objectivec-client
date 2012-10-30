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
//  GTLYouTubeSearchResult.h
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
//   GTLYouTubeSearchResult (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeResourceId;
@class GTLYouTubeSearchResultSnippet;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeSearchResult
//

// A search result contains information about a YouTube video, channel, or
// playlist that matches the search parameters specified in an API request.

@interface GTLYouTubeSearchResult : GTLObject

// The eTag of the search result.
@property (copy) NSString *ETag;

// The id of the resource.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) GTLYouTubeResourceId *identifier;

// The type of this API resource.
@property (copy) NSString *kind;

// Basic details about the search result: title, description, author.
@property (retain) GTLYouTubeSearchResultSnippet *snippet;

@end
