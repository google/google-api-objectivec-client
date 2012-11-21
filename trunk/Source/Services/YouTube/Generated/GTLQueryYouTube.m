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
//  GTLQueryYouTube.m
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
//   GTLQueryYouTube (21 custom class methods, 27 custom properties)

#import "GTLQueryYouTube.h"

#import "GTLYouTubeActivity.h"
#import "GTLYouTubeActivityListResponse.h"
#import "GTLYouTubeChannelListResponse.h"
#import "GTLYouTubeGuideCategoryListResponse.h"
#import "GTLYouTubePlaylist.h"
#import "GTLYouTubePlaylistItem.h"
#import "GTLYouTubePlaylistItemListResponse.h"
#import "GTLYouTubePlaylistListResponse.h"
#import "GTLYouTubeSearchListResponse.h"
#import "GTLYouTubeSubscription.h"
#import "GTLYouTubeSubscriptionListResponse.h"
#import "GTLYouTubeVideo.h"
#import "GTLYouTubeVideoCategoryListResponse.h"
#import "GTLYouTubeVideoListResponse.h"

@implementation GTLQueryYouTube

@dynamic categoryId, channelId, fields, forChannelId, hl, home, identifier,
         maxResults, mine, mySubscribers, order, pageToken, part, playlistId,
         published, publishedAfter, publishedBefore, q, regionCode,
         relatedToVideoId, topicId, type, videoCaption, videoDefinition,
         videoDimension, videoDuration, videoLicense;

+ (NSDictionary *)parameterNameMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

#pragma mark -
#pragma mark "activities" methods
// These create a GTLQueryYouTube object.

+ (id)queryForActivitiesInsertWithObject:(GTLYouTubeActivity *)object
                                    part:(NSString *)part {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"youtube.activities.insert";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.part = part;
  query.expectedObjectClass = [GTLYouTubeActivity class];
  return query;
}

+ (id)queryForActivitiesListWithPart:(NSString *)part {
  NSString *methodName = @"youtube.activities.list";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.part = part;
  query.expectedObjectClass = [GTLYouTubeActivityListResponse class];
  return query;
}

#pragma mark -
#pragma mark "channels" methods
// These create a GTLQueryYouTube object.

+ (id)queryForChannelsListWithPart:(NSString *)part {
  NSString *methodName = @"youtube.channels.list";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.part = part;
  query.expectedObjectClass = [GTLYouTubeChannelListResponse class];
  return query;
}

#pragma mark -
#pragma mark "guideCategories" methods
// These create a GTLQueryYouTube object.

+ (id)queryForGuideCategoriesListWithPart:(NSString *)part {
  NSString *methodName = @"youtube.guideCategories.list";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.part = part;
  query.expectedObjectClass = [GTLYouTubeGuideCategoryListResponse class];
  return query;
}

#pragma mark -
#pragma mark "playlistItems" methods
// These create a GTLQueryYouTube object.

+ (id)queryForPlaylistItemsDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"youtube.playlistItems.delete";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (id)queryForPlaylistItemsInsertWithObject:(GTLYouTubePlaylistItem *)object
                                       part:(NSString *)part {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"youtube.playlistItems.insert";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.part = part;
  query.expectedObjectClass = [GTLYouTubePlaylistItem class];
  return query;
}

+ (id)queryForPlaylistItemsListWithPart:(NSString *)part {
  NSString *methodName = @"youtube.playlistItems.list";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.part = part;
  query.expectedObjectClass = [GTLYouTubePlaylistItemListResponse class];
  return query;
}

+ (id)queryForPlaylistItemsUpdateWithObject:(GTLYouTubePlaylistItem *)object
                                       part:(NSString *)part {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"youtube.playlistItems.update";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.part = part;
  query.expectedObjectClass = [GTLYouTubePlaylistItem class];
  return query;
}

#pragma mark -
#pragma mark "playlists" methods
// These create a GTLQueryYouTube object.

+ (id)queryForPlaylistsDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"youtube.playlists.delete";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (id)queryForPlaylistsInsertWithObject:(GTLYouTubePlaylist *)object
                                   part:(NSString *)part {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"youtube.playlists.insert";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.part = part;
  query.expectedObjectClass = [GTLYouTubePlaylist class];
  return query;
}

+ (id)queryForPlaylistsListWithPart:(NSString *)part {
  NSString *methodName = @"youtube.playlists.list";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.part = part;
  query.expectedObjectClass = [GTLYouTubePlaylistListResponse class];
  return query;
}

+ (id)queryForPlaylistsUpdateWithObject:(GTLYouTubePlaylist *)object
                                   part:(NSString *)part {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"youtube.playlists.update";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.part = part;
  query.expectedObjectClass = [GTLYouTubePlaylist class];
  return query;
}

#pragma mark -
#pragma mark "search" methods
// These create a GTLQueryYouTube object.

+ (id)queryForSearchListWithPart:(NSString *)part {
  NSString *methodName = @"youtube.search.list";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.part = part;
  query.expectedObjectClass = [GTLYouTubeSearchListResponse class];
  return query;
}

#pragma mark -
#pragma mark "subscriptions" methods
// These create a GTLQueryYouTube object.

+ (id)queryForSubscriptionsDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"youtube.subscriptions.delete";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (id)queryForSubscriptionsInsertWithObject:(GTLYouTubeSubscription *)object
                                       part:(NSString *)part {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"youtube.subscriptions.insert";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.part = part;
  query.expectedObjectClass = [GTLYouTubeSubscription class];
  return query;
}

+ (id)queryForSubscriptionsListWithPart:(NSString *)part {
  NSString *methodName = @"youtube.subscriptions.list";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.part = part;
  query.expectedObjectClass = [GTLYouTubeSubscriptionListResponse class];
  return query;
}

#pragma mark -
#pragma mark "videoCategories" methods
// These create a GTLQueryYouTube object.

+ (id)queryForVideoCategoriesListWithPart:(NSString *)part {
  NSString *methodName = @"youtube.videoCategories.list";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.part = part;
  query.expectedObjectClass = [GTLYouTubeVideoCategoryListResponse class];
  return query;
}

#pragma mark -
#pragma mark "videos" methods
// These create a GTLQueryYouTube object.

+ (id)queryForVideosDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"youtube.videos.delete";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (id)queryForVideosInsertWithObject:(GTLYouTubeVideo *)object
                                part:(NSString *)part
                    uploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"youtube.videos.insert";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.part = part;
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLYouTubeVideo class];
  return query;
}

+ (id)queryForVideosListWithIdentifier:(NSString *)identifier
                                  part:(NSString *)part {
  NSString *methodName = @"youtube.videos.list";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.part = part;
  query.expectedObjectClass = [GTLYouTubeVideoListResponse class];
  return query;
}

+ (id)queryForVideosUpdateWithObject:(GTLYouTubeVideo *)object
                                part:(NSString *)part {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"youtube.videos.update";
  GTLQueryYouTube *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.part = part;
  query.expectedObjectClass = [GTLYouTubeVideo class];
  return query;
}

@end
