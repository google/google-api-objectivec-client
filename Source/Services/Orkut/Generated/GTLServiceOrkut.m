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
//  GTLServiceOrkut.m
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
//   GTLServiceOrkut (0 custom class methods, 0 custom properties)

#import "GTLOrkut.h"

@implementation GTLServiceOrkut

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = [NSArray arrayWithObjects:
                      [GTLQueryOrkut class],
                      [GTLOrkutAcl class],
                      [GTLOrkutActivity class],
                      [GTLOrkutActivityList class],
                      [GTLOrkutActivityobjectsResource class],
                      [GTLOrkutActivitypersonResource class],
                      [GTLOrkutAuthorResource class],
                      [GTLOrkutBadge class],
                      [GTLOrkutBadgeList class],
                      [GTLOrkutComment class],
                      [GTLOrkutCommentList class],
                      [GTLOrkutCommunity class],
                      [GTLOrkutCommunityList class],
                      [GTLOrkutCommunityMembers class],
                      [GTLOrkutCommunityMembershipStatus class],
                      [GTLOrkutCommunityMembersList class],
                      [GTLOrkutCommunityMessage class],
                      [GTLOrkutCommunityMessageList class],
                      [GTLOrkutCommunityPoll class],
                      [GTLOrkutCommunityPollComment class],
                      [GTLOrkutCommunityPollCommentList class],
                      [GTLOrkutCommunityPollList class],
                      [GTLOrkutCommunitypolloptionResource class],
                      [GTLOrkutCommunityPollVote class],
                      [GTLOrkutCommunityTopic class],
                      [GTLOrkutCommunityTopicList class],
                      [GTLOrkutCounterResource class],
                      [GTLOrkutCounters class],
                      [GTLOrkutLinkResource class],
                      [GTLOrkutVisibility class],
                      nil];
  return classes;
}
#endif  // DEBUG

- (id)init {
  self = [super init];
  if (self) {
    // Version from discovery.
    self.apiVersion = @"v2";

    // From discovery.  Where to send JSON-RPC.
    // Turn off prettyPrint for this service to save bandwidth (especially on
    // mobile). The fetcher logging will pretty print.
    self.rpcURL = [NSURL URLWithString:@"https://www.googleapis.com/rpc?prettyPrint=false"];
  }
  return self;
}

@end
