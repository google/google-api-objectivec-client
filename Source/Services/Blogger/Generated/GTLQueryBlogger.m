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
//  GTLQueryBlogger.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Blogger API (blogger/v2)
// Description:
//   API for access to the data within Blogger.
// Documentation:
//   https://developers.google.com/blogger/docs/2.0/json/getting_started
// Classes:
//   GTLQueryBlogger (9 custom class methods, 10 custom properties)

#import "GTLQueryBlogger.h"

#import "GTLBloggerBlog.h"
#import "GTLBloggerBlogList.h"
#import "GTLBloggerComment.h"
#import "GTLBloggerCommentList.h"
#import "GTLBloggerPage.h"
#import "GTLBloggerPageList.h"
#import "GTLBloggerPost.h"
#import "GTLBloggerPostList.h"
#import "GTLBloggerUser.h"

@implementation GTLQueryBlogger

@dynamic blogId, commentId, fetchBodies, fields, maxResults, pageId, pageToken,
         postId, startDate, userId;

#pragma mark -
#pragma mark "blogs" methods
// These create a GTLQueryBlogger object.

+ (id)queryForBlogsGetWithBlogId:(NSString *)blogId {
  NSString *methodName = @"blogger.blogs.get";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.expectedObjectClass = [GTLBloggerBlog class];
  return query;
}

#pragma mark -
#pragma mark "comments" methods
// These create a GTLQueryBlogger object.

+ (id)queryForCommentsGetWithBlogId:(NSString *)blogId
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

+ (id)queryForCommentsListWithBlogId:(NSString *)blogId
                              postId:(NSString *)postId {
  NSString *methodName = @"blogger.comments.list";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.postId = postId;
  query.expectedObjectClass = [GTLBloggerCommentList class];
  return query;
}

#pragma mark -
#pragma mark "pages" methods
// These create a GTLQueryBlogger object.

+ (id)queryForPagesGetWithBlogId:(NSString *)blogId
                          pageId:(NSString *)pageId {
  NSString *methodName = @"blogger.pages.get";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.pageId = pageId;
  query.expectedObjectClass = [GTLBloggerPage class];
  return query;
}

+ (id)queryForPagesListWithBlogId:(NSString *)blogId {
  NSString *methodName = @"blogger.pages.list";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.expectedObjectClass = [GTLBloggerPageList class];
  return query;
}

#pragma mark -
#pragma mark "posts" methods
// These create a GTLQueryBlogger object.

+ (id)queryForPostsGetWithBlogId:(NSString *)blogId
                          postId:(NSString *)postId {
  NSString *methodName = @"blogger.posts.get";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.postId = postId;
  query.expectedObjectClass = [GTLBloggerPost class];
  return query;
}

+ (id)queryForPostsListWithBlogId:(NSString *)blogId {
  NSString *methodName = @"blogger.posts.list";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.blogId = blogId;
  query.expectedObjectClass = [GTLBloggerPostList class];
  return query;
}

#pragma mark -
#pragma mark "users.blogs" methods
// These create a GTLQueryBlogger object.

+ (id)queryForUsersBlogsListWithUserId:(NSString *)userId {
  NSString *methodName = @"blogger.users.blogs.list";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLBloggerBlogList class];
  return query;
}

#pragma mark -
#pragma mark "users" methods
// These create a GTLQueryBlogger object.

+ (id)queryForUsersGetWithUserId:(NSString *)userId {
  NSString *methodName = @"blogger.users.get";
  GTLQueryBlogger *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLBloggerUser class];
  return query;
}

@end
