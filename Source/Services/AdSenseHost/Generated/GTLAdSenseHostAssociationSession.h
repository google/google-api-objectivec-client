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
//  GTLAdSenseHostAssociationSession.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Host API (adsensehost/v4.1)
// Description:
//   Gives AdSense Hosts access to report generation, ad code generation, and
//   publisher management capabilities.
// Documentation:
//   https://developers.google.com/adsense/host/
// Classes:
//   GTLAdSenseHostAssociationSession (0 custom class methods, 9 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLAdSenseHostAssociationSession
//

@interface GTLAdSenseHostAssociationSession : GTLObject

// Hosted account id of the associated publisher after association. Present if
// status is ACCEPTED.
@property (nonatomic, copy) NSString *accountId;

// Unique identifier of this association session.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Kind of resource this is, in this case adsensehost#associationSession.
@property (nonatomic, copy) NSString *kind;

// The products to associate with the user. Options: AFC, AFF, AFS, AFMC
@property (nonatomic, retain) NSArray *productCodes;  // of NSString

// Redirect URL of this association session. Used to redirect users into the
// AdSense association flow.
@property (nonatomic, copy) NSString *redirectUrl;

// Status of the completed association, available once the association callback
// token has been verified. One of ACCEPTED, REJECTED, or ERROR.
@property (nonatomic, copy) NSString *status;

// The preferred locale of the user themselves when going through the AdSense
// association flow.
@property (nonatomic, copy) NSString *userLocale;

// The locale of the user's hosted website.
@property (nonatomic, copy) NSString *websiteLocale;

// The URL of the user's hosted website.
@property (nonatomic, copy) NSString *websiteUrl;

@end
