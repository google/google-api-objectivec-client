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
//  GTLYouTubeAnalyticsBatchReport.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   YouTube Analytics API (youtubeAnalytics/v1)
// Description:
//   Retrieve your YouTube Analytics reports.
// Documentation:
//   http://developers.google.com/youtube/analytics/
// Classes:
//   GTLYouTubeAnalyticsBatchReport (0 custom class methods, 6 custom properties)
//   GTLYouTubeAnalyticsBatchReportOutputsItem (0 custom class methods, 3 custom properties)
//   GTLYouTubeAnalyticsBatchReportTimeSpan (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeAnalyticsBatchReportOutputsItem;
@class GTLYouTubeAnalyticsBatchReportTimeSpan;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeAnalyticsBatchReport
//

// Contains single batchReport resource.

@interface GTLYouTubeAnalyticsBatchReport : GTLObject

// The ID that YouTube assigns and uses to uniquely identify the report.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// This value specifies the type of data of this item. For batch report the kind
// property value is youtubeAnalytics#batchReport.
@property (copy) NSString *kind;

// Report outputs.
@property (retain) NSArray *outputs;  // of GTLYouTubeAnalyticsBatchReportOutputsItem

// The ID of the the report definition.
@property (copy) NSString *reportId;

// Period included in the report. For reports containing all entities endTime is
// not set. Both startTime and endTime are inclusive.
@property (retain) GTLYouTubeAnalyticsBatchReportTimeSpan *timeSpan;

// The time when the report was updated.
@property (retain) GTLDateTime *timeUpdated;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeAnalyticsBatchReportOutputsItem
//

@interface GTLYouTubeAnalyticsBatchReportOutputsItem : GTLObject

// Cloud storage URL to download this report. This URL is valid for 30 minutes.
@property (copy) NSString *downloadUrl;

// Format of the output.
@property (copy) NSString *format;

// Type of the output.
@property (copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeAnalyticsBatchReportTimeSpan
//

@interface GTLYouTubeAnalyticsBatchReportTimeSpan : GTLObject

// End of the period included in the report. Inclusive. For reports containing
// all entities endTime is not set.
@property (retain) GTLDateTime *endTime;

// Start of the period included in the report. Inclusive.
@property (retain) GTLDateTime *startTime;

@end
