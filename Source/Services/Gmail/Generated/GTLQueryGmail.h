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
//  GTLQueryGmail.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLGmailDraft;
@class GTLGmailLabel;
@class GTLGmailMessage;

@interface GTLQueryGmail : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (retain) NSArray *addLabelIds;  // of NSString
@property (retain) GTLGmailDraft *draft;
@property (copy) NSString *format;
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;
@property (assign) BOOL includeSpamTrash;
@property (retain) GTLGmailLabel *label;
@property (copy) NSString *labelId;
@property (retain) NSArray *labelIds;  // of NSString
@property (assign) NSUInteger maxResults;
@property (retain) GTLGmailMessage *message;
@property (copy) NSString *messageId;
@property (copy) NSString *pageToken;
@property (copy) NSString *q;
@property (retain) NSArray *removeLabelIds;  // of NSString
@property (assign) unsigned long long startHistoryId;
@property (copy) NSString *userId;

#pragma mark -
#pragma mark "users.drafts" methods
// These create a GTLQueryGmail object.

// Method: gmail.users.drafts.create
// Creates a new draft with the DRAFT label.
//  Optional:
//   draft: GTLGmailDraft
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Upload Parameters:
//   Maximum size: 35MB
//   Accepted MIME type(s): message/rfc822
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailCompose
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailDraft.
+ (id)queryForUsersDraftsCreateWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

// Method: gmail.users.drafts.delete
// Immediately and permanently deletes the specified draft. Does not simply
// trash it.
//  Optional:
//   identifier: The ID of the draft to delete.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailCompose
//   kGTLAuthScopeGmailModify
+ (id)queryForUsersDraftsDelete;

// Method: gmail.users.drafts.get
// Gets the specified draft.
//  Optional:
//   format: The format to return the draft in. (Default kGTLGmailFormatFull)
//      kGTLGmailFormatFull: "full"
//      kGTLGmailFormatMinimal: "minimal"
//      kGTLGmailFormatRaw: "raw"
//   identifier: The ID of the draft to retrieve.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailCompose
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
// Fetches a GTLGmailDraft.
+ (id)queryForUsersDraftsGet;

// Method: gmail.users.drafts.list
// Lists the drafts in the user's mailbox.
//  Optional:
//   maxResults: Maximum number of drafts to return. (Default 100)
//   pageToken: Page token to retrieve a specific page of results in the list.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailCompose
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
// Fetches a GTLGmailListDraftsResponse.
+ (id)queryForUsersDraftsList;

// Method: gmail.users.drafts.send
// Sends the specified, existing draft to the recipients in the To, Cc, and Bcc
// headers.
//  Optional:
//   draft: GTLGmailDraft
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Upload Parameters:
//   Maximum size: 35MB
//   Accepted MIME type(s): message/rfc822
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailCompose
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailMessage.
+ (id)queryForUsersDraftsSendWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

// Method: gmail.users.drafts.update
// Replaces a draft's content.
//  Optional:
//   draft: GTLGmailDraft
//   identifier: The ID of the draft to update.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Upload Parameters:
//   Maximum size: 35MB
//   Accepted MIME type(s): message/rfc822
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailCompose
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailDraft.
+ (id)queryForUsersDraftsUpdateWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

#pragma mark -
#pragma mark "users.history" methods
// These create a GTLQueryGmail object.

// Method: gmail.users.history.list
// Lists the history of all changes to the given mailbox. History results are
// returned in chronological order (increasing historyId).
//  Optional:
//   labelId: Only return messages with a label matching the ID.
//   maxResults: The maximum number of history records to return. (Default 100)
//   pageToken: Page token to retrieve a specific page of results in the list.
//   startHistoryId: Required. Returns history records after the specified
//     startHistoryId. The supplied startHistoryId should be obtained from the
//     historyId of a message, thread, or previous list response. History IDs
//     increase chronologically but are not contiguous with random gaps in
//     between valid IDs. Supplying an invalid or out of date startHistoryId
//     typically returns an HTTP 404 error code. A historyId is typically valid
//     for at least a week, but in some circumstances may be valid for only a
//     few hours. If you receive an HTTP 404 error response, your application
//     should perform a full sync. If you receive no nextPageToken in the
//     response, there are no updates to retrieve and you can store the returned
//     historyId for a future request.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
// Fetches a GTLGmailListHistoryResponse.
+ (id)queryForUsersHistoryList;

