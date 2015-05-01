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
//  GTLMapsEngineFeaturesListResponse.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Maps Engine API (mapsengine/v1)
// Description:
//   The Google Maps Engine API allows developers to store and query geospatial
//   vector and raster data.
// Documentation:
//   https://developers.google.com/maps-engine/
// Classes:
//   GTLMapsEngineFeaturesListResponse (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLMapsEngineFeature;
@class GTLMapsEngineSchema;

// ----------------------------------------------------------------------------
//
//   GTLMapsEngineFeaturesListResponse
//

// The response returned by a call to features.List.

@interface GTLMapsEngineFeaturesListResponse : GTLObject

// An indicator of the maximum rate at which queries may be made, if all queries
// were as expensive as this query.
@property (nonatomic, retain) NSNumber *allowedQueriesPerSecond;  // doubleValue

// Resources returned.
@property (nonatomic, retain) NSArray *features;  // of GTLMapsEngineFeature

// Next page token.
@property (nonatomic, copy) NSString *nextPageToken;

// The feature schema.
@property (nonatomic, retain) GTLMapsEngineSchema *schema;

@property (nonatomic, copy) NSString *type;
@end
