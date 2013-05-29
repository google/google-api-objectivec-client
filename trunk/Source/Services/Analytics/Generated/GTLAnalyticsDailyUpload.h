/* Copyright (c) 2013 Google Inc.
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
//  GTLAnalyticsDailyUpload.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Analytics API (analytics/v3)
// Description:
//   View and manage your Google Analytics data
// Documentation:
//   https://developers.google.com/analytics/
// Classes:
//   GTLAnalyticsDailyUpload (0 custom class methods, 11 custom properties)
//   GTLAnalyticsDailyUploadParentLink (0 custom class methods, 2 custom properties)
//   GTLAnalyticsDailyUploadRecentChangesItem (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsDailyUploadParentLink;
@class GTLAnalyticsDailyUploadRecentChangesItem;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsDailyUpload
//

// Metadata for daily upload entity.

@interface GTLAnalyticsDailyUpload : GTLObject

// Account ID to which this daily upload belongs.
@property (copy) NSString *accountId;

// Number of appends for this date.
@property (retain) NSNumber *appendCount;  // intValue

// Time this daily upload was created.
@property (retain) GTLDateTime *createdTime;

// Custom data source ID to which this daily upload belongs.
@property (copy) NSString *customDataSourceId;

// Date associated with daily upload.
@property (copy) NSString *date;

// Resource type for Analytics daily upload.
@property (copy) NSString *kind;

// Time this daily upload was last modified.
@property (retain) GTLDateTime *modifiedTime;

// Parent link for a daily upload. Points to the custom data source to which
// this daily upload belongs.
@property (retain) GTLAnalyticsDailyUploadParentLink *parentLink;

// Change log for last 10 changes in chronological order.
@property (retain) NSArray *recentChanges;  // of GTLAnalyticsDailyUploadRecentChangesItem

// Link for this daily upload.
@property (copy) NSString *selfLink;

// Web property ID of the form UA-XXXXX-YY to which this daily upload belongs.
@property (copy) NSString *webPropertyId;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsDailyUploadParentLink
//

@interface GTLAnalyticsDailyUploadParentLink : GTLObject

// Link to the custom data source to which this daily upload belongs.
@property (copy) NSString *href;

// Value is "analytics#customDataSource".
@property (copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsDailyUploadRecentChangesItem
//

@interface GTLAnalyticsDailyUploadRecentChangesItem : GTLObject

// The type of change: APPEND, RESET, or DELETE.
@property (copy) NSString *change;

// The time when the change occurred.
@property (retain) GTLDateTime *time;

@end
