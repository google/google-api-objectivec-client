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

// An indication of whether a broadcast slate is enabled for the broadcast. Set
// this property to true to display the slate. Update the property value to
// false to remove the slate. You can insert or remove the broadcast slate at
// any time during an event.
@property (retain) NSNumber *enableSlates;  // boolValue

// A map of slates that are displayed for the broadcast in different regions.
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

// The URL of the slate's background image. This value can be set or updated if
// enableSlates is set to true. The image should have a 16x9 aspect ratio.
@property (copy) NSString *backgroundUrl;

// A multiline message that the slate displays. This value can be set or updated
// if enableSlates is set to true. You can specify up to three lines of text.
@property (retain) NSArray *textLines;  // of NSString

@end
