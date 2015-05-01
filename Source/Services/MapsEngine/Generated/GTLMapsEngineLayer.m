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
//  GTLMapsEngineLayer.m
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
//   GTLMapsEngineLayer (0 custom class methods, 20 custom properties)

#import "GTLMapsEngineLayer.h"

#import "GTLMapsEngineDatasource.h"
#import "GTLMapsEngineVectorStyle.h"

// ----------------------------------------------------------------------------
//
//   GTLMapsEngineLayer
//

@implementation GTLMapsEngineLayer
@dynamic bbox, creationTime, creatorEmail, datasources, datasourceType,
         descriptionProperty, draftAccessList, ETag, identifier,
         lastModifiedTime, lastModifierEmail, layerType, name, processingStatus,
         projectId, publishedAccessList, publishingStatus, style, tags,
         writersCanEditPermissions;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"descriptionProperty" : @"description",
    @"ETag" : @"etag",
    @"identifier" : @"id"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"bbox" : [NSNumber class],
    @"datasources" : [GTLMapsEngineDatasource class],
    @"tags" : [NSString class]
  };
  return map;
}

@end
