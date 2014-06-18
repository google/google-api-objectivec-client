/* Copyright (c) 2014 Google Inc.
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
//  GTLServiceMirror.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Mirror API (mirror/v1)
// Description:
//   API for interacting with Glass users via the timeline.
// Documentation:
//   https://developers.google.com/glass
// Classes:
//   GTLServiceMirror (0 custom class methods, 0 custom properties)

#import "GTLMirror.h"

@implementation GTLServiceMirror

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = [NSArray arrayWithObjects:
                      [GTLQueryMirror class],
                      [GTLMirrorAccount class],
                      [GTLMirrorAttachment class],
                      [GTLMirrorAttachmentsListResponse class],
                      [GTLMirrorAuthToken class],
                      [GTLMirrorCommand class],
                      [GTLMirrorContact class],
                      [GTLMirrorContactsListResponse class],
                      [GTLMirrorLocation class],
                      [GTLMirrorLocationsListResponse class],
                      [GTLMirrorMenuItem class],
                      [GTLMirrorMenuValue class],
                      [GTLMirrorNotification class],
                      [GTLMirrorNotificationConfig class],
                      [GTLMirrorSetting class],
                      [GTLMirrorSubscription class],
                      [GTLMirrorSubscriptionsListResponse class],
                      [GTLMirrorTimelineItem class],
                      [GTLMirrorTimelineListResponse class],
                      [GTLMirrorUserAction class],
                      [GTLMirrorUserData class],
                      nil];
  return classes;
}
#endif  // DEBUG

- (id)init {
  self = [super init];
  if (self) {
    // Version from discovery.
    self.apiVersion = @"v1";

    // From discovery.  Where to send JSON-RPC.
    // Turn off prettyPrint for this service to save bandwidth (especially on
    // mobile). The fetcher logging will pretty print.
    self.rpcURL = [NSURL URLWithString:@"https://www.googleapis.com/rpc?prettyPrint=false"];
    self.rpcUploadURL = [NSURL URLWithString:@"https://www.googleapis.com/upload/rpc?uploadType=resumable&prettyPrint=false"];
  }
  return self;
}

@end
