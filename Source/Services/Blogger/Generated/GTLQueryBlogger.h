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
//  GTLQueryBlogger.h
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
//   GTLQueryBlogger (17 custom class methods, 17 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLBloggerPost;

@interface GTLQueryBlogger : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (copy) NSString *blogId;
@property (copy) NSString *commentId;
@property (retain) GTLDateTime *endDate;
@property (assign) BOOL fetchBodies;
@property (copy) NSString *labels;
@property (assign) NSUInteger maxComments;
@property (assign) NSUInteger maxPosts;
@property (assign) NSUInteger maxResults;
@property (copy) NSString *pageId;
@property (copy) NSString *pageToken;
@property (copy) NSString *path;
@property (copy) NSString *postId;
@property (copy) NSString *q;
@property (retain) GTLDateTime *startDate;
@property (copy) NSString *url;
@property (copy) NSString *userId;

#pragma mark -
#pragma mark "blogs" methods
// These create a GTLQueryBlogger object.

// Method: blogger.blogs.get
// Gets one blog by id.
//  Required:
//   blogId: The ID of the blog to get.
//  Optional:
//   maxPosts: Maximum number of posts to pull back with the blog.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerBlog.
+ (id)queryForBlogsGetWithBlogId:(NSString *)blogId;

// Method: blogger.blogs.getByUrl
// Retrieve a Blog by URL.
//  Required:
//   url: The URL of the blog to retrieve.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerBlog.
+ (id)queryForBlogsGetByUrlWithUrl:(NSString *)url;

// Method: blogger.blogs.listByUser
// Retrieves a list of blogs, possibly filtered.
//  Required:
//   userId: ID of the user whose blogs are to be fetched. Either the word
//     'self' (sans quote marks) or the user's profile identifier.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerBlogList.
+ (id)queryForBlogsListByUserWithUserId:(NSString *)userId;

#pragma mark -
#pragma mark "blogUserInfos" methods
// These create a GTLQueryBlogger object.

// Method: blogger.blogUserInfos.get
// Gets one blog and user info pair by blogId and userId.
//  Required:
//   userId: ID of the user whose blogs are to be fetched. Either the word
//     'self' (sans quote marks) or the user's profile identifier.
//   blogId: The ID of the blog to get.
//  Optional:
//   maxPosts: Maximum number of posts to pull back with the blog.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerBlogUserInfo.
+ (id)queryForBlogUserInfosGetWithUserId:(NSString *)userId
                                  blogId:(NSString *)blogId;

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
//   kGTLAuthScopeBloggerReadonly
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
//   endDate: Latest date of comment to fetch, a date-time with RFC 3339
//     formatting.
//   fetchBodies: Whether the body content of the comments is included.
//   maxResults: Maximum number of comments to include in the result.
//   pageToken: Continuation token if request is paged.
//   startDate: Earliest date of comment to fetch, a date-time with RFC 3339
//     formatting.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
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
//   kGTLAuthScopeBloggerReadonly
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
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerPageList.
+ (id)queryForPagesListWithBlogId:(NSString *)blogId;

#pragma mark -
#pragma mark "posts" methods
// These create a GTLQueryBlogger object.

// Method: blogger.posts.delete
// Delete a post by id.
//  Required:
//   blogId: The Id of the Blog.
//   postId: The ID of the Post.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
+ (id)queryForPostsDeleteWithBlogId:(NSString *)blogId
                             postId:(NSString *)postId;

// Method: blogger.posts.get
// Get a post by id.
//  Required:
//   blogId: ID of the blog to fetch the post from.
//   postId: The ID of the post
//  Optional:
//   maxComments: Maximum number of comments to pull back on a post.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerPost.
+ (id)queryForPostsGetWithBlogId:(NSString *)blogId
                          postId:(NSString *)postId;

// Method: blogger.posts.getByPath
// Retrieve a Post by Path.
//  Required:
//   blogId: ID of the blog to fetch the post from.
//   path: Path of the Post to retrieve.
//  Optional:
//   maxComments: Maximum number of comments to pull back on a post.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerPost.
+ (id)queryForPostsGetByPathWithBlogId:(NSString *)blogId
                                  path:(NSString *)path;

// Method: blogger.posts.insert
// Add a post.
//  Required:
//   blogId: ID of the blog to add the post to.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPost.
+ (id)queryForPostsInsertWithObject:(GTLBloggerPost *)object
                             blogId:(NSString *)blogId;

// Method: blogger.posts.list
// Retrieves a list of posts, possibly filtered.
//  Required:
//   blogId: ID of the blog to fetch posts from.
//  Optional:
//   endDate: Latest post date to fetch, a date-time with RFC 3339 formatting.
//   fetchBodies: Whether the body content of posts is included.
//   labels: Comma-separated list of labels to search for.
//   maxResults: Maximum number of posts to fetch.
//   pageToken: Continuation token if the request is paged.
//   startDate: Earliest post date to fetch, a date-time with RFC 3339
//     formatting.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerPostList.
+ (id)queryForPostsListWithBlogId:(NSString *)blogId;

// Method: blogger.posts.patch
// Update a post. This method supports patch semantics.
//  Required:
//   blogId: The ID of the Blog.
//   postId: The ID of the Post.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPost.
+ (id)queryForPostsPatchWithObject:(GTLBloggerPost *)object
                            blogId:(NSString *)blogId
                            postId:(NSString *)postId;

// Method: blogger.posts.search
// Search for a post.
//  Required:
//   blogId: ID of the blog to fetch the post from.
//   q: Query terms to search this blog for matching posts.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerPostList.
+ (id)queryForPostsSearchWithBlogId:(NSString *)blogId
                                  q:(NSString *)q;

// Method: blogger.posts.update
// Update a post.
//  Required:
//   blogId: The ID of the Blog.
//   postId: The ID of the Post.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPost.
+ (id)queryForPostsUpdateWithObject:(GTLBloggerPost *)object
                             blogId:(NSString *)blogId
                             postId:(NSString *)postId;

#pragma mark -
#pragma mark "users" methods
// These create a GTLQueryBlogger object.

// Method: blogger.users.get
// Gets one user by id.
//  Required:
//   userId: The ID of the user to get.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerUser.
+ (id)queryForUsersGetWithUserId:(NSString *)userId;

@end
