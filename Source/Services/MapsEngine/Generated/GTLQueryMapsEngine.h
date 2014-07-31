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
//  GTLQueryMapsEngine.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLMapsEngineFeature;
@class GTLMapsEngineLayer;
@class GTLMapsEngineMap;
@class GTLMapsEngineRaster;
@class GTLMapsEngineRasterCollection;
@class GTLMapsEngineRasterCollectionsRasterBatchDeleteRequest;
@class GTLMapsEngineRasterCollectionsRastersBatchInsertRequest;
@class GTLMapsEngineTable;

@interface GTLQueryMapsEngine : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (copy) NSString *bbox;
@property (retain) GTLDateTime *createdAfter;
@property (retain) GTLDateTime *createdBefore;
@property (copy) NSString *creatorEmail;
@property (retain) NSArray *features;  // of GTLMapsEngineFeature
@property (copy) NSString *filename;
@property (retain) NSArray *gxIds;  // of NSString
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;
@property (copy) NSString *include;
@property (copy) NSString *intersects;
@property (assign) NSUInteger limit;
@property (assign) NSUInteger maxResults;
@property (retain) GTLDateTime *modifiedAfter;
@property (retain) GTLDateTime *modifiedBefore;
@property (copy) NSString *orderBy;
@property (copy) NSString *pageToken;
@property (retain) NSArray *primaryKeys;  // of NSString
@property (assign) BOOL process;
@property (copy) NSString *projectId;
// "request" has different types for some query methods; see the documentation
// for the right type for each query method.
@property (retain) id request;
@property (copy) NSString *select;
@property (copy) NSString *tableId;
@property (copy) NSString *tags;
@property (copy) NSString *type;
@property (copy) NSString *version;
@property (copy) NSString *where;

#pragma mark -
#pragma mark "assets" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.assets.get
// Return metadata for a particular asset.
//  Required:
//   identifier: The ID of the asset.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineAsset.
+ (id)queryForAssetsGetWithIdentifier:(NSString *)identifier;

// Method: mapsengine.assets.list
// Return all assets readable by the current user.
//  Optional:
//   bbox: A bounding box, expressed as "west,south,east,north". If set, only
//     assets which intersect this bounding box will be returned.
//   createdAfter: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been created at or after
//     this time.
//   createdBefore: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been created at or
//     before this time.
//   creatorEmail: An email address representing a user. Returned assets that
//     have been created by the user associated with the provided email address.
//   maxResults: The maximum number of items to include in a single response
//     page. The maximum supported value is 100.
//   modifiedAfter: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been modified at or
//     after this time.
//   modifiedBefore: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been modified at or
//     before this time.
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     nextPageToken from the previous response.
//   projectId: The ID of a Maps Engine project, used to filter the response. To
//     list all available projects with their IDs, send a Projects: list
//     request. You can also find your project ID as the value of the
//     DashboardPlace:cid URL parameter when signed in to mapsengine.google.com.
//   tags: A comma separated list of tags. Returned assets will contain all the
//     tags from the list.
//   type: An asset type restriction. If set, only resources of this type will
//     be returned.
//      kGTLMapsEngineTypeLayer: Return layers.
//      kGTLMapsEngineTypeMap: Return maps.
//      kGTLMapsEngineTypeRasterCollection: Return raster collections.
//      kGTLMapsEngineTypeTable: Return tables.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineAssetsListResponse.
+ (id)queryForAssetsList;

#pragma mark -
#pragma mark "assets.parents" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.assets.parents.list
// Return all parent ids of the specified asset.
//  Required:
//   identifier: The ID of the asset whose parents will be listed.
//  Optional:
//   maxResults: The maximum number of items to include in a single response
//     page. The maximum supported value is 50.
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     nextPageToken from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineParentsListResponse.
+ (id)queryForAssetsParentsListWithIdentifier:(NSString *)identifier;

