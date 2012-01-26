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
//  GTLOrkutCommunityMessage.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Orkut API (orkut/v2)
// Description:
//   Lets you manage activities, comments and badges in Orkut. More stuff coming
//   in time.
// Documentation:
//   http://code.google.com/apis/orkut/v2/reference.html
// Classes:
//   GTLOrkutCommunityMessage (0 custom class methods, 8 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLOrkutAuthorResource;
@class GTLOrkutLinkResource;

// ----------------------------------------------------------------------------
//
//   GTLOrkutCommunityMessage
//

@interface GTLOrkutCommunityMessage : GTLObject

// The timestamp of the date when the message was added, in RFC 3339 format.
@property (retain) GTLDateTime *addedDate;

// The creator of the message. If ommited, the message is annonimous.
@property (retain) GTLOrkutAuthorResource *author;

// The body of the message.
@property (copy) NSString *body;

// The ID of the message.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSNumber *identifier;  // longLongValue

// Whether this post was marked as spam by the viewer, when he/she is not the
// community owner or one of its moderators.
@property (retain) NSNumber *isSpam;  // boolValue

// Identifies this resource as a community message. Value:
// "orkut#communityMessage"
@property (copy) NSString *kind;

// List of resources for the community message.
@property (retain) NSArray *links;  // of GTLOrkutLinkResource

// The subject of the message.
@property (copy) NSString *subject;

@end
