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
//  GTLOrkutCommunityPoll.h
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
//   GTLOrkutCommunityPoll (0 custom class methods, 22 custom properties)
//   GTLOrkutCommunityPollImage (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLOrkutAuthorResource;
@class GTLOrkutCommunityPollImage;
@class GTLOrkutCommunitypolloptionResource;
@class GTLOrkutLinkResource;

// ----------------------------------------------------------------------------
//
//   GTLOrkutCommunityPoll
//

@interface GTLOrkutCommunityPoll : GTLObject

// The person who created the poll.
@property (retain) GTLOrkutAuthorResource *author;

// The ID of the community.
@property (retain) NSNumber *communityId;  // intValue

// The date of creation of this poll
@property (retain) GTLDateTime *creationTime;

// The poll description.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// The ending date of this poll or empty if the poll doesn't have one.
@property (retain) GTLDateTime *endingTime;

// Whether the user has voted on this poll.
@property (retain) NSNumber *hasVoted;  // boolValue

// The poll ID.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The image representing the poll. Field is omitted if no image exists.
@property (retain) GTLOrkutCommunityPollImage *image;

// Whether the poll is not expired if there is an expiration date. A poll is
// open (that is, not closed for voting) if it either is not expired or doesn't
// have an expiration date at all. Note that just because a poll is open, it
// doesn't mean that the requester can vote on it.
@property (retain) NSNumber *isClosed;  // boolValue

// Whether this poll allows voting for more than one option.
@property (retain) NSNumber *isMultipleAnswers;  // boolValue

// Whether this poll is still opened for voting. A poll is open for voting if it
// is not closed, the user has not yet voted on it and the user has the
// permission to do so, which happens if he/she is either a community member or
// the poll is open for everybody.
@property (retain) NSNumber *isOpenForVoting;  // boolValue

// Whether this poll is restricted for members only. If a poll is open but the
// user can't vote on it, it's been restricted to members only. This information
// is important to tell this case apart from the one where the user can't vote
// simply because the poll is already closed.
@property (retain) NSNumber *isRestricted;  // boolValue

// Whether the user has marked this poll as spam. This only affects the poll for
// this user, not globally.
@property (retain) NSNumber *isSpam;  // boolValue

// If user has already voted, whether his vote is publicly visible.
@property (retain) NSNumber *isUsersVotePublic;  // boolValue

// Whether non-members of the community can vote on the poll.
@property (retain) NSNumber *isVotingAllowedForNonMembers;  // boolValue

// Identifies this resource as a community poll. Value: "orkut#communityPoll"
@property (copy) NSString *kind;

// The date of the last update of this poll.
@property (retain) GTLDateTime *lastUpdate;

// List of resources for the community poll.
@property (retain) NSArray *links;  // of GTLOrkutLinkResource

// List of options of this poll.
@property (retain) NSArray *options;  // of GTLOrkutCommunitypolloptionResource

// The poll question.
@property (copy) NSString *question;

// The total number of votes this poll has received.
@property (retain) NSNumber *totalNumberOfVotes;  // intValue

// List of options the user has voted on, if there are any.
@property (retain) NSArray *votedOptions;  // of NSNumber (intValue)

@end


// ----------------------------------------------------------------------------
//
//   GTLOrkutCommunityPollImage
//

@interface GTLOrkutCommunityPollImage : GTLObject

// A URL that points to an image of the poll.
@property (copy) NSString *url;

@end
