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
//  GTLYouTubeSearchResultSnippet.h
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
//   GTLYouTubeSearchResultSnippet (0 custom class methods, 5 custom properties)
//   GTLYouTubeSearchResultSnippetThumbnails (0 custom class methods, 0 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeSearchResultSnippetThumbnails;
@class GTLYouTubeThumbnail;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeSearchResultSnippet
//

// Basic details about a search result, including title, description and
// thumbnails of the item referenced by the search result.

@interface GTLYouTubeSearchResultSnippet : GTLObject

// The value that YouTube uses to uniquely identify the channel that published
// the resource that the search result identifies.
@property (copy) NSString *channelId;

// A description of the search result.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// The creation date and time of the resource that the search result identifies.
// The value is specified in ISO 8601 (YYYY-MM-DDThh:mm:ss.sZ) format.
@property (retain) GTLDateTime *publishedAt;

// A map of thumbnail images associated with the search result. For each object
// in the map, the key is the name of the thumbnail image, and the value is an
// object that contains other information about the thumbnail.
@property (retain) GTLYouTubeSearchResultSnippetThumbnails *thumbnails;

// The title to display for the search result.
@property (copy) NSString *title;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeSearchResultSnippetThumbnails
//

@interface GTLYouTubeSearchResultSnippetThumbnails : GTLObject
// This object is documented as having more properties that are
// GTLYouTubeThumbnail. Use -additionalJSONKeys and -additionalPropertyForName:
// to get the list of properties and then fetch them; or -additionalProperties
// to fetch them all at once.
@end
