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
//  GTLPlusDomainsActivity.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google+ Domains API (plusDomains/v1)
// Description:
//   The Google+ API enables developers to build on top of the Google+ platform.
// Documentation:
//   https://developers.google.com/+/domains/
// Classes:
//   GTLPlusDomainsActivity (0 custom class methods, 20 custom properties)
//   GTLPlusDomainsActivityActor (0 custom class methods, 5 custom properties)
//   GTLPlusDomainsActivityObject (0 custom class methods, 11 custom properties)
//   GTLPlusDomainsActivityProvider (0 custom class methods, 1 custom properties)
//   GTLPlusDomainsActivityActorImage (0 custom class methods, 1 custom properties)
//   GTLPlusDomainsActivityActorName (0 custom class methods, 2 custom properties)
//   GTLPlusDomainsActivityObjectActor (0 custom class methods, 4 custom properties)
//   GTLPlusDomainsActivityObjectAttachmentsItem (0 custom class methods, 10 custom properties)
//   GTLPlusDomainsActivityObjectPlusoners (0 custom class methods, 2 custom properties)
//   GTLPlusDomainsActivityObjectReplies (0 custom class methods, 2 custom properties)
//   GTLPlusDomainsActivityObjectResharers (0 custom class methods, 2 custom properties)
//   GTLPlusDomainsActivityObjectStatusForViewer (0 custom class methods, 5 custom properties)
//   GTLPlusDomainsActivityObjectActorImage (0 custom class methods, 1 custom properties)
//   GTLPlusDomainsActivityObjectAttachmentsItemEmbed (0 custom class methods, 2 custom properties)
//   GTLPlusDomainsActivityObjectAttachmentsItemFullImage (0 custom class methods, 4 custom properties)
//   GTLPlusDomainsActivityObjectAttachmentsItemImage (0 custom class methods, 4 custom properties)
//   GTLPlusDomainsActivityObjectAttachmentsItemPreviewThumbnailsItem (0 custom class methods, 1 custom properties)
//   GTLPlusDomainsActivityObjectAttachmentsItemThumbnailsItem (0 custom class methods, 3 custom properties)
//   GTLPlusDomainsActivityObjectAttachmentsItemThumbnailsItemImage (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLPlusDomainsAcl;
@class GTLPlusDomainsActivityActor;
@class GTLPlusDomainsActivityActorImage;
@class GTLPlusDomainsActivityActorName;
@class GTLPlusDomainsActivityObject;
@class GTLPlusDomainsActivityObjectActor;
@class GTLPlusDomainsActivityObjectActorImage;
@class GTLPlusDomainsActivityObjectAttachmentsItem;
@class GTLPlusDomainsActivityObjectAttachmentsItemEmbed;
@class GTLPlusDomainsActivityObjectAttachmentsItemFullImage;
@class GTLPlusDomainsActivityObjectAttachmentsItemImage;
@class GTLPlusDomainsActivityObjectAttachmentsItemPreviewThumbnailsItem;
@class GTLPlusDomainsActivityObjectAttachmentsItemThumbnailsItem;
@class GTLPlusDomainsActivityObjectAttachmentsItemThumbnailsItemImage;
@class GTLPlusDomainsActivityObjectPlusoners;
@class GTLPlusDomainsActivityObjectReplies;
@class GTLPlusDomainsActivityObjectResharers;
@class GTLPlusDomainsActivityObjectStatusForViewer;
@class GTLPlusDomainsActivityProvider;
@class GTLPlusDomainsPlace;

// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivity
//

@interface GTLPlusDomainsActivity : GTLObject

// Identifies who has access to see this activity.
@property (nonatomic, retain) GTLPlusDomainsAcl *access;

// The person who performed this activity.
@property (nonatomic, retain) GTLPlusDomainsActivityActor *actor;

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
@property (nonatomic, retain) GTLPlusDomainsPlace *location;

// The object of this activity.
@property (nonatomic, retain) GTLPlusDomainsActivityObject *object;

