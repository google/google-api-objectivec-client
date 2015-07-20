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
//   GTLQueryBlogger (33 custom class methods, 29 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLBloggerPage;
@class GTLBloggerPost;

@interface GTLQueryBlogger : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (nonatomic, copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (nonatomic, copy) NSString *blogId;
@property (nonatomic, copy) NSString *commentId;
@property (nonatomic, retain) GTLDateTime *endDate;
@property (nonatomic, assign) BOOL fetchBodies;
@property (nonatomic, assign) BOOL fetchBody;
@property (nonatomic, assign) BOOL fetchImages;
@property (nonatomic, assign) BOOL fetchUserInfo;
@property (nonatomic, assign) BOOL isDraft;
@property (nonatomic, copy) NSString *labels;
@property (nonatomic, assign) NSUInteger maxComments;
@property (nonatomic, assign) NSUInteger maxPosts;
@property (nonatomic, assign) NSUInteger maxResults;
@property (nonatomic, copy) NSString *orderBy;
@property (nonatomic, copy) NSString *pageId;
@property (nonatomic, copy) NSString *pageToken;
@property (nonatomic, copy) NSString *path;
@property (nonatomic, copy) NSString *postId;
@property (nonatomic, assign) BOOL publish;
@property (nonatomic, retain) GTLDateTime *publishDate;
@property (nonatomic, copy) NSString *q;
@property (nonatomic, retain) NSArray *range;  // of NSString
@property (nonatomic, assign) BOOL revert;
@property (nonatomic, retain) NSArray *role;  // of NSString
@property (nonatomic, retain) GTLDateTime *startDate;
@property (nonatomic, retain) NSArray *status;  // of NSString
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *view;

#pragma mark -
#pragma mark "blogs" methods
// These create a GTLQueryBlogger object.

// Method: blogger.blogs.get
// Gets one blog by ID.
//  Required:
//   blogId: The ID of the blog to get.
//  Optional:
//   maxPosts: Maximum number of posts to pull back with the blog.
//   view: Access level with which to view the blog. Note that some fields
//     require elevated access.
//      kGTLBloggerViewAdmin: Admin level detail.
//      kGTLBloggerViewAuthor: Author level detail.
//      kGTLBloggerViewReader: Reader level detail.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerBlog.
+ (instancetype)queryForBlogsGetWithBlogId:(NSString *)blogId;

// Method: blogger.blogs.getByUrl
// Retrieve a Blog by URL.
//  Required:
//   url: The URL of the blog to retrieve.
//  Optional:
//   view: Access level with which to view the blog. Note that some fields
//     require elevated access.
//      kGTLBloggerViewAdmin: Admin level detail.
//      kGTLBloggerViewAuthor: Author level detail.
//      kGTLBloggerViewReader: Reader level detail.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerBlog.
+ (instancetype)queryForBlogsGetByUrlWithUrl:(NSString *)url;

// Method: blogger.blogs.listByUser
// Retrieves a list of blogs, possibly filtered.
//  Required:
//   userId: ID of the user whose blogs are to be fetched. Either the word
//     'self' (sans quote marks) or the user's profile identifier.
//  Optional:
//   fetchUserInfo: Whether the response is a list of blogs with per-user
//     information instead of just blogs.
//   role: User access types for blogs to include in the results, e.g. AUTHOR
//     will return blogs where the user has author level access. If no roles are
//     specified, defaults to ADMIN and AUTHOR roles.
//      kGTLBloggerRoleAdmin: Admin role - Blogs where the user has Admin level
//        access.
//      kGTLBloggerRoleAuthor: Author role - Blogs where the user has Author
//        level access.
//      kGTLBloggerRoleReader: Reader role - Blogs where the user has Reader
//        level access (to a private blog).
//   status: Blog statuses to include in the result (default: Live blogs only).
//     Note that ADMIN access is required to view deleted blogs. (Default
//     kGTLBloggerStatusLive)
//      kGTLBloggerStatusDeleted: Blog has been deleted by an administrator.
//      kGTLBloggerStatusLive: Blog is currently live.
//   view: Access level with which to view the blogs. Note that some fields
//     require elevated access.
//      kGTLBloggerViewAdmin: Admin level detail.
//      kGTLBloggerViewAuthor: Author level detail.
//      kGTLBloggerViewReader: Reader level detail.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerBlogList.
+ (instancetype)queryForBlogsListByUserWithUserId:(NSString *)userId;

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
+ (instancetype)queryForBlogUserInfosGetWithUserId:(NSString *)userId
                                            blogId:(NSString *)blogId;

#pragma mark -
#pragma mark "comments" methods
// These create a GTLQueryBlogger object.

// Method: blogger.comments.approve
// Marks a comment as not spam.
//  Required:
//   blogId: The ID of the Blog.
//   postId: The ID of the Post.
//   commentId: The ID of the comment to mark as not spam.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerComment.
+ (instancetype)queryForCommentsApproveWithBlogId:(NSString *)blogId
                                           postId:(NSString *)postId
                                        commentId:(NSString *)commentId;

// Method: blogger.comments.delete
// Delete a comment by ID.
//  Required:
//   blogId: The ID of the Blog.
//   postId: The ID of the Post.
//   commentId: The ID of the comment to delete.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
+ (instancetype)queryForCommentsDeleteWithBlogId:(NSString *)blogId
                                          postId:(NSString *)postId
                                       commentId:(NSString *)commentId;

// Method: blogger.comments.get
// Gets one comment by ID.
//  Required:
//   blogId: ID of the blog to containing the comment.
//   postId: ID of the post to fetch posts from.
//   commentId: The ID of the comment to get.
//  Optional:
//   view: Access level for the requested comment (default: READER). Note that
//     some comments will require elevated permissions, for example comments
//     where the parent posts which is in a draft state, or comments that are
//     pending moderation.
//      kGTLBloggerViewAdmin: Admin level detail
//      kGTLBloggerViewAuthor: Author level detail
//      kGTLBloggerViewReader: Admin level detail
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerComment.
+ (instancetype)queryForCommentsGetWithBlogId:(NSString *)blogId
                                       postId:(NSString *)postId
                                    commentId:(NSString *)commentId;

// Method: blogger.comments.list
// Retrieves the comments for a post, possibly filtered.
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
//   status: NSArray<NSString>
//      kGTLBloggerStatusEmptied: Comments that have had their content removed
//      kGTLBloggerStatusLive: Comments that are publicly visible
//      kGTLBloggerStatusPending: Comments that are awaiting administrator
//        approval
//      kGTLBloggerStatusSpam: Comments marked as spam by the administrator
//   view: Access level with which to view the returned result. Note that some
//     fields require elevated access.
//      kGTLBloggerViewAdmin: Admin level detail
//      kGTLBloggerViewAuthor: Author level detail
//      kGTLBloggerViewReader: Reader level detail
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerCommentList.
+ (instancetype)queryForCommentsListWithBlogId:(NSString *)blogId
                                        postId:(NSString *)postId;

// Method: blogger.comments.listByBlog
// Retrieves the comments for a blog, across all posts, possibly filtered.
//  Required:
//   blogId: ID of the blog to fetch comments from.
//  Optional:
//   endDate: Latest date of comment to fetch, a date-time with RFC 3339
//     formatting.
//   fetchBodies: Whether the body content of the comments is included.
//   maxResults: Maximum number of comments to include in the result.
//   pageToken: Continuation token if request is paged.
//   startDate: Earliest date of comment to fetch, a date-time with RFC 3339
//     formatting.
//   status: NSArray<NSString>
//      kGTLBloggerStatusEmptied: Comments that have had their content removed
//      kGTLBloggerStatusLive: Comments that are publicly visible
//      kGTLBloggerStatusPending: Comments that are awaiting administrator
//        approval
//      kGTLBloggerStatusSpam: Comments marked as spam by the administrator
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerCommentList.
+ (instancetype)queryForCommentsListByBlogWithBlogId:(NSString *)blogId;

// Method: blogger.comments.markAsSpam
// Marks a comment as spam.
//  Required:
//   blogId: The ID of the Blog.
//   postId: The ID of the Post.
//   commentId: The ID of the comment to mark as spam.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerComment.
+ (instancetype)queryForCommentsMarkAsSpamWithBlogId:(NSString *)blogId
                                              postId:(NSString *)postId
                                           commentId:(NSString *)commentId;

// Method: blogger.comments.removeContent
// Removes the content of a comment.
//  Required:
//   blogId: The ID of the Blog.
//   postId: The ID of the Post.
//   commentId: The ID of the comment to delete content from.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerComment.
+ (instancetype)queryForCommentsRemoveContentWithBlogId:(NSString *)blogId
                                                 postId:(NSString *)postId
                                              commentId:(NSString *)commentId;

#pragma mark -
#pragma mark "pages" methods
// These create a GTLQueryBlogger object.

// Method: blogger.pages.delete
// Delete a page by ID.
//  Required:
//   blogId: The ID of the Blog.
//   pageId: The ID of the Page.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
+ (instancetype)queryForPagesDeleteWithBlogId:(NSString *)blogId
                                       pageId:(NSString *)pageId;

// Method: blogger.pages.get
// Gets one blog page by ID.
//  Required:
//   blogId: ID of the blog containing the page.
//   pageId: The ID of the page to get.
//  Optional:
//   view: NSString
//      kGTLBloggerViewAdmin: Admin level detail
//      kGTLBloggerViewAuthor: Author level detail
//      kGTLBloggerViewReader: Reader level detail
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerPage.
+ (instancetype)queryForPagesGetWithBlogId:(NSString *)blogId
                                    pageId:(NSString *)pageId;

// Method: blogger.pages.insert
// Add a page.
//  Required:
//   blogId: ID of the blog to add the page to.
//  Optional:
//   isDraft: Whether to create the page as a draft (default: false).
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPage.
+ (instancetype)queryForPagesInsertWithObject:(GTLBloggerPage *)object
                                       blogId:(NSString *)blogId;

// Method: blogger.pages.list
// Retrieves the pages for a blog, optionally including non-LIVE statuses.
//  Required:
//   blogId: ID of the blog to fetch Pages from.
//  Optional:
//   fetchBodies: Whether to retrieve the Page bodies.
//   maxResults: Maximum number of Pages to fetch.
//   pageToken: Continuation token if the request is paged.
//   status: NSArray<NSString>
//      kGTLBloggerStatusDraft: Draft (unpublished) Pages
//      kGTLBloggerStatusLive: Pages that are publicly visible
//   view: Access level with which to view the returned result. Note that some
//     fields require elevated access.
//      kGTLBloggerViewAdmin: Admin level detail
//      kGTLBloggerViewAuthor: Author level detail
//      kGTLBloggerViewReader: Reader level detail
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerPageList.
+ (instancetype)queryForPagesListWithBlogId:(NSString *)blogId;

// Method: blogger.pages.patch
// Update a page. This method supports patch semantics.
//  Required:
//   blogId: The ID of the Blog.
//   pageId: The ID of the Page.
//  Optional:
//   publish: Whether a publish action should be performed when the page is
//     updated (default: false).
//   revert: Whether a revert action should be performed when the page is
//     updated (default: false).
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPage.
+ (instancetype)queryForPagesPatchWithObject:(GTLBloggerPage *)object
                                      blogId:(NSString *)blogId
                                      pageId:(NSString *)pageId;

// Method: blogger.pages.publish
// Publishes a draft page.
//  Required:
//   blogId: The ID of the blog.
//   pageId: The ID of the page.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPage.
+ (instancetype)queryForPagesPublishWithBlogId:(NSString *)blogId
                                        pageId:(NSString *)pageId;

// Method: blogger.pages.revert
// Revert a published or scheduled page to draft state.
//  Required:
//   blogId: The ID of the blog.
//   pageId: The ID of the page.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPage.
+ (instancetype)queryForPagesRevertWithBlogId:(NSString *)blogId
                                       pageId:(NSString *)pageId;

// Method: blogger.pages.update
// Update a page.
//  Required:
//   blogId: The ID of the Blog.
//   pageId: The ID of the Page.
//  Optional:
//   publish: Whether a publish action should be performed when the page is
//     updated (default: false).
//   revert: Whether a revert action should be performed when the page is
//     updated (default: false).
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPage.
+ (instancetype)queryForPagesUpdateWithObject:(GTLBloggerPage *)object
                                       blogId:(NSString *)blogId
                                       pageId:(NSString *)pageId;

#pragma mark -
#pragma mark "pageViews" methods
// These create a GTLQueryBlogger object.

// Method: blogger.pageViews.get
// Retrieve pageview stats for a Blog.
//  Required:
//   blogId: The ID of the blog to get.
//  Optional:
//   range: NSArray<NSString>
//      kGTLBloggerRangeX30days: Page view counts from the last thirty days.
//      kGTLBloggerRangeX7days: Page view counts from the last seven days.
//      kGTLBloggerRangeAll: Total page view counts from all time.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPageviews.
+ (instancetype)queryForPageViewsGetWithBlogId:(NSString *)blogId;

#pragma mark -
#pragma mark "posts" methods
// These create a GTLQueryBlogger object.

// Method: blogger.posts.delete
// Delete a post by ID.
//  Required:
//   blogId: The ID of the Blog.
//   postId: The ID of the Post.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
+ (instancetype)queryForPostsDeleteWithBlogId:(NSString *)blogId
                                       postId:(NSString *)postId;

// Method: blogger.posts.get
// Get a post by ID.
//  Required:
//   blogId: ID of the blog to fetch the post from.
//   postId: The ID of the post
//  Optional:
//   fetchBody: Whether the body content of the post is included (default:
//     true). This should be set to false when the post bodies are not required,
//     to help minimize traffic. (Default true)
//   fetchImages: Whether image URL metadata for each post is included (default:
//     false).
//   maxComments: Maximum number of comments to pull back on a post.
//   view: Access level with which to view the returned result. Note that some
//     fields require elevated access.
//      kGTLBloggerViewAdmin: Admin level detail
//      kGTLBloggerViewAuthor: Author level detail
//      kGTLBloggerViewReader: Reader level detail
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerPost.
+ (instancetype)queryForPostsGetWithBlogId:(NSString *)blogId
                                    postId:(NSString *)postId;

// Method: blogger.posts.getByPath
// Retrieve a Post by Path.
//  Required:
//   blogId: ID of the blog to fetch the post from.
//   path: Path of the Post to retrieve.
//  Optional:
//   maxComments: Maximum number of comments to pull back on a post.
//   view: Access level with which to view the returned result. Note that some
//     fields require elevated access.
//      kGTLBloggerViewAdmin: Admin level detail
//      kGTLBloggerViewAuthor: Author level detail
//      kGTLBloggerViewReader: Reader level detail
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerPost.
+ (instancetype)queryForPostsGetByPathWithBlogId:(NSString *)blogId
                                            path:(NSString *)path;

// Method: blogger.posts.insert
// Add a post.
//  Required:
//   blogId: ID of the blog to add the post to.
//  Optional:
//   fetchBody: Whether the body content of the post is included with the result
//     (default: true). (Default true)
//   fetchImages: Whether image URL metadata for each post is included in the
//     returned result (default: false).
//   isDraft: Whether to create the post as a draft (default: false).
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPost.
+ (instancetype)queryForPostsInsertWithObject:(GTLBloggerPost *)object
                                       blogId:(NSString *)blogId;

// Method: blogger.posts.list
// Retrieves a list of posts, possibly filtered.
//  Required:
//   blogId: ID of the blog to fetch posts from.
//  Optional:
//   endDate: Latest post date to fetch, a date-time with RFC 3339 formatting.
//   fetchBodies: Whether the body content of posts is included (default: true).
//     This should be set to false when the post bodies are not required, to
//     help minimize traffic. (Default true)
//   fetchImages: Whether image URL metadata for each post is included.
//   labels: Comma-separated list of labels to search for.
//   maxResults: Maximum number of posts to fetch.
//   orderBy: Sort search results (Default "PUBLISHED")
//      kGTLBloggerOrderByPublished: Order by the date the post was published
//      kGTLBloggerOrderByUpdated: Order by the date the post was last updated
//   pageToken: Continuation token if the request is paged.
//   startDate: Earliest post date to fetch, a date-time with RFC 3339
//     formatting.
//   status: Statuses to include in the results.
//      kGTLBloggerStatusDraft: Draft (non-published) posts.
//      kGTLBloggerStatusLive: Published posts
//      kGTLBloggerStatusScheduled: Posts that are scheduled to publish in the
//        future.
//   view: Access level with which to view the returned result. Note that some
//     fields require escalated access.
//      kGTLBloggerViewAdmin: Admin level detail
//      kGTLBloggerViewAuthor: Author level detail
//      kGTLBloggerViewReader: Reader level detail
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerPostList.
+ (instancetype)queryForPostsListWithBlogId:(NSString *)blogId;

// Method: blogger.posts.patch
// Update a post. This method supports patch semantics.
//  Required:
//   blogId: The ID of the Blog.
//   postId: The ID of the Post.
//  Optional:
//   fetchBody: Whether the body content of the post is included with the result
//     (default: true). (Default true)
//   fetchImages: Whether image URL metadata for each post is included in the
//     returned result (default: false).
//   maxComments: Maximum number of comments to retrieve with the returned post.
//   publish: Whether a publish action should be performed when the post is
//     updated (default: false).
//   revert: Whether a revert action should be performed when the post is
//     updated (default: false).
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPost.
+ (instancetype)queryForPostsPatchWithObject:(GTLBloggerPost *)object
                                      blogId:(NSString *)blogId
                                      postId:(NSString *)postId;

// Method: blogger.posts.publish
// Publishes a draft post, optionally at the specific time of the given
// publishDate parameter.
//  Required:
//   blogId: The ID of the Blog.
//   postId: The ID of the Post.
//  Optional:
//   publishDate: Optional date and time to schedule the publishing of the Blog.
//     If no publishDate parameter is given, the post is either published at the
//     a previously saved schedule date (if present), or the current time. If a
//     future date is given, the post will be scheduled to be published.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPost.
+ (instancetype)queryForPostsPublishWithBlogId:(NSString *)blogId
                                        postId:(NSString *)postId;

// Method: blogger.posts.revert
// Revert a published or scheduled post to draft state.
//  Required:
//   blogId: The ID of the Blog.
//   postId: The ID of the Post.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPost.
+ (instancetype)queryForPostsRevertWithBlogId:(NSString *)blogId
                                       postId:(NSString *)postId;

// Method: blogger.posts.search
// Search for a post.
//  Required:
//   blogId: ID of the blog to fetch the post from.
//   q: Query terms to search this blog for matching posts.
//  Optional:
//   fetchBodies: Whether the body content of posts is included (default: true).
//     This should be set to false when the post bodies are not required, to
//     help minimize traffic. (Default true)
//   orderBy: Sort search results (Default "PUBLISHED")
//      kGTLBloggerOrderByPublished: Order by the date the post was published
//      kGTLBloggerOrderByUpdated: Order by the date the post was last updated
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerPostList.
+ (instancetype)queryForPostsSearchWithBlogId:(NSString *)blogId
                                            q:(NSString *)q;

// Method: blogger.posts.update
// Update a post.
//  Required:
//   blogId: The ID of the Blog.
//   postId: The ID of the Post.
//  Optional:
//   fetchBody: Whether the body content of the post is included with the result
//     (default: true). (Default true)
//   fetchImages: Whether image URL metadata for each post is included in the
//     returned result (default: false).
//   maxComments: Maximum number of comments to retrieve with the returned post.
//   publish: Whether a publish action should be performed when the post is
//     updated (default: false).
//   revert: Whether a revert action should be performed when the post is
//     updated (default: false).
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
// Fetches a GTLBloggerPost.
+ (instancetype)queryForPostsUpdateWithObject:(GTLBloggerPost *)object
                                       blogId:(NSString *)blogId
                                       postId:(NSString *)postId;

#pragma mark -
#pragma mark "postUserInfos" methods
// These create a GTLQueryBlogger object.

// Method: blogger.postUserInfos.get
// Gets one post and user info pair, by post ID and user ID. The post user info
// contains per-user information about the post, such as access rights, specific
// to the user.
//  Required:
//   userId: ID of the user for the per-user information to be fetched. Either
//     the word 'self' (sans quote marks) or the user's profile identifier.
//   blogId: The ID of the blog.
//   postId: The ID of the post to get.
//  Optional:
//   maxComments: Maximum number of comments to pull back on a post.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerPostUserInfo.
+ (instancetype)queryForPostUserInfosGetWithUserId:(NSString *)userId
                                            blogId:(NSString *)blogId
                                            postId:(NSString *)postId;

// Method: blogger.postUserInfos.list
// Retrieves a list of post and post user info pairs, possibly filtered. The
// post user info contains per-user information about the post, such as access
// rights, specific to the user.
//  Required:
//   userId: ID of the user for the per-user information to be fetched. Either
//     the word 'self' (sans quote marks) or the user's profile identifier.
//   blogId: ID of the blog to fetch posts from.
//  Optional:
//   endDate: Latest post date to fetch, a date-time with RFC 3339 formatting.
//   fetchBodies: Whether the body content of posts is included. Default is
//     false. (Default false)
//   labels: Comma-separated list of labels to search for.
//   maxResults: Maximum number of posts to fetch.
//   orderBy: Sort order applied to search results. Default is published.
//     (Default "PUBLISHED")
//      kGTLBloggerOrderByPublished: Order by the date the post was published
//      kGTLBloggerOrderByUpdated: Order by the date the post was last updated
//   pageToken: Continuation token if the request is paged.
//   startDate: Earliest post date to fetch, a date-time with RFC 3339
//     formatting.
//   status: NSArray<NSString>
//      kGTLBloggerStatusDraft: Draft posts
//      kGTLBloggerStatusLive: Published posts
//      kGTLBloggerStatusScheduled: Posts that are scheduled to publish in
//        future.
//   view: Access level with which to view the returned result. Note that some
//     fields require elevated access.
//      kGTLBloggerViewAdmin: Admin level detail
//      kGTLBloggerViewAuthor: Author level detail
//      kGTLBloggerViewReader: Reader level detail
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerPostUserInfosList.
+ (instancetype)queryForPostUserInfosListWithUserId:(NSString *)userId
                                             blogId:(NSString *)blogId;

#pragma mark -
#pragma mark "users" methods
// These create a GTLQueryBlogger object.

// Method: blogger.users.get
// Gets one user by ID.
//  Required:
//   userId: The ID of the user to get.
//  Authorization scope(s):
//   kGTLAuthScopeBlogger
//   kGTLAuthScopeBloggerReadonly
// Fetches a GTLBloggerUser.
+ (instancetype)queryForUsersGetWithUserId:(NSString *)userId;

@end
