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
//  GTLBloggerBlog.h
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
//   GTLBloggerBlog (0 custom class methods, 13 custom properties)
//   GTLBloggerBlogLocale (0 custom class methods, 3 custom properties)
//   GTLBloggerBlogPages (0 custom class methods, 2 custom properties)
//   GTLBloggerBlogPosts (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBloggerBlogLocale;
@class GTLBloggerBlogPages;
@class GTLBloggerBlogPosts;
@class GTLBloggerPost;

// ----------------------------------------------------------------------------
//
//   GTLBloggerBlog
//

@interface GTLBloggerBlog : GTLObject

// The JSON custom meta-data for the Blog
@property (nonatomic, copy) NSString *customMetaData;

// The description of this blog. This is displayed underneath the title.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// The identifier for this resource.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The kind of this entry. Always blogger#blog
@property (nonatomic, copy) NSString *kind;

// The locale this Blog is set to.
@property (nonatomic, retain) GTLBloggerBlogLocale *locale;

// The name of this blog. This is displayed as the title.
@property (nonatomic, copy) NSString *name;

// The container of pages in this blog.
@property (nonatomic, retain) GTLBloggerBlogPages *pages;

// The container of posts in this blog.
@property (nonatomic, retain) GTLBloggerBlogPosts *posts;

// RFC 3339 date-time when this blog was published.
@property (nonatomic, retain) GTLDateTime *published;

// The API REST URL to fetch this resource from.
@property (nonatomic, copy) NSString *selfLink;

// The status of the blog.
@property (nonatomic, copy) NSString *status;

// RFC 3339 date-time when this blog was last updated.
@property (nonatomic, retain) GTLDateTime *updated;

// The URL where this blog is published.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerBlogLocale
//

@interface GTLBloggerBlogLocale : GTLObject

// The country this blog's locale is set to.
@property (nonatomic, copy) NSString *country;

// The language this blog is authored in.
@property (nonatomic, copy) NSString *language;

// The language variant this blog is authored in.
@property (nonatomic, copy) NSString *variant;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerBlogPages
//

@interface GTLBloggerBlogPages : GTLObject

// The URL of the container for pages in this blog.
@property (nonatomic, copy) NSString *selfLink;

// The count of pages in this blog.
@property (nonatomic, retain) NSNumber *totalItems;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerBlogPosts
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLBloggerBlogPosts : GTLCollectionObject

// The List of Posts for this Blog.
@property (nonatomic, retain) NSArray *items;  // of GTLBloggerPost

// The URL of the container for posts in this blog.
@property (nonatomic, copy) NSString *selfLink;

// The count of posts in this blog.
@property (nonatomic, retain) NSNumber *totalItems;  // intValue

@end
