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
//  GTLServiceMapsEngine.m
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
//   GTLServiceMapsEngine (0 custom class methods, 0 custom properties)

#import "GTLMapsEngine.h"

@implementation GTLServiceMapsEngine

#if DEBUG
// Method compiled in debug builds just to check that all the needed support
// classes are present at link time.
+ (NSArray *)checkClasses {
  NSArray *classes = @[
    [GTLQueryMapsEngine class],
    [GTLMapsEngineAcquisitionTime class],
    [GTLMapsEngineAsset class],
    [GTLMapsEngineAssetsListResponse class],
    [GTLMapsEngineBorder class],
    [GTLMapsEngineColor class],
    [GTLMapsEngineDatasource class],
    [GTLMapsEngineDisplayRule class],
    [GTLMapsEngineFeature class],
    [GTLMapsEngineFeatureInfo class],
    [GTLMapsEngineFeaturesListResponse class],
    [GTLMapsEngineFile class],
    [GTLMapsEngineFilter class],
    [GTLMapsEngineGeoJsonGeometry class],
    [GTLMapsEngineGeoJsonGeometryCollection class],
    [GTLMapsEngineGeoJsonLineString class],
    [GTLMapsEngineGeoJsonMultiLineString class],
    [GTLMapsEngineGeoJsonMultiPoint class],
    [GTLMapsEngineGeoJsonMultiPolygon class],
    [GTLMapsEngineGeoJsonPoint class],
    [GTLMapsEngineGeoJsonPolygon class],
    [GTLMapsEngineGeoJsonProperties class],
    [GTLMapsEngineIcon class],
    [GTLMapsEngineIconsListResponse class],
    [GTLMapsEngineIconStyle class],
    [GTLMapsEngineLabelStyle class],
    [GTLMapsEngineLayer class],
    [GTLMapsEngineLayersListResponse class],
    [GTLMapsEngineLineStyle class],
    [GTLMapsEngineMap class],
    [GTLMapsEngineMapFolder class],
    [GTLMapsEngineMapItem class],
    [GTLMapsEngineMapKmlLink class],
    [GTLMapsEngineMapLayer class],
    [GTLMapsEngineMapsListResponse class],
    [GTLMapsEngineParent class],
    [GTLMapsEngineParentsListResponse class],
    [GTLMapsEnginePermission class],
    [GTLMapsEnginePermissionsBatchDeleteRequest class],
    [GTLMapsEnginePermissionsBatchDeleteResponse class],
    [GTLMapsEnginePermissionsBatchUpdateRequest class],
    [GTLMapsEnginePermissionsBatchUpdateResponse class],
    [GTLMapsEnginePermissionsListResponse class],
    [GTLMapsEnginePointStyle class],
    [GTLMapsEnginePolygonStyle class],
    [GTLMapsEngineProcessResponse class],
    [GTLMapsEngineProject class],
    [GTLMapsEngineProjectsListResponse class],
    [GTLMapsEnginePublishedLayer class],
    [GTLMapsEnginePublishedLayersListResponse class],
    [GTLMapsEnginePublishedMap class],
    [GTLMapsEnginePublishedMapsListResponse class],
    [GTLMapsEnginePublishResponse class],
    [GTLMapsEngineRaster class],
    [GTLMapsEngineRasterCollection class],
    [GTLMapsEngineRasterCollectionsListResponse class],
    [GTLMapsEngineRasterCollectionsRaster class],
    [GTLMapsEngineRasterCollectionsRasterBatchDeleteRequest class],
    [GTLMapsEngineRasterCollectionsRastersBatchDeleteResponse class],
    [GTLMapsEngineRasterCollectionsRastersBatchInsertRequest class],
    [GTLMapsEngineRasterCollectionsRastersBatchInsertResponse class],
    [GTLMapsEngineRasterCollectionsRastersListResponse class],
    [GTLMapsEngineRastersListResponse class],
    [GTLMapsEngineScaledShape class],
    [GTLMapsEngineScalingFunction class],
    [GTLMapsEngineSchema class],
    [GTLMapsEngineSizeRange class],
    [GTLMapsEngineTable class],
    [GTLMapsEngineTableColumn class],
    [GTLMapsEngineTablesListResponse class],
    [GTLMapsEngineValueRange class],
    [GTLMapsEngineVectorStyle class],
    [GTLMapsEngineZoomLevels class]
  ];
  return classes;
}
#endif  // DEBUG

- (instancetype)init {
  self = [super init];
  if (self) {
    // Version from discovery.
    self.apiVersion = @"v1";

    // From discovery.  Where to send JSON-RPC.
    // Turn off prettyPrint for this service to save bandwidth (especially on
    // mobile). The fetcher logging will pretty print.
    self.rpcURL = [NSURL URLWithString:@"https://www.googleapis.com/rpc?prettyPrint=false"];
    self.rpcUploadURL = [NSURL URLWithString:@"https://www.googleapis.com/upload/rpc?uploadType=resumable&prettyPrint=false"];
  }
  return self;
}

@end
