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
//  GTLMapsEngineAcquisitionTime.h
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
//   GTLMapsEngineAcquisitionTime (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLMapsEngineAcquisitionTime
//

// Acquisition time represents acquired time of a raster.

@interface GTLMapsEngineAcquisitionTime : GTLObject

// The end time if acquisition time is a range. The value is an RFC 3339
// formatted date-time value (1970-01-01T00:00:00Z).
@property (retain) GTLDateTime *end;

// The precision of acquisition time.
@property (copy) NSString *precision;

// The acquisition time, or start time if acquisition time is a range. The value
// is an RFC 3339 formatted date-time value (1970-01-01T00:00:00Z).
@property (retain) GTLDateTime *start;

@end
