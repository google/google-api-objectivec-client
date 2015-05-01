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
//  GTLMapsEngineLayer.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLMapsEngineDatasource;
@class GTLMapsEngineVectorStyle;

// ----------------------------------------------------------------------------
//
//   GTLMapsEngineLayer
//

// A Layer combines multiple datasources, with styling information, for
// presentation on a map.

@interface GTLMapsEngineLayer : GTLObject

// A rectangular bounding box which contains all of the data in this Layer. The
// box is expressed as \"west, south, east, north\". The numbers represent
// latitude and longitude in decimal degrees.
@property (nonatomic, retain) NSArray *bbox;  // of NSNumber (doubleValue)

// The creation time of this layer. The value is an RFC 3339 formatted date-time
// value (e.g. 1970-01-01T00:00:00Z).
@property (nonatomic, retain) GTLDateTime *creationTime;

// The email address of the creator of this layer. This is only returned on GET
// requests and not LIST requests.
@property (nonatomic, copy) NSString *creatorEmail;

// An array of datasources used to build this layer. If layerType is "image", or
// layerType is not specified and datasourceType is "image", then each element
// in this array is a reference to an Image or RasterCollection. If layerType is
// "vector", or layerType is not specified and datasourceType is "table" then
// each element in this array is a reference to a Vector Table.
@property (nonatomic, retain) NSArray *datasources;  // of GTLMapsEngineDatasource

// Deprecated: The type of the datasources used to build this Layer. Note: This
// has been replaced by layerType, but is still available for now to maintain
// backward compatibility.
@property (nonatomic, copy) NSString *datasourceType;

// The description of this Layer, supplied by the author.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// Deprecated: The name of an access list of the Map Editor type. The user on
// whose behalf the request is being sent must be an editor on that access list.
// Note: Google Maps Engine no longer uses access lists. Instead, each asset has
// its own list of permissions. For backward compatibility, the API still
// accepts access lists for projects that are already using access lists. If you
// created a GME account/project after July 14th, 2014, you will not be able to
// send API requests that include access lists. Note: This is an input field
// only. It is not returned in response to a list or get request.
@property (nonatomic, copy) NSString *draftAccessList;

// The ETag, used to refer to the current version of the asset.
@property (nonatomic, copy) NSString *ETag;

// A globally unique ID, used to refer to this Layer.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// The last modified time of this layer. The value is an RFC 3339 formatted
// date-time value (e.g. 1970-01-01T00:00:00Z).
@property (nonatomic, retain) GTLDateTime *lastModifiedTime;

// The email address of the last modifier of this layer. This is only returned
// on GET requests and not LIST requests.
@property (nonatomic, copy) NSString *lastModifierEmail;

// The type of the datasources used to build this Layer. This should be used
// instead of datasourceType. At least one of layerType and datasourceType and
// must be specified, but layerType takes precedence.
@property (nonatomic, copy) NSString *layerType;

// The name of this Layer, supplied by the author.
@property (nonatomic, copy) NSString *name;

// The processing status of this layer.
@property (nonatomic, copy) NSString *processingStatus;

// The ID of the project that this Layer is in.
@property (nonatomic, copy) NSString *projectId;

// Deprecated: The access list to whom view permissions are granted. The value
// must be the name of a Maps Engine access list of the Map Viewer type, and the
// user must be a viewer on that list. Note: Google Maps Engine no longer uses
// access lists. Instead, each asset has its own list of permissions. For
// backward compatibility, the API still accepts access lists for projects that
// are already using access lists. If you created a GME account/project after
// July 14th, 2014, you will not be able to send API requests that include
// access lists. Note: This is an input field only. It is not returned in
// response to a list or get request.
@property (nonatomic, copy) NSString *publishedAccessList;

// The publishing status of this layer.
@property (nonatomic, copy) NSString *publishingStatus;

// The styling information for a vector layer. Note: Style information is
// returned in response to a get request but not a list request. After
// requesting a list of layers, you'll need to send a get request to retrieve
// the VectorStyles for each layer.
@property (nonatomic, retain) GTLMapsEngineVectorStyle *style;

// Tags of this Layer.
@property (nonatomic, retain) NSArray *tags;  // of NSString

// If true, WRITERs of the asset are able to edit the asset permissions.
@property (nonatomic, retain) NSNumber *writersCanEditPermissions;  // boolValue

@end
