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
//  GTLOrkutCommunity.h
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
//   GTLOrkutCommunity (0 custom class methods, 14 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLOrkutAuthorResource;
@class GTLOrkutLinkResource;

// ----------------------------------------------------------------------------
//
//   GTLOrkutCommunity
//

@interface GTLOrkutCommunity : GTLObject

// The category of the community.
@property (copy) NSString *category;

// The co-owners of the community.
@property (retain) NSArray *coOwners;  // of GTLOrkutAuthorResource

// The time the community was created, in RFC 3339 format.
@property (retain) GTLDateTime *creationDate;

// The description of the community.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// The id of the community.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSNumber *identifier;  // intValue

// Identifies this resource as a community. Value: "orkut#community"
@property (copy) NSString *kind;

// The official language of the community.
@property (copy) NSString *language;

// List of resources for the community.
@property (retain) NSArray *links;  // of GTLOrkutLinkResource

// The location of the community.
@property (copy) NSString *location;

// The number of users who are part of the community. This number may be
// approximate, so do not rely on it for iteration.
@property (retain) NSNumber *memberCount;  // intValue

// The list of moderators of the community.
@property (retain) NSArray *moderators;  // of GTLOrkutAuthorResource

// The name of the community.
@property (copy) NSString *name;

// The person who owns the community.
@property (retain) GTLOrkutAuthorResource *owner;

// The photo of the community.
@property (copy) NSString *photoUrl;

@end
