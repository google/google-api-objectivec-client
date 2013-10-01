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
//  GTLDoubleClickBidManagerReportStatus.h
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
//   GTLDoubleClickBidManagerReportStatus (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLDoubleClickBidManagerReportFailure;

// ----------------------------------------------------------------------------
//
//   GTLDoubleClickBidManagerReportStatus
//

// Report status.

@interface GTLDoubleClickBidManagerReportStatus : GTLObject

// If the report failed, this records the cause.
@property (retain) GTLDoubleClickBidManagerReportFailure *failure;

// The time when this report either completed successfully or failed.
@property (retain) NSNumber *finishTimeMs;  // longLongValue

// The file type of the report.
@property (copy) NSString *format;

// The state of the report.
@property (copy) NSString *state;

@end
