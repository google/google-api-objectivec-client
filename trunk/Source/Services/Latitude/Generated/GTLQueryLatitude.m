/* Copyright (c) 2012 Google Inc.
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
//  GTLQueryLatitude.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Latitude API (latitude/v1)
// Description:
//   Lets you read and update your current location and work with your location
//   history
// Documentation:
//   https://developers.google.com/latitude/v1/using
// Classes:
//   GTLQueryLatitude (7 custom class methods, 6 custom properties)

#import "GTLQueryLatitude.h"

#import "GTLLatitudeLocation.h"
#import "GTLLatitudeLocationFeed.h"

@implementation GTLQueryLatitude

@dynamic fields, granularity, locationId, maxResults, maxTime, minTime;

+ (NSDictionary *)parameterNameMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"max-results", @"maxResults",
      @"max-time", @"maxTime",
      @"min-time", @"minTime",
      nil];
  return map;
}

#pragma mark -
#pragma mark "currentLocation" methods
// These create a GTLQueryLatitude object.

+ (id)queryForCurrentLocationDelete {
  NSString *methodName = @"latitude.currentLocation.delete";
  GTLQueryLatitude *query = [self queryWithMethodName:methodName];
  return query;
}

+ (id)queryForCurrentLocationGet {
  NSString *methodName = @"latitude.currentLocation.get";
  GTLQueryLatitude *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLLatitudeLocation class];
  return query;
}

+ (id)queryForCurrentLocationInsertWithObject:(GTLLatitudeLocation *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"latitude.currentLocation.insert";
  GTLQueryLatitude *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.expectedObjectClass = [GTLLatitudeLocation class];
  return query;
}

#pragma mark -
#pragma mark "location" methods
// These create a GTLQueryLatitude object.

+ (id)queryForLocationDeleteWithLocationId:(NSString *)locationId {
  NSString *methodName = @"latitude.location.delete";
  GTLQueryLatitude *query = [self queryWithMethodName:methodName];
  query.locationId = locationId;
  return query;
}

+ (id)queryForLocationGetWithLocationId:(NSString *)locationId {
  NSString *methodName = @"latitude.location.get";
  GTLQueryLatitude *query = [self queryWithMethodName:methodName];
  query.locationId = locationId;
  query.expectedObjectClass = [GTLLatitudeLocation class];
  return query;
}

+ (id)queryForLocationInsertWithObject:(GTLLatitudeLocation *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"latitude.location.insert";
  GTLQueryLatitude *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.expectedObjectClass = [GTLLatitudeLocation class];
  return query;
}

+ (id)queryForLocationList {
  NSString *methodName = @"latitude.location.list";
  GTLQueryLatitude *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLLatitudeLocationFeed class];
  return query;
}

@end
