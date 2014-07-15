/* Copyright (c) 2014 Google Inc.
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
//  GTLBloggerConstants.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Blogger API (blogger/v3)
// Description:
//   API for access to the data within Blogger.
// Documentation:
//   https://developers.google.com/blogger/docs/3.0/getting_started

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// Manage your Blogger account
GTL_EXTERN NSString * const kGTLAuthScopeBlogger;          // "https://www.googleapis.com/auth/blogger"
// View your Blogger account
GTL_EXTERN NSString * const kGTLAuthScopeBloggerReadonly;  // "https://www.googleapis.com/auth/blogger.readonly"

// GTLQueryBlogger - OrderBy
GTL_EXTERN NSString * const kGTLBloggerOrderByPublished;  // "published"
GTL_EXTERN NSString * const kGTLBloggerOrderByUpdated;    // "updated"

// GTLQueryBlogger - Range
GTL_EXTERN NSString * const kGTLBloggerRangeAll;      // "all"
GTL_EXTERN NSString * const kGTLBloggerRangeX30days;  // "30DAYS"
GTL_EXTERN NSString * const kGTLBloggerRangeX7days;   // "7DAYS"

// GTLQueryBlogger - Role
GTL_EXTERN NSString * const kGTLBloggerRoleAdmin;   // "ADMIN"
GTL_EXTERN NSString * const kGTLBloggerRoleAuthor;  // "AUTHOR"
GTL_EXTERN NSString * const kGTLBloggerRoleReader;  // "READER"

// GTLQueryBlogger - Status
GTL_EXTERN NSString * const kGTLBloggerStatusDeleted;    // "DELETED"
GTL_EXTERN NSString * const kGTLBloggerStatusDraft;      // "draft"
GTL_EXTERN NSString * const kGTLBloggerStatusEmptied;    // "emptied"
GTL_EXTERN NSString * const kGTLBloggerStatusLive;       // "live"
GTL_EXTERN NSString * const kGTLBloggerStatusPending;    // "pending"
GTL_EXTERN NSString * const kGTLBloggerStatusScheduled;  // "scheduled"
GTL_EXTERN NSString * const kGTLBloggerStatusSpam;       // "spam"

// GTLQueryBlogger - View
GTL_EXTERN NSString * const kGTLBloggerViewAdmin;   // "ADMIN"
GTL_EXTERN NSString * const kGTLBloggerViewAuthor;  // "AUTHOR"
GTL_EXTERN NSString * const kGTLBloggerViewReader;  // "READER"
