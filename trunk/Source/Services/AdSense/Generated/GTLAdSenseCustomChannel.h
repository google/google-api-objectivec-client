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
//  GTLAdSenseCustomChannel.h
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
//   GTLAdSenseCustomChannel (0 custom class methods, 5 custom properties)
//   GTLAdSenseCustomChannelTargetingInfo (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdSenseCustomChannelTargetingInfo;

// ----------------------------------------------------------------------------
//
//   GTLAdSenseCustomChannel
//

@interface GTLAdSenseCustomChannel : GTLObject

// Code of this custom channel, not necessarily unique across ad clients.
@property (nonatomic, copy) NSString *code;

// Unique identifier of this custom channel. This should be considered an opaque
// identifier; it is not safe to rely on it being in any particular format.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Kind of resource this is, in this case adsense#customChannel.
@property (nonatomic, copy) NSString *kind;

// Name of this custom channel.
@property (nonatomic, copy) NSString *name;

// The targeting information of this custom channel, if activated.
@property (nonatomic, retain) GTLAdSenseCustomChannelTargetingInfo *targetingInfo;

@end


// ----------------------------------------------------------------------------
//
//   GTLAdSenseCustomChannelTargetingInfo
//

@interface GTLAdSenseCustomChannelTargetingInfo : GTLObject

// The name used to describe this channel externally.
@property (nonatomic, copy) NSString *adsAppearOn;

// The external description of the channel.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// The locations in which ads appear. (Only valid for content and mobile content
// ads). Acceptable values for content ads are: TOP_LEFT, TOP_CENTER, TOP_RIGHT,
// MIDDLE_LEFT, MIDDLE_CENTER, MIDDLE_RIGHT, BOTTOM_LEFT, BOTTOM_CENTER,
// BOTTOM_RIGHT, MULTIPLE_LOCATIONS. Acceptable values for mobile content ads
// are: TOP, MIDDLE, BOTTOM, MULTIPLE_LOCATIONS.
@property (nonatomic, copy) NSString *location;

// The language of the sites ads will be displayed on.
@property (nonatomic, copy) NSString *siteLanguage;

@end
