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
//  GTLOrkutCommunityMembershipStatus.h
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
//   GTLOrkutCommunityMembershipStatus (0 custom class methods, 11 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLOrkutCommunityMembershipStatus
//

@interface GTLOrkutCommunityMembershipStatus : GTLObject

// Whether the user can create a poll in this community.
@property (retain) NSNumber *canCreatePoll;  // boolValue

// Whether the user can create a topic in this community.
@property (retain) NSNumber *canCreateTopic;  // boolValue

// Whether the user can perform a shout operation in this community.
@property (retain) NSNumber *canShout;  // boolValue

// Whether the session user is a community co-owner.
@property (retain) NSNumber *isCoOwner;  // boolValue

// Whether the user is following this community.
@property (retain) NSNumber *isFollowing;  // boolValue

// Whether the session user is a community moderator.
@property (retain) NSNumber *isModerator;  // boolValue

// Whether the session user is the community owner.
@property (retain) NSNumber *isOwner;  // boolValue

// Whether the restore operation is available for the community.
@property (retain) NSNumber *isRestoreAvailable;  // boolValue

// Whether the take-back operation is available for the community.
@property (retain) NSNumber *isTakebackAvailable;  // boolValue

// Kind of this item. Always orkut#communityMembershipStatus.
@property (copy) NSString *kind;

// The status of the current link between the community and the user.
@property (copy) NSString *status;

@end
