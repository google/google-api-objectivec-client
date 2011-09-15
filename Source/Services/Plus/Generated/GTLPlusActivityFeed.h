/* Copyright (c) 2011 Google Inc.
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
//  GTLPlusActivityFeed.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   plus/v1
// Description:
//   Google+ API
// Classes:
//   GTLPlusActivityFeed (0 custom class methods, 8 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLPlusActivity;

// ----------------------------------------------------------------------------
//
//   GTLPlusActivityFeed
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLPlusActivityFeed : GTLCollectionObject

// The ID of this collection of activities.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSString *identifier;

// The activities in this page of results.
@property (retain) NSArray *items;  // of GTLPlusActivity

// Identifies this resource as a collection of activities. Value:
// "plus#activityFeed".
@property (retain) NSString *kind;

@property (retain) NSString *nextLink;

// The continuation token, used to page through large result sets. Provide this
// value in a subsequent request to return the next page of results.
@property (retain) NSString *nextPageToken;

@property (retain) NSString *selfLink;

// The title of this collection of activities.
@property (retain) NSString *title;

// The time at which this collection of activities was last updated. Formatted
// as an RFC 3339 timestamp.
@property (retain) GTLDateTime *updated;

@end
