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
//  GTLCivicInfoSimpleAddressType.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Civic Information API (civicinfo/v2)
// Description:
//   An API for accessing civic information.
// Documentation:
//   https://developers.google.com/civic-information
// Classes:
//   GTLCivicInfoSimpleAddressType (0 custom class methods, 7 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLCivicInfoSimpleAddressType
//

// A simple representation of an address.

@interface GTLCivicInfoSimpleAddressType : GTLObject

// The city or town for the address.
@property (nonatomic, copy) NSString *city;

// The street name and number of this address.
@property (nonatomic, copy) NSString *line1;

// The second line the address, if needed.
@property (nonatomic, copy) NSString *line2;

// The third line of the address, if needed.
@property (nonatomic, copy) NSString *line3;

// The name of the location.
@property (nonatomic, copy) NSString *locationName;

// The US two letter state abbreviation of the address.
@property (nonatomic, copy) NSString *state;

// The US Postal Zip Code of the address.
@property (nonatomic, copy) NSString *zip;

@end