#pragma mark -
#pragma mark "layers" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.layers.cancelProcessing
// Cancel processing on a layer asset.
//  Required:
//   identifier: The ID of the layer.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
// Fetches a GTLMapsEngineProcessResponse.
+ (id)queryForLayersCancelProcessingWithIdentifier:(NSString *)identifier;

// Method: mapsengine.layers.create
// Create a layer asset.
//  Optional:
//   request: For this method, "request" should be of type GTLMapsEngineLayer.
//   process: Whether to queue the created layer for processing.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
// Fetches a GTLMapsEngineLayer.
+ (id)queryForLayersCreate;

// Method: mapsengine.layers.delete
// Delete a layer.
//  Required:
//   identifier: The ID of the layer. Only the layer creator or project owner
//     are permitted to delete. If the layer is published, or included in a map,
//     the request will fail. Unpublish the layer, and remove it from all maps
//     prior to deleting.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
+ (id)queryForLayersDeleteWithIdentifier:(NSString *)identifier;

// Method: mapsengine.layers.get
// Return metadata for a particular layer.
//  Required:
//   identifier: The ID of the layer.
//  Optional:
//   version: NSString
//      kGTLMapsEngineVersionDraft: The draft version.
//      kGTLMapsEngineVersionPublished: The published version.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineLayer.
+ (id)queryForLayersGetWithIdentifier:(NSString *)identifier;

// Method: mapsengine.layers.list
// Return all layers readable by the current user.
//  Optional:
//   bbox: A bounding box, expressed as "west,south,east,north". If set, only
//     assets which intersect this bounding box will be returned.
//   createdAfter: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been created at or after
//     this time.
//   createdBefore: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been created at or
//     before this time.
//   creatorEmail: An email address representing a user. Returned assets that
//     have been created by the user associated with the provided email address.
//   maxResults: The maximum number of items to include in a single response
//     page. The maximum supported value is 100.
//   modifiedAfter: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been modified at or
//     after this time.
//   modifiedBefore: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been modified at or
//     before this time.
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     nextPageToken from the previous response.
//   projectId: The ID of a Maps Engine project, used to filter the response. To
//     list all available projects with their IDs, send a Projects: list
//     request. You can also find your project ID as the value of the
//     DashboardPlace:cid URL parameter when signed in to mapsengine.google.com.
//   tags: A comma separated list of tags. Returned assets will contain all the
//     tags from the list.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineLayersListResponse.
+ (id)queryForLayersList;

#pragma mark -
#pragma mark "layers.parents" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.layers.parents.list
// Return all parent ids of the specified layer.
//  Required:
//   identifier: The ID of the layer whose parents will be listed.
//  Optional:
//   maxResults: The maximum number of items to include in a single response
//     page. The maximum supported value is 50.
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     nextPageToken from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineParentsListResponse.
+ (id)queryForLayersParentsListWithIdentifier:(NSString *)identifier;

#pragma mark -
#pragma mark "layers" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.layers.patch
// Mutate a layer asset.
//  Required:
//   identifier: The ID of the layer.
//  Optional:
//   request: For this method, "request" should be of type GTLMapsEngineLayer.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
+ (id)queryForLayersPatchWithIdentifier:(NSString *)identifier;

// Method: mapsengine.layers.process
// Process a layer asset.
//  Required:
//   identifier: The ID of the layer.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
// Fetches a GTLMapsEngineProcessResponse.
+ (id)queryForLayersProcessWithIdentifier:(NSString *)identifier;

// Method: mapsengine.layers.publish
// Publish a layer asset.
//  Required:
//   identifier: The ID of the layer.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
// Fetches a GTLMapsEnginePublishResponse.
+ (id)queryForLayersPublishWithIdentifier:(NSString *)identifier;

// Method: mapsengine.layers.unpublish
// Unpublish a layer asset.
//  Required:
//   identifier: The ID of the layer.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
// Fetches a GTLMapsEnginePublishResponse.
+ (id)queryForLayersUnpublishWithIdentifier:(NSString *)identifier;

