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

// GTLMapsEngineAcquisitionTime - Precision
GTL_EXTERN NSString * const kGTLMapsEngineAcquisitionTime_Precision_Day;  // "day"
GTL_EXTERN NSString * const kGTLMapsEngineAcquisitionTime_Precision_Hour;  // "hour"
GTL_EXTERN NSString * const kGTLMapsEngineAcquisitionTime_Precision_Minute;  // "minute"
GTL_EXTERN NSString * const kGTLMapsEngineAcquisitionTime_Precision_Month;  // "month"
GTL_EXTERN NSString * const kGTLMapsEngineAcquisitionTime_Precision_Second;  // "second"
GTL_EXTERN NSString * const kGTLMapsEngineAcquisitionTime_Precision_Year;  // "year"

// GTLMapsEngineAsset - Type
GTL_EXTERN NSString * const kGTLMapsEngineAsset_Type_Layer;     // "layer"
GTL_EXTERN NSString * const kGTLMapsEngineAsset_Type_Map;       // "map"
GTL_EXTERN NSString * const kGTLMapsEngineAsset_Type_Raster;    // "raster"
GTL_EXTERN NSString * const kGTLMapsEngineAsset_Type_RasterCollection;  // "rasterCollection"
GTL_EXTERN NSString * const kGTLMapsEngineAsset_Type_Table;     // "table"

// GTLMapsEngineFile - UploadStatus
GTL_EXTERN NSString * const kGTLMapsEngineFile_UploadStatus_Canceled;  // "canceled"
GTL_EXTERN NSString * const kGTLMapsEngineFile_UploadStatus_Complete;  // "complete"
GTL_EXTERN NSString * const kGTLMapsEngineFile_UploadStatus_Failed;  // "failed"
GTL_EXTERN NSString * const kGTLMapsEngineFile_UploadStatus_InProgress;  // "inProgress"

// GTLMapsEngineFilter - OperatorProperty
GTL_EXTERN NSString * const kGTLMapsEngineFilter_OperatorProperty_Contains;  // "contains"
GTL_EXTERN NSString * const kGTLMapsEngineFilter_OperatorProperty_EndsWith;  // "endsWith"
GTL_EXTERN NSString * const kGTLMapsEngineFilter_OperatorProperty_StartsWith;  // "startsWith"
GTL_EXTERN NSString * const kGTLMapsEngineFilter_OperatorProperty_X;  // ">="

// GTLMapsEngineGeoJsonGeometryCollection - Type
GTL_EXTERN NSString * const kGTLMapsEngineGeoJsonGeometryCollection_Type_GeometryCollection;  // "GeometryCollection"

// GTLMapsEngineGeoJsonLineString - Type
GTL_EXTERN NSString * const kGTLMapsEngineGeoJsonLineString_Type_LineString;  // "LineString"

// GTLMapsEngineGeoJsonMultiLineString - Type
GTL_EXTERN NSString * const kGTLMapsEngineGeoJsonMultiLineString_Type_MultiLineString;  // "MultiLineString"

// GTLMapsEngineGeoJsonMultiPoint - Type
GTL_EXTERN NSString * const kGTLMapsEngineGeoJsonMultiPoint_Type_MultiPoint;  // "MultiPoint"

// GTLMapsEngineGeoJsonMultiPolygon - Type
GTL_EXTERN NSString * const kGTLMapsEngineGeoJsonMultiPolygon_Type_MultiPolygon;  // "MultiPolygon"

// GTLMapsEngineGeoJsonPoint - Type
GTL_EXTERN NSString * const kGTLMapsEngineGeoJsonPoint_Type_Point;  // "Point"

// GTLMapsEngineGeoJsonPolygon - Type
GTL_EXTERN NSString * const kGTLMapsEngineGeoJsonPolygon_Type_Polygon;  // "Polygon"

// GTLMapsEngineLabelStyle - FontStyle
GTL_EXTERN NSString * const kGTLMapsEngineLabelStyle_FontStyle_Italic;  // "italic"
GTL_EXTERN NSString * const kGTLMapsEngineLabelStyle_FontStyle_Normal;  // "normal"

// GTLMapsEngineLabelStyle - FontWeight
GTL_EXTERN NSString * const kGTLMapsEngineLabelStyle_FontWeight_Bold;  // "bold"
GTL_EXTERN NSString * const kGTLMapsEngineLabelStyle_FontWeight_Normal;  // "normal"

// GTLMapsEngineLayer - DatasourceType
GTL_EXTERN NSString * const kGTLMapsEngineLayer_DatasourceType_Image;  // "image"
GTL_EXTERN NSString * const kGTLMapsEngineLayer_DatasourceType_Table;  // "table"

// GTLMapsEngineLayer - ProcessingStatus
GTL_EXTERN NSString * const kGTLMapsEngineLayer_ProcessingStatus_Complete;  // "complete"
GTL_EXTERN NSString * const kGTLMapsEngineLayer_ProcessingStatus_Failed;  // "failed"
GTL_EXTERN NSString * const kGTLMapsEngineLayer_ProcessingStatus_NotReady;  // "notReady"
GTL_EXTERN NSString * const kGTLMapsEngineLayer_ProcessingStatus_Processing;  // "processing"
GTL_EXTERN NSString * const kGTLMapsEngineLayer_ProcessingStatus_Ready;  // "ready"

