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
//  GTLYouTubeAnalyticsBatchReportDefinitionTemplate.h
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
//   GTLYouTubeAnalyticsBatchReportDefinitionTemplate (0 custom class methods, 5 custom properties)
//   GTLYouTubeAnalyticsBatchReportDefinitionTemplateDefaultOutputItem (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubeAnalyticsBatchReportDefinitionTemplateDefaultOutputItem;

// ----------------------------------------------------------------------------
//
//   GTLYouTubeAnalyticsBatchReportDefinitionTemplate
//

// Contains single batchReportDefinition resource.

@interface GTLYouTubeAnalyticsBatchReportDefinitionTemplate : GTLObject

// Default report definition's output.
@property (retain) NSArray *defaultOutput;  // of GTLYouTubeAnalyticsBatchReportDefinitionTemplateDefaultOutputItem

// The ID that YouTube assigns and uses to uniquely identify the report
// definition.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Name of the report definition.
@property (copy) NSString *name;

// Status of the report definition.
@property (copy) NSString *status;

// Type of the report definition.
@property (copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLYouTubeAnalyticsBatchReportDefinitionTemplateDefaultOutputItem
//

@interface GTLYouTubeAnalyticsBatchReportDefinitionTemplateDefaultOutputItem : GTLObject

// Format of the output.
@property (copy) NSString *format;

// Type of the output.
@property (copy) NSString *type;

@end
