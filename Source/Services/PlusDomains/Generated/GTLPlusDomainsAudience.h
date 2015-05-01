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
//  GTLPlusDomainsAudience.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google+ Domains API (plusDomains/v1)
// Description:
//   The Google+ API enables developers to build on top of the Google+ platform.
// Documentation:
//   https://developers.google.com/+/domains/
// Classes:
//   GTLPlusDomainsAudience (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLPlusDomainsAclentryResource;

// ----------------------------------------------------------------------------
//
//   GTLPlusDomainsAudience
//

@interface GTLPlusDomainsAudience : GTLObject

// ETag of this response for caching purposes.
@property (nonatomic, copy) NSString *ETag;

// The access control list entry.
@property (nonatomic, retain) GTLPlusDomainsAclentryResource *item;

// Identifies this resource as an audience. Value: "plus#audience".
@property (nonatomic, copy) NSString *kind;

// The number of people in this circle. This only applies if entity_type is
// CIRCLE.
@property (nonatomic, retain) NSNumber *memberCount;  // unsignedIntValue

// The circle members' visibility as chosen by the owner of the circle. This
// only applies for items with "item.type" equals "circle". Possible values are:
// - "public" - Members are visible to the public.
// - "limited" - Members are visible to a limited audience.
// - "private" - Members are visible to the owner only.
@property (nonatomic, copy) NSString *visibility;

@end
