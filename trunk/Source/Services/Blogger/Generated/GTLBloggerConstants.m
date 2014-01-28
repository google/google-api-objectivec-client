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
//  GTLBloggerConstants.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Blogger API (blogger/v3)
// Description:
//   API for access to the data within Blogger.
// Documentation:
//   https://developers.google.com/blogger/docs/3.0/getting_started

#import "GTLBloggerConstants.h"

// Authorization scope
NSString * const kGTLAuthScopeBlogger         = @"https://www.googleapis.com/auth/blogger";
NSString * const kGTLAuthScopeBloggerReadonly = @"https://www.googleapis.com/auth/blogger.readonly";

// OrderBy
NSString * const kGTLBloggerOrderByPublished = @"published";
NSString * const kGTLBloggerOrderByUpdated   = @"updated";

// Range
NSString * const kGTLBloggerRangeAll     = @"all";
NSString * const kGTLBloggerRangeX30days = @"30DAYS";
NSString * const kGTLBloggerRangeX7days  = @"7DAYS";

// Role
NSString * const kGTLBloggerRoleAdmin  = @"ADMIN";
NSString * const kGTLBloggerRoleAuthor = @"AUTHOR";
NSString * const kGTLBloggerRoleReader = @"READER";

// Status
NSString * const kGTLBloggerStatusDraft     = @"draft";
NSString * const kGTLBloggerStatusEmptied   = @"emptied";
NSString * const kGTLBloggerStatusLive      = @"live";
NSString * const kGTLBloggerStatusPending   = @"pending";
NSString * const kGTLBloggerStatusScheduled = @"scheduled";
NSString * const kGTLBloggerStatusSpam      = @"spam";

// View
NSString * const kGTLBloggerViewAdmin  = @"ADMIN";
NSString * const kGTLBloggerViewAuthor = @"AUTHOR";
NSString * const kGTLBloggerViewReader = @"READER";
