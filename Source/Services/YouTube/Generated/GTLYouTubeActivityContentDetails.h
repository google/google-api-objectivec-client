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
//  GTLYouTubeActivityContentDetails.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   YouTube API (youtube/v3)
// Description:
//   Programmatic access to YouTube features.
// Documentation:
//   https://developers.google.com/youtube
// Classes:
//   GTLYouTubeActivityContentDetails (0 custom class methods, 9 custom properties)
//   GTLYouTubeActivityContentDetailsBulletin (0 custom class methods, 1 custom properties)
//   GTLYouTubeActivityContentDetailsComment (0 custom class methods, 1 custom properties)
//   GTLYouTubeActivityContentDetailsFavorite (0 custom class methods, 1 custom properties)
//   GTLYouTubeActivityContentDetailsLike (0 custom class methods, 1 custom properties)
//   GTLYouTubeActivityContentDetailsPlaylistItem (0 custom class methods, 2 custom properties)
//   GTLYouTubeActivityContentDetailsRecommendation (0 custom class methods, 3 custom properties)
//   GTLYouTubeActivityContentDetailsSocial (0 custom class methods, 5 custom properties)
//   GTLYouTubeActivityContentDetailsSubscription (0 custom class methods, 1 custom properties)
//   GTLYouTubeActivityContentDetailsUpload (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeActivityContentDetailsBulletin;
@class GTLYouTubeActivityContentDetailsComment;
@class GTLYouTubeActivityContentDetailsFavorite;
@class GTLYouTubeActivityContentDetailsLike;
@class GTLYouTubeActivityContentDetailsPlaylistItem;
@class GTLYouTubeActivityContentDetailsRecommendation;
@class GTLYouTubeActivityContentDetailsSocial;
@class GTLYouTubeActivityContentDetailsSubscription;
@class GTLYouTubeActivityContentDetailsUpload;
@class GTLYouTubeResourceId;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetails
//

// Details about the content of an activity: the video that was shared, the
// channel that was subscribed to, etc.

@interface GTLYouTubeActivityContentDetails : GTLObject

// Only present if the type is "bulletin".
@property (retain) GTLYouTubeActivityContentDetailsBulletin *bulletin;

// Only present if the type is "comment".
@property (retain) GTLYouTubeActivityContentDetailsComment *comment;

// Only present if the type is "favorite".
@property (retain) GTLYouTubeActivityContentDetailsFavorite *favorite;

// Only present if the type is "like".
@property (retain) GTLYouTubeActivityContentDetailsLike *like;

// Only present if the type is "playlistItem".
@property (retain) GTLYouTubeActivityContentDetailsPlaylistItem *playlistItem;

// Only set if the type is "recommendation".
@property (retain) GTLYouTubeActivityContentDetailsRecommendation *recommendation;

// Only present if the type is "social".
@property (retain) GTLYouTubeActivityContentDetailsSocial *social;

// Only present if the type is "subscription".
@property (retain) GTLYouTubeActivityContentDetailsSubscription *subscription;

// Only present if the type is "upload".
@property (retain) GTLYouTubeActivityContentDetailsUpload *upload;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsBulletin
//

@interface GTLYouTubeActivityContentDetailsBulletin : GTLObject

// ID of the resource this bulletin is about.
@property (retain) GTLYouTubeResourceId *resourceId;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsComment
//

@interface GTLYouTubeActivityContentDetailsComment : GTLObject

// ID of the commented resource.
@property (retain) GTLYouTubeResourceId *resourceId;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsFavorite
//

@interface GTLYouTubeActivityContentDetailsFavorite : GTLObject

// ID of the favorited resource.
@property (retain) GTLYouTubeResourceId *resourceId;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsLike
//

@interface GTLYouTubeActivityContentDetailsLike : GTLObject

// ID of the rated resource.
@property (retain) GTLYouTubeResourceId *resourceId;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsPlaylistItem
//

@interface GTLYouTubeActivityContentDetailsPlaylistItem : GTLObject

// ID of the playlist the resource was added to.
@property (copy) NSString *playlistId;

// ID of the resource added to the playlist.
@property (retain) GTLYouTubeResourceId *resourceId;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsRecommendation
//

@interface GTLYouTubeActivityContentDetailsRecommendation : GTLObject

// Reason for which the video was recommended.
@property (copy) NSString *reason;

// ID of the recommended resource.
@property (retain) GTLYouTubeResourceId *resourceId;

// ID of the video that caused this recommendation.
@property (retain) GTLYouTubeResourceId *seedResourceId;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsSocial
//

@interface GTLYouTubeActivityContentDetailsSocial : GTLObject

// Author of the post.
@property (copy) NSString *author;

// Image of the post author.
@property (copy) NSString *imageUrl;

// Url of the social post.
@property (copy) NSString *referenceUrl;

// ID of the resource this social activity is about.
@property (retain) GTLYouTubeResourceId *resourceId;

// Type of the social network.
@property (copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsSubscription
//

@interface GTLYouTubeActivityContentDetailsSubscription : GTLObject

// ID of the resource subscribed to.
@property (retain) GTLYouTubeResourceId *resourceId;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsUpload
//

@interface GTLYouTubeActivityContentDetailsUpload : GTLObject

// ID of the uploaded video.
@property (copy) NSString *videoId;

@end
