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
//  GTLOrkutCommunityTopic.h
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
//   GTLOrkutCommunityTopic (0 custom class methods, 11 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLOrkutAuthorResource;
@class GTLOrkutCommunityMessage;
@class GTLOrkutLinkResource;

// ----------------------------------------------------------------------------
//
//   GTLOrkutCommunityTopic
//

@interface GTLOrkutCommunityTopic : GTLObject

// The creator of the topic.
@property (retain) GTLOrkutAuthorResource *author;

// The body of the topic.
@property (copy) NSString *body;

// The ID of the topic.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSNumber *identifier;  // longLongValue

// Whether the topic is closed for new messages.
@property (retain) NSNumber *isClosed;  // boolValue

// Identifies this resource as a community topic. Value: "orkut#communityTopic"
@property (copy) NSString *kind;

// The timestamp of the last update, in RFC 3339 format.
@property (retain) GTLDateTime *lastUpdate;

// Snippet of the last message posted on this topic.
@property (copy) NSString *latestMessageSnippet;

// List of resources for the community.
@property (retain) NSArray *links;  // of GTLOrkutLinkResource

// Most recent messages.
@property (retain) NSArray *messages;  // of GTLOrkutCommunityMessage

// The total number of replies this topic has received.
@property (retain) NSNumber *numberOfReplies;  // intValue

// The title of the topic.
@property (copy) NSString *title;

@end
