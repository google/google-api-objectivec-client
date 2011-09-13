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
//  GTLQueryBlogger.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Blogger API (blogger/v2)
// Description:
//   API for access to the data within Blogger.
// Documentation:
//   https://code.google.com/apis/blogger/docs/2.0/json/getting_started.html
// Classes:
//   GTLQueryBlogger (9 custom class methods, 10 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@interface GTLQueryBlogger : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (retain) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (retain) NSString *blogId;
@property (retain) NSString *commentId;
@property (assign) BOOL fetchBodies;
@property (assign) NSUInteger maxResults;
@property (retain) NSString *pageId;
@property (retain) NSString *pageToken;
@property (retain) NSString *postId;
@property (retain) NSString *startDate;
@property (retain) NSString *userId;

#pragma mark -
#pragma mark "blogs" methods
// These create a GTLQueryBlogger object.

// Method: blogger.blogs.get
// Gets one blog by id.
//  Required:
//   blogId: The ID of the blog to get.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerBlog.
+ (id)queryForBlogsGetWithBlogId:(NSString *)blogId;

#pragma mark -
#pragma mark "comments" methods
// These create a GTLQueryBlogger object.

// Method: blogger.comments.get
// Gets one comment by id.
//  Required:
//   blogId: ID of the blog to containing the comment.
//   postId: ID of the post to fetch posts from.
//   commentId: The ID of the comment to get.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerComment.
+ (id)queryForCommentsGetWithBlogId:(NSString *)blogId
                             postId:(NSString *)postId
                          commentId:(NSString *)commentId;

// Method: blogger.comments.list
// Retrieves the comments for a blog, possibly filtered.
//  Required:
//   blogId: ID of the blog to fetch comments from.
//   postId: ID of the post to fetch posts from.
//  Optional:
//   fetchBodies: Whether the body content of the comments is included.
//   maxResults: Maximum number of comments to include in the result.
//   pageToken: Continuation token if request is paged.
//   startDate: Earliest date of comment to fetch.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerCommentList.
+ (id)queryForCommentsListWithBlogId:(NSString *)blogId
                              postId:(NSString *)postId;

#pragma mark -
#pragma mark "pages" methods
// These create a GTLQueryBlogger object.

// Method: blogger.pages.get
// Gets one blog page by id.
//  Required:
//   blogId: ID of the blog containing the page.
//   pageId: The ID of the page to get.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPage.
+ (id)queryForPagesGetWithBlogId:(NSString *)blogId
                          pageId:(NSString *)pageId;

// Method: blogger.pages.list
// Retrieves pages for a blog, possibly filtered.
//  Required:
//   blogId: ID of the blog to fetch pages from.
//  Optional:
//   fetchBodies: Whether to retrieve the Page bodies.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPageList.
+ (id)queryForPagesListWithBlogId:(NSString *)blogId;

#pragma mark -
#pragma mark "posts" methods
// These create a GTLQueryBlogger object.

// Method: blogger.posts.get
// Get a post by id.
//  Required:
//   blogId: ID of the blog to fetch the post from.
//   postId: The ID of the post
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPost.
+ (id)queryForPostsGetWithBlogId:(NSString *)blogId
                          postId:(NSString *)postId;

// Method: blogger.posts.list
// Retrieves a list of posts, possibly filtered.
//  Required:
//   blogId: ID of the blog to fetch posts from.
//  Optional:
//   fetchBodies: Whether the body content of posts is included.
//   maxResults: Maximum number of posts to fetch.
//   pageToken: Continuation token if the request is paged.
//   startDate: Earliest post date to fetch.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPostList.
+ (id)queryForPostsListWithBlogId:(NSString *)blogId;

#pragma mark -
#pragma mark "users.blogs" methods
// These create a GTLQueryBlogger object.

// Method: blogger.users.blogs.list
// Retrieves a list of blogs, possibly filtered.
//  Required:
//   userId: ID of the user whose blogs are to be fetched.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerBlogList.
+ (id)queryForUsersBlogsListWithUserId:(NSString *)userId;

#pragma mark -
#pragma mark "users" methods
// These create a GTLQueryBlogger object.

// Method: blogger.users.get
// Gets one user by id.
//  Required:
//   userId: The ID of the user to get.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerUser.
+ (id)queryForUsersGetWithUserId:(NSString *)userId;

@end
