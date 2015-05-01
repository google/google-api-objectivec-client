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
//  GTLSpectrumVcard.h
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
//   GTLSpectrumVcard (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLSpectrumVcardAddress;
@class GTLSpectrumVcardTelephone;
@class GTLSpectrumVcardTypedText;

// ----------------------------------------------------------------------------
//
//   GTLSpectrumVcard
//

// A vCard-in-JSON message that contains only the fields needed for PAWS:
// - fn: Full name of an individual
// - org: Name of the organization
// - adr: Address fields
// - tel: Telephone numbers
// - email: Email addresses

@interface GTLSpectrumVcard : GTLObject

// The street address of the entity.
@property (nonatomic, retain) GTLSpectrumVcardAddress *adr;

// An email address that can be used to reach the contact.
@property (nonatomic, retain) GTLSpectrumVcardTypedText *email;

// The full name of the contact person. For example: John A. Smith.
@property (nonatomic, copy) NSString *fn;

// The organization associated with the registering entity.
@property (nonatomic, retain) GTLSpectrumVcardTypedText *org;

// A telephone number that can be used to call the contact.
@property (nonatomic, retain) GTLSpectrumVcardTelephone *tel;

@end
