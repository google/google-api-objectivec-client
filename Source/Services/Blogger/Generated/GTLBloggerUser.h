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
//  GTLBloggerUser.h
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
//   GTLBloggerUser (0 custom class methods, 9 custom properties)
//   GTLBloggerUserBlogs (0 custom class methods, 1 custom properties)
//   GTLBloggerUserLocale (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBloggerUserBlogs;
@class GTLBloggerUserLocale;

// ----------------------------------------------------------------------------
//
//   GTLBloggerUser
//

@interface GTLBloggerUser : GTLObject

// Profile summary information.
@property (retain) NSString *about;

// The container of blogs for this user.
@property (retain) GTLBloggerUserBlogs *blogs;

// The timestamp of when this profile was created, in seconds since epoch.
@property (retain) GTLDateTime *created;

// The display name.
@property (retain) NSString *displayName;

// The identifier for this User.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSNumber *identifier;  // longLongValue

// The kind of this entity. Always blogger#user
@property (retain) NSString *kind;

// This user's locale
@property (retain) GTLBloggerUserLocale *locale;

// The API REST URL to fetch this resource from.
@property (retain) NSString *selfLink;

// The user's profile page.
@property (retain) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerUserBlogs
//

@interface GTLBloggerUserBlogs : GTLObject

// The URL of the Blogs for this user.
@property (retain) NSString *selfLink;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerUserLocale
//

@interface GTLBloggerUserLocale : GTLObject

// The user's country setting.
@property (retain) NSString *country;

// The user's language setting.
@property (retain) NSString *language;

// The user's language variant setting.
@property (retain) NSString *variant;

@end
