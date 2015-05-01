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
//  GTLAdSenseAdClient.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Management API (adsense/v1.4)
// Description:
//   Gives AdSense publishers access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://developers.google.com/adsense/management/
// Classes:
//   GTLAdSenseAdClient (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLAdSenseAdClient
//

@interface GTLAdSenseAdClient : GTLObject

// Whether this ad client is opted in to ARC.
@property (nonatomic, retain) NSNumber *arcOptIn;  // boolValue

// ARC review mode this ad client is in. Empty if the client is not opted in to
// ARC. Possible values: POST_REVIEW, AUTOMATIC_PRE_REVIEW.
@property (nonatomic, copy) NSString *arcReviewMode;

// Unique identifier of this ad client.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Kind of resource this is, in this case adsense#adClient.
@property (nonatomic, copy) NSString *kind;

// This ad client's product code, which corresponds to the PRODUCT_CODE report
// dimension.
@property (nonatomic, copy) NSString *productCode;

// Whether this ad client supports being reported on.
@property (nonatomic, retain) NSNumber *supportsReporting;  // boolValue

@end
