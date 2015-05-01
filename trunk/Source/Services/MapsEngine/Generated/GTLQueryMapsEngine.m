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
//   GTLQueryMapsEngine (77 custom class methods, 32 custom properties)

#import "GTLQueryMapsEngine.h"

#import "GTLMapsEngineAsset.h"
#import "GTLMapsEngineAssetsListResponse.h"
#import "GTLMapsEngineFeature.h"
#import "GTLMapsEngineFeaturesListResponse.h"
#import "GTLMapsEngineIcon.h"
#import "GTLMapsEngineIconsListResponse.h"
#import "GTLMapsEngineLayer.h"
#import "GTLMapsEngineLayersListResponse.h"
#import "GTLMapsEngineMap.h"
#import "GTLMapsEngineMapsListResponse.h"
#import "GTLMapsEngineParentsListResponse.h"
#import "GTLMapsEnginePermissionsBatchDeleteRequest.h"
#import "GTLMapsEnginePermissionsBatchDeleteResponse.h"
#import "GTLMapsEnginePermissionsBatchUpdateRequest.h"
#import "GTLMapsEnginePermissionsBatchUpdateResponse.h"
#import "GTLMapsEnginePermissionsListResponse.h"
#import "GTLMapsEngineProcessResponse.h"
#import "GTLMapsEngineProjectsListResponse.h"
#import "GTLMapsEnginePublishedLayer.h"
#import "GTLMapsEnginePublishedLayersListResponse.h"
#import "GTLMapsEnginePublishedMap.h"
#import "GTLMapsEnginePublishedMapsListResponse.h"
#import "GTLMapsEnginePublishResponse.h"
#import "GTLMapsEngineRaster.h"
#import "GTLMapsEngineRasterCollection.h"
#import "GTLMapsEngineRasterCollectionsListResponse.h"
#import "GTLMapsEngineRasterCollectionsRasterBatchDeleteRequest.h"
#import "GTLMapsEngineRasterCollectionsRastersBatchDeleteResponse.h"
#import "GTLMapsEngineRasterCollectionsRastersBatchInsertRequest.h"
#import "GTLMapsEngineRasterCollectionsRastersBatchInsertResponse.h"
#import "GTLMapsEngineRasterCollectionsRastersListResponse.h"
#import "GTLMapsEngineRastersListResponse.h"
#import "GTLMapsEngineTable.h"
#import "GTLMapsEngineTablesListResponse.h"

@implementation GTLQueryMapsEngine

@dynamic bbox, createdAfter, createdBefore, creatorEmail, features, fields,
         filename, force, gxIds, identifier, include, intersects, limit,
         maxResults, modifiedAfter, modifiedBefore, normalizeGeometries,
         orderBy, pageToken, primaryKeys, process, processingStatus, projectId,
         request, role, search, select, tableId, tags, type, version, where;

+ (NSDictionary *)parameterNameMap {
  NSDictionary *map = @{
    @"gxIds" : @"gx_ids",
    @"identifier" : @"id"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"features" : [GTLMapsEngineFeature class],
    @"gx_ids" : [NSString class],
    @"primaryKeys" : [NSString class]
  };
  return map;
}

#pragma mark -
#pragma mark "assets" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForAssetsGetWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.assets.get";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineAsset class];
  return query;
}

+ (instancetype)queryForAssetsList {
  NSString *methodName = @"mapsengine.assets.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineAssetsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "assets.parents" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForAssetsParentsListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.assets.parents.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineParentsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "assets.permissions" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForAssetsPermissionsListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.assets.permissions.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePermissionsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "layers" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForLayersCancelProcessingWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.cancelProcessing";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineProcessResponse class];
  return query;
}

+ (instancetype)queryForLayersCreate {
  NSString *methodName = @"mapsengine.layers.create";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineLayer class];
  return query;
}

+ (instancetype)queryForLayersDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.delete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (instancetype)queryForLayersGetWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.get";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineLayer class];
  return query;
}

+ (instancetype)queryForLayersGetPublishedWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.getPublished";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePublishedLayer class];
  return query;
}

+ (instancetype)queryForLayersList {
  NSString *methodName = @"mapsengine.layers.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineLayersListResponse class];
  return query;
}

+ (instancetype)queryForLayersListPublished {
  NSString *methodName = @"mapsengine.layers.listPublished";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEnginePublishedLayersListResponse class];
  return query;
}

#pragma mark -
#pragma mark "layers.parents" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForLayersParentsListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.parents.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineParentsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "layers" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForLayersPatchWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.patch";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

