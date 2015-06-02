/* Copyright (c) 2015 Google Inc.
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
//  GTLServiceGmail.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Gmail API (gmail/v1)
// Description:
//   The Gmail REST API.
// Documentation:
//   https://developers.google.com/gmail/api/
// Classes:
//   GTLServiceGmail (0 custom class methods, 0 custom properties)

#import "GTLGmail.h"

@implementation GTLServiceGmail

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = @[
    [GTLQueryGmail class],
    [GTLGmailDraft class],
    [GTLGmailHistory class],
    [GTLGmailHistoryLabelAdded class],
    [GTLGmailHistoryLabelRemoved class],
    [GTLGmailHistoryMessageAdded class],
    [GTLGmailHistoryMessageDeleted class],
    [GTLGmailLabel class],
    [GTLGmailListDraftsResponse class],
    [GTLGmailListHistoryResponse class],
    [GTLGmailListLabelsResponse class],
    [GTLGmailListMessagesResponse class],
    [GTLGmailListThreadsResponse class],
    [GTLGmailMessage class],
    [GTLGmailMessagePart class],
    [GTLGmailMessagePartBody class],
    [GTLGmailMessagePartHeader class],
    [GTLGmailProfile class],
    [GTLGmailThread class],
    [GTLGmailWatchResponse class]
  ];
  return classes;
}
#endif  // DEBUG

- (instancetype)init {
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
