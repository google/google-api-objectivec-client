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
//  GTLQueryMirror.h
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
//   GTLQueryMirror (24 custom class methods, 14 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLMirrorAccount;
@class GTLMirrorContact;
@class GTLMirrorSubscription;
@class GTLMirrorTimelineItem;

@interface GTLQueryMirror : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (copy) NSString *accountName;
@property (copy) NSString *accountType;
@property (copy) NSString *attachmentId;
@property (copy) NSString *bundleId;
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;
@property (assign) BOOL includeDeleted;
@property (copy) NSString *itemId;
@property (assign) NSUInteger maxResults;
@property (copy) NSString *orderBy;
@property (copy) NSString *pageToken;
@property (assign) BOOL pinnedOnly;
@property (copy) NSString *sourceItemId;
@property (copy) NSString *userToken;

#pragma mark -
#pragma mark "accounts" methods
// These create a GTLQueryMirror object.

// Method: mirror.accounts.insert
// Inserts a new account for a user
//  Required:
//   userToken: The ID for the user.
//   accountType: Account type to be passed to Android Account Manager.
//   accountName: The name of the account to be passed to the Android Account
//     Manager.
// Fetches a GTLMirrorAccount.
+ (id)queryForAccountsInsertWithObject:(GTLMirrorAccount *)object
                             userToken:(NSString *)userToken
                           accountType:(NSString *)accountType
                           accountName:(NSString *)accountName;

#pragma mark -
#pragma mark "contacts" methods
// These create a GTLQueryMirror object.

// Method: mirror.contacts.delete
// Deletes a contact.
//  Required:
//   identifier: The ID of the contact.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassTimeline
+ (id)queryForContactsDeleteWithIdentifier:(NSString *)identifier;

// Method: mirror.contacts.get
// Gets a single contact by ID.
//  Required:
//   identifier: The ID of the contact.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorContact.
+ (id)queryForContactsGetWithIdentifier:(NSString *)identifier;

// Method: mirror.contacts.insert
// Inserts a new contact.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorContact.
+ (id)queryForContactsInsertWithObject:(GTLMirrorContact *)object;

// Method: mirror.contacts.list
// Retrieves a list of contacts for the authenticated user.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorContactsListResponse.
+ (id)queryForContactsList;

// Method: mirror.contacts.patch
// Updates a contact in place. This method supports patch semantics.
//  Required:
//   identifier: The ID of the contact.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorContact.
+ (id)queryForContactsPatchWithObject:(GTLMirrorContact *)object
                           identifier:(NSString *)identifier;

// Method: mirror.contacts.update
// Updates a contact in place.
//  Required:
//   identifier: The ID of the contact.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorContact.
+ (id)queryForContactsUpdateWithObject:(GTLMirrorContact *)object
                            identifier:(NSString *)identifier;

#pragma mark -
#pragma mark "locations" methods
// These create a GTLQueryMirror object.

// Method: mirror.locations.get
// Gets a single location by ID.
//  Required:
//   identifier: The ID of the location or latest for the last known location.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassLocation
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorLocation.
+ (id)queryForLocationsGetWithIdentifier:(NSString *)identifier;

// Method: mirror.locations.list
// Retrieves a list of locations for the user.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassLocation
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorLocationsListResponse.
+ (id)queryForLocationsList;

#pragma mark -
#pragma mark "settings" methods
// These create a GTLQueryMirror object.

// Method: mirror.settings.get
// Gets a single setting by ID.
//  Required:
//   identifier: The ID of the setting. The following IDs are valid:
//     - locale - The key to the user’s language/locale (BCP 47 identifier) that
//     Glassware should use to render localized content.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorSetting.
+ (id)queryForSettingsGetWithIdentifier:(NSString *)identifier;

#pragma mark -
#pragma mark "subscriptions" methods
// These create a GTLQueryMirror object.

// Method: mirror.subscriptions.delete
// Deletes a subscription.
//  Required:
//   identifier: The ID of the subscription.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassTimeline
+ (id)queryForSubscriptionsDeleteWithIdentifier:(NSString *)identifier;

// Method: mirror.subscriptions.insert
// Creates a new subscription.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorSubscription.
+ (id)queryForSubscriptionsInsertWithObject:(GTLMirrorSubscription *)object;

// Method: mirror.subscriptions.list
// Retrieves a list of subscriptions for the authenticated user and service.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorSubscriptionsListResponse.
+ (id)queryForSubscriptionsList;

// Method: mirror.subscriptions.update
// Updates an existing subscription in place.
//  Required:
//   identifier: The ID of the subscription.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorSubscription.
+ (id)queryForSubscriptionsUpdateWithObject:(GTLMirrorSubscription *)object
                                 identifier:(NSString *)identifier;

