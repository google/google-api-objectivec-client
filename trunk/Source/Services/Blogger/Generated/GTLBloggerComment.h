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
//  GTLBloggerComment.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Blogger API (blogger/v3)
// Description:
//   API for access to the data within Blogger.
// Documentation:
//   https://developers.google.com/blogger/docs/3.0/getting_started
// Classes:
//   GTLBloggerComment (0 custom class methods, 10 custom properties)
//   GTLBloggerCommentAuthor (0 custom class methods, 4 custom properties)
//   GTLBloggerCommentBlog (0 custom class methods, 1 custom properties)
//   GTLBloggerCommentInReplyTo (0 custom class methods, 1 custom properties)
//   GTLBloggerCommentPost (0 custom class methods, 1 custom properties)
//   GTLBloggerCommentAuthorImage (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBloggerCommentAuthor;
@class GTLBloggerCommentAuthorImage;
@class GTLBloggerCommentBlog;
@class GTLBloggerCommentInReplyTo;
@class GTLBloggerCommentPost;

// ----------------------------------------------------------------------------
//
//   GTLBloggerComment
//

@interface GTLBloggerComment : GTLObject

// The author of this Comment.
@property (retain) GTLBloggerCommentAuthor *author;

// Data about the blog containing this comment.
@property (retain) GTLBloggerCommentBlog *blog;

// The actual content of the comment. May include HTML markup.
@property (copy) NSString *content;

// The identifier for this resource.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Data about the comment this is in reply to.
@property (retain) GTLBloggerCommentInReplyTo *inReplyTo;

// The kind of this entry. Always blogger#comment
@property (copy) NSString *kind;

// Data about the post containing this comment.
@property (retain) GTLBloggerCommentPost *post;

// RFC 3339 date-time when this comment was published.
@property (retain) GTLDateTime *published;

// The API REST URL to fetch this resource from.
@property (copy) NSString *selfLink;

// RFC 3339 date-time when this comment was last updated.
@property (retain) GTLDateTime *updated;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerCommentAuthor
//

@interface GTLBloggerCommentAuthor : GTLObject

// The display name.
@property (copy) NSString *displayName;

// The identifier of the Comment creator.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The comment creator's avatar.
@property (retain) GTLBloggerCommentAuthorImage *image;

// The URL of the Comment creator's Profile page.
@property (copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerCommentBlog
//

@interface GTLBloggerCommentBlog : GTLObject

// The identifier of the blog containing this comment.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerCommentInReplyTo
//

@interface GTLBloggerCommentInReplyTo : GTLObject

// The identified of the parent of this comment.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerCommentPost
//

@interface GTLBloggerCommentPost : GTLObject

// The identifier of the post containing this comment.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerCommentAuthorImage
//

@interface GTLBloggerCommentAuthorImage : GTLObject

// The comment creator's avatar URL.
@property (copy) NSString *url;

@end
