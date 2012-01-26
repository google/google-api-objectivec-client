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
//  GTLOrkutCommunityMessageList.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Orkut API (orkut/v2)
// Description:
//   Lets you manage activities, comments and badges in Orkut. More stuff coming
//   in time.
// Documentation:
//   http://code.google.com/apis/orkut/v2/reference.html
// Classes:
//   GTLOrkutCommunityMessageList (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLOrkutCommunityMessage;

// ----------------------------------------------------------------------------
//
//   GTLOrkutCommunityMessageList
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLOrkutCommunityMessageList : GTLCollectionObject

// The value of pageToken query parameter in community_messages.list request to
// get the first page.
@property (copy) NSString *firstPageToken;

// List of messages retrieved.
@property (retain) NSArray *items;  // of GTLOrkutCommunityMessage

// Identifies this resource as a collection of community messages. Value:
// "orkut#communityMessageList"
@property (copy) NSString *kind;

// The value of pageToken query parameter in community_messages.list request to
// get the last page.
@property (copy) NSString *lastPageToken;

// The value of pageToken query parameter in community_messages.list request to
// get the next page, if there are more to retrieve.
@property (copy) NSString *nextPageToken;

// The value of pageToken query parameter in community_messages.list request to
// get the previous page, if there are more to retrieve.
@property (copy) NSString *prevPageToken;

@end