#pragma mark -
#pragma mark "maps" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.maps.create
// Create a map asset.
//  Optional:
//   request: For this method, "request" should be of type GTLMapsEngineMap.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
// Fetches a GTLMapsEngineMap.
+ (id)queryForMapsCreate;

// Method: mapsengine.maps.delete
// Delete a map.
//  Required:
//   identifier: The ID of the map. Only the map creator or project owner are
//     permitted to delete. If the map is published the request will fail.
//     Unpublish the map prior to deleting.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
+ (id)queryForMapsDeleteWithIdentifier:(NSString *)identifier;

// Method: mapsengine.maps.get
// Return metadata for a particular map.
//  Required:
//   identifier: The ID of the map.
//  Optional:
//   version: NSString
//      kGTLMapsEngineVersionDraft: The draft version.
//      kGTLMapsEngineVersionPublished: The published version.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineMap.
+ (id)queryForMapsGetWithIdentifier:(NSString *)identifier;

// Method: mapsengine.maps.list
// Return all maps readable by the current user.
//  Optional:
//   bbox: A bounding box, expressed as "west,south,east,north". If set, only
//     assets which intersect this bounding box will be returned.
//   createdAfter: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been created at or after
//     this time.
//   createdBefore: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been created at or
//     before this time.
//   creatorEmail: An email address representing a user. Returned assets that
//     have been created by the user associated with the provided email address.
//   maxResults: The maximum number of items to include in a single response
//     page. The maximum supported value is 100.
//   modifiedAfter: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been modified at or
//     after this time.
//   modifiedBefore: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been modified at or
//     before this time.
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     nextPageToken from the previous response.
//   projectId: The ID of a Maps Engine project, used to filter the response. To
//     list all available projects with their IDs, send a Projects: list
//     request. You can also find your project ID as the value of the
//     DashboardPlace:cid URL parameter when signed in to mapsengine.google.com.
//   tags: A comma separated list of tags. Returned assets will contain all the
//     tags from the list.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineMapsListResponse.
+ (id)queryForMapsList;

// Method: mapsengine.maps.patch
// Mutate a map asset.
//  Required:
//   identifier: The ID of the map.
//  Optional:
//   request: For this method, "request" should be of type GTLMapsEngineMap.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
+ (id)queryForMapsPatchWithIdentifier:(NSString *)identifier;

// Method: mapsengine.maps.publish
// Publish a map asset.
//  Required:
//   identifier: The ID of the map.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
// Fetches a GTLMapsEnginePublishResponse.
+ (id)queryForMapsPublishWithIdentifier:(NSString *)identifier;

// Method: mapsengine.maps.unpublish
// Unpublish a map asset.
//  Required:
//   identifier: The ID of the map.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
// Fetches a GTLMapsEnginePublishResponse.
+ (id)queryForMapsUnpublishWithIdentifier:(NSString *)identifier;

#pragma mark -
#pragma mark "projects" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.projects.list
// Return all projects readable by the current user.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineProjectsListResponse.
+ (id)queryForProjectsList;

#pragma mark -
#pragma mark "rasterCollections" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.rasterCollections.cancelProcessing
// Cancel processing on a raster collection asset.
//  Required:
//   identifier: The ID of the raster collection.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
// Fetches a GTLMapsEngineProcessResponse.
+ (id)queryForRasterCollectionsCancelProcessingWithIdentifier:(NSString *)identifier;

// Method: mapsengine.rasterCollections.create
// Create a raster collection asset.
//  Optional:
//   request: For this method, "request" should be of type
//     GTLMapsEngineRasterCollection.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
// Fetches a GTLMapsEngineRasterCollection.
+ (id)queryForRasterCollectionsCreate;

