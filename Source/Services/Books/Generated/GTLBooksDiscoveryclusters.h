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
//  GTLBooksDiscoveryclusters.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBooksDiscoveryclustersClustersItem;
@class GTLBooksDiscoveryclustersClustersItemBannerWithContentContainer;
@class GTLBooksVolume;

// ----------------------------------------------------------------------------
//
//   GTLBooksDiscoveryclusters
//

@interface GTLBooksDiscoveryclusters : GTLObject
@property (nonatomic, retain) NSArray *clusters;  // of GTLBooksDiscoveryclustersClustersItem

// Resorce type.
@property (nonatomic, copy) NSString *kind;

@property (nonatomic, retain) NSNumber *totalClusters;  // intValue
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDiscoveryclustersClustersItem
//

@interface GTLBooksDiscoveryclustersClustersItem : GTLObject
@property (nonatomic, retain) GTLBooksDiscoveryclustersClustersItemBannerWithContentContainer *bannerWithContentContainer;
@property (nonatomic, copy) NSString *subTitle;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, retain) NSNumber *totalVolumes;  // intValue
@property (nonatomic, copy) NSString *uid;
@property (nonatomic, retain) NSArray *volumes;  // of GTLBooksVolume
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDiscoveryclustersClustersItemBannerWithContentContainer
//

@interface GTLBooksDiscoveryclustersClustersItemBannerWithContentContainer : GTLObject
@property (nonatomic, copy) NSString *fillColorArgb;
@property (nonatomic, copy) NSString *imageUrl;
@property (nonatomic, copy) NSString *maskColorArgb;
@property (nonatomic, copy) NSString *moreButtonText;
@property (nonatomic, copy) NSString *moreButtonUrl;
@property (nonatomic, copy) NSString *textColorArgb;
@end
