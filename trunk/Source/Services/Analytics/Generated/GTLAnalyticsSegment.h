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
//  GTLAnalyticsSegment.h
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
//   GTLAnalyticsSegment (0 custom class methods, 9 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsSegment
//

// JSON template for an Analytics segment.

@interface GTLAnalyticsSegment : GTLObject

// Time the segment was created.
@property (nonatomic, retain) GTLDateTime *created;

// Segment definition.
@property (nonatomic, copy) NSString *definition;

// Segment ID.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Resource type for Analytics segment.
@property (nonatomic, copy) NSString *kind;

// Segment name.
@property (nonatomic, copy) NSString *name;

// Segment ID. Can be used with the 'segment' parameter in Core Reporting API.
@property (nonatomic, copy) NSString *segmentId;

// Link for this segment.
@property (nonatomic, copy) NSString *selfLink;

// Type for a segment. Possible values are "BUILT_IN" or "CUSTOM".
@property (nonatomic, copy) NSString *type;

// Time the segment was last modified.
@property (nonatomic, retain) GTLDateTime *updated;

@end
