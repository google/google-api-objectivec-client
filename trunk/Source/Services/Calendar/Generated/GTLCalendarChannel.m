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
//  GTLCalendarChannel.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Calendar API (calendar/v3)
// Description:
//   Lets you manipulate events and other calendar data.
// Documentation:
//   https://developers.google.com/google-apps/calendar/firstapp
// Classes:
//   GTLCalendarChannel (0 custom class methods, 10 custom properties)
//   GTLCalendarChannelParams (0 custom class methods, 0 custom properties)

#import "GTLCalendarChannel.h"

// ----------------------------------------------------------------------------
//
//   GTLCalendarChannel
//

@implementation GTLCalendarChannel
@dynamic address, expiration, identifier, kind, params, payload, resourceId,
         resourceUri, token, type;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"identifier" : @"id"
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"api#channel"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLCalendarChannelParams
//

@implementation GTLCalendarChannelParams

+ (Class)classForAdditionalProperties {
  return [NSString class];
}

@end
