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
//   GTLBloggerComment (0 custom class methods, 11 custom properties)
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
@property (nonatomic, retain) GTLBloggerCommentAuthor *author;

// Data about the blog containing this comment.
@property (nonatomic, retain) GTLBloggerCommentBlog *blog;

// The actual content of the comment. May include HTML markup.
@property (nonatomic, copy) NSString *content;

// The identifier for this resource.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Data about the comment this is in reply to.
@property (nonatomic, retain) GTLBloggerCommentInReplyTo *inReplyTo;

// The kind of this entry. Always blogger#comment
@property (nonatomic, copy) NSString *kind;

// Data about the post containing this comment.
@property (nonatomic, retain) GTLBloggerCommentPost *post;

// RFC 3339 date-time when this comment was published.
@property (nonatomic, retain) GTLDateTime *published;

// The API REST URL to fetch this resource from.
@property (nonatomic, copy) NSString *selfLink;

// The status of the comment (only populated for admin users)
@property (nonatomic, copy) NSString *status;

// RFC 3339 date-time when this comment was last updated.
@property (nonatomic, retain) GTLDateTime *updated;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerCommentAuthor
//

@interface GTLBloggerCommentAuthor : GTLObject

// The display name.
@property (nonatomic, copy) NSString *displayName;

// The identifier of the Comment creator.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The comment creator's avatar.
@property (nonatomic, retain) GTLBloggerCommentAuthorImage *image;

// The URL of the Comment creator's Profile page.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerCommentBlog
//

@interface GTLBloggerCommentBlog : GTLObject

// The identifier of the blog containing this comment.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerCommentInReplyTo
//

@interface GTLBloggerCommentInReplyTo : GTLObject

// The identified of the parent of this comment.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerCommentPost
//

@interface GTLBloggerCommentPost : GTLObject

// The identifier of the post containing this comment.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerCommentAuthorImage
//

@interface GTLBloggerCommentAuthorImage : GTLObject

// The comment creator's avatar URL.
@property (nonatomic, copy) NSString *url;

@end
