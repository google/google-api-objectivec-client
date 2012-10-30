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
//  GTLYouTubePlaylistItemSnippet.h
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
//   GTLYouTubePlaylistItemSnippet (0 custom class methods, 8 custom properties)
//   GTLYouTubePlaylistItemSnippetThumbnails (0 custom class methods, 0 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubePlaylistItemSnippetThumbnails;
@class GTLYouTubeResourceId;
@class GTLYouTubeThumbnail;

// ----------------------------------------------------------------------------
//
//   GTLYouTubePlaylistItemSnippet
//

// Basic details about an item included in a playlist, including title,
// description, thumbnails, playlist the item is part of and position of the
// item inside the playlist.

@interface GTLYouTubePlaylistItemSnippet : GTLObject

// Channel publishing the playlist item.
@property (copy) NSString *channelId;

// Description of the playlist item.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// The playlist the item is part of.
@property (copy) NSString *playlistId;

// The position of the item within the playlist.
@property (retain) NSNumber *position;  // unsignedIntValue

// Date and time the playlist item was published at.
@property (retain) GTLDateTime *publishedAt;

// The ID of the resource referenced by the playlist item.
@property (retain) GTLYouTubeResourceId *resourceId;

// Playlist item thumbnails.
@property (retain) GTLYouTubePlaylistItemSnippetThumbnails *thumbnails;

// Title of the playlist item.
@property (copy) NSString *title;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubePlaylistItemSnippetThumbnails
//

@interface GTLYouTubePlaylistItemSnippetThumbnails : GTLObject
// This object is documented as having more properties that are
// GTLYouTubeThumbnail. Use -additionalJSONKeys and -additionalPropertyForName:
// to get the list of properties and then fetch them; or -additionalProperties
// to fetch them all at once.
@end
