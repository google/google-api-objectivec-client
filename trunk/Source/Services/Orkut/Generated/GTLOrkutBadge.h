/* Copyright (c) 2011 Google Inc.
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
//  GTLOrkutBadge.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Orkut API (orkut/v2)
// Description:
//   Lets you manage activities, comments and badges in Orkut. More stuff coming
//   in time.
// Documentation:
//   http://code.google.com/apis/orkut/v2/reference.html
// Classes:
//   GTLOrkutBadge (0 custom class methods, 9 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLOrkutBadge
//

@interface GTLOrkutBadge : GTLObject

// The URL for the 64x64 badge logo.
@property (copy) NSString *badgeLargeLogo;

// The URL for the 24x24 badge logo.
@property (copy) NSString *badgeSmallLogo;

// The name of the badge, suitable for display.
@property (copy) NSString *caption;

// The description for the badge, suitable for display.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// The unique ID for the badge.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSNumber *identifier;  // longLongValue

// Identifies this resource as a badge. Value: "orkut#badge"
@property (copy) NSString *kind;

// The URL for the 32x32 badge sponsor logo.
@property (copy) NSString *sponsorLogo;

// The name of the badge sponsor, suitable for display.
@property (copy) NSString *sponsorName;

// The URL for the badge sponsor.
@property (copy) NSString *sponsorUrl;

@end
