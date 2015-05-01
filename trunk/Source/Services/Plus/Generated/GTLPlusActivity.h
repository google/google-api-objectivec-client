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
//  GTLPlusActivity.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google+ API (plus/v1)
// Description:
//   The Google+ API enables developers to build on top of the Google+ platform.
// Documentation:
//   https://developers.google.com/+/api/
// Classes:
//   GTLPlusActivity (0 custom class methods, 20 custom properties)
//   GTLPlusActivityActor (0 custom class methods, 5 custom properties)
//   GTLPlusActivityObject (0 custom class methods, 10 custom properties)
//   GTLPlusActivityProvider (0 custom class methods, 1 custom properties)
//   GTLPlusActivityActorImage (0 custom class methods, 1 custom properties)
//   GTLPlusActivityActorName (0 custom class methods, 2 custom properties)
//   GTLPlusActivityObjectActor (0 custom class methods, 4 custom properties)
//   GTLPlusActivityObjectAttachmentsItem (0 custom class methods, 9 custom properties)
//   GTLPlusActivityObjectPlusoners (0 custom class methods, 2 custom properties)
//   GTLPlusActivityObjectReplies (0 custom class methods, 2 custom properties)
//   GTLPlusActivityObjectResharers (0 custom class methods, 2 custom properties)
//   GTLPlusActivityObjectActorImage (0 custom class methods, 1 custom properties)
//   GTLPlusActivityObjectAttachmentsItemEmbed (0 custom class methods, 2 custom properties)
//   GTLPlusActivityObjectAttachmentsItemFullImage (0 custom class methods, 4 custom properties)
//   GTLPlusActivityObjectAttachmentsItemImage (0 custom class methods, 4 custom properties)
//   GTLPlusActivityObjectAttachmentsItemThumbnailsItem (0 custom class methods, 3 custom properties)
//   GTLPlusActivityObjectAttachmentsItemThumbnailsItemImage (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLPlusAcl;
@class GTLPlusActivityActor;
@class GTLPlusActivityActorImage;
@class GTLPlusActivityActorName;
@class GTLPlusActivityObject;
@class GTLPlusActivityObjectActor;
@class GTLPlusActivityObjectActorImage;
@class GTLPlusActivityObjectAttachmentsItem;
@class GTLPlusActivityObjectAttachmentsItemEmbed;
@class GTLPlusActivityObjectAttachmentsItemFullImage;
@class GTLPlusActivityObjectAttachmentsItemImage;
@class GTLPlusActivityObjectAttachmentsItemThumbnailsItem;
@class GTLPlusActivityObjectAttachmentsItemThumbnailsItemImage;
@class GTLPlusActivityObjectPlusoners;
@class GTLPlusActivityObjectReplies;
@class GTLPlusActivityObjectResharers;
@class GTLPlusActivityProvider;
@class GTLPlusPlace;

// ----------------------------------------------------------------------------
//
//   GTLPlusActivity
//

@interface GTLPlusActivity : GTLObject

// Identifies who has access to see this activity.
@property (nonatomic, retain) GTLPlusAcl *access;

// The person who performed this activity.
@property (nonatomic, retain) GTLPlusActivityActor *actor;

// Street address where this activity occurred.
@property (nonatomic, copy) NSString *address;

// Additional content added by the person who shared this activity, applicable
// only when resharing an activity.
@property (nonatomic, copy) NSString *annotation;

// If this activity is a crosspost from another system, this property specifies
// the ID of the original activity.
@property (nonatomic, copy) NSString *crosspostSource;

// ETag of this response for caching purposes.
@property (nonatomic, copy) NSString *ETag;

// Latitude and longitude where this activity occurred. Format is latitude
// followed by longitude, space separated.
@property (nonatomic, copy) NSString *geocode;

// The ID of this activity.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Identifies this resource as an activity. Value: "plus#activity".
@property (nonatomic, copy) NSString *kind;

// The location where this activity occurred.
@property (nonatomic, retain) GTLPlusPlace *location;

// The object of this activity.
@property (nonatomic, retain) GTLPlusActivityObject *object;

// ID of the place where this activity occurred.
@property (nonatomic, copy) NSString *placeId;

