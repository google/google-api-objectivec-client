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
//   GTLYouTubeActivityContentDetailsPlaylistItem (0 custom class methods, 3 custom properties)
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

// The bulletin object contains details about a channel bulletin post. This
// object is only present if the snippet.type is bulletin.
@property (retain) GTLYouTubeActivityContentDetailsBulletin *bulletin;

// The comment object contains information about a resource that received a
// comment. This property is only present if the snippet.type is comment.
@property (retain) GTLYouTubeActivityContentDetailsComment *comment;

// The favorite object contains information about a video that was marked as a
// favorite video. This property is only present if the snippet.type is
// favorite.
@property (retain) GTLYouTubeActivityContentDetailsFavorite *favorite;

// The like object contains information about a resource that received a
// positive (like) rating. This property is only present if the snippet.type is
// like.
@property (retain) GTLYouTubeActivityContentDetailsLike *like;

// The playlistItem object contains information about a new playlist item. This
// property is only present if the snippet.type is playlistItem.
@property (retain) GTLYouTubeActivityContentDetailsPlaylistItem *playlistItem;

// The recommendation object contains information about a recommended resource.
// This property is only present if the snippet.type is recommendation.
@property (retain) GTLYouTubeActivityContentDetailsRecommendation *recommendation;

// The social object contains details about a social network post. This property
// is only present if the snippet.type is social.
@property (retain) GTLYouTubeActivityContentDetailsSocial *social;

// The subscription object contains information about a channel that a user
// subscribed to. This property is only present if the snippet.type is
// subscription.
@property (retain) GTLYouTubeActivityContentDetailsSubscription *subscription;

// The upload object contains information about the uploaded video. This
// property is only present if the snippet.type is upload.
@property (retain) GTLYouTubeActivityContentDetailsUpload *upload;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsBulletin
//

@interface GTLYouTubeActivityContentDetailsBulletin : GTLObject

// The resourceId object contains information that identifies the resource
// associated with a bulletin post.
@property (retain) GTLYouTubeResourceId *resourceId;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsComment
//

@interface GTLYouTubeActivityContentDetailsComment : GTLObject

// The resourceId object contains information that identifies the resource
// associated with the comment.
@property (retain) GTLYouTubeResourceId *resourceId;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsFavorite
//

@interface GTLYouTubeActivityContentDetailsFavorite : GTLObject

// The resourceId object contains information that identifies the resource that
// was marked as a favorite.
@property (retain) GTLYouTubeResourceId *resourceId;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsLike
//

@interface GTLYouTubeActivityContentDetailsLike : GTLObject

// The resourceId object contains information that identifies the rated
// resource.
@property (retain) GTLYouTubeResourceId *resourceId;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsPlaylistItem
//

@interface GTLYouTubeActivityContentDetailsPlaylistItem : GTLObject

// The value that YouTube uses to uniquely identify the playlist.
@property (copy) NSString *playlistId;

// ID of the item within the playlist.
@property (copy) NSString *playlistItemId;

// The resourceId object contains information about the resource that was added
// to the playlist.
@property (retain) GTLYouTubeResourceId *resourceId;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsRecommendation
//

@interface GTLYouTubeActivityContentDetailsRecommendation : GTLObject

// The reason that the resource is recommended to the user.
@property (copy) NSString *reason;

// The resourceId object contains information that identifies the recommended
// resource.
@property (retain) GTLYouTubeResourceId *resourceId;

// The seedResourceId object contains information about the resource that caused
// the recommendation.
@property (retain) GTLYouTubeResourceId *seedResourceId;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsSocial
//

@interface GTLYouTubeActivityContentDetailsSocial : GTLObject

// The author of the social network post.
@property (copy) NSString *author;

// An image of the post's author.
@property (copy) NSString *imageUrl;

// The URL of the social network post.
@property (copy) NSString *referenceUrl;

// The resourceId object encapsulates information that identifies the resource
// associated with a social network post.
@property (retain) GTLYouTubeResourceId *resourceId;

// The name of the social network.
@property (copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsSubscription
//

@interface GTLYouTubeActivityContentDetailsSubscription : GTLObject

// The resourceId object contains information that identifies the resource that
// the user subscribed to.
@property (retain) GTLYouTubeResourceId *resourceId;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsUpload
//

@interface GTLYouTubeActivityContentDetailsUpload : GTLObject

// The ID that YouTube uses to uniquely identify the uploaded video.
@property (copy) NSString *videoId;

@end
