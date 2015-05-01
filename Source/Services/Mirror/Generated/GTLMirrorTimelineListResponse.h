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
//  GTLMirrorTimelineListResponse.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Mirror API (mirror/v1)
// Description:
//   API for interacting with Glass users via the timeline.
// Documentation:
//   https://developers.google.com/glass
// Classes:
//   GTLMirrorTimelineListResponse (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLMirrorTimelineItem;

// ----------------------------------------------------------------------------
//
//   GTLMirrorTimelineListResponse
//

// A list of timeline items. This is the response from the server to GET
// requests on the timeline collection.

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLMirrorTimelineListResponse : GTLCollectionObject

// Items in the timeline.
@property (nonatomic, retain) NSArray *items;  // of GTLMirrorTimelineItem

// The type of resource. This is always mirror#timeline.
@property (nonatomic, copy) NSString *kind;

// The next page token. Provide this as the pageToken parameter in the request
// to retrieve the next page of results.
@property (nonatomic, copy) NSString *nextPageToken;

@end