// GTLMapsEngineMap - ProcessingStatus
GTL_EXTERN NSString * const kGTLMapsEngineMap_ProcessingStatus_Complete;  // "complete"
GTL_EXTERN NSString * const kGTLMapsEngineMap_ProcessingStatus_Failed;  // "failed"
GTL_EXTERN NSString * const kGTLMapsEngineMap_ProcessingStatus_NotReady;  // "notReady"
GTL_EXTERN NSString * const kGTLMapsEngineMap_ProcessingStatus_Processing;  // "processing"
GTL_EXTERN NSString * const kGTLMapsEngineMap_ProcessingStatus_Ready;  // "ready"

// GTLMapsEngineMap - Versions
GTL_EXTERN NSString * const kGTLMapsEngineMap_Versions_Draft;   // "draft"
GTL_EXTERN NSString * const kGTLMapsEngineMap_Versions_Published;  // "published"

// GTLMapsEngineMapFolder - Type
GTL_EXTERN NSString * const kGTLMapsEngineMapFolder_Type_Folder;  // "folder"

// GTLMapsEngineMapKmlLink - Type
GTL_EXTERN NSString * const kGTLMapsEngineMapKmlLink_Type_KmlLink;  // "kmlLink"

// GTLMapsEngineMapLayer - Type
GTL_EXTERN NSString * const kGTLMapsEngineMapLayer_Type_Layer;  // "layer"

// GTLMapsEngineRaster - ProcessingStatus
GTL_EXTERN NSString * const kGTLMapsEngineRaster_ProcessingStatus_Complete;  // "complete"
GTL_EXTERN NSString * const kGTLMapsEngineRaster_ProcessingStatus_Failed;  // "failed"
GTL_EXTERN NSString * const kGTLMapsEngineRaster_ProcessingStatus_NotReady;  // "notReady"
GTL_EXTERN NSString * const kGTLMapsEngineRaster_ProcessingStatus_Processing;  // "processing"
GTL_EXTERN NSString * const kGTLMapsEngineRaster_ProcessingStatus_Ready;  // "ready"

// GTLMapsEngineRaster - RasterType
GTL_EXTERN NSString * const kGTLMapsEngineRaster_RasterType_Image;  // "image"

// GTLMapsEngineRasterCollection - ProcessingStatus
GTL_EXTERN NSString * const kGTLMapsEngineRasterCollection_ProcessingStatus_Complete;  // "complete"
GTL_EXTERN NSString * const kGTLMapsEngineRasterCollection_ProcessingStatus_Failed;  // "failed"
GTL_EXTERN NSString * const kGTLMapsEngineRasterCollection_ProcessingStatus_NotReady;  // "notReady"
GTL_EXTERN NSString * const kGTLMapsEngineRasterCollection_ProcessingStatus_Processing;  // "processing"
GTL_EXTERN NSString * const kGTLMapsEngineRasterCollection_ProcessingStatus_Ready;  // "ready"

// GTLMapsEngineRasterCollection - RasterType
GTL_EXTERN NSString * const kGTLMapsEngineRasterCollection_RasterType_Image;  // "image"

// GTLMapsEngineTable - ProcessingStatus
GTL_EXTERN NSString * const kGTLMapsEngineTable_ProcessingStatus_Complete;  // "complete"
GTL_EXTERN NSString * const kGTLMapsEngineTable_ProcessingStatus_Failed;  // "failed"
GTL_EXTERN NSString * const kGTLMapsEngineTable_ProcessingStatus_NotReady;  // "notReady"
GTL_EXTERN NSString * const kGTLMapsEngineTable_ProcessingStatus_Processing;  // "processing"
GTL_EXTERN NSString * const kGTLMapsEngineTable_ProcessingStatus_Ready;  // "ready"

// GTLMapsEngineTableColumn - Type
GTL_EXTERN NSString * const kGTLMapsEngineTableColumn_Type_Boolean;  // "boolean"
GTL_EXTERN NSString * const kGTLMapsEngineTableColumn_Type_Datetime;  // "datetime"
GTL_EXTERN NSString * const kGTLMapsEngineTableColumn_Type_Double;  // "double"
GTL_EXTERN NSString * const kGTLMapsEngineTableColumn_Type_Integer;  // "integer"
GTL_EXTERN NSString * const kGTLMapsEngineTableColumn_Type_LineStrings;  // "lineStrings"
GTL_EXTERN NSString * const kGTLMapsEngineTableColumn_Type_MixedGeometry;  // "mixedGeometry"
GTL_EXTERN NSString * const kGTLMapsEngineTableColumn_Type_Points;  // "points"
GTL_EXTERN NSString * const kGTLMapsEngineTableColumn_Type_Polygons;  // "polygons"
GTL_EXTERN NSString * const kGTLMapsEngineTableColumn_Type_String;  // "string"

// GTLMapsEngineVectorStyle - Type
GTL_EXTERN NSString * const kGTLMapsEngineVectorStyle_Type_DisplayRule;  // "displayRule"

// GTLQueryMapsEngine - Type
GTL_EXTERN NSString * const kGTLMapsEngineTypeLayer;            // "layer"
GTL_EXTERN NSString * const kGTLMapsEngineTypeMap;              // "map"
GTL_EXTERN NSString * const kGTLMapsEngineTypeRasterCollection;  // "rasterCollection"
GTL_EXTERN NSString * const kGTLMapsEngineTypeTable;            // "table"

// GTLQueryMapsEngine - Version
GTL_EXTERN NSString * const kGTLMapsEngineVersionDraft;      // "draft"
GTL_EXTERN NSString * const kGTLMapsEngineVersionPublished;  // "published"
