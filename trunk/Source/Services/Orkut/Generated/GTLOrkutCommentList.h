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
//  GTLOrkutCommentList.h
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
//   GTLOrkutCommentList (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLOrkutComment;

// ----------------------------------------------------------------------------
//
//   GTLOrkutCommentList
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLOrkutCommentList : GTLCollectionObject

// List of comments retrieved.
@property (retain) NSArray *items;  // of GTLOrkutComment

// Identifies this resource as a collection of comments. Value:
// "orkut#commentList"
@property (copy) NSString *kind;

// The value of pageToken query parameter in comments.list request to get the
// next page, if there are more to retrieve.
@property (copy) NSString *nextPageToken;

// The value of pageToken query parameter in comments.list request to get the
// previous page, if there are more to retrieve.
@property (copy) NSString *previousPageToken;

@end
