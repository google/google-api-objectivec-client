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
//  GTLYouTubeActivity.h
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
//   GTLYouTubeActivity (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeActivityContentDetails;
@class GTLYouTubeActivitySnippet;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivity
//

// An activity resource contains information about an action that a channel has
// taken on YouTube.

@interface GTLYouTubeActivity : GTLObject

// Type specific information about the activity.
@property (retain) GTLYouTubeActivityContentDetails *contentDetails;

// The eTag of the activity.
@property (copy) NSString *ETag;

// The unique ID of the activity.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The type of this API response.
@property (copy) NSString *kind;

// Basic details about the activity: title, description, thumbnails.
@property (retain) GTLYouTubeActivitySnippet *snippet;

@end
