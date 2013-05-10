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
//  GTLAdSenseReportingMetadataEntry.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Management API (adsense/v1.3)
// Description:
//   Gives AdSense publishers access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://developers.google.com/adsense/management/
// Classes:
//   GTLAdSenseReportingMetadataEntry (0 custom class methods, 7 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLAdSenseReportingMetadataEntry
//

@interface GTLAdSenseReportingMetadataEntry : GTLObject

// For metrics this is a list of dimension IDs which the metric is compatible
// with, for dimensions it is a list of compatibility groups the dimension
// belongs to.
@property (retain) NSArray *compatibleDimensions;  // of NSString

// The names of the metrics the dimension or metric this reporting metadata
// entry describes is compatible with.
@property (retain) NSArray *compatibleMetrics;  // of NSString

// Unique identifier of this reporting metadata entry, corresponding to the name
// of the appropriate dimension or metric.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Kind of resource this is, in this case adsense#reportingMetadataEntry.
@property (copy) NSString *kind;

// The names of the dimensions which the dimension or metric this reporting
// metadata entry describes requires to also be present in order for the report
// to be valid. Omitting these will not cause an error or warning, but may
// result in data which cannot be correctly interpreted.
@property (retain) NSArray *requiredDimensions;  // of NSString

// The names of the metrics which the dimension or metric this reporting
// metadata entry describes requires to also be present in order for the report
// to be valid. Omitting these will not cause an error or warning, but may
// result in data which cannot be correctly interpreted.
@property (retain) NSArray *requiredMetrics;  // of NSString

// The codes of the projects supported by the dimension or metric this reporting
// metadata entry describes.
@property (retain) NSArray *supportedProducts;  // of NSString

@end