// ID of the place where this activity occurred.
@property (nonatomic, copy) NSString *placeId;

// Name of the place where this activity occurred.
@property (nonatomic, copy) NSString *placeName;

// The service provider that initially published this activity.
@property (nonatomic, retain) GTLPlusDomainsActivityProvider *provider;

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
//   GTLPlusDomainsActivityActor
//

@interface GTLPlusDomainsActivityActor : GTLObject

// The name of the actor, suitable for display.
@property (nonatomic, copy) NSString *displayName;

// The ID of the actor's Person resource.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The image representation of the actor.
@property (nonatomic, retain) GTLPlusDomainsActivityActorImage *image;

// An object representation of the individual components of name.
@property (nonatomic, retain) GTLPlusDomainsActivityActorName *name;

// The link to the actor's Google profile.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObject
//

@interface GTLPlusDomainsActivityObject : GTLObject

// If this activity's object is itself another activity, such as when a person
// reshares an activity, this property specifies the original activity's actor.
@property (nonatomic, retain) GTLPlusDomainsActivityObjectActor *actor;

// The media objects attached to this activity.
@property (nonatomic, retain) NSArray *attachments;  // of GTLPlusDomainsActivityObjectAttachmentsItem

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
@property (nonatomic, retain) GTLPlusDomainsActivityObjectPlusoners *plusoners;

// Comments in reply to this activity.
@property (nonatomic, retain) GTLPlusDomainsActivityObjectReplies *replies;

// People who reshared this activity.
@property (nonatomic, retain) GTLPlusDomainsActivityObjectResharers *resharers;

// Status of the activity as seen by the viewer.
@property (nonatomic, retain) GTLPlusDomainsActivityObjectStatusForViewer *statusForViewer;

// The URL that points to the linked resource.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityProvider
//

@interface GTLPlusDomainsActivityProvider : GTLObject

// Name of the service provider.
@property (nonatomic, copy) NSString *title;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityActorImage
//

@interface GTLPlusDomainsActivityActorImage : GTLObject

// The URL of the actor's profile photo. To resize the image and crop it to a
// square, append the query string ?sz=x, where x is the dimension in pixels of
// each side.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityActorName
//

@interface GTLPlusDomainsActivityActorName : GTLObject

// The family name ("last name") of the actor.
@property (nonatomic, copy) NSString *familyName;

// The given name ("first name") of the actor.
@property (nonatomic, copy) NSString *givenName;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectActor
//

@interface GTLPlusDomainsActivityObjectActor : GTLObject

// The original actor's name, which is suitable for display.
@property (nonatomic, copy) NSString *displayName;

// ID of the original actor.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The image representation of the original actor.
@property (nonatomic, retain) GTLPlusDomainsActivityObjectActorImage *image;

// A link to the original actor's Google profile.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectAttachmentsItem
//

@interface GTLPlusDomainsActivityObjectAttachmentsItem : GTLObject

// If the attachment is an article, this property contains a snippet of text
// from the article. It can also include descriptions for other types.
@property (nonatomic, copy) NSString *content;

// The title of the attachment, such as a photo caption or an article title.
@property (nonatomic, copy) NSString *displayName;

// If the attachment is a video, the embeddable link.
@property (nonatomic, retain) GTLPlusDomainsActivityObjectAttachmentsItemEmbed *embed;

// The full image URL for photo attachments.
@property (nonatomic, retain) GTLPlusDomainsActivityObjectAttachmentsItemFullImage *fullImage;

// The ID of the attachment.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The preview image for photos or videos.
@property (nonatomic, retain) GTLPlusDomainsActivityObjectAttachmentsItemImage *image;

// The type of media object. Possible values include, but are not limited to,
// the following values:
// - "photo" - A photo.
// - "album" - A photo album.
// - "video" - A video.
// - "article" - An article, specified by a link.
@property (nonatomic, copy) NSString *objectType;