#pragma mark -
#pragma mark "layers.permissions" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForLayersPermissionsBatchDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.permissions.batchDelete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePermissionsBatchDeleteResponse class];
  return query;
}

+ (instancetype)queryForLayersPermissionsBatchUpdateWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.permissions.batchUpdate";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePermissionsBatchUpdateResponse class];
  return query;
}

+ (instancetype)queryForLayersPermissionsListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.permissions.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePermissionsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "layers" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForLayersProcessWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.process";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineProcessResponse class];
  return query;
}

+ (instancetype)queryForLayersPublishWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.publish";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePublishResponse class];
  return query;
}

+ (instancetype)queryForLayersUnpublishWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.layers.unpublish";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePublishResponse class];
  return query;
}

#pragma mark -
#pragma mark "maps" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForMapsCreate {
  NSString *methodName = @"mapsengine.maps.create";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineMap class];
  return query;
}

+ (instancetype)queryForMapsDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.maps.delete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (instancetype)queryForMapsGetWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.maps.get";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineMap class];
  return query;
}

+ (instancetype)queryForMapsGetPublishedWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.maps.getPublished";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePublishedMap class];
  return query;
}

+ (instancetype)queryForMapsList {
  NSString *methodName = @"mapsengine.maps.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineMapsListResponse class];
  return query;
}

+ (instancetype)queryForMapsListPublished {
  NSString *methodName = @"mapsengine.maps.listPublished";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEnginePublishedMapsListResponse class];
  return query;
}

+ (instancetype)queryForMapsPatchWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.maps.patch";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

#pragma mark -
#pragma mark "maps.permissions" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForMapsPermissionsBatchDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.maps.permissions.batchDelete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePermissionsBatchDeleteResponse class];
  return query;
}

+ (instancetype)queryForMapsPermissionsBatchUpdateWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.maps.permissions.batchUpdate";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePermissionsBatchUpdateResponse class];
  return query;
}

+ (instancetype)queryForMapsPermissionsListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.maps.permissions.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePermissionsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "maps" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForMapsPublishWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.maps.publish";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePublishResponse class];
  return query;
}

+ (instancetype)queryForMapsUnpublishWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.maps.unpublish";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePublishResponse class];
  return query;
}

#pragma mark -
#pragma mark "projects.icons" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForProjectsIconsCreateWithProjectId:(NSString *)projectId
                                        uploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  NSString *methodName = @"mapsengine.projects.icons.create";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLMapsEngineIcon class];
  return query;
}

+ (instancetype)queryForProjectsIconsGetWithProjectId:(NSString *)projectId
                                           identifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.projects.icons.get";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineIcon class];
  return query;
}

+ (instancetype)queryForProjectsIconsListWithProjectId:(NSString *)projectId {
  NSString *methodName = @"mapsengine.projects.icons.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.expectedObjectClass = [GTLMapsEngineIconsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "projects" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForProjectsList {
  NSString *methodName = @"mapsengine.projects.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineProjectsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "rasterCollections" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForRasterCollectionsCancelProcessingWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.cancelProcessing";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineProcessResponse class];
  return query;
}

+ (instancetype)queryForRasterCollectionsCreate {
  NSString *methodName = @"mapsengine.rasterCollections.create";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineRasterCollection class];
  return query;
}

+ (instancetype)queryForRasterCollectionsDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.delete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (instancetype)queryForRasterCollectionsGetWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.get";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineRasterCollection class];
  return query;
}

+ (instancetype)queryForRasterCollectionsList {
  NSString *methodName = @"mapsengine.rasterCollections.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineRasterCollectionsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "rasterCollections.parents" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForRasterCollectionsParentsListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.parents.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineParentsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "rasterCollections" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForRasterCollectionsPatchWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.patch";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

#pragma mark -
#pragma mark "rasterCollections.permissions" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForRasterCollectionsPermissionsBatchDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.permissions.batchDelete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePermissionsBatchDeleteResponse class];
  return query;
}

+ (instancetype)queryForRasterCollectionsPermissionsBatchUpdateWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.permissions.batchUpdate";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePermissionsBatchUpdateResponse class];
  return query;
}

+ (instancetype)queryForRasterCollectionsPermissionsListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.permissions.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePermissionsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "rasterCollections" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForRasterCollectionsProcessWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.process";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineProcessResponse class];
  return query;
}

