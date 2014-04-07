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
//  GTLYouTubeAnalyticsBatchReportDefinitionList.h
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
//   GTLYouTubeAnalyticsBatchReportDefinitionList (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeAnalyticsBatchReportDefinitionTemplate;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeAnalyticsBatchReportDefinitionList
//

// A paginated list of batchReportDefinition resources returned in response to a
// youtubeAnalytics.batchReportDefinitions.list request.

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLYouTubeAnalyticsBatchReportDefinitionList : GTLCollectionObject

// A list of batchReportDefinition resources that match the request criteria.
@property (retain) NSArray *items;  // of GTLYouTubeAnalyticsBatchReportDefinitionTemplate

// This value specifies the type of data included in the API response. For the
// list method, the kind property value is
// youtubeAnalytics#batchReportDefinitionList.
@property (copy) NSString *kind;

@end
