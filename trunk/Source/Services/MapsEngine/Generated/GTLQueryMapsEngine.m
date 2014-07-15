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
//  GTLQueryMapsEngine.m
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
//   GTLQueryMapsEngine (51 custom class methods, 27 custom properties)

#import "GTLQueryMapsEngine.h"

#import "GTLMapsEngineAsset.h"
#import "GTLMapsEngineAssetsListResponse.h"
#import "GTLMapsEngineFeature.h"
#import "GTLMapsEngineFeaturesListResponse.h"
#import "GTLMapsEngineLayer.h"
#import "GTLMapsEngineLayersListResponse.h"
#import "GTLMapsEngineMap.h"
#import "GTLMapsEngineMapsListResponse.h"
#import "GTLMapsEngineParentsListResponse.h"
#import "GTLMapsEngineProcessResponse.h"
#import "GTLMapsEngineProjectsListResponse.h"
#import "GTLMapsEnginePublishResponse.h"
#import "GTLMapsEngineRaster.h"
#import "GTLMapsEngineRasterCollection.h"
#import "GTLMapsEngineRasterCollectionsListResponse.h"
#import "GTLMapsEngineRasterCollectionsRasterBatchDeleteRequest.h"
#import "GTLMapsEngineRasterCollectionsRastersBatchDeleteResponse.h"
#import "GTLMapsEngineRasterCollectionsRastersBatchInsertRequest.h"
#import "GTLMapsEngineRasterCollectionsRastersBatchInsertResponse.h"
#import "GTLMapsEngineRasterCollectionsRastersListResponse.h"
#import "GTLMapsEngineTable.h"
#import "GTLMapsEngineTablesListResponse.h"

@implementation GTLQueryMapsEngine

@dynamic bbox, createdAfter, createdBefore, creatorEmail, features, fields,
         filename, gxIds, identifier, include, intersects, limit, maxResults,
         modifiedAfter, modifiedBefore, orderBy, pageToken, primaryKeys,
         process, projectId, request, select, tableId, tags, type, version,
         where;

+ (NSDictionary *)parameterNameMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"gx_ids", @"gxIds",
      @"id", @"identifier",
      nil];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLMapsEngineFeature class], @"features",
      [NSString class], @"gx_ids",
      [NSString class], @"primaryKeys",
      nil];
  return map;
}

#pragma mark -
#pragma mark "assets" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForAssetsGetWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.assets.get";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineAsset class];
  return query;
}

+ (id)queryForAssetsList {
  NSString *methodName = @"mapsengine.assets.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineAssetsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "assets.parents" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForAssetsParentsListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.assets.parents.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineParentsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "layers" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForLayersCancelProcessingWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.cancelProcessing";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineProcessResponse class];
  return query;
}

+ (id)queryForLayersCreate {
  NSString *methodName = @"mapsengine.layers.create";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineLayer class];
  return query;
}

+ (id)queryForLayersDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.delete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (id)queryForLayersGetWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.get";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineLayer class];
  return query;
}

+ (id)queryForLayersList {
  NSString *methodName = @"mapsengine.layers.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineLayersListResponse class];
  return query;
}

#pragma mark -
#pragma mark "layers.parents" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForLayersParentsListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.parents.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineParentsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "layers" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForLayersPatchWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.patch";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (id)queryForLayersProcessWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.process";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineProcessResponse class];
  return query;
}

+ (id)queryForLayersPublishWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.publish";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePublishResponse class];
  return query;
}

+ (id)queryForLayersUnpublishWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.unpublish";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePublishResponse class];
  return query;
}

#pragma mark -
#pragma mark "maps" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForMapsCreate {
  NSString *methodName = @"mapsengine.maps.create";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineMap class];
  return query;
}

+ (id)queryForMapsDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.maps.delete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (id)queryForMapsGetWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.maps.get";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineMap class];
  return query;
}

+ (id)queryForMapsList {
  NSString *methodName = @"mapsengine.maps.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineMapsListResponse class];
  return query;
}

+ (id)queryForMapsPatchWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.maps.patch";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (id)queryForMapsPublishWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.maps.publish";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePublishResponse class];
  return query;
}