// Name of the place where this activity occurred.
@property (nonatomic, copy) NSString *placeName;

// The service provider that initially published this activity.
@property (nonatomic, retain) GTLPlusActivityProvider *provider;

// The time at which this activity was initially published. Formatted as an RFC
// 3339 timestamp.
@property (nonatomic, retain) GTLDateTime *published;

// Radius, in meters, of the region where this activity occurred, centered at
// the latitude and longitude identified in geocode.
@property (nonatomic, copy) NSString *radius;

// Title of this activity.
@property (nonatomic, copy) NSString *title;

// The time at which this activity was last updated. Formatted as an RFC 3339
// timestamp.
@property (nonatomic, retain) GTLDateTime *updated;

// The link to this activity.
@property (nonatomic, copy) NSString *url;

// This activity's verb, which indicates the action that was performed. Possible
// values include, but are not limited to, the following values:
// - "post" - Publish content to the stream.
// - "share" - Reshare an activity.
@property (nonatomic, copy) NSString *verb;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusActivityActor
//

@interface GTLPlusActivityActor : GTLObject

// The name of the actor, suitable for display.
@property (nonatomic, copy) NSString *displayName;

// The ID of the actor's Person resource.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The image representation of the actor.
@property (nonatomic, retain) GTLPlusActivityActorImage *image;

// An object representation of the individual components of name.
@property (nonatomic, retain) GTLPlusActivityActorName *name;

// The link to the actor's Google profile.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusActivityObject
//

@interface GTLPlusActivityObject : GTLObject

// If this activity's object is itself another activity, such as when a person
// reshares an activity, this property specifies the original activity's actor.
@property (nonatomic, retain) GTLPlusActivityObjectActor *actor;

// The media objects attached to this activity.
@property (nonatomic, retain) NSArray *attachments;  // of GTLPlusActivityObjectAttachmentsItem

// The HTML-formatted content, which is suitable for display.
@property (nonatomic, copy) NSString *content;

// The ID of the object. When resharing an activity, this is the ID of the
// activity that is being reshared.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The type of the object. Possible values include, but are not limited to, the
// following values:
// - "note" - Textual content.
// - "activity" - A Google+ activity.
@property (nonatomic, copy) NSString *objectType;

// The content (text) as provided by the author, which is stored without any
// HTML formatting. When creating or updating an activity, this value must be
// supplied as plain text in the request.
@property (nonatomic, copy) NSString *originalContent;

// People who +1'd this activity.
@property (nonatomic, retain) GTLPlusActivityObjectPlusoners *plusoners;

// Comments in reply to this activity.
@property (nonatomic, retain) GTLPlusActivityObjectReplies *replies;

// People who reshared this activity.
@property (nonatomic, retain) GTLPlusActivityObjectResharers *resharers;

// The URL that points to the linked resource.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusActivityProvider
//

@interface GTLPlusActivityProvider : GTLObject

// Name of the service provider.
@property (nonatomic, copy) NSString *title;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusActivityActorImage
//

@interface GTLPlusActivityActorImage : GTLObject

// The URL of the actor's profile photo. To resize the image and crop it to a
// square, append the query string ?sz=x, where x is the dimension in pixels of
// each side.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusActivityActorName
//

@interface GTLPlusActivityActorName : GTLObject

// The family name ("last name") of the actor.
@property (nonatomic, copy) NSString *familyName;

// The given name ("first name") of the actor.
@property (nonatomic, copy) NSString *givenName;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusActivityObjectActor
//

@interface GTLPlusActivityObjectActor : GTLObject

// The original actor's name, which is suitable for display.
@property (nonatomic, copy) NSString *displayName;

// ID of the original actor.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The image representation of the original actor.
@property (nonatomic, retain) GTLPlusActivityObjectActorImage *image;

// A link to the original actor's Google profile.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusActivityObjectAttachmentsItem
//

@interface GTLPlusActivityObjectAttachmentsItem : GTLObject

// If the attachment is an article, this property contains a snippet of text
// from the article. It can also include descriptions for other types.
@property (nonatomic, copy) NSString *content;

// The title of the attachment, such as a photo caption or an article title.
@property (nonatomic, copy) NSString *displayName;

