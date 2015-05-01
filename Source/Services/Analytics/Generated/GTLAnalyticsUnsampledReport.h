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
//  GTLAnalyticsUnsampledReport.h
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
//   GTLAnalyticsUnsampledReport (0 custom class methods, 19 custom properties)
//   GTLAnalyticsUnsampledReportCloudStorageDownloadDetails (0 custom class methods, 2 custom properties)
//   GTLAnalyticsUnsampledReportDriveDownloadDetails (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsUnsampledReportCloudStorageDownloadDetails;
@class GTLAnalyticsUnsampledReportDriveDownloadDetails;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsUnsampledReport
//

// JSON template for Analytics unsampled report resource.

@interface GTLAnalyticsUnsampledReport : GTLObject

// Account ID to which this unsampled report belongs.
@property (nonatomic, copy) NSString *accountId;

// Download details for a file stored in Google Cloud Storage.
@property (nonatomic, retain) GTLAnalyticsUnsampledReportCloudStorageDownloadDetails *cloudStorageDownloadDetails;

// Time this unsampled report was created.
@property (nonatomic, retain) GTLDateTime *created;

// The dimensions for the unsampled report.
@property (nonatomic, copy) NSString *dimensions;

// The type of download you need to use for the report data file.
@property (nonatomic, copy) NSString *downloadType;

// Download details for a file stored in Google Drive.
@property (nonatomic, retain) GTLAnalyticsUnsampledReportDriveDownloadDetails *driveDownloadDetails;

// The end date for the unsampled report.
@property (nonatomic, copy) NSString *endDate;

// The filters for the unsampled report.
@property (nonatomic, copy) NSString *filters;

// Unsampled report ID.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Resource type for an Analytics unsampled report.
@property (nonatomic, copy) NSString *kind;

// The metrics for the unsampled report.
@property (nonatomic, copy) NSString *metrics;

// View (Profile) ID to which this unsampled report belongs.
@property (nonatomic, copy) NSString *profileId;

// The segment for the unsampled report.
@property (nonatomic, copy) NSString *segment;

// Link for this unsampled report.
@property (nonatomic, copy) NSString *selfLink;

// The start date for the unsampled report.
@property (nonatomic, copy) NSString *startDate;

// Status of this unsampled report. Possible values are PENDING, COMPLETED, or
// FAILED.
@property (nonatomic, copy) NSString *status;

// Title of the unsampled report.
@property (nonatomic, copy) NSString *title;

// Time this unsampled report was last modified.
@property (nonatomic, retain) GTLDateTime *updated;

// Web property ID to which this unsampled report belongs. The web property ID
// is of the form UA-XXXXX-YY.
@property (nonatomic, copy) NSString *webPropertyId;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsUnsampledReportCloudStorageDownloadDetails
//

@interface GTLAnalyticsUnsampledReportCloudStorageDownloadDetails : GTLObject

// Id of the bucket the file object is stored in.
@property (nonatomic, copy) NSString *bucketId;

// Id of the file object containing the report data.
@property (nonatomic, copy) NSString *objectId;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsUnsampledReportDriveDownloadDetails
//

@interface GTLAnalyticsUnsampledReportDriveDownloadDetails : GTLObject

// Id of the document/file containing the report data.
@property (nonatomic, copy) NSString *documentId;

@end
