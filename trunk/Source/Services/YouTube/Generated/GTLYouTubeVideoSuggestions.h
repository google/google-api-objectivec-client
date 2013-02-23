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
//  GTLYouTubeVideoSuggestions.h
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
//   GTLYouTubeVideoSuggestions (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeVideoSuggestionsTagSuggestion;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeVideoSuggestions
//

// Specifies suggestions on how to improve video content, including encoding
// hints, tag suggestions, and editor suggestions.

@interface GTLYouTubeVideoSuggestions : GTLObject

// Editor operations that could improve video quality.
@property (retain) NSArray *editorSuggestions;  // of NSString

// Errors encountered during video processing.
@property (retain) NSArray *processingErrors;  // of NSString

// Hints about how to improve video processing.
@property (retain) NSArray *processingHints;  // of NSString

// Warnings produced by the video processing engine.
@property (retain) NSArray *processingWarnings;  // of NSString

// Tags that could be added to aid video discovery.
@property (retain) NSArray *tagSuggestions;  // of GTLYouTubeVideoSuggestionsTagSuggestion

@end
