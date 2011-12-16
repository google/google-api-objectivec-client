/* Copyright (c) 2011 Google Inc.
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
//  GTLBooksConcurrentAccessRestriction.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Books API (books/v1)
// Description:
//   Lets you search for books and manage your Google Books library.
// Documentation:
//   https://code.google.com/apis/books/docs/v1/getting_started.html
// Classes:
//   GTLBooksConcurrentAccessRestriction (0 custom class methods, 11 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLBooksConcurrentAccessRestriction
//

@interface GTLBooksConcurrentAccessRestriction : GTLObject

// Whether access is granted for this (user, device, volume).
@property (retain) NSNumber *deviceAllowed;  // boolValue

// Resource type.
@property (copy) NSString *kind;

// The maximum number of concurrent access licenses for this volume.
@property (retain) NSNumber *maxConcurrentDevices;  // intValue

// Error/warning message.
@property (copy) NSString *message;

// Client nonce for verification. Download access and client-validation only.
@property (copy) NSString *nonce;

// Error/warning reason code.
@property (copy) NSString *reasonCode;

// Whether this volume has any concurrent access restrictions.
@property (retain) NSNumber *restricted;  // boolValue

// Response signature.
@property (copy) NSString *signature;

// Client app identifier for verification. Download access and client-validation
// only.
@property (copy) NSString *source;

// Time in seconds for license auto-expiration.
@property (retain) NSNumber *timeWindowSeconds;  // intValue

// Identifies the volume for which this entry applies.
@property (copy) NSString *volumeId;

@end
