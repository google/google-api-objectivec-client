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
//  GTLBooksDownloadAccessRestriction.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Books API (books/v1)
// Description:
//   Lets you search for books and manage your Google Books library.
// Documentation:
//   https://developers.google.com/books/docs/v1/getting_started
// Classes:
//   GTLBooksDownloadAccessRestriction (0 custom class methods, 12 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLBooksDownloadAccessRestriction
//

@interface GTLBooksDownloadAccessRestriction : GTLObject

// If restricted, whether access is granted for this (user, device, volume).
@property (retain) NSNumber *deviceAllowed;  // boolValue

// If restricted, the number of content download licenses already acquired
// (including the requesting client, if licensed).
@property (retain) NSNumber *downloadsAcquired;  // intValue

// If deviceAllowed, whether access was just acquired with this request.
@property (retain) NSNumber *justAcquired;  // boolValue

// Resource type.
@property (copy) NSString *kind;

// If restricted, the maximum number of content download licenses for this
// volume.
@property (retain) NSNumber *maxDownloadDevices;  // intValue

// Error/warning message.
@property (copy) NSString *message;

// Client nonce for verification. Download access and client-validation only.
@property (copy) NSString *nonce;

// Error/warning reason code. Additional codes may be added in the future. 0 OK
// 100 ACCESS_DENIED_PUBLISHER_LIMIT 101 ACCESS_DENIED_LIMIT 200
// WARNING_USED_LAST_ACCESS
@property (copy) NSString *reasonCode;

// Whether this volume has any download access restrictions.
@property (retain) NSNumber *restricted;  // boolValue

// Response signature.
@property (copy) NSString *signature;

// Client app identifier for verification. Download access and client-validation
// only.
@property (copy) NSString *source;

// Identifies the volume for which this entry applies.
@property (copy) NSString *volumeId;

@end
