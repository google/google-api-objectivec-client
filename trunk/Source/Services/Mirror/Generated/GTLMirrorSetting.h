/* Copyright (c) 2015 Google Inc.
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
//  GTLMirrorSetting.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Mirror API (mirror/v1)
// Description:
//   API for interacting with Glass users via the timeline.
// Documentation:
//   https://developers.google.com/glass
// Classes:
//   GTLMirrorSetting (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLMirrorSetting
//

// A setting for Glass.

@interface GTLMirrorSetting : GTLObject

// The setting's ID. The following IDs are valid:
// - locale - The key to the user’s language/locale (BCP 47 identifier) that
// Glassware should use to render localized content.
// - timezone - The key to the user’s current time zone region as defined in the
// tz database. Example: America/Los_Angeles.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The type of resource. This is always mirror#setting.
@property (nonatomic, copy) NSString *kind;

// The setting value, as a string.
@property (nonatomic, copy) NSString *value;

@end
