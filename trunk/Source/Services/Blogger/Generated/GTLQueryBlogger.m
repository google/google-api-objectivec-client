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
//  GTLQueryBlogger.m
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

#import "GTLQueryBlogger.h"

#import "GTLBloggerBlog.h"
#import "GTLBloggerBlogList.h"
#import "GTLBloggerBlogUserInfo.h"
#import "GTLBloggerComment.h"
#import "GTLBloggerCommentList.h"
#import "GTLBloggerPage.h"
#import "GTLBloggerPageList.h"
#import "GTLBloggerPageviews.h"
#import "GTLBloggerPost.h"
#import "GTLBloggerPostList.h"
#import "GTLBloggerPostUserInfo.h"
#import "GTLBloggerPostUserInfosList.h"
#import "GTLBloggerUser.h"

@implementation GTLQueryBlogger

@dynamic blogId, commentId, endDate, fetchBodies, fetchBody, fetchImages,
         fetchUserInfo, fields, isDraft, labels, maxComments, maxPosts,
         maxResults, orderBy, pageId, pageToken, path, postId, publish,
         publishDate, q, range, revert, role, startDate, status, url, userId,
         view;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"range" : [NSString class],
    @"role" : [NSString class],
    @"status" : [NSString class]
  };
  return map;
}

#pragma mark -
#pragma mark "blogs" methods
// These create a GTLQueryBlogger object.

+ (instancetype)queryForBlogsGetWithBlogId:(NSString *)blogId {
  NSString *methodName = @"blogger.blogs.get";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.expectedObjectClass = [GTLBloggerBlog class];
  return query;
}

+ (instancetype)queryForBlogsGetByUrlWithUrl:(NSString *)url {
  NSString *methodName = @"blogger.blogs.getByUrl";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.url = url;
  query.expectedObjectClass = [GTLBloggerBlog class];
  return query;
}

+ (instancetype)queryForBlogsListByUserWithUserId:(NSString *)userId {
  NSString *methodName = @"blogger.blogs.listByUser";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLBloggerBlogList class];
  return query;
}

#pragma mark -
#pragma mark "blogUserInfos" methods
// These create a GTLQueryBlogger object.

+ (instancetype)queryForBlogUserInfosGetWithUserId:(NSString *)userId
                                            blogId:(NSString *)blogId {
  NSString *methodName = @"blogger.blogUserInfos.get";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.blogId = blogId;
  query.expectedObjectClass = [GTLBloggerBlogUserInfo class];
  return query;
}

#pragma mark -
#pragma mark "comments" methods
// These create a GTLQueryBlogger object.

+ (instancetype)queryForCommentsApproveWithBlogId:(NSString *)blogId
                                           postId:(NSString *)postId
                                        commentId:(NSString *)commentId {
  NSString *methodName = @"blogger.comments.approve";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.postId = postId;
  query.commentId = commentId;
  query.expectedObjectClass = [GTLBloggerComment class];
  return query;
}

+ (instancetype)queryForCommentsDeleteWithBlogId:(NSString *)blogId
                                          postId:(NSString *)postId
                                       commentId:(NSString *)commentId {
  NSString *methodName = @"blogger.comments.delete";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.postId = postId;
  query.commentId = commentId;
  return query;
}

+ (instancetype)queryForCommentsGetWithBlogId:(NSString *)blogId
                                       postId:(NSString *)postId
                                    commentId:(NSString *)commentId {
  NSString *methodName = @"blogger.comments.get";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.postId = postId;
  query.commentId = commentId;
  query.expectedObjectClass = [GTLBloggerComment class];
  return query;
}

+ (instancetype)queryForCommentsListWithBlogId:(NSString *)blogId
                                        postId:(NSString *)postId {
  NSString *methodName = @"blogger.comments.list";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.postId = postId;
  query.expectedObjectClass = [GTLBloggerCommentList class];
  return query;
}

+ (instancetype)queryForCommentsListByBlogWithBlogId:(NSString *)blogId {
  NSString *methodName = @"blogger.comments.listByBlog";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.expectedObjectClass = [GTLBloggerCommentList class];
  return query;
}

+ (instancetype)queryForCommentsMarkAsSpamWithBlogId:(NSString *)blogId
                                              postId:(NSString *)postId
                                           commentId:(NSString *)commentId {
  NSString *methodName = @"blogger.comments.markAsSpam";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.postId = postId;
  query.commentId = commentId;
  query.expectedObjectClass = [GTLBloggerComment class];
  return query;
}

+ (instancetype)queryForCommentsRemoveContentWithBlogId:(NSString *)blogId
                                                 postId:(NSString *)postId
                                              commentId:(NSString *)commentId {
  NSString *methodName = @"blogger.comments.removeContent";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.postId = postId;
  query.commentId = commentId;
  query.expectedObjectClass = [GTLBloggerComment class];
  return query;
}

#pragma mark -
#pragma mark "pages" methods
// These create a GTLQueryBlogger object.

+ (instancetype)queryForPagesDeleteWithBlogId:(NSString *)blogId
                                       pageId:(NSString *)pageId {
  NSString *methodName = @"blogger.pages.delete";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.pageId = pageId;
  return query;
}

+ (instancetype)queryForPagesGetWithBlogId:(NSString *)blogId
                                    pageId:(NSString *)pageId {
  NSString *methodName = @"blogger.pages.get";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.pageId = pageId;
  query.expectedObjectClass = [GTLBloggerPage class];
  return query;
}

+ (instancetype)queryForPagesInsertWithObject:(GTLBloggerPage *)object
                                       blogId:(NSString *)blogId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"blogger.pages.insert";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.blogId = blogId;
  query.expectedObjectClass = [GTLBloggerPage class];
  return query;
}

