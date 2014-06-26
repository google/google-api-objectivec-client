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
//   GTLQueryGmail (29 custom class methods, 17 custom properties)

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
#import "GTLGmailThread.h"

@implementation GTLQueryGmail

@dynamic addLabelIds, draft, fields, format, identifier, includeSpamTrash,
         label, labelId, labelIds, maxResults, message, messageId, pageToken, q,
         removeLabelIds, startHistoryId, userId;

+ (NSDictionary *)parameterNameMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [NSString class], @"addLabelIds",
      [NSString class], @"labelIds",
      [NSString class], @"removeLabelIds",
      nil];
  return map;
}

#pragma mark -
#pragma mark "users.drafts" methods
// These create a GTLQueryGmail object.

+ (id)queryForUsersDraftsCreateWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"gmail.users.drafts.create";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLGmailDraft class];
  return query;
}

+ (id)queryForUsersDraftsDelete {
  NSString *methodName = @"gmail.users.drafts.delete";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  return query;
}

+ (id)queryForUsersDraftsGet {
  NSString *methodName = @"gmail.users.drafts.get";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailDraft class];
  return query;
}

+ (id)queryForUsersDraftsList {
  NSString *methodName = @"gmail.users.drafts.list";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailListDraftsResponse class];
  return query;
}

+ (id)queryForUsersDraftsSendWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"gmail.users.drafts.send";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLGmailMessage class];
  return query;
}

+ (id)queryForUsersDraftsUpdateWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"gmail.users.drafts.update";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLGmailDraft class];
  return query;
}

#pragma mark -
#pragma mark "users.history" methods
// These create a GTLQueryGmail object.

+ (id)queryForUsersHistoryList {
  NSString *methodName = @"gmail.users.history.list";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailListHistoryResponse class];
  return query;
}

#pragma mark -
#pragma mark "users.labels" methods
// These create a GTLQueryGmail object.

+ (id)queryForUsersLabelsCreate {
  NSString *methodName = @"gmail.users.labels.create";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailLabel class];
  return query;
}

+ (id)queryForUsersLabelsDelete {
  NSString *methodName = @"gmail.users.labels.delete";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  return query;
}

+ (id)queryForUsersLabelsGet {
  NSString *methodName = @"gmail.users.labels.get";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailLabel class];
  return query;
}

+ (id)queryForUsersLabelsList {
  NSString *methodName = @"gmail.users.labels.list";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailListLabelsResponse class];
  return query;
}

+ (id)queryForUsersLabelsPatch {
  NSString *methodName = @"gmail.users.labels.patch";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailLabel class];
  return query;
}

+ (id)queryForUsersLabelsUpdate {
  NSString *methodName = @"gmail.users.labels.update";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailLabel class];
  return query;
}

#pragma mark -
#pragma mark "users.messages.attachments" methods
// These create a GTLQueryGmail object.

+ (id)queryForUsersMessagesAttachmentsGet {
  NSString *methodName = @"gmail.users.messages.attachments.get";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailMessagePartBody class];
  return query;
}

#pragma mark -
#pragma mark "users.messages" methods
// These create a GTLQueryGmail object.

+ (id)queryForUsersMessagesDelete {
  NSString *methodName = @"gmail.users.messages.delete";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  return query;
}

+ (id)queryForUsersMessagesGet {
  NSString *methodName = @"gmail.users.messages.get";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailMessage class];
  return query;
}

+ (id)queryForUsersMessagesImportWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"gmail.users.messages.import";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLGmailMessage class];
  return query;
}

+ (id)queryForUsersMessagesInsertWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"gmail.users.messages.insert";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLGmailMessage class];
  return query;
}

+ (id)queryForUsersMessagesList {
  NSString *methodName = @"gmail.users.messages.list";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailListMessagesResponse class];
  return query;
}

+ (id)queryForUsersMessagesModify {
  NSString *methodName = @"gmail.users.messages.modify";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailMessage class];
  return query;
}

+ (id)queryForUsersMessagesSendWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"gmail.users.messages.send";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLGmailMessage class];
  return query;
}

+ (id)queryForUsersMessagesTrash {
  NSString *methodName = @"gmail.users.messages.trash";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailMessage class];
  return query;
}

+ (id)queryForUsersMessagesUntrash {
  NSString *methodName = @"gmail.users.messages.untrash";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailMessage class];
  return query;
}

#pragma mark -
#pragma mark "users.threads" methods
// These create a GTLQueryGmail object.

+ (id)queryForUsersThreadsDelete {
  NSString *methodName = @"gmail.users.threads.delete";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  return query;
}

+ (id)queryForUsersThreadsGet {
  NSString *methodName = @"gmail.users.threads.get";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailThread class];
  return query;
}

+ (id)queryForUsersThreadsList {
  NSString *methodName = @"gmail.users.threads.list";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailListThreadsResponse class];
  return query;
}

+ (id)queryForUsersThreadsModify {
  NSString *methodName = @"gmail.users.threads.modify";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailThread class];
  return query;
}

+ (id)queryForUsersThreadsTrash {
  NSString *methodName = @"gmail.users.threads.trash";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailThread class];
  return query;
}

+ (id)queryForUsersThreadsUntrash {
  NSString *methodName = @"gmail.users.threads.untrash";
  GTLQueryGmail *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLGmailThread class];
  return query;
}

@end