#pragma mark -
#pragma mark "rasterCollections.rasters" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForRasterCollectionsRastersBatchDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.rasters.batchDelete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineRasterCollectionsRastersBatchDeleteResponse class];
  return query;
}

+ (instancetype)queryForRasterCollectionsRastersBatchInsertWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.rasters.batchInsert";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineRasterCollectionsRastersBatchInsertResponse class];
  return query;
}

+ (instancetype)queryForRasterCollectionsRastersListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasterCollections.rasters.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineRasterCollectionsRastersListResponse class];
  return query;
}

#pragma mark -
#pragma mark "rasters" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForRastersDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasters.delete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

#pragma mark -
#pragma mark "rasters.files" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForRastersFilesInsertWithIdentifier:(NSString *)identifier
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

+ (instancetype)queryForRastersGetWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasters.get";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineRaster class];
  return query;
}

+ (instancetype)queryForRastersListWithProjectId:(NSString *)projectId {
  NSString *methodName = @"mapsengine.rasters.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.expectedObjectClass = [GTLMapsEngineRastersListResponse class];
  return query;
}

#pragma mark -
#pragma mark "rasters.parents" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForRastersParentsListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasters.parents.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineParentsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "rasters" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForRastersPatchWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasters.patch";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

#pragma mark -
#pragma mark "rasters.permissions" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForRastersPermissionsBatchDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasters.permissions.batchDelete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePermissionsBatchDeleteResponse class];
  return query;
}

+ (instancetype)queryForRastersPermissionsBatchUpdateWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasters.permissions.batchUpdate";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePermissionsBatchUpdateResponse class];
  return query;
}

+ (instancetype)queryForRastersPermissionsListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasters.permissions.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePermissionsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "rasters" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForRastersProcessWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.rasters.process";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineProcessResponse class];
  return query;
}

+ (instancetype)queryForRastersUpload {
  NSString *methodName = @"mapsengine.rasters.upload";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineRaster class];
  return query;
}

#pragma mark -
#pragma mark "tables" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForTablesCreate {
  NSString *methodName = @"mapsengine.tables.create";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineTable class];
  return query;
}

+ (instancetype)queryForTablesDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.delete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

#pragma mark -
#pragma mark "tables.features" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForTablesFeaturesBatchDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.features.batchDelete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (instancetype)queryForTablesFeaturesBatchInsertWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.features.batchInsert";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (instancetype)queryForTablesFeaturesBatchPatchWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.features.batchPatch";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

+ (instancetype)queryForTablesFeaturesGetWithTableId:(NSString *)tableId {
  NSString *methodName = @"mapsengine.tables.features.get";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.tableId = tableId;
  query.expectedObjectClass = [GTLMapsEngineFeature class];
  return query;
}

+ (instancetype)queryForTablesFeaturesListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.features.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineFeaturesListResponse class];
  return query;
}

#pragma mark -
#pragma mark "tables.files" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForTablesFilesInsertWithIdentifier:(NSString *)identifier
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

+ (instancetype)queryForTablesGetWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.get";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineTable class];
  return query;
}

+ (instancetype)queryForTablesList {
  NSString *methodName = @"mapsengine.tables.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineTablesListResponse class];
  return query;
}

#pragma mark -
#pragma mark "tables.parents" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForTablesParentsListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.parents.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineParentsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "tables" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForTablesPatchWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.patch";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  return query;
}

#pragma mark -
#pragma mark "tables.permissions" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForTablesPermissionsBatchDeleteWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.permissions.batchDelete";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePermissionsBatchDeleteResponse class];
  return query;
}

+ (instancetype)queryForTablesPermissionsBatchUpdateWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.permissions.batchUpdate";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePermissionsBatchUpdateResponse class];
  return query;
}

+ (instancetype)queryForTablesPermissionsListWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.permissions.list";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEnginePermissionsListResponse class];
  return query;
}

#pragma mark -
#pragma mark "tables" methods
// These create a GTLQueryMapsEngine object.

+ (instancetype)queryForTablesProcessWithIdentifier:(NSString *)identifier {
  NSString *methodName = @"mapsengine.tables.process";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.identifier = identifier;
  query.expectedObjectClass = [GTLMapsEngineProcessResponse class];
  return query;
}

+ (instancetype)queryForTablesUpload {
  NSString *methodName = @"mapsengine.tables.upload";
  GTLQueryMapsEngine *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLMapsEngineTable class];
  return query;
}

@end
