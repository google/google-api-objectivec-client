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
//  GTLOrkutCommunityPoll.m
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

#import "GTLOrkutCommunityPoll.h"

#import "GTLOrkutAuthorResource.h"
#import "GTLOrkutCommunitypolloptionResource.h"
#import "GTLOrkutLinkResource.h"

// ----------------------------------------------------------------------------
//
//   GTLOrkutCommunityPoll
//

@implementation GTLOrkutCommunityPoll
@dynamic author, communityId, creationTime, descriptionProperty, endingTime,
         hasVoted, identifier, image, isClosed, isMultipleAnswers,
         isOpenForVoting, isRestricted, isSpam, isUsersVotePublic,
         isVotingAllowedForNonMembers, kind, lastUpdate, links, options,
         question, totalNumberOfVotes, votedOptions;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"description", @"descriptionProperty",
      @"id", @"identifier",
      nil];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLOrkutLinkResource class], @"links",
      [GTLOrkutCommunitypolloptionResource class], @"options",
      [NSNumber class], @"votedOptions",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"orkut#communityPoll"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLOrkutCommunityPollImage
//

@implementation GTLOrkutCommunityPollImage
@dynamic url;
@end
