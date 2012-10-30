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
//  GTLYouTubePlaylistSnippet.m
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
//   GTLYouTubePlaylistSnippet (0 custom class methods, 5 custom properties)
//   GTLYouTubePlaylistSnippetThumbnails (0 custom class methods, 0 custom properties)

#import "GTLYouTubePlaylistSnippet.h"

#import "GTLYouTubeThumbnail.h"

// ----------------------------------------------------------------------------
//
//   GTLYouTubePlaylistSnippet
//

@implementation GTLYouTubePlaylistSnippet
@dynamic channelId, descriptionProperty, publishedAt, thumbnails, title;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"description"
                                forKey:@"descriptionProperty"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubePlaylistSnippetThumbnails
//

@implementation GTLYouTubePlaylistSnippetThumbnails

+ (Class)classForAdditionalProperties {
  return [GTLYouTubeThumbnail class];
}

@end