// If the attachment is a video, the embeddable link.
@property (nonatomic, retain) GTLPlusActivityObjectAttachmentsItemEmbed *embed;

// The full image URL for photo attachments.
@property (nonatomic, retain) GTLPlusActivityObjectAttachmentsItemFullImage *fullImage;

// The ID of the attachment.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The preview image for photos or videos.
@property (nonatomic, retain) GTLPlusActivityObjectAttachmentsItemImage *image;

// The type of media object. Possible values include, but are not limited to,
// the following values:
// - "photo" - A photo.
// - "album" - A photo album.
// - "video" - A video.
// - "article" - An article, specified by a link.
@property (nonatomic, copy) NSString *objectType;

// If the attachment is an album, this property is a list of potential
// additional thumbnails from the album.
@property (nonatomic, retain) NSArray *thumbnails;  // of GTLPlusActivityObjectAttachmentsItemThumbnailsItem

// The link to the attachment, which should be of type text/html.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusActivityObjectPlusoners
//

@interface GTLPlusActivityObjectPlusoners : GTLObject

// The URL for the collection of people who +1'd this activity.
@property (nonatomic, copy) NSString *selfLink;

// Total number of people who +1'd this activity.
@property (nonatomic, retain) NSNumber *totalItems;  // unsignedIntValue

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusActivityObjectReplies
//

@interface GTLPlusActivityObjectReplies : GTLObject

// The URL for the collection of comments in reply to this activity.
@property (nonatomic, copy) NSString *selfLink;

// Total number of comments on this activity.
@property (nonatomic, retain) NSNumber *totalItems;  // unsignedIntValue

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusActivityObjectResharers
//

@interface GTLPlusActivityObjectResharers : GTLObject

// The URL for the collection of resharers.
@property (nonatomic, copy) NSString *selfLink;

// Total number of people who reshared this activity.
@property (nonatomic, retain) NSNumber *totalItems;  // unsignedIntValue

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusActivityObjectActorImage
//

@interface GTLPlusActivityObjectActorImage : GTLObject

// A URL that points to a thumbnail photo of the original actor.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusActivityObjectAttachmentsItemEmbed
//

@interface GTLPlusActivityObjectAttachmentsItemEmbed : GTLObject

// Media type of the link.
@property (nonatomic, copy) NSString *type;

// URL of the link.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusActivityObjectAttachmentsItemFullImage
//

@interface GTLPlusActivityObjectAttachmentsItemFullImage : GTLObject

// The height, in pixels, of the linked resource.
@property (nonatomic, retain) NSNumber *height;  // unsignedIntValue

// Media type of the link.
@property (nonatomic, copy) NSString *type;

// URL of the image.
@property (nonatomic, copy) NSString *url;

// The width, in pixels, of the linked resource.
@property (nonatomic, retain) NSNumber *width;  // unsignedIntValue

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusActivityObjectAttachmentsItemImage
//

@interface GTLPlusActivityObjectAttachmentsItemImage : GTLObject

// The height, in pixels, of the linked resource.
@property (nonatomic, retain) NSNumber *height;  // unsignedIntValue

// Media type of the link.
@property (nonatomic, copy) NSString *type;

// Image URL.
@property (nonatomic, copy) NSString *url;

// The width, in pixels, of the linked resource.
@property (nonatomic, retain) NSNumber *width;  // unsignedIntValue

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusActivityObjectAttachmentsItemThumbnailsItem
//

@interface GTLPlusActivityObjectAttachmentsItemThumbnailsItem : GTLObject

// Potential name of the thumbnail.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// Image resource.
@property (nonatomic, retain) GTLPlusActivityObjectAttachmentsItemThumbnailsItemImage *image;

// URL of the webpage containing the image.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusActivityObjectAttachmentsItemThumbnailsItemImage
//

@interface GTLPlusActivityObjectAttachmentsItemThumbnailsItemImage : GTLObject

// The height, in pixels, of the linked resource.
@property (nonatomic, retain) NSNumber *height;  // unsignedIntValue

// Media type of the link.
@property (nonatomic, copy) NSString *type;

// Image url.
@property (nonatomic, copy) NSString *url;

// The width, in pixels, of the linked resource.
@property (nonatomic, retain) NSNumber *width;  // unsignedIntValue

@end
