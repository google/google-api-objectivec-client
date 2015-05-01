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
//  GTLQPXExpressTaxInfo.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   QPX Express API (qpxExpress/v1)
// Description:
//   Lets you find the least expensive flights between an origin and a
//   destination.
// Documentation:
//   http://developers.google.com/qpx-express
// Classes:
//   GTLQPXExpressTaxInfo (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressTaxInfo
//

// Tax information.

@interface GTLQPXExpressTaxInfo : GTLObject

// Whether this is a government charge or a carrier surcharge.
@property (nonatomic, copy) NSString *chargeType;

// The code to enter in the ticket's tax box.
@property (nonatomic, copy) NSString *code;

// For government charges, the country levying the charge.
@property (nonatomic, copy) NSString *country;

// Identifier uniquely identifying this tax in a response. Not present for
// unnamed carrier surcharges.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Identifies this as a tax information object. Value: the fixed string
// qpxexpress#taxInfo.
@property (nonatomic, copy) NSString *kind;

// The price of the tax in the sales or equivalent currency.
@property (nonatomic, copy) NSString *salePrice;

@end
