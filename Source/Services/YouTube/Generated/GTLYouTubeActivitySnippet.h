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
//  GTLYouTubeActivitySnippet.h
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
//   GTLYouTubeActivitySnippet (0 custom class methods, 7 custom properties)
//   GTLYouTubeActivitySnippetThumbnails (0 custom class methods, 0 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeActivitySnippetThumbnails;
@class GTLYouTubeThumbnail;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivitySnippet
//

// Basic details about an activity, including title, description, thumbnails,
// activity type and group.

@interface GTLYouTubeActivitySnippet : GTLObject

// Channel publishing the activity.
@property (copy) NSString *channelId;

// Description of the activity.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Id of the group that this activity is part of.
@property (copy) NSString *groupId;

// Date and time the activity was published at.
@property (retain) GTLDateTime *publishedAt;

// Activity thumbnails.
@property (retain) GTLYouTubeActivitySnippetThumbnails *thumbnails;

// Title of the activity.
@property (copy) NSString *title;

// Type of the activity.
@property (copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivitySnippetThumbnails
//

@interface GTLYouTubeActivitySnippetThumbnails : GTLObject
// This object is documented as having more properties that are
// GTLYouTubeThumbnail. Use -additionalJSONKeys and -additionalPropertyForName:
// to get the list of properties and then fetch them; or -additionalProperties
// to fetch them all at once.
@end
