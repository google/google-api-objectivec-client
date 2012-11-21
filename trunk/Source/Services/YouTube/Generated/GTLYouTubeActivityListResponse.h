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
//  GTLYouTubeActivityListResponse.h
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
//   GTLYouTubeActivityListResponse (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeActivity;
@class GTLYouTubePageInfo;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeActivityListResponse
//

// A paginated list of activities returned as a response to
// youtube.activities.list calls.

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLYouTubeActivityListResponse : GTLCollectionObject

// The ETag of the response.
@property (copy) NSString *ETag;

// A list of activities, or events, that match the request criteria.
@property (retain) NSArray *items;  // of GTLYouTubeActivity

// The type of the API response. For this operation, the value will be
// youtube#activityListResponse.
@property (copy) NSString *kind;

// The token that can be used as the value of the pageToken parameter to
// retrieve the next page in the result set.
@property (copy) NSString *nextPageToken;

// The pageInfo object encapsulates paging information for the result set.
@property (retain) GTLYouTubePageInfo *pageInfo;

// The token that can be used as the value of the pageToken parameter to
// retrieve the previous page in the result set.
@property (copy) NSString *prevPageToken;

@end