// Method: mapsengine.rasterCollections.delete
// Delete a raster collection.
//  Required:
//   identifier: The ID of the raster collection. Only the raster collection
//     creator or project owner are permitted to delete. If the rastor
//     collection is included in a layer, the request will fail. Remove the
//     raster collection from all layers prior to deleting.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
+ (id)queryForRasterCollectionsDeleteWithIdentifier:(NSString *)identifier;

// Method: mapsengine.rasterCollections.get
// Return metadata for a particular raster collection.
//  Required:
//   identifier: The ID of the raster collection.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineRasterCollection.
+ (id)queryForRasterCollectionsGetWithIdentifier:(NSString *)identifier;

// Method: mapsengine.rasterCollections.list
// Return all raster collections readable by the current user.
//  Optional:
//   bbox: A bounding box, expressed as "west,south,east,north". If set, only
//     assets which intersect this bounding box will be returned.
//   createdAfter: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been created at or after
//     this time.
//   createdBefore: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been created at or
//     before this time.
//   creatorEmail: An email address representing a user. Returned assets that
//     have been created by the user associated with the provided email address.
//   maxResults: The maximum number of items to include in a single response
//     page. The maximum supported value is 100.
//   modifiedAfter: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been modified at or
//     after this time.
//   modifiedBefore: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been modified at or
//     before this time.
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     nextPageToken from the previous response.
//   projectId: The ID of a Maps Engine project, used to filter the response. To
//     list all available projects with their IDs, send a Projects: list
//     request. You can also find your project ID as the value of the
//     DashboardPlace:cid URL parameter when signed in to mapsengine.google.com.
//   tags: A comma separated list of tags. Returned assets will contain all the
//     tags from the list.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineRasterCollectionsListResponse.
+ (id)queryForRasterCollectionsList;

#pragma mark -
#pragma mark "rasterCollections.parents" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.rasterCollections.parents.list
// Return all parent ids of the specified raster collection.
//  Required:
//   identifier: The ID of the raster collection whose parents will be listed.
//  Optional:
//   maxResults: The maximum number of items to include in a single response
//     page. The maximum supported value is 50.
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     nextPageToken from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineParentsListResponse.
+ (id)queryForRasterCollectionsParentsListWithIdentifier:(NSString *)identifier;

#pragma mark -
#pragma mark "rasterCollections" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.rasterCollections.patch
// Mutate a raster collection asset.
//  Required:
//   identifier: The ID of the raster collection.
//  Optional:
//   request: For this method, "request" should be of type
//     GTLMapsEngineRasterCollection.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
+ (id)queryForRasterCollectionsPatchWithIdentifier:(NSString *)identifier;

// Method: mapsengine.rasterCollections.process
// Process a raster collection asset.
//  Required:
//   identifier: The ID of the raster collection.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
// Fetches a GTLMapsEngineProcessResponse.
+ (id)queryForRasterCollectionsProcessWithIdentifier:(NSString *)identifier;

#pragma mark -
#pragma mark "rasterCollections.rasters" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.rasterCollections.rasters.batchDelete
// Remove rasters from an existing raster collection.
// Up to 50 rasters can be included in a single batchDelete request. Each
// batchDelete request is atomic.
//  Required:
//   identifier: The ID of the raster collection to which these rasters belong.
//  Optional:
//   request: For this method, "request" should be of type
//     GTLMapsEngineRasterCollectionsRasterBatchDeleteRequest.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
// Fetches a GTLMapsEngineRasterCollectionsRastersBatchDeleteResponse.
+ (id)queryForRasterCollectionsRastersBatchDeleteWithIdentifier:(NSString *)identifier;

// Method: mapsengine.rasterCollections.rasters.batchInsert
// Add rasters to an existing raster collection. Rasters must be successfully
// processed in order to be added to a raster collection.
// Up to 50 rasters can be included in a single batchInsert request. Each
// batchInsert request is atomic.
//  Required:
//   identifier: The ID of the raster collection to which these rasters belong.
//  Optional:
//   request: For this method, "request" should be of type
//     GTLMapsEngineRasterCollectionsRastersBatchInsertRequest.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
// Fetches a GTLMapsEngineRasterCollectionsRastersBatchInsertResponse.
+ (id)queryForRasterCollectionsRastersBatchInsertWithIdentifier:(NSString *)identifier;

