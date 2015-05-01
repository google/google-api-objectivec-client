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
//  GTLBloggerPost.h
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
//   GTLBloggerPost (0 custom class methods, 19 custom properties)
//   GTLBloggerPostAuthor (0 custom class methods, 4 custom properties)
//   GTLBloggerPostBlog (0 custom class methods, 1 custom properties)
//   GTLBloggerPostImagesItem (0 custom class methods, 1 custom properties)
//   GTLBloggerPostLocation (0 custom class methods, 4 custom properties)
//   GTLBloggerPostReplies (0 custom class methods, 3 custom properties)
//   GTLBloggerPostAuthorImage (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBloggerComment;
@class GTLBloggerPostAuthor;
@class GTLBloggerPostAuthorImage;
@class GTLBloggerPostBlog;
@class GTLBloggerPostImagesItem;
@class GTLBloggerPostLocation;
@class GTLBloggerPostReplies;

// ----------------------------------------------------------------------------
//
//   GTLBloggerPost
//

@interface GTLBloggerPost : GTLObject

// The author of this Post.
@property (nonatomic, retain) GTLBloggerPostAuthor *author;

// Data about the blog containing this Post.
@property (nonatomic, retain) GTLBloggerPostBlog *blog;

// The content of the Post. May contain HTML markup.
@property (nonatomic, copy) NSString *content;

// The JSON meta-data for the Post.
@property (nonatomic, copy) NSString *customMetaData;

// Etag of the resource.
@property (nonatomic, copy) NSString *ETag;

// The identifier of this Post.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Display image for the Post.
@property (nonatomic, retain) NSArray *images;  // of GTLBloggerPostImagesItem

// The kind of this entity. Always blogger#post
@property (nonatomic, copy) NSString *kind;

// The list of labels this Post was tagged with.
@property (nonatomic, retain) NSArray *labels;  // of NSString

// The location for geotagged posts.
@property (nonatomic, retain) GTLBloggerPostLocation *location;

// RFC 3339 date-time when this Post was published.
@property (nonatomic, retain) GTLDateTime *published;

// Comment control and display setting for readers of this post.
@property (nonatomic, copy) NSString *readerComments;

// The container of comments on this Post.
@property (nonatomic, retain) GTLBloggerPostReplies *replies;

// The API REST URL to fetch this resource from.
@property (nonatomic, copy) NSString *selfLink;

// Status of the post. Only set for admin-level requests
@property (nonatomic, copy) NSString *status;

// The title of the Post.
@property (nonatomic, copy) NSString *title;

// The title link URL, similar to atom's related link.
@property (nonatomic, copy) NSString *titleLink;

// RFC 3339 date-time when this Post was last updated.
@property (nonatomic, retain) GTLDateTime *updated;

// The URL where this Post is displayed.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerPostAuthor
//

@interface GTLBloggerPostAuthor : GTLObject

// The display name.
@property (nonatomic, copy) NSString *displayName;

// The identifier of the Post creator.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The Post author's avatar.
@property (nonatomic, retain) GTLBloggerPostAuthorImage *image;

// The URL of the Post creator's Profile page.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerPostBlog
//

@interface GTLBloggerPostBlog : GTLObject

// The identifier of the Blog that contains this Post.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerPostImagesItem
//

@interface GTLBloggerPostImagesItem : GTLObject
@property (nonatomic, copy) NSString *url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerPostLocation
//

@interface GTLBloggerPostLocation : GTLObject

// Location's latitude.
@property (nonatomic, retain) NSNumber *lat;  // doubleValue

// Location's longitude.
@property (nonatomic, retain) NSNumber *lng;  // doubleValue

// Location name.
@property (nonatomic, copy) NSString *name;

// Location's viewport span. Can be used when rendering a map preview.
@property (nonatomic, copy) NSString *span;

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerPostReplies
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLBloggerPostReplies : GTLCollectionObject

// The List of Comments for this Post.
@property (nonatomic, retain) NSArray *items;  // of GTLBloggerComment

// The URL of the comments on this post.
@property (nonatomic, copy) NSString *selfLink;

// The count of comments on this post.
@property (nonatomic, retain) NSNumber *totalItems;  // longLongValue

@end


// ----------------------------------------------------------------------------
//
//   GTLBloggerPostAuthorImage
//

@interface GTLBloggerPostAuthorImage : GTLObject

// The Post author's avatar URL.
@property (nonatomic, copy) NSString *url;

@end
