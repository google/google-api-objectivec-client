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
//  GTLYouTubeActivityContentDetails.m
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

#import "GTLYouTubeActivityContentDetails.h"

#import "GTLYouTubeResourceId.h"

// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetails
//

@implementation GTLYouTubeActivityContentDetails
@dynamic bulletin, comment, favorite, like, playlistItem, recommendation,
         social, subscription, upload;
@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsBulletin
//

@implementation GTLYouTubeActivityContentDetailsBulletin
@dynamic resourceId;
@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsComment
//

@implementation GTLYouTubeActivityContentDetailsComment
@dynamic resourceId;
@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsFavorite
//

@implementation GTLYouTubeActivityContentDetailsFavorite
@dynamic resourceId;
@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsLike
//

@implementation GTLYouTubeActivityContentDetailsLike
@dynamic resourceId;
@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsPlaylistItem
//

@implementation GTLYouTubeActivityContentDetailsPlaylistItem
@dynamic playlistId, playlistItemId, resourceId;
@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsRecommendation
//

@implementation GTLYouTubeActivityContentDetailsRecommendation
@dynamic reason, resourceId, seedResourceId;
@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsSocial
//

@implementation GTLYouTubeActivityContentDetailsSocial
@dynamic author, imageUrl, referenceUrl, resourceId, type;
@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsSubscription
//

@implementation GTLYouTubeActivityContentDetailsSubscription
@dynamic resourceId;
@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityContentDetailsUpload
//

@implementation GTLYouTubeActivityContentDetailsUpload
@dynamic videoId;
@end