// Method: mapsengine.rasterCollections.rasters.list
// Return all rasters within a raster collection.
//  Required:
//   identifier: The ID of the raster collection to which these rasters belong.
//  Optional:
//   bbox: A bounding box, expressed as "west,south,east,north". If set, only
//     assets which intersect this bounding box will be returned.
//   createdAfter: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been created at or after
//     this time.
//   createdBefore: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been created at or
//     before this time.
//   creatorEmail: An email address representing a user. Returned assets that
//     have been created by the user associated with the provided email address.
//   maxResults: The maximum number of items to include in a single response
//     page. The maximum supported value is 100.
//   modifiedAfter: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been modified at or
//     after this time.
//   modifiedBefore: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been modified at or
//     before this time.
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     nextPageToken from the previous response.
//   tags: A comma separated list of tags. Returned assets will contain all the
//     tags from the list.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineRasterCollectionsRastersListResponse.
+ (id)queryForRasterCollectionsRastersListWithIdentifier:(NSString *)identifier;

#pragma mark -
#pragma mark "rasters" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.rasters.delete
// Delete a raster.
//  Required:
//   identifier: The ID of the raster. Only the raster creator or project owner
//     are permitted to delete. If the raster is included in a layer or mosaic,
//     the request will fail. Remove it from all parents prior to deleting.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
+ (id)queryForRastersDeleteWithIdentifier:(NSString *)identifier;

#pragma mark -
#pragma mark "rasters.files" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.rasters.files.insert
// Upload a file to a raster asset.
//  Required:
//   identifier: The ID of the raster asset.
//   filename: The file name of this uploaded file.
//  Upload Parameters:
//   Maximum size: 10GB
//   Accepted MIME type(s): */*
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
+ (id)queryForRastersFilesInsertWithIdentifier:(NSString *)identifier
                                      filename:(NSString *)filename
                              uploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

#pragma mark -
#pragma mark "rasters" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.rasters.get
// Return metadata for a single raster.
//  Required:
//   identifier: The ID of the raster.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineRaster.
+ (id)queryForRastersGetWithIdentifier:(NSString *)identifier;

#pragma mark -
#pragma mark "rasters.parents" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.rasters.parents.list
// Return all parent ids of the specified rasters.
//  Required:
//   identifier: The ID of the rasters whose parents will be listed.
//  Optional:
//   maxResults: The maximum number of items to include in a single response
//     page. The maximum supported value is 50.
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     nextPageToken from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineParentsListResponse.
+ (id)queryForRastersParentsListWithIdentifier:(NSString *)identifier;

#pragma mark -
#pragma mark "rasters" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.rasters.patch
// Mutate a raster asset.
//  Required:
//   identifier: The ID of the raster.
//  Optional:
//   request: For this method, "request" should be of type GTLMapsEngineRaster.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
+ (id)queryForRastersPatchWithIdentifier:(NSString *)identifier;

// Method: mapsengine.rasters.upload
// Create a skeleton raster asset for upload.
//  Optional:
//   request: For this method, "request" should be of type GTLMapsEngineRaster.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
// Fetches a GTLMapsEngineRaster.
+ (id)queryForRastersUpload;

#pragma mark -
#pragma mark "tables" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.tables.create
// Create a table asset.
//  Optional:
//   request: For this method, "request" should be of type GTLMapsEngineTable.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
// Fetches a GTLMapsEngineTable.
+ (id)queryForTablesCreate;

