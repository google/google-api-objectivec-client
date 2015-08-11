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
//  GTLQueryGmail.m
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
//   GTLQueryGmail (32 custom class methods, 24 custom properties)

#import "GTLQueryGmail.h"

#import "GTLGmailDraft.h"
#import "GTLGmailLabel.h"
#import "GTLGmailListDraftsResponse.h"
#import "GTLGmailListHistoryResponse.h"
#import "GTLGmailListLabelsResponse.h"
#import "GTLGmailListMessagesResponse.h"
#import "GTLGmailListThreadsResponse.h"
#import "GTLGmailMessage.h"
#import "GTLGmailMessagePartBody.h"
#import "GTLGmailProfile.h"
#import "GTLGmailThread.h"
#import "GTLGmailWatchResponse.h"

@implementation GTLQueryGmail

@dynamic addLabelIds, deleted, draft, fields, format, identifier,
         includeSpamTrash, internalDateSource, label, labelFilterAction,
         labelId, labelIds, maxResults, message, messageId, metadataHeaders,
         neverMarkSpam, pageToken, processForCalendar, q, removeLabelIds,
         startHistoryId, topicName, userId;

+ (NSDictionary *)parameterNameMap {
  NSDictionary *map = @{
    @"identifier" : @"id"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"addLabelIds" : [NSString class],
    @"labelIds" : [NSString class],
    @"metadataHeaders" : [NSString class],
    @"removeLabelIds" : [NSString class]
  };
  return map;
}

#pragma mark - "users.drafts" methods
// These create a GTLQueryGmail object.

+ (instancetype)queryForUsersDraftsCreateWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"gmail.users.drafts.create";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLGmailDraft class];
  return query;
}

+ (instancetype)queryForUsersDraftsDelete {
  NSString *methodName = @"gmail.users.drafts.delete";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  return query;
}

+ (instancetype)queryForUsersDraftsGet {
  NSString *methodName = @"gmail.users.drafts.get";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailDraft class];
  return query;
}

+ (instancetype)queryForUsersDraftsList {
  NSString *methodName = @"gmail.users.drafts.list";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailListDraftsResponse class];
  return query;
}

+ (instancetype)queryForUsersDraftsSendWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"gmail.users.drafts.send";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLGmailMessage class];
  return query;
}

+ (instancetype)queryForUsersDraftsUpdateWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"gmail.users.drafts.update";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLGmailDraft class];
  return query;
}

#pragma mark - "users" methods
// These create a GTLQueryGmail object.

+ (instancetype)queryForUsersGetProfile {
  NSString *methodName = @"gmail.users.getProfile";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailProfile class];
  return query;
}

#pragma mark - "users.history" methods
// These create a GTLQueryGmail object.

+ (instancetype)queryForUsersHistoryList {
  NSString *methodName = @"gmail.users.history.list";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailListHistoryResponse class];
  return query;
}

#pragma mark - "users.labels" methods
// These create a GTLQueryGmail object.

+ (instancetype)queryForUsersLabelsCreate {
  NSString *methodName = @"gmail.users.labels.create";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailLabel class];
  return query;
}

+ (instancetype)queryForUsersLabelsDelete {
  NSString *methodName = @"gmail.users.labels.delete";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  return query;
}

+ (instancetype)queryForUsersLabelsGet {
  NSString *methodName = @"gmail.users.labels.get";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailLabel class];
  return query;
}

+ (instancetype)queryForUsersLabelsList {
  NSString *methodName = @"gmail.users.labels.list";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailListLabelsResponse class];
  return query;
}

+ (instancetype)queryForUsersLabelsPatch {
  NSString *methodName = @"gmail.users.labels.patch";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailLabel class];
  return query;
}

+ (instancetype)queryForUsersLabelsUpdate {
  NSString *methodName = @"gmail.users.labels.update";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailLabel class];
  return query;
}

#pragma mark - "users.messages.attachments" methods
// These create a GTLQueryGmail object.

+ (instancetype)queryForUsersMessagesAttachmentsGet {
  NSString *methodName = @"gmail.users.messages.attachments.get";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailMessagePartBody class];
  return query;
}

#pragma mark - "users.messages" methods
// These create a GTLQueryGmail object.

+ (instancetype)queryForUsersMessagesDelete {
  NSString *methodName = @"gmail.users.messages.delete";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  return query;
}

+ (instancetype)queryForUsersMessagesGet {
  NSString *methodName = @"gmail.users.messages.get";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailMessage class];
  return query;
}

+ (instancetype)queryForUsersMessagesImportWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"gmail.users.messages.import";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLGmailMessage class];
  return query;
}

+ (instancetype)queryForUsersMessagesInsertWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"gmail.users.messages.insert";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLGmailMessage class];
  return query;
}

+ (instancetype)queryForUsersMessagesList {
  NSString *methodName = @"gmail.users.messages.list";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailListMessagesResponse class];
  return query;
}

+ (instancetype)queryForUsersMessagesModify {
  NSString *methodName = @"gmail.users.messages.modify";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailMessage class];
  return query;
}

+ (instancetype)queryForUsersMessagesSendWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"gmail.users.messages.send";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLGmailMessage class];
  return query;
}

+ (instancetype)queryForUsersMessagesTrash {
  NSString *methodName = @"gmail.users.messages.trash";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailMessage class];
  return query;
}

+ (instancetype)queryForUsersMessagesUntrash {
  NSString *methodName = @"gmail.users.messages.untrash";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailMessage class];
  return query;
}

#pragma mark - "users" methods
// These create a GTLQueryGmail object.

+ (instancetype)queryForUsersStop {
  NSString *methodName = @"gmail.users.stop";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  return query;
}

#pragma mark - "users.threads" methods
// These create a GTLQueryGmail object.

+ (instancetype)queryForUsersThreadsDelete {
  NSString *methodName = @"gmail.users.threads.delete";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  return query;
}

+ (instancetype)queryForUsersThreadsGet {
  NSString *methodName = @"gmail.users.threads.get";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailThread class];
  return query;
}

+ (instancetype)queryForUsersThreadsList {
  NSString *methodName = @"gmail.users.threads.list";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailListThreadsResponse class];
  return query;
}

+ (instancetype)queryForUsersThreadsModify {
  NSString *methodName = @"gmail.users.threads.modify";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailThread class];
  return query;
}

+ (instancetype)queryForUsersThreadsTrash {
  NSString *methodName = @"gmail.users.threads.trash";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailThread class];
  return query;
}

+ (instancetype)queryForUsersThreadsUntrash {
  NSString *methodName = @"gmail.users.threads.untrash";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailThread class];
  return query;
}

#pragma mark - "users" methods
// These create a GTLQueryGmail object.

+ (instancetype)queryForUsersWatch {
  NSString *methodName = @"gmail.users.watch";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailWatchResponse class];
  return query;
}

@end
