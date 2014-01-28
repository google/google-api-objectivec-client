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
//  GTLPlusDomainsActivity.m
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

#import "GTLPlusDomainsActivity.h"

#import "GTLPlusDomainsAcl.h"
#import "GTLPlusDomainsPlace.h"

// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivity
//

@implementation GTLPlusDomainsActivity
@dynamic access, actor, address, annotation, crosspostSource, ETag, geocode,
         identifier, kind, location, object, placeId, placeName, provider,
         published, radius, title, updated, url, verb;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"etag", @"ETag",
      @"id", @"identifier",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"plus#activity"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityActor
//

@implementation GTLPlusDomainsActivityActor
@dynamic displayName, identifier, image, name, url;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObject
//

@implementation GTLPlusDomainsActivityObject
@dynamic actor, attachments, content, identifier, objectType, originalContent,
         plusoners, replies, resharers, statusForViewer, url;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLPlusDomainsActivityObjectAttachmentsItem class]
                                forKey:@"attachments"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityProvider
//

@implementation GTLPlusDomainsActivityProvider
@dynamic title;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityActorImage
//

@implementation GTLPlusDomainsActivityActorImage
@dynamic url;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityActorName
//

@implementation GTLPlusDomainsActivityActorName
@dynamic familyName, givenName;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectActor
//

@implementation GTLPlusDomainsActivityObjectActor
@dynamic displayName, identifier, image, url;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectAttachmentsItem
//

@implementation GTLPlusDomainsActivityObjectAttachmentsItem
@dynamic content, displayName, embed, fullImage, identifier, image, objectType,
         previewThumbnails, thumbnails, url;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLPlusDomainsActivityObjectAttachmentsItemPreviewThumbnailsItem class], @"previewThumbnails",
      [GTLPlusDomainsActivityObjectAttachmentsItemThumbnailsItem class], @"thumbnails",
      nil];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectPlusoners
//

@implementation GTLPlusDomainsActivityObjectPlusoners
@dynamic selfLink, totalItems;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectReplies
//

@implementation GTLPlusDomainsActivityObjectReplies
@dynamic selfLink, totalItems;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectResharers
//

@implementation GTLPlusDomainsActivityObjectResharers
@dynamic selfLink, totalItems;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectStatusForViewer
//

@implementation GTLPlusDomainsActivityObjectStatusForViewer
@dynamic canComment, canPlusone, canUpdate, isPlusOned, resharingDisabled;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectActorImage
//

@implementation GTLPlusDomainsActivityObjectActorImage
@dynamic url;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectAttachmentsItemEmbed
//

@implementation GTLPlusDomainsActivityObjectAttachmentsItemEmbed
@dynamic type, url;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectAttachmentsItemFullImage
//

@implementation GTLPlusDomainsActivityObjectAttachmentsItemFullImage
@dynamic height, type, url, width;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectAttachmentsItemImage
//

@implementation GTLPlusDomainsActivityObjectAttachmentsItemImage
@dynamic height, type, url, width;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectAttachmentsItemPreviewThumbnailsItem
//

@implementation GTLPlusDomainsActivityObjectAttachmentsItemPreviewThumbnailsItem
@dynamic url;
@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectAttachmentsItemThumbnailsItem
//

@implementation GTLPlusDomainsActivityObjectAttachmentsItemThumbnailsItem
@dynamic descriptionProperty, image, url;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"description"
                                forKey:@"descriptionProperty"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsActivityObjectAttachmentsItemThumbnailsItemImage
//

@implementation GTLPlusDomainsActivityObjectAttachmentsItemThumbnailsItemImage
@dynamic height, type, url, width;
@end
