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
//  GTLMapsEngineTable.h
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
//   GTLMapsEngineTable (0 custom class methods, 14 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLMapsEngineFile;
@class GTLMapsEngineSchema;

// ----------------------------------------------------------------------------
//
//   GTLMapsEngineTable
//

// A collection of geographic features, and associated metadata.

@interface GTLMapsEngineTable : GTLObject

// An array of four numbers (west, south, east, north) which define the
// rectangular bounding box which contains all of the data in this table.
@property (retain) NSArray *bbox;  // of NSNumber (doubleValue)

// The creation time of this table. The value is an RFC 3339 formatted date-time
// value (e.g. 1970-01-01T00:00:00Z).
@property (retain) GTLDateTime *creationTime;

// The description of this table, supplied by the author.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// The name of an access list of the Map Editor type. The user on whose behalf
// the request is being sent must be an editor on that access list. Read About
// access lists in the Google Maps Engine help center for more information.
@property (copy) NSString *draftAccessList;

// The files associated with this table.
@property (retain) NSArray *files;  // of GTLMapsEngineFile

// A globally unique ID, used to refer to this table.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The last modified time of this table. The value is an RFC 3339 formatted
// date-time value (e.g. 1970-01-01T00:00:00Z).
@property (retain) GTLDateTime *lastModifiedTime;

// The name of this table, supplied by the author.
@property (copy) NSString *name;

// The processing status of this table. The supported processing status values
// are:
// - notReady: The table is not ready to be processed - some files have not been
// uploaded.
// - ready: The table is queued for processing.
// - processing: The table is currently processing.
// - complete: Processing has completed successfully.
// - failed: Processing failed to complete.
@property (copy) NSString *processingStatus;

// The ID of the project to which the table belongs.
@property (copy) NSString *projectId;

// The access list to whom view permissions are granted. The value must be the
// name of a Maps Engine access list of the Map Viewer type, and the user must
// be a viewer on that list. Read About access lists in the Google Maps Engine
// help center for more information.
@property (copy) NSString *publishedAccessList;

// The schema for this table.
@property (retain) GTLMapsEngineSchema *schema;

// Encoding of the uploaded files. Valid values include UTF-8, CP1251, ISO
// 8859-1, and Shift_JIS.
@property (copy) NSString *sourceEncoding;

// An array of text strings, with each string representing a tag. More
// information about tags can be found in the Tagging data article of the Maps
// Engine help center.
@property (retain) NSArray *tags;  // of NSString

@end
