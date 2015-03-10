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
//  GTLDoubleClickBidManagerQueryMetadata.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   DoubleClick Bid Manager API (doubleclickbidmanager/v1)
// Description:
//   API for viewing and managing your reports in DoubleClick Bid Manager.
// Documentation:
//   https://developers.google.com/bid-manager/
// Classes:
//   GTLDoubleClickBidManagerQueryMetadata (0 custom class methods, 11 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLDoubleClickBidManagerQueryMetadata
//

// Query metadata.

@interface GTLDoubleClickBidManagerQueryMetadata : GTLObject

// Range of report data.
@property (copy) NSString *dataRange;

// Format of the generated report.
@property (copy) NSString *format;

// The path to the location in Google Cloud Storage where the latest report is
// stored.
@property (copy) NSString *googleCloudStoragePathForLatestReport;

// The path in Google Drive for the latest report.
@property (copy) NSString *googleDrivePathForLatestReport;

// The time when the latest report started to run.
@property (retain) NSNumber *latestReportRunTimeMs;  // longLongValue

// Locale of the generated reports. Valid values are cs CZECH de GERMAN en
// ENGLISH es SPANISH fr FRENCH it ITALIAN ja JAPANESE ko KOREAN pl POLISH pt-BR
// BRAZILIAN_PORTUGUESE ru RUSSIAN tr TURKISH uk UKRAINIAN zh-CN CHINA_CHINESE
// zh-TW TAIWAN_CHINESE
// An locale string not in the list above will generate reports in English.
@property (copy) NSString *locale;

// Number of reports that have been generated for the query.
@property (retain) NSNumber *reportCount;  // intValue

// Whether the latest report is currently running.
@property (retain) NSNumber *running;  // boolValue

// Whether to send an email notification when a report is ready. Default to
// false.
@property (retain) NSNumber *sendNotification;  // boolValue

// List of email addresses which are sent email notifications when the report is
// finished. Separate from sendNotification.
@property (retain) NSArray *shareEmailAddress;  // of NSString

// Query title. It is used to name the reports generated from this query.
@property (copy) NSString *title;

@end
