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
//  GTLPlusComment.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google+ API (plus/v1)
// Description:
//   The Google+ API enables developers to build on top of the Google+ platform.
// Documentation:
//   http://developers.google.com/+/api/
// Classes:
//   GTLPlusComment (0 custom class methods, 9 custom properties)
//   GTLPlusCommentActor (0 custom class methods, 4 custom properties)
//   GTLPlusCommentInReplyToItem (0 custom class methods, 2 custom properties)
//   GTLPlusCommentObject (0 custom class methods, 2 custom properties)
//   GTLPlusCommentActorImage (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLPlusCommentActor;
@class GTLPlusCommentActorImage;
@class GTLPlusCommentInReplyToItem;
@class GTLPlusCommentObject;

// ----------------------------------------------------------------------------
//
//   GTLPlusComment
//

@interface GTLPlusComment : GTLObject

// The person who posted this comment.
@property (retain) GTLPlusCommentActor *actor;

// The ID of this comment.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSString *identifier;

// The activity this comment replied to.
@property (retain) NSArray *inReplyTo;  // of GTLPlusCommentInReplyToItem

// Identifies this resource as a comment. Value: "plus#comment".
@property (retain) NSString *kind;

// The object of this comment.
@property (retain) GTLPlusCommentObject *object;

// The time at which this comment was initially published. Formatted as an RFC
// 3339 timestamp.
@property (retain) GTLDateTime *published;

// Link to this comment resource.
@property (retain) NSString *selfLink;

// The time at which this comment was last updated. Formatted as an RFC 3339
// timestamp.
@property (retain) GTLDateTime *updated;

// This comment's verb, indicating what action was performed. Possible values
// are: - "post" - Publish content to the stream.
@property (retain) NSString *verb;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusCommentActor
//

@interface GTLPlusCommentActor : GTLObject

// The name of this actor, suitable for display.
@property (retain) NSString *displayName;

// The ID of the actor.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSString *identifier;

// The image representation of this actor.
@property (retain) GTLPlusCommentActorImage *image;

// A link to the person resource for this actor.
@property (retain) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusCommentInReplyToItem
//

@interface GTLPlusCommentInReplyToItem : GTLObject

// The id of the activity.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSString *identifier;

// The url of the activity.
@property (retain) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusCommentObject
//

@interface GTLPlusCommentObject : GTLObject

// The content of this comment.
@property (retain) NSString *content;

// The object type of this comment. Possible values are: - "comment" - A comment
// in reply to an activity.
@property (retain) NSString *objectType;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusCommentActorImage
//

@interface GTLPlusCommentActorImage : GTLObject

// The URL of the actor's profile photo. To re-size the image and crop it to a
// square, append the query string ?sz=x, where x is the dimension in pixels of
// each side.
@property (retain) NSString *url;

@end
