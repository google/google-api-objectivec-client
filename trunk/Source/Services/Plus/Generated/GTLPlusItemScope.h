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
//  GTLPlusItemScope.h
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
//   GTLPlusItemScope (0 custom class methods, 55 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLPlusItemScope;

// ----------------------------------------------------------------------------
//
//   GTLPlusItemScope
//

@interface GTLPlusItemScope : GTLObject

// The subject matter of the content.
@property (nonatomic, retain) GTLPlusItemScope *about;

// An additional name for a Person, can be used for a middle name.
@property (nonatomic, retain) NSArray *additionalName;  // of NSString

// Postal address.
@property (nonatomic, retain) GTLPlusItemScope *address;

// Address country.
@property (nonatomic, copy) NSString *addressCountry;

// Address locality.
@property (nonatomic, copy) NSString *addressLocality;

// Address region.
@property (nonatomic, copy) NSString *addressRegion;

// The encoding.
@property (nonatomic, retain) NSArray *associatedMedia;  // of GTLPlusItemScope

// Number of attendees.
@property (nonatomic, retain) NSNumber *attendeeCount;  // intValue

// A person attending the event.
@property (nonatomic, retain) NSArray *attendees;  // of GTLPlusItemScope

// From http://schema.org/MusicRecording, the audio file.
@property (nonatomic, retain) GTLPlusItemScope *audio;

// The person or persons who created this result. In the example of restaurant
// reviews, this might be the reviewer's name.
@property (nonatomic, retain) NSArray *author;  // of GTLPlusItemScope

// Best possible rating value that a result might obtain. This property defines
// the upper bound for the ratingValue. For example, you might have a 5 star
// rating scale, you would provide 5 as the value for this property.
@property (nonatomic, copy) NSString *bestRating;

// Date of birth.
@property (nonatomic, copy) NSString *birthDate;

// From http://schema.org/MusicRecording, the artist that performed this
// recording.
@property (nonatomic, retain) GTLPlusItemScope *byArtist;

// The caption for this object.
@property (nonatomic, copy) NSString *caption;

// File size in (mega/kilo) bytes.
@property (nonatomic, copy) NSString *contentSize;

// Actual bytes of the media object, for example the image file or video file.
@property (nonatomic, copy) NSString *contentUrl;

// A list of contributors to this result.
@property (nonatomic, retain) NSArray *contributor;  // of GTLPlusItemScope

// The date the result was created such as the date that a review was first
// created.
@property (nonatomic, copy) NSString *dateCreated;

// The date the result was last modified such as the date that a review was last
// edited.
@property (nonatomic, copy) NSString *dateModified;

// The initial date that the result was published. For example, a user writes a
// comment on a blog, which has a result.dateCreated of when they submit it. If
// the blog users comment moderation, the result.datePublished value would match
// the date when the owner approved the message.
@property (nonatomic, copy) NSString *datePublished;

// The string that describes the content of the result.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// The duration of the item (movie, audio recording, event, etc.) in ISO 8601
// date format.
@property (nonatomic, copy) NSString *duration;

// A URL pointing to a player for a specific video. In general, this is the
// information in the src element of an embed tag and should not be the same as
// the content of the loc tag.
@property (nonatomic, copy) NSString *embedUrl;

// The end date and time of the event (in ISO 8601 date format).
@property (nonatomic, copy) NSString *endDate;

// Family name. This property can be used with givenName instead of the name
// property.
@property (nonatomic, copy) NSString *familyName;

// Gender of the person.
@property (nonatomic, copy) NSString *gender;

// Geo coordinates.
@property (nonatomic, retain) GTLPlusItemScope *geo;

// Given name. This property can be used with familyName instead of the name
// property.
@property (nonatomic, copy) NSString *givenName;

// The height of the media object.
@property (nonatomic, copy) NSString *height;

// An identifier for the object. Your app can choose how to identify objects.
// The object.id is required if you are writing an action that does not have a
// corresponding web page or object.url property.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// A URL to the image that represents this result. For example, if a user writes
// a review of a restaurant and attaches a photo of their meal, you might use
// that photo as the result.image.
@property (nonatomic, copy) NSString *image;

// From http://schema.org/MusicRecording, which album a song is in.
@property (nonatomic, retain) GTLPlusItemScope *inAlbum;

// Identifies this resource as an itemScope.
@property (nonatomic, copy) NSString *kind;

// Latitude.
@property (nonatomic, retain) NSNumber *latitude;  // doubleValue

// The location of the event or organization.
@property (nonatomic, retain) GTLPlusItemScope *location;

// Longitude.
@property (nonatomic, retain) NSNumber *longitude;  // doubleValue

// The name of the result. In the example of a restaurant review, this might be
// the summary the user gave their review such as "Great ambiance, but
// overpriced."
@property (nonatomic, copy) NSString *name;

// Property of http://schema.org/TVEpisode indicating which series the episode
// belongs to.
@property (nonatomic, retain) GTLPlusItemScope *partOfTVSeries;

// The main performer or performers of the event-for example, a presenter,
// musician, or actor.
@property (nonatomic, retain) NSArray *performers;  // of GTLPlusItemScope

// Player type that is required. For example: Flash or Silverlight.
@property (nonatomic, copy) NSString *playerType;

// Postal code.
@property (nonatomic, copy) NSString *postalCode;

// Post office box number.
@property (nonatomic, copy) NSString *postOfficeBoxNumber;

// Rating value.
@property (nonatomic, copy) NSString *ratingValue;

// Review rating.
@property (nonatomic, retain) GTLPlusItemScope *reviewRating;

// The start date and time of the event (in ISO 8601 date format).
@property (nonatomic, copy) NSString *startDate;

// Street address.
@property (nonatomic, copy) NSString *streetAddress;

// The text that is the result of the app activity. For example, if a user
// leaves a review of a restaurant, this might be the text of the review.
@property (nonatomic, copy) NSString *text;

// Thumbnail image for an image or video.
@property (nonatomic, retain) GTLPlusItemScope *thumbnail;

// A URL to a thumbnail image that represents this result.
@property (nonatomic, copy) NSString *thumbnailUrl;

// The exchange traded instrument associated with a Corporation object. The
// tickerSymbol is expressed as an exchange and an instrument name separated by
// a space character. For the exchange component of the tickerSymbol attribute,
// we recommend using the controlled vocabulary of Market Identifier Codes (MIC)
// specified in ISO15022.
@property (nonatomic, copy) NSString *tickerSymbol;

// The schema.org URL that best describes the referenced object and matches the
// type of moment.
@property (nonatomic, copy) NSString *type;

// The URL that points to the result object. For example, a permalink directly
// to a restaurant reviewer's comment.
@property (nonatomic, copy) NSString *url;

// The width of the media object.
@property (nonatomic, copy) NSString *width;

// Worst possible rating value that a result might obtain. This property defines
// the lower bound for the ratingValue.
@property (nonatomic, copy) NSString *worstRating;

@end
