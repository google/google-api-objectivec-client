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
//  GTLOrkutActivity.h
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
//   GTLOrkutActivity (0 custom class methods, 10 custom properties)
//   GTLOrkutActivityObject (0 custom class methods, 4 custom properties)
//   GTLOrkutActivityObjectReplies (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLOrkutAcl;
@class GTLOrkutActivityObject;
@class GTLOrkutActivityObjectReplies;
@class GTLOrkutActivityobjectsResource;
@class GTLOrkutAuthorResource;
@class GTLOrkutComment;
@class GTLOrkutLinkResource;

// ----------------------------------------------------------------------------
//
//   GTLOrkutActivity
//

@interface GTLOrkutActivity : GTLObject

// Identifies who has access to see this activity.
@property (retain) GTLOrkutAcl *access;

// The person who performed the activity.
@property (retain) GTLOrkutAuthorResource *actor;

// The ID for the activity.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The kind of activity. Always orkut#activity.
@property (copy) NSString *kind;

// Links to resources related to this activity.
@property (retain) NSArray *links;  // of GTLOrkutLinkResource

// The activity's object.
@property (retain) GTLOrkutActivityObject *object;

// The time at which the activity was initially published.
@property (retain) GTLDateTime *published;

// Title of the activity.
@property (copy) NSString *title;

// The time at which the activity was last updated.
@property (retain) GTLDateTime *updated;

// This activity's verb, indicating what action was performed. Possible values
// are:
// - add - User added new content to profile or album, e.g. video, photo.
// - post - User publish content to the stream, e.g. status, scrap.
// - update - User commented on an activity.
// - make-friend - User added a new friend.
// - birthday - User has a birthday.
@property (copy) NSString *verb;

@end


// ----------------------------------------------------------------------------
//
//   GTLOrkutActivityObject
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLOrkutActivityObject : GTLCollectionObject

// The HTML-formatted content, suitable for display. When updating an activity's
// content, post the changes to this property, using the value of
// originalContent as a starting point. If the update is successful, the server
// adds HTML formatting and responds with this formatted content.
@property (copy) NSString *content;

// The list of additional items.
@property (retain) NSArray *items;  // of GTLOrkutActivityobjectsResource

// The type of the object affected by the activity. Clients can use this
// information to style the rendered activity object differently depending on
// the content.
@property (copy) NSString *objectType;

// Comments in reply to this activity.
@property (retain) GTLOrkutActivityObjectReplies *replies;

@end


// ----------------------------------------------------------------------------
//
//   GTLOrkutActivityObjectReplies
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLOrkutActivityObjectReplies : GTLCollectionObject

// The list of comments.
@property (retain) NSArray *items;  // of GTLOrkutComment

// Total number of comments.
@property (retain) NSNumber *totalItems;  // unsignedLongLongValue

// URL for the collection of comments in reply to this activity.
@property (copy) NSString *url;

@end
