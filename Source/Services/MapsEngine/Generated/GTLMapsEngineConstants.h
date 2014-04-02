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
//  GTLMapsEngineConstants.h
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

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// View and manage your Google Maps Engine data
GTL_EXTERN NSString * const kGTLAuthScopeMapsEngine;          // "https://www.googleapis.com/auth/mapsengine"
// View your Google Maps Engine data
GTL_EXTERN NSString * const kGTLAuthScopeMapsEngineReadonly;  // "https://www.googleapis.com/auth/mapsengine.readonly"

// Type
GTL_EXTERN NSString * const kGTLMapsEngineTypeLayer;            // "layer"
GTL_EXTERN NSString * const kGTLMapsEngineTypeMap;              // "map"
GTL_EXTERN NSString * const kGTLMapsEngineTypeRasterCollection;  // "rasterCollection"
GTL_EXTERN NSString * const kGTLMapsEngineTypeTable;            // "table"

// Version
GTL_EXTERN NSString * const kGTLMapsEngineVersionDraft;      // "draft"
GTL_EXTERN NSString * const kGTLMapsEngineVersionPublished;  // "published"