// Method: mapsengine.tables.delete
// Delete a table.
//  Required:
//   identifier: The ID of the table. Only the table creator or project owner
//     are permitted to delete. If the table is included in a layer, the request
//     will fail. Remove it from all layers prior to deleting.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
+ (id)queryForTablesDeleteWithIdentifier:(NSString *)identifier;

#pragma mark -
#pragma mark "tables.features" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.tables.features.batchDelete
// Delete all features matching the given IDs.
//  Required:
//   identifier: The ID of the table that contains the features to be deleted.
//  Optional:
//   gxIds: NSArray
//   primaryKeys: NSArray
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
+ (id)queryForTablesFeaturesBatchDeleteWithIdentifier:(NSString *)identifier;

// Method: mapsengine.tables.features.batchInsert
// Append features to an existing table.
// A single batchInsert request can create:
// - Up to 50 features.
// - A combined total of 10 000 vertices.
// Feature limits are documented in the Supported data formats and limits
// article of the Google Maps Engine help center. Note that free and paid
// accounts have different limits.
// For more information about inserting features, read Creating features in the
// Google Maps Engine developer's guide.
//  Required:
//   identifier: The ID of the table to append the features to.
//  Optional:
//   features: NSArray
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
+ (id)queryForTablesFeaturesBatchInsertWithIdentifier:(NSString *)identifier;

// Method: mapsengine.tables.features.batchPatch
// Update the supplied features.
// A single batchPatch request can update:
// - Up to 50 features.
// - A combined total of 10 000 vertices.
// Feature limits are documented in the Supported data formats and limits
// article of the Google Maps Engine help center. Note that free and paid
// accounts have different limits.
// Feature updates use HTTP PATCH semantics:
// - A supplied value replaces an existing value (if any) in that field.
// - Omitted fields remain unchanged.
// - Complex values in geometries and properties must be replaced as atomic
// units. For example, providing just the coordinates of a geometry is not
// allowed; the complete geometry, including type, must be supplied.
// - Setting a property's value to null deletes that property.
// For more information about updating features, read Updating features in the
// Google Maps Engine developer's guide.
//  Required:
//   identifier: The ID of the table containing the features to be patched.
//  Optional:
//   features: NSArray
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
+ (id)queryForTablesFeaturesBatchPatchWithIdentifier:(NSString *)identifier;

// Method: mapsengine.tables.features.get
// Return a single feature, given its ID.
//  Required:
//   tableId: The ID of the table.
//  Optional:
//   identifier: The ID of the feature to get.
//   select: A SQL-like projection clause used to specify returned properties.
//     If this parameter is not included, all properties are returned.
//   version: The table version to access. See Accessing Public Data for
//     information.
//      kGTLMapsEngineVersionDraft: The draft version.
//      kGTLMapsEngineVersionPublished: The published version.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineFeature.
+ (id)queryForTablesFeaturesGetWithTableId:(NSString *)tableId;

// Method: mapsengine.tables.features.list
// Return all features readable by the current user.
//  Required:
//   identifier: The ID of the table to which these features belong.
//  Optional:
//   include: A comma separated list of optional data to include. Optional data
//     available: schema.
//   intersects: A geometry literal that specifies the spatial restriction of
//     the query.
//   limit: The total number of features to return from the query, irrespective
//     of the number of pages.
//   maxResults: The maximum number of items to include in the response, used
//     for paging. The maximum supported value is 1000.
//   orderBy: An SQL-like order by clause used to sort results. If this
//     parameter is not included, the order of features is undefined.
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     nextPageToken from the previous response.
//   select: A SQL-like projection clause used to specify returned properties.
//     If this parameter is not included, all properties are returned.
//   version: The table version to access. See Accessing Public Data for
//     information.
//      kGTLMapsEngineVersionDraft: The draft version.
//      kGTLMapsEngineVersionPublished: The published version.
//   where: An SQL-like predicate used to filter results.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineFeaturesListResponse.
+ (id)queryForTablesFeaturesListWithIdentifier:(NSString *)identifier;

