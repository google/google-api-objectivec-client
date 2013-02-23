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
//  GTLYouTubeLiveBroadcastSlateSettings.h
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
//   GTLYouTubeLiveBroadcastSlateSettings (0 custom class methods, 2 custom properties)
//   GTLYouTubeLiveBroadcastSlateSettingsSlates (0 custom class methods, 0 custom properties)
//   GTLYouTubeLiveBroadcastSlateSettingsSlatesSlate (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeLiveBroadcastSlateSettingsSlates;
@class GTLYouTubeLiveBroadcastSlateSettingsSlatesSlate;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeLiveBroadcastSlateSettings
//

// Slate settings of a broadcast.

@interface GTLYouTubeLiveBroadcastSlateSettings : GTLObject

// Whether slate is enabled or not.
@property (retain) NSNumber *enableSlates;  // boolValue

// Broadcast slates.
@property (retain) GTLYouTubeLiveBroadcastSlateSettingsSlates *slates;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeLiveBroadcastSlateSettingsSlates
//

@interface GTLYouTubeLiveBroadcastSlateSettingsSlates : GTLObject
// This object is documented as having more properties that are
// GTLYouTubeLiveBroadcastSlateSettingsSlatesSlate. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeLiveBroadcastSlateSettingsSlatesSlate
//

@interface GTLYouTubeLiveBroadcastSlateSettingsSlatesSlate : GTLObject

// Url of the background image.
@property (copy) NSString *backgroundUrl;

// Multi-line message showing in the slate.
@property (retain) NSArray *textLines;  // of NSString

@end
