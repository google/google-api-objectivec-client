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
//  GTLDoubleClickBidManagerQuery.h
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
//   GTLDoubleClickBidManagerQuery (0 custom class methods, 8 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLDoubleClickBidManagerParameters;
@class GTLDoubleClickBidManagerQueryMetadata;
@class GTLDoubleClickBidManagerQuerySchedule;

// ----------------------------------------------------------------------------
//
//   GTLDoubleClickBidManagerQuery
//

// Represents a query.

@interface GTLDoubleClickBidManagerQuery : GTLObject

// Identifies what kind of resource this is. Value: the fixed string
// "doubleclickbidmanager#query".
@property (nonatomic, copy) NSString *kind;

// Query metadata.
@property (nonatomic, retain) GTLDoubleClickBidManagerQueryMetadata *metadata;

// Query parameters.
@property (nonatomic, retain) GTLDoubleClickBidManagerParameters *params;

// Query ID.
@property (nonatomic, retain) NSNumber *queryId;  // longLongValue

// The ending time for the data that is shown in the report. Note,
// reportDataEndTimeMs is required if metadata.dataRange is CUSTOM_DATES and
// ignored otherwise.
@property (nonatomic, retain) NSNumber *reportDataEndTimeMs;  // longLongValue

// The starting time for the data that is shown in the report. Note,
// reportDataStartTimeMs is required if metadata.dataRange is CUSTOM_DATES and
// ignored otherwise.
@property (nonatomic, retain) NSNumber *reportDataStartTimeMs;  // longLongValue

// Information on how often and when to run a query.
@property (nonatomic, retain) GTLDoubleClickBidManagerQuerySchedule *schedule;

// Canonical timezone code for report data time. Defaults to America/New_York.
@property (nonatomic, copy) NSString *timezoneCode;

@end
