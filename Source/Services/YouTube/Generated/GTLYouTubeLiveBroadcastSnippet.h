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
//  GTLYouTubeLiveBroadcastSnippet.h
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
//   GTLYouTubeLiveBroadcastSnippet (0 custom class methods, 9 custom properties)
//   GTLYouTubeLiveBroadcastSnippetThumbnails (0 custom class methods, 0 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeLiveBroadcastSnippetThumbnails;
@class GTLYouTubeThumbnail;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeLiveBroadcastSnippet
//

// Basic details about a live broadcast, including title, description and
// thumbnails.

@interface GTLYouTubeLiveBroadcastSnippet : GTLObject

// Date and time the broadcast is actual to end. The value is specified in ISO
// 8601 (YYYY-MM-DDThh:mm:ss.sZ) format.
@property (retain) GTLDateTime *actualEndTime;

// Date and time the broadcast is actual to start. The value is specified in ISO
// 8601 (YYYY-MM-DDThh:mm:ss.sZ) format.
@property (retain) GTLDateTime *actualStartTime;

// Channel publishing the broadcast.
@property (copy) NSString *channelId;

// Description of the broadcast.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Date and time the broadcast was published at. The value is specified in ISO
// 8601 (YYYY-MM-DDThh:mm:ss.sZ) format.
@property (retain) GTLDateTime *publishedAt;

// Date and time the broadcast is scheduled to end. The value is specified in
// ISO 8601 (YYYY-MM-DDThh:mm:ss.sZ) format.
@property (retain) GTLDateTime *scheduledEndTime;

// Date and time the broadcast is scheduled to start. The value is specified in
// ISO 8601 (YYYY-MM-DDThh:mm:ss.sZ) format.
@property (retain) GTLDateTime *scheduledStartTime;

// Video thumbnails.
@property (retain) GTLYouTubeLiveBroadcastSnippetThumbnails *thumbnails;

// Title of the broadcast.
@property (copy) NSString *title;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeLiveBroadcastSnippetThumbnails
//

@interface GTLYouTubeLiveBroadcastSnippetThumbnails : GTLObject
// This object is documented as having more properties that are
// GTLYouTubeThumbnail. Use -additionalJSONKeys and -additionalPropertyForName:
// to get the list of properties and then fetch them; or -additionalProperties
// to fetch them all at once.
@end
