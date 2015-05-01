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
//  GTLAdExchangeSellerAlert.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Ad Exchange Seller API (adexchangeseller/v2.0)
// Description:
//   Gives Ad Exchange seller users access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://developers.google.com/ad-exchange/seller-rest/
// Classes:
//   GTLAdExchangeSellerAlert (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeSellerAlert
//

@interface GTLAdExchangeSellerAlert : GTLObject

// Unique identifier of this alert. This should be considered an opaque
// identifier; it is not safe to rely on it being in any particular format.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Kind of resource this is, in this case adexchangeseller#alert.
@property (nonatomic, copy) NSString *kind;

// The localized alert message.
@property (nonatomic, copy) NSString *message;

// Severity of this alert. Possible values: INFO, WARNING, SEVERE.
@property (nonatomic, copy) NSString *severity;

// Type of this alert. Possible values: SELF_HOLD, MIGRATED_TO_BILLING3,
// ADDRESS_PIN_VERIFICATION, PHONE_PIN_VERIFICATION, CORPORATE_ENTITY,
// GRAYLISTED_PUBLISHER, API_HOLD.
@property (nonatomic, copy) NSString *type;

@end
