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
//   GTLQueryGmail (32 custom class methods, 24 custom properties)

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
@property (nonatomic, copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (nonatomic, retain) NSArray *addLabelIds;  // of NSString
@property (nonatomic, assign) BOOL deleted;
@property (nonatomic, retain) GTLGmailDraft *draft;
@property (nonatomic, copy) NSString *format;
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, assign) BOOL includeSpamTrash;
@property (nonatomic, copy) NSString *internalDateSource;
@property (nonatomic, retain) GTLGmailLabel *label;
@property (nonatomic, copy) NSString *labelFilterAction;
@property (nonatomic, copy) NSString *labelId;
@property (nonatomic, retain) NSArray *labelIds;  // of NSString
@property (nonatomic, assign) NSUInteger maxResults;
@property (nonatomic, retain) GTLGmailMessage *message;
@property (nonatomic, copy) NSString *messageId;
@property (nonatomic, retain) NSArray *metadataHeaders;  // of NSString
@property (nonatomic, assign) BOOL neverMarkSpam;
@property (nonatomic, copy) NSString *pageToken;
@property (nonatomic, assign) BOOL processForCalendar;
@property (nonatomic, copy) NSString *q;
@property (nonatomic, retain) NSArray *removeLabelIds;  // of NSString
@property (nonatomic, assign) unsigned long long startHistoryId;
@property (nonatomic, copy) NSString *topicName;
@property (nonatomic, copy) NSString *userId;

#pragma mark - "users.drafts" methods
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
+ (instancetype)queryForUsersDraftsCreateWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

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
+ (instancetype)queryForUsersDraftsDelete;

// Method: gmail.users.drafts.get
// Gets the specified draft.
//  Optional:
//   format: The format to return the draft in. (Default kGTLGmailFormatFull)
//      kGTLGmailFormatFull: "full"
//      kGTLGmailFormatMetadata: "metadata"
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
+ (instancetype)queryForUsersDraftsGet;

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
+ (instancetype)queryForUsersDraftsList;

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
+ (instancetype)queryForUsersDraftsSendWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

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
+ (instancetype)queryForUsersDraftsUpdateWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

#pragma mark - "users" methods
// These create a GTLQueryGmail object.

// Method: gmail.users.getProfile
// Gets the current user's Gmail profile.
//  Optional:
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailCompose
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
// Fetches a GTLGmailProfile.
+ (instancetype)queryForUsersGetProfile;

#pragma mark - "users.history" methods
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
//     for at least a week, but in some rare circumstances may be valid for only
//     a few hours. If you receive an HTTP 404 error response, your application
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
+ (instancetype)queryForUsersHistoryList;

#pragma mark - "users.labels" methods
// These create a GTLQueryGmail object.

// Method: gmail.users.labels.create
// Creates a new label.
//  Optional:
//   label: GTLGmailLabel
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailLabels
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailLabel.
+ (instancetype)queryForUsersLabelsCreate;

// Method: gmail.users.labels.delete
// Immediately and permanently deletes the specified label and removes it from
// any messages and threads that it is applied to.
//  Optional:
//   identifier: The ID of the label to delete.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailLabels
//   kGTLAuthScopeGmailModify
+ (instancetype)queryForUsersLabelsDelete;

// Method: gmail.users.labels.get
// Gets the specified label.
//  Optional:
//   identifier: The ID of the label to retrieve.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailLabels
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
// Fetches a GTLGmailLabel.
+ (instancetype)queryForUsersLabelsGet;

// Method: gmail.users.labels.list
// Lists all labels in the user's mailbox.
//  Optional:
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailLabels
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
// Fetches a GTLGmailListLabelsResponse.
+ (instancetype)queryForUsersLabelsList;

// Method: gmail.users.labels.patch
// Updates the specified label. This method supports patch semantics.
//  Optional:
//   label: GTLGmailLabel
//   identifier: The ID of the label to update.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailLabels
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailLabel.
+ (instancetype)queryForUsersLabelsPatch;

// Method: gmail.users.labels.update
// Updates the specified label.
//  Optional:
//   label: GTLGmailLabel
//   identifier: The ID of the label to update.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailLabels
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailLabel.
+ (instancetype)queryForUsersLabelsUpdate;

#pragma mark - "users.messages.attachments" methods
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
+ (instancetype)queryForUsersMessagesAttachmentsGet;

#pragma mark - "users.messages" methods
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
+ (instancetype)queryForUsersMessagesDelete;

// Method: gmail.users.messages.get
// Gets the specified message.
//  Optional:
//   format: The format to return the message in. (Default kGTLGmailFormatFull)
//      kGTLGmailFormatFull: "full"
//      kGTLGmailFormatMetadata: "metadata"
//      kGTLGmailFormatMinimal: "minimal"
//      kGTLGmailFormatRaw: "raw"
//   identifier: The ID of the message to retrieve.
//   metadataHeaders: When given and format is METADATA, only include headers
//     specified.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
// Fetches a GTLGmailMessage.
+ (instancetype)queryForUsersMessagesGet;

