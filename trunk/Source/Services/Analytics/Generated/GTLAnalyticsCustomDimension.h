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
//  GTLAnalyticsCustomDimension.h
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
//   GTLAnalyticsCustomDimension (0 custom class methods, 12 custom properties)
//   GTLAnalyticsCustomDimensionParentLink (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsCustomDimensionParentLink;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsCustomDimension
//

// JSON template for Analytics Custom Dimension.

@interface GTLAnalyticsCustomDimension : GTLObject

// Account ID.
@property (nonatomic, copy) NSString *accountId;

// Boolean indicating whether the custom dimension is active.
@property (nonatomic, retain) NSNumber *active;  // boolValue

// Time the custom dimension was created.
@property (nonatomic, retain) GTLDateTime *created;

// Custom dimension ID.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Index of the custom dimension.
@property (nonatomic, retain) NSNumber *index;  // intValue

// Kind value for a custom dimension. Set to "analytics#customDimension". It is
// a read-only field.
@property (nonatomic, copy) NSString *kind;

// Name of the custom dimension.
@property (nonatomic, copy) NSString *name;

// Parent link for the custom dimension. Points to the property to which the
// custom dimension belongs.
@property (nonatomic, retain) GTLAnalyticsCustomDimensionParentLink *parentLink;

// Scope of the custom dimension: HIT, SESSION, USER or PRODUCT.
@property (nonatomic, copy) NSString *scope;

// Link for the custom dimension
@property (nonatomic, copy) NSString *selfLink;

// Time the custom dimension was last modified.
@property (nonatomic, retain) GTLDateTime *updated;

// Property ID.
@property (nonatomic, copy) NSString *webPropertyId;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsCustomDimensionParentLink
//

@interface GTLAnalyticsCustomDimensionParentLink : GTLObject

// Link to the property to which the custom dimension belongs.
@property (nonatomic, copy) NSString *href;

// Type of the parent link. Set to "analytics#webproperty".
@property (nonatomic, copy) NSString *type;

@end