#pragma mark -
#pragma mark "users.labels" methods
// These create a GTLQueryGmail object.

// Method: gmail.users.labels.create
// Creates a new label.
//  Optional:
//   label: GTLGmailLabel
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailLabel.
+ (id)queryForUsersLabelsCreate;

// Method: gmail.users.labels.delete
// Immediately and permanently deletes the specified label and removes it from
// any messages and threads that it is applied to.
//  Optional:
//   identifier: The ID of the label to delete.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
+ (id)queryForUsersLabelsDelete;

// Method: gmail.users.labels.get
// Gets the specified label.
//  Optional:
//   identifier: The ID of the label to retrieve.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
// Fetches a GTLGmailLabel.
+ (id)queryForUsersLabelsGet;

// Method: gmail.users.labels.list
// Lists all labels in the user's mailbox.
//  Optional:
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
// Fetches a GTLGmailListLabelsResponse.
+ (id)queryForUsersLabelsList;

// Method: gmail.users.labels.patch
// Updates the specified label. This method supports patch semantics.
//  Optional:
//   label: GTLGmailLabel
//   identifier: The ID of the label to update.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailLabel.
+ (id)queryForUsersLabelsPatch;

// Method: gmail.users.labels.update
// Updates the specified label.
//  Optional:
//   label: GTLGmailLabel
//   identifier: The ID of the label to update.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailLabel.
+ (id)queryForUsersLabelsUpdate;

#pragma mark -
#pragma mark "users.messages.attachments" methods
// These create a GTLQueryGmail object.

// Method: gmail.users.messages.attachments.get
// Gets the specified message attachment.
//  Optional:
//   identifier: The ID of the attachment.
//   messageId: The ID of the message containing the attachment.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
// Fetches a GTLGmailMessagePartBody.
+ (id)queryForUsersMessagesAttachmentsGet;

#pragma mark -
#pragma mark "users.messages" methods
// These create a GTLQueryGmail object.

// Method: gmail.users.messages.delete
// Immediately and permanently deletes the specified message. This operation
// cannot be undone. Prefer messages.trash instead.
//  Optional:
//   identifier: The ID of the message to delete.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
+ (id)queryForUsersMessagesDelete;

// Method: gmail.users.messages.get
// Gets the specified message.
//  Optional:
//   format: The format to return the message in. (Default kGTLGmailFormatFull)
//      kGTLGmailFormatFull: "full"
//      kGTLGmailFormatMinimal: "minimal"
//      kGTLGmailFormatRaw: "raw"
//   identifier: The ID of the message to retrieve.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
// Fetches a GTLGmailMessage.
+ (id)queryForUsersMessagesGet;

// Method: gmail.users.messages.import
// Directly imports a message into only this user's mailbox, similar to
// receiving via SMTP. Does not send a message.
//  Optional:
//   message: GTLGmailMessage
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Upload Parameters:
//   Maximum size: 35MB
//   Accepted MIME type(s): message/rfc822
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailMessage.
+ (id)queryForUsersMessagesImportWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

// Method: gmail.users.messages.insert
// Directly inserts a message into only this user's mailbox. Does not send a
// message.
//  Optional:
//   message: GTLGmailMessage
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Upload Parameters:
//   Maximum size: 35MB
//   Accepted MIME type(s): message/rfc822
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailMessage.
+ (id)queryForUsersMessagesInsertWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

