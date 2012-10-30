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
//  GTLServiceYouTube.m
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
//   GTLServiceYouTube (0 custom class methods, 0 custom properties)

#import "GTLYouTube.h"

@implementation GTLServiceYouTube

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = [NSArray arrayWithObjects:
                      [GTLQueryYouTube class],
                      [GTLYouTubeActivity class],
                      [GTLYouTubeActivityContentDetails class],
                      [GTLYouTubeActivityListResponse class],
                      [GTLYouTubeActivitySnippet class],
                      [GTLYouTubeChannel class],
                      [GTLYouTubeChannelContentDetails class],
                      [GTLYouTubeChannelListResponse class],
                      [GTLYouTubeChannelSnippet class],
                      [GTLYouTubeChannelStatistics class],
                      [GTLYouTubeChannelTopicDetails class],
                      [GTLYouTubeGuideCategory class],
                      [GTLYouTubeGuideCategoryListResponse class],
                      [GTLYouTubeGuideCategorySnippet class],
                      [GTLYouTubePageInfo class],
                      [GTLYouTubePlaylist class],
                      [GTLYouTubePlaylistItem class],
                      [GTLYouTubePlaylistItemContentDetails class],
                      [GTLYouTubePlaylistItemListResponse class],
                      [GTLYouTubePlaylistItemSnippet class],
                      [GTLYouTubePlaylistListResponse class],
                      [GTLYouTubePlaylistSnippet class],
                      [GTLYouTubePlaylistStatus class],
                      [GTLYouTubeResourceId class],
                      [GTLYouTubeSearchListResponse class],
                      [GTLYouTubeSearchResult class],
                      [GTLYouTubeSearchResultSnippet class],
                      [GTLYouTubeSubscription class],
                      [GTLYouTubeSubscriptionContentDetails class],
                      [GTLYouTubeSubscriptionListResponse class],
                      [GTLYouTubeSubscriptionSnippet class],
                      [GTLYouTubeThumbnail class],
                      [GTLYouTubeVideo class],
                      [GTLYouTubeVideoCategory class],
                      [GTLYouTubeVideoCategoryListResponse class],
                      [GTLYouTubeVideoCategorySnippet class],
                      [GTLYouTubeVideoContentDetails class],
                      [GTLYouTubeVideoListResponse class],
                      [GTLYouTubeVideoPlayer class],
                      [GTLYouTubeVideoSnippet class],
                      [GTLYouTubeVideoStatistics class],
                      [GTLYouTubeVideoStatus class],
                      [GTLYouTubeVideoTopicDetails class],
                      nil];
  return classes;
}
#endif  // DEBUG

- (id)init {
  self = [super init];
  if (self) {
    // Version from discovery.
    self.apiVersion = @"v3";

    // From discovery.  Where to send JSON-RPC.
    // Turn off prettyPrint for this service to save bandwidth (especially on
    // mobile). The fetcher logging will pretty print.
    self.rpcURL = [NSURL URLWithString:@"https://www.googleapis.com/rpc?prettyPrint=false"];
    self.rpcUploadURL = [NSURL URLWithString:@"https://www.googleapis.com/upload/rpc?uploadType=resumable&prettyPrint=false"];
  }
  return self;
}

@end
