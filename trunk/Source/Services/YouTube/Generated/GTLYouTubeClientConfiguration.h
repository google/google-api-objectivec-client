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
//  GTLYouTubeClientConfiguration.h
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
//   GTLYouTubeClientConfiguration (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeClientConfigurationSettings;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeClientConfiguration
//

// Remote settings that apply to a first-party client.

@interface GTLYouTubeClientConfiguration : GTLObject

// Etag of this resource.
@property (copy) NSString *ETag;

// The id uniquely identifies the client configuration.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The kind, fixed to "youtube#clientConfiguration".
@property (copy) NSString *kind;

// The settings object identifies the properties and values that are applicable
// to the client.
@property (retain) GTLYouTubeClientConfigurationSettings *settings;

@end