// Method: gmail.users.messages.import
// Imports a message into only this user's mailbox, with standard email delivery
// scanning and classification similar to receiving via SMTP. Does not send a
// message.
//  Optional:
//   message: GTLGmailMessage
//   deleted: Mark the email as permanently deleted (not TRASH) and only visible
//     in Google Apps Vault to a Vault administrator. Only used for Google Apps
//     for Work accounts. (Default false)
//   internalDateSource: Source for Gmail's internal date of the message.
//     (Default kGTLGmailInternalDateSourceDateHeader)
//      kGTLGmailInternalDateSourceDateHeader: "dateHeader"
//      kGTLGmailInternalDateSourceReceivedTime: "receivedTime"
//   neverMarkSpam: Ignore the Gmail spam classifier decision and never mark
//     this email as SPAM in the mailbox. (Default false)
//   processForCalendar: Process calendar invites in the email and add any
//     extracted meetings to the Google Calendar for this user. (Default false)
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Upload Parameters:
//   Maximum size: 35MB
//   Accepted MIME type(s): message/rfc822
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailInsert
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailMessage.
+ (instancetype)queryForUsersMessagesImportWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

// Method: gmail.users.messages.insert
// Directly inserts a message into only this user's mailbox similar to IMAP
// APPEND, bypassing most scanning and classification. Does not send a message.
//  Optional:
//   message: GTLGmailMessage
//   deleted: Mark the email as permanently deleted (not TRASH) and only visible
//     in Google Apps Vault to a Vault administrator. Only used for Google Apps
//     for Work accounts. (Default false)
//   internalDateSource: Source for Gmail's internal date of the message.
//     (Default kGTLGmailInternalDateSourceReceivedTime)
//      kGTLGmailInternalDateSourceDateHeader: "dateHeader"
//      kGTLGmailInternalDateSourceReceivedTime: "receivedTime"
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Upload Parameters:
//   Maximum size: 35MB
//   Accepted MIME type(s): message/rfc822
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailInsert
//   kGTLAuthScopeGmailModify
// Fetches a GTLGmailMessage.
+ (instancetype)queryForUsersMessagesInsertWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

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
+ (instancetype)queryForUsersMessagesList;

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
+ (instancetype)queryForUsersMessagesModify;

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
//   kGTLAuthScopeGmailSend
// Fetches a GTLGmailMessage.
+ (instancetype)queryForUsersMessagesSendWithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

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
+ (instancetype)queryForUsersMessagesTrash;

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
+ (instancetype)queryForUsersMessagesUntrash;

#pragma mark - "users" methods
// These create a GTLQueryGmail object.

// Method: gmail.users.stop
// Stop receiving push notifications for the given user mailbox.
//  Optional:
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
+ (instancetype)queryForUsersStop;

#pragma mark - "users.threads" methods
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
+ (instancetype)queryForUsersThreadsDelete;

// Method: gmail.users.threads.get
// Gets the specified thread.
//  Optional:
//   format: The format to return the messages in. (Default kGTLGmailFormatFull)
//      kGTLGmailFormatFull: "full"
//      kGTLGmailFormatMetadata: "metadata"
//      kGTLGmailFormatMinimal: "minimal"
//   identifier: The ID of the thread to retrieve.
//   metadataHeaders: When given and format is METADATA, only include headers
//     specified.
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
// Fetches a GTLGmailThread.
+ (instancetype)queryForUsersThreadsGet;

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
+ (instancetype)queryForUsersThreadsList;

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
+ (instancetype)queryForUsersThreadsModify;

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
+ (instancetype)queryForUsersThreadsTrash;

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
+ (instancetype)queryForUsersThreadsUntrash;

#pragma mark - "users" methods
// These create a GTLQueryGmail object.

// Method: gmail.users.watch
// Set up or update a push notification watch on the given user mailbox.
//  Optional:
//   labelFilterAction: Filtering behavior of labelIds list specified.
//      kGTLGmailLabelFilterActionExclude: "exclude"
//      kGTLGmailLabelFilterActionInclude: "include"
//   labelIds: List of label_ids to restrict notifications about. By default, if
//     unspecified, all changes are pushed out. If specified then dictates which
//     labels are required for a push notification to be generated.
//   topicName: A fully qualified Google Cloud Pub/Sub API topic name to publish
//     the events to. This topic name **must** already exist in Cloud Pub/Sub
//     and you **must** have already granted gmail "publish" permission on it.
//     For example, "projects/my-project-identifier/topics/my-topic-name" (using
//     the new Cloud Pub/Sub "v1beta2" topic naming format).
//     Note that the "my-project-identifier" portion must exactly match your
//     Google developer project id (the one executing this watch request).
//   userId: The user's email address. The special value me can be used to
//     indicate the authenticated user. (Default me)
//  Authorization scope(s):
//   kGTLAuthScopeGmail
//   kGTLAuthScopeGmailModify
//   kGTLAuthScopeGmailReadonly
// Fetches a GTLGmailWatchResponse.
+ (instancetype)queryForUsersWatch;

@end
