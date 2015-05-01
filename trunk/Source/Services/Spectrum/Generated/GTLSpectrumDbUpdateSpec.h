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
//  GTLSpectrumDbUpdateSpec.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Spectrum Database API (spectrum/v1explorer)
// Description:
//   API for spectrum-management functions.
// Documentation:
//   http://developers.google.com/spectrum
// Classes:
//   GTLSpectrumDbUpdateSpec (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSpectrumDatabaseSpec;

// ----------------------------------------------------------------------------
//
//   GTLSpectrumDbUpdateSpec
//

// This message is provided by the database to notify devices of an upcoming
// change to the database URI.

@interface GTLSpectrumDbUpdateSpec : GTLObject

// A required list of one or more databases. A device should update its
// preconfigured list of databases to replace (only) the database that provided
// the response with the specified entries.
@property (nonatomic, retain) NSArray *databases;  // of GTLSpectrumDatabaseSpec

@end
