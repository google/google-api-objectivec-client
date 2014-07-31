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
//  GTLMapsEngineRasterCollection.h
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
//   GTLMapsEngineRasterCollection (0 custom class methods, 14 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLMapsEngineRasterCollection
//

// A raster collection groups multiple Raster resources for inclusion in a
// Layer.

@interface GTLMapsEngineRasterCollection : GTLObject

// The name of the attribution to be used for this RasterCollection.
@property (copy) NSString *attribution;

// A rectangular bounding box which contains all of the data in this
// RasterCollection. The numbers represent latitude and longitude in decimal
// degrees.
@property (retain) NSArray *bbox;  // of NSNumber (doubleValue)

// The creation time of this RasterCollection. The value is an RFC 3339
// formatted date-time value (e.g. 1970-01-01T00:00:00Z).
@property (retain) GTLDateTime *creationTime;

// The description of this RasterCollection, supplied by the author.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Deprecated: The name of an access list of the Map Editor type. The user on
// whose behalf the request is being sent must be an editor on that access list.
// Note: Google Maps Engine no longer uses access lists. For backward
// compatibility, the API still accepts access lists for projects that are
// already using access lists. If you created a GME account/project after July
// 14th, 2014, you will not be able to send API requests that include access
// lists. The API does not yet support the new permissions model. When you
// create a map via the API without specifying permissions, the account that
// created the map is the owner and has effective administrator access. Users
// can then use the Maps Engine user interface to adjust the permissions. This
// is a temporary workaround until the API supports the new permissions model.
// Read Add new users and groups in the Google Maps Engine help center for more
// information.
@property (copy) NSString *draftAccessList;

// The ETag, used to refer to the current version of the asset.
@property (copy) NSString *ETag;

// A globally unique ID, used to refer to this RasterCollection.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The last modified time of this RasterCollection. The value is an RFC 3339
// formatted date-time value (e.g. 1970-01-01T00:00:00Z).
@property (retain) GTLDateTime *lastModifiedTime;

// True if this RasterCollection is a mosaic.
@property (retain) NSNumber *mosaic;  // boolValue

// The name of this RasterCollection, supplied by the author.
@property (copy) NSString *name;

// The processing status of this RasterCollection.
@property (copy) NSString *processingStatus;

// The ID of the project that this RasterCollection is in.
@property (copy) NSString *projectId;

// The type of rasters contained within this RasterCollection.
@property (copy) NSString *rasterType;

// Tags of this RasterCollection.
@property (retain) NSArray *tags;  // of NSString

@end
