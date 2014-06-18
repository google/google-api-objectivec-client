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
//  GTLCivicInfoDivisionSearchResponse.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Civic Information API (civicinfo/v1)
// Description:
//   An API for accessing civic information.
// Documentation:
//   https://developers.google.com/civic-information
// Classes:
//   GTLCivicInfoDivisionSearchResponse (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLCivicInfoDivisionSearchResult;

// ----------------------------------------------------------------------------
//
//   GTLCivicInfoDivisionSearchResponse
//

// The result of a division search query.

@interface GTLCivicInfoDivisionSearchResponse : GTLObject

// Identifies what kind of resource this is. Value: the fixed string
// "civicinfo#divisionSearchResponse".
@property (copy) NSString *kind;

@property (retain) NSArray *results;  // of GTLCivicInfoDivisionSearchResult

// The result of the request. One of: success, addressUnparseable,
// noAddressParameter, internalLookupFailure
@property (copy) NSString *status;

@end
