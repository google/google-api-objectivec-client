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
//  GTLDoubleClickBidManagerReportMetadata.h
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
//   GTLDoubleClickBidManagerReportMetadata (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLDoubleClickBidManagerReportStatus;

// ----------------------------------------------------------------------------
//
//   GTLDoubleClickBidManagerReportMetadata
//

// Report metadata.

@interface GTLDoubleClickBidManagerReportMetadata : GTLObject

// The path to the location in Google Cloud Storage where the report is stored.
@property (copy) NSString *googleCloudStoragePath;

// The ending time for the data that is shown in the report.
@property (retain) NSNumber *reportDataEndTimeMs;  // longLongValue

// The starting time for the data that is shown in the report.
@property (retain) NSNumber *reportDataStartTimeMs;  // longLongValue

// Report status.
@property (retain) GTLDoubleClickBidManagerReportStatus *status;

@end
