/* Copyright (c) 2014 Google Inc.
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
//  GTLMirrorAccount.h
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
//   GTLMirrorAccount (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLMirrorAuthToken;
@class GTLMirrorUserData;

// ----------------------------------------------------------------------------
//
//   GTLMirrorAccount
//

// Represents an account passed into the Account Manager on Glass.

@interface GTLMirrorAccount : GTLObject
@property (retain) NSArray *authTokens;  // of GTLMirrorAuthToken
@property (retain) NSArray *features;  // of NSString
@property (copy) NSString *password;

// Remapped to 'userDataProperty' to avoid GTLObject's 'userData'.
@property (retain) NSArray *userDataProperty;  // of GTLMirrorUserData

@end
