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
//  GTLOrkutAcl.h
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
//   GTLOrkutAcl (0 custom class methods, 4 custom properties)
//   GTLOrkutAclItemsItem (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLOrkutAclItemsItem;

// ----------------------------------------------------------------------------
//
//   GTLOrkutAcl
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLOrkutAcl : GTLCollectionObject

// Human readable description of the access granted.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// The list of ACL entries.
@property (retain) NSArray *items;  // of GTLOrkutAclItemsItem

// Identifies this resource as an access control list. Value: "orkut#acl"
@property (copy) NSString *kind;

// The total count of participants of the parent resource.
@property (retain) NSNumber *totalParticipants;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLOrkutAclItemsItem
//

@interface GTLOrkutAclItemsItem : GTLObject

// The ID of the entity. For entities of type "person" or "circle", this is the
// ID of the resource. For other types, this will be unset.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The type of entity to whom access is granted.
@property (copy) NSString *type;

@end