#pragma mark -
#pragma mark "tables.files" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.tables.files.insert
// Upload a file to a placeholder table asset. See Table Upload in the
// Developer's Guide for more information.
// Supported file types are listed in the Supported data formats and limits
// article of the Google Maps Engine help center.
//  Required:
//   identifier: The ID of the table asset.
//   filename: The file name of this uploaded file.
//  Upload Parameters:
//   Maximum size: 1GB
//   Accepted MIME type(s): */*
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
+ (id)queryForTablesFilesInsertWithIdentifier:(NSString *)identifier
                                     filename:(NSString *)filename
                             uploadParameters:(GTLUploadParameters *)uploadParametersOrNil;

#pragma mark -
#pragma mark "tables" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.tables.get
// Return metadata for a particular table, including the schema.
//  Required:
//   identifier: The ID of the table.
//  Optional:
//   version: NSString
//      kGTLMapsEngineVersionDraft: The draft version.
//      kGTLMapsEngineVersionPublished: The published version.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineTable.
+ (id)queryForTablesGetWithIdentifier:(NSString *)identifier;

// Method: mapsengine.tables.list
// Return all tables readable by the current user.
//  Optional:
//   bbox: A bounding box, expressed as "west,south,east,north". If set, only
//     assets which intersect this bounding box will be returned.
//   createdAfter: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been created at or after
//     this time.
//   createdBefore: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been created at or
//     before this time.
//   creatorEmail: An email address representing a user. Returned assets that
//     have been created by the user associated with the provided email address.
//   maxResults: The maximum number of items to include in a single response
//     page. The maximum supported value is 100.
//   modifiedAfter: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been modified at or
//     after this time.
//   modifiedBefore: An RFC 3339 formatted date-time value (e.g.
//     1970-01-01T00:00:00Z). Returned assets will have been modified at or
//     before this time.
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     nextPageToken from the previous response.
//   projectId: The ID of a Maps Engine project, used to filter the response. To
//     list all available projects with their IDs, send a Projects: list
//     request. You can also find your project ID as the value of the
//     DashboardPlace:cid URL parameter when signed in to mapsengine.google.com.
//   tags: A comma separated list of tags. Returned assets will contain all the
//     tags from the list.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineTablesListResponse.
+ (id)queryForTablesList;

#pragma mark -
#pragma mark "tables.parents" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.tables.parents.list
// Return all parent ids of the specified table.
//  Required:
//   identifier: The ID of the table whose parents will be listed.
//  Optional:
//   maxResults: The maximum number of items to include in a single response
//     page. The maximum supported value is 50.
//   pageToken: The continuation token, used to page through large result sets.
//     To get the next page of results, set this parameter to the value of
//     nextPageToken from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
//   kGTLAuthScopeMapsEngineReadonly
// Fetches a GTLMapsEngineParentsListResponse.
+ (id)queryForTablesParentsListWithIdentifier:(NSString *)identifier;

#pragma mark -
#pragma mark "tables" methods
// These create a GTLQueryMapsEngine object.

// Method: mapsengine.tables.patch
// Mutate a table asset.
//  Required:
//   identifier: The ID of the table.
//  Optional:
//   request: For this method, "request" should be of type GTLMapsEngineTable.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
+ (id)queryForTablesPatchWithIdentifier:(NSString *)identifier;

// Method: mapsengine.tables.upload
// Create a placeholder table asset to which table files can be uploaded.
// Once the placeholder has been created, files are uploaded to the
// https://www.googleapis.com/upload/mapsengine/v1/tables/table_id/files
// endpoint.
// See Table Upload in the Developer's Guide or Table.files: insert in the
// reference documentation for more information.
//  Optional:
//   request: For this method, "request" should be of type GTLMapsEngineTable.
//  Authorization scope(s):
//   kGTLAuthScopeMapsEngine
// Fetches a GTLMapsEngineTable.
+ (id)queryForTablesUpload;

@end