// Method: gmail.users.messages.list
// Lists the messages in the user's mailbox.
//  Optional:
//   includeSpamTrash: Include messages from SPAM and TRASH in the results.
//     (Default false)
//   labelIds: Only return messages with labels that match all of the specified
//     label IDs.
//   maxResults: Maximum number of messages to return. (Default 100)
//   pageToken: Page token to retrieve a specific page of results in the list.
//   q: Only return messages matching the specified query. Supports the same
//     query format as the Gmail search box. For example,
//     "from:someuser@example.com rfc822msgid: is:unread".
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
// Fetches a GTLGmailListMessagesResponse.
+ (id)queryForUsersMessagesList;

// Method: gmail.users.messages.modify
// Modifies the labels on the specified message.
//  Optional:
//   addLabelIds: A list of IDs of labels to add to this message.
//   identifier: The ID of the message to modify.
//   removeLabelIds: A list IDs of labels to remove from this message.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailMessage.
+ (id)queryForUsersMessagesModify;

// Method: gmail.users.messages.send
// Sends the specified message to the recipients in the To, Cc, and Bcc headers.
//  Optional:
//   message: GTLGmailMessage
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Upload Parameters:
//   Maximum size: 35MB
//   Accepted MIME type(s): message/rfc822
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailCompose
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailMessage.
+ (id)queryForUsersMessagesSendWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

// Method: gmail.users.messages.trash
// Moves the specified message to the trash.
//  Optional:
//   identifier: The ID of the message to Trash.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailMessage.
+ (id)queryForUsersMessagesTrash;

// Method: gmail.users.messages.untrash
// Removes the specified message from the trash.
//  Optional:
//   identifier: The ID of the message to remove from Trash.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailMessage.
+ (id)queryForUsersMessagesUntrash;

#pragma mark -
#pragma mark "users.threads" methods
// These create a GTLQueryGmail object.

// Method: gmail.users.threads.delete
// Immediately and permanently deletes the specified thread. This operation
// cannot be undone. Prefer threads.trash instead.
//  Optional:
//   identifier: ID of the Thread to delete.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
+ (id)queryForUsersThreadsDelete;

// Method: gmail.users.threads.get
// Gets the specified thread.
//  Optional:
//   identifier: The ID of the thread to retrieve.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
// Fetches a GTLGmailThread.
+ (id)queryForUsersThreadsGet;

// Method: gmail.users.threads.list
// Lists the threads in the user's mailbox.
//  Optional:
//   includeSpamTrash: Include threads from SPAM and TRASH in the results.
//     (Default false)
//   labelIds: Only return threads with labels that match all of the specified
//     label IDs.
//   maxResults: Maximum number of threads to return. (Default 100)
//   pageToken: Page token to retrieve a specific page of results in the list.
//   q: Only return threads matching the specified query. Supports the same
//     query format as the Gmail search box. For example,
//     "from:someuser@example.com rfc822msgid: is:unread".
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
// Fetches a GTLGmailListThreadsResponse.
+ (id)queryForUsersThreadsList;

// Method: gmail.users.threads.modify
// Modifies the labels applied to the thread. This applies to all messages in
// the thread.
//  Optional:
//   addLabelIds: A list of IDs of labels to add to this thread.
//   identifier: The ID of the thread to modify.
//   removeLabelIds: A list of IDs of labels to remove from this thread.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailThread.
+ (id)queryForUsersThreadsModify;

// Method: gmail.users.threads.trash
// Moves the specified thread to the trash.
//  Optional:
//   identifier: The ID of the thread to Trash.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailThread.
+ (id)queryForUsersThreadsTrash;

// Method: gmail.users.threads.untrash
// Removes the specified thread from the trash.
//  Optional:
//   identifier: The ID of the thread to remove from Trash.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailThread.
+ (id)queryForUsersThreadsUntrash;

@end