+ (instancetype)queryForPagesListWithBlogId:(NSString *)blogId {
  NSString *methodName = @"blogger.pages.list";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.expectedObjectClass = [GTLBloggerPageList class];
  return query;
}

+ (instancetype)queryForPagesPatchWithObject:(GTLBloggerPage *)object
                                      blogId:(NSString *)blogId
                                      pageId:(NSString *)pageId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"blogger.pages.patch";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.blogId = blogId;
  query.pageId = pageId;
  query.expectedObjectClass = [GTLBloggerPage class];
  return query;
}

+ (instancetype)queryForPagesPublishWithBlogId:(NSString *)blogId
                                        pageId:(NSString *)pageId {
  NSString *methodName = @"blogger.pages.publish";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.pageId = pageId;
  query.expectedObjectClass = [GTLBloggerPage class];
  return query;
}

+ (instancetype)queryForPagesRevertWithBlogId:(NSString *)blogId
                                       pageId:(NSString *)pageId {
  NSString *methodName = @"blogger.pages.revert";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.pageId = pageId;
  query.expectedObjectClass = [GTLBloggerPage class];
  return query;
}

+ (instancetype)queryForPagesUpdateWithObject:(GTLBloggerPage *)object
                                       blogId:(NSString *)blogId
                                       pageId:(NSString *)pageId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"blogger.pages.update";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.blogId = blogId;
  query.pageId = pageId;
  query.expectedObjectClass = [GTLBloggerPage class];
  return query;
}

#pragma mark -
#pragma mark "pageViews" methods
// These create a GTLQueryBlogger object.

+ (instancetype)queryForPageViewsGetWithBlogId:(NSString *)blogId {
  NSString *methodName = @"blogger.pageViews.get";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.expectedObjectClass = [GTLBloggerPageviews class];
  return query;
}

#pragma mark -
#pragma mark "posts" methods
// These create a GTLQueryBlogger object.

+ (instancetype)queryForPostsDeleteWithBlogId:(NSString *)blogId
                                       postId:(NSString *)postId {
  NSString *methodName = @"blogger.posts.delete";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.postId = postId;
  return query;
}

+ (instancetype)queryForPostsGetWithBlogId:(NSString *)blogId
                                    postId:(NSString *)postId {
  NSString *methodName = @"blogger.posts.get";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.postId = postId;
  query.expectedObjectClass = [GTLBloggerPost class];
  return query;
}

+ (instancetype)queryForPostsGetByPathWithBlogId:(NSString *)blogId
                                            path:(NSString *)path {
  NSString *methodName = @"blogger.posts.getByPath";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.path = path;
  query.expectedObjectClass = [GTLBloggerPost class];
  return query;
}

+ (instancetype)queryForPostsInsertWithObject:(GTLBloggerPost *)object
                                       blogId:(NSString *)blogId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"blogger.posts.insert";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.blogId = blogId;
  query.expectedObjectClass = [GTLBloggerPost class];
  return query;
}

+ (instancetype)queryForPostsListWithBlogId:(NSString *)blogId {
  NSString *methodName = @"blogger.posts.list";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.expectedObjectClass = [GTLBloggerPostList class];
  return query;
}

+ (instancetype)queryForPostsPatchWithObject:(GTLBloggerPost *)object
                                      blogId:(NSString *)blogId
                                      postId:(NSString *)postId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"blogger.posts.patch";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.blogId = blogId;
  query.postId = postId;
  query.expectedObjectClass = [GTLBloggerPost class];
  return query;
}

+ (instancetype)queryForPostsPublishWithBlogId:(NSString *)blogId
                                        postId:(NSString *)postId {
  NSString *methodName = @"blogger.posts.publish";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.postId = postId;
  query.expectedObjectClass = [GTLBloggerPost class];
  return query;
}

+ (instancetype)queryForPostsRevertWithBlogId:(NSString *)blogId
                                       postId:(NSString *)postId {
  NSString *methodName = @"blogger.posts.revert";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.postId = postId;
  query.expectedObjectClass = [GTLBloggerPost class];
  return query;
}

+ (instancetype)queryForPostsSearchWithBlogId:(NSString *)blogId
                                            q:(NSString *)q {
  NSString *methodName = @"blogger.posts.search";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.q = q;
  query.expectedObjectClass = [GTLBloggerPostList class];
  return query;
}

+ (instancetype)queryForPostsUpdateWithObject:(GTLBloggerPost *)object
                                       blogId:(NSString *)blogId
                                       postId:(NSString *)postId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"blogger.posts.update";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.blogId = blogId;
  query.postId = postId;
  query.expectedObjectClass = [GTLBloggerPost class];
  return query;
}

#pragma mark -
#pragma mark "postUserInfos" methods
// These create a GTLQueryBlogger object.

+ (instancetype)queryForPostUserInfosGetWithUserId:(NSString *)userId
                                            blogId:(NSString *)blogId
                                            postId:(NSString *)postId {
  NSString *methodName = @"blogger.postUserInfos.get";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.blogId = blogId;
  query.postId = postId;
  query.expectedObjectClass = [GTLBloggerPostUserInfo class];
  return query;
}

+ (instancetype)queryForPostUserInfosListWithUserId:(NSString *)userId
                                             blogId:(NSString *)blogId {
  NSString *methodName = @"blogger.postUserInfos.list";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.blogId = blogId;
  query.expectedObjectClass = [GTLBloggerPostUserInfosList class];
  return query;
}

#pragma mark -
#pragma mark "users" methods
// These create a GTLQueryBlogger object.

+ (instancetype)queryForUsersGetWithUserId:(NSString *)userId {
  NSString *methodName = @"blogger.users.get";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLBloggerUser class];
  return query;
}

@end
