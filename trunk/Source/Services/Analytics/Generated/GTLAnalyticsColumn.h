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
//  GTLAnalyticsColumn.h
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
//   GTLAnalyticsColumn (0 custom class methods, 3 custom properties)
//   GTLAnalyticsColumnAttributes (0 custom class methods, 0 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsColumnAttributes;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsColumn
//

// JSON template for a metadata column.

@interface GTLAnalyticsColumn : GTLObject

// Map of attribute name and value for this column.
@property (nonatomic, retain) GTLAnalyticsColumnAttributes *attributes;

// Column id.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Resource type for Analytics column.
@property (nonatomic, copy) NSString *kind;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsColumnAttributes
//

@interface GTLAnalyticsColumnAttributes : GTLObject
// This object is documented as having more properties that are NSString. Use
// -additionalJSONKeys and -additionalPropertyForName: to get the list of
// properties and then fetch them; or -additionalProperties to fetch them all at
// once.
@end