+ (id)queryForMapsUnpublishWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.maps.unpublish";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePublishResponse class];
  return query;
}

#pragma mark -
#pragma mark "projects" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForProjectsList {
  NSString *methodName = @"mapsengine.projects.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineProjectsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "rasterCollections" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForRasterCollectionsCancelProcessingWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.cancelProcessing";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineProcessResponse class];
  return query;
}

+ (id)queryForRasterCollectionsCreate {
  NSString *methodName = @"mapsengine.rasterCollections.create";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineRasterCollection class];
  return query;
}

+ (id)queryForRasterCollectionsDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.delete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (id)queryForRasterCollectionsGetWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.get";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineRasterCollection class];
  return query;
}

+ (id)queryForRasterCollectionsList {
  NSString *methodName = @"mapsengine.rasterCollections.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineRasterCollectionsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "rasterCollections.parents" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForRasterCollectionsParentsListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.parents.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineParentsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "rasterCollections" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForRasterCollectionsPatchWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.patch";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (id)queryForRasterCollectionsProcessWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.process";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineProcessResponse class];
  return query;
}

#pragma mark -
#pragma mark "rasterCollections.rasters" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForRasterCollectionsRastersBatchDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.rasters.batchDelete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineRasterCollectionsRastersBatchDeleteResponse class];
  return query;
}

+ (id)queryForRasterCollectionsRastersBatchInsertWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.rasters.batchInsert";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineRasterCollectionsRastersBatchInsertResponse class];
  return query;
}

+ (id)queryForRasterCollectionsRastersListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.rasters.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineRasterCollectionsRastersListResponse class];
  return query;
}

#pragma mark -
#pragma mark "rasters" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForRastersDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasters.delete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

#pragma mark -
#pragma mark "rasters.files" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForRastersFilesInsertWithIdentifier:(NSString *)identifier
                                      filename:(NSString *)filename
                              uploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"mapsengine.rasters.files.insert";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.filename = filename;
  query.uploadParameters = uploadParametersOrNil;
  return query;
}

#pragma mark -
#pragma mark "rasters" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForRastersGetWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasters.get";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineRaster class];
  return query;
}

#pragma mark -
#pragma mark "rasters.parents" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForRastersParentsListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasters.parents.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineParentsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "rasters" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForRastersPatchWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasters.patch";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (id)queryForRastersUpload {
  NSString *methodName = @"mapsengine.rasters.upload";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineRaster class];
  return query;
}

#pragma mark -
#pragma mark "tables" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForTablesCreate {
  NSString *methodName = @"mapsengine.tables.create";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineTable class];
  return query;
}

+ (id)queryForTablesDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.delete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

#pragma mark -
#pragma mark "tables.features" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForTablesFeaturesBatchDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.features.batchDelete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (id)queryForTablesFeaturesBatchInsertWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.features.batchInsert";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (id)queryForTablesFeaturesBatchPatchWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.features.batchPatch";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (id)queryForTablesFeaturesGetWithTableId:(NSString *)tableId {
  NSString *methodName = @"mapsengine.tables.features.get";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.tableId = tableId;
  query.expectedObjectClass = [GTLMapsEngineFeature class];
  return query;
}

+ (id)queryForTablesFeaturesListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.features.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineFeaturesListResponse class];
  return query;
}

#pragma mark -
#pragma mark "tables.files" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForTablesFilesInsertWithIdentifier:(NSString *)identifier
                                     filename:(NSString *)filename
                             uploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"mapsengine.tables.files.insert";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.filename = filename;
  query.uploadParameters = uploadParametersOrNil;
  return query;
}

#pragma mark -
#pragma mark "tables" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForTablesGetWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.get";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineTable class];
  return query;
}

+ (id)queryForTablesList {
  NSString *methodName = @"mapsengine.tables.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineTablesListResponse class];
  return query;
}

#pragma mark -
#pragma mark "tables.parents" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForTablesParentsListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.parents.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineParentsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "tables" methods
// These create a GTLQueryMapsEngine object.

+ (id)queryForTablesPatchWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.patch";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (id)queryForTablesUpload {
  NSString *methodName = @"mapsengine.tables.upload";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineTable class];
  return query;
}

@end
