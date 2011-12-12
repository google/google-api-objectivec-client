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
//  GTLOrkutComment.h
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
//   GTLOrkutComment (0 custom class methods, 7 custom properties)
//   GTLOrkutCommentInReplyTo (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLOrkutAuthorResource;
@class GTLOrkutCommentInReplyTo;
@class GTLOrkutLinkResource;

// ----------------------------------------------------------------------------
//
//   GTLOrkutComment
//

@interface GTLOrkutComment : GTLObject

// The person who posted the comment.
@property (retain) GTLOrkutAuthorResource *actor;

// The content of the comment in text/html
@property (copy) NSString *content;

// The unique ID for the comment.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Link to the original activity where this comment was posted.
@property (retain) GTLOrkutCommentInReplyTo *inReplyTo;

// Identifies this resource as a comment. Value: "orkut#comment"
@property (copy) NSString *kind;

// List of resources for the comment.
@property (retain) NSArray *links;  // of GTLOrkutLinkResource

// The time the comment was initially published, in RFC 3339 format.
@property (retain) GTLDateTime *published;

@end


// ----------------------------------------------------------------------------
//
//   GTLOrkutCommentInReplyTo
//

@interface GTLOrkutCommentInReplyTo : GTLObject

// Link to the post on activity stream being commented.
@property (copy) NSString *href;

// Unique identifier of the post on activity stream being commented.
@property (copy) NSString *ref;

// Relationship between the comment and the post on activity stream being
// commented. Always inReplyTo.
@property (copy) NSString *rel;

// Type of the post on activity stream being commented. Always text/html.
@property (copy) NSString *type;

@end
