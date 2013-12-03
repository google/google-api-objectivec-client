/* Copyright (c) 2013 Google Inc.
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
//  GTLSpectrumVcardAddress.h
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
//   GTLSpectrumVcardAddress (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLSpectrumVcardAddress
//

// The structure used to represent a street address.

@interface GTLSpectrumVcardAddress : GTLObject

// The postal code associated with the address. For example: 94423.
@property (copy) NSString *code;

// The country name. For example: US.
@property (copy) NSString *country;

// The city or local equivalent portion of the address. For example: San Jose.
@property (copy) NSString *locality;

// An optional post office box number.
@property (copy) NSString *pobox;

// The state or local equivalent portion of the address. For example: CA.
@property (copy) NSString *region;

// The street number and name. For example: 123 Any St.
@property (copy) NSString *street;

@end