// When previewing, these are the optional thumbnails for the post. When posting
// an article, choose one by setting the attachment.image.url property. If you
// don't choose one, one will be chosen for you.
@property (nonatomic, retain) NSArray *previewThumbnails;  // of GTLPlusDomainsActivityObjectAttachmentsItemPreviewThumbnailsItem

// If the attachment is an album, this property is a list of potential
// additional thumbnails from the album.
@property (nonatomic, retain) NSArray *thumbnails;  // of GTLPlusDomainsActivityObjectAttachmentsItemThumbnailsItem

// The link to the attachment, which should be of type text/html.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectPlusoners
//

@interface GTLPlusDomainsActivityObjectPlusoners : GTLObject

// The URL for the collection of people who +1'd this activity.
@property (nonatomic, copy) NSString *selfLink;

// Total number of people who +1'd this activity.
@property (nonatomic, retain) NSNumber *totalItems;  // unsignedIntValue

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectReplies
//

@interface GTLPlusDomainsActivityObjectReplies : GTLObject

// The URL for the collection of comments in reply to this activity.
@property (nonatomic, copy) NSString *selfLink;

// Total number of comments on this activity.
@property (nonatomic, retain) NSNumber *totalItems;  // unsignedIntValue

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectResharers
//

@interface GTLPlusDomainsActivityObjectResharers : GTLObject

// The URL for the collection of resharers.
@property (nonatomic, copy) NSString *selfLink;

// Total number of people who reshared this activity.
@property (nonatomic, retain) NSNumber *totalItems;  // unsignedIntValue

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectStatusForViewer
//

@interface GTLPlusDomainsActivityObjectStatusForViewer : GTLObject

// Whether the viewer can comment on the activity.
@property (nonatomic, retain) NSNumber *canComment;  // boolValue

// Whether the viewer can +1 the activity.
@property (nonatomic, retain) NSNumber *canPlusone;  // boolValue

// Whether the viewer can edit or delete the activity.
@property (nonatomic, retain) NSNumber *canUpdate;  // boolValue

// Whether the viewer has +1'd the activity.
@property (nonatomic, retain) NSNumber *isPlusOned;  // boolValue

// Whether reshares are disabled for the activity.
@property (nonatomic, retain) NSNumber *resharingDisabled;  // boolValue

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectActorImage
//

@interface GTLPlusDomainsActivityObjectActorImage : GTLObject

// A URL that points to a thumbnail photo of the original actor.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectAttachmentsItemEmbed
//

@interface GTLPlusDomainsActivityObjectAttachmentsItemEmbed : GTLObject

// Media type of the link.
@property (nonatomic, copy) NSString *type;

// URL of the link.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectAttachmentsItemFullImage
//

@interface GTLPlusDomainsActivityObjectAttachmentsItemFullImage : GTLObject

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
//   GTLPlusDomainsActivityObjectAttachmentsItemImage
//

@interface GTLPlusDomainsActivityObjectAttachmentsItemImage : GTLObject

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
//   GTLPlusDomainsActivityObjectAttachmentsItemPreviewThumbnailsItem
//

@interface GTLPlusDomainsActivityObjectAttachmentsItemPreviewThumbnailsItem : GTLObject

// URL of the thumbnail image.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectAttachmentsItemThumbnailsItem
//

@interface GTLPlusDomainsActivityObjectAttachmentsItemThumbnailsItem : GTLObject

// Potential name of the thumbnail.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// Image resource.
@property (nonatomic, retain) GTLPlusDomainsActivityObjectAttachmentsItemThumbnailsItemImage *image;

// URL of the webpage containing the image.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectAttachmentsItemThumbnailsItemImage
//

@interface GTLPlusDomainsActivityObjectAttachmentsItemThumbnailsItemImage : GTLObject

// The height, in pixels, of the linked resource.
@property (nonatomic, retain) NSNumber *height;  // unsignedIntValue

// Media type of the link.
@property (nonatomic, copy) NSString *type;

// Image url.
@property (nonatomic, copy) NSString *url;

// The width, in pixels, of the linked resource.
@property (nonatomic, retain) NSNumber *width;  // unsignedIntValue

@end