#pragma mark -
#pragma mark "timeline.attachments" methods
// These create a GTLQueryMirror object.

// Method: mirror.timeline.attachments.delete
// Deletes an attachment from a timeline item.
//  Required:
//   itemId: The ID of the timeline item the attachment belongs to.
//   attachmentId: The ID of the attachment.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassTimeline
+ (id)queryForTimelineAttachmentsDeleteWithItemId:(NSString *)itemId
                                     attachmentId:(NSString *)attachmentId;

// Method: mirror.timeline.attachments.get
// Retrieves an attachment on a timeline item by item ID and attachment ID.
//  Required:
//   itemId: The ID of the timeline item the attachment belongs to.
//   attachmentId: The ID of the attachment.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorAttachment.
+ (id)queryForTimelineAttachmentsGetWithItemId:(NSString *)itemId
                                  attachmentId:(NSString *)attachmentId;

// Method: mirror.timeline.attachments.insert
// Adds a new attachment to a timeline item.
//  Required:
//   itemId: The ID of the timeline item the attachment belongs to.
//  Upload Parameters:
//   Maximum size: 10MB
//   Accepted MIME type(s): audio/*, image/*, video/*
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorAttachment.
+ (id)queryForTimelineAttachmentsInsertWithItemId:(NSString *)itemId
                                 uploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

// Method: mirror.timeline.attachments.list
// Returns a list of attachments for a timeline item.
//  Required:
//   itemId: The ID of the timeline item whose attachments should be listed.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorAttachmentsListResponse.
+ (id)queryForTimelineAttachmentsListWithItemId:(NSString *)itemId;

#pragma mark -
#pragma mark "timeline" methods
// These create a GTLQueryMirror object.

// Method: mirror.timeline.delete
// Deletes a timeline item.
//  Required:
//   identifier: The ID of the timeline item.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassLocation
//   kGTLAuthScopeMirrorGlassTimeline
+ (id)queryForTimelineDeleteWithIdentifier:(NSString *)identifier;

// Method: mirror.timeline.get
// Gets a single timeline item by ID.
//  Required:
//   identifier: The ID of the timeline item.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassLocation
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorTimelineItem.
+ (id)queryForTimelineGetWithIdentifier:(NSString *)identifier;

// Method: mirror.timeline.insert
// Inserts a new item into the timeline.
//  Upload Parameters:
//   Maximum size: 10MB
//   Accepted MIME type(s): audio/*, image/*, video/*
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassLocation
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorTimelineItem.
+ (id)queryForTimelineInsertWithObject:(GTLMirrorTimelineItem *)object
                      uploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

// Method: mirror.timeline.list
// Retrieves a list of timeline items for the authenticated user.
//  Optional:
//   bundleId: If provided, only items with the given bundleId will be returned.
//   includeDeleted: If true, tombstone records for deleted items will be
//     returned.
//   maxResults: The maximum number of items to include in the response, used
//     for paging.
//   orderBy: Controls the order in which timeline items are returned.
//      kGTLMirrorOrderByDisplayTime: Results will be ordered by displayTime
//        (default). This is the same ordering as is used in the timeline on the
//        device.
//      kGTLMirrorOrderByWriteTime: Results will be ordered by the time at which
//        they were last written to the data store.
//   pageToken: Token for the page of results to return.
//   pinnedOnly: If true, only pinned items will be returned.
//   sourceItemId: If provided, only items with the given sourceItemId will be
//     returned.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassLocation
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorTimelineListResponse.
+ (id)queryForTimelineList;

// Method: mirror.timeline.patch
// Updates a timeline item in place. This method supports patch semantics.
//  Required:
//   identifier: The ID of the timeline item.
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassLocation
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorTimelineItem.
+ (id)queryForTimelinePatchWithObject:(GTLMirrorTimelineItem *)object
                           identifier:(NSString *)identifier;

// Method: mirror.timeline.update
// Updates a timeline item in place.
//  Required:
//   identifier: The ID of the timeline item.
//  Upload Parameters:
//   Maximum size: 10MB
//   Accepted MIME type(s): audio/*, image/*, video/*
//  Authorization scope(s):
//   kGTLAuthScopeMirrorGlassLocation
//   kGTLAuthScopeMirrorGlassTimeline
// Fetches a GTLMirrorTimelineItem.
+ (id)queryForTimelineUpdateWithObject:(GTLMirrorTimelineItem *)object
                            identifier:(NSString *)identifier
                      uploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

@end
