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
//  GTLBooksDiscoveryclusters.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Books API (books/v1)
// Description:
//   Lets you search for books and manage your Google Books library.
// Documentation:
//   https://developers.google.com/books/docs/v1/getting_started
// Classes:
//   GTLBooksDiscoveryclusters (0 custom class methods, 3 custom properties)
//   GTLBooksDiscoveryclustersClustersItem (0 custom class methods, 6 custom properties)
//   GTLBooksDiscoveryclustersClustersItemBannerWithContentContainer (0 custom class methods, 6 custom properties)

#import "GTLBooksDiscoveryclusters.h"

#import "GTLBooksVolume.h"

// ----------------------------------------------------------------------------
//
//   GTLBooksDiscoveryclusters
//

@implementation GTLBooksDiscoveryclusters
@dynamic clusters, kind, totalClusters;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"clusters" : [GTLBooksDiscoveryclustersClustersItem class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"books#discovery#clusters"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDiscoveryclustersClustersItem
//

@implementation GTLBooksDiscoveryclustersClustersItem
@dynamic bannerWithContentContainer, subTitle, title, totalVolumes, uid,
         volumes;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"bannerWithContentContainer" : @"banner_with_content_container"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"volumes" : [GTLBooksVolume class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDiscoveryclustersClustersItemBannerWithContentContainer
//

@implementation GTLBooksDiscoveryclustersClustersItemBannerWithContentContainer
@dynamic fillColorArgb, imageUrl, maskColorArgb, moreButtonText, moreButtonUrl,
         textColorArgb;
@end
